// 2013112149 박지용
// 문제 3번. Dinamic Programming을 이용한 돌 가져오기 게임의 승리 구도

#include <stdio.h>
#define M 10
#define N 7

int turn = 0;

void game(int m, int n)
{
	int left = m, right = n;

	while (left >= 0 && right >= 0)
	{
		if (left == 0 && right == 0)	// 둘 다 0이면 게임을 진행할 수가 없음
			break;
		
		turn++;		// 1턴부터 시작
		printf("%d턴 - ", turn);

		if (turn % 2 != 0)		// 홀수턴일 때(먼저 시작하는 영희의 턴일 때)
		{
			if (left % 2 == 0 && right % 2 != 0)	// 짝홀
			{
				printf("영희가 오른쪽 돌을 하나 가져갑니다.\n");
				right--;
			}
			else if (left % 2 != 0 && right % 2 == 0)	// 홀짝
			{
				printf("영희가 왼쪽 돌을 하나 가져갑니다.\n");
				left--;
			}
			else if (left % 2 != 0 && right % 2 != 0)	// 홀홀
			{
				printf("영희가 양쪽 돌을 하나씩 가져갑니다.\n");
				left--; right--;
			}
			else	// 짝홀
			{
				if ((left > 2 || right > 2) && left != 0 && right != 0)	/* 왼쪽2, 오른쪽2 일 경우 양쪽에서 1개씩 가져가면 안되기 때문
																		그리고 left나 right가 0이면 양쪽에서 가져올 수가 없다 */
				{
					printf("영희가 양쪽 돌을 하나씩 가져갑니다.\n");
					left--; right--;
				}
				else if (left == 0)		// left가 0이면 왼쪽에서 가져올 수가 없다
				{
					printf("영희가 오른쪽 돌을 하나 가져갑니다.\n");
					right--;
				}
				else
				{
					printf("영희가 왼쪽 돌을 하나 가져갑니다.\n");	// 왼쪽에서 가져올 수 있는 경우 왼쪽에서 우선적으로 가져옴(3:2나 2:3은 동일하기 때문)
					left--;
				}
			}
		}
		else		// 짝수턴일 때(늦게 시작하는 철수의 턴일 때)
		{
			if (left % 2 == 0 && right % 2 != 0)	// 짝홀
			{
				printf("철수가 오른쪽 돌을 하나 가져갑니다.\n");
				right--;
			}
			else if (left % 2 != 0 && right % 2 == 0)	// 홀짝
			{
				printf("철수가 왼쪽 돌을 하나 가져갑니다.\n");
				left--;
			}
			else if (left % 2 != 0 && right % 2 != 0)	// 홀홀
			{
				printf("철수가 양쪽 돌을 하나씩 가져갑니다.\n");
				left--; right--;
			}
			else	// 짝홀
			{
				if ((left > 2 || right > 2) && left != 0 && right != 0)			/* 왼쪽2, 오른쪽2 일 경우 양쪽에서 1개씩 가져가면 안되기 때문
																		그리고 left나 right가 0이면 양쪽에서 가져올 수가 없다 */
				{
					printf("철수가 양쪽 돌을 하나씩 가져갑니다.\n");
					left--; right--;
				}
				else if (left == 0)		// left가 0이면 왼쪽에서 가져올 수가 없다
				{
					printf("철수가 오른쪽 돌을 하나 가져갑니다.\n");
					right--;
				}
				else
				{
					printf("철수가 왼쪽 돌을 하나 가져갑니다.\n");	// 왼쪽에서 가져올 수 있는 경우 왼쪽에서 우선적으로 가져옴(3:2나 2:3은 동일하기 때문)
					left--;
				}
			}
		}
		printf("현재 남은 돌의 개수\n: 왼쪽 : %d, 오른쪽 : %d\n", left, right);
	}
}

int main(void)
{
	int m, n;
	for (m = M; m >= 8; m--)
	{
		for (n = N; n >= 6; n--)
		{
			printf("\n*********** %d : %d개 Game Start! ***********\n", m, n);
			game(m, n);
			if (turn % 2 == 0)
			{
				printf("영희의 패배!\n");
				turn = 0;	// 다음 판을 하려면 turn을 0으로 복귀시켜줌
			}
			else
			{
				printf("영희의 승리!\n");
				turn = 0;	// 다음 판을 하려면 turn을 0으로 복귀시켜줌
			}
		}
	}
	return 0;
}