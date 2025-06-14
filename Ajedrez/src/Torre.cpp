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
    haComidoFicha = false;
    std::vector<Vector2D> posiciones;

    // Movimientos en 4 direcciones: (dx, dy)
    int dx[] = { 1, -1, 0, 0 };  // derecha, izquierda
    int dy[] = { 0, 0, 1, -1 };  // abajo, arriba

    for (int dir = 0; dir < 4; dir++) { // La torre solo tiene 4 direcciones
        int x = static_cast<int>(pos.x);
        int y = static_cast<int>(pos.y);

        while (true) {
            x += dx[dir];
            y += dy[dir];

            // Comprobamos que la casilla esté dentro del tablero
            if (!casillaValida(x, y, control))
                break;

            // Si la casilla está vacía, la añadimos como válida
            if (control[x][y] == nullptr) {
                posiciones.push_back({ static_cast<double>(x), static_cast<double>(y) });
            }
            else {
                // Si hay una ficha (incluso de su propio equipo, según tu lógica puede comérsela)
                posiciones.push_back({ static_cast<double>(x), static_cast<double>(y) });
                haComidoFicha = true;  // Detenemos la exploración en esta dirección
                break;
            }
        }
    }

    return posiciones;
}


bool Torre::casillaValida(int i, int j, std::vector<std::vector<Fichas*>> control)
{
	if (i >= 0 && i < control.size() && j >= 0 && j < control[0].size())
		return true;
	else
		return false;
}
