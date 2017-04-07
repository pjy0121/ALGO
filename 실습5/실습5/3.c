#include <stdio.h>
#define M 6
#define N 6

int main(void)
{
	int game[M][N] = { 1, };
	int m, n;
	game[0][0] = 0;
	game[1][0] = 1;
	game[0][1] = 1;
	game[1][1] = 1;

	for (m = 0; m < M; m++)
	{
		for (n = 0; n < N; n++)
		{
			if (game[m][n] == 0)
			{
				game[m + 1][n + 1] = 1;
				game[m + 1][n] = 1;
				game[m][n + 1] = 1;
			}
			else if (game[m - 1][n - 1] == 1 && game[m - 1][n] == 1 && game[n][m - 1] == 1)
				game[m][n] = 0;

		}
	}

	for (m = 0; m < M; m++)
	{
		for (n = 0; n < N; n++)
			printf("%d ", game[m][n]);
		printf("\n");
	}
	return 0;
}