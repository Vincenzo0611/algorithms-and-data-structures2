#include <cmath>
#include "Budowa_struktury.h"
#include "kolejka.h"

void Znajdz_miasta(char* tablica, int w, int h, ListaM* miasta[], kolejka* listaP, Dijkstra* tablica_D)
{
	Point punkt;
	while (listaP != nullptr)
	{
		punkt = Zkolejki(listaP);
		dodajMiasto(miasta, tablica_D, tablica, punkt.x, punkt.y, w, h);
		
	}
}

void dodajMiasto(ListaM* miasta[], Dijkstra* tablica_D, char* tablica, int x, int y, int w, int h)
{
	str* nazwa = nullptr;
	if (x + 1 < w)
	{
		if (tablica[y * w + x + 1] != '.' && tablica[y * w + x + 1] != '*' && tablica[y * w + x + 1] != '#')
		{
			//prawo
			int xL = x + 1;
			int yL = y;
			nazwa = NazwazMapy(tablica, xL, yL, w);
			int hash = hashuj(nazwa);
			ListaM* head = AddNew(miasta[hash], tablica_D, nazwa, x, y);
			miasta[hash] = head;
			return;
		}
	}
	if (x > 0)
	{
		if (y > 0)
		{
			if (tablica[(y - 1) * w + x - 1] != '.' && tablica[(y - 1) * w + x - 1] != '*' && tablica[(y - 1) * w + x - 1] != '#')
			{
				//Litera trzeba isc w lewo
				int xL = x - 1;
				int yL = y - 1;
				while (tablica[yL * w + xL] != '.' && tablica[yL * w + xL] != '*' && tablica[yL * w + xL] != '#')
				{
					xL = xL - 1;
					if (xL < 0)
						break;
				}
				xL++;
				nazwa = NazwazMapy(tablica, xL, yL, w);
				int hash = hashuj(nazwa);
				ListaM* head = AddNew(miasta[hash], tablica_D, nazwa, x, y);
				miasta[hash] = head;
				return;
			}
		}
		if (tablica[y * w + x - 1] != '.' && tablica[y * w + x - 1] != '*' && tablica[y * w + x - 1] != '#')
		{
			//Litera trzeba isc w lewo
			int xL = x - 1;
			int yL = y;
			while (tablica[yL * w + xL] != '.' && tablica[yL * w + xL] != '*' && tablica[yL * w + xL] != '#')
			{
				xL = xL - 1;
				if (xL < 0)
					break;
			}
			xL++;
			nazwa = NazwazMapy(tablica, xL, yL, w);
			int hash = hashuj(nazwa);
			ListaM* head = AddNew(miasta[hash], tablica_D, nazwa, x, y);
			miasta[hash] = head;
			return;
		}
		if (y + 1 < h)
		{
			if (tablica[(y + 1) * w + x - 1] != '.' && tablica[(y + 1) * w + x - 1] != '*' && tablica[(y + 1) * w + x - 1] != '#')
			{
				//Litera trzeba isc w lewo
				int xL = x - 1;
				int yL = y + 1;
				while (tablica[yL * w + xL] != '.' && tablica[yL * w + xL] != '*' && tablica[yL * w + xL] != '#')
				{
					xL = xL - 1;
					if (xL < 0)
						break;
				}
				xL++;
				nazwa = NazwazMapy(tablica, xL, yL, w);
				int hash = hashuj(nazwa);

				ListaM* head = AddNew(miasta[hash], tablica_D, nazwa, x, y);
				miasta[hash] = head;
				return;
			}
		}
	}
	if (y > 0)
	{
		if (tablica[(y - 1) * w + x] != '.' && tablica[(y - 1) * w + x] != '*' && tablica[(y - 1) * w + x] != '#')
		{
			//Litera trzeba isc w prawo
			int xL = x;
			int yL = y - 1;
			nazwa = NazwazMapy(tablica, xL, yL, w);
			int hash = hashuj(nazwa);
			ListaM* head = AddNew(miasta[hash], tablica_D, nazwa, x, y);
			miasta[hash] = head;
			return;
		}
		if (x + 1 < w)
		{
			if (tablica[(y - 1) * w + x + 1] != '.' && tablica[(y - 1) * w + x + 1] != '*' && tablica[(y - 1) * w + x + 1] != '#')
			{
				//Litera trzeba isc w prawo
				int xL = x + 1;
				int yL = y - 1;
				nazwa = NazwazMapy(tablica, xL, yL, w);
				int hash = hashuj(nazwa);
				ListaM* head = AddNew(miasta[hash], tablica_D, nazwa, x, y);
				miasta[hash] = head;
				return;
			}
		}
	}
	if (y + 1 < h)
	{
		if (tablica[(y + 1) * w + x] != '.' && tablica[(y + 1) * w + x] != '*' && tablica[(y + 1) * w + x] != '#')
		{
			//Litera trzeba isc w prawo
			int xL = x;
			int yL = y + 1;
			nazwa = NazwazMapy(tablica, xL, yL, w);
			int hash = hashuj(nazwa);

			ListaM* head = AddNew(miasta[hash], tablica_D, nazwa, x, y);
			miasta[hash] = head;
			return;
		}
		if (x + 1 < w)
		{
			if (tablica[(y + 1) * w + x + 1] != '.' && tablica[(y + 1) * w + x + 1] != '*' && tablica[(y + 1) * w + x + 1] != '#')
			{
				//Litera trzeba isc w prawo
				int xL = x + 1;
				int yL = y + 1;
				nazwa = NazwazMapy(tablica, xL, yL, w);
				int hash = hashuj(nazwa);

				ListaM* head = AddNew(miasta[hash], tablica_D, nazwa, x, y);
				miasta[hash] = head;
				return;
			}
		}
	}
}

