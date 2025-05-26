#pragma once
#include "Vector2D.h"
#include "Menu.h"
const int ancho_casilla = 154;
const int alto_casilla = 154;

class Raton
{
public:
	Vector2D casilla{};				//donde esta ahora
	Vector2D casilla_anterior{};	//donde estaba

	Vector2D posicion{};
	

	Vector2D elige_casilla(Vector2D posicion, Menu::ModoJuego modo);		//En caso de se Vector2D, la funcion devuelve el vector casilla, que va del 1,1 hasta el nfila,mcolumna
};

