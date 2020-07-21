//���� Ž�� ������ Ǯ ���� �׻� ���� ������ ��� ������ �������� ������ ���°� ����. 
//�Ʒ� ������ ���� ������ ���ηδ� ���� ������ ����ġ�� ���Ͽ� ����ġ�� ������ Ƚ���� �������� �����س����� ���̷δ� ����ġ�� ��ȣ�� �������� ������ ������. 
//���� ���� ������ ���ηδ� ����ġ�� ��ȣ�� �������� ������ ������ ���ηδ� ����ġ�� ������ Ƚ���� �������� ������ ������. 
//��� ������ ���� ����� ����ϸ� ����� ���� �ð��� ������ �� �ִ� �ݸ� �Ʒ� ����� ����ϸ� ����� ���� �߰� �ð��� �ҿ��Ѵ�.

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
	//���� ��� 1 : ���� ã�� �� �ִ� ��� 
	if (is_sync())	return 0;
	//���� ��� 2 : ���� ã�� �� ���� ��� 
	if (depth <= 0)	return MAX_NUM;
	int ret = MAX_NUM + 1;
	int tmp;

	for (int i = 0; i < 4; i++) {
		move_clock_forward(clock_switches[10-depth],i);
		tmp = sync_clock(depth - 1);
		ret = (ret > (tmp + i)) ? (tmp + i) : ret;
		move_clock_backward(clock_switches[10-depth], i);
	}

	//���� ��� 1, 2 : ���� ã�� ��� + ���� ã�� �� ���� ��� 
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