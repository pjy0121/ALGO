// 2013112149 ������
// ���� 2��. �Ǻ���ġ ���� �˰���

#include <stdio.h>

// recursive���·� ������ �Ǻ���ġ ����
int fibonacci(int n)
{
	if (n == 1 || n == 2) return 1;		// input�� ������ ���� �Ͽ� 0������ ���� ���ؼ� ����ϴ� �ڵ�� �ۼ����� ����
	else return fibonacci(n - 1) + fibonacci(n - 2);	// �Ǻ���ġ ������ ����
}
int main(void)
{
	int n;
	for (n = 1; n <= 20; n++)
		printf("F%d = %d\n", n, fibonacci(n));
	return 0;
}