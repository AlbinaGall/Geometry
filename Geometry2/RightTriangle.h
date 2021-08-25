#pragma once
#include "Shape.h"
#include "Triangle.h"

class RightTriangle : public Triangle {
	double a;
	double b;
public:
	double get_a() const { return a; }
	double get_height() const { return b; }
	double set_a(double a) {
		if (a <= 0) a = 1;
		this->a = a;
		return this->a;
	}
	double set_height(double b) {
		if (b <= 0) b = 1;
		this->b = b;
		return this->b;
	}
	RightTriangle(double a, double b, Color color) : Triangle(color) {
		set_a(a);
		set_height(b);
	}
	~RightTriangle() {}

	double get_hypotenuse()const {
		return sqrt(a * a + b * b);
	}

	double get_area()const {
		return a * b / 2;
	}

	double get_perimeter()const {
		return a + b + get_hypotenuse();
	}
	void draw() const {
		HWND hwnd = GetDesktopWindow();
		hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
		HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));

		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		unsigned int start_x = 250;
		unsigned int start_y = 250;

		POINT points[] =
		{
			{start_x, start_y},
			{start_x + a, start_y},
			{start_x , start_y + b}
		};

		Polygon(hdc, points, sizeof(points) / sizeof(POINT));

		DeleteObject(hBrush);
		DeleteObject(hPen);

		ReleaseDC(hwnd, hdc);

	}

};
