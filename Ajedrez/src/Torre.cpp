#include "Torre.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "Mundo.h"
#include "Fichas.h"
#include <stdio.h>

void Torre::mueveficha(double x, double y)
{
	posicion_ficha.x = x;
	posicion_ficha.y = y;
}

void Torre::set_pos_ficha(const Vector2D& pos)
{
	posicion_ficha = pos;
}

void Torre::dibuja_ficha()
{
	glPushMatrix();
	glTranslated(posicion_ficha.x, posicion_ficha.y, 0.001);
	if (color == 0) 
		sprite2.draw();
	if (color == 1)
		sprite.draw();
}

void Torre::set_color_ficha(bool a)
{
	if (a == true)
		color = true; //1
	if (a == false)
		color = false;
}

bool Torre::FichaAhogada(vector<Vector2D> posiciones)
{
	if (posiciones.size() == 0)
		return true;
	else
		return false;
}

std::vector<Vector2D> Torre::get_movimientos_validos(std::vector<std::vector<Fichas*>> control, Vector2D pos, Vector2D reyPos)
{
	return std::vector<Vector2D>();
}

bool Torre::casillaValida(int i, int j, std::vector<std::vector<Fichas*>> control)
{
	if (i >= 0 && i < control.size() && j >= 0 && j < control[0].size())
		return true;
	else
		return false;
}
