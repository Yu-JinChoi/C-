/*
1번 예제 4-1

#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle donut;
	Circle pizza(30);

	cout << donut.getArea() << endl;

	Circle *p;
	p = &donut;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;

	p = &pizza;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;
}
*/

/*
1번 예제 4-2

#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle circleArray[3];

	circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);

	for(int i=0; i<3; i++)
		cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;

	Circle *p;
	p = circleArray;
	for(int i=0; i<3; i++) {
		cout << "Circle " << i << "의 면적은 " << p->getArea() << endl;
		p++;
	}
}
*/

/*
1번 예제 4-3

#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle circleArray[3] = { Circle(10), Circle(20), Circle() };

	for(int i=0; i<3; i++)
		cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;
}
*/

/*
1번 예제 4-4

#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle circles[2][3];
	
	circles[0][0].setRadius(1);
	circles[0][1].setRadius(2);
	circles[0][2].setRadius(3);
	circles[1][0].setRadius(4);
	circles[1][1].setRadius(5);
	circles[1][2].setRadius(6);

	for(int i=0; i<2; i++)
		for(int j=0; j<3; j++) {
			cout << "Circle [" << i << "," << j << "]의 면적은 ";
			cout << circles[i][j].getArea() << endl;
		}
}
*/

/*
1번 예제 4-5

#include<iostream>
using namespace std;

int main() {
	int *p;

	p = new int;
	if(!p) {
		cout << "메모리를 할당할 수 없습니다.";
		return 0;
	}

	*p = 5;
	int n = *p;
	cout << "*p = " << *p << endl;
	cout << "n = " << n << endl;

	delete p;
}
*/

/*
1번 예제 4-6

#include<iostream>
using namespace std;

int main() {
	cout << "입력할 정수의 개수는?";
	int n;
	cin >> n;
	if( n <= 0) return 0;
	int *p = new int[n];
	if(!p) {
		cout << "메모리를 할당할 수 없습니다.";
		return 0;
	}

	for(int i=0; i<n; i++) {
		cout << i+1 << "번째 정수: ";
		cin >> p[i];
	}

	int sum = 0;
	for(int i=0; i<n; i++)
		sum += p[i];
	cout << "평균 = " << sum/n << endl;

	delete [] p;
}
*/

/*
1번 예제 4-7

#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14*radius*radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
}

int main() {
	Circle *p, *q;
	p = new Circle;
	q = new Circle(30);
	cout << p->getArea() << endl << q->getArea() << endl;
	delete p;
	delete q;
}
*/

/*
1번 예제 4-8

#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14*radius*radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
}

int main() {
	int radius;
	while(true) {
		cout << "정수 반지름 입력(음수이면 종료)>> ";
		cin >> radius;
		if(radius < 0) break;
		Circle *p = new Circle(radius);
		cout << "원의 면적은 " << p->getArea() << endl;
		delete p;
	}
}
*/

/*
1번 예제 4-9

#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14*radius*radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
}

int main() {
	Circle *pArray = new Circle[3];

	pArray[0].setRadius(10);
	pArray[1].setRadius(20);
	pArray[2].setRadius(30);

	for(int i=0; i<3; i++) {
		cout << pArray[i].getArea() << endl;
	}
	Circle *p = pArray;
	for(int i=0; i<3; i++) {
		cout << p->getArea() << endl;
		p++;
	}

	delete [] pArray;
}
*/

/*
1번 예제 4-10

#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	~Circle() { }
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14*radius*radius; }
};

Circle::Circle() {
	radius = 1;
}

int main() {
	cout << "생성하고자 하는 원의 개수?";
	int n, radius;
	cin >> n;
	if(n <= 0) return 0;
	Circle *pArray = new Circle [n];
	for(int i=0; i<n; i++) {
		cout << "원" << i+1 << ": ";
		cin >> radius;
		pArray[i].setRadius(radius);
	}
	int count = 0;
	Circle* p = pArray;
	for(int i=0; i<n; i++) {
		cout << p->getArea() << ' ';
		if(p->getArea() >= 100 && p->getArea() <= 200)
			count++;
		p++;
	}
	cout << endl << "면적이 100에서 200 사이인 원의 개수는 " << count << endl;
	delete [] pArray;
}
*/

