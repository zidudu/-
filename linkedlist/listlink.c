#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include "listlink.h"


//���� ���� ����Ʈ ����
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}
//���� ����Ʈ ��ü �޸� ����
void freeLinkedList_h(linkedList_h* L) {
	//head ����ü p ����
	listNode* p;
	//L�� ����Ű�� head�� NULL�� �ƴҶ� �ݺ�
	while (L->head != NULL)
	{
		//p�� L�� head�� ����
		p = L->head;
		L->head = L->head->link; //�޸𸮸� ������ �Ŀ��� ���� ����� ��ġ�� �˰� �־� ������ ������ �� �ֽ��ϴ�.
		free(p);
		p = NULL;
	}
}
//���� ����Ʈ ������� ���
void printList(linkedList_h* L) {
	listNode* p;
	printf("L= (");
	p = L->head;
	while (p != NULL){ //head�� ����Ű�� ��尡 ������
		printf("%s", p->data); //���
		p = p->link;
		if (p != NULL)printf(", "); //p�� ����Ű�� ��ũ�ʵ尡 null�� �ƴҶ��� ,�� �ٿ��� ��� �������ʵ尪 ����
	}
	printf(") \n");
}
// ù��° ���� �����ϴ¿���
void insertFirstNode(linkedList_h* L, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode)); //���� �� ���



	//newNode=(listNode*)malloc(sizeof(listNode));
	//������ ����
	strcpy(newNode->data, x);
	//new �ּ�
	newNode->link = L->head;
	L->head = newNode;
}
//��� pre �ڿ� ���Կ���
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode)); //���� �� ���
	strcpy(newNode->data, x); //����
	if (L->head == NULL) {newNode->link = NULL;L->head = newNode;} //��� ���� ���:newnode�� ������ ��尡 �Ǽ� newnode��ũ�ʵ忣 null
	//L->head�� newNode �ּ� ����Ŵ
	else if (pre == NULL) {newNode->link = L->head;L->head = newNode;}//���� ��� �ڿ� ��尡 ���� ���: newnode��ũ�ʵ�� L->head�� ����Ű�� 
	else {newNode->link = pre->link;pre->link = newNode;}
}
//������ ���� ����
void insertLastNode(linkedList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {L->head = newNode; return;}
	//���� ����Ʈ�� ������ �ƴ� ���
	temp = L->head;
	while (temp->link != NULL)temp = temp->link; //���� ����Ʈ�� ������ ��带 ã��
	temp->link = newNode; //�� ��带 ������ ����� ���� ���� ����
	
}


listNode* FindNode(linkedList_h* L, char* x) {
	listNode* temp = L->head;
	// ����Ʈ�� ��ȸ�ϸ鼭 ���ϴ� �����͸� �����ϴ� ��� �˻�
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) {  // ���ڿ� �񱳸� ���� strcmp ���
			return temp; // �����Ͱ� ��ġ�ϴ� ����� ������ ��ȯ
		}
		temp = temp->link; // ���� ���� �̵�
	}
	return NULL; // ��ġ�ϴ� ��带 ã�� ������ ��� NULL ��ȯ
}