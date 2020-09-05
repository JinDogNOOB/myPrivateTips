 // c++������ ���� ������� ǥ�� ����°� ������ ������� �Ͼ .


// ����ü ������ ���� ����Ϳ� ����ϱ�
/*
#include <iostream>
using namespace std;

struct insa {
	char name[20];
	int age;
	char address[20];
};

void main()
{
	insa man = { "������",20,"����" };
	
	cout << man.name << "::" << man.age << "::" << man.address << endl;
}
*/


/*
ofstream fout; ��½�Ʈ���� �����ϱ� ���� ��ü�� �����Ѵ�.
fout.open("insa.dat"); Ư�� ������ �����Ѵ�.
fout<<man.name<< ���ش�. 
fout.close(); ������ ������ �ݴ´�.
*/
// �̰Ÿ� ���Ϸ� �����ҷ���
// ��½�Ʈ���� �����ϱ� ���� ��ü�� �����ؾ��Ѵ�.

/*
#include <iostream>
#include <fstream> // fstream �� ���Խ��Ѿ��Ѵ�  

using namespace std;

struct insa {
	char name[20];
	char age;
	char address[20];
};

void main()
{
	insa man = { "������", 20, "�ϱ�" };

	ofstream fout;
	// ǥ������� �����̹Ƿ� << �� ��ӵȴ�.
	fout.open("insa.dat");
	//������ C:\Users\yck\source\repos\ProjectCPP\ProjectCPP �ش� ������Ʈ ������ ������.
	fout << man.name << "::" << man.age << "::" << man.address << endl;
	fout.close();
}
*/






// ���� �Է��� �ϵ��ũ�κ��� �޸𸮷� �Է��ؾ��ϳ��״��� ��ư ���������� ����
/*
#include <iostream>
#include <fstream>
using namespace std;

struct insa{
	char name[20];
	char age;
	char address[20];
};

void main()
{
	insa man = { "null", 0 , "null" };
	
	ifstream fin; // �Է½�Ʈ���� �����ϱ����Ѱ�ü ����

	fin.open("C:\\test\\insa.dat"); 
	
	if (fin.fail()) {
		cout << "���¿� �����߽��ϴ�." << endl;
		return;
	}
	
	fin >> man.name >> man.age >> man.address; // �������� �����͸� �������µ�.
	cout << man.name << " " << man.age << " " << man.address << endl;
	cout << man.name << endl;
	cout << man.age << endl;
	cout << man.address << endl;
	fin.close();
	
}
*/



// �Լ��� �̿��� ���� ����� <<>> ���� get �̶� put

/*
#include <iostream>
#include <fstream>
using namespace std;


void main()
{
	char ch;
	while (cin.get(ch)) {
		cout.put(ch);
	}
}
*/


/*

#include <iostream>
#include <fstream>
using namespace std;

void main()
{

	char ch;

	ofstream fout;

	fout.open("test.dat");
	
	while (cin.get(ch)) {
		fout.put(ch);
	}  
	fout.close();
}


*/

//���� ���� ���¸� �о���� get�� ostreamŬ������ ����Լ� �߿��� ���� �� ���� ����ϱ� ���� put�Լ�
/*
#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	char ch;
	
	ofstream fout;

	fout.open("test.dat");
	if (fout.fail()) {
		cout << "file open failure" << endl;
		return;
	}
	while (cin.get(ch)) {
		fout.put(ch);
	}

	fout.close();
	
}
*/



/*
//���� ������ ���Ͽ��� �Է¹ޱ�
#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	char ch;
	ifstream fin;
	fin.open("test.dat");
	if (fin.fail()) {
		cout << "fin.open() failure" << endl;
		return;
	}
	while (fin.get(ch)) {
		cout.put(ch); // cout.put() ǲ�Լ��� �� �ù��ڴ����� 
	}
}
*/


// dos�� type ��ɾ� ����� ��
// main �Լ��� �Ű������� ������� �ʴ´�. ������ main�Լ��� �Ű������� �������� ������ ���� ���¸� ���Ѵ�.
// void main(int argc, char *argv[])

// ����� ���� �Լ��� �Լ� ȣ��� ����� �Ű��������� ���� �Ű������� ���޹޴´�.

