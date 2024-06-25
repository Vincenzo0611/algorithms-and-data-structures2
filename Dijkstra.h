#pragma once
#include "Miasto.h"

struct Dijkstra {
	Miasto* wierzcholek;
	int odleglosc;
	bool odwiedzony;
	Miasto* poprzedni;
};

struct dane_kopca
{
	int id_miasta;
	int odleglosc;
};

struct Kopiec {
	dane_kopca* tablica;
	int* id_w_kopcu;
	int size;
	int ostatni_id;
};

void stowrz_kopiec(Kopiec*& k, int size);

void usun_kopiec(Kopiec*& k);

void dodaj_doKopca(Kopiec*& k, int id_miasta, int odleglosc);

void heapifyUp(Kopiec* k, int id);

void heapifyDown(Kopiec* k, int id);

dane_kopca wez_z_kopca(Kopiec* k);

void dijkstra(Dijkstra* tablica_D, int ilosc_miast, int id_zrodla, int id_celu, int type);

void drukuj_sciezke(Dijkstra* tablica_D, int id_zrodla, int id_koniec);
