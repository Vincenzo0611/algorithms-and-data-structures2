#pragma once
#include <iostream>

struct str {
    char s;
    str* next; 
    str* tail; 
};

void add(str*& head, char n);

void del(str*& s);

void del2(str*& s1, str*& s2);

void print(str* str);

bool same(str* s1, str* s2);

//str* copy(str* s);

