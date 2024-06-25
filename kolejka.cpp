#include "kolejka.h"


void addNewKolejka(kolejka*& head, int x, int y)
{
	if (head == nullptr)
	{
		head = new kolejka;
		head->p.x = x;
		head->p.y = y;
		head->next = nullptr;
		head->tail = head;
	}
	else
	{
		kolejka* nowy = new kolejka;
		nowy->p.x = x;
		nowy->p.y = y;
		nowy->next = nullptr;
		head->tail->next = nowy;
		head->tail = nowy;
	}
}

Point Zkolejki(kolejka*& head)
{
	Point result;

	result.x = head->p.x;
	result.y = head->p.y;

	kolejka* tmp = head;
	if(head->next != nullptr)
		head->next->tail = head->tail;
	head = head->next;
	delete tmp;

	return result;
}
