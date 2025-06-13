#include "freeglut.h"
#include "ETSIDI.h"
#include <stdio.h>
#include "Rey.h"
#include "Mundo.h" 
#include "Fichas.h"

void Rey::mueveficha(double x, double y)
{
	posicion_ficha.x = x;
	posicion_ficha.y = y;
}
void Rey::set_pos_ficha(const Vector2D& pos)
{
	posicion_ficha = pos;
}

void Rey::dibuja_ficha()
{
	glPushMatrix();
	glTranslated(posicion_ficha.x, posicion_ficha.y, 0.001);
	if (color == 0)
		sprite2.draw();
	if (color == 1)
		sprite.draw();
}

void Rey::set_color_ficha(bool a)
{
	if (a == true)
		color = true; //1
	if (a == false)
		color = false;
}

bool Rey::FichaAhogada(vector<Vector2D> posiciones)
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

bool Rey::casillaValida(int i, int j, std::vector<std::vector<Fichas*>> control)
{
	if (i >= 0 && i < control.size() && j >= 0 && j < control[0].size())
		return true;
	else
		return false;
}


std::vector<Vector2D> Rey::get_movimientos_validos(std::vector<std::vector<Fichas*>> control, Vector2D pos, Vector2D reyPos)
{
	haComidoFicha = false;
	std::vector<Vector2D> posiciones;

	int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
	int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };

	// Genera todos los posibles movimientos del rey
	std::vector<Vector2D> movimientosRey = {
		{reyPos.x + 1, reyPos.y},
		{reyPos.x + 1, reyPos.y - 1},
		{reyPos.x, reyPos.y - 1},
		{reyPos.x - 1, reyPos.y - 1},
		{reyPos.x - 1, reyPos.y},
		{reyPos.x - 1, reyPos.y + 1},
		{reyPos.x, reyPos.y + 1},
		{reyPos.x + 1, reyPos.y + 1}
	};

	//movimientos legales para el rey negro. No se tiene en cuenta los jaques
	for (int i = 0; i < 8; i++) { 
		int x = static_cast<int>(pos.x) + dx[i];
		int y = static_cast<int>(pos.y) + dy[i];

		if (casillaValida(movimientosRey[i].x, movimientosRey[i].y, control)) { // se comprueba que no se salga del rango de la matriz
			if (control[movimientosRey[i].x][movimientosRey[i].y] == nullptr) { // se recorre la fila de la torre en horizontal (y = cte)
				posiciones.push_back({ static_cast<double>(movimientosRey[i].x), static_cast<double>(movimientosRey[i].y) }); // se añade al vector las posiciones donde la torre puede moverse
				//haComidoPieza = false;
			}
			else if (control[movimientosRey[i].x][movimientosRey[i].y] != nullptr && control[movimientosRey[i].x][movimientosRey[i].y]->get_color() == true) { //se comprueba que es viable la captura de la pieza
				posiciones.push_back({ static_cast<double>(movimientosRey[i].x), static_cast<double>(movimientosRey[i].y) }); // se añade al vector las posiciones donde la torre puede moverse
				haComidoFicha = true;
			}
			else if (control[movimientosRey[i].x][movimientosRey[i].y] != nullptr && control[movimientosRey[i].x][movimientosRey[i].y]->get_color() == false) { // se detecta pieza negra
				//haComidoPieza = false;
			}
		}
	}

	return posiciones;
}

/*std::vector<Vector2D> Rey::get_movimientos_validos(std::vector<std::vector<Fichas*>> control, Vector2D pos, Vector2D reyPos)
{
    std::vector<Vector2D> posiciones;

    int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
    int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };

    for (int dir = 0; dir < 8; dir++) {
        int x = static_cast<int>(pos.x) + dx[dir];
        int y = static_cast<int>(pos.y) + dy[dir];

        if (!casillaValida(x, y, control))
            continue;

        Fichas* destino = control[x][y];
        if (destino == nullptr || destino->getColor() != this->getColor()) {
            // Simula el movimiento
            auto copiaControl = control;
            copiaControl[static_cast<int>(pos.x)][static_cast<int>(pos.y)] = nullptr;
            copiaControl[x][y] = this;

            Vector2D nuevaPosRey = { static_cast<double>(x), static_cast<double>(y) };

            if (!estaEnJaque(nuevaPosRey, copiaControl, this->getColor())) {
                posiciones.push_back(nuevaPosRey);
            }
        }
    }

    return posiciones;
}*/