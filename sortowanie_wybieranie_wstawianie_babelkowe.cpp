// sortowanie_przez_wybieranie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <Windows.h>
using namespace std;
void selection_sort(int tab[], int n);
void sortowanie_wstawianie(int tab[], int n);
void sortowanie_babelkowe(int tab[], int n);


void sortowanie_babelkowe(int tab[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (tab[i] > tab[j])
			{
				swap(tab[i], tab[j]);
			}
		}
	}
}

void sortowanie_wstawianie(int tab[], int n)
{
	int temp, j;
	for (int i = 1; i < n; i++)
	{
		temp = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > temp)
		{
			tab[j + 1] = tab[j]; //przesuwanie element�w
			--j;
		}
		tab[j + 1] = temp; //wstawienie pom w odpowiednie miejsce
	}
}

void selection_sort(int tab[], int n) //n - ilo�� element�w do posortowania
{
	int k; //zmienna pomocnicza przechowuj�ca indeks kom�rki 
			//z minimaln� warto�ci�
	for (int i = 0; i < n - 1; i++)
	{
		k = i;
		for (int j = i + 1; j < n; j++) //p�tla wyszukuje najmniejszy element w podzbiorze nieposortowanym
			if (tab[j] < tab[k])
				k = j;

		//zamiana elementu najmniejszego w podzbiorze z pierwsz� pozycj� nieposortowan�
		swap(tab[i], tab[k]);
	}
}




int main()
{
	 long int size=20000;
	int* tablica;
	tablica = new int[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++) 
	{
		tablica[i] =rand() % 100;
	}
	//for (int i = 0; i < size; i++)
	//{
		//cout << tablica[i] << endl;
	//}
	selection_sort(tablica, size);
	cout << endl;

	//for (int i = 0; i < size; i++)
	//{
		//cout << tablica[i] << endl;
	//}
	clock_t start, stop;
    std::cout << "Hello World!\n";
	start= clock();
	sortowanie_wstawianie(tablica, size);
	stop = clock();
	double wynik = ( double) ((stop - start) /CLOCKS_PER_SEC);
	cout << "czas: " << wynik << endl;
	//for (int i = 0; i < size; i++)
	//{
		//cout << tablica[i] << endl;
	//}
	start = clock();
	selection_sort(tablica, size);
	stop = clock();
	wynik = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "czas: " << wynik << endl;

	start = clock();
	sortowanie_babelkowe(tablica, size);
	stop = clock();
	wynik = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "czas: " << wynik << endl;

}

