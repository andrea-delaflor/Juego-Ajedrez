// JuegoAjedrez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//comprobación librería freeGlut
#include "freeglut.h"
//#include <afx.h> //para usar las MFC: CStringA, creo q ahora son las de abajo?
#define _AFXDLL
#include <afxwin.h>
#include <afxdlgs.h> 
#include <cmath>

#define PI = 3,1415926;


//YA NO HACE FALTA HEMOS CREADO LA ESTRUCTURA
/*
float radio_esfera = 2.0f;
float x_esfera = 0.0f;
unsigned char rojo_esfera = 255;
unsigned char verde_esfera = 255;
unsigned char azul_esfera = 255;
*/


struct Mundo
{
	float x_ojo;// posicion del ojo
	float y_ojo;
	float z_ojo;
	float d; //radio circunferencia
	float ang; //angulo
};

Mundo mundo = { -10,10,20, 20, 0 };

struct Esfera
{
	float radio;
	float x;
	float y;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
};

Esfera esfera = { 3,-2.5,0,0,255,255 };
Esfera esfera2 = { 1,3,0,255,0,0 };


//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void Mueve(Esfera* e); //LA USAREMOS EN LA DE ONTIMER
void Dibuja(Esfera e);//CREAMOS UNA FUNCION DND PONER TODO LO NECESARIO PARA DIBUJAR
void OnDraw(void);		 //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600); // define el tamaño de la ventanna en pixeles
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // define el modo de visualizacion (GLUT_DOUBLE: Usa doble buffer, evita parpadeos en la animación;GLUT_RGB: Usa el modelo de color RGB (rojo, verde, azul);GLUT_DEPTH: Habilita el buffer de profundidad para manejar la perspectiva correctamente)
	glutCreateWindow("MiJuego"); // crea la ventana de renderizado con ese titulo

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0); // GL_LIGHT0: Activa la fuente de luz 0.
	glEnable(GL_LIGHTING); // GL_LIGHTING: Habilita el sistema de iluminación en OpenGL.
	glEnable(GL_DEPTH_TEST); // Habilita el buffer de profundidad, lo que permite que los objetos más cercanos tapen a los más lejanos.
	glEnable(GL_COLOR_MATERIAL); //Permite que el color del material afecte cómo responde a la iluminación
	glMatrixMode(GL_PROJECTION); //Cambia a la matriz de proyección (definiendo cómo se verá la escena 3D en la pantalla 2D)
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);//Define la perspectiva de la cámara con: 40.0: Ángulo de visión vertical; 800 / 600.0f : Relación de aspecto(ancho / alto); 0.1 : Distancia mínima de visión(near); 150 : Distancia máxima de visión(far).

	//Registrar los callbacks
	glutDisplayFunc(OnDraw); // registra la función OnDraw como la encargada de dibujar la escena
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer(), Se usa para actualizar la animación en intervalos de tiempo
	glutKeyboardFunc(OnKeyboardDown); //Registra la función OnKeyboardDown() para manejar la entrada del teclado

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop(); // Inicia el bucle de eventos de GLUT, quedándose en ejecución hasta que se cierre la ventana

	return 0;
}




