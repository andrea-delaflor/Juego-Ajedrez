// JuegoAjedrez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//comprobación librería freeGlut

// JuegoAjedrez.cpp
#include "Mundo.h"
#include "freeglut.h"
#include "ETSIDI.h"

// Prototipo de tu callback
void OnDraw(void);

Mundo mundo;

int main(int argc, char** argv) {
    // 1) Inicializar GLUT y crear ventana
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
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
    // (opcional si quieres animar) glutIdleFunc(OnDraw);

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

    mundo.inicializa();
    //añadir menus
    // 
    // 
   //usar mundo en funcion del menu seria
    mundo.inicializa_4x5();
    mundo.inicializa_speedchess();

    // 5) Intercambiar buffers
    glutSwapBuffers();
}
