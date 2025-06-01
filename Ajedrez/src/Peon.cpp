#include <stdio.h>
#include "freeglut.h"
#include "ETSIDI.h"
#include "Peon.h"
#include "Mundo.h" 
#include "Fichas.h"

void Peon::mueveficha(double x, double y)
{
	posicion_ficha.x = x;
	posicion_ficha.y = y;
}

bool Peon::FichaAhogada(std::vector<Vector2D> posiciones)
{
    if (posiciones.size() == 0)
        return true;
    else
        return false;
}

bool Peon::casillaValida(int i, int j, std::vector<std::vector<Fichas*>> control) {  
    return i >= 0 && i < control.size() && j >= 0 && j < control[i].size();
}

void Peon::set_pos_ficha(const Vector2D& pos)
{
    posicion_ficha = pos;
}

void Peon::dibuja_ficha()
{
	glPushMatrix();
	glTranslated(posicion_ficha.x, posicion_ficha.y, 0.001);
	if (color == 0)
		sprite2.draw();			//negras
	if (color == 1)
		sprite.draw();		// blancas

	glPopMatrix();
	glFlush();
}

void Peon::set_color_ficha(bool a)
{

	if (a == true)
		color = true;
	if (a == false)
		color = false;

}

//peon puede realizar tres movieminetos, hacia delante, diagonales para comerse ficha
std::vector<Vector2D> Peon::get_movimientos_validos(std::vector<std::vector <Fichas*>> control, Vector2D pos, Vector2D reyPos) { // pos es la casilla que ocupa la torre en nuestra matriz de control
	haComidoFicha = false; // por defecto no come pieza. En caso de que tenga la posibilidad de hacerlo, si valor cambiará a true
	std::vector<Vector2D> posiciones; // se almacenan las posiciones de control de todas las piezas de color negro
	// MOVIMIENTOS DEL PEON
	if (casillaValida(pos.x, pos.y - 1, control)) { // se comprueba que no se salga del rango de la matriz
		if (control[pos.x][pos.y - 1] == nullptr) {
			posiciones.push_back({ static_cast<double>(pos.x), static_cast<double>(pos.y - 1) }); // se añade al vector las posiciones donde el peon puede moverse, hacia delante
			//haComidoFicha = false;
		}
	}
	if (casillaValida(pos.x + 1, pos.y - 1, control)) { // se comprueba que no se salga del rango de la matriz
		if (control[pos.x + 1][pos.y - 1] != nullptr && control[pos.x + 1][pos.y - 1]->get_color() == true) { //come hacia diagonal derecha una pieza blanca
			posiciones.push_back({ static_cast<double>(pos.x + 1), static_cast<double>(pos.y - 1) }); // se añade al vector las posiciones donde la torre puede moverse
			haComidoFicha = true;
		}
	}

	if (casillaValida(pos.x - 1, pos.y - 1, control)) { // se comprueba que no se salga del rango de la matriz
		if (control[pos.x - 1][pos.y - 1] != nullptr && control[pos.x - 1][pos.y - 1]->get_color() == true) { //come hacia diagonal izda una pieza blanca
			posiciones.push_back({ static_cast<double>(pos.x - 1), static_cast<double>(pos.y - 1) }); // se añade al vector las posiciones donde la torre puede moverse
			haComidoFicha = true;
		}
	}

	return posiciones;
}

