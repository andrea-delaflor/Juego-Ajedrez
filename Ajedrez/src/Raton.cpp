#include "Raton.h"
#include "freeglut.h"
#include <iostream>
#include<Menu.h>




Vector2D elige_casilla(Vector2D posicion, Menu::ModoJuego modo, bool click_izq){
    //Dimensiones en p�xeles de cada casilla del tablero.
    int casilla_w = 154;
    int casilla_h = 154;

    //Variables para almacenar el tama�o del tablero, que cambia seg�n el modo.
    int columnas = 0;
    int filas = 0;

     
    //Configura el n�mero de columnas y filas del tablero seg�n el modo de juego.Si el modo no es v�lido, devuelve un vector inv�lido.
    switch (modo) {

    case Menu::ModoJuego::MODO_SPEEDCHESS:
        columnas = 5;
        filas = 6;
        break;

    case Menu::ModoJuego::MODO_4x5:
        columnas = 4;
        filas = 5;
        break;

    default:
        return { -1, -1 }; //modo no v�lido
 
    }

    //Calcula en qu� columna y fila se hizo clic usando la posici�n del rat�n.
    int col = posicion.x / casilla_w;
    int fila = posicion.y / casilla_h;

    
    //Verifica que el clic est� dentro del tablero -> depende del modo seleccionado
    if (col < 0 || col >= columnas || fila < 0 || fila >= filas) {
        return { -1, -1 }; //fuera del tablero
    }

    //Calcula la posici�n del centro de la casilla seleccionada
    float pos_x = col * casilla_w + casilla_w / 2.0f;
    float pos_y = fila * casilla_h + casilla_h / 2.0f;

    //Dibuja un cuadrado rojo si se hizo click.
    if (click_izq) {
        float left = col * casilla_w;
        float right = left + casilla_w;
        float bottom = fila * casilla_h;
        float top = bottom + casilla_h;

        glColor3ub(220, 0, 0);      //Rojo
        glBegin(GL_LINE_LOOP);      //Borde de la casilla
        glVertex2f(left, bottom);
        glVertex2f(left, top);
        glVertex2f(right, top);
        glVertex2f(right, bottom);
        glEnd();
    }

    return { pos_x, pos_y };
}
