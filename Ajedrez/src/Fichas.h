#include "Vector2D.h"
#include <vector>

class Fichas {
public:

	bool color;			// FALSE es negro. TRUE es blanco
	bool haComidoFicha; //TRUE comido ficha

	Vector2D posicion_ficha{}; // comun a todas las fichas

	virtual ~Fichas() {}

	virtual void mueveficha(double x, double y) {}
	virtual void set_pos_ficha(const Vector2D& pos) {} // Se introduce la dirección en la que hay una ficha
	virtual void dibuja_ficha() {}
	virtual void set_color_ficha(bool a) {
		if (a == true)
			color = true;
		if (a == false)
			color = false;
	}
	virtual bool get_color() {
		return color;
	}
	virtual bool get_haComidoFicha() {
		return haComidoFicha;
	}
	virtual Vector2D get_pos() {
		return posicion_ficha;
	}

	//situación en la que el jugador al que le toca mover no tiene ningún movimiento legal y su rey no está en jaque
	//El jugador no está en jaque, pero no puede mover ninguna de sus piezas sin poner a su rey en jaque(lo cual no está permitido),
	//Por lo tanto, el juego termina automáticamente en tablas (empate).

	virtual bool FichaAhogada(std::vector <Vector2D> posiciones)
	{
		if (posiciones.size() == 0)
			return true;
		else
			return false;
	}

	virtual bool casillaValida(int i, int j, std::vector <Fichas*> control) //puntero para apuntar a las fichas
	{																	    // Para que no se salga del tamaño de la matriz control al comprobar si es jaque o no
		return false;
	}

	virtual std::vector<Vector2D> get_movimientos_validos(std::vector<std::vector<Fichas*>> control, Vector2D pos, Vector2D reyPos) { // 
		std::vector<Vector2D> posiciones; // se almacenan las posiciones de control de todas las piezas de color negro
		return posiciones;
	}
};
