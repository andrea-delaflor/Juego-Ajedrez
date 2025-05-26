#include "Menu.h"
#include "ETSIDI.h"
#include <freeglut.h>
#include <iostream>



void Menu::dibuja_menu() {

	if (tipo_menu == TipoMenu::MENU_JUEGO)
	{

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/menugame.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(-14, -3, 0.005);	// izda abajo
		glTexCoord2d(1, 1); glVertex3d(14, -3, 0.005);	// dcha abajo
		glTexCoord2d(1, 0); glVertex3d(14, 18, 0.005);	// dcha arriba
		glTexCoord2d(0, 0); glVertex3d(-14, 18, 0.005);// izda arriba
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}
	if (tipo_menu == TipoMenu::MENU_PLAYER)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/menuplayer.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(-14, -3, 0.005);	// izda abajo
		glTexCoord2d(1, 1); glVertex3d(14, -3, 0.005);	// dcha abajo
		glTexCoord2d(1, 0); glVertex3d(14, 18, 0.005);	// dcha arriba
		glTexCoord2d(0, 0); glVertex3d(-14, 18, 0.005);// izda arriba
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	if (tipo_menu == TipoMenu::MENU_VICTORIA_BLANCAS)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/victoriablancas.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(4.27, 0, 0.5);	// izda abajo
		glTexCoord2d(1, 1); glVertex3d(13.78, 0, 0.5);	// dcha abajo
		glTexCoord2d(1, 0); glVertex3d(13.78, 15.10, 0.5);	// dcha arriba
		glTexCoord2d(0, 0); glVertex3d(4.27, 15.10, 0.5);// izda arriba
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	if (tipo_menu == TipoMenu::MENU_VICTORIA_NEGRAS)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/victorianegras.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(4.27, 0, 0.5);	// izda abajo
		glTexCoord2d(1, 1); glVertex3d(13.78, 0, 0.5);	// dcha abajo
		glTexCoord2d(1, 0); glVertex3d(13.78, 15.10, 0.5);	// dcha arriba
		glTexCoord2d(0, 0); glVertex3d(4.27, 15.10, 0.5);// izda arriba
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	if (tipo_menu == TipoMenu::MENU_TABLAS)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/tablas.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(4.27, 0, 0.5);	// izda abajo
		glTexCoord2d(1, 1); glVertex3d(13.78, 0, 0.5);	// dcha abajo
		glTexCoord2d(1, 0); glVertex3d(13.78, 15.10, 0.5);	// dcha arriba
		glTexCoord2d(0, 0); glVertex3d(4.27, 15.10, 0.5);// izda arriba
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	
	
	/* if (tipo_menu == TipoMenu::MENU_PAUSA)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/menupausa.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(-5, 0, 0.5);	// izda abajo
		glTexCoord2d(1, 1); glVertex3d(5, 0, 0.5);	// dcha abajo
		glTexCoord2d(1, 0); glVertex3d(5, 15.10, 0.5);	// dcha arriba
		glTexCoord2d(0, 0); glVertex3d(-5, 15.10, 0.5);// izda arriba
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	} */

}
Menu::ModoJuego Menu::getModoSeleccionado() const {
	return modo_seleccionado;
}

bool Menu::detectar_click(const Vector2D& pos) {

	if (tipo_menu == TipoMenu::MENU_JUEGO) {
		if (pos.x > -7.1 && pos.x < -2.1 && pos.y>0.8 && pos.y < 18) {
			modo_seleccionado = ModoJuego::MODO_SPEEDCHESS;
			tipo_menu = TipoMenu::MENU_JUEGO;
			ETSIDI::play("sonido/Inicio.mp3");// Enter
			return true;
		}
		if (pos.x > 2.2 && pos.x < 7.1 && pos.y>0.8 && pos.y < 18) {
			ETSIDI::play("sonido/Inicio.mp3");// Enter
			modo_seleccionado = ModoJuego::MODO_4x5;
			tipo_menu = TipoMenu::MENU_JUEGO;
			return true;
		}
	}
	if (tipo_menu == TipoMenu::MENU_PLAYER) {

		if (pos.x > -7.1 && pos.x < -2.1 && pos.y>0.8 && pos.y < 18) {
			ETSIDI::play("sonido/Inicio.mp3");// Enter
			formajuego = FormaJuego::FORMA_1V1;
			return true;
		}
		if (pos.x > 2.2 && pos.x < 7.1 && pos.y>0.8 && pos.y < 18) {
			ETSIDI::play("sonido/Inicio.mp3");// Enter
			formajuego = FormaJuego::FORMA_IA;
			return true;
		}

	}

	//PODEMOS CAMBIAR MUSICA EN FUCION DE GANA UNO U OTROS Y DARSE A ESPACIO PARA SALIR A MENU DE INICIO Y ASI

	if (tipo_menu == TipoMenu::MENU_VICTORIA_NEGRAS) {
			ETSIDI::play("sonido/Inicio.mp3");// Enter
	
			return true;
	}
	if (tipo_menu == TipoMenu::MENU_VICTORIA_BLANCAS) {
			ETSIDI::play("sonido/Inicio.mp3");// Enter

			return true;
		


	}
	if (tipo_menu == TipoMenu::MENU_TABLAS) {
			ETSIDI::play("sonido/Inicio.mp3");// Enter
			
			return true;
		
		}






	}

	return false;
}