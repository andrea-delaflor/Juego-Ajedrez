/*#pragma once
#include "vector2D.h"
#include "vector"
#include "ETSIDI.h"

#include "fichas.h"

class Peon: public Pieza        //peon se hereda de pieza
{
private:
	bool color; // FALSO NEGRO   TRUE BLANCO
	bool piezacomida;   //devuelve 1 o 0
	ETSIDI::SpriteSequence sprite{ "meterdireecion imagen", 1 };  //para blanco 
	ETSIDI::SpriteSequence sprite{ "meterdirecciondelaimagen", 1 };   //para negro

public:

	Peon()
	{
		//linea para colocar el peon
		//liena para dar la altura al peon
		//linea para colocar el peon 2
		//liena para dar la altura al peon2
	
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
	bool ok_piezacomida() {
		return piezacomida;
	}

	bool casilla_correcta() {

	}
};
*/