// 2013112149 박지용
// 실습 1번. 완전이진트리의 삽입, 삭제, 탐색

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct _NODE
{
	element key;
	struct _NODE *left, *right;
}NODE;	//트리의 노드 구조체

//탐색 함수
NODE* search_tree(NODE* root, element key)
{
	NODE *p = root;
	while (p != NULL)
	{
		if (key == p->key)		//내가 찾는 키와 동일할 때 -> 노드 반환
			return p;
		if(key < p->key)		//내가 찾는 key가 더 작을 때 -> 왼쪽 서브트리
			p = p->left;
		else		//내가 찾는 key가 더 클 때 -> 오른쪽 서브트리
			p = p->right;
	}
	return p; //반복이 끝나면 노드 반환
}

//새로운 노드 삽입 함수 - 삽입 성공 시 1, 삽입 실패 시 0 반환
int insert_node(NODE **root, element key)
{
	NODE *p, *temp, *new_node;

	temp = *root;		//temp가 첫 노드를 가리키게 됨
	p = NULL;

	while (temp != NULL)
	{
		if (key == temp->key)	//이미 해당 key가 트리에 존재할 때
			return 0;
		p = temp;
		if (key < temp->key)
			temp = temp->left;
		else temp = temp->right;
	}
	new_node = (NODE*)malloc(sizeof(NODE));
	if (new_node == NULL)
		return 0;		//메모리 할당 오류
	new_node->key = key;		//새로운 노드에 데이터 복사
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

//노드 삭제함수 - 삭제 성공 시 삭제된 key값, 삭제 실패 시 0반환
int delete_node(NODE **root, element key)
{
	NODE *p, *child, *succ, *succ_p, *t;	//p는 선행노드(부모), child는 자식노드, t는 삭제할 노드
	int return_value = 0;
	p = NULL;
	t = *root;
	while (t != NULL && key != t->key)		//둘이 같지 않으면
	{
		p = t;
		t = (key < t->key) ? t->left : t->right;	//어느쪽 서브트리로 가야되는지 결정
	}
	if (t == NULL)
		return 0;
	if ((t->left == NULL) && (t->right == NULL)) //삭제할 노드가 단말노드일 때
	{
		if (p != NULL)
		{
			if (p->left == t)
				p->left = NULL;
			else p->right = NULL;		//부모 노드에서 나오는 간선을 삭제해준다
		}
		else
			*root = NULL;
	}
	else if ((t->left == NULL || t->right == NULL)) //자식이 하나만 있을 때
	{
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL)
		{
			if (p->left == t)
				p->left = child;
			else p->right = child;		//노드를 삭제한 뒤에 자식을 삭제된 부모 노드의 위치로 옮긴다
		}
		else
			*root = child;
	}
	else		//두 자식 모두 있는 경우
	{
		//오른쪽 서브 트리에서 후속자 succ를 찾고 succ_p의 선행노드(부모)는 t가 됨
		succ_p = t;
		succ = t->right;
		while (succ->left != NULL)
		{
			succ_p = succ;
			succ = succ->left;		//가장 왼쪽 노드로 이동, 후속자의 부모도 따라 이동
		}
		if (succ_p->left == succ)	//succ이 부모의 왼쪽 자식일 때
			succ_p->left = succ->right;
		else		//t의 오른쪽 자식 노드가 왼쪽 자식을 갖고있지 않을 경우
			succ_p->right = succ->right;		//succ을 삭제해주고
		t->key = succ->key;		//t에 succ의 데이터를 옮겨준다
		t = succ;		//succ이었던 노드를 free해주기 위함
	}
	return_value = t->key;
	free(t);
	return return_value;
}

//중위순회로 출력하는 함수
void display(NODE *p)
{
	if (p != NULL)
	{
		display(p->left);
		printf("%d\t", p->key);	 // 키 값을 출력
		display(p->right);
	}
}

//메뉴 목록
void menu()
{
	printf("\t 수행하려는 옵션을 골라주세요\n");
	printf("p : 전체 데이터 출력\t\t");
	printf("q : 종료\n");
	printf("i : 입력\t");
	printf("d : 삭제\t");
	printf("s : 검색\n: ");
}

int main(void)
{
	char select = 0;
	int flag = 0;
	element key;
	NODE *dest_node, *root = NULL;	//탐색 대상이 될 노드
	insert_node(&root, 20); insert_node(&root, 6); insert_node(&root, 2);
	insert_node(&root, 4); insert_node(&root, 16); insert_node(&root, 10);
	insert_node(&root, 8); insert_node(&root, 12); insert_node(&root, 14); insert_node(&root, 9);	// 노드 삽입

	while(1)
	{
		menu();
		scanf(" %c", &select);

		if (select == 'i')
		{
			printf("삽입하실 key값을 입력하세요 : ");
			scanf("%d", &key);
			flag = insert_node(&root, key);		// 새로운 노드의 key를 입력받아 삽입
			if (flag != 0)
				printf("삽입 성공!\n");
			else
				printf("삽입 실패...\n이미 존재하는 key값 입니다.\n");
		}
		else if (select == 'd')
		{
			if (root == NULL)
				printf("데이터가 없습니다\n");
			else
			{
				printf("삭제하실 key값을 입력하세요 : ");
				scanf("%d", &key);
				flag = delete_node(&root, key);	//삭제 진행
				if (flag != 0)
					printf("삭제 성공!\n");
				else
					printf("삭제 실패...\n존재하지 않는 key값 입니다.\n");
			}
		}
		else if (select == 's')
		{
			if (root == NULL)
				printf("탐색 실패...\n데이터가 없습니다\n");
			else
			{
				printf("찾으려는 key값을 입력하세요 : ");
				scanf("%d", &key);
				dest_node = search_tree(root, key);	//탐색 진행
				if (dest_node != NULL)
				{
					printf("탐색 성공!\nkey가 존재합니다.\n");
					if (dest_node->left != NULL)
						printf("왼쪽 자식 : %d\n", dest_node->left->key);	//탐색이 성공할 경우 왼쪽과 오른쪽 자식 출력
					else
						printf("왼쪽 자식이 없습니다.\n");
					if (dest_node->right != NULL)
						printf("오른쪽 자식 : %d\n", dest_node->right->key);
					else
						printf("오른쪽 자식이 없습니다.\n");
				}
				else
					printf("탐색 실패...\n존재하지 않는 key값 입니다.\n");
			}
		}
		else if (select == 'p')
		{
			if (root == NULL)
				printf("데이터가 없습니다\n");
			else
			{
				display(root);	// 출력 실행
				printf("\n");
			}
		}
		else break;	// 입력으로 다른 것이 들어올 경우 반복 종료
		printf("\n");
	}
	return 0;
}