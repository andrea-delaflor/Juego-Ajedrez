#pragma once
#include <vector>
#include "vector2D.h"
#include "ETSIDI.h"
#include "fichas.h"
/*class Alfil :public Ficha //Declaras la clase Alfil, que hereda de la clase abstracta Pieza. As� reutilizas todo el comportamiento com�n de las piezas.
{
private:
	bool color;//indica el color de la pieza FALSE= NEGRO Y TRUE=BLANCO 
	//sabes qu� sprite dibujar, a qu� jugador pertenece y c�mo calcular movimientos
	bool comido_pieza; //Registra si este alfil ya ha capturado (comido) alguna pieza durante la partida
	ETSIDI::SpriteSequence sprite{ "imagenes/alfilB.png", 1 }; //imagen del alfil blanco.1 indica que cada secuencia tiene 1 fotograma (no hay animaci�n en bucle)
	ETSIDI::SpriteSequence sprite2{ "imagenes/alfilN.png", 1 }; //imagen del alfin negro.1 indica que cada secuencia tiene 1 fotograma (no hay animaci�n en bucle)
public:
	Alfil() {
		//constructor por defecto 
		color = true; //blanco determinado 
	}
	void muevepieza(double, double);
	void dibuja_pieza();
	void set_pos_pieza(const Vector2D& pos);//Asigna la posici�n interna (posicion_pieza) de la pieza en el tablero
	void set_color_pieza(bool c);//Dibuja en pantalla el sprite correspondiente al alfil, eligiendo sprite o sprite2 seg�n color
	bool get_color() //valor de color (para saber en tiempo de ejecuci�n si es blanca o negra)
	{
		return color;
	}
	Vector2D get_pos() {
		return pos_pieza;
	}
	bool get_comido_pieza() {
		return comido_pieza; //Consulta si ya ha capturado alguna pieza.
	}

};
*/
