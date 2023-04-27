#include <stdio.h>
#include "mouse.h"
#include "my_list.h"
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    //  -------------------------Пункт 10-------------------------------

    //Cоздаем список объектов
    List* head = NULL;

    //Добавляем в список три элемента
    Mouse* m1 = malloc(sizeof(Mouse)), * m2 = malloc(sizeof(Mouse)), * m3 = malloc(sizeof(Mouse)), * m4 = malloc(sizeof(Mouse));

    *m1 = Init(m1, "Blody", 4, 3500);
    *m2 = Init(m2, "Razer", 2, 7000);
    *m3 = Init(m3, "Logitech", 3, 10000);

    head = push(m1, head);
    head = push(m2, head);
    head = push(m3, head);
    PrintList(head);

    //Удаляем из начала списка один элемент

    head = pop(head);

    //Печатаем полученный список;

    puts("Список для пункта 10:\n");
    PrintList(head);

    //Удаляем весь список

    head = deleteList(head);

    //  -------------------------Пункт 13-------------------------------

    //Создание нового списка объектов

    head = NULL;

    //Добавление в упорядоченный список четырех элементов;

    *m1 = Init(m1, "Blody", 4, 3500);
    *m2 = Init(m2, "Razer", 2, 7000);
    *m3 = Init(m3, "Logitech", 3, 10000);
    *m4 = Init(m4, "Dexp", 6, 2300);

    head = Insert_Sort(m1, head);
    head = Insert_Sort(m2, head);
    head = Insert_Sort(m3, head);
    head = Insert_Sort(m4, head);

    //Удаляет из списка один заданный элемент;

    Delete_Item(head, 3);

    //Печать полученного списка;

    puts("\nСписок для пункта 13:\n");
    PrintList(head);

    //Удаление всего списка.

    deleteList(head);

    //Удаляем экземпляры структуры

    free(m1);
    free(m2);
    free(m3);
    free(m4);

    return 0;
}