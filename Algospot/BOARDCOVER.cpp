/*
#include <stdio.h>

char board[22][22];

int H, W;
int block[4][3][2] = { {{0,0},{1,0},{1,1}},
					   {{0,0},{0,1},{1,1}},
					   {{0,0},{1,0},{1,-1}},
					   {{0,0},{0,1},{1,0}} };

int fillBoard() {

	int cur_x, cur_y;
	int nx, ny;
	int num = 0;
	int find = 0;

	for (cur_y = 0; cur_y < H; cur_y++)
	{
		for (cur_x = 0; cur_x < W; cur_x++)
			if (board[cur_y][cur_x] != '#') {
				find = 1;
				break;
			}
		if (find)
			break;
	}
	//기저 사례 1 : Board를 모두 Block으로 채운 경우 
	if (cur_y >= H && cur_x >= W) {
		return 1;
	}

	for (int i = 0; i < 4; i++)
	{
		find = 0;
		for (int j = 0; j < 3; j++)
		{
			ny = cur_y + block[i][j][0];
			nx = cur_x + block[i][j][1];
			if (nx < 0 || nx >= W) {
				find = 0;
				break;
			}
			if (ny < 0 || ny >= H) {
				find = 0;
				break;
			}
			if (board[ny][nx] == '#')
			{
				find = 0;
				break;
			}
			find = 1;
		}
		if (find)
		{
			for (int j = 0; j < 3; j++)
			{
				ny = cur_y + block[i][j][0];
				nx = cur_x + block[i][j][1];
				board[ny][nx] = '#';
			}
			num = num +  fillBoard();
			for (int j = 0; j < 3; j++)
			{
				ny = cur_y + block[i][j][0];
				nx = cur_x + block[i][j][1];
				board[ny][nx] = '.';
			}
		}
	}

	//기저 사례 2 : Block으로 Board의 모든 칸을 채울 수 없는 경우 -> 0 리턴 
	//지금 까지 찾은 Board의 모든 칸을 Block으로 채울 수 있는 방법의 수 (기저 사례 2가 아닌 경우) 
	return num;
}


int main(void) {
	int C;
	int num;

	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		num = 0;
		scanf("%d %d", &H, &W);
		for (int y = 0; y < H; y++)
		{
			while (getchar() != '\n');
			for (int x = 0; x < W; x++)
				scanf("%c", board[y] + x);
		}
		printf("%d\n", fillBoard());
	}
	 

	return 0;
}
*/