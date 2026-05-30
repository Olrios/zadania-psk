#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "check_read_number.h"

int main()
{
	int uruchomiony = 1;
	int zadanie;
	char xx, aa, bb, cc;
	double x, a, b, c;

	const char* lista_zadan[] = {
		"",
		// zadania:
		"Podaj liczbe wymierna aby wyœwietliæ jej pierwiastek kwadratowy:\n",
		"Podaj trzy dowolne liczby CALKOWITE aby wyliczyc ich œrednia arytmetyczna:\n",
		"Podaj liczbê wymiern¹ aby zapisaæ w notacji wyk³adniczej:\n",
		"Podaj liczbe wymierna, by zaokr¹gliæ do 2 miejsc po przecinku:\n",
		"Podaj 3 liczby aby znaleŸæ najwiêksz¹ z nich:\n",
		"Obliczanie pola trójk¹ta na podstawie wprowadzonych danych.\nCzy chcesz podaæ wymiary [B]oków czy wymiary [W]ysokoœci i podstawy?\n"
	};
	int max_index_listy_zadan = (sizeof(lista_zadan) / sizeof(lista_zadan[0])) - 1;

	printf("Podaj zadanie do wyœwietlenia z zakresu 1 do %d:\n", max_index_listy_zadan);

	while (uruchomiony) {
		printf("%s\n", lista_zadan[0]);
		if ((scanf_s("%d", &zadanie) != 1) || zadanie < 0 || zadanie > max_index_listy_zadan) {
			printf("Niepoprawna wartoœæ! Podaj liczbê z zakresu 1 do %d:\n", max_index_listy_zadan);
			return 1;
		}

		if (lista_zadan[zadanie]) printf("%s\n", lista_zadan[zadanie]);

		switch (zadanie) {
			case 1:
				if (!check_read_number(&x)) break;
				printf("Pierwiastek z liczby %f: %f\n", x, sqrt(x));
				break;

			case 2:
				if (!check_read_number(&a) || !check_read_number(&b) || !check_read_number(&c)) break;
				printf("Œrednia arytmetyczna z %lf, %lf, %lf to dok³adnie: %.2f\n", a, b, c, ((a + b + c) / 3.0));
				break;

			case 3:
				if (!check_read_number(&x)) break;
				printf("Wynik: %e\n", x);
				break;

			case 4:
				if (!check_read_number(&x)) break;
				printf("Wynik: %.2f\n", x);
				break;

			case 5:
				if (!check_read_number(&a) || !check_read_number(&b) || !check_read_number(&c)) break;
				x = (a > b) ? a : b;
				x = (b > c) ? b : c;
				x = (c > a) ? c : a;
				printf("Wynik: %f\n", x);
				break;

			case 6:
				scanf_s("%c", &xx, 1);
				if (xx == 'w' || xx == 'W') {
					if (!check_read_number(&a) || !check_read_number(&b)) break;
					printf("Pole tego trójk¹ta o podstawie i wysokoœci %lf, %lf to %lf\n", a, b, a * b / 2);
				}
				
				if (xx == 'b' || xx == 'B') {
					if (!check_read_number(&a) || !check_read_number(&b) || !check_read_number(&c)) break;
				}
				break;

			case 7:

			case 0:
				uruchomiony = 0;
				break;

			default:
				break;
		}
	}

	printf("tesdt");
	return 0;
}