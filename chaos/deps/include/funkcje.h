#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <SDL.h>

/** funkcja ustawiaj�ca punkty w odpowiednich miejscach.
@param how_many_points liczba punkt�w do kt�rych b�dzie d��y� nast�pna wy�wietlana kropka.
@return Funkcja nie zwraca niczego.
*/
void set_points(int how_many_points);


/** funkcja wybiera nast�pny punkt do kt�rego zmierzamy.
@param how_many_points liczba punkt�w do kt�rych d��y wy�wietlana kropka.
@param last_selected punkt poprzednio wybrany. (je�li to pierwszy punkt to powinni�my przekaza� -1)
@return zwraca number punktu do kt�rego b�dziemy si� zbli�a�.
*/
int get_random_point(int how_many_points, int last_selected);


/** funkcja wy�wietdla punkty na ekranie.
@param how_many_points liczba punkt�w do kt�rych d��y wy�wietlana kropka.
@param divide_distance_by liczba przez kt�r� b�dziemy dzieli� odleg�o�� mi�dzy aktualnym punktem a wylosowanym.
@return zwraca number punktu do kt�rego b�dziemy si� zbli�a�.
*/
void display_points(int how_many_points, int divide_distance_by);