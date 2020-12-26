/*
1�� ���� 5-1

#include<iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	double getArea() { return 3.14*radius*radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "������ ���� radius = " << radius << endl;
}

Circle::Circle(int radius) {
	this->radius = radius;
	cout << "������ ���� radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "�Ҹ��� ���� radius = " << radius << endl;
}

void increase(Circle c) {
	int r = c.getRadius();
	c.setRadius(r+1);
}

int main() {
	Circle waffle(30);
	increase(waffle);
	cout << waffle.getRadius() << endl;
}
*/

/*
1�� ���� 5-2

#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};

Circle getCircle() {
	Circle tmp(30);
	return tmp;
}

int main() {
	Circle c;
	cout << c.getArea() << endl;

	c = getCircle();
	cout << c.getArea() << endl;
}
*/

/*
1�� ���� 5-3

#include<iostream>
using namespace std;

int main() {
	cout << "i" << '\t' << "n" << '\t' << "refn" << endl;
	int i = 1;
	int n = 2;
	int &refn = n;
	n = 4;
	refn++;
	cout << i << '\t' << n << '\t' << refn << endl;

	refn = i;
	refn++;
	cout << i << '\t' << n << '\t' << refn << endl;

	int *p = &refn;
	*p = 20;
	cout << i << '\t' << n << '\t' << refn << endl;
}
*/

/*
1�� ���� 5-4

#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};

int main() {
	Circle circle;
	Circle &refc = circle;
	refc.setRadius(10);
	cout << refc.getArea() << " " << circle.getArea();
}
*/

/*
1�� ���� 5-5

#include<iostream>
using namespace std;

bool average(int a[], int size, int& avg) {
	if(size <= 0)
		return false;
	int sum = 0;
	for(int i=0; i<size; i++)
		sum += a[i];
	avg = sum/size;
	return true;
}

int main() {
	int x[] = {0,1,2,3,4,5};
	int avg;
	if(average(x, 6, avg)) cout << "����� " << avg << endl;
	else cout << "�Ű� ���� ���� " << endl;

	if(average(x, -2, avg)) cout << "����� " << avg << endl;
	else cout << "�Ű� ���� ���� " << endl;
}
*/

/*
1�� ���� 5-6

#include<iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	double getArea() { return 3.14*radius*radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "������ ���� radius = " << radius << endl;
}

Circle::Circle(int radius) {
	this->radius = radius;
	cout << "������ ���� radius = " << radius << endl;
}

Circle::~Circle() {
	cout <<  "�Ҹ��� ���� radius = " << radius << endl;
}

void increase(Circle &c) {
	int r = c.getRadius();
	c.setRadius(r+1);
}

int main() {
	Circle waffle(30);
	increase(waffle);
	cout << waffle.getRadius() << endl;
}
*/

/*
1�� ���� 5-7

#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};

void readRadius(Circle &c) {
	int r;
	cout << "���� ������ �������� �Է��ϼ���>>";
	cin >> r;
	c.setRadius(r);
}

int main() {
	Circle donut;
	readRadius(donut);
	cout << "donut�� ���� = " << donut.getArea() << endl;
}
*/

/*
1�� ���� 5-8

#include<iostream>
using namespace std;

char& find(char s[], int index) {
	return s[index];
}

int main() {
	char name[] = "Mike";
	cout << name << endl;

	find(name, 0) = 'S';
	cout << name << endl;

	char& ref = find(name, 2);
	ref = 't';
	cout << name << endl;
}
*/

/*
1�� ���� 5-9

#include<iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle(Circle& c);
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};

Circle::Circle(Circle& c) {
	this->radius = c.radius;
	cout << "���� ������ ���� radius = " << radius << endl;
}

int main() {
	Circle src(30);
	Circle dest(src);

	cout << "������ ���� = " << src.getArea() << endl;
	cout << "�纻�� ���� = " << dest.getArea() << endl;
}
*/

/*
1�� ���� 5-10

#include<iostream>
#include<cstring>
using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(int id, char* name);
	~Person();
	void changeName(char* name);
	void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, char* name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char [len+1];
	strcpy(this->name, name);
}

Person::~Person() {
	if(name)
		delete [] name;
}

void Person::changeName(char* name) {
	if(strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

int main() {
	Person father(1, "Kitae");
	Person daughter(father);

	cout << "daughter ��ü ���� ���� ----" << endl;
	father.show();
	daughter.show();

	daughter.changeName("Grace");
	cout << "daughter �̸��� Grace�� ������ �� ----" << endl;
	father.show();
	daughter.show();

	return 0;
}
*/

/*
1�� ���� 5-11

#include<iostream>
#include<cstring>
using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(int id, char* name);
	Person(Person& person);
	~Person();
	void changeName(char* name);
	void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, char* name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char [len+1];
	strcpy(this->name, name);
}

Person::Person(Person& person) {
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len+1];
	strcpy(this->name, person.name);
	cout << "���� ������ ����, ���� ��ü�� �̸� " << this->name << endl;
}

Person::~Person() {
	if(name)
		delete [] name;
}

void Person::changeName(char* name) {
	if(strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

int main() {
	Person father(1, "Kitae");
	Person daughter(father);

	cout << "daughter ��ü ���� ���� ----" << endl;
	father.show();
	daughter.show();

	daughter.changeName("Grace");
	cout << "daughter �̸��� Grace�� ������ �� ----" << endl;
	father.show();
	daughter.show();

	return 0;
}
*/

/*
1�� ���� 5-12

#include<iostream>
using namespace std;

#include<iostream>
#include<cstring>
using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(int id, char* name);
	Person(Person& person);
	~Person();
	void changeName(char* name);
	void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, char* name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char [len+1];
	strcpy(this->name, name);
}

Person::Person(Person& person) {
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len+1];
	strcpy(this->name, person.name);
	cout << "���� ������ ���� " << this->name << endl;
}

Person::~Person() {
	if(name)
		delete [] name;
}

void Person::changeName(char* name) {
	if(strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

void f(Person person) {
	person.changeName("dummy");
}

Person g() {
	Person mother(2, "Jane");
	return mother;
}

int main() {
	Person father(1, "Kitae");
	Person son = father;
	f(father);
	g();
}
*/

/*
2��*/

#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int r) { radius = r; }
	~Circle();
	double getArea() { return 3.14*radius*radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

void swap(Circle &c, Circle &p) {
	int tmp;
}