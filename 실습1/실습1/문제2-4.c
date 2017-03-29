// 2013112149 박지용

//문제 2번 - 4
#include <stdio.h>
#include <stdlib.h>

int smallest_sum = 1000; /* 사용코인이 최소일 때의 개수
		- BruteForceChange의 return값을 전체 코인값을 담은 포인터로 주기 위해 전역변수로 선언
		- 어차피 가장 작은 sum값을 찾을거니 애초에 아주 큰 수로 초기화하였음  
	*/

//전역탐색 알고리즘
int* BruteForceChange(int M, int c[], int d)
{
	int *k = (int*)malloc(sizeof(int));	//배열화하기 위해 동적할당
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
							printf("(%d,%d,%d,%d,%d), sum = %d\n", k1, k2, k3, k4, k5, sum);	// 가능한 k들과 sum값을 전부 출력

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

int main(void)
{
	int i, d = 5, M = 28;
	int *k;
	int c[5] = { 25,20,10,5,1 };
	k = BruteForceChange(M, c, d);
	printf("\n---- 사용 코인이 최소인 경우 ----\nk = (");
	for (i = 0; i < d; i++)
		printf("%d, ", k[i]);
	printf(")\n사용 코인 개수 = %d\n\n", smallest_sum);
	return 0;
}