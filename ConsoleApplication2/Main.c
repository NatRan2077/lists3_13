#include <stdio.h>
#include "mouse.h"
#include "my_list.h"
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    //  -------------------------����� 10-------------------------------

    //C������ ������ ��������
    List* head = NULL;

    //��������� � ������ ��� ��������
    Mouse* m1 = malloc(sizeof(Mouse)), * m2 = malloc(sizeof(Mouse)), * m3 = malloc(sizeof(Mouse)), * m4 = malloc(sizeof(Mouse));

    *m1 = Init(m1, "Blody", 4, 3500);
    *m2 = Init(m2, "Razer", 2, 7000);
    *m3 = Init(m3, "Logitech", 3, 10000);

    head = push(m1, head);
    head = push(m2, head);
    head = push(m3, head);
    PrintList(head);

    //������� �� ������ ������ ���� �������

    head = pop(head);

    //�������� ���������� ������;

    puts("������ ��� ������ 10:\n");
    PrintList(head);

    //������� ���� ������

    head = deleteList(head);

    //  -------------------------����� 13-------------------------------

    //�������� ������ ������ ��������

    head = NULL;

    //���������� � ������������� ������ ������� ���������;

    *m1 = Init(m1, "Blody", 4, 3500);
    *m2 = Init(m2, "Razer", 2, 7000);
    *m3 = Init(m3, "Logitech", 3, 10000);
    *m4 = Init(m4, "Dexp", 6, 2300);

    head = Insert_Sort(m1, head);
    head = Insert_Sort(m2, head);
    head = Insert_Sort(m3, head);
    head = Insert_Sort(m4, head);

    //������� �� ������ ���� �������� �������;

    Delete_Item(head, 3);

    //������ ����������� ������;

    puts("\n������ ��� ������ 13:\n");
    PrintList(head);

    //�������� ����� ������.

    deleteList(head);

    //������� ���������� ���������

    free(m1);
    free(m2);
    free(m3);
    free(m4);

    return 0;
}