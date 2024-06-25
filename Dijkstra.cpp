#include "Dijkstra.h"
#include <limits>
#include "stos.h"
#include "kolejka.h"
#include "define.h"


void stowrz_kopiec(Kopiec*& k, int size)
{
    k = new Kopiec;
    k->tablica = new dane_kopca[size];
    k->id_w_kopcu = new int[size];
    for (int i = 0; i < size; i++)
        k->id_w_kopcu[i] = -1;
    k->size = size;
    k->ostatni_id = -1;
}

void usun_kopiec(Kopiec*& k)
{
    delete[] k->tablica;
    delete[] k->id_w_kopcu;
    delete k;
}

void dodaj_doKopca(Kopiec*& k, int id_miasta, int odleglosc)
{
    if (k->ostatni_id == k->size - 1)
    {
        //Pelny kopiec
        return;
    }

    if (k->id_w_kopcu[id_miasta] != -1)
    {
        if (k->tablica[k->id_w_kopcu[id_miasta]].odleglosc > odleglosc)
        {
            k->tablica[k->id_w_kopcu[id_miasta]].odleglosc = odleglosc;
            heapifyUp(k, k->id_w_kopcu[id_miasta]);
        }
        return;
    }

    k->ostatni_id++;
    k->tablica[k->ostatni_id].id_miasta = id_miasta;
    k->id_w_kopcu[id_miasta] = k->ostatni_id;
    k->tablica[k->ostatni_id].odleglosc = odleglosc;
    heapifyUp(k, k->ostatni_id);
}

void heapifyUp(Kopiec* k, int id)
{
    if (id == 0)
    {
        return;
    }

    int parentIndex = (id - 1) / 2;
    if (k->tablica[parentIndex].odleglosc > k->tablica[id].odleglosc)
    {
        dane_kopca tmp;
        tmp.id_miasta = k->tablica[parentIndex].id_miasta;
        tmp.odleglosc = k->tablica[parentIndex].odleglosc;
        k->id_w_kopcu[tmp.id_miasta] = id;
        k->id_w_kopcu[k->tablica[id].id_miasta] = parentIndex;
        k->tablica[parentIndex].id_miasta = k->tablica[id].id_miasta;
        k->tablica[parentIndex].odleglosc = k->tablica[id].odleglosc;
        k->tablica[id].id_miasta = tmp.id_miasta;
        k->tablica[id].odleglosc = tmp.odleglosc;
        heapifyUp(k, parentIndex);
    }
}

dane_kopca wez_z_kopca(Kopiec* k)
{
    if (k->ostatni_id == -1)
    {
        //Kopiec pusty
        dane_kopca r;
        r.id_miasta = -1;
        r.odleglosc = -1;
        return r;
    }
    dane_kopca result;
    result.id_miasta = k->tablica[0].id_miasta;
    result.odleglosc = k->tablica[0].odleglosc;
    k->id_w_kopcu[result.id_miasta] = -1;
    k->id_w_kopcu[k->tablica[k->ostatni_id].id_miasta] = 0;
    k->tablica[0].id_miasta = k->tablica[k->ostatni_id].id_miasta;
    k->tablica[0].odleglosc = k->tablica[k->ostatni_id].odleglosc;
    k->ostatni_id--;
    heapifyDown(k, 0);
    return result;
}

void heapifyDown(Kopiec* k, int id)
{
    int leftIndex = 2 * id + 1;
    int rightIndex = 2 * id + 2;
    int minIndex = id;

    if (leftIndex <= k->ostatni_id && k->tablica[leftIndex].odleglosc < k->tablica[minIndex].odleglosc)
    {
        minIndex = leftIndex;
    }

    if (rightIndex <= k->ostatni_id && k->tablica[rightIndex].odleglosc < k->tablica[minIndex].odleglosc)
    {
        minIndex = rightIndex;
    }

    if (minIndex != id)
    {
        dane_kopca tmp;
        tmp.id_miasta = k->tablica[minIndex].id_miasta;
        tmp.odleglosc = k->tablica[minIndex].odleglosc;

        k->id_w_kopcu[tmp.id_miasta] = id;
        k->id_w_kopcu[k->tablica[id].id_miasta] = minIndex;

        k->tablica[minIndex].id_miasta = k->tablica[id].id_miasta;
        k->tablica[minIndex].odleglosc = k->tablica[id].odleglosc;
        k->tablica[id].id_miasta = tmp.id_miasta;
        k->tablica[id].odleglosc = tmp.odleglosc;
        heapifyDown(k, minIndex);
    }
}


void dijkstra(Dijkstra* tablica_D, int ilosc_miast, int id_zrodla, int id_celu, int type)
{
    Kopiec* kopiec = nullptr;

    stowrz_kopiec(kopiec, ilosc_miast);
    dodaj_doKopca(kopiec, id_zrodla, 0);
    for (int i = 0; i < ilosc_miast; i++)
    {
        tablica_D[i].odwiedzony = false;
        tablica_D[i].odleglosc = INT_MAX;
    }

    tablica_D[id_zrodla].odleglosc = 0;


    dane_kopca aktualne_miasto;

    do
    {
        aktualne_miasto = wez_z_kopca(kopiec);
        tablica_D[aktualne_miasto.id_miasta].odwiedzony = true;
        sasiedztwo* tmp = tablica_D[aktualne_miasto.id_miasta].wierzcholek->s;
        while (tmp != nullptr)
        {
            if (tmp->droga.koszt + tablica_D[aktualne_miasto.id_miasta].odleglosc < tablica_D[tmp->droga.cel->id].odleglosc)
            {
                tablica_D[tmp->droga.cel->id].odleglosc = tmp->droga.koszt + tablica_D[aktualne_miasto.id_miasta].odleglosc;
                dodaj_doKopca(kopiec, tmp->droga.cel->id, tablica_D[tmp->droga.cel->id].odleglosc);
                tablica_D[tmp->droga.cel->id].poprzedni = tablica_D[aktualne_miasto.id_miasta].wierzcholek;
            }
            tmp = tmp->next;
        }

    } while (aktualne_miasto.id_miasta != id_celu);

    std::cout << aktualne_miasto.odleglosc << " ";

    usun_kopiec(kopiec);


    if (type == 1 && id_zrodla != aktualne_miasto.id_miasta)
    {
        drukuj_sciezke(tablica_D, id_zrodla, tablica_D[aktualne_miasto.id_miasta].poprzedni->id);
    }

    std::cout << "\n";

}

void drukuj_sciezke(Dijkstra* tablica_D, int id_zrodla, int id_koniec)
{
    stos* stos = nullptr;
    while (id_koniec != id_zrodla)
    {
        addNewStos(stos, tablica_D[id_koniec].wierzcholek->nazwa);
        id_koniec = tablica_D[id_koniec].poprzedni->id;
    }
    while (stos != nullptr)
    {
        str* n;
        n = Zestosu(stos);
        print(n);
        std::cout << " ";
    }
}