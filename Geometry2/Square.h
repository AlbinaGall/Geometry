#pragma once
#include "Shape.h"

class Square :public Shape {
	double side;
public:
	double get_side()const {
		return this->side;
	}
	void set_side(double side) {
		if (side <= 0)side = 1;
		this->side = side;
	}
	Square(double side, Color color) :Shape(color) {
		set_side(side);
	}

	~Square() {}

	double get_area()const {
		return side * side;
	}
	double get_perimeter()const {
		return side * 4;
	}
	void draw()const {
		//#define SIMPLE_DRAW		
#ifdef SIMPLE_DRAW
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//�������� ���������� ���� ������� ��� ��������� � ���� �������
		SetConsoleTextAttribute(hConsole, get_color());//������ ���� ������ � ��������� ���� �������
		for (int i = 0; i < side; i++) {
			for (int j = 0; j < side; j++) {
				cout << "* ";
			}
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT);//���������� �������� ����
#endif //SIMPLE_DRAW
		//1.�������� ���������� ���� (handler to window)
		HWND hwnd = GetConsoleWindow();
		//2. �������� �������� ����
		HDC hdc = GetDC(hwnd);
		//3. ������� �������� � �����, ������� ����� ��������
		HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0)); //PS_SOLID-�������� �����, 5- ������� ����� � ��������
		//pen - ������ ������ ������
		HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
		//4. ������� ��������� �������� � �����
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		//5.������ �������
		Rectangle(hdc, 100, 100, 100 + side, 100 + side);


		//����������� �������
		DeleteObject(hBrush);
		DeleteObject(hPen);
		ReleaseDC(hwnd, hdc);


	}


};

