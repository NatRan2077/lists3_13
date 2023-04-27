#pragma once
#ifndef MY_LIST_H_
#define MY_LIST_H_
#include "mouse.h"

typedef struct List {
    Mouse* m;
    struct List* next;
} List;

//�������, ��� ���������� �������� � ������ ������
List* push(Mouse*, List*);

//�������, ��� �������� �������� � ������ ������
List* pop(List*);

//�������, ��� �������� ������
List* deleteList(List*);

//�������, ��� ������ ���� ��������� ������
void PrintList(List*);

//������� ��� ���������� �������� � ������������� ������.
List* Insert_Sort(Mouse*, List*);

//������� ��� �������� ��������� �������� �� ������.
List* Delete_Item(List*, int);

#endif /* MY_LIST_H_ */