#pragma once
#include "Shape.h"

class Circle : public Shape {
	double radius;
public:
	double get_radius()const {
		return this->radius;
	}
	void set_radius(double radius) {
		if (radius <= 0) radius = 1;
		this->radius = radius;
	}

	Circle(double radius, Color color) :Shape(color) {
		set_radius(radius);
	}

	~Circle() {}

	double get_area()const {
		return 3, 14 * radius * radius;
	}
	double get_perimeter()const {
		return 2 * 3, 14 * radius;
	}
	void draw()const {
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);
		HPEN hPen = CreatePen(PS_SOLID, 5, RGB(155, 0, 10));
		HBRUSH hBrush = CreateSolidBrush(RGB(155, 0, 10));

		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		Ellipse(hdc, 200, 200, radius, radius);

		DeleteObject(hBrush);
		DeleteObject(hPen);
		ReleaseDC(hwnd, hdc);
	}
};
