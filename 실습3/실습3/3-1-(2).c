// 2013112149 박지용
//문제 1-2번. 비순환적 합병 정렬

// 각각의 부분배열들을 합병하며 정렬하는 함수

#include <stdio.h>
#define NUM_OF_KEYS 10

void merge(int A[], int left, int mid, int right)
{
	int i;
	int Buffer[NUM_OF_KEYS];	// 정렬된 값을 임시로 저장할 배열
	int L = left, R = mid + 1, B = left;	/* L은 현재 왼쪽배열의 index
											R은 현재 오른쪽배열의 index
											B는 현재 Buffer배열의 index
											*/
	while (L <= mid && R <= right)
	{
		if (A[L] < A[R])
			Buffer[B++] = A[L++];	// 오른쪽과 왼쪽 중 작은 값을 버퍼에 넣어줌
		else
			Buffer[B++] = A[R++];
	}
	if (L > mid)	// 왼쪽 배열의 원소가 다 버퍼로 들어갔으면
	{
		for (i = R; i <= right; i++)
			Buffer[B++] = A[i];	// 오른쪽 배열을 다 넣어줌
	}
	else	// 왼쪽 배열의 원소가 다 버퍼로 들어갔으면
	{
		for (i = L; i <= mid; i++)
			Buffer[B++] = A[i];	// 왼쪽 배열을 다 넣어줌
	}
	printf("[");
	for (i = left; i <= right; i++)
	{
		A[i] = Buffer[i];	//정렬이 끝난 배열을 A에 옮겨줌
		printf("%d ", Buffer[i]);
	}
	printf("]");
}

// 비순환적 합병정렬 - 분할/정복 방식이 아닌 정복 방식
void merge_sort(int A[], int left, int right)
{
	int mid, i, j, n = NUM_OF_KEYS;
	static int count = 0;
	for (i = 1; i < n; i *= 2)
	{
		left = 0;	// left index는 한 사이클(while)에 1씩 커지므로 결국 n이 될텐데, n이 될때마다 0으로 돌아와야한다. 
		printf("합병과정 %d : ", ++count);
		while (left < n)
		{
			right = left + 2 * i - 1;	// right는 2*i단위로 커져나가야 함
			if (right >= n)
				right = n-1;
			mid = left + i - 1;		/* 전체 데이터의 개수(NUM_OF_KEYS)가 2의 제곱수일(4, 8, ...) 때는 mid가 (left+right)/2 여도
									   상관없지만 데이터가 2의 제곱수로 떨어지지 않고 남을 때는 병합을 반복적으로 수행하게 된다. */
			if (mid < n)	// 따라서 mid가 n보다 작을 때만 병합을 해줘야 한다. ((left+right)/2는 절대로 n을 넘을 수가 없기 때문)
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
	printf("분할된 A = ");
	for (i = 0; i <= right; i++)		// 처음 배열 A를 분할한 것 출력
		printf("[%d] ", A[i]);
	printf("\n");
	merge_sort(A, left, right);
	printf("result = [");
	for (i = left; i <= right; i++)		// 정렬 결과 출력
	{
		printf("%d ", A[i]);
	}
	printf("]\n");
	return 0;
}