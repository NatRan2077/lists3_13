#include "mouse.h"
#include <stdio.h>


//‘ункци€ дл€ инициализации структуры. јгрументы: инициализируема€ структура,
//значени€ полей: название фирмы, количество доп кнопок, цена
Mouse Init(Mouse* m, char* firm, int add_button, int coast)
{
	strncpy(m->firm, firm, MAX_LEN);
	m->add_button = add_button;
	m->coast = coast;

	return *m;
}


//‘ункци€, вывод€щу€ сведени€ об экземпл€ре структуры
void Print(Mouse m)
{
	printf("Mouse:%s, additional button: %d, coast: %d\n", m.firm, m.add_button, m.coast);
}

//‘ункци€, провер€ющу€ на равенство два экземпл€ра структуры(аналог операции Ђ == ї)
//1 - экзепл€ры равны, иначе - 0
int Equals(Mouse* m, Mouse* m1)
{
	if (m->add_button == m1->add_button && m->coast == m1->coast && strcmp(m->firm, m1->firm) == 0)
		return 1;
	else
		return 0;
}

//‘ункци€, сравнивающу€ два экземпл€ра структуры (аналог операции Ђ<ї)
//1 - первый экзепл€р < второй экземпл€р
//2 - первый экзепл€р >= второй экземпл€р
//—равнение идет по цене
int Less(Mouse* m, Mouse* m1)
{
	if (m->coast < m1->coast)
		return 1;
	else
		return 0;
}