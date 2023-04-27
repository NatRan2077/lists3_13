#pragma once
#ifndef MY_LIST_H_
#define MY_LIST_H_
#include "mouse.h"

typedef struct List {
    Mouse* m;
    struct List* next;
} List;

//Функция, для добавления элемента в начало списка
List* push(Mouse*, List*);

//Функция, для удаления элемента в начале списка
List* pop(List*);

//Функция, для удаления списка
List* deleteList(List*);

//Функция, для печати всех элементов списка
void PrintList(List*);

//Функцию для добавления элемента в упорядоченный список.
List* Insert_Sort(Mouse*, List*);

//Функцию для удаления заданного элемента из списка.
List* Delete_Item(List*, int);

#endif /* MY_LIST_H_ */