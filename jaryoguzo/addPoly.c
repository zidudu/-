#include "addPoly.h"
polynomial addPoly(polynomial A, polynomial B) {
	polynomial C;
	int A_index = 0, B_index = 0, C_index = 0; //�迭 ��� ����
	int A_degree = A.degree, B_degree = B.degree; //�ִ����� ����
	C.degree = MAX(A.degree, B.degree); //c ������ a�� b�� ū �ִ� ���� ��ȯ�� ����

	while (A_index<=A.degree&&B_index<=B.degree) //���Ѽ�
	{
		// A�� �ִ������� B�� �ִ��������� Ŭ��
		if (A_degree > B_degree) {
			C.coef[C_index++] = A.coef[A_index++]; //�ε��� �־����� ���� ������
			A_degree--; //a�� ���� ����

		}
		// A�� �ִ������� B�� �ִ������� ������
		else if (A_degree == B_degree) {
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++]; //�� ���� ��� ���ؼ� C�� ���� �� ����� ������
			A_degree--;
			B_degree--;
		}
		// B�� �ִ������� A�� �ִ��������� Ŭ��
		else {
			C.coef[C_index++] = B.coef[B_index++]; //B�� ���� �� ����� ���׽� C�� ���� ���� ����� ������
			B_degree--;
		}
	}
	return C; //���� ����� C ��ȯ

}
void printPoly(polynomial P) { // ��� �Լ� ����
	int i, degree;
	degree = P.degree; //�ִ� ���� ���� ����
	

	for (i = 0; i <= P.degree; i++) {
		
			printf("%3.0fx^%d", P.coef[i], degree--); //���� ������ ���� ������ ������� ǥ���ǰ� ��
			if (i < P.degree)printf(" +"); //i�� p�� �������� ���ٸ� �߰��߰� + �߰���, �ִ��� ������ ������ +1�̴� ������ŭ �ݺ��� �������� +�Ⱥ���
	}
	printf("\n"); //�ٹٲ�

}