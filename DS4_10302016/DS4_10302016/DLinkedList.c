//더미 노드 기반의 정렬 삽입도 되고, 정렬 삽입의 기준도 바꿀 수 있는 무지 좋은 연결 리스트
//전의 프로젝트는 배열기반 리스트, 지금은 연결기반 리스트
//추가된거 : 더미노드의 사용, tail의 사라짐(노드를 앞에서 부터 추가하기로 했으니깐 불필요) 등등

#include<stdio.h>
#include<stdlib.h>
#include"DlinkedList.h"

void ListInit(List * plist) {

	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;//더미노드
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List *plist, LData data) {

	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
	
}

void SInsert(List *plist, LData data) {

	Node * newNode = (Node*)malloc(sizeof(Node));
	Node *pred = plist->head;
	newNode->data = data;

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0){//comp는 리스트의 정렬기준
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}

void LInsert(List *plist, LData data) {
	
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);

}

int LFirst(List *plist, LData *pdata) {
	
	if (plist->head->next == NULL)
		return FALSE;//덤노드가 가리키는게 없을때

	else {
		plist->before = plist->head;//더미가 before
		plist->cur = plist->head->next;

		*pdata = plist->cur->data;
		return TRUE;
	}

}

int LNext(List *plist, LData *pdata) {
	
	if (plist->cur->next == NULL)
		return FALSE;
	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;

}

LData LRemove(List *plist) {
	
	Node *rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;

}

int LCount(List *plist) {

	return plist->numOfData;
}

void SetSortRule(List *plist, int(*comp)(LData d1, LData d2)){

	plist->comp = comp;
}