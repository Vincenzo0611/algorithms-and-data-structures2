#pragma once
#include <iostream>
#include "Miasto.h"

struct Miasto;

struct Droga
{
	int koszt;
	Miasto* cel;
};

struct sasiedztwo
{
	Droga droga;
	sasiedztwo* next;
};


void addNewSorted(sasiedztwo*& head, Droga droga);

void deleteList(sasiedztwo* head);
