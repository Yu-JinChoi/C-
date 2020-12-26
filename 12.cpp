/*
1�� ���� 12-1

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char name[10], dept[20];
	int sid;

	cout << "�̸�>>";
	cin >> name;
	cout << "�й�(���ڷ�)>>";
	cin >> sid;
	cout << "�а�>>";
	cin >> dept;

	ofstream fout("c:\\student.txt");
	if(!fout) {
		cout << "c:\\student.txt ������ �� �� ����";
		return 0;
	}

	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;

	fout.close();
}
*/

/*
1�� ���� 12-2

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ifstream fin;
	fin.open("c:\\student.txt");
	if(!fin) {
		cout << "������ �� �� ����";
		return 0;
	}

	char name[10], dept[20];
	int sid;

	fin >> name;
	fin >> sid;
	fin >> dept;

	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;

	fin.close();
}
*/

/*
1�� ���� 12-3

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char* file = "c:\\windows\\system.ini";
	ifstream fin(file);
	if(!fin) {
		cout << file << "���� ����" << endl;
		return 0;
	}
	int count = 0;
	int c;
	while((c=fin.get()) != EOF) {
		cout << (char)c;
		count++;
	}

	cout << "���� ����Ʈ ���� " << count << endl;
	fin.close();
}
*/

/*
1�� ���� 12-4

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char* firstFile = "c:\\student.txt";
	char* secondFile = "c:\\windows\\system.ini";

	fstream fout(firstFile, ios::out | ios::app);
	if(!fout) {
		cout << firstFile << " ���� ����";
		return 0;
	}

	fstream fin(secondFile, ios::in);
	if(!fin) {
		cout << secondFile << " ���� ����";
		return 0;
	}

	int c;
	while((c=fin.get()) != EOF) {
		fout.put(c);
	}

	fin.close();
	fout.close();
}
*/

/*
1�� ���� 12-5

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini");
	if(!fin) {
		cout << "c:\\windows\\system.ini ���� ����" << endl;
		return 0;
	}

	char buf[81];
	while(true) {
		fin.getline(buf, 81);
		if(fin.eof()) break;
		cout << buf << endl;
	}

	fin.close();
}
*/

/*
1�� ���� 12-6

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

void fileRead(vector<string> &v, ifstream &fin) {
	string line;
	while(true) {
		getline(fin, line);
		if(fin.eof()) break;
		v.push_back(line);
	}
}

void search(vector<string> &v, string word) {
	for(int i=0; i<v.size(); i++) {
		int index = v[i].find(word);
		if(index != -1)
			cout << v[i] << endl;
	}
}

int main() {
	vector<string> wordVector;
	ifstream fin("words.txt");
	if(!fin) {
		cout << "words.txt ������ �� �� �����ϴ�" << endl;
		return 0;
	}
	fileRead(wordVector, fin);
	fin.close();

	cout << "words.txt ������ �о����ϴ�." << endl;
	while(true) {
		cout << "�˻��� �ܾ �Է��ϼ��� >>";
		string word;
		getline(cin, word);
		if(word == "exit")
			break;
		search(wordVector, word);
	}
	cout << "���α׷��� �����մϴ�." << endl;
}
*/

/*
1�� ���� 12-7

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char* srcFile = "c:\\users\\public\\pictures\\sample pictures\\desert.jpg";
	char* destFile = "c:\\copydesert.jpg";

	ifstream fsrc(srcFile, ios::in | ios::binary);
	if(!fsrc) {
		cout << srcFile << " ���� ����" << endl;
		return 0;
	}

	ofstream fdest(destFile, ios::out | ios::binary);
	if(!fdest) {
		cout << destFile << " ���� ����" << endl;
		return 0;
	}

	int c;
	while((c=fsrc.get()) != EOF) {
		fdest.put(c);
	}
	cout << srcFile << "�� " << destFile << "�� ���� �Ϸ�" << endl;
	fsrc.close();
	fdest.close();
}
*/

/*
1�� ���� 12-8

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char* file = "c:\\windows\\system.ini";

	ifstream fin;
	fin.open(file, ios::in | ios::binary);
	if(!fin) {
		cout << "���� ���� ����";
		return 0;
	}

	int count = 0;
	char s[32];
	while(!fin.eof()) {
		fin.read(s, 32);
		int n = fin.gcount();
		cout.write(s, n);
		count += n;
	}

	cout << "���� ����Ʈ ���� " << count << endl;
	fin.close();
}
*/

