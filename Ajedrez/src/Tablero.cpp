#pragma once
#include <iostream>
#include "Tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "Color.h"



void Tablero::dibuja()
{

    //CASILLAS 

    //FONDO 
}

void Tablero::inicializa(const int& TJ)
{
    Tipo_juego = TJ;
    // Inicializar matriz lógica 4×5
    matriz.assign(4, std::vector<int>(5, 0));
}