#include <algorithm>
#include <vector>

using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
//linked[i][j] = 'x' : i번 스위치와 j번 시계가 연결되어 있다. 
//linked[i][j] = '.' : i번 스위치와 j번 시계가 연결되어 있지 않다. 
const char linked[SWITCHES][CLOCKS + 1] = {
	"XXX.............",
	"...X...X.X.X....",
	"....X.....X...XX",
	"X...XXXX........",
	"......XXX.X.X...",
	"X.X...........XX",
	"...X..........XX",
	".XXXXX..........",
	"...XXX...X...X.."
};

//모든 시계가 12시를 가리키고 있는지 확인한다.
bool areAligned(const vector<int>& clocks);

//swtch번 스위치를 누른다. 
void push(vector<int>& clocks, int swtch) {
	for (int clock = 0; clock < CLOCKS; ++clock) {
		if (linked[swtch][clock] == 'X') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}

//clocks : 현재 시계들의 상태 
//swtch : 이번에 누를 스위치 번호 
//가 주어질 때, 남은 스위치들을 눌러서 clocks를 12시로 맞출 수 있는 최소 횟수를 반환한다. 
//만약 불가능하다면 INF 이상의 큰 수를 반환한다. 
int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;

	//이 스위치를 0번 누르는 경우부터 세 번 누르는 경우까지를 모두 시도한다. 
	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}

	return ret;
}


