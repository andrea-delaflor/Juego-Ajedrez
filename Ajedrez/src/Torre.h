#pragma once
#include "ETSIDI.h"
#include "Fichas.h"

class Torre:public Fichas
{
private:
	bool color; //al usar bool se devuelve un valor booleano, es decir, true o false

public:
	Torre() 
	{
		//aqui van las sentencias del sprite
		color = false; //negro
	}
	void muevepieza(double, double);
	void dibuja_pieza();
	void set_color_pieza(bool c);
	bool get_color()
	{
		return color;
	}
	void set_pos_pieza(const Vector2D& pos);
	Vector2D get_pos()
	{
		return pos_pieza;
	}
	//entender que es lo de piezaahogada y casillavalida
	// casilla valida creo que son las casillas que son posibles movimientos teniendo en cuenta como se mueve la ficha
	//ver tambien la lógica de de la eliminacion de piezas: como se come una pieza la torre
};

