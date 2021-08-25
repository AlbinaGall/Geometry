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
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Получаем обработчик окна консоли для обращения к окну консоли
		SetConsoleTextAttribute(hConsole, get_color());//задаем цвет текста в выбранном окне консоли
		for (int i = 0; i < side; i++) {
			for (int j = 0; j < side; j++) {
				cout << "* ";
			}
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT);//возвращаем исходный цвет
#endif //SIMPLE_DRAW
		//1.получаем обработчик окна (handler to window)
		HWND hwnd = GetConsoleWindow();
		//2. получаем контекст окна
		HDC hdc = GetDC(hwnd);
		//3. создаем карандаш и кисть, котрыми булем рисовать
		HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0)); //PS_SOLID-сплошная линия, 5- толщина линии в пикселях
		//pen - рисует контур фигуры
		HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
		//4. выбрать созданные карандаш и кисть
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		//5.рисуем квадрат
		Rectangle(hdc, 100, 100, 100 + side, 100 + side);


		//освобождаем ресурсы
		DeleteObject(hBrush);
		DeleteObject(hPen);
		ReleaseDC(hwnd, hdc);


	}


};

