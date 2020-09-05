
/*

#include <iostream>
#include <string>
using namespace std;

void main()
{
	char strA[100] = "Apple";
	char strB[100];
	char strC[100];

	// strB = "Banana"; // ����

	strcpy_s(strB, "Banana");

	//strC = strA + strB; // ����

	strcpy_s(strC, strA);
	strcat_s(strC, strB);

	cout << "�� ���ڿ��� ��";
	cout << strC << endl;

	cout << strC[2] << endl; // it's difficult... difficult.... lemon difficult

}

*/




/*
// c++�� �⺻������ �������ִ� string class
#include <iostream>
#include <string>
using namespace std;

void main()
{
	string strA("Apple");
	string strB;
	string strC;

	strB = "Banana";

	strC = strA + strB;

	cout << strC << endl;

	cout << strC[2] << endl;
}
*/




// mystring class ����

// ���ڿ� �迭�� ������ �޸𸮱����� �ϴ� �Ҵ��ϰ� ���°ű⶧���� �޸𸮰� �����.
// �Ҵ�� �޸𸮸� ������ �����Ҽ����վ �����ϴ�. �����÷ο찰����                                           

// ������ Ŭ������ �ʿ��� ��ŭ�� �޸𸮸� �Ҵ�ǵ��� ����. �̸� ���ؼ��� �����޸� �Ҵ��� �ʿ�-



// ���� �޸� �Ҵ��� �ϴ� Ŭ���� ������ ���ؼ���    
// ���ڿ��� ���̸� �������� ������� int  m_nLen ��
// �Ҵ��� �� ������ ����ų ������������ char * m_pStr  �� �ʿ��ϴ�.  

// �ٽø��ϸ�    ����ΰ� �׸��� �󸶳� �䰡.. �װŴ�.. ��������G?

// �׸��� �����Ϳ��� const��   
// const int *p �϶� *p�� ����������� ����Ų�ٴ� �ǹ���    
// p = &a �ϸ�    a�� �ٲܼ�����.
// p = &b �̰� ��.. /
// �ٽø��ؼ� ����Ű�´���� ���� ���ٲٴµ�    ����Ű�� ����� �ٲ���־�.

// �׷��� �ڷ��� �ڿ� ��������???
// int* const p = &a ��   �������� �ݴ��
// ����Ű�� ����� ���ٲ۴�... a �����̴�. 
// �ٵ� ���� �ٲܼ��ִ�. ��ư �׷��Ŵ�.






/*
#include <iostream>
#include <string>
using namespace std;

class MyString {
private:
	int m_nLen;
	char *m_pStr;
public:
	MyString(const char* const str);
	MyString();
	~MyString();
	friend ostream &operator<<(ostream & os, MyString & temp); // ostream�� << �����ε�
	MyString &operator=(const MyString & RightHand); 
	// ���� Ŭ�������̳� �׷����� �⺻ = �����ڸ� �������ش�. �� Ŭ�������� �Ⱥ������� �ִ°Ŵ�.
	// �̰Ŵ� ��������� �ٽ� ����������Ѵ�.
	MyString operator+(const MyString & RightHand);
	MyString(const MyString & src); // ���� ������ ����
	char operator[](int num);
	bool operator==(const MyString &RightHand);
	bool operator==(const char* RightHand);
}; 



bool MyString::operator==(const char* RightHand) {
	if (strcmp(m_pStr, RightHand) == 0) {
		return true;
	}
	else
		return false;
}
bool MyString::operator==(const MyString &RightHand) {
	if (strcmp(m_pStr, RightHand.m_pStr) == 0) {// strcmp�� �� ���� ������ flase�� ��ȯ��
		return true;
	}
	else
		return false;
}
char MyString::operator[](int num) {
	if (num >= m_nLen){
		return m_pStr[m_nLen - 1];
	}
	else {
		return *(m_pStr + 1);
	}
}
MyString MyString::operator+(const MyString & RightHand) {
	int tot_len = m_nLen + RightHand.m_nLen - 1;
	char * temp = new char[tot_len];
	strcpy(temp, m_pStr);
	strcat(temp, RightHand.m_pStr);

	MyString result(temp);
	delete[] temp;
	return result;
}
MyString &MyString::operator=(const MyString &temp) {
	if (this == &temp)
		return *this;
	
	delete[]m_pStr;
	this->m_nLen = strlen(temp.m_pStr) + 1;
	this->m_pStr = new char[this->m_nLen];
	strcpy(this->m_pStr, temp.m_pStr);
	return *this;
}
MyString::MyString(const MyString & src) {
	m_nLen = src.m_nLen;
	m_pStr = new char[m_nLen];
	strcpy(m_pStr, src.m_pStr);
}
MyString::MyString(const char* const str) {
	m_nLen = strlen(str) + 1;
	m_pStr = new char[m_nLen];
	strcpy(m_pStr, str);
}
MyString::MyString() {
	m_nLen = 1;
	m_pStr = new char[m_nLen];
	strcpy(m_pStr, "");
}
MyString::~MyString() {
	delete[] m_pStr;
	m_nLen = 0;
	m_pStr = NULL;
}
ostream &operator<<(ostream &os, MyString & temp) {
	cout << temp.m_pStr;
	return os;
}


void main()
{
	MyString strA("Apple");
	MyString strB;
	cout << "test" << endl;
	cout << strA << endl;
	cout << strB << endl;

	MyString strC(strA);
	cout << strC << endl; // �ߵǴٰ� ������� �ֳ��ϸ�.. ���� �����̱⶧��... �̷� �ʱ�ȭ��..
	// �̷��� �ϸ� strC(�Ű������ΰ�) �����ڰ� ȣ���� �ȵǰ� ����Ʈ��������ڰ� ������ȴ�.
	// ���÷����� ���� ������

	// ����Ʈ ���� ������ �ȿ����� �̷� �۾��� �Ͼ��.
	// two.real = one.real;
	// two.image = one.image; ���� �����̴�.
	// ����Ʈ ��������ڸ� ����ϸ� �ȵǴ� ��ǥ���� ���� �����޸� �Ҵ��ϴ� Ŭ������ ����.

	// strC(strA)�ϸ�   C m_pStr ��    A m_pStr�� ����Ű�� �ִ� �ּҰ� �Ѱ��༭ �������� �����ϴ� ���°� �Ͼ.
	// �׸��� �Ҹ��ڰ� ȣ��ɶ� ���߿� ȣ��ȳ��� �̹� ������ �� ������ �� �����Ϸ��� �ϴ� ������ ����.
	// ���߿� ����� ��ü�� ���� �Ҹ�ǹǷ� strA�� �������ؼ� ������ �հԵȴ�.

	// �켱 c++ �����Ϸ��� �⺻������ �����ϴ� ����Ʈ �������� �⺻ ���¸� ����.
	// Ŭ������(const Ŭ������ & ��ü��);

	
	strB = strA; // �̰͵� �������� �Ͼ��. �׸��� Ŭ������ �����޸��Ҵ��ϴ� �����;���...�̰͵� ������Ѵ�.
	cout << "strB ��������" << endl;
	cout << strB << endl;


	cout << "str A + str B" << endl;
	cout << strA[2];
}

*/