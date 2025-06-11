#include "Alfil.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "Mundo.h"
#include "Fichas.h"
#include <stdio.h>

void Alfil::mueveficha(double x, double y)
{
	posicion_ficha.x = x;
	posicion_ficha.y = y;
}

void Alfil::set_pos_ficha(const Vector2D& pos)
{
	posicion_ficha = pos;
}

void Alfil::dibuja_ficha()
{
	glPushMatrix();
	glTranslated(posicion_ficha.x, posicion_ficha.y, 0.001);
	if (color == 0)              // si la ficha es negra
		sprite2.draw();
	if (color == 1)              // si la ficha es blanca
		sprite.draw();

	glPopMatrix();
	glFlush();
}

void Alfil::set_color_ficha(bool a)
{
	color = a;
}

bool Alfil::FichaAhogada(vector<Vector2D> posiciones)
{
	return posiciones.empty();
}

std::vector<Vector2D> Alfil::get_movimientos_validos(std::vector<std::vector<Fichas*>> control, Vector2D pos, Vector2D reyPos)
{
	haComidoFicha = false;
	std::vector<Vector2D> posiciones;

	// Solo movimientos diagonales
	int dx[] = { 1, 1, -1, -1 };
	int dy[] = { 1, -1, 1, -1 };

	for (int dir = 0; dir < 4; dir++) {
		int x = static_cast<int>(pos.x);
		int y = static_cast<int>(pos.y);

		while (true) {
			x += dx[dir];
			y += dy[dir];

			if (!casillaValida(x, y, control))
				break;

			if (control[x][y] == nullptr) {
				posiciones.push_back({ static_cast<double>(x), static_cast<double>(y) });
			}
			else {
				if (control[x][y]->get_color() != color) {
					posiciones.push_back({ static_cast<double>(x), static_cast<double>(y) });
					haComidoFicha = true;
				}
				break;
			}
		}
	}

	return posiciones;
}

bool Alfil::casillaValida(int i, int j, std::vector<std::vector<Fichas*>> control)
{
	if (i >= 0 && i < control.size() && j >= 0 && j < control[0].size())
		return true;
	else
		return false;
}




