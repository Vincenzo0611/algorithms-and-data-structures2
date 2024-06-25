#pragma once
#include "ListaM.h"
#include "str.h"
#include "define.h"
#include "kolejka.h"
#include "Dijkstra.h"


void Znajdz_miasta(char* tablica, int w, int h, ListaM* miasta[], kolejka* listaP, Dijkstra* tablica_D);

void dodajMiasto(ListaM* miasta[], Dijkstra* tablica_D, char* tablica, int x, int y, int w, int h);

str* NazwazMapy(char* tablica, int x, int y, int w);

int hashuj(str* nazwa);

void BFS(Miasto* start, char* tablica, int* visited, int w, int h, ListaM* miasta[], int ilosc_miast);

str* literaMiasto(char* tablica, int x, int y, int w, int h);

void clear(int* visited, int w, int h);