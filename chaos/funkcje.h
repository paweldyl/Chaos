#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <SDL.h>

/** funkcja ustawiaj¹ca punkty w odpowiednich miejscach.
@param how_many_points liczba punktów do których bêdzie d¹¿yæ nastêpna wyœwietlana kropka.
@return Funkcja nie zwraca niczego.
*/
void set_points(int how_many_points);


/** funkcja wybiera nastêpny punkt do którego zmierzamy.
@param how_many_points liczba punktów do których d¹¿y wyœwietlana kropka.
@param last_selected punkt poprzednio wybrany. (jeœli to pierwszy punkt to powinniœmy przekazaæ -1)
@return zwraca number punktu do którego bêdziemy siê zbli¿aæ.
*/
int get_random_point(int how_many_points, int last_selected);


/** funkcja wyœwietdla punkty na ekranie.
@param how_many_points liczba punktów do których d¹¿y wyœwietlana kropka.
@param divide_distance_by liczba przez któr¹ bêdziemy dzieliæ odleg³oœæ miêdzy aktualnym punktem a wylosowanym.
@return zwraca number punktu do którego bêdziemy siê zbli¿aæ.
*/
void display_points(int how_many_points, int divide_distance_by);