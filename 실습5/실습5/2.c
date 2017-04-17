// 2013112149 박지용
// 문제 2번. Dinamic Programming을 이용한 동전교환 문제

#include <stdio.h>
#define M 11

int find_min(int a, int b, int c)
{
	int min = (a < b ? a : b);
	min = (min < c ? min : c);

	return min;
}

// 동전 사용횟수의 최솟값을 찾는 함수
int smallest(int m, int c[], int d)
{
	int result = 0, x = 100, y = 100, z = 100;	// x는 5보다 작은 범위에서 존재하지 않으므로 비교 대상으로 치지않기 위해 처음부터 아주 큰 값을 넣어줌
	if (m >= 0 && m <= 1)
		return m;	// m이 0일 때는 무조건 0, m이 1일 때는 무조건 1 

	if (m >= 5)
		x = smallest(m - 5, c, d);
	if (m >= 3)
		y = smallest(m - 3, c, d);
	if (m >= 1)
		z = smallest(m - 1, c, d);

	return find_min(x, y, z) + 1;	// m-5번째와 m-3번째, m-1번째에서 최소인 값에서 1개의 코인을 더 써야함
}

int main(void)
{
	int c[] = { 1, 3, 5 };
	int m = M, d = 3, i;
	int k[3] = { 0, };
	printf("동전 최소 사용개수 : %d\n", smallest(m, c, d));

	return 0;
}