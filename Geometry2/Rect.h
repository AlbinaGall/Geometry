#pragma once
#include "Shape.h"

class Rect : public Shape {
	double widght;
	double lenght;
public:
	double get_widght()const {
		return this->widght;
	}
	double get_lenght()const {
		return this->lenght;
	}
	void set_widght(double widght) {
		if (widght <= 0) widght = 1;
		this->widght = widght;
	}
	void set_lenght(double lenght) {
		if (lenght <= 0) lenght = 1;
		this->lenght = lenght;
	}
	Rect(double widght, double lenght, Color color) :Shape(color) {
		set_widght(widght);
		set_lenght(lenght);
	}

	~Rect() {}

	double get_area()const {
		return widght * lenght;
	}
	double get_perimeter()const {
		return (lenght + widght) * 2;
	}
	void draw()const {
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);
		HPEN hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
		HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));

		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);


		Rectangle(hdc, 100, 100, widght, lenght);

		DeleteObject(hBrush);
		DeleteObject(hPen);
		ReleaseDC(hwnd, hdc);
	}
};
