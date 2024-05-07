#pragma once
#define MAX(a,b)((a>b)?a:b)
#define MAX_DEGREE 50

	typedef struct { //��� ���Ҹ� �����ϱ� ���� ����ü term ����
	int degree; //���׽� ����
	float coef[MAX_DEGREE]; //�� ��� ���� �迭

} polynomial; //Ŭ���� �̸�

	polynomial addPoly(polynomial A,polynomial B); //�� ���׽� ���� ����Լ� ����
	void printPoly(polynomial P); // ��� �Լ� ����
	void deleteElement(polynomial *L);
