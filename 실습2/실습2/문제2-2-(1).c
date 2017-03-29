// 2013112149 박지용
//실습문제 2 - 1번. 선택정렬 알고리즘

#include <stdio.h>

//배열 a의 idx1번째 index의 원소와 idx2번째 index의 원소의 값을 바꾸는 함수 
void swap(int a[], int idx1, int idx2)
{
	int temp = 0;
	temp = a[idx1];
	a[idx1] = a[idx2];
	a[idx2] = temp;
}

//선택정렬 알고리즘
void selection_sort(int a[], int n)
{
	int i, j, k, min = 0, idx = 0;
	static int count = 0;	//count는 출력을 위한 단계를 세주기 위해 만들었음
	for (i = 0; i < n - 1; i++)
	{
		min = a[i];		// i번째 원소부터 배열의 끝까지 비교할 것이므로 a[i]에서 시작
		for (j = i+1; j < n; j++)
		{
			if (a[j] < min)		// a[i]보다 작은놈이 나타나면 그놈을 최솟값으로 지정... 반복
			{
				min = a[j];
				idx = j;	//idx는 배열 나머지 부분 중 최솟값인 원소의 index
			}
		}
		if (min < a[i])
			swap(a, idx, i);	/* 최솟값이 처음 index(= i)의 원소보다 작으면 두 수의 자리를 바꿈
								이걸 i가 n-1이 될때까지 반복
								*/
		printf("%d단계 : a = (", ++count);
		for (k = 0; k < n; k++)
			printf("%d ", a[k]);		//단계별 출력
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
		printf("%d ", a[i]);		//최종 결과 출력
	printf(")\n");
	return 0;
}