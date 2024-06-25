#include <iostream>
#include <cstdio>
#include "ListaM.h"
#include "define.h"
#include "Budowa_struktury.h"
#include "Dijkstra.h"
#include "kolejka.h"

using namespace std;

int main()
{
	int h = 0, w = 0;
	char input;
	int ilosc_lotow = 0, ilosc_pytan = 0;
	int ilosc_miast = 0;
	bool czy_istnieje_droga = false;

	ListaM** miasta = new ListaM * [HASH];

	for (int i = 0; i < HASH; i++)
		miasta[i] = nullptr;

	input = (char)getchar();

	while (input > 47 && input < 58)
	{
		w = w * 10 + input - 48;
		input = (char)getchar();
	}

	input = (char)getchar();

	while (input > 47 && input < 58)
	{
		h = h * 10 + input - 48;
		input = (char)getchar();
	}

	char* mapa = new char[w * h];
	int* visited = new int[w * h];
	char c;
	kolejka* listaPunktow = nullptr;


	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			c = (char)(char)getchar();
			if (c > ' ')
			{
				if (c == '*')
				{
					addNewKolejka(listaPunktow, j, i);
					ilosc_miast++;
				}
				if (c == '#')
					czy_istnieje_droga = true;
				mapa[i * w + j] = c;
			}
			else
				j--;
		}
	}

	Dijkstra* tablica_D = new Dijkstra[ilosc_miast];

	Znajdz_miasta(mapa, w, h, miasta, listaPunktow, tablica_D);

	bool v = true;
	for (int i = 0; i < HASH; i++)
	{
		ListaM* tmp = miasta[i];
		while (tmp != nullptr)
		{
			if (v == true && czy_istnieje_droga == true)
			{
				BFS(tmp->m, mapa, visited, w, h, miasta, ilosc_miast);
				if (ilosc_miast == 2)
					v = false;
			}
			else
			{
				i = HASH;
			}
			tmp = tmp->next;
		}
	}


	delete[] mapa;
	delete[] visited;


	input = (char)getchar();
	if(input == '\n')
		input = (char)getchar();

	while (input > 47 && input < 58)
	{
		ilosc_lotow = ilosc_lotow * 10 + input - 48;
		input = (char)getchar();
	}

	char s;
	str* zrodlo = nullptr;
	str* cel = nullptr;
	int time = 0;

	for (int i = 0; i < ilosc_lotow; i++)
	{
		s = (char)getchar();
		while(s <= ' ')
			s = (char)getchar();
		while (s > ' ')
		{
			add(zrodlo, s);
			s = (char)getchar();
		}
		s = (char)getchar();
		while (s > ' ')
		{
			add(cel, s);
			s = (char)getchar();
		}

		s = (char)getchar();

		while(s > 47 && s < 58)
		{
			time = time * 10 + s - 48;
			s = (char)getchar();
		}

		int hash = hashuj(zrodlo);

		ListaM* tmp = miasta[hash];
		if(tmp->next != nullptr)
		{
			while (same(tmp->m->nazwa, zrodlo) == false)
			{
				tmp = tmp->next;
			}
		}

		hash = hashuj(cel);

		ListaM* tmp2 = miasta[hash];

		if(tmp2->next != nullptr)
		{
			while (same(tmp2->m->nazwa, cel) == false)
			{
				tmp2 = tmp2->next;
			}
		}

		Droga d;
		d.koszt = time;
		d.cel = tmp2->m;

		addNewSorted(tmp->m->s, d);

		del2(zrodlo, cel);
		time = 0;
	}

	//Dijkstra
	input = (char)getchar();

	while (input > 47 && input < 58)
	{
		ilosc_pytan = ilosc_pytan * 10 + input - 48;
		input = (char)getchar();
	}


	for (int i = 0; i < ilosc_pytan; i++)
	{
		int type = 0;
		s = (char)getchar();
		while (s <= ' ')
			s = (char)getchar();
		while (s > ' ')
		{
			add(zrodlo, s);
			s = (char)getchar();
		}
		s = (char)getchar();
		while (s > ' ')
		{
			add(cel, s);
			s = (char)getchar();
		}
		
		input = (char)getchar();

		while (input > 47 && input < 58)
		{
			type = type * 10 + input - 48;
			input = (char)getchar();
		}

		int hash = hashuj(zrodlo);

		ListaM* tmp = miasta[hash];

		if(tmp->next != nullptr)
		{
			while (same(tmp->m->nazwa, zrodlo) == false)
			{
				tmp = tmp->next;
			}
		}

		hash = hashuj(cel);

		ListaM* tmp2 = miasta[hash];
		if(tmp2->next != nullptr)
		{
			while (same(tmp2->m->nazwa, cel) == false)
			{
				tmp2 = tmp2->next;
			}
		}

		//tmp - skad
		//tmp2 - dokad
		//type - 0 czy 1

		dijkstra(tablica_D, ilosc_miast, tmp->m->id, tmp2->m->id, type);

		del2(zrodlo, cel);
	}





	for (int i = 0; i < HASH; i++)
	{
		deleteAll(miasta[i]);
	}

	delete[] tablica_D;
	delete[] miasta;

	return 0;
}