#pragma once
#include "Mundo.h"
#include "Vector2D.h"
#include "Tablero.h"
#include "Torre.h"
#include "Reina.h"
#include "Rey.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Peon.h"
#include "Fichas.h"
#include <vector>

void Mundo::inicializa() {
    x_ojo = 0.0;
    y_ojo = 7.5;
    z_ojo = 30.0;

    /*if (menu.modo_seleccionado == Menu::ModoJuego::MODO_SPEEDCHESS) {
        inicializa_speedchess();
    }
    else if (menu.modo_seleccionado == Menu::ModoJuego::MODO_4x5) {
        inicializa_4x5();
    }*/
}

void Mundo::inicializa_4x5() {
    columnas = 4;
    filas = 5;

    tablero.dibuja_tablero(columnas, filas);
}

void Mundo::inicializa_speedchess() {
    columnas = 5;
    filas = 6;

    tablero.dibuja_tablero(columnas, filas);

}