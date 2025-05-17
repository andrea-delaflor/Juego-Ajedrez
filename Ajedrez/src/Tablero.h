#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include <vector>



class Tablero
{
public:
    Vector2D coordenadas{};
    Vector2D casilla;
    ETSIDI::SpriteSequence fondo1{ "imagenes/4x5.png",1 };
public:
    Tablero() {
        fondo1.setCenter(0, 0);
        fondo1.setSize(10, 10);
    }
    void dibuja_tablero(int c, int f);
    void dibuja_cuadrado_blanco(double i, double j);
    void dibuja_cuadrado_negro(double i, double j);
};
      