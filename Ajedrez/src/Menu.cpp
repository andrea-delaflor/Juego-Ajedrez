#include "Menu.h"
#include "ETSIDI.h"
#include <freeglut.h>
#include <iostream>



void Menu::dibuja_menu() {

	if (tipo_menu == TipoMenu::MENU_JUEGO)
	{

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/menu1.png").id);
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
			ETSIDI::getTexture("imagenes/menu2.png").id);
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
			ETSIDI::getTexture("imagenes/vicblancas.png").id);
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
			ETSIDI::getTexture("imagenes/vicnegras.png").id);
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