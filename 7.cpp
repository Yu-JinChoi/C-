/*
1번 예제 7-1

#include<iostream>
using namespace std;

class Rect;
bool equals(Rect r, Rect s);

class Rect {
int width, height;
public:
Rect(int width, int height) { this->width = width; this->height = height; }
friend bool equals(Rect r, Rect s);
};

bool equals(Rect r, Rect s) {
if(r.width == s.width && r.height == s.height) return true;
else return false;
}

int main() {
Rect a(3,4), b(4,5);
if(equals(a,b)) cout << "equal" << endl;
else cout << "not equal" << endl;
}
*/

/*
1번 예제 7-2

#include<iostream>
using namespace std;

class Rect;

class RectManager {
public:
bool equals(Rect r, Rect s);
};

class Rect {
int width, height;
public:
Rect(int width, int height) { this->width = width; this->height = height;}
friend bool RectManager::equals(Rect r, Rect s);
};

bool RectManager::equals(Rect r, Rect s) {
if(r.width == s.width && r.height == s.height) return true;
else return false;
}

int main() {
Rect a(3,4), b(3,4);
RectManager man;

if(man.equals(a,b)) cout << "equal" << endl;
else cout << "not equal" << endl;
}
*/

/*
1번 예제 7-3

#include<iostream>
using namespace std;

class Rect;

class RectManager {
public:
bool equals(Rect r, Rect s);
void copy(Rect& dest, Rect& src);
};

class Rect {
int width, height;
public:
Rect(int width, int height) { this->width = width; this->height = height;}
friend RectManager;
};

bool RectManager::equals(Rect r, Rect s) {
if(r.width == s.width && r.height == s.height) return true;
else return false;
}

void RectManager::copy(Rect& dest, Rect& src) {
dest.width = src.width; dest.height = src.height;
}

int main() {
Rect a(3,4), b(5,6);
RectManager man;

man.copy(b,a);
if(man.equals(a,b)) cout << "equal" << endl;
else cout << "not equal" << endl;
}
*/

/*
1번 예제 7-4

#include<iostream>
using namespace std;

class Power {
int kick;
int punch;
public:
Power(int kick=0, int punch=0) {
this->kick = kick; this->punch = punch;
}
void show();
Power operator+ (Power op2);
};

void Power::show() {
cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power::operator+(Power op2) {
Power tmp;
tmp.kick = this->kick + op2.kick;
tmp.punch = this->punch + op2.punch;
return tmp;
}

int main() {
Power a(3,5), b(4,6), c;
c = a + b;
a.show();
b.show();
c.show();
}
*/

/*
1번 예제 7-5

#include<iostream>
using namespace std;

class Power {
int kick;
int punch;
public:
Power(int kick=0, int punch=0) { this->kick = kick; this->punch = punch; }
void show();
bool operator== (Power op2);
};

void Power::show() {
cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

bool Power::operator==(Power op2) {
if(kick==op2.kick && punch==op2.punch) return true;
else return false;
}

int main() {
Power a(3,5), b(3,5);
a.show();
b.show();
if(a == b) cout << "두 파워가 같다." << endl;
else cout << "두 파워가 같지 않다." << endl;
}
*/

/*
1번 예제 7-6

#include<iostream>
using namespace std;

class Power {
int kick;
int punch;
public:
Power(int kick=0, int punch=0) {
this->kick = kick; this->punch = punch;
}
void show();
Power operator+= (Power op2);
};

void Power::show() {
cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power::operator+=(Power op2) {
kick = kick + op2.kick;
punch = punch + op2.punch;
return *this;
}

int main() {
Power a(3,5), b(4,6), c;
a.show();
b.show();
c = a += b;
a.show();
c.show();
}
*/

/*
1번 예제 7-7

#include<iostream>
using namespace std;

class Power {
int kick;
int punch;
public:
Power(int kick=0, int punch=0) {
this->kick = kick; this->punch = punch;
}
void show();
Power operator+ (int op2);
};

void Power::show() {
cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power::operator+(int op2) {
Power tmp;
tmp.kick = kick + op2;
tmp.punch = punch + op2;
return tmp;
}

int main() {
Power a(3,5), b;
a.show();
b.show();
b = a + 2;
a.show();
b.show();
}
*/

/*
1번 예제 7-8

#include<iostream>
using namespace std;

class Power {
int kick;
int punch;
public:
Power(int kick=0, int punch=0) {
this->kick = kick; this->punch = punch;
}
void show();
Power operator++ ();
};

void Power::show() {
cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power::operator++() {
kick++;
punch++;
return *this;
}

int main() {
Power a(3,5), b;
a.show();
b.show();
b = ++a;
a.show();
b.show();
}
*/

