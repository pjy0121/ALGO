//2013112149 ������

//���� 1��
#include <stdio.h>

int find_except(int input[], int n)	//input �迭�� ������ ����(n)�� �޾� ���ܵ� ��(x)�� ã��
{
	int i, sum = 0, sum_except = 0;
	int x;
	for (i = 1; i <= n; i++)
		sum += i;		//1~n������ �� ���ϱ�

	for (i = 0; i < n - 1; i++)		//1���� ���ܵǸ� ������ ������ n-1��
		sum_except += input[i];

	x = sum - sum_except;		//1~n������ �տ��� ���ڰ� ���ܵ� ������ ���� ���� ���ܵ� ���ڸ� ����

	return x;
}

int main(void)
{
	int n = 0;
	int input[] = { 5,6,2,4,9,10,8,7,1 };	//input�迭�� ũ�Ⱑ n�� �Ǿ����
	printf("1~n������ ���� �� ���� �ϳ��� ã��ʹ�. n�� �Է��Ͻÿ�.\n");
	scanf_s("%d", &n);

	printf("���ܵ� �� : %d\n", find_except(input, n));

	return 0;
}