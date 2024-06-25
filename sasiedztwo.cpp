#include "sasiedztwo.h"


void addNewSorted(sasiedztwo*& head, Droga droga) 
{

    if (head == nullptr) {
        sasiedztwo* newNode = new sasiedztwo;
        newNode->droga = droga;
        newNode->next = nullptr;
        head = newNode;
        return;
    }

    sasiedztwo* current = head;

    if (current->droga.cel->id == droga.cel->id)
    {
        if (current->droga.koszt <= droga.koszt)
        {
            return;
        }
        else
        {
            current->droga.koszt = droga.koszt;
            return;
        }
    }


    if (droga.koszt < head->droga.koszt) 
    {
        sasiedztwo* newNode = new sasiedztwo;
        newNode->droga = droga;
        newNode->next = head;
        head = newNode;
        return;
    }

    while (current->next != nullptr && current->next->droga.koszt < droga.koszt)
    {
        if (current->next->droga.cel->id == droga.cel->id)
        {
            if (current->next->droga.koszt <= droga.koszt)
            {
                return;
            }
            else
            {
                current->droga.koszt = droga.koszt;
                return;
            }
        }
        current = current->next;
    }

    sasiedztwo* newNode = new sasiedztwo;
    newNode->droga = droga;
    newNode->next = current->next;
    current->next = newNode;
}

void deleteList(sasiedztwo* head) {
    sasiedztwo* current = head;
    sasiedztwo* next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}