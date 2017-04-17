#include <stdio.h>

int get_count(int n)
{
	static int count = 0;	// ����Ƚ���� ī��Ʈ�ϴ� ����
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
	printf("���� ��! n = %d", n);
	return count;
}

int main(void)
{
	int input_number = 0;
	printf("����Ƚ���� ���ϰ� ���� ������ �Է��ϼ���\n: ");
	scanf("%d", &input_number);
	printf("�Է��Ͻ� ���� %d�� �ʿ��� ����Ƚ���� %dȸ �Դϴ�.\n", input_number, get_count(input_number));
}