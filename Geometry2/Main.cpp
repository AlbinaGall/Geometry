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
	cout << "����� �������: " << square.get_side() << endl;
	cout << "������� ��������: " << square.get_perimeter() << endl;
	cout << "�������� ��������: " << square.get_area() << endl;
	square.draw();
	//cin.get();

	EquilateralTriangle e3(100, Color::CONSOLE_GREEN);
	cout << "����� �������: " << e3.get_side() << endl;
	cout << "�������� ������������: " << e3.get_perimeter() << endl;
	cout << "������� ������������: " << e3.get_area() << endl;
	e3.draw();*/
	
	cout << "--------------------------------" << endl << "�������������" << endl;
	Rect rect(750,450, Color::CONSOLE_RED);
	cout << "������: " << rect.get_widght() << endl;
	cout << "�����: " << rect.get_lenght() << endl;
	cout << "������� ��������������: " << rect.get_perimeter() << endl;
	cout << "�������� ��������������: " << rect.get_area() << endl;
	rect.draw();
	
	cout << "--------------------------------" << endl << "����������" << endl;
	Circle circle(650, Color::CONSOLE_RED);
	cout << "������ ����������: " << circle.get_radius() << endl;
	cout << "����� ����������: " << circle.get_perimeter() << endl;
	cout << "������� ����������: " << circle.get_area() << endl;
	circle.draw();

	cout << "--------------------------------" << endl << "������������� �����������"<< endl;
	RightTriangle rtr(300,500, Color::CONSOLE_GREEN);
	cout << "����� �: " << rtr.get_a() << endl;
	cout << "����� b: " << rtr.get_height() << endl;
	cout << "������� ������������: " << rtr.get_area() << endl;
	cout << "�������� ������������: " << rtr.get_perimeter() << endl;
	rtr.draw();

	cout << "--------------------------------" << endl << "�������������� �����������" << endl;
	IsoscelesTriangle rbtr(100, 150, Color::CONSOLE_GREEN);
	cout << "����� �������: " << rbtr.get_side() << endl;
	cout << "����� ���������: " << rbtr.get_base() << endl;
	cout << "������: " << rbtr.get_height() << endl;
	cout << "������� ������������: " << rbtr.get_area() << endl;
	cout << "�������� ������������: " << rbtr.get_perimeter() << endl;
	rbtr.draw();
}