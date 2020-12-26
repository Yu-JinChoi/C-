/*
1번 예제 11-1

#include<iostream>
using namespace std;

int main() {
	cout.put('H');
	cout.put('i');
	cout.put(33);
	cout.put('\n');

	cout.put('C').put('+').put('+').put(' ' );

	char str[] = "I love programming";
	cout.write(str, 6);
}
*/

/*
1번 예제 11-2

#include<iostream>
using namespace std;

void get1() {
	cout << "cin.get()로 <Enter> 키까지 입력받고 출력합니다>>";
	int ch;
	while((ch = cin.get()) != EOF) {
		cout.put(ch);
		if(ch == '\n')
			break;
	}
}

void get2() {
	cout << "cin.get(char&)로 <Enter> 키까지 입력 받고 출력합니다>>";
	char ch;
	while(true) {
		cin.get(ch);
		if(cin.eof()) break;
		cout.put(ch);
		if(ch == '\n')
			break;
	}
}

int main() {
	get1();
	get2();
}
*/

/*
1번 예제 11-3

#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char cmd[80];
	cout << "cin.get(char*, int)로 문자열을 읽습니다." << endl;
	while(true) {
		cout << "종료하려면 exit을 입력하세요 >> ";
		cin.get(cmd, 80);
		if(strcmp(cmd, "exit") == 0) {
			cout << "프로그램을 종료합니다....";
			return 0;
		}
		else
			cin.ignore(1);
	}
}
*/

/*
1번 예제 11-4

#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char line[80];
	cout << "cin.getline() 함수로 라인을 읽습니다." << endl;
	cout << "exit을 입력하면 루프가 끝납니다." << endl;
	int no = 1;
	while(true) {
		cout << "라인 " << no << " >> " ;
		cin.getline(line, 80);
		if(strcmp(line, "exit") == 0)
			break;
		cout << "echo --> ";
		cout << line << endl;
		no++;
	}
}
*/

/*
1번 예제 11-5

#include<iostream>
using namespace std;

int main() {
	cout << 30 << endl;

	cout.unsetf(ios::dec);
	cout.setf(ios::hex);
	cout << 30 << endl;

	cout.setf(ios::showbase);
	cout << 30 << endl;

	cout.setf(ios::uppercase);
	cout << 30 << endl;

	cout.setf(ios::dec | ios::showpoint);

	cout << 23.5 << endl;

	cout.setf(ios::scientific);
	cout << 23.5 << endl;

	cout.setf(ios::showpos);
	cout << 23.5;
}
*/

/*
1번 예제 11-6

#include<iostream>
using namespace std;

void showWidth() {
	cout.width(10);
	cout << "Hello" << endl;
	cout.width(5);
	cout << 12 << endl;

	cout << '%';
	cout.width(10);
	cout << "Korea/" << "Seoul/" << "City" << endl;
}

int main() {
	showWidth();
	cout << endl;

	cout.fill('^');
	showWidth();
	cout << endl;

	cout.precision(5);
	cout << 11./3. << endl;
}
*/

/*
1번 예제 11-7

#include<iostream>
using namespace std;

int main() {
	cout << hex << showbase << 30 << endl;
	cout << dec << showpos << 100 << endl;
	cout << true << ' ' << false << endl;
	cout << boolalpha << true << ' ' << false << endl;
}
*/

/*
1번 예제 11-8

#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	cout << showbase;

	cout << setw(8) << "Number";
	cout << setw(10) << "Octal";
	cout << setw(10) << "Hexa" << endl;

	for(int i=0; i<50; i+=5) {
		cout << setw(8) << setfill('.') << dec << i;
		cout << setw(10) << setfill(' ') << oct << i;
		cout << setw(10) << setfill(' ') << hex << i << endl;
	}
}
*/

/*
1번 예제 11-9

#include<iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x=0, int y=0) {
		this->x = x;
		this->y = y;
	}
	friend ostream& operator << (ostream& stream, Point a);
};

ostream& operator << (ostream& stream, Point a) {
	stream << "(" << a.x << "," << a.y << ")";
	return stream;
}

int main() {
	Point p(3,4);
	cout << p << endl;

	Point q(1,100), r(2,200);
	cout << q << r << endl;
}
*/

