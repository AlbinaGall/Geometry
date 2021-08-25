#pragma once
#include "Shape.h"

class Triangle : public Shape {
public:
	Triangle(Color color) : Shape(color) {}
	~Triangle() {}
	virtual double get_height()const = 0;
};