/*
1번 예제 7-9

#include<iostream>
using namespace std;

class Power {
int kick;
int punch;
public:
Power(int kick=0, int punch=0) {
this->kick = kick; this->punch = punch;
}
void show();
bool operator! ();
};

void Power::show() {
cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

bool Power::operator!() {
if(kick == 0 && punch == 0) return true;
else return false;
}

int main() {
Power a(0,0), b(5,5);
if(!a) cout << "a의 파워가 0이다." << endl;
else cout << "a의 파워가 0이 아니다." << endl;
if(!b) cout << "b의 파워가 0이다." << endl;
else cout << "b의 파워가 0이 아니다." << endl;
}
*/

/*
1번 예제 7-10

#include<iostream>
using namespace std;

class Power {
int kick;
int punch;
public:
Power(int kick=0, int punch=0) {
this->kick = kick; this->punch = punch;
}
void show();
Power operator++ (int x);
};

void Power::show() {
cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power::operator++(int x) {
Power tmp = *this;
kick++;
punch++;
return tmp;
}

int main() {
Power a(3,5), b;
a.show();
b.show();
b = a++;
a.show();
b.show();
}
*/

/*
1번 예제 7-11

#include<iostream>
using namespace std;

class Power {
int kick;
int punch;
public:
Power(int kick=0, int punch=0) {
this->kick = kick; this->punch = punch;
}
void show();
friend Power operator+(int op1, Power op2);
};

void Power::show() {
cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator+(int op1, Power op2) {
Power tmp;
tmp.kick = op1 + op2.kick;
tmp.punch = op1 + op2.punch;
return tmp;
}

int main() {
Power a(3,5), b;
a.show();
b.show();
b = 2 + a;
a.show();
b.show();
}
*/

/*
1번 예제 7-12

#include<iostream>
using namespace std;

class Power {
int kick;
int punch;
public:
Power(int kick=0, int punch=0) {
this->kick = kick; this->punch = punch;
}
void show();
friend Power operator+(Power op1, Power op2);
};

void Power::show() {
cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator+(Power op1, Power op2) {
Power tmp;
tmp.kick = op1.kick + op2.kick;
tmp.punch = op1.punch + op2.punch;
return tmp;
}

int main() {
Power a(3,5), b(4,6), c;
c = a + b;
a.show();
b.show();
c.show();
}
*/

/*
1번 예제 7-13

#include<iostream>
using namespace std;

class Power {
int kick;
int punch;
public:
Power(int kick=0, int punch=0) { this->kick = kick; this->punch = punch; }
void show();
friend Power operator++(Power& op);
friend Power operator++(Power& op, int x);
};

void Power::show() {
cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator++(Power& op) {
op.kick++;
op.punch++;
return op;
}

Power operator++(Power& op, int x) {
Power tmp = op;
op.kick++;
op.punch++;
return tmp;
}

int main() {
Power a(3,5), b;
b = ++a;
a.show(); b.show();

b = a++;
a.show(); b.show();
}
*/

/*
2번-1

#include<iostream>
#include<cstring>
using namespace std;

class Book {
string name;
int num;
int page;
public:
Book(string name, int num, int page) {this->name = name; this->num = num; this->page = page; }
Book operator+=(int op2);
Book operator-=(int op2);
void show();
};

Book Book::operator+=(int op2) {
num = num + op2;
return *this;
}

Book Book::operator-=(int op2) {
num = num - op2;
return *this;
}

void Book::show() {
int len, i;
len = name.length();
for(i=0; i<len; i++) cout << name[i];
cout << " " << num << "원 " << page << " 페이지" << endl;
}

int main() {
Book a("청춘", 20000, 300), b("미래", 30000, 500);
a += 500;
b -= 500;
a.show();
b.show();
}
*/

/*
2번-2

#include<iostream>
#include<cstring>
using namespace std;

class Book {
string name;
int num;
int page;
public:
Book(string name="NULL", int num=0, int page=0) {this->name = name; this->num = num; this->page = page; }
friend Book operator+=(Book &op1, int op2);
friend Book operator-=(Book &op1, int op2);
void show();
};

Book operator+=(Book &op1, int op2) {
op1.num = op1.num + op2;
return op1;
}

Book operator-=(Book &op1, int op2) {
op1.num = op1.num - op2;
return op1;
}

void Book::show() {
int len, i;
len = name.length();
for(i=0; i<len; i++) cout << name[i];
cout << " " << num << "원 " << page << " 페이지" << endl;
}

int main() {
Book a("청춘", 20000, 300), b("미래", 30000, 500);
a += 500;
b -= 500;
a.show();
b.show();
}
*/

