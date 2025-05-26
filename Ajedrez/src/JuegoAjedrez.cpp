// JuegoAjedrez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//comprobación librería freeGlut

// JuegoAjedrez.cpp
#include<stdio.h>
#include "Mundo.h"
#include "Raton.h"
#include "Menu.h"
#include "freeglut.h"
#include "ETSIDI.h"

//Variable global para manejar click raton
bool click_izq = false;


// Prototipo de tu callback
void OnDraw(void);
void mouseCallback(int button, int state, int x, int y);
void display();

Mundo mundo;
Raton raton;

int main(int argc, char** argv) {
    // 1) Inicializar GLUT y crear ventana
    //glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
   // glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("MiJuego");

    // 2) Habilitar test de profundidad y luces
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    // 3) Definir perspectiva (matriz de proyección)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
        40.0,            // FOV vertical en grados
        800.0f / 600.0f,   // aspect ratio
        0.1,             // near
        150.0            // far
    );

    // 4) Registrar callback de dibujo
    glutDisplayFunc(OnDraw);
    glutMouseFunc(mouseCallback);
    // glutTimerFunc(25, OnTimer, 0);

    //
    mundo.inicializa();
    // 5) Entrar en el bucle principal
    glutMainLoop();
    return 0;
}

void OnDraw(void) {
    // 1) Limpiar buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 2) Preparar modelo/vista
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // 3) Alejar la cámara para ver el tablero en Z=0
    glTranslatef(0.0f, 0.0f, -30.0f);

   
    //añadir menus
    // 
    // 
   //usar mundo en funcion del menu seria
    mundo.inicializa_4x5();
    mundo.inicializa_speedchess();

    // 5) Intercambiar buffers
    glutSwapBuffers();
}

// Función para manejar clics de ratón
void mouseCallback(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        click_izq = true;

        //Convertir las coordenadas del mouse de pantalla a coordenadas del tablero
        //Necesitas adaptar esta parte según tu sistema de coordenadas (OpenGL suele tener origen abajo izquierda)
        Vector2D posicion_mouse{ static_cast<float>(x), static_cast<float>(y) };

        //Asumamos que tienes un modo de juego activo
        Menu::ModoJuego modo_actual = mundo.getModoJuego(); // elegir modo de juego para poder calcular tb psocion depedneiendo del tablero

        //Obtener el centro de la casilla clicada usando tu función
        Vector2D pos_casilla_centro = raton.elige_casilla(posicion_mouse, modo_actual);
      

        //Guardar posiciones previas para manejo de movimientos
        mundo.posicion_central_click_anterior = mundo.posicion_central_click;
        mundo.posicion_central_click = pos_casilla_centro;

        // Calcular la casilla lógica (fila, columna) basándonos en el centro devuelto
        // como en el código de elige_casilla
        int casilla_col = static_cast<int>(posicion_mouse.x) / ancho_casilla;
        int casilla_fila = static_cast<int>(posicion_mouse.y) / alto_casilla;

        // Guardar casilla anterior y actual
        mundo.casilla_anterior = mundo.casilla_actual;
        mundo.casilla_actual = Vector2D{ static_cast<float>(casilla_col), static_cast<float>(casilla_fila) };

        // Actualizar el objeto raton si lo tienes
        raton.posicion = posicion_mouse;
        raton.casilla = mundo.casilla_actual;
        raton.casilla_anterior = mundo.casilla_anterior;
        mundo.posicion_central_click = pos_casilla_centro;

        // Ahora puedes llamar a funciones para mover piezas o manejar estados
        mundo.set_casilla_actual(mundo.casilla_actual);
        mundo.set_casilla_anterior(mundo.casilla_anterior);

        
        mundo.mueve_piezas();
        

        // Finalmente pedir redibujar la ventana
        glutPostRedisplay();
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        click_izq = false;
    }
       
}

void display() {
    // Función de visualización
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}