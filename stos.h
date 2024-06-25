#pragma once
#include "str.h"

struct stos {
	str* nazwa;
	stos* next;
};

struct stosK {
	int index;
	stosK* next;
};

void addNewStos(stos*& head, str* nazwa);

str* Zestosu(stos*& head);