/*
3번-1

#include<iostream>
#include<cstring>
using namespace std;

class Book {
string name;
int num;
int page;
public:
Book(string name="NULL", int num=0, int page=0) { this->name = name; this->num = num; this->page = page; }
bool operator==(int op2);
bool operator==(string op2);
bool operator==(Book op2);
};

bool Book::operator==(int op2) {
if(num == op2) return true;
else return false;
}

bool Book::operator==(string op2) {
int i, len;

len = op2.length();
for(i=0; i<len; i++) {
if(name[i] == op2[i]) return true;
else { return false; break;}
}
}

bool Book::operator==(Book op2) {
int i, len;

len = op2.name.length();
for(i=0; i<len; i++) {
if(num == op2.num && page == op2.page && name[i] == op2.name[i]) return true;
else { return false; break; }
}
}

int main() {
Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
if(a == 30000) cout << "정가 30000원" << endl;
if(a == "명품 C++") cout << "명품 C++ 입니다." << endl;
if(a == b) cout << "두 책이 같은 책입니다." << endl;
}
*/

/*
3번-2

#include<iostream>
#include<cstring>
using namespace std;

class Book {
string name;
int num;
int page;
public:
Book(string name="NULL", int num=0, int page=0) { this->name = name; this->num = num; this->page = page; }
friend bool operator==(Book &op1, int op2);
friend bool operator==(Book &op1, string op2);
friend bool operator==(Book &op1, Book op2);
};

bool operator==(Book &op1, int op2) {
if(op1.num == op2) return true;
else false;
}

bool operator==(Book &op1, string op2) {
int i, len;

len = op2.length();
for(i=0; i<len; i++) {
if(op1.name[i] == op2[i]) return true;
else { return false; break;}
}
}

bool operator==(Book &op1, Book op2) {
int i, len;

len = op2.name.length();
for(i=0; i<len; i++) {
if(op1.num == op2.num && op1.page == op2.page && op1.name[i] == op2.name[i]) return true;
else { return false; break; }
}
}

int main() {
Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
if(a == 30000) cout << "정가 30000원" << endl;
if(a == "명품 C++") cout << "명품 C++ 입니다." << endl;
if(a == b) cout << "두 책이 같은 책입니다." << endl;
}
*/

/*
4번-1

#include<iostream>
using namespace std;

class Matrix {
int a, b, c, d;
public:
Matrix(int a=0, int b=0, int c=0, int d=0) { this->a = a; this->b = b; this->c = c; this->d = d; }
Matrix operator+(Matrix op2);
Matrix operator+=(Matrix op2);
bool operator==(Matrix op2);
void show();
};

Matrix Matrix::operator+(Matrix op2) {
Matrix tmp;
tmp.a = this->a + op2.a;
tmp.b = this->b + op2.b;
tmp.c = this->c + op2.c;
tmp.d = this->d + op2.d;

return tmp;
}

Matrix Matrix::operator+=(Matrix op2) {
a = a + op2.a;
b = b + op2.b;
c = c + op2.c;
d = d + op2.d;

return *this;
}

bool Matrix::operator==(Matrix op2) {
if(a==op2.a && b==op2.b && c==op2.c && d==op2.d) return true;
else false;
}

void Matrix::show() {
cout << "Matrix = { " << a << " " << b << " " << c << " " << d << " }" << endl;
}

int main() {
Matrix a(1,2,3,4), b(2,3,4,5), c;
c = a + b;
a += b;
a.show(); b.show(); c.show();
if(a == c)
cout << "a and c are the same" << endl;
}
*/

