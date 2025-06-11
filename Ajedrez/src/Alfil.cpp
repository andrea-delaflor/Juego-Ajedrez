#include "Alfil.h"
#include "freeglut.h"
#include<ETSIDI.h>
#include<stdio.h>
#include "Mundo.h"
#include "Fichas.h"//hacerla 

void Alfil::muevepieza(double x, double y)
{
	pos_pieza.x = x;
	pos_pieza.y = y;
}
bool Alfil::set_pos_pieza(const Vector2D& pos)
{

}

void Alfil::dibuja_pieza()
{
	glPushMatrix();
	glTranslated(pos_pieza.x, pos_pieza.y, 0.001);
	if (color == 0) // false 
		sprite2.draw(); //negro
	íf (color == 1) //true   // no se pq no me va 
		sprite.draw(); //blancas // no se pq no me va 
	glPopMatrix();
	glFlush();
}

void Alfil::set_color_pieza(bool a)
{
	if (a == TRUE)
		color = TRUE;
	if (a == FALSE)
		color = FALSE;
}




