// 2013112149 ������

//���� 2�� - 2
#include <stdio.h>
#include <stdlib.h>

//Ž�� �˰���
int* GreedyBetterChange(int M, int c[], int d)		//M : �ٲ� �׼�, c[] : �� �� �ִ� �������� ����, d : ������ �� ����
{
	int *k = (int*)malloc(sizeof(int));
	int i, ki;	//ki�� �迭 k�� �� ����
	for (i = 0; i < d; i++)
	{
		ki = M / c[i];
		M = M - c[i] * ki;

		k[i] = ki;
	}
	return k;	//�� ���� �� ���� ���� ���� �迭�� return
}

int main(void)
{
	int i;
	int M = 40, c[] = { 25, 20, 10, 5, 1 }, d = 5;	//input datas
	int *k = NULL;
	k = GreedyBetterChange(M, c, d);
	printf("coins = ( 25, 20, 10, 5,  1, )\n");
	printf("count = (");			//k �迭�� ��� �� count(����)��� �Ͽ���
	for(i=0; i<d; i++)
		printf("%2d, ", k[i]);
	printf(")\n");
}