//완전 탐색 문제를 풀 때는 항상 상태 공간을 어떻게 전개해 나갈건지 생각해 보는게 좋다. 
//아래 문제는 상태 공간을 가로로는 현재 지정된 스위치에 대하여 스위치를 누르는 횟수를 기준으로 전개해나가고 깊이로는 스위치의 번호를 기준으로 전개해 나간다. 
//나는 상태 공간을 가로로는 스위치의 번호를 기준으로 전개해 나갔고 세로로는 스위치를 누르는 횟수를 기준으로 전개해 나갔다. 
//결과 적으로 위의 방법을 사용하면 상당히 많은 시간을 단축할 수 있는 반면 아래 방법을 사용하면 상당히 많은 추가 시간을 소요한다.

#include <stdio.h>
#include <vector>

#define MAX_NUM 111111111

using namespace std;

int clock[17];
int turn_num[17];
vector<int> clock_switches[10] = { {0,1,2,},{3,7,9,11},{4,10,14,15},{0,4,5,6,7},{6,7,8,10,12}
						          ,{0,2,14,15}, {3,14,15}, {4,5,7,14,15}, {1,2,3,4,5}, {3,4,5,9,13} };


bool is_sync() {
	for (int i = 0; i < 16; i++) {
		if (clock[i] != 0) {
			return false;
		}
	}

	return true;
}

void move_clock_forward(vector<int> clock_switch, int num) {
	
	for (int i = 0; i < clock_switch.size(); i++) {
		clock[clock_switch[i]] = (clock[clock_switch[i]] + 3*num) % 12;
	}

	return;
}

void move_clock_backward(vector<int> clock_switch, int num) {
	for (int i = 0; i < clock_switch.size(); i++) {
		clock[clock_switch[i]] = ((clock[clock_switch[i]] - 3*num)>-1) ? (clock[clock_switch[i]]-3*num) : (clock[clock_switch[i]]-3*num +12);
	}
}

int sync_clock(int depth) {
	//기저 사례 1 : 답을 찾울 수 있는 경우 
	if (is_sync())	return 0;
	//기저 사례 2 : 답을 찾을 수 없는 경우 
	if (depth <= 0)	return MAX_NUM;
	int ret = MAX_NUM + 1;
	int tmp;

	for (int i = 0; i < 4; i++) {
		move_clock_forward(clock_switches[10-depth],i);
		tmp = sync_clock(depth - 1);
		ret = (ret > (tmp + i)) ? (tmp + i) : ret;
		move_clock_backward(clock_switches[10-depth], i);
	}

	//기저 사례 1, 2 : 답을 찾는 경우 + 답을 찾을 수 없는 경우 
	return ret;
}


int main(void) {
	int sol; 
	
	for (int i = 0; i < 16; i++) {
		scanf("%d", clock + i);
		clock[i] = (clock[i])%12;
	}

	sol = sync_clock(10);
	if (sol > MAX_NUM)
		sol = -1;
	printf("%d\n", sol);

	return 0;
}