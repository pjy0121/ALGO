// 2013112149 ������
//�ǽ����� 2 - 1��. �������� �˰���

#include <stdio.h>

//�迭 a�� idx1��° index�� ���ҿ� idx2��° index�� ������ ���� �ٲٴ� �Լ� 
void swap(int a[], int idx1, int idx2)
{
	int temp = 0;
	temp = a[idx1];
	a[idx1] = a[idx2];
	a[idx2] = temp;
}

//�������� �˰���
void selection_sort(int a[], int n)
{
	int i, j, k, min = 0, idx = 0;
	static int count = 0;	//count�� ����� ���� �ܰ踦 ���ֱ� ���� �������
	for (i = 0; i < n - 1; i++)
	{
		min = a[i];		// i��° ���Һ��� �迭�� ������ ���� ���̹Ƿ� a[i]���� ����
		for (j = i+1; j < n; j++)
		{
			if (a[j] < min)		// a[i]���� �������� ��Ÿ���� �׳��� �ּڰ����� ����... �ݺ�
			{
				min = a[j];
				idx = j;	//idx�� �迭 ������ �κ� �� �ּڰ��� ������ index
			}
		}
		if (min < a[i])
			swap(a, idx, i);	/* �ּڰ��� ó�� index(= i)�� ���Һ��� ������ �� ���� �ڸ��� �ٲ�
								�̰� i�� n-1�� �ɶ����� �ݺ�
								*/
		printf("%d�ܰ� : a = (", ++count);
		for (k = 0; k < n; k++)
			printf("%d ", a[k]);		//�ܰ躰 ���
		printf(")\n");
	}
}

int main(void)
{
	int a[] = { 30, 20, 40, 10, 5, 10, 30, 15 };
	int n = 8, i;
	selection_sort(a, n);
	printf("result : a = (");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);		//���� ��� ���
	printf(")\n");
	return 0;
}