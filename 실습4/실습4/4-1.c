// 2013112149 박지용
// 문제 1. 배열의 원소들 중 최솟값과 최댓값 찾기

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ARRAY_SIZE 1000

// 배열의 원소들 중 최솟값을 구하는 함수
int minimum(int A[], int n)
{
	int min = A[0], i;
	for (i = 0; i < n; i++)
		if (A[i] < min)		// min값보다 작은 놈이 나오면 min에 넣어줌
			min = A[i];
	return min;
}

// 배열의 원소들 중 최댓값을 구하는 함수
int maximum(int A[], int n)
{
	int max = A[0], i;
	for (i = 0; i < n; i++)
		if (A[i] > max)		// // max값보다 큰 놈이 나오면 max에 넣어줌
			max = A[i];
	return max;
}

int min_value = 0, max_value = 0;	// 최솟값을 저장할 min_value와 최댓값을 저장할 max를 전역변수로 선언

// 배열의 원소들 중 최솟값과 최댓값을 동시에 구하는 함수
void findMaxMin(int A[], int n)
{
	int i;
	min_value = max_value = A[0];
	for (i = 0; i < n; i++)
	{
		if (A[i] < min_value)
			min_value = A[i];
		if (A[i] > max_value)
			max_value = A[i];
	}
}

int main(void)
{
	int i, n = MAX_ARRAY_SIZE;
	int A[MAX_ARRAY_SIZE];
	srand((unsigned)time(NULL));	// rand 함수에서 나오는 값들에 변화를 주기 위함
	
	for (i = 0; i < n; i++)
		A[i] = (int)((rand() << 15) | rand()) % 100000 + 1;	// A배열의 각 원소들에 1 ~ 100000 사이의 랜덤한 값을 넣어줌

	printf("minimum 함수를 이용\n최솟값 : %d\n", minimum(A, n));
	printf("maximum 함수를 이용\n최댓값 : %d\n", maximum(A, n));
	findMaxMin(A, n);
	printf("findMaxMin 함수를 이용\n최솟값 : %d, 최댓값 : %d\n", min_value, max_value);
	return 0;	
}