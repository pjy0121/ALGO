//2013112149 ������
//���� 1-1��. ��ȯ���� �պ� ����
#include <stdio.h>
#define NUM_OF_KEYS 10

// ������ �κй迭���� �պ��ϸ� �����ϴ� �Լ�
void merge(int A[], int left, int mid, int right)
{
	int i;
	int Buffer[NUM_OF_KEYS];	// ���ĵ� ���� �ӽ÷� ������ �迭
	int L = left, R = mid+1, B = left;	/* L�� ���� ���ʹ迭�� index
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
	for (i = left; i <= right; i++)
		A[i] = Buffer[i];	//������ ���� �迭�� A�� �Ű���
}

//left���� right������ �迭 ���Ҹ� �պ������ϴ� �Լ�
void merge_sort(int A[], int left, int right)
{
	int mid, i;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(A, left, mid);	// ���� �迭 �պ�����
		printf("�� ���� : [");
		for (i = left; i <= mid; i++)
			printf("%d ", A[i]);
		printf("] / ");
		
		merge_sort(A, mid + 1, right); // ������ �迭 �պ�����
		printf("������ : [");
		for (i = mid + 1; i <= right; i++)
			printf("%d ", A[i]);
		printf("] �� ");
		merge(A, left, mid, right);
		printf("�պ� => [");
		for (i = left; i <= right; i++)
			printf("%d ", A[i]);
		printf("]\n");
	}
}

int main(void)
{
	int i;
	int A[] = { 15, 30, 35, 40, 5, 20, 25, 10, 45, 50 };
	int left = 0, right = NUM_OF_KEYS - 1;
	printf("ó�� A = [");
	for (i = left; i <= right; i++)		// �����ϱ� �� �迭 ��ºκ�
		printf("%d ", A[i]);
	printf("]\n");
	merge_sort(A, left, right);
	printf("\nresult = [");
	for (i = left; i <= right; i++)		// ���� �� �迭 ��ºκ�
		printf("%d ", A[i]);
	printf("]\n");
	return 0;
}