#include "Torre.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "Mundo.h"
#include "Fichas.h"
#include <stdio.h>

void Torre::mueveficha(double, double)
{

}

void Torre::set_pos_ficha(const Vector2D& pos)
{

}

void Torre::dibuja_ficha()
{

}

void Torre::set_color_ficha(bool a)
{

}

bool Torre::FichaAhogada(vector<Vector2D> posiciones)
{
	return false;
}

std::vector<Vector2D> Torre::get_movimientos_validos(std::vector<std::vector<Fichas*>> control, Vector2D pos, Vector2D reyPos)
{
	return std::vector<Vector2D>();
}

bool Torre::casillaValida(int i, int j, std::vector<std::vector<Fichas*>> control)
{
	return false;
}
