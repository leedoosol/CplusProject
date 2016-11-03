#include<stdio.h>
#include"DlinkedList.h"

int WhoIsPercede(int d1, int d2) {//이 함수가 main문에 있어야 하는 이유는 p149

	if (d1 < d2)
		return 0;
	else
		return 1;
}

int main(void) {

	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPercede);//해당 리스트와 정렬의 기준 등록

	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d", data);
		while (LNext(&list, &data))
			printf("%d", data);

	}
	printf("\n\n");


	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data)) {
			if (data == 22)
				LRemove(&list);
		}

	}

	printf("현재 데이터의 수: %d\n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d", data);

		while (LNext(&list, &data))
			printf("%d", data);
	}
	printf("\n\n");
	return 0;
}

