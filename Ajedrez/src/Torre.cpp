#include "Torre.h"
#include "ETSIDI.h"
#include "freeglut"
#include "Fichas.h"

void Torre::muevepieza(double x, double y)
{
	pos_pieza.x = x;
	pos_pieza.y = y;
}

void Torre::set_pos_pieza(const Vector2D& pos)
{
	if ()
		pos_pieza = pos;
}

void Torre::set_color_pieza(bool c)
{
	if (c == true)
		color = true; //blanco
	if (c == false)
		color = false; //negro
}
//falta la lógica de la torre con el std
//ver que es lo de piezaahogada y casilla valida