void Dibuja(Esfera e)
{
	glColor3ub(e.rojo, e.verde, e.azul);
	glTranslatef(e.x, e.y, 0);
	glutSolidSphere(e.radio, 20, 20);
	glTranslatef(-e.x, -e.y, 0);

}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW); // Cambia a la matriz de modelo-vista para dibujar objetos en la escena
	glLoadIdentity(); //  restablece la matriz a su estado inicial.





	//DEFINICION DEL PUNTO DE VISTA
	mundo.x_ojo = mundo.d * cos(mundo.ang);
	mundo.z_ojo = mundo.d * sin(mundo.ang);
	gluLookAt(mundo.x_ojo, mundo.y_ojo, mundo.z_ojo,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  



	//aqui es donde hay que poner el código de dibujo

	//EN VEZ DE PONER TODO ESTO LLAMAMAMOS A LA FUNCION DIBUJA ESFERA Q CONTINE TODOS LOS PARAMETROS
	/*
	glColor3ub(esfera.rojo, esfera.verde, esfera.azul);//COLOR

	glTranslatef(esfera.x, esfera.y, 0);
	glutSolidSphere(esfera.radio, 20, 20);
	glTranslatef(-esfera.x, -esfera.y, 0);
	*/

	Dibuja(esfera);
	Dibuja(esfera2);

	//TODO ESTO SON OTRAS FIGURAS, POSICIONES, COLORES...
	/*
	glutSolidSphere(2, 100, 100);

	glTranslatef(3, 0, 0);//DONDE DIBIJAMOS EN EL PLANO
	glutSolidTeapot(1);//TETERA
	glutWireSphere(2, 10, 10);//ESFERA DE ALAMBRE
	glTranslatef(-3, 0, 0);//ELEGIMOS OTRA POSICION
	glutSolidTeapot(1);//TETERA
	*/

	//DIBUJAMOS UN CUADRADO CON DIFUMINACION DE COLOR ejrcicio propuestp

	glBegin(GL_POLYGON); //comienza la definicion de un poligono
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0f, 0.0f, -5.0f);
	glColor3ub(255, 255, 0);
	glVertex3f(-5.0f, 0.0f, 5.0f);
	glColor3ub(255, 255, 255);
	glVertex3f(5.0f, 0.0f, 5.0f);
	glColor3ub(0, 255, 255);
	glVertex3f(5.0f, 0.0f, -5.0f);
	glEnd(); //finaliza la definicion del poligono

	glColor3ub(0, 255, 0);
	glutSolidTorus(1, 6, 20, 20);



	//ES OTRO CUADRADO PERO HEMOS CAMBIADO LA PERSPECTIVA
	/*
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glVertex3f(-5.0f, 0, -5.0f);
	glVertex3f(-5.0f, 0, 5.0f);
	glVertex3f(5.0f, 0, 5.0f);
	glVertex3f(5.0f, 0, -5.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	*/


	//Al final, cambiar el buffer (redibujar)
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers(); /*
						Intercambia los buffers de dibujo en doble buffer.
						Recuerda que en GLUT_DOUBLE (doble buffer), tenemos:
						Un buffer frontal (lo que se muestra en pantalla).
						Un buffer trasero (donde se dibuja en segundo plano).
						Evita parpadeos porque el dibujo completo se muestra de golpe.
						Después de dibujar algo en el buffer trasero, se usa esta función para intercambiarlo con el frontal y actualizar la imagen.
						*/
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{

	//poner aqui el código de teclado
	if (key == '+' && esfera.radio < 3)
		esfera2.radio += 0.5f;
	if (key == '-' && esfera.radio > 1)
		esfera.radio -= 0.5f;
	if (key == 'r')
	{
		esfera.rojo = 255;
		esfera2.verde = 0;
		esfera2.azul = 0;
	}
	if (key == 'a')
		esfera2.x -= 0.1f;
	if (key == 'd')
		esfera2.x += 0.1f;
	if (key == 's')
		esfera2.y -= 0.1f;
	if (key == 'w')
		esfera2.y += 0.1f;

}

void OnTimer(int value)
{
	//poner aqui el código de animacion
	//Mueve(&esfera);
	Mueve(&esfera2);

	mundo.ang += 0.1f;
	if (mundo.ang > 360) //si la camara ha lleagado a dar una vuleta entera le restamos la vuelta y empieza en 0 otra vez no?
		mundo.ang -= 360;

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0); //Programa la función OnTimer() para que se ejecute en 25 ms. Es la misma que en la main pero esto sirve para crear un loop infinito
	glutPostRedisplay(); //Marca la ventana como "necesita ser redibujada".
	//No la redibuja inmediatamente, sino que avisa a GLUT para que llame a glutDisplayFunc(OnDraw) en el siguiente ciclo del bucle.

}


void Mueve(Esfera* e)
{
	e->radio += 0.1f;
	if (e->radio > 3)
		e->radio = 0.5f;
}
