// 2013112149 ������
//���� 2-1��. �� ���� �˰���

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

int main(void)
{
	int A[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	int i, j, n = SIZE_OF_HEAP;
	printf("�迭 A = [");
	for (i = 0; i < n; i++)		// ���� �� �迭 ���
		printf("%d ", A[i]);
	printf("]\n");
	for (i = 1; i <= n / 2; i++)	// n/2���� �ص� ���� ��ȭ�� ���ٴ� ���� Ȯ��
	{
		for (j = i; j >= 0; j--)
			make_heap(A, j, n - 1);		// �迭�� heap���� ��ȯ����(���� for�� �̿�)
	}
	printf("heap A = [");
	for (i = 0; i < n; i++)		// ��� �迭 ���
		printf("%d ", A[i]);
	printf("]\n");
	return 0;
}