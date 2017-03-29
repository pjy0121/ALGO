// 2013112149 ������
//���� 2-2��. �� ���� �˰���

#include <stdio.h>
#define SIZE_OF_HEAP 10

// �� ����
int make_heap(int A[], int root, int last)
{
	int parent, left, right, child, root_value;
	parent = root;
	root_value = A[root];
	left = 2 * parent + 1;
	right = left + 1;
	while (left <= last)	 // left�� ������ ������ �ݺ� ����
	{
		if (right <= last && A[left] < A[right])
		{
			child = right;		// ���ʰ� ������ �� ū���� �ķ��ڽ��� �� �ڰ��� ����
								/* last�� ���� ������ �� ���� : ���� ����Ʈ������ ������ ��尡
								left�� �� �� �ֱ� ������ right�� �������� ���� ���� �ִ� */
		}
		else child = left;
		if (root_value < A[child])
		{
			A[parent] = A[child];	// parent �ڸ��� child �ڸ��� ���Ҹ� �־���
			parent = child;		// child�� �θ�� �ٲ���
			left = parent * 2 + 1;	// �׿� �°� �ڽĵ鵵 �ٲ���
			right = left + 1;
		}
		else break;
	}
	A[parent] = root_value;		// �ᱹ while���� �� ���� �����ִ� �� �ڸ��� root_value�� �־���
}
// �迭�� index1�� index2�� �Է����־��� �� ������ ���Ҹ� �ٲ��ִ� �Լ�
void swap(int A[], int index1, int index2)
{
	int temp = A[index1];
	A[index1] = A[index2];
	A[index2] = temp;
}

// �� ���� �˰���
void heap_sort(int A[], int n)
{
	int i, j;
	for (i = 1; i <= n / 2; i++)
	{
		for (j = i; j >= 0; j--)
			make_heap(A, j, n - 1);		// ������ �迭�� heap���� ��ȯ����
	}
	for (i = n - 1; i > 0; i--)
	{
		swap(A, 0, i);		// heap�� root���Ҹ� A[i]�� ��ȯ����
		make_heap(A, 0, i - 1);		// ���� �͵�� ���ο� heap�� ����
		for (j = 0; j < n; j++)
			printf("%d ", A[j]);
		printf("\n");
	}
}

int main(void)
{
	int i, n = SIZE_OF_HEAP;
	int A[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	printf("�迭 A = [");
	for (i = 0; i < n; i++)		// ���� �� �迭 ���
		printf("%d ", A[i]);
	printf("]\n");
	heap_sort(A, n);
	printf("sorted A = [");
	for (i = 0; i < n; i++)		// ��� �迭 ���
		printf("%d ", A[i]);
	printf("]\n");
	return 0;
}