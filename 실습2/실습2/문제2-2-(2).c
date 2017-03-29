// 2013112149 박지용
//실습문제 2 - 2번. 선택정렬을 recursive형태로 구현하기

#include <stdio.h>

//길이가 n인 배열에서 가장 작은 원소의 index를 반환
int min_array_index(int a[], int n)
{
	int i, idx = 0, min = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[i] < min)		// a[0]보다 작은 놈이 나타나면 그놈을 최솟값으로 지정... 반복
		{
			min = a[i];	
			idx = i;	// 최솟값일 때의 index
		}
	}
	return idx;
}

//배열 a의 idx1번째 index의 원소와 idx2번째 index의 원소의 값을 바꾸는 함수 
void swap(int a[], int idx1, int idx2)
{
	int temp = 0;
	temp = a[idx1];
	a[idx1] = a[idx2];
	a[idx2] = temp;
}

//선택정렬 알고리즘(재귀)
void selection_sort(int a[], int n)
{
	int i;
	static int count = 0;
	int min_idx = 0;	// 각 시점별로 가장 작은 원소의 index
	if (n > 1)
	{
		min_idx = min_array_index(a, n);	// min_array_index 함수를 통해 구한 값을 대입
		printf("%d단계. a = (", count++);
		for (i = 0; i < 8; i++)
		{
			printf("%d ", a[i]);
		}
		printf(")\n");
		swap(a, min_idx, n - 1);		// n-1번째 원소(가장 마지막 원소)와 가장 작은 원소를 바꿔줌
		selection_sort(a, n - 1);	/* 배열의 크기를 하나 줄여서 나머지 부분들에서 다시 최솟값을 구해
												바꿔주는 식으로 반복 */
	}
}

int main(void)
{
	int a[] = { 30, 20, 40, 10, 5, 10, 30, 15 };
	int n = 8, i;
	selection_sort(a, n);

	/* 현재 내가 정렬한 배열은 최솟값을 맨 앞자리와 바꾸는 식으로 반복하는 
		기존의 선택정렬의 역순으로 구현하였으니 역순으로 출력 
		원래 순서대로로 구할 수도 있으나 indexing이 복잡하여 이 방식으로 하였음 */
	printf("역순출력 : (");
	for (i = n - 1; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}
	printf(")\n");
	return 0;
}