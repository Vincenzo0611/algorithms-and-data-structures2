#include <iostream>
#include "str.h"

void add(str*& head, char n)
{
    str* newS = new str;
    newS->s = n;
    newS->next = nullptr;

    if (head == nullptr) {
        head = newS;
        head->tail = head;
    }
    else {
        head->tail->next = newS;
        head->tail = newS;
    }
}


void del(str*& s)
{
    if (s != nullptr)
    {
        str* tmp = s->next;
        while (tmp != nullptr)
        {
            delete s;
            s = tmp;
            tmp = tmp->next;
        }
        delete s;
        s = nullptr;
    }
}

void del2(str*& s1, str*& s2)
{
    if (s1 != nullptr && s2 != nullptr)
    {
        str* tmp1 = s1->next;
        str* tmp2 = s2->next;
        while (tmp1 != nullptr || tmp2 != nullptr)
        {
            if (tmp1 != nullptr)
            {
                delete s1;
                s1 = tmp1;
                tmp1 = tmp1->next;
            }
            if(tmp2 != nullptr)
            {
                delete s2;
                s2 = tmp2;
                tmp2 = tmp2->next;
            }
        }
        delete s1;
        delete s2;
        s1 = nullptr;
        s2 = nullptr;
    }
}

void print(str* str)
{
    while (str != nullptr)
    {
        std::cout << str->s;
        str = str->next;
    }
}

bool same(str* s1, str* s2)
{
    if (s1 == nullptr || s2 == nullptr)
        return false;

    while (s1 != nullptr && s2 != nullptr)
    {
        if (s1->s != s2->s)
            return false;
        s1 = s1->next;
        s2 = s2->next;
    }

    if (s1 == nullptr && s2 == nullptr)
        return true;
    return false;
}
