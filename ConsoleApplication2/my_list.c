#include "my_list.h"
#include <stdio.h>
#include <stdlib.h>

//�������, ��� ���������� �������� � ������ ������
List* push(Mouse* m, List* head)
{
	List* newItem = malloc(sizeof(List));
	newItem->m = m;
	newItem->next = head;
	return newItem;
}

//�������, ��� �������� �������� � ������ ������
List* pop(List* head)
{
	List* item = head;
	if (item->next == NULL)puts("������ ����!");
	else {
		head = head->next;
		free(item);
	}
	return head;
}

//�������, ��� �������� ������
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

//�������, ��� ������ ���� ��������� ������
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

//������� ��� ���������� �������� � ������������� ������.
List* Insert_Sort(Mouse* m, List* head)
{
	List* q = malloc(sizeof(List)), * p = head;
	q->next = NULL;
	q->m = m;
	if (head == NULL) return q;
	if (Less(&m, &head->m)) // ��������� �������� � ������ ������
	{
		q->next = head;
		return q;
	}
	while (p->next != NULL) {
		if (Less(&m, &p->next->m)) // ��������� �������� � �������� ������
		{
			q->next = p->next;
			p->next = q;
			break;
		}
		else
			p = p->next;
	}
	p->next = q; // ��������� �������� � ����� ������
	return head;
}

//������� ��� �������� ��������� �������� �� ������.
List* Delete_Item(List* head, int id)
{
	List* p = head, * t = malloc(sizeof(List));
	int i = 1;
	if (head == NULL) { puts("������ ����!"); return NULL; }
	if (id == i) // �������� �������� �� ������ ������
		return pop(head);

	while (p->next != NULL) {
		i++;
		if (id == i) // �������� �������� �� �������� ������
		{
			t = p->next;
			p->next = p->next->next;
			free(t);
			return head;
		}
		p = p->next;
	}
	puts("������ ������ � ������ ���!"); // ������ ������ � ������ ���
	return head;
}