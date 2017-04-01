// 2013112149 ������
// ���� 1. �迭�� ���ҵ� �� �ּڰ��� �ִ� ã��

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ARRAY_SIZE 1000

// �迭�� ���ҵ� �� �ּڰ��� ���ϴ� �Լ�
int minimum(int A[], int n)
{
	int min = A[0], i;
	for (i = 0; i < n; i++)
		if (A[i] < min)		// min������ ���� ���� ������ min�� �־���
			min = A[i];
	return min;
}

// �迭�� ���ҵ� �� �ִ��� ���ϴ� �Լ�
int maximum(int A[], int n)
{
	int max = A[0], i;
	for (i = 0; i < n; i++)
		if (A[i] > max)		// // max������ ū ���� ������ max�� �־���
			max = A[i];
	return max;
}

int min_value = 0, max_value = 0;	// �ּڰ��� ������ min_value�� �ִ��� ������ max�� ���������� ����

// �迭�� ���ҵ� �� �ּڰ��� �ִ��� ���ÿ� ���ϴ� �Լ�
void findMaxMin(int A[], int n)
{
	int i;
	min_value = max_value = A[0];
	for (i = 0; i < n; i++)
	{
		if (A[i] < min_value)
			min_value = A[i];
		if (A[i] > max_value)
			max_value = A[i];
	}
}

int main(void)
{
	int i, n = MAX_ARRAY_SIZE;
	int A[MAX_ARRAY_SIZE];
	srand((unsigned)time(NULL));	// rand �Լ����� ������ ���鿡 ��ȭ�� �ֱ� ����
	
	for (i = 0; i < n; i++)
		A[i] = (int)((rand() << 15) | rand()) % 100000 + 1;	// A�迭�� �� ���ҵ鿡 1 ~ 100000 ������ ������ ���� �־���

	printf("minimum �Լ��� �̿�\n�ּڰ� : %d\n", minimum(A, n));
	printf("maximum �Լ��� �̿�\n�ִ� : %d\n", maximum(A, n));
	findMaxMin(A, n);
	printf("findMaxMin �Լ��� �̿�\n�ּڰ� : %d, �ִ� : %d\n", min_value, max_value);
	return 0;	
}