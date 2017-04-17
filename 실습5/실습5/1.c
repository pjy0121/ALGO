// 2013112149 ������
// �ǽ� 1��. ��������Ʈ���� ����, ����, Ž��

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct _NODE
{
	element key;
	struct _NODE *left, *right;
}NODE;	//Ʈ���� ��� ����ü

//Ž�� �Լ�
NODE* search_tree(NODE* root, element key)
{
	NODE *p = root;
	while (p != NULL)
	{
		if (key == p->key)		//���� ã�� Ű�� ������ �� -> ��� ��ȯ
			return p;
		if(key < p->key)		//���� ã�� key�� �� ���� �� -> ���� ����Ʈ��
			p = p->left;
		else		//���� ã�� key�� �� Ŭ �� -> ������ ����Ʈ��
			p = p->right;
	}
	return p; //�ݺ��� ������ ��� ��ȯ
}

//���ο� ��� ���� �Լ� - ���� ���� �� 1, ���� ���� �� 0 ��ȯ
int insert_node(NODE **root, element key)
{
	NODE *p, *temp, *new_node;

	temp = *root;		//temp�� ù ��带 ����Ű�� ��
	p = NULL;

	while (temp != NULL)
	{
		if (key == temp->key)	//�̹� �ش� key�� Ʈ���� ������ ��
			return 0;
		p = temp;
		if (key < temp->key)
			temp = temp->left;
		else temp = temp->right;
	}
	new_node = (NODE*)malloc(sizeof(NODE));
	if (new_node == NULL)
		return 0;		//�޸� �Ҵ� ����
	new_node->key = key;		//���ο� ��忡 ������ ����
	new_node->left = new_node->right = NULL;

	if (p != NULL)
	{
		if (key < p->key)
			p->left = new_node;
		else p->right = new_node;
	}
	else
		*root = new_node;
	return 1;
}

//��� �����Լ� - ���� ���� �� ������ key��, ���� ���� �� 0��ȯ
int delete_node(NODE **root, element key)
{
	NODE *p, *child, *succ, *succ_p, *t;	//p�� ������(�θ�), child�� �ڽĳ��, t�� ������ ���
	int return_value = 0;
	p = NULL;
	t = *root;
	while (t != NULL && key != t->key)		//���� ���� ������
	{
		p = t;
		t = (key < t->key) ? t->left : t->right;	//����� ����Ʈ���� ���ߵǴ��� ����
	}
	if (t == NULL)
		return 0;
	if ((t->left == NULL) && (t->right == NULL)) //������ ��尡 �ܸ������ ��
	{
		if (p != NULL)
		{
			if (p->left == t)
				p->left = NULL;
			else p->right = NULL;		//�θ� ��忡�� ������ ������ �������ش�
		}
		else
			*root = NULL;
	}
	else if ((t->left == NULL || t->right == NULL)) //�ڽ��� �ϳ��� ���� ��
	{
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL)
		{
			if (p->left == t)
				p->left = child;
			else p->right = child;		//��带 ������ �ڿ� �ڽ��� ������ �θ� ����� ��ġ�� �ű��
		}
		else
			*root = child;
	}
	else		//�� �ڽ� ��� �ִ� ���
	{
		//������ ���� Ʈ������ �ļ��� succ�� ã�� succ_p�� ������(�θ�)�� t�� ��
		succ_p = t;
		succ = t->right;
		while (succ->left != NULL)
		{
			succ_p = succ;
			succ = succ->left;		//���� ���� ���� �̵�, �ļ����� �θ� ���� �̵�
		}
		if (succ_p->left == succ)	//succ�� �θ��� ���� �ڽ��� ��
			succ_p->left = succ->right;
		else		//t�� ������ �ڽ� ��尡 ���� �ڽ��� �������� ���� ���
			succ_p->right = succ->right;		//succ�� �������ְ�
		t->key = succ->key;		//t�� succ�� �����͸� �Ű��ش�
		t = succ;		//succ�̾��� ��带 free���ֱ� ����
	}
	return_value = t->key;
	free(t);
	return return_value;
}

//������ȸ�� ����ϴ� �Լ�
void display(NODE *p)
{
	if (p != NULL)
	{
		display(p->left);
		printf("%d\t", p->key);	 // Ű ���� ���
		display(p->right);
	}
}

//�޴� ���
void menu()
{
	printf("\t �����Ϸ��� �ɼ��� ����ּ���\n");
	printf("p : ��ü ������ ���\t\t");
	printf("q : ����\n");
	printf("i : �Է�\t");
	printf("d : ����\t");
	printf("s : �˻�\n: ");
}

int main(void)
{
	char select = 0;
	int flag = 0;
	element key;
	NODE *dest_node, *root = NULL;	//Ž�� ����� �� ���
	insert_node(&root, 20); insert_node(&root, 6); insert_node(&root, 2);
	insert_node(&root, 4); insert_node(&root, 16); insert_node(&root, 10);
	insert_node(&root, 8); insert_node(&root, 12); insert_node(&root, 14); insert_node(&root, 9);	// ��� ����

	while(1)
	{
		menu();
		scanf(" %c", &select);

		if (select == 'i')
		{
			printf("�����Ͻ� key���� �Է��ϼ��� : ");
			scanf("%d", &key);
			flag = insert_node(&root, key);		// ���ο� ����� key�� �Է¹޾� ����
			if (flag != 0)
				printf("���� ����!\n");
			else
				printf("���� ����...\n�̹� �����ϴ� key�� �Դϴ�.\n");
		}
		else if (select == 'd')
		{
			if (root == NULL)
				printf("�����Ͱ� �����ϴ�\n");
			else
			{
				printf("�����Ͻ� key���� �Է��ϼ��� : ");
				scanf("%d", &key);
				flag = delete_node(&root, key);	//���� ����
				if (flag != 0)
					printf("���� ����!\n");
				else
					printf("���� ����...\n�������� �ʴ� key�� �Դϴ�.\n");
			}
		}
		else if (select == 's')
		{
			if (root == NULL)
				printf("Ž�� ����...\n�����Ͱ� �����ϴ�\n");
			else
			{
				printf("ã������ key���� �Է��ϼ��� : ");
				scanf("%d", &key);
				dest_node = search_tree(root, key);	//Ž�� ����
				if (dest_node != NULL)
				{
					printf("Ž�� ����!\nkey�� �����մϴ�.\n");
					if (dest_node->left != NULL)
						printf("���� �ڽ� : %d\n", dest_node->left->key);	//Ž���� ������ ��� ���ʰ� ������ �ڽ� ���
					else
						printf("���� �ڽ��� �����ϴ�.\n");
					if (dest_node->right != NULL)
						printf("������ �ڽ� : %d\n", dest_node->right->key);
					else
						printf("������ �ڽ��� �����ϴ�.\n");
				}
				else
					printf("Ž�� ����...\n�������� �ʴ� key�� �Դϴ�.\n");
			}
		}
		else if (select == 'p')
		{
			if (root == NULL)
				printf("�����Ͱ� �����ϴ�\n");
			else
			{
				display(root);	// ��� ����
				printf("\n");
			}
		}
		else break;	// �Է����� �ٸ� ���� ���� ��� �ݺ� ����
		printf("\n");
	}
	return 0;
}