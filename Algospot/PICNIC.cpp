/*
#include <stdio.h>

int friends[11][11];
int paired[11];


int makePair(int n)
{
	int cur = -1;
	int pairs = 0;

	for (int i = 0; i < n; i++)
		if (paired[i] == 0)
		{
			cur = i;
			break;
		}
	if (cur < 0)	return 1;
	paired[cur] = 1;
	for (int i = 0; i < n; i++)
	{
		if (paired[i])	continue;
		if (!friends[cur][i])	continue;
		paired[i] = 1;
		pairs += makePair(n);
		paired[i] = 0;
	}
	paired[cur] = 0;
	return pairs;
}

int main(void)
{
	int C;
	int n, m;
	int fr1, fr2;

	scanf("%d", &C);
	for (int i = 0; i < C; i++) {
		scanf("%d %d", &n, &m);
		for (int j = 0; j < m; j++)
		{
			scanf("%d %d", &fr1, &fr2);
			friends[fr1][fr2] = friends[fr2][fr1] = 1;
		}

		printf("%d\n", makePair(n));

		for (int r = 0; r < 11; r++)
		{
			for (int c = 0; c < 11; c++)
				friends[r][c] = 0;
			paired[r] = 0;
		}
	}

	return 0;
}
*/