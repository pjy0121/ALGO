//2013112149 ������
//�ǽ����� 1��. BruteForceChange �˰����� Recursive���·� �����غ���

#include <stdio.h>

int smallest_sum = 1000;
int howMuch = 0, sum = 0;
int k[6];

int BruteForceChange(int M, int c[], int d)
{
	int i;
	for (i = 0; i < d; i++)
	{
		k[i] = M / c[i];	//�� ó�� k�� �迭�� ���� �ο�����
		howMuch = c[0] * k[0] + c[1] * k[1] + c[2] * k[2] + c[3]*k[3] + c[4]*k[4] + c[5]*k[5]; //howMuch�� �� ������ �׼��� ���� Ƚ���� ���� ���� ��(�� �ݾ�)
		sum = k[0] + k[1] + k[2] + k[3] + k[4] + k[5];	//+= �� �̿��ϸ� howMuch�� sum�� ���� �ٽ� �ʱ�ȭ���Ѿ� �ϴ� ������ �߻��ϹǷ� ���� �Է�����

		if (howMuch == 40)	//ó�� �Է��� M�� ���� ��
		{
			printf("k = (%d %d %d %d %d %d)\n, sum = %d\n", k[0], k[1], k[2], k[3], k[4], k[5], sum);
			if (sum < smallest_sum)
				smallest_sum = sum;
		}
		if (M / c[i] != 0)
		{
			BruteForceChange(M - c[i], c, d);
		}

	}
	return smallest_sum;
}

int main(void)
{��
	int M = 40, d = 6;
	int c[] = { 25, 20, 15, 10, 5, 1 };
	
	printf("M = 40�� ���� ���� �ּ� ��� ���� : %d\n", BruteForceChange(M, c, d));
	return 0;
}