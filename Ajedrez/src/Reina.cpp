#include "Reina.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "Mundo.h"
#include "Fichas.h"
#include <stdio.h>



void Reina::mueveficha(double x, double y)
{
	posicion_ficha.x = x;
	posicion_ficha.y = y;
}

void Reina::set_pos_ficha(const Vector2D& pos)
{
	posicion_ficha = pos;
}

void Reina::dibuja_ficha()
{
	glPushMatrix();
	glTranslated(posicion_ficha.x, posicion_ficha.y, 0.001);
	if (color == 0)              //si la ficha es blanca o negra
		sprite2.draw();
	if (color == 1)
		sprite.draw();

	glPopMatrix();
	glFlush();
}

void Reina::set_color_ficha(bool a)
{

	if (a == true)
		color = true;
	if (a == false)
		color = false;

}

bool Reina::FichaAhogada(vector<Vector2D> posiciones)
{
	if (posiciones.size() == 0)
		return true;
	else
		return false;
}

std::vector<Vector2D> Reina::get_movimientos_validos(std::vector<std::vector<Fichas*>> control, Vector2D pos, Vector2D reyPos)
{
    haComidoFicha = false;
    std::vector<Vector2D> posiciones;

    // Movimientos en 8 direcciones: (dx, dy)
    int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };            //(1,0) == derecha, (-1,0) == izquierda, (0,1) == abajo , (0, -1) == arriba, (1,1) == diagonal abajo derecha......
    int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };

    // Recorremos cada dirección
    for (int dir = 0; dir < 8; dir++) {   // la reina tiene 8 movimientos posibles asi q dir = 8
        int x = static_cast<int>(pos.x);
        int y = static_cast<int>(pos.y);

        while (true) {    //haComidoFicha sigue en False......es decir se mueve hasta topar con otra ficha
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
                // Si hay una ficha 
                posiciones.push_back({ static_cast<double>(x), static_cast<double>(y) });
                haComidoFicha = true; //se deja de mover
                
                break;
            }
        }
    }

    return posiciones;
}

bool Reina::casillaValida(int i, int j, std::vector<std::vector<Fichas*>> control)
{
	if (i >= 0 && i < control.size() && j >= 0 && j < control[0].size())
		return true;
	else 
		return false;
	
}
