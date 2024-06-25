#include "stos.h"

void addNewStos(stos*& head, str* nazwa)
{
	if (head == nullptr)
	{
		stos* nowy = new stos;
		nowy->nazwa = nazwa;
		nowy->next = nullptr;
		head = nowy;
	}
	else
	{
		stos* nowy = new stos;
		nowy->nazwa = nazwa;
		nowy->next = head;
		head = nowy;
	}
}

str* Zestosu(stos*& head)
{
	if (head == nullptr)
		return nullptr;

	str* result;
	result = head->nazwa;

	stos* tmp = head;
	head = head->next;
	delete tmp;

	return result;
}
