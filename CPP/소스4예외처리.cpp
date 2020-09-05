
/*
// ���α׷��� ���ܻ�Ȳ�� ���������� ������������  �� ������ ������ ��� ���ڴ�./
// �׷��� �߰��� ����ġ ���� ���������� ���α׷��� �׷��� �� ���ư����Ѵ�. �׷��� ����ó���־���� 
// ������ ������ ���α׷��� ¥����

#include <iostream>
using namespace std;

void main()
{
	int a, b, c, d;
	
	cout << "�������� �ϱ� ���ؼ� �����͸� �Է��Ͻÿ�" << endl;

	cout << "������ �� ������ �Է�" << endl;
	cin >> a;

	cout << "������ �� ���� �Է�" << endl;
	cin >> b;

	c = a / b;//��
	cout << "�� = " << c << endl;
	d = a % b; // ������
	cout << "������ = " << d << endl;

	return;
}
// 0���� ������ ������.
// c++�� ���ܸ� �˻��ϰ� ó���ϴµ� ����ϴ� �������� try-catch �� �����Ѵ�. 
// ���ܰ� �߻��� ���� ������ try ��Ͼȿ� ����ϰ�
// �˻��ؼ� ���ܰ� �߻��ϸ� catch ���� ���� ���� ó�� ������ �����ϵ��� �Ѵ�.
*/


/*
try{
	���ܰ� �߻��� ���� �ڵ�
	}

catch{�ش�_Exception e) {
	����ó���� ���� ��ƾ
	}
	
*/
// �׸��� throw ���ܰ�ü;    �� ���α׷��Ӱ� �ǵ������� ���ܸ� �߻���Ű���� �Ҷ� ����Ѵ�.

//���� ������ throw ���� �̿��� �ǵ������� ���ܸ� �߻���Ű�� �߻��� ���ܸ� try catch �������� ó���ϴ� ���α׷�


/*
#include <iostream>
using namespace std;

void main()
{
	int a, b, c, d;

	cin >> a;
	cin >> b;

	try {
		if (b == 0) {
			throw b; // �ش� b�� 0�̸� 0�� ������.
		}
		c = a / b;
		d = a % b;
		cout << c << "." << d << endl;
	}

	catch (int ex) {
		cout << ex << "�� �������� �õ��� �־����Ƿ� ���� �߻�" << endl;
	}

	cout << "���ܰ� �־ ��������� ��" << endl;
	return;
}

*/




/*
#include <iostream>
using namespace std;

// divide �Լ� ������ ����ó���ϱ�, �ƴϸ� ȣ���� �Լ��� ������ �����ϱ�.
//ȣ���� �Լ��� ���� �����ϱ�

void divide(int a, int b)
{
	int c, d;
	cout << "********divide �Լ�********" << endl;

	if (b == 0)
		throw b;
	c = a / b;
	d = a % b;
	cout << " ��=" << c << " ������=" << d << endl;
	
}


void main()
{
	
	try {
		divide(10, 3);
		divide(20, 0);
		divide(30, 4);

	}
	catch(int ex){
		cout << " ���ܹ߻� " << ex << "�� �������� �õ�" << endl;
	}

}
*/



/*
// �׷��� �Լ� ���ο� try catch ���� divide �Լ� ���ο� ���� �Űܺ���
#include <iostream>
using namespace std;

void divide(int a, int b)
{
	int c, d;
	cout << "**********divide �Լ�*******" << endl;
	try 
	{
		if (b == 0)
			throw b;
		c = a / b;
		d = a % b;
		cout << "��" << c << " ������" << d << endl;
	}
	catch (int ex)
	{
		cout << ex << "�� �������� �õ� �����߻�" << endl;
	}

}

void main()
{
	divide(10, 3);
	divide(12, 0);
	divide(13, 2);

	cout << "0���� �������� ��������� ^^" << endl;
}
*/





/*
// try ���� ���ο��� �߻��ϴ� ���ܰ� �پ��� �� �����Ƿ� ���� ������ ���ܸ� ó���ϱ� ���ؼ� �ϳ� �̻��� catch���� ����� �� �ִ�.
#include <iostream>
using namespace std;

void func(int a)
{
	try {
		if (a == 0)
			throw "������ ���� 0�̴پƾ�";
		else
			throw a;
	}
	catch (const char *str){ // const �����ָ� ������
		cout << str << endl;
	}
	catch (int ex) {
		cout << "���� " << ex << "�� ���� ���� �߻�" << endl;
	}

}


void main() {

	func(10);
	func(20);
	func(0);

}

*/



/*
//�Լ��� ���� �߻� ����ϱ�
// ���ܰ� �߻��� ���ɼ��� �ִ� �Լ����� ���ܸ� ���� ó������ �ʰ� ȣ���� �Լ��� �ű�� �ִ� ���� �ڷ����� �����ϸ鼭
// ��������� ��Ÿ�����ִ�. 
#include <iostream>
using namespace std;

void func(int a) throw(const char *, int) // �������� �ϴ°� ����ٰ� ����س��´�. �ڷ�����.
{ // ���� throw���� �����Ϸ����� �̷��� ���� ��Ȳ�� �߻��Ҽ��ִٴ� ���� ��������� �˷��ش�.
	// try ������ �����Ϸ��� �Ĳ��ϰ� ���캸�°��̶� �ʹ� �����ϸ� ���α׷� ����������.
		if (a == 0)
			throw "������ ���� 0�̴�";
		else
			throw a;
	
	
}


void main()
{

	try {


		func(10);
		func(0);
	}



	catch (const char *str) {
		cout << str << endl;
	}
	catch (int ex) {
		cout << "����" << ex << "���ܹ߻�" << endl;
	}
}
*/