//���࿡ �������� �ҽ�5����IO.exe    one two three four �ϸ�
// argc ��ť��Ʈ ī��Ʈ�� 5���� �޴´� �ڱ��ڽŵ� �����ϱ⶧����
// argv�� �Է¹��� ���ڿ��� �����ϴ� �迭�̴�. �׷��ϱ� char *argv[] �� argument value



// ����࿡�� ���ڿ� �о����
/*
#include <iostream>
#include <fstream>
using namespace std;

void main(int argc, char *argv[])
{
	cout << "�ֽ��̾�" << endl;
	for (int i = 0; i < argc; i++) 
	{
		cout << argv[i] << endl;
	}
}
*/



/*
// type ��ɾ� �� ����ϰ� ���� ����
#include <iostream>
#include <fstream>

using namespace std;

void main(int argc, char * argv[])
{
	if (argc != 2)
	{
		cout << "just open only 1 file you dude" << endl;
		return;
	}
	char ch;
	ifstream fin;
	fin.open(argv[1]);

	if (fin.fail()) {
		cout << "open failure" << endl;
		return;
	}
	else if (fin.good()) {
		while (fin.get(ch)) {
			cout.put(ch);// cout << ch �� �ϴ°� ������
		}
	}
	else
		return;

	fin.close();
}
*/


/*
//���Ͽ��� �Է¹��� ������ �ٽ� ���Ͽ� ����ϱ�
#include <iostream>
#include <fstream>
using namespace std;

void main(int argc, char * argv[])
{
	if (argc != 3) {
		cout << "3 ���� �Է��϶�" << endl;
		return; // ���⼭ exit(0); �ص��ȴ�.
	}
	
	ifstream fin;
	ofstream fout;

	fin.open(argv[1]);
	fout.open(argv[2]);
	if (fin.fail() || fout.fail()) {
		cout << "file open failure" << endl;
		return;
	}
	char ch;
	while (fin.get(ch)) {
		fout.put(ch); // ������������� �۵���. copy�� ��� 
	}
	
	fin.close();
	fout.close();
	cout << "it worked!!!" << endl;
	return;
}
*/


/*
#include <iostream>
#include <fstream>
using namespace std;
//���Ͼ��� �ҹ��ڸ� ��� �빮�ڷ� ��ȯ�ض�. �� ����ϴ� ���α׷��̱��� ��

void main() {
	//AZaz ��
	// cout << (int)'a' << endl << (int)'A' <<endl<< (int)'z' <<endl<< (int)'Z' << endl;
	
	ifstream fin;
	ofstream fout;

	char ch; // �� ���� �ϳ��ϳ� ������ ����
	int AsGap = (int)'a' - (int)'A'; // �ƽ�Ű �빮�� �ҹ����� ����
	
	fin.open("eng.txt");
	
	if (fin.fail()) {
		cout << "error: fail to open the file";
	}
	while (fin.get(ch)) {
		
		if ((int)ch >= (int)'a' && (int)ch <= (int)'z'){
			ch = (char)((int)ch - AsGap); //��... ch ���� '' �� �ٿ����� �ٺ���..����
			cout << ch; // �̰� �� ������ �ٲ�� �ɱ� �ƴϸ� �ڿ� �̾���̱������ �Ǵ°ɱ�.
		}
		else
			cout << ch;

		if ((int)ch == (int)'A') { //��Ѹ��� ���� �ѱ��ھ� �˻��ϴ±���. ������ �����Ͱ� �ֳ���.
			ch = 'X';
			cout << ch;
		}
	}

	cout << "done." << endl;
	fin.close();
	
}
*/




/*
// ���� �տ� ��ȣ�� �ٿ��� ����϶�... get�ϰ� put�� ���� ���� �پ�

#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	
	ifstream fin;
	int count = 0;
	char ch;

	fin.open("eng.txt");
	if (fin.fail()) {
		cout << "file open failure";
	}
	
	cout <<count<< " : ";
	while (fin.get(ch)) {
		if (ch == '\n') {
			count++;
			cout << ch;
			cout << count << " : ";
			continue;
		}
		cout << ch;
	}
	

	fin.close();
	cout << endl << "done";
	return;
}
*/