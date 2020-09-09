#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <SDL.h>

#include "funkcje.h"
int main(int argc, char ** argv) {
	int how_many_points = 3, divide_distance_by = 2;
	// przetworzenie
	if (argc > 3) {
		printf("zle wywolanie. Poprawne wywolanie: chaos.exe ile_punktow_bocznych dzielenie_odleglosci_przez\n");
		return 1;
	}
	else if (argc == 3) {
		how_many_points = atoi(argv[1]);
		divide_distance_by = atoi(argv[2]);
		if (divide_distance_by == 0) {
			printf("error, nie mozna dzielic przez zero.\n");
			return 1;
		}
	}
	else if (argc == 2) {
		how_many_points = atoi(argv[1]);
	}
	if (how_many_points > 5 || how_many_points < 1) {
		printf("nieprawidlowa liczba punktow bocznych. Podaj liczbe calkowita od 1 do 5.\n");
		return 1;
	}

	// ustawianie bocznych punktów w zale¿noœci od wyboru u¿ytkownika.
	set_points(how_many_points);
	// wyœwietlanie punktów
	display_points(how_many_points, divide_distance_by);
	return 0;
}