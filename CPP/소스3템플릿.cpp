
/*
// �� �̻��� �ڷ����� ���� ���ø�ȭ

#include <iostream>
using namespace std;
// Data<TYPE, ARG_TYPE>
// ���ø�ȭ�ϸ� ��ü�����Ҷ� �������� <> �ȿ��ٰ� �� ������� ���� �� ������ �� ��ġ�Ǽ� ���Ӱ� ���������.
template <typename TYPE, typename ARG_TYPE>
class Data {
private:
	TYPE value;
public:
	Data(TYPE v);
	void CopyData(ARG_TYPE v);
	TYPE GetData();
};

template <typename TYPE, typename ARG_TYPE>
Data<TYPE, ARG_TYPE>::Data(TYPE v) {
	value = v;
}

template <typename TYPE, typename ARG_TYPE>
void Data<TYPE, ARG_TYPE>::CopyData(ARG_TYPE v) {
	value = v;
}

template <typename TYPE, typename ARG_TYPE>
TYPE Data<TYPE, ARG_TYPE>::GetData() {
	return value;
}
// ���ø� Ŭ������ �ν��Ͻ�ȭ00

int main() {
	int a = 10;

	Data<int, int &> obj1(10);
	cout << obj1.GetData() << endl;

	obj1.CopyData(a);
	cout << obj1.GetData() << endl;


	double b = 3.4;
	
	Data<double, double &> obj2(1.5); // �������� ���ø�ȭ�� Ŭ������ �������� <   > ���¸��� ���θ����.
	cout << obj2.GetData() << endl;
	
	obj2.CopyData(b);
	cout << obj2.GetData() << endl;

	return 0;
}
*/





/*
// ���ø� Ŭ���� template <typename any>
#include <iostream>
using namespace std;

template <typename DATATYPE> // Ŭ���� test �� DATATYPE�̶�� �̸����� ���ø�ȭ �ϰڴ�.
class Test {
private:
	DATATYPE value;
public:
	Test(DATATYPE v = 0);
	void SetValue(DATATYPE v);
	DATATYPE &GetValue();
};

template <typename DATATYPE>
Test<DATATYPE>::Test(DATATYPE v)
{
	value = v;
}

template <typename DATATYPE> // �Լ����ο��� ����ϰ� �ִ� ����ŸŸ�Կ� ���ؼ� �����ϴºκ� 
void Test<DATATYPE>::SetValue(DATATYPE v) // SetValue�Լ��� ���ø�Ŭ������ ����Լ��� �Ǿ���ϹǷ�Test<DATATYPE>:: ���ش�
{
	value = v;
}

template <typename DATATYPE>
DATATYPE &Test<DATATYPE>::GetValue()
{
	return value;
}


int main()
{
	Test<int> Obj1(10); // ��ü������ �ϸ� ���ø� Ŭ������ ���ؼ� Ŭ���� �ν��Ͻ��� ���������.
	Obj1.SetValue(10); // ���� <int> ������ ��ü�� �����Ǹ鼭 Ŭ����������<DATATYPE> �� int �� ��ġ�� �Ͼ��.
	cout << Obj1.GetValue() << endl;

	Test<double> Obj2(5.7);
	cout << Obj2.GetValue() << endl;

	// �̿� ���� ���ø� Ŭ������ ���� �� �����ϴ� ���� ���� �ڵ带 ��Ȱ���Ҽ��ְ� ���ش�.
	return 0;
}
*/






/*
// ���ø��� �ڵ��� ��Ȱ��  c++ �����Ϸ��� �����Ѵ�.
#include <iostream>
using namespace std;

// �����Ϸ����� T�� ������������ �ڷ����̶�� �̸� �˷������
// �ݵ�� �Լ����Ǻ� ���� �����ؾ��Ѵٰ���.
// ����ڰ� �����ϴ� ����ü�� Ŭ�������� �ɼ��ִ�.
template <typename T>
T abs(T num)
{
	if (num < 0) {
		num = (-num);
	}
	return num;
}
int main()
{
	int a = -10;
	cout << abs(a) << endl; 
	// int ������ �Ű������ָ�
	// ���ø��Լ��� �׿��°� �ν��Ͻ��� ���� ���� ������ش�.
	float b = -3.4;
	cout << abs(b) << endl;
	return 0;
}
*/





//������ ���ϴ��Լ� ���⼭ �ݺ��Ǵ°͸� T�� ��ü����
/*
#include <iostream>
using namespace std;

int abs(int num) 
{
	if (num < 0) {
		num = (-num);
	}
	return num;	
}

long abs(long num) 
{
	if (num < 0) {
		num = (-num);
	}
	return num;
}


double abs(double num) 
{
	if (num < 0) {
		num = (-num);
	}
		return num;
}

int main() 
{
	int a = -10;
	cout << "abs int = " << abs(a) << endl;

	long b= -12L;
	cout << "abs long = " << abs(b) << endl;

	double c = -3.4;
	cout << "abs double = " << abs(c) << endl;

	return 0;
}
*/





// ��������   �̰Ÿ� �ۻʸ�ȭ�ض�  
/*
#include <iostream>
using namespace std;
void change(int &a, int &b);
void change(double &a, double &b);

void main()
{
	int a = 10, b = 20;
	change(a, b);
	cout << a << "." << b << endl;

	double c = 10.5, d = 20.7;
	change(c, d);
	cout << c << "." << d << endl;

}

void change(int &a, int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

void change(double &a, double &b)
{
	double t;
	t = a;
	a = b;
	b = t;
}
*/



/*
#include <iostream>
using namespace std;

template <typename DATATYPE>
void change(DATATYPE &a, DATATYPE &b);

void main()
{
	int a = 10, b = 20;
	change(a, b);
	cout << a << "." << b << endl;

	double c = 10.5, d = 20.7;
	change(c, d);
	cout << c << "." << d << endl;

}

template <typename DATATYPE>
void change(DATATYPE &a, DATATYPE &b)
{
	DATATYPE t;
	t = a;
	a = b;
	b = t;
}
*/


/*
#include <iostream>
using namespace std;

template <typename T>
class Add {
private:
	T a;
	T b;
public:
	Add(T a, T b);
	T Sum();
};

template <typename T>
Add<T>::Add(T a, T b)
{
	this->a = a;
	this->b = b;
}
template <typename T>
T Add<T>::Sum()
{
	return a + b;
}

void main()
{
	Add<int> obj(10, 20);
	cout << obj.Sum() << endl;
}
*/