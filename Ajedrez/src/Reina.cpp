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
   

    /*
	Los movimientos de la reina
	.
	.
	.
	.
	.
	*/
	
   
    return posiciones;
}

bool Reina::casillaValida(int i, int j, std::vector<std::vector<Fichas*>> control)
{
	if (i >= 0 && i < control.size() && j >= 0 && j < control[0].size())
		return true;
	else 
		return false;
	
}
