#include "Miasto.h"


Miasto* addNew(str* nazwa, int x, int y)
{
    static int id = 0;
    Miasto* newM = new Miasto;
    newM->id = id;
    id++;
    newM->nazwa = nazwa;
    newM->x = x;
    newM->y = y;
    newM->s = nullptr;

    return newM;
}