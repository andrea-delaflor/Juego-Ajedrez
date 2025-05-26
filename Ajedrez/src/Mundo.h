#pragma once
#include "Menu.h"
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

class Mundo
{
	Tablero tablero;
	Torre torreB1, torreB2, torreN1, torreN2; //se quitara el error cuando se haga la clase
	Reina reinaB, reinaN;
	Rey reyB, reyN;
	Peon peonB1, peonB2, peonB3, peonB4, peonB5, peonN1, peonN2, peonN3, peonN4, peonN5;
	Caballo caballoB, caballoN;
	Alfil alfilB, alfilN;



public:

	Vector2D casilla_actual;
	Vector2D casilla_anterior;

	Vector2D posicion_anterior;
	Vector2D posicion_actual;

	Vector2D posicion_central_click;
	Vector2D posicion_central_click_anterior;


	double x_ojo{}, y_ojo{}, z_ojo{};
	int columnas;
	int filas;

	bool movida = false; //será true cuando se haya movido una pieza

	Menu menu;  // Instancia del menú
	void set_tipo_menu(Menu::TipoMenu tipo);
	void set_modo_juego(Menu::ModoJuego modo);
	void set_forma_juego(Menu::FormaJuego forma);

	void dibuja();

	void inicializa();
	void inicializa_speedchess();
	void inicializa_4x5();

	void mueve_piezas();

	void set_posicion_central_click(Vector2D& posicion_central_click);	// De esta manera no es necesario introducir como entrada este valor para los metodos "mueve_pieza()" y "dibuja()"
	void set_posicion_central_click_anterior(Vector2D& posicion_central);
	void set_casilla_actual(Vector2D& casilla_actual);	// De esta manera no es necesario introducir como entrada este valor para los metodos "mueve_pieza()" y "dibuja()"
	void set_casilla_anterior(Vector2D& casilla_anterior);

	Menu::ModoJuego getModoJuego() const {
		return menu.getModoSeleccionado();  // Aquí llamas a la función que ya tienes
	}

};