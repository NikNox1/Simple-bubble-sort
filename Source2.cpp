
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <iostream>
#include <iostream>
#include <iomanip>

long MierzCzas()
	{
		static clock_t start = 0;
		clock_t teraz = clock();
		long wynik = ((1000 * (teraz - start) + (CLOCKS_PER_SEC >> 1)) / CLOCKS_PER_SEC);
		start = teraz;
		return wynik;
	}
int *tablica, min, max, y, *tp,*tab;


void merge(int pocz, int sr, int kon)
{
	int ab, cd, ef;
	for (ab = pocz; ab <= kon; ab++) tp[ab] = tab[ab];
	ab = pocz; cd = sr + 1; ef = pocz;
	while (ab <= sr && cd <= kon)
	{
		if (tp[ab] < tp[cd])
			tab[ef++] = tp[ab++];
		else
			tab[ef++] = tp[cd++];
	}
	while (ab <= sr) tab[ef++] = tp[ab++];
}

void mergesort(int pocz, int kon)
{
	int sr;
	if (pocz < kon)
	{
		sr = (pocz + kon) / 2;
		mergesort(pocz, sr);
		mergesort(sr + 1, kon);
		merge(pocz, sr, kon);
	}
}


int main(void) {

	


	
	
	//deklaracje zminny i wprowadzanie danych
	printf("\n Ile liczb chcesz posortowa\206 ?\n Podaj ilo\230\206 liczb do posortowania:");
	
	scanf ("%d", &y);
	
	int *lw, *d,i,j;
	//tablice dynamiczne
	tablica = new int[y];
	tp = new int[y];
    tab = new int[y];
    lw = new int[max - min + 1];
	d = new int[y];

	
	

	printf("\n Podaj warto\230\206 zakresu liczb\n Min:");
	scanf("%d", &min);
	printf("Max:");
	scanf("%d", &max);
	printf("Sortuj\251 %d", y); 
	printf(" liczb w zakrese od %d", min); 
	printf(" do %d", max);
	
	printf("\n Sortowanie b\245belkowe");
	printf("\n\n\n Liczby przed posortowaniem\n\n ");

    //LOSOWANIE LICZB I PRZEKAZYWANIE ICH DO TABLICY
	for (int i= 0; i < y; i++) 
	{
		tablica[i] = (rand()%(max-min) + min );
		printf(" %d\t ", tablica[i]);
	}

	printf("\n");
	printf("\n\n Sortowanie, prosz\251 czeka\206...");
    

    
	printf("\n\n Liczby po sortowaniu");
	printf("\n\n ");
	
	MierzCzas();
	for (int a = 0; a < y; a++)
	{

		for (int i = 0; i < y; i++)
		{
			if (tablica[i] < tablica[i - 1])
			{
				int z = tablica[i];
				tablica[i] = tablica[i - 1];
				tablica[i - 1] = z;
			}
		}

	}

	for (int i = 0; i<y; i++)
	{
		printf(" %d\t ", tablica[i]);
	}
	
	printf("\n\n Czas sortowania : %lu ms\n", MierzCzas());

	_getch();
	_getch();
	
	///////////////////////////////////////////////////////////////////////////// BUCKET SORT

	printf(" \n\n\n Sortowanie kubelkowe \n");

	// tworze zbiór wejœciowy do sortowania
    // wyœwietlam zawartoœæ zbioru przed sortowaniem
	for (int i = 0; i < y; i++)
	{
		d[i] = (rand() % (max - min) + min);
		printf(" %d\t ", d[i]);
	}
	// sortuje

	// najpierw zeruje liczniki
	MierzCzas();
	for (i = min; i <= max; i++) lw[i - min] = 0;

	// zliczam w odpowiednich licznikach wyst¹pienia
	// wartoœci elementów sortowanego zbioru

	for (i = 0; i < y; i++) lw[d[i] - min]++;

	// zapisuje do zbioru wynikowego numery niezerowych liczników
	// tyle razy, ile wynosi ich zawartoœæ

	j = 0;
	for (i = min; i <= max; i++) while (lw[i - min]--) d[j++] = i;

	// wyœwietlam zawartoœæ zbioru po sortowaniu

	printf("\n Po sortowaniu:\n\n ");
	for (i = 0; i < y; i++)
	{
		printf (" %d\t ", d[i]);
    }
	printf("\n\nCzas sortowania : %lu ms\n", MierzCzas());

	_getch();
	_getch();

	//////////////////////////////////////////////////////////// MERGE SORT
	for (int i = 0; i < y; i++)
	{
		tab[i] = (rand() % (max - min) + min);
	}
	


	printf("\n\n Merge Sort\n\n Przed sortowaniem:\n\n ");
	for (i = 0; i < y; i++)
	{
		printf(" %d\t ", tab[i]);
	}
	MierzCzas();
	mergesort(0, y - 1);

	printf("\n Po sortowaniu:\n\n ");

	

	for (i = 0; i < y; i++)
	{
		printf(" %d\t ", tab[i]);
	}
	printf("\n\nCzas sortowania : %lu ms\n", MierzCzas()); 
	_getch();
	delete tablica;
	delete tab;
	delete tp;
	delete lw;
	delete d;
	_getch();
	
	
}

