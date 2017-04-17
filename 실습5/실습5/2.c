// 2013112149 ������
// ���� 2��. Dinamic Programming�� �̿��� ������ȯ ����

#include <stdio.h>
#define M 11

int find_min(int a, int b, int c)
{
	int min = (a < b ? a : b);
	min = (min < c ? min : c);

	return min;
}

// ���� ���Ƚ���� �ּڰ��� ã�� �Լ�
int smallest(int m, int c[], int d)
{
	int result = 0, x = 100, y = 100, z = 100;	// x�� 5���� ���� �������� �������� �����Ƿ� �� ������� ġ���ʱ� ���� ó������ ���� ū ���� �־���
	if (m >= 0 && m <= 1)
		return m;	// m�� 0�� ���� ������ 0, m�� 1�� ���� ������ 1 

	if (m >= 5)
		x = smallest(m - 5, c, d);
	if (m >= 3)
		y = smallest(m - 3, c, d);
	if (m >= 1)
		z = smallest(m - 1, c, d);

	return find_min(x, y, z) + 1;	// m-5��°�� m-3��°, m-1��°���� �ּ��� ������ 1���� ������ �� �����
}

int main(void)
{
	int c[] = { 1, 3, 5 };
	int m = M, d = 3, i;
	int k[3] = { 0, };
	printf("���� �ּ� ��밳�� : %d\n", smallest(m, c, d));

	return 0;
}