#include "mouse.h"
#include <stdio.h>


//������� ��� ������������� ���������. ���������: ���������������� ���������,
//�������� �����: �������� �����, ���������� ��� ������, ����
Mouse Init(Mouse* m, char* firm, int add_button, int coast)
{
	strncpy(m->firm, firm, MAX_LEN);
	m->add_button = add_button;
	m->coast = coast;

	return *m;
}


//�������, ��������� �������� �� ���������� ���������
void Print(Mouse m)
{
	printf("Mouse:%s, additional button: %d, coast: %d\n", m.firm, m.add_button, m.coast);
}

//�������, ����������� �� ��������� ��� ���������� ���������(������ �������� � == �)
//1 - ��������� �����, ����� - 0
int Equals(Mouse* m, Mouse* m1)
{
	if (m->add_button == m1->add_button && m->coast == m1->coast && strcmp(m->firm, m1->firm) == 0)
		return 1;
	else
		return 0;
}

//�������, ������������ ��� ���������� ��������� (������ �������� �<�)
//1 - ������ �������� < ������ ���������
//2 - ������ �������� >= ������ ���������
//��������� ���� �� ����
int Less(Mouse* m, Mouse* m1)
{
	if (m->coast < m1->coast)
		return 1;
	else
		return 0;
}