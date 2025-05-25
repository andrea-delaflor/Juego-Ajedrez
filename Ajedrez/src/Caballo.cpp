#include <stdio.h>
#include "freeglut.h"
#include "ETSIDI.h"
#include "Caballo.h"
#include "Mundo.h" 
#include "Fichas.h"

void Caballo::mueveficha(double x, double y)
{
    posicion_ficha.x = x;
    posicion_ficha.y = y;
}

bool Caballo::FichaAhogada(std::vector<Vector2D> posiciones)
{
    if (posiciones.size() == 0)
        return true;
    else
        return false;
}

bool Caballo::casillaValida(int i, int j, std::vector<std::vector<Fichas*>> control) {   // Para que no se salga del tamaño de la matriz control al comprobar si es jaque o no
    return i >= 0 && i < control.size() && j >= 0 && j < control[i].size();
}

std::vector<Vector2D> Caballo::get_movimientos_validos(std::vector<std::vector <Fichas*>> control, Vector2D pos, Vector2D reyPos) { // pos es la casilla que ocupa la torre en nuestra matriz de control
    haComidoFicha = false; // por defecto no come pieza. En caso de que tenga la posibilidad de hacerlo, si valor cambiará a true
    std::vector<Vector2D> posiciones; // se almacenan las posiciones de control de todas las piezas de color negro
    // MOVIMIENTOS DEL CABALLO
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if ((i == 2 && j == 1) || (i == 1 && j == 2)) { // condición para que sea un movimiento en forma de L
                if (casillaValida(pos.x + i, pos.y + j, control)) {
                    if (control[pos.x + i][pos.y + j] == nullptr) {
                        posiciones.push_back({ static_cast<double>(pos.x + i), static_cast<double>(pos.y + j) });
                    }
                    else if (control[pos.x + i][pos.y + j] != nullptr && control[pos.x + i][pos.y + j]->get_color() == true) {
                        posiciones.push_back({ static_cast<double>(pos.x + i), static_cast<double>(pos.y + j) });
                        haComidoFicha = true;
                    }
                }
                if (casillaValida(pos.x - i, pos.y + j, control)) {
                    if (control[pos.x - i][pos.y + j] == nullptr) {
                        posiciones.push_back({ static_cast<double>(pos.x - i), static_cast<double>(pos.y + j) });
                    }
                    else if (control[pos.x - i][pos.y + j] != nullptr && control[pos.x - i][pos.y + j]->get_color() == true) {
                        posiciones.push_back({ static_cast<double>(pos.x - i), static_cast<double>(pos.y + j) });
                        haComidoFicha = true;
                    }
                }
                if (casillaValida(pos.x + i, pos.y - j, control)) {
                    if (control[pos.x + i][pos.y - j] == nullptr) {
                        posiciones.push_back({ static_cast<double>(pos.x + i), static_cast<double>(pos.y - j) });
                    }
                    else if (control[pos.x + i][pos.y - j] != nullptr && control[pos.x + i][pos.y - j]->get_color() == true) {
                        posiciones.push_back({ static_cast<double>(pos.x + i), static_cast<double>(pos.y - j) });
                        haComidoFicha = true;
                    }
                }
                if (casillaValida(pos.x - i, pos.y - j, control)) {
                    if (control[pos.x - i][pos.y - j] == nullptr) {
                        posiciones.push_back({ static_cast<double>(pos.x - i), static_cast<double>(pos.y - j) });
                    }
                    else if (control[pos.x - i][pos.y - j] != nullptr && control[pos.x - i][pos.y - j]->get_color() == true) {
                        posiciones.push_back({ static_cast<double>(pos.x - i), static_cast<double>(pos.y - j) });
                        haComidoFicha = true;
                    }
                }
            }
        }
    }
    return posiciones;
}

//revisar como queremos comprobar el movimiento para relacionarlo con el movimiento de las teclas, del rato o como
/*
 //una opcion
 Fichas.h
 Vector2D posicion_ficha;
posicion_ficha.x = origen.x + casilla.x * tileSize;
posicion_ficha.y = origen.y + casilla.y * tileSize;

- tamaño fijo en píxeles, que sería el ancho de la casilla, tileSize
- El tablero empieza a dibujarse desde un origen, depende de como lo hagamos si lo queremos hacer pos casillas seria ideal

void Caballo::actualizar_posicion_grafica(int tileSize, const Vector2D& origen)
{
    posicion_ficha.x = origen.x + casilla.x * tileSize;
    posicion_ficha.y = origen.y + casilla.y * tileSize;
}*/

void Caballo::set_pos_ficha(const Vector2D& pos)
{
        posicion_ficha = pos;
}

void Caballo::dibuja_ficha()
{
    glPushMatrix();
    glTranslated(posicion_ficha.x, posicion_ficha.y, 0.001);
    if (color == 0)
        sprite2.draw();			//negras
    if (color == 1)
        sprite.draw();		// blancas
    //fin del codigo incluido
    glPopMatrix();
    glFlush();
}

void Caballo::set_color_ficha(bool a)
{
    if (a == TRUE)
        color = TRUE;
    if (a == FALSE)
        color = FALSE;
}

