#pragma once
typedef struct { //��� ���Ҹ� �����ϱ� ���� ����ü term ����
	int row; //��
	int col; //��
	int value; //��� ���� �ִ� ��

} term; //��ü �̸�

void smTranspose(term a[], term b[]); //����Լ� ����
