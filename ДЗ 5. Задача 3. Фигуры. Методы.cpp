#include <iostream>
#include <string>

class Figure
{
public:
	Figure() :sidesNumber(0), name("Фигура:") {};

	void print_info()
	{
		std::cout << name << "\n" << check << "\n" << "Количество сторон: " << sidesNumber << "\n" << get_sides() << get_corners() << "" << " " << " " << "\n";
	}
protected:
	int sidesNumber;
	std::string name;
	std::string sides;
	std::string corners;
	std::string check;

	Figure(const int& sidesNumber, const std::string& name) :sidesNumber(3), name("Фигура:")
	{

	}

	virtual bool check_bool()
	{
		if (sidesNumber == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	virtual void check_func()
	{
		if (check_bool())
		{
			check = "Правильная";
		}
		else {
			check = "Неправильная";
		}
	}

	virtual std::string get_sides()
	{
		return " ";
	}
	virtual std::string get_corners()
	{
		return " ";
	}

};

class Triangle : public Figure
{
public:
	Triangle() :Figure(3, "Треугольник")
	{

	}
	Triangle(const int& a, const int& b, const int& c, const int& A, const int& B, const int& C) :Triangle(a, b, c, A, B, C, 3, "Треугольник:")
	{

	}

protected:
	Triangle(const int& a, const int& b, const int& c, const int& A, const int& B, const int& C, const int& sidesNumber, const std::string& name)
	{
		this->a = a; this->b = b; this->c = c;
		this->A = A; this->B = B; this->C = C;
		this->name = name;
		this->sidesNumber = sidesNumber;
		check_func();
	}

	std::string get_sides() override
	{
		std::string t = { "Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + "\n" };
		return t;
	}
	std::string get_corners() override
	{
		std::string t = { "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + "\n" };
		return t;
	}

	bool check_bool() override
	{
		if ((A + B + C) == 180)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int a = 0, b = 0, c = 0;
	int A = 0, B = 0, C = 0;
};

class rightTriangle : public Triangle
{
public:
	rightTriangle(int a, int b, int c, int A, int B) :Triangle(a, b, c, A, B, 90, 3, "Прямоугольный треугольник: ")
	{

	}

protected:
	bool check_bool() override
	{
		if ((Triangle::check_bool()) && (C == 90))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};

class isoscelesTriangle : public Triangle
{
public:
	isoscelesTriangle(int a, int b, int A, int B) :Triangle(a, b, a, A, B, A, 3, "Равнобедренный треугольник: ")
	{

	}
protected:
	bool check_bool() override
	{
		if ((Triangle::check_bool()) && (a == c) && (A == C))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class equilateralTriangle : public Triangle
{
public:
	equilateralTriangle(int a) :Triangle(a, a, a, 60, 60, 60, 3, "Равносторонний треугольник: ")
	{

	}
protected:
	bool check_bool() override
	{
		if ((Triangle::check_bool()) && (a == b) && (b == c) && (c == a))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Quadrangle : public Figure
{
protected:
public:
	Quadrangle() :Figure(4, "Четырехугольник:") {}

	Quadrangle(const int& a, const int& b, const int& c, const int& d, const int& A, const int& B, const int& C, const int& D) :Quadrangle(a, b, c, d, A, B, C, D, 4, "Четырехугольник:") {}

protected:
	Quadrangle(const int& a, const int& b, const int& c, const int& d, const int& A, const int& B, const int& C, const int& D, const int& sidesNumber, const std::string& name)
	{
		this->a = a; this->b = b; this->c = c; this->d = d;
		this->A = A; this->B = B; this->C = C; this->D = D;
		this->name = name;
		this->sidesNumber = sidesNumber;
		check_func();
	}

	std::string get_sides()
	{
		std::string q = { "Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + " d=" + std::to_string(d) + "\n" };
		return q;
	}
	std::string get_corners()
	{
		std::string q = { "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + " D=" + std::to_string(D) + "\n" };
		return q;
	}

	bool check_bool() override
	{
		if ((A + B + C + D) == 360)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int a = 0, b = 0, c = 0, d = 0;
	int A = 0, B = 0, C = 0, D = 0;
};

class Parallelogram : public Quadrangle 
{
public:
	Parallelogram(int a, int b, int A, int B) :Quadrangle(a, b, a, b, A, B, A, B, 4, "Параллелограм: ")
	{

	}
	
protected:
	Parallelogram(int a, int b, int A, int B, int sidesNumber, std::string name) :Quadrangle(a, b, a, b, A, B, A, B, sidesNumber, name)
	{

	}

	bool check_bool() override
	{
		if ((Quadrangle::check_bool()) && (a == c && b == d) && (A == C && B == D))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(int a, int b) :Parallelogram(a, b, 90, 90, 4, "Прямоугольник: ")
	{

	}

protected:
	Rectangle(int a, int b, int sidesNumber, std::string name) :Parallelogram(a, b, 90, 90, sidesNumber, name)
	{

	}

	bool check_bool() override
	{
		if ((a == c && b == d) && a != b && (A == 90 && B == 90 && C == 90 && D == 90))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Square : public Rectangle
{
public:
	Square(int a) :Rectangle(a, a, 4, "Квадрат: ")
	{

	}
protected:
	bool check_bool() override
	{
		if ((a == c && b == d) && (a == b && c == d) && (A == 90 && B == 90 && C == 90 && D == 90))
		{
			this->check = "Правильная";
			return true;
		}
		else
		{
			this->check = "Неправильная";
			return false;
		}
	}
};


class Rhomb : public Parallelogram
{
public:
	Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B, 4, "Ромб: ")
	{

	}

protected:
	bool check_bool() override
	{
		if ((a == c && b == d) && (a == b && c == d) && (A == C && B == D) && (A + B == 180))
		{
			this->check = "Правильная";
			return true;
		}
		else
		{
			this->check = "Неправильная";
			return false;
		}
	}
};

void print_info(Figure* figure)
{
	figure->print_info();
}


int main()
{
	setlocale(LC_ALL, "Russian");
	


	Figure f = {};
	Triangle triangle = { 10,20,30,50,60,70 };
	rightTriangle r_triangle = { 10,20,30,50,60 };
	rightTriangle r_triangle2 = { 10,20,30,50,40 };
	isoscelesTriangle i_triangle = { 10,20,50,60 };
	equilateralTriangle e_triangle = { 30 };

	Quadrangle quadrangle = { 10,20,30,40,50,60,70,80 }; 
	Parallelogram parallelogram = { 20,30,30,40 }; 
	Rectangle rectangle = { 20,30 };
	Square square = { 20 }; 
	Rhomb rhomb = { 30,30,40 };


	Figure* p_triangle = &triangle;
	Figure* p_equilateral_triangle = &e_triangle;
	Figure* p_isosceles_triangle = &i_triangle;
	Figure* p_right_triangle = &r_triangle;
	Figure* p_right_triangle2 = &r_triangle2;

	Figure* p_rectangle = &rectangle;
	Figure* p_quadrangle = &quadrangle;
	Figure* p_square = &square;
	Figure* p_parallelogram = &parallelogram;
	Figure* p_rhomb = &rhomb;

	print_info(p_triangle);
	print_info(p_right_triangle);
	print_info(p_right_triangle2);
	print_info(p_isosceles_triangle);
	print_info(p_equilateral_triangle);

	print_info(p_quadrangle);
	print_info(p_rectangle);
	print_info(p_square);
	print_info(p_parallelogram);
	print_info(p_rhomb);



	return 0;
}