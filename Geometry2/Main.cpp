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
	Shape(Color color = Color::CONSOLE_DEFAULT) :color(color){}
	virtual ~Shape(){}

	virtual double get_area() const = 0; //Pure-virtual function
	virtual double get_perimeter() const = 0;
	virtual void draw() const = 0;
};
		
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

	~Square(){}

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
		HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0,255,0)); //PS_SOLID-сплошная линия, 5- толщина линии в пикселях
		//pen - рисует контур фигуры
		HBRUSH hBrush= CreateSolidBrush(RGB(0,255,0));
		//4. выбрать созданные карандаш и кисть
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		//5.рисуем квадрат
		Rectangle(hdc,100,100,100+side,100+side);


		//освобождаем ресурсы
		DeleteObject(hBrush);
		DeleteObject(hPen);
		ReleaseDC(hwnd, hdc);


	}


};

class Rect : public Shape{
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
		return (lenght + widght)*2;
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
		return 3,14 * radius * radius;
	}
	double get_perimeter()const {
		return 2* 3,14 * radius;
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

class Triangle : public Shape {
public:
	Triangle(Color color) : Shape(color) {}
	~Triangle(){}
	virtual double get_height()const=0;
};

class EquilateralTriangle : public Triangle {
	double side;
public: 
	double get_side() const { return side; }
	double set_side(double side) {
		if (side <= 0) side = 1;
		this->side = side;
		return this->side;
	}
	EquilateralTriangle(double side, Color color) : Triangle(color){
		set_side(side);
	}
	~EquilateralTriangle(){}

	double get_height()const {
		return sqrt(3) / 2 * side;
	}

	double get_area()const {
		return get_height() * side/2;
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
			{start_x + side/2, start_y+side-get_height()}
		};

		Polygon(hdc,points,sizeof(points)/sizeof(POINT));

		DeleteObject(hBrush);
		DeleteObject(hPen);

		ReleaseDC(hwnd, hdc);

	}

};

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
		return sqrt(a*a +b*b);
	}

	double get_area()const {
		return a * b / 2;
	}

	double get_perimeter()const {
		return a+b+get_hypotenuse();
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
			{start_x+a, start_y},
			{start_x , start_y+b}
		};

		Polygon(hdc, points, sizeof(points) / sizeof(POINT));

		DeleteObject(hBrush);
		DeleteObject(hPen);

		ReleaseDC(hwnd, hdc);

	}

};

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
		return side * 2+base;
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


void main() {
	setlocale(LC_ALL, "Russian");
	//Shape shape(Color::CONSOLE_BLUE);
	//cout << hex << shape.get_color() << endl;

	/*Square square(250, Color::CONSOLE_GREEN);
	cout << "Длина стороны: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_perimeter() << endl;
	cout << "Периметр квадрата: " << square.get_area() << endl;
	square.draw();
	//cin.get();

	EquilateralTriangle e3(100, Color::CONSOLE_GREEN);
	cout << "Длина стороны: " << e3.get_side() << endl;
	cout << "Периметр треугольника: " << e3.get_perimeter() << endl;
	cout << "Площадь треугольника: " << e3.get_area() << endl;
	e3.draw();*/
	
	cout << "--------------------------------" << endl << "Прямоугольник" << endl;
	Rect rect(750,450, Color::CONSOLE_RED);
	cout << "Ширина: " << rect.get_widght() << endl;
	cout << "Длина: " << rect.get_lenght() << endl;
	cout << "Площадь прямоугольника: " << rect.get_perimeter() << endl;
	cout << "Периметр прямоугольника: " << rect.get_area() << endl;
	rect.draw();
	
	cout << "--------------------------------" << endl << "Окружность" << endl;
	Circle circle(650, Color::CONSOLE_RED);
	cout << "Радиус окружности: " << circle.get_radius() << endl;
	cout << "Длина окружности: " << circle.get_perimeter() << endl;
	cout << "Площадь окружности: " << circle.get_area() << endl;
	circle.draw();

	cout << "--------------------------------" << endl << "Прямоугольный треугольник"<< endl;
	RightTriangle rtr(300,500, Color::CONSOLE_GREEN);
	cout << "Катет а: " << rtr.get_a() << endl;
	cout << "Катет b: " << rtr.get_height() << endl;
	cout << "Площадь треугольника: " << rtr.get_area() << endl;
	cout << "Периметр треугольника: " << rtr.get_perimeter() << endl;
	rtr.draw();

	cout << "--------------------------------" << endl << "Равнобедренный треугольник" << endl;
	IsoscelesTriangle rbtr(100, 150, Color::CONSOLE_GREEN);
	cout << "Длина стороны: " << rbtr.get_side() << endl;
	cout << "Длина основания: " << rbtr.get_base() << endl;
	cout << "Высота: " << rbtr.get_height() << endl;
	cout << "Площадь треугольника: " << rbtr.get_area() << endl;
	cout << "Периметр треугольника: " << rbtr.get_perimeter() << endl;
	rbtr.draw();
}