// 2013112149 ������
//�ǽ����� 2 - 2��. ���������� recursive���·� �����ϱ�

#include <stdio.h>

//���̰� n�� �迭���� ���� ���� ������ index�� ��ȯ
int min_array_index(int a[], int n)
{
	int i, idx = 0, min = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[i] < min)		// a[0]���� ���� ���� ��Ÿ���� �׳��� �ּڰ����� ����... �ݺ�
		{
			min = a[i];	
			idx = i;	// �ּڰ��� ���� index
		}
	}
	return idx;
}

//�迭 a�� idx1��° index�� ���ҿ� idx2��° index�� ������ ���� �ٲٴ� �Լ� 
void swap(int a[], int idx1, int idx2)
{
	int temp = 0;
	temp = a[idx1];
	a[idx1] = a[idx2];
	a[idx2] = temp;
}

//�������� �˰���(���)
void selection_sort(int a[], int n)
{
	int i;
	static int count = 0;
	int min_idx = 0;	// �� �������� ���� ���� ������ index
	if (n > 1)
	{
		min_idx = min_array_index(a, n);	// min_array_index �Լ��� ���� ���� ���� ����
		printf("%d�ܰ�. a = (", count++);
		for (i = 0; i < 8; i++)
		{
			printf("%d ", a[i]);
		}
		printf(")\n");
		swap(a, min_idx, n - 1);		// n-1��° ����(���� ������ ����)�� ���� ���� ���Ҹ� �ٲ���
		selection_sort(a, n - 1);	/* �迭�� ũ�⸦ �ϳ� �ٿ��� ������ �κе鿡�� �ٽ� �ּڰ��� ����
												�ٲ��ִ� ������ �ݺ� */
	}
}

int main(void)
{
	int a[] = { 30, 20, 40, 10, 5, 10, 30, 15 };
	int n = 8, i;
	selection_sort(a, n);

	/* ���� ���� ������ �迭�� �ּڰ��� �� ���ڸ��� �ٲٴ� ������ �ݺ��ϴ� 
		������ ���������� �������� �����Ͽ����� �������� ��� 
		���� ������η� ���� ���� ������ indexing�� �����Ͽ� �� ������� �Ͽ��� */
	printf("������� : (");
	for (i = n - 1; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}
	printf(")\n");
	return 0;
}