/*
1�� ���� 12-9

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char* srcFile = "c:\\users\\public\\pictures\\sample pictures\\tulips.jpg";
	char* destFile = "c:\\copytulips.jpg";

	ifstream fsrc(srcFile, ios::in | ios::binary);
	if(!fsrc) {
		cout << srcFile << " ���� ����" << endl;
		return 0;
	}

	ofstream fdest(destFile, ios::out | ios::binary);
	if(!fdest) {
		cout << destFile << " ���� ����" << endl;
		return 0;
	}

	char buf[1024];
	while(!fsrc.eof()) {
		fsrc.read(buf, 1024);
		int n = fsrc.gcount();
		fdest.write(buf, n);
	}
	cout << srcFile << "�� " << destFile << "�� ���� �Ϸ�" << endl;
	fsrc.close();
	fdest.close();
}
*/

/*
1�� ���� 12-10

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char* file = "c://data.dat";

	ofstream fout;
	fout.open(file, ios::out | ios::binary);
	if(!fout) {
		cout << "���� ���� ����";
		return 0;
	}

	int n[] = {0,1,2,3,4,5,6,7,8,9};
	double d = 3.15;
	fout.write((char*)n, sizeof(n));
	fout.write((char*)(&d), sizeof(d));
	fout.close();

	for(int i=0; i<10; i++) n[i]=99;
	d = 8.15;

	ifstream fin(file, ios::in);
	if(!fin) {
		cout << "���� ���� ����";
		return 0;
	}

	fin.read((char*)n, sizeof(n));
	fin.read((char*)(&d), sizeof(d));

	for(int i=0; i<10; i++)
		cout << n[i] << ' ';
	cout << endl << d << endl;
	fin.close();
}
*/

/*
1�� ���� 12-11

#include<iostream>
#include<fstream>
using namespace std;

void showStreamState(ios& stream) {
	cout << "eof() " << stream.eof() << endl;
	cout << "fail() " << stream.fail() << endl;
	cout << "bad() " << stream.bad() << endl;
	cout << "good()" << stream.good() << endl;
}

int main() {
	char* noExistFile = "c:\\noexist.txt";
	char* existFile = "c:\\student.txt";

	ifstream fin(noExistFile);
	if(!fin) {
		cout << noExistFile << " ���� ����" << endl;
		showStreamState(fin);

		cout << existFile << " ���� ����" << endl;
		fin.open(existFile);
		showStreamState(fin);
	}

	int c;
	while((c=fin.get()) != EOF)
		cout.put((char)c);

	cout << endl;
	showStreamState(fin);

	fin.close();
}
*/

/*
1�� ���� 12-12

#include<iostream>
#include<fstream>
using namespace std;

long getFileSize(ifstream& fin) {
	fin.seekg(0, ios::end);
	long length = fin.tellg();
	return length;
}

int main() {
	char* file = "c:\\windows\\system.ini";

	ifstream fin(file);
	if(!fin) {
		cout << file << " ���� ����" << endl;
		return 0;
	}
	cout << file << "�� ũ��� " << getFileSize(fin);
	fin.close();
}
*/

/*
2��

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ifstream fin;
	fin.open("c:\\test.txt");
	if(!fin) {
		cout << "������ �� �� ����";
		return 0;
	}

	char name[10];
	int num;

	fin >> num;
	fin >> name;

	cout << num << endl;
	cout << name << endl;

	fin.close();
}
*/

/*
3��

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ifstream fin;
	fin.open("c:\\test.txt");
	if(!fin) {
		cout << "������ �� �� ����";
		return 0;
	}

	char name[10];

	fin >> name;

	for(int i=0; name[i] != '0'; i++) {
		if(name[i] >= 'a' && name[i] <= 'z') {
			name[i] = name[i] - 32;
		}
	}

	ofstream fout("c:\\windows\\system.ini");
	fout << name << endl;
	cout << name << endl;
}
*/

/*
4��*/

#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char* srcFile = "c:\\windows\\system.ini";
	char* destFile = "c:\\system.txt";

	ifstream fsrc(srcFile, ios::in | ios::binary);
	if(!fsrc) {
		cout << srcFile << " ���� ����" << endl;
		return 0;
	}

	ofstream fdest(destFile, ios::out | ios::binary);
	if(!fdest) {
		cout << destFile << " ���� ����" << endl;
		return 0;
	}

	char buf[1024];
	while(!fsrc.eof()) {
		fsrc.read(buf, 1024);
		int n = fsrc.gcount();
		if(n%10 == 0) {
			cout << ".21B " << n << "%" << endl;
		}

	}

	cout << srcFile << "�� " << destFile << "�� ���� �Ϸ�" << endl;
	fsrc.close();
	fdest.close();
}