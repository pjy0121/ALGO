// 2013112149 ������

//���� 2�� - 4
#include <stdio.h>
#include <stdlib.h>

int smallest_sum = 1000; /* ��������� �ּ��� ���� ����
		- BruteForceChange�� return���� ��ü ���ΰ��� ���� �����ͷ� �ֱ� ���� ���������� ����
		- ������ ���� ���� sum���� ã���Ŵ� ���ʿ� ���� ū ���� �ʱ�ȭ�Ͽ���  
	*/

//����Ž�� �˰���
int* BruteForceChange(int M, int c[], int d)
{
	int *k = (int*)malloc(sizeof(int));	//�迭ȭ�ϱ� ���� �����Ҵ�
	int k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0, sum = 0, howMuch = 0;	//sum�� �� ���� ��� ����, howMuch�� ������ ���μ�*���ΰ��� �� ���ؼ� ���� �ݾ�
	for (k1 = 0; k1 <= M / c[0]; k1++)		//5�� for���� �̿��� �� ������ ���� Ƚ��(k1, k2, k3, k4, k5)�� �÷����鼭 ��� ����� ���� ���
	{
		for (k2 = 0; k2 <= M / c[1]; k2++)
		{
			for (k3 = 0; k3 <= M / c[2]; k3++)
			{
				for (k4 = 0; k4 <= M / c[3]; k4++)
				{
					for (k5 = 0; k5 <= M / c[4]; k5++)
					{
						howMuch = k1*c[0] + k2*c[1] + k3*c[2] + k4*c[3] + k5*c[4];
						if (howMuch == M)		// �ݾ��� �־��� �ݾװ� ������
						{
							sum = k1 + k2 + k3 + k4 + k5;
							printf("(%d,%d,%d,%d,%d), sum = %d\n", k1, k2, k3, k4, k5, sum);	// ������ k��� sum���� ���� ���

							if (sum < smallest_sum)
							{
								smallest_sum = sum;
								k[0] = k1; k[1] = k2; k[2] = k3; k[3] = k4; k[4] = k5;
								//sum�� �ּҰ� �� ���� ������ ���� Ƚ��(k1, ..., k5)�� �迭�� ���� 
							}
						}
					}
				}
			}
		}
	}
	return k;
}

int main(void)
{
	int i, d = 5, M = 28;
	int *k;
	int c[5] = { 25,20,10,5,1 };
	k = BruteForceChange(M, c, d);
	printf("\n---- ��� ������ �ּ��� ��� ----\nk = (");
	for (i = 0; i < d; i++)
		printf("%d, ", k[i]);
	printf(")\n��� ���� ���� = %d\n\n", smallest_sum);
	return 0;
}