// JuegoAjedrez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//comprobación librería freeGlut

#include "Tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"

Tablero tablero;

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Dibuja un 4×5 en pantalla
	tablero.dibuja_tablero(4, 5);
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
	glutDisplayFunc(display);

	glutIdleFunc(display);

	glutMainLoop();
    return 0;
}




