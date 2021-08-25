#pragma once
#include "Shape.h"
#include "Triangle.h"

class EquilateralTriangle : public Triangle {
	double side;
public:
	double get_side() const { return side; }
	double set_side(double side) {
		if (side <= 0) side = 1;
		this->side = side;
		return this->side;
	}
	EquilateralTriangle(double side, Color color) : Triangle(color) {
		set_side(side);
	}
	~EquilateralTriangle() {}

	double get_height()const {
		return sqrt(3) / 2 * side;
	}

	double get_area()const {
		return get_height() * side / 2;
	}

	double get_perimeter()const {
		return side * 3;
	}
	void draw() const {
		HWND hwnd = GetDesktopWindow();
		hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
		HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));

		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		unsigned int start_x = 300;
		unsigned int start_y = 300;

		POINT points[] =
		{
			{start_x, start_y + side},
			{start_x + side, start_y + side},
			{start_x + side / 2, start_y + side - get_height()}
		};

		Polygon(hdc, points, sizeof(points) / sizeof(POINT));

		DeleteObject(hBrush);
		DeleteObject(hPen);

		ReleaseDC(hwnd, hdc);

	}

};
