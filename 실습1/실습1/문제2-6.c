// 2013112149 박지용

//문제 2번 - 6
#include <stdio.h>
#include <stdlib.h>

//탐욕 알고리즘
void GreedyBetterChange(int M, int c[], int d, int *k)		//M : 바꿀 액수, c[] : 쓸 수 있는 동전들의 집합, d : 동전의 총 개수
{
	int i, ki;	//ki는 배열 k에 들어갈 원소
	for (i = 0; i < d; i++)
	{
		ki = M / c[i];
		M = M - c[i] * ki;

		k[i] = ki;
	}
	return k;	//각 코인 별 코인 수를 담은 배열을 return
}

//전역탐색 알고리즘
void BruteForceChange(int M, int c[], int d, int *k)
{
	int smallest_sum = 1000;
	int k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0, sum = 0, howMuch = 0;	//sum은 총 코인 사용 개수, howMuch는 각각의 코인수*코인값을 다 더해서 나온 금액
	for (k1 = 0; k1 <= M / c[0]; k1++)		//5중 for문을 이용해 각 코인이 쓰인 횟수(k1, k2, k3, k4, k5)를 늘려가면서 모든 경우의 수를 계산
	{
		for (k2 = 0; k2 <= M / c[1]; k2++)
		{
			for (k3 = 0; k3 <= M / c[2]; k3++)
			{
				for (k4 = 0; k4 <= M / c[3]; k4++)
				{
					for (k5 = 0; k5 <= M / c[4]; k5++)
					{
						howMuch = k1*c[0] + k2*c[1] + k3*c[2] + k4*c[3] + k5*c[4];
						if (howMuch == M)		// 금액이 주어진 금액과 같으면
						{
							sum = k1 + k2 + k3 + k4 + k5;

							if (sum < smallest_sum)
							{
								smallest_sum = sum;
								k[0] = k1; k[1] = k2; k[2] = k3; k[3] = k4; k[4] = k5;
								//sum이 최소가 될 때의 코인이 쓰인 횟수(k1, ..., k5)를 배열에 저장 
							}
						}
					}
				}
			}
		}
	}
	return k;
}

int array_compare(int a[], int b[], int d)
{
	int i=0;
	while(i<d)
	{
		if (a[i] == b[i])
		{
			i++;
			continue;
		}
		else
			return 0;
	}
	return 1;
}

int main(void)
{
	int M, d = 5, modified_d = 6, i;
	int c[] = { 25, 20, 10, 5, 1 };
	int modified_c[] = { 25, 20, 10, 15, 5, 1 };
	int *k1 = (int*)malloc(sizeof(int)); 
	int *k2 = (int*)malloc(sizeof(int));

	for (M = 1; M < 100; M++)
	{
		GreedyBetterChange(M, c, d, k1);
		BruteForceChange(M, c, d, k2);
		if (!array_compare(k1, k2, d))
		{
			printf("M = %d\n", M);
			printf("GreedyBetterChange : (");
			for (i = 0; i < d; i++)
			{
				printf("%d, ", k1[i]);
			}
			printf(") / BruteForceChange : (");
			for (i = 0; i < d; i++)
			{
				printf("%d, ", k2[i]);
			}
			printf(")\n");
		}
	}
	return 0;
}