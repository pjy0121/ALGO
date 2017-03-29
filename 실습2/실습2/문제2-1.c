//2013112149 박지용
//실습문제 1번. BruteForceChange 알고리즘을 Recursive형태로 구현해보기

#include <stdio.h>

int smallest_sum = 1000;
int howMuch = 0, sum = 0;
int k[6];

int BruteForceChange(int M, int c[], int d)
{
	int i;
	for (i = 0; i < d; i++)
	{
		k[i] = M / c[i];	//맨 처음 k의 배열의 값을 부여해줌
		howMuch = c[0] * k[0] + c[1] * k[1] + c[2] * k[2] + c[3]*k[3] + c[4]*k[4] + c[5]*k[5]; //howMuch는 각 코인의 액수와 쓰인 횟수를 곱한 것의 합(총 금액)
		sum = k[0] + k[1] + k[2] + k[3] + k[4] + k[5];	//+= 을 이용하면 howMuch와 sum의 값을 다시 초기화시켜야 하는 문제가 발생하므로 직접 입력해줌

		if (howMuch == 40)	//처음 입력한 M과 같을 때
		{
			printf("k = (%d %d %d %d %d %d)\n, sum = %d\n", k[0], k[1], k[2], k[3], k[4], k[5], sum);
			if (sum < smallest_sum)
				smallest_sum = sum;
		}
		if (M / c[i] != 0)
		{
			BruteForceChange(M - c[i], c, d);
		}

	}
	return smallest_sum;
}

int main(void)
{ㄴ
	int M = 40, d = 6;
	int c[] = { 25, 20, 15, 10, 5, 1 };
	
	printf("M = 40일 때의 코인 최소 사용 개수 : %d\n", BruteForceChange(M, c, d));
	return 0;
}