str* NazwazMapy(char* tablica, int x, int y, int w)
{
	str* nazwa = nullptr;
	while (tablica[y * w + x] != '.' && tablica[y * w + x] != '*' && tablica[y * w + x] != '#')
	{
		add(nazwa, tablica[y * w + x]);
		if (x + 1 < w)
			x++;
		else
			break;
	}
	return nazwa;
}

int hashuj(str* nazwa)
{
	//hash
	unsigned long hash = H;

	while (nazwa != nullptr)
	{
		char c;
		c = nazwa->s;
		hash = hash * 59 + c;
		nazwa = nazwa->next;
	}

	return hash % HASH;
}

void BFS(Miasto* start, char* tablica, int* visited, int w, int h, ListaM* miasta[], int ilosc_miast)
{
	clear(visited, w, h);

	kolejka* kolejka = nullptr;
	Point punkt;
	Point kolejny;
	kolejny.x = 0;
	kolejny.y = 0;
	int q = 1;

	addNewKolejka(kolejka, start->x, start->y);
	visited[start->y * w + start->x] = 1;

	while (kolejka != nullptr || q == 0)
	{
		if (q == 0)
		{
			q = 1;
			punkt.x = kolejny.x;
			punkt.y = kolejny.y;
		}
		else
		{
			punkt = Zkolejki(kolejka);
		}
		if (punkt.x > 0 && visited[punkt.y * w + punkt.x - 1] == 0 && tablica[punkt.y * w + punkt.x - 1] != '.')
		{
			if (tablica[punkt.y * w + punkt.x - 1] == '*')
			{
				//Znalazl miasto
				Droga d;
				d.koszt = visited[punkt.y * w + punkt.x];
				str* nazwa = literaMiasto(tablica, punkt.x - 1, punkt.y, w, h);
				int hash = hashuj(nazwa);

				ListaM* tmp = miasta[hash];

				while (1)
				{
					if (tmp->m->x == punkt.x - 1 && tmp->m->y == punkt.y)
						break;
					else
						tmp = tmp->next;
				}

				d.cel = tmp->m;

				addNewSorted(start->s, d);
				if (ilosc_miast == 2)
				{
					Miasto* powrot = d.cel;
					d.cel = start;
					addNewSorted(powrot->s, d);
				}
			}
			else if (tablica[punkt.y * w + punkt.x - 1] == '#')
			{
				visited[punkt.y * w + punkt.x - 1] = visited[punkt.y * w + punkt.x] + 1;
				if (kolejka == nullptr)
				{
					if (q == 1)
					{
						kolejny.x = punkt.x - 1;
						kolejny.y = punkt.y;
						q = 0;
					}
					else if (q == 0)
					{
						addNewKolejka(kolejka, kolejny.x, kolejny.y);
						addNewKolejka(kolejka, punkt.x - 1, punkt.y);
					}
				}
				else
					addNewKolejka(kolejka, punkt.x - 1, punkt.y);
			}
		}
		if (punkt.x + 1 < w && visited[punkt.y * w + punkt.x + 1] == 0 && tablica[punkt.y * w + punkt.x + 1] != '.')
		{
			if (tablica[punkt.y * w + punkt.x + 1] == '*')
			{
				//Znalazl miasto
				Droga d;
				d.koszt = visited[punkt.y * w + punkt.x];
				str* nazwa = literaMiasto(tablica, punkt.x + 1, punkt.y, w, h);
				int hash = hashuj(nazwa);

				ListaM* tmp = miasta[hash];

				while (1)
				{
					if (tmp->m->x == punkt.x + 1 && tmp->m->y == punkt.y)
						break;
					else
						tmp = tmp->next;
				}

				d.cel = tmp->m;

				addNewSorted(start->s, d);
				if (ilosc_miast == 2)
				{
					Miasto* powrot = d.cel;
					d.cel = start;
					addNewSorted(powrot->s, d);
				}
			}
			if (tablica[punkt.y * w + punkt.x + 1] == '#')
			{
				visited[punkt.y * w + punkt.x + 1] = visited[punkt.y * w + punkt.x] + 1;
				if (kolejka == nullptr)
				{
					if (q == 1)
					{
						kolejny.x = punkt.x + 1;
						kolejny.y = punkt.y;
						q = 0;
					}
					else if (q == 0)
					{
						addNewKolejka(kolejka, kolejny.x, kolejny.y);
						addNewKolejka(kolejka, punkt.x + 1, punkt.y);
					}
				}
				else
					addNewKolejka(kolejka, punkt.x + 1, punkt.y);
			}
		}
		if (punkt.y > 0 && visited[(punkt.y - 1) * w + punkt.x] == 0 && tablica[(punkt.y - 1) * w + punkt.x] != '.')
		{
			if (tablica[(punkt.y - 1) * w + punkt.x] == '*')
			{
				//Znalazl miasto
				Droga d;
				d.koszt = visited[punkt.y * w + punkt.x];
				str* nazwa = literaMiasto(tablica, punkt.x, punkt.y - 1, w, h);
				int hash = hashuj(nazwa);

				ListaM* tmp = miasta[hash];

				while (1)
				{
					if (tmp->m->x == punkt.x && tmp->m->y == punkt.y - 1)
						break;
					else
						tmp = tmp->next;
				}

				d.cel = tmp->m;

				addNewSorted(start->s, d);
				if (ilosc_miast == 2)
				{
					Miasto* powrot = d.cel;
					d.cel = start;
					addNewSorted(powrot->s, d);
				}
			}
			if (tablica[(punkt.y - 1) * w + punkt.x] == '#')
			{
				visited[(punkt.y - 1) * w + punkt.x] = visited[punkt.y * w + punkt.x] + 1;
				if (kolejka == nullptr)
				{
					if (q == 1)
					{
						kolejny.x = punkt.x;
						kolejny.y = punkt.y - 1;
						q = 0;
					}
					else if (q == 0)
					{
						addNewKolejka(kolejka, kolejny.x, kolejny.y);
						addNewKolejka(kolejka, punkt.x, punkt.y - 1);
					}
				}
				else
					addNewKolejka(kolejka, punkt.x, punkt.y - 1);
			}
		}
		if (punkt.y + 1 < h && visited[(punkt.y + 1) * w + punkt.x] == 0 && tablica[(punkt.y + 1) * w + punkt.x] != '.')
		{
			if (tablica[(punkt.y + 1) * w + punkt.x] == '*')
			{
				//Znalazl miasto
				Droga d;
				d.koszt = visited[punkt.y * w + punkt.x];
				str* nazwa = literaMiasto(tablica, punkt.x, punkt.y + 1, w, h);
				int hash = hashuj(nazwa);

				ListaM* tmp = miasta[hash];

				while (1)
				{
					if (tmp->m->x == punkt.x && tmp->m->y == punkt.y + 1)
						break;
					else
						tmp = tmp->next;
				}

				d.cel = tmp->m;

				addNewSorted(start->s, d);
				if (ilosc_miast == 2)
				{
					Miasto* powrot = d.cel;
					d.cel = start;
					addNewSorted(powrot->s, d);
				}
			}
			if (tablica[(punkt.y + 1) * w + punkt.x] == '#')
			{
				visited[(punkt.y + 1) * w + punkt.x] = visited[punkt.y * w + punkt.x] + 1;
				if (kolejka == nullptr)
				{
					if (q == 1)
					{
						kolejny.x = punkt.x;
						kolejny.y = punkt.y + 1;
						q = 0;
					}
					else if (q == 0)
					{
						addNewKolejka(kolejka, kolejny.x, kolejny.y);
						addNewKolejka(kolejka, punkt.x, punkt.y + 1);
					}
				}
				else
					addNewKolejka(kolejka, punkt.x, punkt.y + 1);
			}
		}
	}
}

