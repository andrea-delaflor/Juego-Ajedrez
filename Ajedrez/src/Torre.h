#pragma once
#include "ETSIDI.h"
#include "Fichas.h"
#include <vector>
#include "Vector2D.h"


using std::vector;



class Torre:public Fichas
{
	bool color; //al usar bool se devuelve un valor booleano, es decir, true o false
	bool haComidoFicha;

	ETSIDI::SpriteSequence sprite{ "imagenes/TORRE BLANCA.png", 1 };
	ETSIDI::SpriteSequence sprite2{ "imagenes/TORRE NEGRA.png", 1 };

public:
	Torre() 
	{
		sprite.setCenter(+0.75, +0.75);
		sprite.setSize(1.5, 1.5);
		sprite2.setCenter(+0.75, +0.75);
		sprite2.setSize(1.5, 1.5);
		color = true; // Blanco predeterminado
	}

	void mueveficha(double, double) override;
	void set_pos_ficha(const Vector2D& pos) override;
	void dibuja_ficha() override;
	void set_color_ficha(bool a) override;    //recuerda TRUE= blanco......FALSE=negro
	bool get_color() override { return color; }
	bool get_haComidoFicha() override { return haComidoFicha; }
	Vector2D get_pos() override { return posicion_ficha; }

	bool FichaAhogada(vector<Vector2D> posiciones);
	std::vector<Vector2D> get_movimientos_validos(std::vector<std::vector<Fichas*>> control, Vector2D pos, Vector2D reyPos) override;

	bool casillaValida(int i, int j, std::vector<std::vector<Fichas*>> control) override;
};






