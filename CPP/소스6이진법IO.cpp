//���ݱ��� ������ ����Ÿ�� �ؽ�Ʈ ���Ͽ� �ؽ�Ʈ �������� ��������.
// �װŸ� ������������ �޸𸮿� ����Ǿ��ִ� ������ ���� ���� �����Ҽ��ִ�.

// fout << man.namne ,< " " << man.age << " " �̷������� �ϸ� ������ �����ϴ�. �ؽ�Ʈ������
// fout.write((char *) &man, sizeof(man)); �������� �ϸ� ����.
// write(char *, int n);

/*
#include <iostream>
#include <fstream>
using namespace std;

struct insa {
	char name[20]; 
	int age;
	char address[20];
};

void main()
{
	insa man[5] = { {"������",20, "����"},{"������", 30, "�λ�"},{"������", 24, "�뱸"},{"������", 34, "����"},{"ä����", 25, "����"} };
	
	ofstream fout;
	fout.open("insa.dat");
	if (fout.fail()) {
		cout << "file open failure";
		return;
	}

	for (int i = 0; i < 5; i++) {
		fout << man[i].name << " " << man[i].age << " " << man[i].address << endl;
	}

	fout.close();
	cout << "done!" << endl;

	return;
} // ������ ���
*/

/*
#include <iostream>
#include <fstream>
using namespace std;

struct insa {
	char name[20];
	int age;
	char address[20];
};

void main()
{
	insa man[5] = { {"������",20, "����"},{"������", 30, "�λ�"},{"������", 24, "�뱸"},{"������", 34, "����"},{"ä����", 25, "����"} };

	ofstream fout;
	fout.open("insa.dat");
	if (fout.fail()) {
		cout << "open failure";
		return;
	}


		fout.write((char*)&man[i], sizeof(insa) * 5);
	
	fout.close();

	ifstream fin; // read(char *, int n);

	insa newman[5];

	fin.open("insa.dat");
	if (fin.fail()) {
		cout << "open failure" << endl;
		return;
	}
	
	fin.read((char*)&newman, sizeof(insa) * 5); // ��� ��ϴ����� �ٽ� �����´� read�� 
	for (int i = 0; i < 5; i++)
		cout << newman[i].name << " " << newman[i].age << " " << newman[i].address << endl;




	//while (fin.read((char *)&newman, sizeof(newman))) {
	//	cout << newman.name << "\t" << newman.age << "\t" << newman.address << endl;
	//}

	fin.close();
}
*/


/*
#include <iostream>
#include <fstream>
using namespace std;

struct insa {
	char name[20];
	int age;
	char address[20];
};

void main()
{
	insa man;
	ifstream fin;
	int pos;
	bool bFind = true;

	fin.open("insa.dat");
	if (fin.fail() != 0) {
		cout << "Error: open file failure";
		return;
	}

	cout << "�� ��° ���ڵ��� ������ ����ͽ��ϱ�?" << endl;
	cin >> pos;

	for (int i = 0; i < pos; i++) {
		fin.read((char *)&man, sizeof(man));
		if (!fin.good()) {
			bFind = false;
			break;
		}
	}
	
	if (bFind == true) {
		cout << man.name << " " << man.age << " " << man.address << endl;
	}
	else if (bFind == false) {
		cout << "�ش��ϴ� ���ڵ忡 �����Ͱ� ����" << endl;
	}
	fin.close();
	
}
*/

/*
// �������� ����� �ӵ��� �������� ��ȿ������
// �������� ������� �ؾ���. ��� �����Ͱ� ������ ũ�⿩����.
// ���� �ϸ� ����������. 
//����ü �״�θ� ���Ͽ� �����ϱ⿡ ���ϴ� ��ġ�� ã�ư��⿡�� ���������͸� ����ü ũ�⸸ŭ �����̸��
// ���ڵ� �����͸� ���ϴ� ��ġ�� �̵��ϱ� ���ްŴ� seekg �Լ��� ����ؾ���.

#include <iostream>
#include <fstream>
using namespace std;

// istream & seekg(long offset, seek_dir);

// seekg �Ԥ����� ù��°�� �Ű������� offset�� seek dir �κ��� �󸶳� �����ϱ ���Ѱ���
// seekg �Լ��� seek_dir �� �Է��Ҽ��ִ°͵� ios::beg ó��  ios::cur ����  ios::end ��
// ����   ex fin.seekg(-4, ios::end)�� �� ���������� -4�� �����Ѵ� ������

struct insa {
	char name[20];
	int age;
	char address[20];
};

void main()
{
	insa man;
	ifstream fin;

	int pos;
	int total_rec;

	fin.open("insa.dat");

	if (fin.fail()) {
		cout << "file open failure" << endl;
		return;
	}

	fin.seekg(0, ios::end); // tellg�� ���̰� ������ ������
	total_rec = fin.tellg() / sizeof(insa); // �� ��� ���ڵ����� ����ҷ���.
	cout << "���� ���ڵ��� �� ������ " << total_rec << endl; // ���⼭ insa.dat �Ҷ� �𸣰� write�Լ�����
	// for�� �ᰡ���菉��;; ��û ���� ���ð���
	// tellg �� ó������ ���� ��ġ���� ����Ʈ������ ���Ѵ�. 
	cout << " �а���� ���ڵ��" << endl;
	cin >> pos;

	if (pos >= total_rec) {
		cout << "���ڵ� ã�� ����" << endl;
	}

	fin.seekg((pos - 1) * sizeof(insa), ios::beg); // ���࿡ �ι�° ���ڵ� ����; 2 �Է��ϸ�
	// 1 * 44 �Ǽ�   ios::beg ���� 44�Ĵϱ� 44����Ʈ���� ���� �����Ҽ��մ°���
	fin.read((char *)&man, sizeof(insa));

	cout << man.name << " " << man.age << " " << man.address << endl;
}

*/
