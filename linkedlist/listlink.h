#pragma once

//�ܼ� ���� ����Ʈ ��� ���� ����ü�� ����
typedef struct ListNode {
    char data[4]; //������ 
    struct ListNode* link; //��ũ
} listNode;
//����Ʈ ���� ��Ÿ���� head ���
typedef struct {
    listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(void); //���� ����Ʈ ����
void freeLinkedList_h(linkedList_h* L); //���� ����Ʈ ����
void printList(linkedList_h* L); // ���� ����Ʈ ���
void insertFirstNode(linkedList_h* L, char* x); //ù��° ��忡 ����
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x); //�߰� ����
void insertLastNode(linkedList_h* L, char* x); //������ ����

listNode* FindNode(linkedList_h* L, char* x);