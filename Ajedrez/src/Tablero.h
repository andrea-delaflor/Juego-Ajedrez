#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include <vector>



class Tablero
{
public:
    Vector2D coordenadas{ -10.0, -7.5 };// origen en el que empezar a dibujar (esquina inferior izquiera del tablero
    Vector2D casilla{ 5.0, 3.0 };// tamaño de cada casilla(ancho ,alto) //154 x 154 pixeles
   // ETSIDI::SpriteSequence fondo1{ "imagenes/4x5.png",1 };
public:
    Tablero() {
        
    }
    void dibuja_tablero(int c, int f);
    void dibuja_cuadrado_blanco(double i, double j);
    void dibuja_cuadrado_negro(double i, double j);
};
      