str* literaMiasto(char* tablica, int x, int y, int w, int h)
{
	str* nazwa = nullptr;
	if (x + 1 < w)
	{
		if (tablica[y * w + x + 1] != '.' && tablica[y * w + x + 1] != '*' && tablica[y * w + x + 1] != '#')
		{
			//prawo
			int xL = x + 1;
			int yL = y;
			nazwa = NazwazMapy(tablica, xL, yL, w);
			return nazwa;
		}
	}
	if (x > 0)
	{
		if (y > 0)
		{
			if (tablica[(y - 1) * w + x - 1] != '.' && tablica[(y - 1) * w + x - 1] != '*' && tablica[(y - 1) * w + x - 1] != '#')
			{
				//Litera trzeba isc w lewo
				int xL = x - 1;
				int yL = y - 1;
				while (tablica[yL * w + xL] != '.' && tablica[yL * w + xL] != '*' && tablica[yL * w + xL] != '#')
				{
					xL = xL - 1;
					if (xL < 0)
						break;
				}
				xL++;
				nazwa = NazwazMapy(tablica, xL, yL, w);
				return nazwa;
			}
		}
		if (tablica[y * w + x - 1] != '.' && tablica[y * w + x - 1] != '*' && tablica[y * w + x - 1] != '#')
		{
			//Litera trzeba isc w lewo
			int xL = x - 1;
			int yL = y;
			while (tablica[yL * w + xL] != '.' && tablica[yL * w + xL] != '*' && tablica[yL * w + xL] != '#')
			{
				xL = xL - 1;
				if (xL < 0)
					break;
			}
			xL++;
			nazwa = NazwazMapy(tablica, xL, yL, w);
			return nazwa;
		}
		if (y + 1 < h)
		{
			if (tablica[(y + 1) * w + x - 1] != '.' && tablica[(y + 1) * w + x - 1] != '*' && tablica[(y + 1) * w + x - 1] != '#')
			{
				//Litera trzeba isc w lewo
				int xL = x - 1;
				int yL = y + 1;
				while (tablica[yL * w + xL] != '.' && tablica[yL * w + xL] != '*' && tablica[yL * w + xL] != '#')
				{
					xL = xL - 1;
					if (xL < 0)
						break;
				}
				xL++;
				nazwa = NazwazMapy(tablica, xL, yL, w);
				return nazwa;
			}
		}
	}
	if (y > 0)
	{
		if (tablica[(y - 1) * w + x] != '.' && tablica[(y - 1) * w + x] != '*' && tablica[(y - 1) * w + x] != '#')
		{
			//Litera trzeba isc w prawo
			int xL = x;
			int yL = y - 1;
			nazwa = NazwazMapy(tablica, xL, yL, w);
			return nazwa;
		}
		if (x + 1 < w)
		{
			if (tablica[(y - 1) * w + x + 1] != '.' && tablica[(y - 1) * w + x + 1] != '*' && tablica[(y - 1) * w + x + 1] != '#')
			{
				//Litera trzeba isc w prawo
				int xL = x + 1;
				int yL = y - 1;
				nazwa = NazwazMapy(tablica, xL, yL, w);
				return nazwa;
			}
		}
	}
	if (y + 1 < h)
	{
		if (tablica[(y + 1) * w + x] != '.' && tablica[(y + 1) * w + x] != '*' && tablica[(y + 1) * w + x] != '#')
		{
			//Litera trzeba isc w prawo
			int xL = x;
			int yL = y + 1;
			nazwa = NazwazMapy(tablica, xL, yL, w);
			return nazwa;
		}
		if (x + 1 < w)
		{
			if (tablica[(y + 1) * w + x + 1] != '.' && tablica[(y + 1) * w + x + 1] != '*' && tablica[(y + 1) * w + x + 1] != '#')
			{
				//Litera trzeba isc w prawo
				int xL = x + 1;
				int yL = y + 1;
				nazwa = NazwazMapy(tablica, xL, yL, w);
				return nazwa;
			}
		}
	}
	return nazwa;
}

void clear(int* visited, int w, int h)
{
	for (int i = 0; i < w * h; i++)
		visited[i] = 0;
}