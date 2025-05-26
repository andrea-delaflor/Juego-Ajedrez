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

	void mueveficha(double, double) override;
	void set_pos_ficha(const Vector2D& pos) override;
	void dibuja_ficha() override ;
	void set_color_ficha(bool a) override;
	bool get_color() override {
		return color;
	}

	bool get_haComidoFicha() override {
		return haComidoFicha;
	}

	Vector2D get_pos() override {
		return posicion_ficha;
	}
	
	bool FichaAhogada(std::vector<Vector2D> posiciones);
	
	bool casillaValida(int i, int j, std::vector<std::vector<Fichas*>> control) override;  // Para que no se salga del tamaño de la matriz control al comprobar si es jaque o no

	std::vector<Vector2D> get_movimientos_validos(std::vector<std::vector<Fichas*>> control, Vector2D pos, Vector2D reyPos) override;

};