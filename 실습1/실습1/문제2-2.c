// 2013112149 박지용

//문제 2번 - 2
#include <stdio.h>
#include <stdlib.h>

//탐욕 알고리즘
int* GreedyBetterChange(int M, int c[], int d)		//M : 바꿀 액수, c[] : 쓸 수 있는 동전들의 집합, d : 동전의 총 개수
{
	int *k = (int*)malloc(sizeof(int));
	int i, ki;	//ki는 배열 k에 들어갈 원소
	for (i = 0; i < d; i++)
	{
		ki = M / c[i];
		M = M - c[i] * ki;

		k[i] = ki;
	}
	return k;	//각 코인 별 코인 수를 담은 배열을 return
}

int main(void)
{
	int i;
	int M = 40, c[] = { 25, 20, 10, 5, 1 }, d = 5;	//input datas
	int *k = NULL;
	k = GreedyBetterChange(M, c, d);
	printf("coins = ( 25, 20, 10, 5,  1, )\n");
	printf("count = (");			//k 배열을 출력 시 count(개수)라고 하였음
	for(i=0; i<d; i++)
		printf("%2d, ", k[i]);
	printf(")\n");
}