/*
1번 예제 11-10

#include<iostream>
#include<string>
using namespace std;

class Book {
	string title;
	string press;
	string author;
public:
	Book(string title="", string press="", string author="") {
		this->title = title;
		this->press = press;
		this->author = author;
	}
	friend ostream& operator << (ostream& stream, Book b);
};

ostream& operator << (ostream& stream, Book b) {
	stream << b.title << "," << b.press << "," << b.author;
	return stream;
}

int main() {
	Book book("소유냐 존재냐", "한국출판사", "에리히프롬");
	cout << book;
}
*/

/*
1번 예제 11-11

#include<iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x=0, int y=0) {
		this->x = x;
		this->y = y;
	}
	friend istream& operator >> (istream& ins, Point &a);
	friend ostream& operator << (ostream& stream, Point a);
};

istream& operator >> (istream& ins, Point &a) {
	cout << "x 좌표>>";
	ins >> a.x;
	cout << "y 좌표>>";
	ins >> a.y;
	return ins;
}

ostream& operator << (ostream& stream, Point a) {
	stream << "(" << a.x << "," << a.y << ")";
	return stream;
}

int main() {
	Point p;
	cin >> p;
	cout << p;
}
*/

/*
1번 예제 11-12

#include<iostream>
using namespace std;

ostream& fivestar(ostream& outs) {
	return outs << "*****";
}

ostream& rightarrow(ostream& outs) {
	return outs << "---->";
}

ostream& beep(ostream& outs) {
	return outs << '\a';
}

int main() {
	cout << "벨이 울립니다" << beep << endl;
	cout << "C" << rightarrow << "C++" << rightarrow << "Java" << endl;
	cout << "Visual" << fivestar << "C++" << endl;
}
*/

/*
1번 예제 11-13

#include<iostream>
#include<string>
using namespace std;

istream& question(istream& ins) {
	cout << "거울아 거울아 누가 제일 예쁘니?";
	return ins;
}

int main() {
	string answer;
	cin >> question >> answer;
	cout << "세상에서 제일 예쁜 사람은 " << answer << "입니다." << endl;
}
*/

/*
2번

#include<iostream>
using namespace std;

int main() {
	char ch[100];
	int t=0;

	cin.get(ch, 100);
	for(int i=0; ch[i] != '\0'; i++) {
		if(ch[i] == 'a') t++;
	}

	cout << "a의 개수는 " << t << "개 입니다." << endl;
}
*/

/*
3번

#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char cmd[80];
	while(true) {
		cin.ignore(80, ';');
		cin.get(cmd, 80);
		for(int i=0; cmd[i] != '\0'; i++) {
			cout << cmd[i];
		}
		if(cin.eof()) {
			break;
		}
	}
}
*/

/*
4번

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main() {
	cout << left;

	cout << setw(15) << "Number";
	cout << setw(15) << "Square";
	cout << setw(15) << "Square Root" << endl;

	for(int i=0; i<50; i+=5) {
		cout << setfill('_') << setw(15) << i << setfill('_');
		cout << setw(15) << i*i << setfill('_');
		cout.precision(3);
		cout << setw(15) << sqrt((double)i) << setfill('_') << endl;
	}
}
*/

/*
5번

#include<iostream>
#include<string>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius=1, string name="") {
		this->radius = radius; this->name = name;
	}
	friend istream& operator >> (istream& ins, Circle &a);
	friend ostream& operator << (ostream& stream, Circle &a);
};

istream& operator >> (istream& ins, Circle &a) {
	cout << "반지름 >> ";
	ins >> a.radius;

	cout << "이름 >> ";
	ins >> a.name;

	return ins;
}

ostream& operator << (ostream& stream, Circle &a) {
	stream << "(반지름" << a.radius << "인 " << a.name << ")";

	return stream;
}

int main() {
	Circle d, w;
	cin >> d >> w;
	cout << d << w << endl;
}
*/

/*
6번*/

#include<iostream>
using namespace std;

istream& pos(istream& ins) {
	cout << "위치는? ";
	return ins;
}

int main() {
	int x, y;
	cin >> pos >> x;
	cin >> pos >> y;
	cout << x << ',' << y << endl;
}