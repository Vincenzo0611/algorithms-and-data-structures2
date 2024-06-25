#pragma once
#include <iostream>
#include "str.h"
#include "sasiedztwo.h"

struct sasiedztwo;

struct Miasto
{
	int id;
	str* nazwa;
	int x;
	int y;
	sasiedztwo* s;
};


Miasto* addNew(str* nazwa, int x, int y);

