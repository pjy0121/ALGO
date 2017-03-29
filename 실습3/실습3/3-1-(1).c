//2013112149 박지용
//문제 1-1번. 순환적인 합병 정렬
#include <stdio.h>
#define NUM_OF_KEYS 10

// 각각의 부분배열들을 합병하며 정렬하는 함수
void merge(int A[], int left, int mid, int right)
{
	int i;
	int Buffer[NUM_OF_KEYS];	// 정렬된 값을 임시로 저장할 배열
	int L = left, R = mid+1, B = left;	/* L은 현재 왼쪽배열의 index
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
	for (i = left; i <= right; i++)
		A[i] = Buffer[i];	//정렬이 끝난 배열을 A에 옮겨줌
}

//left부터 right까지의 배열 원소를 합병정렬하는 함수
void merge_sort(int A[], int left, int right)
{
	int mid, i;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(A, left, mid);	// 왼쪽 배열 합병정렬
		printf("☆ 왼쪽 : [");
		for (i = left; i <= mid; i++)
			printf("%d ", A[i]);
		printf("] / ");
		
		merge_sort(A, mid + 1, right); // 오른쪽 배열 합병정렬
		printf("오른쪽 : [");
		for (i = mid + 1; i <= right; i++)
			printf("%d ", A[i]);
		printf("] ★ ");
		merge(A, left, mid, right);
		printf("합병 => [");
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
	printf("처음 A = [");
	for (i = left; i <= right; i++)		// 정렬하기 전 배열 출력부분
		printf("%d ", A[i]);
	printf("]\n");
	merge_sort(A, left, right);
	printf("\nresult = [");
	for (i = left; i <= right; i++)		// 정렬 후 배열 출력부분
		printf("%d ", A[i]);
	printf("]\n");
	return 0;
}