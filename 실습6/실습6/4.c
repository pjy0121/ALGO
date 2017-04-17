#include <stdio.h>

int get_count(int n)
{
	static int count = 0;	// 연산횟수를 카운트하는 변수
	while (n != 1)
	{
		printf("%d. n = %d  ", count, n);
		count++;
		if (n % 3 == 0)
		{
			n /= 3; 
			printf("/3\n", n);
			continue;
		}
		if ((n - 1) % 3 == 0)
		{
			n--; printf("-1\n");
			continue;
		}
		if (n % 2 == 0)
		{
			n /= 2; printf("/2\n");
			continue;
		}
		n--; printf("-1\n");
	}
	printf("연산 끝! n = %d", n);
	return count;
}

int main(void)
{
	int input_number = 0;
	printf("연산횟수를 구하고 싶은 정수를 입력하세요\n: ");
	scanf("%d", &input_number);
	printf("입력하신 숫자 %d에 필요한 연산횟수는 %d회 입니다.\n", input_number, get_count(input_number));
}