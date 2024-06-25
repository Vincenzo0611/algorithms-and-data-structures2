#pragma once

struct Point
{
	int x;
	int y;
};

struct kolejka {
	Point p;
	kolejka* next;
	kolejka* tail;
};

void addNewKolejka(kolejka*& head, int x, int y);

Point Zkolejki(kolejka*& head);