/*
1번 예제 4-11

#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	string address("서울시 성북구 삼선동 389");
	string copyAddress(address);

	char text[] = {'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0'};
	string title(text);

	cout << str << endl;
	cout << address << endl;
	cout << copyAddress << endl;
	cout << title << endl;
}
*/

/*
1번 예제 4-12

#include<iostream>
#include<string>
using namespace std;

int main() {
	string names[5];

	for(int i=0; i<5; i++) {
		cout << "이름 >> ";
		getline(cin, names[i], '\n');
	}

	string latter = names[0];
	for(int i=1; i<5; i++) {
		if(latter < names[i]) {
			latter = names[i];
		}
	}
	cout << "사전에서 가장 뒤에 나오는 문자열은 " << latter << endl;
}
*/

/*
1번 예제 4-13

#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;

	cout << "아래에 문자열을 입력하세요. 빈 칸이 있어도 됩니다.(한글 안됨) " << endl;
	getline(cin, s, '\n');
	int len = s.length();

	for(int i=0; i<len; i++) {
		string first = s.substr(0, 1);
		string sub = s.substr(1, len-1);
		s = sub + first;
		cout << s << endl;
	}
}
*/

/*
1번 예제 4-14

#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요." << endl;
	getline(cin, s, '\n');
	int sum = 0;
	int startIndex = 0;
	while(true) {
		int fIndex = s.find('+', startIndex);
		if(fIndex == -1) {
			string part = s.substr(startIndex);
			if(part == "") break;
			cout << part << endl;
			sum += stoi(part);
			break;
		}
		int conut = fIndex - startIndex;
		string part = s.substr(startIndex, conut);

		cout << part << endl;
		sum += stoi(part);
		startIndex = fIndex+1;
	}
	cout << "숫자들의 합은 " << sum;
}
*/

/*
1번 예제 4-15

#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cout << "여러 줄의 문자열을 입력하세요. 입력의 끝은 &문자입니다." << endl;
	getline(cin, s, '&');
	cin.ignore();

	string f, r;
	cout << endl << "find: ";
	getline(cin, f, '\n');
	cout << "replace: ";
	getline(cin, r, '\n');

	int startIndex = 0;
	while(true) {
		int fIndex = s.find(f, startIndex);
		if(fIndex == -1)
			break;
		s.replace(fIndex, f.length(), r);
		startIndex = fIndex + r.length();
	}
	cout << s << endl;
}
*/

/*
2번

#include<iostream>
using namespace std;

class Sample {
	int *p;
	int size;
public:
	Sample(int n) {
		size = n; p = new int [n];
	}
	void read();
	void write();
	int big();
	~Sample();
};

void Sample::read() {

	for(int i=0; i<10; i++) {
		cin >> p[i];
	}
}

void Sample::write() {
	
	for(int i=0; i<10; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}

int Sample::big() {

	int max =0;

	for(int i=0; i<10; i++) {

		if(p[i] >= max) max = p[i];
	}

	return max;
}

Sample::~Sample() {}

int main() {
	Sample s(10);
	s.read();
	s.write();
	cout << "가장 큰 수는 " << s.big() << endl;
}
*/

/*
3번

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	int len;
	int i;

	cout << "아래의 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;

	while (1) {
		cout << ">>";
		getline(cin, str, '\n');

		if (str._Equal("exit")) break;
		len = str.length();

		for (i = len; i >= 0; i--) {
			cout << str[i];
		}



		cout << endl;
	}

	return 0;
}
*/

