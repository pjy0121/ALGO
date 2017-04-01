// 2013112149 박지용
// Dinamic Programming을 통한 Manhattan Tourist Problem : 최종적으로 가장 많은 볼거리를 보면 되는 문제

typedef struct _VERTEX
{
	int right;		// 각 정점의 오른쪽 가중치
	int down;		// 각 정점의 아래쪽 가중치
}VERTEX;

#include <stdio.h>

int main(void)
{
	VERTEX ver[5][5] =
	{	{ {3, 1}, {2, 0}, {4, 2}, {0, 4}, {0, 3} },
		{ {3, 4}, {2, 6}, {4, 5}, {1, 2}, {0, 1} },
		{ {0, 4}, {7, 4}, {3, 5}, {4, 2}, {0, 1} },
		{ {3, 5}, {3, 6}, {0, 8}, {2, 5}, {0, 3} },
		{ {1, 0}, {3, 0}, {2, 0}, {2, 0}, {0, 0} }	};	// 각각의 정점은 정점의 {오른쪽 가중치, 아래쪽 가중치}로 정의

	int weight[5][5] = { 0, }, visited[5][5] = { 0, };	// weight는 각 정점들의 가중치를 담는 배열, visited는 방문된 정점을 확인하기 위한 배열
	int i, j, a = 0, b = 0;
	weight[0][0] = 0; visited[4][4] = 1;		// 첫번째 정점의 가중치는 0이어야하고 맨 마지막 정점은 반드시 방문되어야 함

	for (i = 1; i < 5; i++)
		weight[i][0] = weight[i - 1][0] + ver[i-1][0].down;	// 0열에 있는 정점들의 가중치 부여
	for (j = 1; j < 5; j++)
		weight[0][j] = weight[0][j - 1] + ver[0][j - 1].right;		// 0행에 있는 정점들의 가중치 부여
	for (i = 1; i < 5; i++)
	{
		for (j = 1; j < 5; j++)
		{
			a = weight[i][j - 1] + ver[i][j - 1].right;	// 왼쪽에서 오른쪽으로 가는 경우
			b = weight[i - 1][j] + ver[i - 1][j].down;		// 위에서 아래로 갈 경우

			if (a > b)
				weight[i][j] = a;	// 오른쪽의 가중치를 더해준다
			else
				weight[i][j] = b;	// 왼쪽의 가중치를 더해준다
		}
	}

	i = 4; j = 4;	// 맨 마지막 정점부터
	while (i >= 0 && j >= 0)	//	제일 앞 정점까지 Backtracking
	{
		if (i == 1 || j == 1)	// 정점에 부여된 가중치(weight)만 따라갈 경우에 발생하는 문제 해결(1행 이하 혹은 1열 이하 일 때만)
		{
			if (ver[i - 1][j].down > ver[i][j - 1].right)	// 현재 정점의 위쪽 간선과 왼쪽 간선을 비교
			{
				visited[i - 1][j] = 1;	
				i--;
			}
			else
			{
				visited[i][j - 1] = 1;	// 가중치가 더 큰 쪽으로 간다
				j--;
			}
		}
		else
		{
			if (weight[i - 1][j] >= weight[i][j - 1])
			{
				visited[i - 1][j] = 1;
				i--;
			}
			else
			{
				visited[i][j - 1] = 1;		// 맨 뒤에서 전 단계의 정점(위 or 왼쪽) 중 가중치가 큰 쪽으로 향한다
				j--;
			}
		}
	}

	printf("weight\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%2d ", weight[i][j]);	// 정점에 부여된 가중치 출력
		printf("\n");
	}
	printf("\n");
	printf("visited\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%2d ", visited[i][j]);		// 방문된 위치들 출력
		printf("\n");
	}
	printf("\n");
}
