#pragma once
#include <iostream>
#include "Miasto.h"
#include "str.h"
#include "Dijkstra.h"

struct ListaM
{
	Miasto* m;
	ListaM* next;
};

ListaM* AddNew(ListaM* head, Dijkstra* tablica_D, str* n, int x, int y);

void deleteAll(ListaM* head);