/*
4번

#include<iostream>
#include<string>
using namespace std;

class Person {
	string name;
public:
	Person() {}
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};

class Family {
	Person *p;
	int size;
	string name;
public:
	Family(string name, int size);
	void show();
	~Family();
	void setName(int i, string name);
};

Family::Family(string name, int size) {
	this->name = name;
	this->size = size;
	p = new Person[size];
}

void Family::setName(int i, string name) {
	p[i].setName(name);
}

void Family::show() {
	int i;

	cout << name << "가족은 다음과 같이 " << size << "명 입니다." << endl;

	for (i = 0; i < size; i++) {
		cout << p[i].getName() << '\t';
	}
	cout << endl;
}

Family::~Family() {
	delete[] p;
}

int main()
{
	Family *simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
}
*/

/*
5번

#include<iostream>
#include<string>
using namespace std;

class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius);
	double getArea();
	string getName();
};

class CircleManager {
	Circle *p;
	int size;
public:
	CircleManager(int size);
	~CircleManager();
	void searchByName();
	void searchByArea();
};

void Circle::setCircle(string name, int radius) {
	this->name = name;
	this->radius = radius;
}

double Circle::getArea() {
	return 3.14*radius*radius;
}

string Circle::getName() {
	return name;
}

CircleManager::CircleManager(int size) {
	int i, radius;
	string name;

	p = new Circle[size];
	this->size = size;

	for (i = 0; i < size; i++) {
		cout << "원 " << i + 1 << "의 이름과 반지름 >>";
		cin >> name >> radius;
		p[i].setCircle(name, radius);
	}
}

CircleManager::~CircleManager() {
	delete[] p;
}

void CircleManager::searchByName() {
	string search;
	int i;

	cout << "검색하고자 하는 원의 이름 >> ";
	cin >> search;

	for (i = 0; i < size; i++) {
		if (p[i].getName() == search)
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
	}
}

void CircleManager::searchByArea() {
	int min, i, radius;
	string name;

	cout << "최소 면적을 정수로 입력하세요 >>";
	cin >> min;
	cout << min << "보다 큰 원을 검색합니다." << endl;

	for (i = 0; i < size; i++) {
		if (p[i].getArea() >= min)
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ", ";
	}
	cout << endl;
}

int main()
{
	int n;

	cout << "원의 개수 >>";
	cin >> n;

	CircleManager *c = new CircleManager(n);
	c->searchByName();
	c->searchByArea();
}
*/

/*
6번*/

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

class Player {
	string name;
public:
	void setName(string name);
	string getName();
};

class GamblingGame {
	Player *p;
	int card[3];
public:
	void setCard(int n);
	bool GameTrue();
	GamblingGame();
	~GamblingGame();
};

void Player::setName(string name) {
	this->name = name;
}

string Player::getName() {
	return name;
}

GamblingGame::GamblingGame() {
	srand((unsigned)time(NULL));
}

void GamblingGame::setCard(int n) {
	int i;

	for (i = 0; i < 3; i++) {
		card[i] = rand() % (n + 1);
	}
	cout << "\t" << card[0] << "\t" << card[1] << "\t" << card[2];
}

GamblingGame::~GamblingGame() {
	delete[] p;
}

bool GamblingGame::GameTrue() {
	if (card[0] == card[1] && card[0] == card[2])
		return true;
	else return false;
}

int main()
{
	int i, n;
	Player *p = new Player[2];
	GamblingGame g;
	string name;

	cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
	cout << "첫번째 선수 이름>>";
	cin >> name;
	p[0].setName(name);
	cout << "두번째 선수 이름>>";
	cin >> name;
	p[1].setName(name);
	cout << "숫자의 범위는 몇으로 하시겠습니까?(2, 3, 4 중에 골라주세요) : ";
	cin >> n;

	string s;
	for (i = 0; ; i++) {
		cout << p[i % 2].getName() << "<Enter>";
		getline(cin, s, '\n');
		cout << endl;
		g.setCard(n);
		if (g.GameTrue()) {
			cout << "\t" << p[i % 2].getName() << "님 승리 !!";
			break;
		}
		else
			cout << "\t" << "아쉽군요 !" << endl;
	}
}