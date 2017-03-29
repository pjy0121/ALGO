//2013112149 박지용

//문제 1번
#include <stdio.h>

int find_except(int input[], int n)	//input 배열과 정수의 개수(n)를 받아 제외된 수(x)를 찾음
{
	int i, sum = 0, sum_except = 0;
	int x;
	for (i = 1; i <= n; i++)
		sum += i;		//1~n까지의 합 구하기

	for (i = 0; i < n - 1; i++)		//1개가 제외되면 정수의 개수는 n-1개
		sum_except += input[i];

	x = sum - sum_except;		//1~n까지의 합에서 숫자가 제외된 상태의 합을 빼서 제외된 숫자를 구함

	return x;
}

int main(void)
{
	int n = 0;
	int input[] = { 5,6,2,4,9,10,8,7,1 };	//input배열의 크기가 n이 되어야함
	printf("1~n까지의 정수 중 없는 하나를 찾고싶다. n을 입력하시오.\n");
	scanf_s("%d", &n);

	printf("제외된 수 : %d\n", find_except(input, n));

	return 0;
}