#pragma once
#include "Vector2D.h"


struct CASILLA
{   
    // Parámetros gráficos de casilla 
    int vx;
    int vy;
    int colR, colG, colB;
};

class Tablero
{
private:

    int Tipo_juego, Tipo_oponente; // Tipo de juego al que vamos a jugar y tipo de oponente (jugador o maquina) que vamos a enfrentar

    CASILLA Mcasillas[5][4];  // Para parte GRÁFICA -> Indica posición filasxcolumnas
    Vector2D PosEnCasillas[5][4];  // Para parte GRÁFICA -> Indica posición del centro de las casilas
    // i = FILAS , j = COLUMNAS         [filas][columnas] 
public:
    void inicializa(const int& TJ); //Aqui inicializamos el tipo de juego (4×5 con un único peón o Speed Chess )
    void dibuja();

};
      