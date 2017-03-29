// 2013112149 박지용
// 문제 2번. 피보나치 수열 알고리즘

#include <stdio.h>

// recursive형태로 구현한 피보나치 수열
int fibonacci(int n)
{
	if (n == 1 || n == 2) return 1;		// input이 양수라는 전제 하에 0이하의 수에 대해서 고려하는 코드는 작성하지 않음
	else return fibonacci(n - 1) + fibonacci(n - 2);	// 피보나치 수열의 정의
}
int main(void)
{
	int n;
	for (n = 1; n <= 20; n++)
		printf("F%d = %d\n", n, fibonacci(n));
	return 0;
}