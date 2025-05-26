#pragma once
#include"Menu.h"
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

void Mundo::set_tipo_menu(Menu::TipoMenu tipo) {
    menu.tipo_menu = tipo;
}
void Mundo::set_modo_juego(Menu::ModoJuego modo) {
    menu.modo_seleccionado = modo;
}
void Mundo::set_forma_juego(Menu::FormaJuego forma) {
    menu.formajuego = forma;
}


void Mundo::set_posicion_central_click(Vector2D& posicion_central) {
    posicion_central_click = posicion_central;
    // Aquí no detectamos clics en el menú si no estamos en el estado de menú principal
}

void Mundo::set_posicion_central_click_anterior(Vector2D& posicion_central)
{
    posicion_central_click_anterior = posicion_central; //centro de la casilla a la que se hace click

}
void Mundo::set_casilla_actual(Vector2D& casilla_act)
{
    casilla_actual = casilla_act;
}
void Mundo::set_casilla_anterior(Vector2D& casilla_ant)
{
    casilla_anterior = casilla_ant;
}
