#include "my_list.h"
#include <stdio.h>
#include <stdlib.h>

//Функция, для добавления элемента в начало списка
List* push(Mouse* m, List* head)
{
	List* newItem = malloc(sizeof(List));
	newItem->m = m;
	newItem->next = head;
	return newItem;
}

//Функция, для удаления элемента в начале списка
List* pop(List* head)
{
	List* item = head;
	if (item->next == NULL)puts("Список пуст!");
	else {
		head = head->next;
		free(item);
	}
	return head;
}

//Функция, для удаления списка
List* deleteList(List* head)
{
	List* p;
	while (head != NULL) {
		p = head;
		head = head->next;
		free(p);
	}
	return NULL;
}

//Функция, для печати всех элементов списка
void PrintList(List* head)
{
	int i = 1;
	for (List* item = head; item != NULL; item = head) {
		head = head->next;
		printf("%d: ", i);
		Print(*item->m);
		i++;
	}
}

//Функцию для добавления элемента в упорядоченный список.
List* Insert_Sort(Mouse* m, List* head)
{
	List* q = malloc(sizeof(List)), * p = head;
	q->next = NULL;
	q->m = m;
	if (head == NULL) return q;
	if (Less(&m, &head->m)) // Включение элемента в начало списка
	{
		q->next = head;
		return q;
	}
	while (p->next != NULL) {
		if (Less(&m, &p->next->m)) // Включение элемента в середину списка
		{
			q->next = p->next;
			p->next = q;
			break;
		}
		else
			p = p->next;
	}
	p->next = q; // Включение элемента в конец списка
	return head;
}

//Функцию для удаления заданного элемента из списка.
List* Delete_Item(List* head, int id)
{
	List* p = head, * t = malloc(sizeof(List));
	int i = 1;
	if (head == NULL) { puts("Список пуст!"); return NULL; }
	if (id == i) // Удаление элемента из начала списка
		return pop(head);

	while (p->next != NULL) {
		i++;
		if (id == i) // Удаление элемента из середины списка
		{
			t = p->next;
			p->next = p->next->next;
			free(t);
			return head;
		}
		p = p->next;
	}
	puts("Такого номера в списке нет!"); // Такого номера в списке нет
	return head;
}