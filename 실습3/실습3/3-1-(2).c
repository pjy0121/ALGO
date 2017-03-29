// 2013112149 ������
//���� 1-2��. ���ȯ�� �պ� ����

// ������ �κй迭���� �պ��ϸ� �����ϴ� �Լ�

#include <stdio.h>
#define NUM_OF_KEYS 10

void merge(int A[], int left, int mid, int right)
{
	int i;
	int Buffer[NUM_OF_KEYS];	// ���ĵ� ���� �ӽ÷� ������ �迭
	int L = left, R = mid + 1, B = left;	/* L�� ���� ���ʹ迭�� index
											R�� ���� �����ʹ迭�� index
											B�� ���� Buffer�迭�� index
											*/
	while (L <= mid && R <= right)
	{
		if (A[L] < A[R])
			Buffer[B++] = A[L++];	// �����ʰ� ���� �� ���� ���� ���ۿ� �־���
		else
			Buffer[B++] = A[R++];
	}
	if (L > mid)	// ���� �迭�� ���Ұ� �� ���۷� ������
	{
		for (i = R; i <= right; i++)
			Buffer[B++] = A[i];	// ������ �迭�� �� �־���
	}
	else	// ���� �迭�� ���Ұ� �� ���۷� ������
	{
		for (i = L; i <= mid; i++)
			Buffer[B++] = A[i];	// ���� �迭�� �� �־���
	}
	printf("[");
	for (i = left; i <= right; i++)
	{
		A[i] = Buffer[i];	//������ ���� �迭�� A�� �Ű���
		printf("%d ", Buffer[i]);
	}
	printf("]");
}

// ���ȯ�� �պ����� - ����/���� ����� �ƴ� ���� ���
void merge_sort(int A[], int left, int right)
{
	int mid, i, j, n = NUM_OF_KEYS;
	static int count = 0;
	for (i = 1; i < n; i *= 2)
	{
		left = 0;	// left index�� �� ����Ŭ(while)�� 1�� Ŀ���Ƿ� �ᱹ n�� ���ٵ�, n�� �ɶ����� 0���� ���ƿ;��Ѵ�. 
		printf("�պ����� %d : ", ++count);
		while (left < n)
		{
			right = left + 2 * i - 1;	// right�� 2*i������ Ŀ�������� ��
			if (right >= n)
				right = n-1;
			mid = left + i - 1;		/* ��ü �������� ����(NUM_OF_KEYS)�� 2�� ��������(4, 8, ...) ���� mid�� (left+right)/2 ����
									   ��������� �����Ͱ� 2�� �������� �������� �ʰ� ���� ���� ������ �ݺ������� �����ϰ� �ȴ�. */
			if (mid < n)	// ���� mid�� n���� ���� ���� ������ ����� �Ѵ�. ((left+right)/2�� ����� n�� ���� ���� ���� ����)
				merge(A, left, mid, right);
			left = right + 1;
		}
		printf("\n");
	}
}

int main(void)
{
	int A[] = { 30, 20, 40, 35, 5, 50, 45, 10, 25, 15 };
	int right = NUM_OF_KEYS-1, left = 0, i;
	printf("���ҵ� A = ");
	for (i = 0; i <= right; i++)		// ó�� �迭 A�� ������ �� ���
		printf("[%d] ", A[i]);
	printf("\n");
	merge_sort(A, left, right);
	printf("result = [");
	for (i = left; i <= right; i++)		// ���� ��� ���
	{
		printf("%d ", A[i]);
	}
	printf("]\n");
	return 0;
}