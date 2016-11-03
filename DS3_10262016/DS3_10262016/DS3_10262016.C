#include<stdio.h>
#include<stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node *next;

}Node;

int main(void) {
	Node *head = NULL;
	Node *tail = NULL;
	Node *cur = NULL;

	Node *newNode = NULL;
	int readData;

	while (1) {

		printf("자연수 입력 : ");
		scanf_s("%d", &readData);
		
		if (readData < 0) break;
		//노드의 추가과정
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else tail->next = newNode;//첫번째 노드 만들 때만 윗 조건 성립, 그다음부턴 else로만 들어옴, tail->next의 tail은 그 전의 tail

		tail = newNode;
	}

	printf("\n");
	
	printf("입력받은 데이터 모두 출력\n");
	
	if (head == NULL) {
		printf("저장된 자연수가 존재하지 않습니다.\n");
	}
	else {
		cur = head;
		printf("%d", cur->data);
		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d", cur->data);
		}

	}

	if (head == NULL)
		return 0;

	else {
		Node *delNode = head;
		Node *delNextNode = head->next;

		printf("%d을 삭제합니다. \n", delNode->data);
		free(delNode);

		while (delNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}
	return 0;
	

}