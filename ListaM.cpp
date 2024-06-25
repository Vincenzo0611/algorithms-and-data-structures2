#include "ListaM.h"

ListaM* AddNew(ListaM* head, Dijkstra* tablica_D, str* n, int x, int y)
{
	if (head == nullptr)
	{
		head = new ListaM;
		Miasto* miasto = addNew(n, x, y);
		head->m = miasto;
		tablica_D[miasto->id].wierzcholek = miasto;
		head->next = nullptr;
		return head;
	}
	else
	{
		ListaM* tmp = head;
		while (tmp->next != nullptr)
			tmp = tmp->next;
		ListaM* nowy = new ListaM;
		Miasto* miasto = addNew(n, x, y);
		nowy->m = miasto;
		tablica_D[miasto->id].wierzcholek = miasto;
		nowy->next = nullptr;
		tmp->next = nowy;
		return head;
	}
}

void deleteAll(ListaM* head)
{
	ListaM* current = head;
	ListaM* next;

	while (current != nullptr) {
		next = current->next;
		deleteList(current->m->s);
		del(current->m->nazwa);
		delete current->m;
		delete current;
		current = next;
	}
}