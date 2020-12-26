/*
1�� ���� 4-1

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
1�� ���� 4-2

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
		cout << "Circle " << i << "�� ������ " << circleArray[i].getArea() << endl;

	Circle *p;
	p = circleArray;
	for(int i=0; i<3; i++) {
		cout << "Circle " << i << "�� ������ " << p->getArea() << endl;
		p++;
	}
}
*/

/*
1�� ���� 4-3

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
		cout << "Circle " << i << "�� ������ " << circleArray[i].getArea() << endl;
}
*/

/*
1�� ���� 4-4

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
			cout << "Circle [" << i << "," << j << "]�� ������ ";
			cout << circles[i][j].getArea() << endl;
		}
}
*/

/*
1�� ���� 4-5

#include<iostream>
using namespace std;

int main() {
	int *p;

	p = new int;
	if(!p) {
		cout << "�޸𸮸� �Ҵ��� �� �����ϴ�.";
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
1�� ���� 4-6

#include<iostream>
using namespace std;

int main() {
	cout << "�Է��� ������ ������?";
	int n;
	cin >> n;
	if( n <= 0) return 0;
	int *p = new int[n];
	if(!p) {
		cout << "�޸𸮸� �Ҵ��� �� �����ϴ�.";
		return 0;
	}

	for(int i=0; i<n; i++) {
		cout << i+1 << "��° ����: ";
		cin >> p[i];
	}

	int sum = 0;
	for(int i=0; i<n; i++)
		sum += p[i];
	cout << "��� = " << sum/n << endl;

	delete [] p;
}
*/

/*
1�� ���� 4-7

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
	cout << "������ ���� radius = " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "������ ���� radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "�Ҹ��� ���� radius = " << radius << endl;
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
1�� ���� 4-8

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
	cout << "������ ���� radius = " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "������ ���� radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "�Ҹ��� ���� radius = " << radius << endl;
}

int main() {
	int radius;
	while(true) {
		cout << "���� ������ �Է�(�����̸� ����)>> ";
		cin >> radius;
		if(radius < 0) break;
		Circle *p = new Circle(radius);
		cout << "���� ������ " << p->getArea() << endl;
		delete p;
	}
}
*/

/*
1�� ���� 4-9

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
	cout << "������ ���� radius = " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "������ ���� radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "�Ҹ��� ���� radius = " << radius << endl;
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
1�� ���� 4-10

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
	cout << "�����ϰ��� �ϴ� ���� ����?";
	int n, radius;
	cin >> n;
	if(n <= 0) return 0;
	Circle *pArray = new Circle [n];
	for(int i=0; i<n; i++) {
		cout << "��" << i+1 << ": ";
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
	cout << endl << "������ 100���� 200 ������ ���� ������ " << count << endl;
	delete [] pArray;
}
*/

/*
1�� ���� 4-11

#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	string address("����� ���ϱ� �Ｑ�� 389");
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
1�� ���� 4-12

#include<iostream>
#include<string>
using namespace std;

int main() {
	string names[5];

	for(int i=0; i<5; i++) {
		cout << "�̸� >> ";
		getline(cin, names[i], '\n');
	}

	string latter = names[0];
	for(int i=1; i<5; i++) {
		if(latter < names[i]) {
			latter = names[i];
		}
	}
	cout << "�������� ���� �ڿ� ������ ���ڿ��� " << latter << endl;
}
*/

/*
1�� ���� 4-13

#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;

	cout << "�Ʒ��� ���ڿ��� �Է��ϼ���. �� ĭ�� �־ �˴ϴ�.(�ѱ� �ȵ�) " << endl;
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
1�� ���� 4-14

#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cout << "7+23+5+100+25�� ���� ���� ���ڿ��� �Է��ϼ���." << endl;
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
	cout << "���ڵ��� ���� " << sum;
}
*/

/*
1�� ���� 4-15

#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cout << "���� ���� ���ڿ��� �Է��ϼ���. �Է��� ���� &�����Դϴ�." << endl;
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
2��

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
	cout << "���� ū ���� " << s.big() << endl;
}
*/

/*
3��

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	int len;
	int i;

	cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)" << endl;

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
4��

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

	cout << name << "������ ������ ���� " << size << "�� �Դϴ�." << endl;

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
5��

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
		cout << "�� " << i + 1 << "�� �̸��� ������ >>";
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

	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
	cin >> search;

	for (i = 0; i < size; i++) {
		if (p[i].getName() == search)
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << endl;
	}
}

void CircleManager::searchByArea() {
	int min, i, radius;
	string name;

	cout << "�ּ� ������ ������ �Է��ϼ��� >>";
	cin >> min;
	cout << min << "���� ū ���� �˻��մϴ�." << endl;

	for (i = 0; i < size; i++) {
		if (p[i].getArea() >= min)
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << ", ";
	}
	cout << endl;
}

int main()
{
	int n;

	cout << "���� ���� >>";
	cin >> n;

	CircleManager *c = new CircleManager(n);
	c->searchByName();
	c->searchByArea();
}
*/

/*
6��*/

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

	cout << "***** ���� ������ �����մϴ�. *****" << endl;
	cout << "ù��° ���� �̸�>>";
	cin >> name;
	p[0].setName(name);
	cout << "�ι�° ���� �̸�>>";
	cin >> name;
	p[1].setName(name);
	cout << "������ ������ ������ �Ͻðڽ��ϱ�?(2, 3, 4 �߿� ����ּ���) : ";
	cin >> n;

	string s;
	for (i = 0; ; i++) {
		cout << p[i % 2].getName() << "<Enter>";
		getline(cin, s, '\n');
		cout << endl;
		g.setCard(n);
		if (g.GameTrue()) {
			cout << "\t" << p[i % 2].getName() << "�� �¸� !!";
			break;
		}
		else
			cout << "\t" << "�ƽ����� !" << endl;
	}
}