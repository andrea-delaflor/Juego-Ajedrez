#pragma once
#include "Vector2D.h"
//#include "Raton.h"
#include <vector>
#include "ETSIDI.h"
#include "Fichas.h"

using std::vector;

class Rey :public Fichas
{
	bool color; //al usar bool se devuelve un valor booleano, es decir, true o false
	bool haComidoFicha;
	//Raton r;

	ETSIDI::SpriteSequence sprite{ "imagenes/REY BLANCO.png", 1 };
	ETSIDI::SpriteSequence sprite2{ "imagenes/REY NEGRO.png", 1 };
public:
	Rey() {
		sprite.setCenter(+0.75, +0.75);
		sprite.setSize(1.5, 1.5);
		sprite2.setCenter(+0.75, +0.75); 
		sprite2.setSize(1.5, 1.5);
		color = TRUE; //Blanco predeterminado
	}
	void mueveficha(double, double) override;
	void set_pos_ficha(const Vector2D& pos) override; //direccion rey
	void dibuja_ficha() override;
	void set_color_ficha(bool a) override;    //recuerda TRUE= blanco......FALSE=negro
	bool get_color() override { return color; }
	bool get_haComidoFicha() override { return haComidoFicha; }
	Vector2D get_pos() override { return posicion_ficha; }

	bool FichaAhogada(vector<Vector2D> posiciones);
	std::vector<Vector2D> get_movimientos_validos(std::vector<std::vector<Fichas*>> control, Vector2D pos, Vector2D reyPos) override;

	bool casillaValida(int i, int j, std::vector<std::vector<Fichas*>> control) override;
	/*

	
	

	void muevepieza(double, double);
	void set_pos_pieza(const Vector2D& pos);	// Se introduce la dirección en la que esta el rey
	void dibuja_pieza();
	void set_color_pieza(bool a);
	bool get_color() {
		return color;
	}
	bool get_haComidoPieza() {
		return haComidoPieza;
	}
	Vector2D get_pos() {
		return posicion_pieza;
	}
	bool piezaAhogada(std::vector<Vector2D> posiciones);
	std::vector<Vector2D> get_movimientos_validos(std::vector<std::vector<Pieza*>> control, Vector2D pos, Vector2D reyPos);
	bool casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control);  // Para que no se salga del tamaño de la matriz control al comprobar si es jaque o no
};*/
};

