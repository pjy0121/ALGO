// 2013112149 박지용
//문제 2-1번. 힙 생성 알고리즘

#include <stdio.h>
#define SIZE_OF_HEAP 10

// 힙 생성
int make_heap(int A[], int root, int last)
{
	int parent, left, right, child, root_value;
	parent = root;
	root_value = A[root];
	left = 2 * parent + 1;
	right = left + 1;
	while (left <= last)	 // left가 존재할 때까지 반복 수행
	{
		if (right <= last && A[left] < A[right])
		{
			child = right;		// 왼쪽과 오른쪽 중 큰놈이 후레자식이 될 자격을 얻음
		/* last에 대한 조건을 준 이유 : 완전 이진트리에서 마지막 노드가
			left가 될 수 있기 때문에 right는 존재하지 않을 수도 있다 */
		}
		else child = left;
		if (root_value < A[child])
		{
			A[parent] = A[child];	// parent 자리에 child 자리의 원소를 넣어줌
			parent = child;		// child를 부모로 바꿔줌
			left = parent * 2 + 1;	// 그에 맞게 자식들도 바꿔줌
			right = left + 1;
		}
		else break;
	}
	A[parent] = root_value;		// 결국 while문이 다 돌고 남아있는 빈 자리에 root_value를 넣어줌
}

int main(void)
{
	int A[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	int i, j, n = SIZE_OF_HEAP;
	printf("배열 A = [");
	for (i = 0; i < n; i++)		// 정렬 전 배열 출력
		printf("%d ", A[i]);
	printf("]\n");
	for (i = 1; i <= n / 2; i++)	// n/2으로 해도 값의 변화가 없다는 것을 확인
	{
		for (j = i; j >= 0; j--)
			make_heap(A, j, n - 1);		// 배열을 heap으로 변환해줌(이중 for문 이용)
	}
	printf("heap A = [");
	for (i = 0; i < n; i++)		// 결과 배열 출력
		printf("%d ", A[i]);
	printf("]\n");
	return 0;
}