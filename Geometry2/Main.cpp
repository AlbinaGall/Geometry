#include <iostream>
#include "Shape.h"
#include "Square.h"
#include "Rect.h"
#include "Circle.h"
#include "Triangle.h"
#include "EquilateralTriangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"


void main() {
	setlocale(LC_ALL, "Russian");
	//Shape shape(Color::CONSOLE_BLUE);
	//cout << hex << shape.get_color() << endl;

	/*Square square(250, Color::CONSOLE_GREEN);
	cout << "Длина стороны: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_perimeter() << endl;
	cout << "Периметр квадрата: " << square.get_area() << endl;
	square.draw();
	//cin.get();

	EquilateralTriangle e3(100, Color::CONSOLE_GREEN);
	cout << "Длина стороны: " << e3.get_side() << endl;
	cout << "Периметр треугольника: " << e3.get_perimeter() << endl;
	cout << "Площадь треугольника: " << e3.get_area() << endl;
	e3.draw();*/
	
	cout << "--------------------------------" << endl << "Прямоугольник" << endl;
	Rect rect(750,450, Color::CONSOLE_RED);
	cout << "Ширина: " << rect.get_widght() << endl;
	cout << "Длина: " << rect.get_lenght() << endl;
	cout << "Площадь прямоугольника: " << rect.get_perimeter() << endl;
	cout << "Периметр прямоугольника: " << rect.get_area() << endl;
	rect.draw();
	
	cout << "--------------------------------" << endl << "Окружность" << endl;
	Circle circle(650, Color::CONSOLE_RED);
	cout << "Радиус окружности: " << circle.get_radius() << endl;
	cout << "Длина окружности: " << circle.get_perimeter() << endl;
	cout << "Площадь окружности: " << circle.get_area() << endl;
	circle.draw();

	cout << "--------------------------------" << endl << "Прямоугольный треугольник"<< endl;
	RightTriangle rtr(300,500, Color::CONSOLE_GREEN);
	cout << "Катет а: " << rtr.get_a() << endl;
	cout << "Катет b: " << rtr.get_height() << endl;
	cout << "Площадь треугольника: " << rtr.get_area() << endl;
	cout << "Периметр треугольника: " << rtr.get_perimeter() << endl;
	rtr.draw();

	cout << "--------------------------------" << endl << "Равнобедренный треугольник" << endl;
	IsoscelesTriangle rbtr(100, 150, Color::CONSOLE_GREEN);
	cout << "Длина стороны: " << rbtr.get_side() << endl;
	cout << "Длина основания: " << rbtr.get_base() << endl;
	cout << "Высота: " << rbtr.get_height() << endl;
	cout << "Площадь треугольника: " << rbtr.get_area() << endl;
	cout << "Периметр треугольника: " << rbtr.get_perimeter() << endl;
	rbtr.draw();
}