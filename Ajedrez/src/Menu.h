#pragma once
#include "Vector2D.h"


class Menu {
public:
    enum class ModoJuego {
        MODO_SPEEDCHESS,
        MODO_4x5
    };
    enum class FormaJuego {
        FORMA_1V1,
        FORMA_IA
    };
    enum class TipoMenu {
        MENU_JUEGO,
        MENU_PLAYER,
        MENU_VICTORIA_BLANCAS,
        MENU_VICTORIA_NEGRAS,
        MENU_TABLAS,
    //    MENU_PAUSA
    };

    ModoJuego modo_seleccionado;
    TipoMenu tipo_menu;
    FormaJuego formajuego;

 //   ModoVictoria funcion_victoria;
 //   ModoPausa funcion_pausa;



    Menu();//constructor por defecto
    void dibuja_menu();

    bool detectar_click(const Vector2D& pos);
    
    ModoJuego getModoSeleccionado() const;



};