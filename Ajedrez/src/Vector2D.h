#pragma once
#include<cmath>

//Utilizadades de la clase Vector 2D en nuestro ajedrez
//1.Representar la posición de las piezas en el tablero mediante un par de números reales (x, y).
//2.Facilitar los cálculos relacionados con el movimiento de las piezas, por ejemplo :
//2.1.Distancia entre dos posiciones(usando modulo()).
//2.2.Dirección de un movimiento(usando unitario()).
//2.3.Verificar movimientos legales o trayectorias(con suma, resta, y producto escalar)


struct Vector2D
{
	double x{};
	double y{};
	double modulo() const;						 //modulo del vector
	double argumento() const;					 //argumento del vector
	Vector2D unitario() const;					 //devuelve un vector unitario
	Vector2D operator - (const Vector2D&) const; //resta de vectores
	Vector2D operator + (const Vector2D&) const; //suma de vectores
	double operator *(const Vector2D&) const;    // producto escalar
	Vector2D operator *(double) const;           // producto por un escalar
};

inline double Vector2D::modulo() const
{
	return sqrt(x * x + y * y);
}

inline double Vector2D::argumento() const
{
	return atan2(y, x);
}

inline Vector2D Vector2D::unitario() const
{
	auto mod = modulo();
	if (mod > 0.00001) return { x / mod, y / mod };
	return { x,y };
}

inline Vector2D Vector2D::operator - (const Vector2D& v) const
{
	return { x - v.x , y - v.y };
}
inline Vector2D Vector2D::operator + (const Vector2D& v) const
{
	return { x + v.x , y + v.y };
}

inline double Vector2D::operator *(const Vector2D& v) const
{
	return{ x * v.x + y * v.y };
}

inline Vector2D Vector2D::operator *(double n) const
{
	return{ x * n, y * n };
}

inline Vector2D operator * (double f, const Vector2D& v) {
	return { v.x * f, v.y * f };
}

