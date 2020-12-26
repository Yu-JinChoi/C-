/*
1번 예제 8-1

#include<iostream>
#include<string>
using namespace std;

class Point {
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}

int main() {
	Point p;
	ColorPoint cp;
	cp.set(3,4);
	cp.setColor("Red");
	cp.showColorPoint();
}
*/

/*
1번 예제 8-2

#include<iostream>
#include<string>
using namespace std;

class Point {
protected:
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
	bool equals(ColorPoint p);
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}

bool ColorPoint::equals(ColorPoint p) {
	if(x == p.x && y == p.y && color == p.color)
		return true;
	else 
		return false;
}

int main() {
	Point p;
	p.set(2,3);
	//p.x = 5; 오류발생
	//p.y = 5; 오류발생
	p.showPoint();

	ColorPoint cp;
	//cp.x = 10; 오류발생
	//cp.y = 10; 오류발생
	cp.set(3,4);
	cp.setColor("Red");

	ColorPoint cp2;
	cp2.set(3,4);
	cp2.setColor("Red");
	cout << ((cp.equals(cp2))?"true":"false");
}
*/

/*
1번 예제 8-3

#include<iostream>
#include<string>
using namespace std;

class TV {
	int size;
public:
	TV() { size = 20; }
	TV(int size) { this->size = size; }
	int getSize() { return size; }
};

class WideTV : public TV {
	bool videoIn;
public:
	WideTV(int size, bool videoIn) : TV(size) {
		this->videoIn = videoIn;
	}
	bool getVideoIn() { return videoIn; }
};

class SmartTV : public WideTV {
	string ipAddr;
public:
	SmartTV(string ipAddr, int size) : WideTV(size, true) {
		this->ipAddr = ipAddr;
	}
	string getIpAddr() { return ipAddr; }
};

int main() {
	SmartTV htv("192.0.0.1", 32);
	cout << "size=" << htv.getSize() << endl;
	cout << "videoIn=" << boolalpha << htv.getVideoIn() << endl;
	cout << "IP=" << htv.getIpAddr() << endl;
}
*/

/*
1번 예제 8-4

#include<iostream>
using namespace std;

class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { cout << a; }
};

class Derived : private Base {
	int b;
protected:
	void setB(int b) { this->b = b; }
public:
	void showB() { cout << b; }
};

int main() {
	Derived x;
	//x.a = 5; 오류발생
	//x.setA(10); 오류발생
	//x.setA(); 오류발생
	//x.b = 10; 오류발생
	//x.setB(10); 오류발생
	x.showB();
}
*/

/*
1번 예제 8-5

#include<iostream>
using namespace std;

class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { cout << a; }
};

class Derived : protected Base {
	int b;
protected:
	void setB(int b) { this->b = b; }
public:
	void showB() { cout << b; }
};

int main() {
	Derived x;
	//x.a = 5; 오류발생
	//x.setA(10); 오류발생
	//x.showA(); 오류발생
	//x.b = 10; 오류발생
	//x.setB(10); 오류발생
	x.showB();
}
*/

/*
1번 예제 8-6

#include<iostream>
using namespace std;

class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { cout << a; }
};

class Derived : private Base {
	int b;
protected:
	void setB(int b) { this->b = b; }
public:
	void showB() {
		setA(5);
		showA();
		cout << b;
	}
};

class GrandDerived : private Derived {
	int c;
protected:
	void setAB(int x) {
		//setA(x); 오류발생
		//showA(); 오류발생
		setB(x);
	}
};
*/

/*
1번 예제 8-7

#include<iostream>
using namespace std;

class Adder {
protected:
	int add(int a, int b) { return a+b; }
};

class Subtractor {
protected:
	int minus(int a, int b) { return a-b; }
};

class Calculator : public Adder, public Subtractor {
public:
	int calc(char op, int a, int b);
};

int Calculator::calc(char op, int a, int b) {
	int res=0;
	switch(op) {
		case '+' : res = add(a, b); break;
		case '-' : res = minus(a, b); break;
	}
	return res;
}

int main() {
	Calculator handCalculator;
	cout << "2 + 4 = " << handCalculator.calc('+', 2, 4) << endl;
	cout << "100 - 8 = " << handCalculator.calc('-', 100, 8) << endl;
}
*/

/*
2번

#include<iostream>
#include<cstring>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius=0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};

class NamedCircle : public Circle {
	int radius;
	string name;
public:
	NamedCircle(int radius, string name="NULL") { setRadius(radius); this->name = name; }
	void show();
};

void NamedCircle::show() {
	int len;

	len = name.length();
	cout << "반지름이 " << getRadius() << "인 ";
	for(int i=0; i<len; i++) {
		cout << name[i];
	}
	cout << endl;
}

int main() {
	NamedCircle waffle(3, "waffle");
	waffle.show();
}
*/

/*
3번*/

#include<iostream>
#include<cstring>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x=0, int y=0) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point {
	int x, y;
	string color;
public:
	ColorPoint(int x=0, int y=0, string color="NULL") { move(x, y); this->color = color; }
	void setPoint(int x, int y);
	void setColor(string color);
	void show();
};

void ColorPoint::setPoint(int x, int y) {
	move(x, y);
}

void ColorPoint::setColor(string color) {
	this->color = color;
}

void ColorPoint::show() {
	int len;

	len = color.length();
	for(int i=0; i<len; i++) {
		cout << color[i];
	}
	cout << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
}

int main() {
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}


/*
4번

#include<iostream>
using namespace std;

class BaseArray {
private:
	int capacity;
	int *mem;
protected:
	BaseArray(int capacity=100) {
		this->capacity = capacity; mem = new int [capacity];
	}
	~BaseArray() { delete [] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray {
	int n;
public:
	
};

int main() {
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for(int i=0; i<5; i++) {
		cin >> n;
		mQ.
		*/