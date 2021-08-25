#pragma once
#include "Shape.h"
#include "Triangle.h"

class IsoscelesTriangle : public Triangle {
	double side;
	double base;
public:
	double get_side() const { return side; }
	double get_base() const { return base; }
	double set_side(double side) {
		if (side <= 0) side = 1;
		this->side = side;
		return this->side;
	}
	double set_base(double base) {
		if (base <= 0) base = 1;
		this->base = base;
		return this->base;
	}
	IsoscelesTriangle(double side, double base, Color color) : Triangle(color) {
		set_side(side);
	}
	~IsoscelesTriangle() {}

	double get_height()const {
		return sqrt(3) / 2 * side;
	}

	double get_area()const {
		return get_height() * side / 2;
	}

	double get_perimeter()const {
		return side * 2 + base;
	}
	void draw() const {
		HWND hwnd = GetDesktopWindow();
		hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 15));
		HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 15));

		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		unsigned int start_x = 200;
		unsigned int start_y = 200;

		POINT points[] =
		{
			{start_x, start_y + side},
			{start_x + side, start_y + side},
			{start_x + side / 2, start_y + side - base }
		};

		Polygon(hdc, points, sizeof(points) / sizeof(POINT));

		DeleteObject(hBrush);
		DeleteObject(hPen);

		ReleaseDC(hwnd, hdc);

	}

};