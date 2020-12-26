/*
1�� ���� 9-1

#include<iostream>
using namespace std;

class Base {
public:
	void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
public:
	void f() { cout << "Derived::f() called" << endl; }
};

void main() {
	Derived d, *pDer;
	pDer = &d;
	pDer->f();

	Base* pBase;
	pBase = pDer;
	pBase->f();
}
*/

/*
1�� ���� 9-2

#include<iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
public:
	virtual void f() { cout << "Derived::f() called" << endl; }
};

void main() {
	Derived d, *pDer;
	pDer = &d;
	pDer->f();

	Base* pBase;
	pBase = pDer;
	pBase->f();
}
*/

/*
1�� ���� 9-3

#include<iostream>
using namespace std;

class Base {
public: virtual void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
public: void f() { cout << "Derived::f() called" << endl; }
};

class GrandDerived : public Derived {
public: void f() { cout << "GrandDerived::f() called" << endl; }
};

int main() {
	GrandDerived g;
	Base *bp;
	Derived *dp;
	GrandDerived *gp;
	bp = dp = gp = &g;

	bp->f();
	dp->f();
	gp->f();
}
*/

/*
1�� ���� 9-4

#include<iostream>
using namespace std;

class Shape {
public:
	virtual void draw() {
		cout << "--Shape--";
	}
};

class Circle : public Shape {
public:
	int x;
	virtual void draw() {
		Shape::draw();
		cout << "Circle" << endl;
	}
};

int main() {
	Circle circle;
	Shape* pShape = &circle;

	pShape->draw();
	pShape->Shape::draw();
}
*/

/*
1�� ���� 9-5

#include<iostream>
using namespace std;

class Base {
public:
	virtual ~Base() { cout << "~Base()" << endl; }
};

class Derived: public Base {
public:
	virtual ~Derived() { cout << "~Derived()" << endl; }
};

int main() {
	Derived *dp = new Derived();
	Base *bp = new Derived();

	delete dp;
	delete bp;
}
*/

/*
1�� ���� 9-6

#include<iostream>
using namespace std;

class Calculator {
public:
	virtual int add(int a, int b) = 0;
	virtual int subtract(int a, int b) = 0;
	virtual double average(int a [], int size) = 0;
};

class GoodCalc : public Calculator {
public:
	int add(int a, int b) { return a + b; }
	int subtract(int a, int b) { return a - b; }
	double average(int a [], int size) {
		double sum = 0;
		for(int i=0; i<size; i++)
			sum += a[i];
		return sum/size;
	}
};

int main() {
	int a[] = {1,2,3,4,5};
	Calculator *p = new GoodCalc();
	cout << p->add(2,3) << endl;
	cout << p->subtract(2,3) << endl;
	cout << p->average(a,5) << endl;
	delete p;
}
*/

/*
1�� ���� 9-7

#include<iostream>
using namespace std;

class Calculator {
	void input() {
		cout << "���� 2 ���� �Է��ϼ���>> ";
		cin >> a >> b;
	}
protected:
	int a, b;
	virtual int calc(int a, int b) = 0;
public:
	void run() {
		input();
		cout << "���� ���� " << calc(a, b) << endl;
	}
};

class Adder : public Calculator {
protected:
	int calc(int a, int b) {
		return a + b;
	}
};

class Subtractor : public Calculator {
protected:
	int calc(int a, int b) {
		return a - b;
	}
};

int main() {
	Adder adder;
	Subtractor subtractor;

	adder.run();
	subtractor.run();
}
*/

/*
2��*/

#include<iostream>
#include<string>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src)=0;
	virtual string getSourceString()=0;
	virtual string getDestString()=0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
		cout << getSourceString() << "�� �Է��ϼ���>> ";
		cin >> src;
		cout << "��ȯ ��� : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {
public:
	double convert(double src);
	string getSourceString();
	string getDestString();
	WonToDollar(double ratio) : Converter(ratio) {}
};

string WonToDollar::getSourceString() {
	return "��";
}

string WonToDollar::getDestString() {
	return "�޷�";
}

double WonToDollar::convert(double src) {
	src = src/ratio;

	return src;
}

int main() {
	WonToDollar wd(1010);
	wd.run();
}