#pragma once
#include <iostream>
#include "Tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "Color.h"
#include <stdio.h>



void Tablero::dibuja_tablero(int c,int f)
{
    for (int i = 0; i < c; i++) 
    {
        for (int j = 0; j < f; j++)
        {
            if ((i + j) % 2 != 0) // alternamos color: (i+j)%2!=0 → blanca, sino negra
                dibuja_cuadrado_blanco(i, j);// blanco
            else
                dibuja_cuadrado_negro(i, j);//negro
        }
    }
    
}

void Tablero::dibuja_cuadrado_blanco(double i, double j) {
    // Calculamos su rectángulo en coordenadas de mundo
    float x0 = coordenadas.x + i * casilla.x;
    float y0 = coordenadas.y + j * casilla.y;
    float x1 = x0 + casilla.x;
    float y1 = y0 + casilla.y;

    glEnable(GL_TEXTURE_2D); //bind de la textura blanca
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/casilla_blanca.png").id);  //La imagen suministrada en el directorio. Este es el Fondo. Dentro de la carpeta bin
    glDisable(GL_LIGHTING);


    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);  glVertex2f(x0, y0);
    glTexCoord2f(1.0f, 0.0f);  glVertex2f(x1, y0);
    glTexCoord2f(1.0f, 1.0f);  glVertex2f(x1, y1);
    glTexCoord2f(0.0f, 1.0f);  glVertex2f(x0, y1);
    glEnd();

    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}

void Tablero::dibuja_cuadrado_negro(double i, double j) {
    // Mismos cálculos de posición
    float x0 = coordenadas.x + i * casilla.x;
    float y0 = coordenadas.y + j * casilla.y;
    float x1 = x0 + casilla.x;
    float y1 = y0 + casilla.y;

    // Bind de la textura negra
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,ETSIDI::getTexture("imagenes/casilla_negra.png").id);
    glDisable(GL_LIGHTING);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);  glVertex2f(x0, y0);
    glTexCoord2f(1.0f, 0.0f);  glVertex2f(x1, y0);
    glTexCoord2f(1.0f, 1.0f);  glVertex2f(x1, y1);
    glTexCoord2f(0.0f, 1.0f);  glVertex2f(x0, y1);
    glEnd();

    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}