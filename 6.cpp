/*
1번 예제 6-1

#include<iostream>
using namespace std;

int big(int a, int b) {
	if(a>b) return a;
	else return b;
}
int big(int a[], int size) {
	int res = a[0];
	for(int i=1; i<size; i++)
		if(res < a[i]) res = a[i];
	return res;
}

int main() {
	int array[5] = {1, 9, -2, 8, 6};
	cout << big(2,3) << endl;
	cout << big(array, 5) << endl;
}
*/

/*
1번 예제 6-2

#include<iostream>
using namespace std;

int sum(int a, int b) {
	int s = 0;
	for(int i=a; i<=b; i++) 
		s += i;
	return s;
}

int sum(int a) {
	int s = 0;
	for(int i=0; i<=a; i++)
		s += i;
	return s;
}

int main() {
	cout << sum(3,5) << endl;
	cout << sum(3) << endl;
	cout << sum(100) << endl;
}
*/

/*
1번 예제 6-3

#include<iostream>
#include<string>
using namespace std;

void star(int a=5);
void msg(int id, string text="");

void star(int a) {
	for(int i=0; i<a; i++) cout << '*';
	cout << endl;
}

void msg(int id, string text) {
	cout << id << ' ' << text << endl;
}

int main() {
	star();
	star(10);

	msg(10);
	msg(10, "Hello");
}
*/

/*
1번 예제 6-4

#include<iostream>
using namespace std;

void f(char c=' ', int line=1);

void f(char c, int line) {
	for(int i=0; i<line; i++) {
		for(int j=0; j<10; j++)
			cout << c;
		cout << endl;
	}
}

int main() {
	f();
	f('%');
	f('@', 5);
}
*/

/*
1번 예제 6-5

#include<iostream>
using namespace std;

void fillLine(int n=25, char c='*') {
	for(int i=0; i<n; i++)
		cout << c;
	cout << endl;
}

int main() {
	fillLine();
	fillLine(10, '%');
}
*/

/*
1번 예제 6-6

#include<iostream>
using namespace std;

class MyVector{
	int *p;
	int size;
public:
	MyVector(int n=100) {
		p = new int [n];
		size = n;
	}
	~MyVector() { delete [] p; }
};

int main() {
	MyVector *v1, *v2;
	v1 = new MyVector();
	v2 = new MyVector(1024);

	delete v1;
	delete v2;
}
*/

/*
1번 예제 6-7

#include<iostream>
using namespace std;

float square(float a) {
	return a*a;
}

double square(double a) {
	return a*a;
}

int main() {
	cout << square(3.0);
	cout << square((float)3);
}
*/

/*
1번 예제 6-8

#include<iostream>
using namespace std;

int add(int a, int b) {
	return a+b;
}

int add(int a, int &b) {
	b = b + a;
	return b;
}

int main() {
	int s=10, t=20;
	cout << add(s, t);
}
*/

/*
1번 예제 6-9

#include<iostream>
#include<string>
using namespace std;

void msg(int id) {
	cout << id << endl;
}

void msg(int id, string s="") {
	cout << id << ":" << s << endl;
}

int main() {
	msg(5, "Good Morning");
	msg(6);
}
*/

/*
1번 예제 6-10

#include<iostream>
using namespace std;

class Math {
public:
	static int abs(int a) { return a>0?a:-a; }
	static int max(int a, int b) { return (a>b)?a:b; }
	static int min(int a, int b) { return (a>b)?b:a; }
};

int main() {
	cout << Math::abs(-5) << endl;
	cout << Math::max(10, 8) << endl;
	cout << Math::min(-3, -8) << endl;
}
*/

/*
1번 예제 6-11

#include<iostream>
using namespace std;

class Circle {
private:
	static int numOfCircles;
	int radius;
public:
	Circle(int r=1);
	~Circle() { numOfCircles--; }
	double getArea() { return 3.14*radius*radius; }
	static int getNumOfCircles() { return numOfCircles; }
};

Circle::Circle(int r) {
	radius = r;
	numOfCircles++;
}

int Circle::numOfCircles = 0;

int main() {
	Circle *p = new Circle[10];
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;

	delete [] p;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;

	Circle a;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;

	Circle b;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;
}
*/

/*
2번*/

#include<iostream>
using namespace std;

int add(int a[], int i, int b[]=NULL) {
	int n;
	int total=0;

	for(n=0; n<i; n++) {
		total += a[n];
		if(b != NULL) total += b[n];
	}
	return total;
}

int main() {
	int a[] = {1,2,3,4,5};
	int b[] = {6,7,8,9,10};
	int c = add(a, 5);
	int d = add(a, 5, b);
	cout << c << endl;
	cout << d << endl;
}


/*
3번

#include<iostream>
using namespace std;

class MyVector {
	int *mem;
	int size;
public:
	MyVector(int n, int val);
	~MyVector(*/