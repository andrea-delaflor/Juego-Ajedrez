#pragma once
#include <vector>
#include "ETSIDI.h"
#include "Vector2D.h"
#include "Fichas.h"

class Caballo : public Fichas {
private:
	bool color; // FALSE es negro. TRUE es blanco
	bool haComidoFicha;
	ETSIDI::SpriteSequence sprite{ "imagenes/CABALLO BLANCO.png", 1 };
	ETSIDI::SpriteSequence sprite2{ "imagenes/CABALLO NEGRO.png", 1 };
public:
	Caballo() { //depende de como seleccionemos el tablero miarar ancho de las casillaas
		sprite.setCenter(+0.75, +0.75);
		sprite.setSize(1.5, 1.5);
		sprite2.setCenter(+0.75, +0.75);
		sprite2.setSize(1.5, 1.5);
		color = true; // Blanco predeterminado
	}

	void mueveficha(double, double);
	void set_pos_ficha(const Vector2D& pos);
	void dibuja_ficha();
	void set_color_ficha(bool a);
	bool get_color() {
		return color;
	}
	Vector2D get_pos() {
		return posicion_ficha;
	}
	bool get_haComidoFicha() {
		return haComidoFicha;
	}
	bool FichaAhogada(std::vector<Vector2D> posiciones);

	std::vector<Vector2D> get_movimientos_validos(std::vector<std::vector<Fichas*>> control, Vector2D pos, Vector2D reyPos);

	bool casillaValida(int i, int j, std::vector<std::vector<Fichas*>> control);  // Para que no se salga del tamaño de la matriz control al comprobar si es jaque o no
};