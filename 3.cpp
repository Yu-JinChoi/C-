/*
1번 예제 3-1

#include<iostream>
using namespace std;

class Circle {
public:
	int radius;
	double getArea();
};

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle donut;
	donut.radius = 1;
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle pizza;
	pizza.radius = 30;
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}
*/

/*
1번 예제 3-2

#include<iostream>
using namespace std;

class Rectangle {
public:
	int width;
	int height;
	int getArea();
};

int Rectangle::getArea() {
	return width*height;
}

int main() {
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "사각형의 면적은 " << rect.getArea() << endl;
}
*/

/*
1번 예제 3-3

#include<iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	double getArea();
};

Circle::Circle() {
	radius = 1;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle donut;
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}
*/

/*
1번 예제 3-4

#include<iostream>
using namespace std;

class Rectangle {
public:
	int width, height;
	Rectangle();
	Rectangle(int w, int h);
	Rectangle(int lenght);
	bool isSquare();
};

Rectangle::Rectangle() {
	width = height = 1;
}

Rectangle::Rectangle(int w, int h) {
	width = w; height = h;
}

Rectangle::Rectangle(int length) {
	width = height = length;
}

bool Rectangle::isSquare() {
	if(width == height) return true;
	else return false;
}

int main() {
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);
	
	if(rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
	if(rect2.isSquare()) cout << "rect2는 정사각형이다." << endl;
	if(rect3.isSquare()) cout << "rect3는 정사각형이다." << endl;
}
*/

/*
1번 예제 3-5

#include<iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};

Circle::Circle() {
	radius = 1;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::~Circle() {
	cout << "반지름 " << radius << " 원 소멸" << endl;
}

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle donut;
	Circle pizza(30);
	return 0;
}
*/

/*
1번 예제 3-6

#include<iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};

Circle::Circle() {
	radius = 1;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::~Circle() {
	cout << "반지름 " << radius << " 원 소멸" << endl;
}

double Circle::getArea() {
	return 3.14*radius*radius;
}

Circle globalDonut(1000);
Circle globalPizza(2000);

void f() {
	Circle fDonut(100);
	Circle fPizza(200);
}

int main() {
	Circle mainDonut;
	Circle mainPizza(30);
	f();
}
*/

/*
2번

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Random {
public:
	Random();
	int next();
	int nextInRange(int first, int end);
};

Random::Random() {
	srand((unsigned)time(0));
}

int Random::next() {
	return rand() % (RAND_MAX+1);
}

int Random::nextInRange(int first, int end) {
	return rand() % (end - first + 1) + first;
}

int main() {
	Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10개--" << endl;
	for(int i=0; i<10; i++) {
		int n = r.next();
		cout << n << ' ';
	}

	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10개 --" << endl;
	for(int i=0; i<10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;
}
*/

/*
3번

#include<iostream>
using namespace std;

class Oval {

public:
	int width, height;
	Oval(int width, int height);
	Oval();
	~Oval();
	int getWidth();
	int getHeight();
	void set(int w, int h);
	void show();
};

Oval::Oval(int w, int h) {
	width = w;
	height = h;
}

Oval::Oval() {
	width = height = 1;
}

Oval::~Oval() {
	cout << "Oval 소멸 : width = " << width << ", height = " << height<< endl;
}

int Oval::getWidth() {
	return width;
}

int Oval::getHeight() {
	return height;
}

void Oval::set(int w, int h) {
	width = w;
	height = h;
}

void Oval::show() {
	cout << "width = " << width << ", height = " << height << endl;
}

int main() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << "," << b.getHeight() << endl;
}
*/

/*
4번

#include<iostream>
using namespace std;

class Add {
public:
	int a;
	int b;
	void setValue(int x, int y);
	int calculate();
};

void Add::setValue(int x, int y) {
	a = x;
	b = y;
}

int Add::calculate() {
	return a + b;
}

class Sub {
public:
	int a;
	int b;
	void setValue(int x, int y);
	int calculate();
};

void Sub::setValue(int x, int y) {
	a = x;
	b = y;
}

int Sub::calculate() {
	return a - b;
}

class Mul {
public:
	int a;
	int b;
	void setValue(int x, int y);
	int calculate();
};

void Mul::setValue(int x, int y) {
	a = x;
	b = y;
}

int Mul::calculate() {
	return a*b;
}

class Div {
public:
	int a;
	int b;
	void setValue(int x, int y);
	int calculate();
};

void Div::setValue(int x, int y) {
	a = x;
	b = y;
}

int Div::calculate() {
	return a/b;
}

int main() {
	int i, j;
	char k;

	Add a;
	Sub s;
	Mul m;
	Div d;

	while (1) {

		cout << "두 정수와 연산자를 입력하세요>>";
		cin >> i >> j >> k;

		if (k == '+') {
			a.setValue(i, j);
			cout << a.calculate() << endl;
		}
		else if (k == '-') {
			s.setValue(i, j);
			cout << s.calculate() << endl;
		}

		else if (k == '*') {
			m.setValue(i, j);
			cout << m.calculate() << endl;
		}

		else if (k == '/') {
			d.setValue(i, j);
			cout << d.calculate() << endl;
		}
	}
}
*/

/*
5번*/

#include<iostream>
using namespace std;

class Point {
protected:
	int m_x, m_y;

public:
	void GetX(int x);
	void GetY(int y);
	bool SetX();
	bool SetY();
	void IsEqual(const Point &a, const Point &b);
	void Print();
};

void Point::GetX(int x) {
	m_x = x;
}

void Point::GetY(int y) {
	m_y = y;
}

bool Point::SetX() {
	if(m_x > 1000) {
		m_x = 1000;
		cout << "X 좌표 변경 실패" << endl;
		return false;
	}
	else if (m_x < 0) {
		m_x = 0;
		cout << "X 좌표 변경 실패" << endl;
		return false;
	}
	else return true;
}

bool Point::SetY() {
	if (m_y > 1000) {
		m_y = 1000;
		cout << "Y 좌표 변경 실패" << endl;
		return false;
	}
	else if (m_y < 0) {
		m_y = 0;
		cout << "Y 좌표 변경 실패" << endl;
		return false;
	}
	else return true;
}

void Point::IsEqual(const Point &a, const Point &b) {

	if ((a.m_x == b.m_x) && (a.m_y == b.m_y))
		cout << "p1 과 p2의 값은 같습니다." << endl;

	else
		cout << "p1 과 p2의 값은 다릅니다." << endl;
}

void Point::Print() {
	cout << "(" << m_x << "," << m_y << ")" << endl;
}

int main() {

	int i, j, n, m;

	Point r;
	Point k;
	Point t;

	cout << "p1:" << endl;
	cin >> i >> j;

	r.GetX(i);
	r.GetY(j);

	cout << "p2:" << endl;
	cin >> n >> m;

	k.GetX(n);
	k.GetY(m);

	r.SetX();
	r.SetY();
	k.SetX();
	k.SetY();

	cout << "p1 = ";
	r.Print();
	cout << "p2 = ";
	k.Print();

	t.IsEqual(r, k);

}
