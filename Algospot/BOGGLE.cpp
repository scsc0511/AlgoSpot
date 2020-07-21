//문제를 풀면서 잘 생각해내지 못했던 것 
//시작 지점을 어떻게 정해야 하는지(즉 (y,x)를 어떻게 정해야 하는지  
//같은 지점에 중복해서 방문할 수 있는지 
//기저 사례를 어떻게 지정해야 하는지 

/*
#include <stdio.h>
#include <string.h>

char board[6][7];
char words[11][12];
bool visit[6][7];


int dx[8] = {0,0,-1,1,-1,1,-1,1};
int dy[8] = {1,-1,0,0,-1,-1,1,1};

int boggle(int x, int y,int w_id, int eq_cnt, int len) {
	if (eq_cnt >= (len-1))	return 1;
	int nx, ny;

	for (int i = 0; i < 8; i++)
	{
		nx = x + dx[i]; ny = y + dy[i];
		if (nx < 0 || nx >4)	continue;
		if (ny < 0 || ny>4)		continue;
		if (board[ny][nx] != words[w_id][eq_cnt+1])	continue;
		if(boggle(nx,ny, w_id, eq_cnt + 1,len))
			return 1;

	}

	return 0;
}

int main(void) {
	int C,N;
	int find_flag;

	scanf("%d", &C);

	for (int i = 0; i < 5; i++)
		scanf("%s", board[i]);


	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", words[i]);
	}
	for (int i = 0; i < N; i++) {
		find_flag = 0;
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				if (board[y][x] == words[i][0])	
					find_flag = boggle(x, y, i, 0, strlen(words[i]));
				if (find_flag)	break;
			}
			if (find_flag)	break;
		}
		if (find_flag)
			printf("%s YES\n", words[i]);
		else
			printf("%s NO\n", words[i]);
	}


	return 0;
}
*/