#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

enum Color {
	CONSOLE_DEFAULT = 0x07,
	CONSOLE_RED = 0xCC,
	CONSOLE_GREEN = 0xAA,
	CONSOLE_BLUE = 0x99,
};

class Shape {
	Color color;
public:
	Color get_color()const {
		return this->color;
	}
	void set_color(Color color) {
		this->color = color;
	}
	Shape(Color color = Color::CONSOLE_DEFAULT) :color(color) {}
	virtual ~Shape() {}

	virtual double get_area() const = 0; //Pure-virtual function
	virtual double get_perimeter() const = 0;
	virtual void draw() const = 0;
};

