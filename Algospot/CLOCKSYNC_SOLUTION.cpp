#include <algorithm>
#include <vector>

using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
//linked[i][j] = 'x' : i�� ����ġ�� j�� �ð谡 ����Ǿ� �ִ�. 
//linked[i][j] = '.' : i�� ����ġ�� j�� �ð谡 ����Ǿ� ���� �ʴ�. 
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

//��� �ð谡 12�ø� ����Ű�� �ִ��� Ȯ���Ѵ�.
bool areAligned(const vector<int>& clocks);

//swtch�� ����ġ�� ������. 
void push(vector<int>& clocks, int swtch) {
	for (int clock = 0; clock < CLOCKS; ++clock) {
		if (linked[swtch][clock] == 'X') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}

//clocks : ���� �ð���� ���� 
//swtch : �̹��� ���� ����ġ ��ȣ 
//�� �־��� ��, ���� ����ġ���� ������ clocks�� 12�÷� ���� �� �ִ� �ּ� Ƚ���� ��ȯ�Ѵ�. 
//���� �Ұ����ϴٸ� INF �̻��� ū ���� ��ȯ�Ѵ�. 
int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;

	//�� ����ġ�� 0�� ������ ������ �� �� ������ �������� ��� �õ��Ѵ�. 
	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}

	return ret;
}