/*
4번-2

#include<iostream>
using namespace std;

class Matrix {
int a, b, c, d;
public:
Matrix(int a=0, int b=0, int c=0, int d=0) { this->a = a; this->b = b; this->c = c; this->d = d; }
friend Matrix operator+(Matrix &op1, Matrix op2);
friend Matrix operator+=(Matrix &op1, Matrix op2);
friend bool operator==(Matrix &op1, Matrix op2);
void show();
};

Matrix operator+(Matrix &op1, Matrix op2) {
Matrix tmp;
tmp.a = op1.a + op2.a;
tmp.b = op1.b + op2.b;
tmp.c = op1.c + op2.c;
tmp.d = op1.d + op2.d;

return tmp;
}

Matrix operator+=(Matrix &op1, Matrix op2) {
op1.a = op1.a + op2.a;
op1.b = op1.b + op2.b;
op1.c = op1.c + op2.c;
op1.d = op1.d + op2.d;

return op1;
}

bool operator==(Matrix &op1, Matrix op2) {
if(op1.a==op2.a && op1.b==op2.b && op1.c==op2.c && op1.d==op2.d) return true;
else false;
}

void Matrix::show() {
cout << "Matrix = { " << a << " " << b << " " << c << " " << d << " }" << endl;
}

int main() {
Matrix a(1,2,3,4), b(2,3,4,5), c;
c = a + b;
a += b;
a.show(); b.show(); c.show();
if(a == c)
cout << "a and c are the same" << endl;
}
*/

/*
5번-1

#include<iostream>
using namespace std;

class Matrix {
int a, b, c, d;
public:
Matrix(int a=0, int b=0, int c=0, int d=0) { this->a = a; this->b = b; this->c = c; this->d = d; }
Matrix operator>>(int *x);
Matrix operator<<(int *y);
void show();
};

Matrix Matrix::operator<<(int *y) {
a = y[0];
b = y[1];
c = y[2];
d = y[3];

return *this;
}

Matrix Matrix::operator>>(int *x) {
x[0] = a;
x[1] = b;
x[2] = c;
x[3] = d;

return *this;
}

void Matrix::show() {
cout << "Matrix = { " << a << " " << b << " " << c << " " << d << " }" << endl;
}

int main() {
Matrix a(4,3,2,1), b;
int x[4], y[4] = {1,2,3,4};
a >> x;
b << y;

for(int i=0; i<4; i++) cout << x[i] << ' ';
cout << endl;
b.show();
}
*/

/*
5번-2

#include<iostream>
using namespace std;

class Matrix {
int a, b, c, d;
public:
Matrix(int a=0, int b=0, int c=0, int d=0) { this->a = a; this->b = b; this->c = c; this->d = d; }
friend Matrix operator>>(Matrix &op1, int *x);
friend Matrix operator<<(Matrix &op1, int *y);
void show();
};

Matrix operator<<(Matrix &op1, int *y) {
op1.a = y[0];
op1.b = y[1];
op1.c = y[2];
op1.d = y[3];

return op1;
}

Matrix operator>>(Matrix &op1, int *x) {
x[0] = op1.a;
x[1] = op1.b;
x[2] = op1.c;
x[3] = op1.d;

return op1;
}

void Matrix::show() {
cout << "Matrix = { " << a << " " << b << " " << c << " " << d << " }" << endl;
}

int main() {
Matrix a(4,3,2,1), b;
int x[4], y[4] = {1,2,3,4};
a >> x;
b << y;

for(int i=0; i<4; i++) cout << x[i] << ' ';
cout << endl;
b.show();
}
*/

/*
6번

#include<iostream>
using namespace std;

class Circle {
int radius;
public:
Circle(int radius=0) { this->radius = radius; }
friend Circle operator++(Circle &op1);
friend Circle operator++(Circle &op1, int x);
void show() { cout << "radius = " << radius << " 인 원" << endl; }
};

Circle operator++(Circle &op1) {
op1.radius++;
return op1;
}

Circle operator++(Circle &op1, int x) {
Circle tmp = op1;
op1.radius++;
return tmp;
}

int main() {
Circle a(5), b(4);
++a;;
b = a++;
a.show();
b.show();
}
*/

/*
7번*/

#include<iostream>
using namespace std;

class Statistics {
	int *a;
	int size;
public:
	Statistics() { a = new int[6]; size = 0; }
	bool operator!();
	void operator>>(int &op1);
	Statistics &operator<<(int op1);
	void operator~();
};

bool Statistics::operator!() {
	if (a == NULL) return true;
	else false;
}

void Statistics::operator>>(int &op1) {
	int i, sum = 0;

	for (i = 0; i<size; i++) {
		sum = sum + a[i];
	}
	op1 = sum / size;
}

Statistics &Statistics::operator<<(int op1) {
	a[size] = op1;
	size++;

	return *this;
};

void Statistics::operator~() {
	for (int i = 0; i<size; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
	Statistics stat;
	if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;

	int x[5];
	cout << "5 개의 정수를 입력하라>>";
	for (int i = 0; i<5; i++) cin >> x[i];

	for (int i = 0; i<5; i++) stat << x[i];
	stat << 100 << 200;
	~stat;

	int avg;
	stat >> avg;
	cout << "avg=" << avg << endl;
}