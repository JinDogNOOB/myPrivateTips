


/*
//������ �����ε� �� �ı� 
//������ �����ε� �Ұ� ������ .  ::    ?:     sizeof     typeid      static_cast     dynamic_cast    const_cast     reinterpert_cast    �� 

#include <iostream>
using namespace std;
class Complex {
private:
	int real;
	int image;
	static int count; // Ŭ��������������� ����
public:
	Complex(int r=0, int i=0); // �������� ��������
	
	//�Ϲ������� Complex x(10,20);
	// Complex y = x; �� y�� x�� �ʱ�ȭ��Ű�� �������簡 �Ͼ�� �̰� �� this->real = &temp.real  �ƹ�ư �ּҸ� �ְԵǼ� x�Ҹ��ڰ� ȣ��Ǹ� y�Ҹ��ڰ� ����� ��� �ƹ�ư �ҰԾ�����
	//���� ���簡 �ʿ����� �� �Ŵ� �̷��� �ϸ��
	Complex(const Complex &temp){
		// ���ڿ��� ���� strcpy_s(this->real, temp.real);
		//Ŭ������ �̷��� �ϸ�ǳ�?
		Complex::count++;
		cout << Complex::count<<" ��°������ ȣ�� ��������"<<endl; // ���� �𸣰ڴ� ���� �̰� ��� ����
		real = temp.real;
		image = temp.image; // �� �ּҷ� * ��簡 & ��簡   �� ��������ڴ� ���������ϸ��� ��������ü�� ����Ǽ� ���λ���°Ծƴ�   �����Ŵ� �����Ǵ� �� ��ü ��ü�� �����ϴ°Ŷ� ��ư �׷� ��]
		// �ٵ� �Ҹ��� �� ȣ��ȵǳ�
		
	
		//this->real = new temp.real; �𸣰ڴ�.
		//this->image = new temp.image;
		
	}
	~Complex()
	{
		cout << Complex::count <<" ��° �Ҹ��� ȣ��" << endl;
		Complex::count--;
	}
	void SetComplex(int r = 0, int i = 0);
	void PrnComplex()const;

	//������� ������ �����ε�
	//���� ���� ���� ���� ���� 
	friend Complex &operator++(Complex &cObj); // ����   ++test
	friend const Complex operator ++(Complex &cObj, int); // ���� test++

	friend Complex &operator--(Complex &cObj); // ���� --
	friend const Complex operator--(Complex &cObj, int);
	
};
int Complex::count = 0; //Ŭ�������� ������� ����
Complex::Complex(int r, int i)
{
	Complex::count++;
	cout << Complex::count<<" ��° ������ ȣ��" << endl;
	this->real = r; 
	this->image = i; 
	
}
void Complex::SetComplex(int r, int i)
{
	real = r; 
	image = i;
}
void Complex::PrnComplex() const
{
	cout << this->real << "." << this->image << "i" << endl;
}
Complex &operator++(Complex &cObj)
{
	cObj.image++;
	cObj.real++;
	return cObj;
}
const Complex operator ++(Complex &cObj, int)
{
	Complex temp = cObj;
	cObj.real += 1;
	cObj.image += 1;
	return temp;
}
Complex &operator--(Complex &cObj)
{
	cObj.real++;
	cObj.image++;
	return cObj;
}
const Complex operator--(Complex &cObj, int)
{
	Complex temp = cObj;
	cObj.real += 1;
	cObj.image += 1;
	return temp;
}


void main()
{
	Complex x(1, 2), y(4, 6), z = x;
	//x.PrnComplex(); // �� �۵��Ѵ�.
	//x++.PrnComplex();
	//x.PrnComplex();
	//(++x).PrnComplex();
	
	Complex q;
	system("pause");
	return;
}
*/




/*
// string class << �����ϰ� ����
#include <iostream>
#include <string.h>
using namespace std;
class Cstring {
private:
	char data[256];
public:
	Cstring(const char *nul = "\0") {
		strcpy_s(data, nul);// �����ڷ� �ʱ�ȭ
	}
	friend ostream &operator<<(ostream &os, const Cstring &right) ;
};
ostream &operator<<(ostream &os, const Cstring &right)
{
	os << right.data;
	return os;
}
void main()
{
	Cstring Astr("ghh0");
	Cstring Bstr("asdsad");

	cout << Astr << endl; // ��Ÿ� �����ϰ� << �� �����ε�
	cout << Bstr << endl;

	system("pause");
	return;
}
*/



/*
//���� �����ڷ� �ѹ� �غ��� operator- +
#include <iostream>
using namespace std;
class Complex {
private:
	int real;
	int image;
public:
	Complex(int r = 0, int i = 0);
	void ShowComplex() const; // const ����Լ��� ����������� ���� ��븸�ϰ� �������� ���ϵ��� �Ѵ�.
	void SetComplex(int r=0, int i=0);
	Complex operator-(Complex &rightHand) const; 
	Complex operator-() const; // ���׿����� -  ex)   -a
	Complex operator+(Complex &rightHand);

	// ��´�� �Լ��� ������ operator<<
	friend ostream &operator<<(ostream &os, const Complex &comObj) ;

	// ������ ����ϴ� �Լ��� ������ operator*
	Complex &operator*(Complex &rightHand)const;
	
	
};

Complex::Complex(int r, int i):real(r), image(i)
{}
void Complex::ShowComplex() const
{
	if (image > 0)
		cout << real << ".+" << image << "i" << endl;
	else if (image < 0)
		cout << real << "." << image << "i" << endl;
	else
		cout << real << endl;
}
void Complex::SetComplex(int r, int i)
{
	real = r;
	image = i;
}
inline Complex Complex::operator-(Complex &rightHand) const // ����Լ��ε� 
{
	Complex res;
	res.real = this->real - rightHand.real;
	res.image = this->image - rightHand.image;
	return res;
}
inline Complex Complex::operator-() const
{
	Complex res;
	res.real = -this->real;
	res.image = -this->image;
	return res;
}
inline Complex Complex::operator+(Complex &rightHand)
{
	Complex res;
	res.real = this->real + rightHand.real;
	res.image = this->image + rightHand.image;
	return res;
}
inline ostream &operator<<(ostream &os, const Complex &comObj) // cout << a << "i" << b<< endl;  cout << a �� cout ��ȯ�ϰ�   cout<<"i"<<b<<endl; ���� �ݺ������� ���������ΰ���
{
	os << comObj.real << "." << comObj.image << "i" << endl;
	return os;
}
inline Complex &Complex::operator*(Complex &rightHand)const
{
	Complex res;
	res.real = this->real * rightHand.real;
	res.image = this->image * rightHand.image;
	return res;
}
void main()
{
	Complex x(10, 10 ), y(50, 20), z;

	cout << "x + y = z" << endl;
	z = x + y;
	z.ShowComplex();
	
	cout << "x - y = z" << endl;
	z = x - y;
	z.ShowComplex();

	cout << "z = -x" << endl;
	z = -x;
	z.ShowComplex();

	cout << "z = x*y" << endl;
	z = x * y;
	z.ShowComplex();

	

	cout << x << y << z << endl;
	system("pause");
	return;
}
*/





/*
//�տ����� �������Լ� + ���۷��������� ���� �Ẹ�� // p407 �����ߴ�..
#include <iostream>
using namespace std;
class Complex {
private: 
	int real;
	int image;
public:
	Complex(int = 0, int = 0);
	void ShowComplex()const;
	
	friend Complex &AddOnePrefix(Complex &operand);
	friend Complex &AddOnePostfix(Complex &operand);
};

Complex::Complex(int r, int i)
{
	real = r;
	image = i;
}

void Complex::ShowComplex() const
{
	cout << real << "." << image << "i" << endl;
}

Complex &AddOnePrefix(Complex &operand)
{
	++operand.real;
	++operand.image;
	return operand;
}

Complex &AddOnePostfix(Complex &operand)
{
	Complex temp = operand;
	++operand.real;
	++operand.image;
	return temp;
}

void main()
{
	Complex x(1, 2), y(4, 5), xx, yy;
	
	x.ShowComplex();
	xx = AddOnePrefix(x);
	x.ShowComplex();
	xx.ShowComplex();

	y.ShowComplex();
	yy = AddOnePostfix(y);
	y.ShowComplex();
	yy.ShowComplex();

	system("pause");
	return;
}
*/






/*
// ++a   a++ �� �����غ���  ���� ����Լ����� AddOnePrefix    AddOnePostfix  
#include <iostream>
using namespace std;
class Complex {
private:
	int real;
	int image;
public:
	Complex(int = 0, int = 0);
	void ShowComplex() const;
	 
	Complex AddOnePrefix();
	Complex AddOnePostfix();
};

Complex::Complex(int r, int i)
{
	real = r;
	image = i;

}

void Complex::ShowComplex()const
{
	cout << real << "." << image << "i" << endl;
}

Complex Complex::AddOnePrefix()
{
	++this->real;
	++this->image;
	return *this;
}

Complex Complex::AddOnePostfix()
{
	Complex temp = *this;
	++this->real;
	++this->image;
	return temp;
}

void main()
{
	Complex x(1, 2), y(5, 7), xx, yy;
	x.ShowComplex();
	xx = x.AddOnePrefix();
	x.ShowComplex();
	xx.ShowComplex();

	y.ShowComplex();
	yy = y.AddOnePostfix();
	y.ShowComplex();
	yy.ShowComplex();

	system("pause");
	return;
}
*/






/*
// Complex ���ϱ⸦ ������ �Լ��� ����
#include <iostream>
using namespace std;
class Complex {
private:
	int real;
	int image;
public:
	Complex(int = 0, int = 0);
	void ShowComplex() const;
	friend Complex sum(Complex &x, Complex &y); // ������ Complex�� ����Լ��� �ƴ϶� �Ϲ��Լ��� ����
};

Complex::Complex(int r, int i)
{
	real = r; image = i;
}

void Complex::ShowComplex() const
{
	cout << real << "." << image << "i" << endl;
}

Complex sum(Complex &x, Complex &y)
{
	Complex res;
	res.real = x.real + y.real;
	res.image = x.image + y.image;
	return res;
}

void main() {
	
	Complex x(5, 3), y(1, 6), z;
	z = sum(x, y);
	x.ShowComplex();
	y.ShowComplex();
	z.ShowComplex();

	system("pause");
	return;
}
*/




/*
//������ �����ε� �ϴ� +  - �� ���߿� �ϰ� Complex��ü���� ���ϴ°��� ����Լ��� ��������.
#include <iostream>
using namespace std;
class Complex {
private:
	int real;
	int image;
public:
	Complex(int = 0, int = 0);
	void ShowComplex() const;
	Complex sum(Complex &ins);
};

Complex::Complex(int r, int i)
{
	real = r;
	image = i;
}

void Complex::ShowComplex() const
{
	cout << real << "." << image << "i" << endl;
}

Complex Complex::sum(Complex &ins)
{
	Complex res;
	res.real = this->real + ins.real;
	res.image = this->image + ins.image;

	return res;
}

void main()
{
	Complex x(4, 3), y(2,4), z;
	
	z = x.sum(y);

	x.ShowComplex();
	cout << " + " << endl;
		y.ShowComplex();
		cout << " = " << endl;

	z.ShowComplex();

	system("pause");
	return;
}
*/








/*
//friend functions   �Ϲ��Լ������� �����Ͻ� Ŭ���������� private�� �����Ҽ��ֵ��� �ϴ� ������ ��� ... friend �Լ�....   ���������м��� ���������. �׷��ϱ� ���� �����ϸ� �ȵ�. 
// friend functions �� �Ǳ� ���� ����.
// �����ϰ��� �ϴ� private����� ���� Ŭ���� ���ο� friend�Լ��� �����Ѵ�.
// ������ �Լ� �����Ҷ��� �Լ��� �տ� ������ ���� ����� friend�� ���δ�.
#include <iostream>
using namespace std;
class Complex {
private:
	int real;
	int image;
	static int count;
public:
	Complex(int =0, int =0);
	~Complex();
	void ShowComplex() const;
	
	friend void prn(Complex *parr); // ������ �Լ� ����
	friend void rprn(Complex &r); // ���۷����� �غ���?? // �迭 ��ü�� �������� �����̴�.. �׷��� ���۷����δ� �ȵȴٴµ�???����
};

int Complex::count = 0;

Complex::Complex(int r, int i) : real(r), image(i)
{
	Complex::count++;
}
Complex::~Complex()
{
	Complex::count--;
}
void Complex::ShowComplex() const
{
	cout << real << "." << image << "i" << endl;
}

void prn(Complex *parr)
{
	for (int i = 0; i < Complex::count; i++) {
		cout << (parr + i)->real << "." << (parr + i)->image << "i" << endl;
	}
}

void rprn(Complex &r)
{
	for (int i = 0; i < Complex::count; i++)
		cout << r.real << "." << r.image << "i" << endl;
}

void main()
{
	Complex arr[6] = { //������ arr[5] �� default
		Complex(4,3),
		Complex(6,4),
		Complex(1,2),
		Complex(7,3),
		Complex(0,1)
	};
		
	prn(arr); // Complex�� ������ �Լ��� prn�� ComplexŬ���� ��ü���� private member�� real�� image�� ������� ������ ���. 
	//rprn(arr);
	system("pause");
	return;
}
*/





/*
// ��ü�迭 
#include <iostream>
using namespace std;
class Complex {
private:
	int real;
	int image;
	static int count;
public:
	Complex(int real = 0, int image = 0);
	~Complex();
	void SetComplex(int, int);
	void PrnComplex() const;
	static void PrnCount();
};
int Complex::count = 0;
Complex::Complex(int real, int image)
{
	this->real = real;
	this->image = image;
	Complex::count++;
}
Complex::~Complex() // ī��Ʈ �ٿ��ִ� �Ҹ��� ����
{
	cout << "�Ҹ��� ȣ��" << endl;
	Complex::count--;
}
void Complex::SetComplex(int real, int image)
{
	this->real = real; this->image = image;
}
void Complex::PrnComplex()const
{
	cout << real << "." << image << "i" << endl;
}
void Complex::PrnCount()
{
	cout << Complex::count << "��° ����" << endl;
}

void prn(Complex *parr) {
	// �̰� �迭 �� ����ϴ� �Լ� ����, ����
	for (int i = 0; i < 5; i++)
		(parr + i)->PrnComplex();
}
void main()
{
	Complex arr[5] = { // 10A 11B 12C 13D 14E 15F -> 0
		Complex(4,5),
		Complex(8,34),
		Complex(7,12),
		Complex(3,4)
	}; // ������ 4��°���� �ʱⰪ����
	Complex *parr = arr; // *parr ���� �� arr�迭�� �����ּ� ���� 
	Complex::PrnCount();

	for (int i = 0; i < 5; i++) { // arr[0] 1000 ������� ġ��    arr
		arr[i].PrnComplex(); // ���� *parr ������ ������ ����Ϸ��� *(parr+i)->PrnComplex(); ���ָ� �� ������ �ؿ�
	}
	for (int i = 0; i < 5; i++) {
		(parr + i)->PrnComplex();
		(arr + i)->PrnComplex();
		cout << "\n parr+i �� �ּҰ�"<< (&parr+i);
		cout << "\n arr+i �� �ּҰ�" << arr + i << endl;
		
	}
	prn(arr); // prn �Լ� ȣ��
	system("pause");
	return;
}
*/






/*
//���� ��������� ������ ��� ��
#include <iostream>
using namespace std;
class Cstud {
private:
	char name[20];
	char handphone[30];
	char email[40];
	//static int count; //����������� count ����
	static int count;

public:
	static void PrnCount(); // static �ٿ���� �ν��Ͻ� �������� Cstud::PrnCount�� ȣ���� �� 
	Cstud( char const pname[20] = "null", char const phandphone[30] = "010-0000-0000", char const pemail[40] = "null@naver.com");
	void PrintStud()const; //��Ǫ�ν�Ʈ
};

int Cstud::count = 0; // ����������� count 0���� �ʱ�ȭ

Cstud::Cstud(char const pname[20], char const phandphone[30], char const pemail[40])
{
	strcpy_s(name, pname);   // �̾� _s ���� �����ϴ� 
	strcpy_s(handphone, phandphone);
	strcpy_s(email, pemail);
	Cstud::count++;
	cout << "���� " << count << endl;
}
void Cstud::PrintStud()const
{
	cout << name << "\t" << handphone << "\t" << email << endl;
}
void Cstud::PrnCount()
{
	cout << "���� count" << Cstud::count << endl;
}
void main()
{
	Cstud x("aaa","aaa","aaa"), y("bbb","bbb","bbb"), z, d;
	// cout << Csutd::count << endl; �̷��� ȣ�� ���� aht�Ѵ�. private���� 
	//cout << Cstud::count << endl;
	x.PrintStud();
	y.PrintStud();
	z.PrintStud();
	d.PrintStud();

	x.PrnCount(); // x�ν������� ���ؼ� ȣ��
	Cstud::PrnCount(); // Ŭ�������� ��������Լ��� ȣ�� static �� �ٿ����Ѵ�
	system("pause");
	return;
}
*/





/*
// Ŭ���� ���� ����� ��ü ���� ���
//���� ����Լ�
#include <iostream>
using namespace std;
class StaticTest {
private:
	static int a;
	int b;
public:
	StaticTest();
	static void SetA(int new_a);
	static int  GetA();
};
int StaticTest::a = 10;
StaticTest::StaticTest() {
	b = 20;
}
void StaticTest::SetA(int new_a) {
	a = new_a;
}
int StaticTest::GetA() {
	return a;
}

void main()
{
	StaticTest x;
	x.SetA(1002);
	cout << x.GetA() << endl;
	cout << StaticTest::GetA() << endl;
	
	system("pause");
	return;
}
*/


/*
#include <iostream>
using namespace std;
class StaticTest {
public:
	static int a; // Ŭ���� ���� ��� ���� ����
	int b; // ��ü ���� ��� ����
	StaticTest();
};

int StaticTest::a = 0; // Ŭ���� ���� ��� ���� �ʱ�ȭ�� Ŭ���� ���� �ۿ��ٰ� �����������.

StaticTest::StaticTest()
{
	b = 20;
}

void main()
{
	cout << "StaticTest::a => " << StaticTest::a << "\n\n";

	StaticTest s1, s2;

	cout << "s1.a -> " << s1.a << "\t s2.a -> " << s2.a << "\n";
	cout << "s1.b -> " << s1.b << "\t s2.b -> " << s2.b << "\n\n";

	s1.a = 100;

	cout << "s1.a -> " << s1.a << "\t s2.a -> " << s2.a << "\n";
	cout << "s1.b -> " << s1.b << "\t s2.b -> " << s2.b << "\n\n";

	s1.b = 200;
	cout << "s1.a -> " << s1.a << "\t s2.a -> " << s2.a << "\n";
	cout << "s1.b -> " << s1.b << "\t s2.b -> " << s2.b << "\n\n";

	system("pause");
	return;
}
*/


/*
// �Ʒ��� ���� ����
#include <iostream>
using namespace std;
class Complex {
private:
	int real;
	int image;
public:
	Complex(int r = 0, int i = 0);
	void ShowComplex()const;
};

Complex::Complex(int r, int i)
{
	real = r;
	image = i;
}

void Complex::ShowComplex() const
{
	cout << real << "." << image << "i" << endl;
}

Complex &CopyComplex(Complex &dst, const Complex &src)
{
	dst = src;
	return dst;  // �̰� Complex &CopyComplex = (return)dst  ������ �ǳ���   �Ƹ�..
}

void main()
{
	Complex x(10, 20), y(40, 50), z;
	x.ShowComplex();
	y.ShowComplex();
	z.ShowComplex();
	cout << endl;
	z = CopyComplex(y, x);
	x.ShowComplex();
	y.ShowComplex();
	z.ShowComplex();

	system("pause");
	return;
}
*/



/*


Complex CopyComplex(Complex &dst, Complex &src) {
// �̰� ��ȯ�Ϸ����ϸ� CopyComplex���� dst�� ������ ������ �����. �׷��� ����� �׷��ϱ�
return dst
}



Complex &CopyComplex(Complex &dst, Complex &src) { // ���� Complex &CopyComplex �� ���̴°�. & ���̸���   &dst   �׷��ϱ� main::y  �� ��Ī���� CopyComplex�� ����°Ŵ� 
// �׷��� main::y �� ��Ī�� ��    CopyComplex::dst      CopyComplex()   �� �Ǵ°Ŵ�                        ��ư �׷����� ������ ���� ���ٸ� ������ ���������ʴ´�
return dst
}
*/

/*
//���۷����� ���� CopyComplex �Լ� �豸��
#include <iostream>
using namespace std;
class Complex {
private:
	int real;
	int image;
public:
	Complex(int real = 0, int image = 0);
	void ShowComplex() const;
};

Complex::Complex(int real, int image)
{
	this->real = real; this->image = image;
}

void Complex::ShowComplex() const
{
	cout << real << "." << image << "i" << endl;
}

void CopyComplex(Complex &dst, const Complex &src)  // �� �Լ������� src���۷�����ü ������ ���� ����Ǹ��� �ȵǹǷ� const ����� �ٿ��ش�. const Complex &src     ��ġ const int num = 0; ���� ���� ���࿡ �Լ� ���ο��� ����ɶ���ϸ� ��������.��
{
	dst = src; // ���࿡ �� �Լ� ���ϰ� �������  �� �Լ� ���ο���   �� ���ϰ��� ���� Complex��ü ������ �ϳ� ����� �̰͵� ������ ������������. �׷��ϱ�. ���� �ּ� �޾Ƴ�����

}

int main()
{
	Complex x(10, 20), y(50, 60);
	x.ShowComplex();
	y.ShowComplex();
	cout << "Copy Complex() ȣ���� " << endl;
	CopyComplex(y, x);
	x.ShowComplex();
	y.ShowComplex();
	system("pause");
	return 0;
}
*/



/*
// ���� /*���� ������ �޾� ���� �ٲٴ� CopyComplex(Complex src, Complex dst) �� ���ó� �ȵȴ� ����. ��ü �ּҷ� �Ѱ���� �۵��Ѵ�. ���۷����ε� �ǳ�? �ȴ�
//�ϴ� ���� ���� ���޷� CopyComplex�� �ҷ����� �����ϰ� ���ϰ����� ��ư�ؾ��Ѵ� 

#include <iostream>
using namespace std;
class Complex {
private:
	int real;
	int image;
public:
	Complex(int real = 0 ,int image = 0);
	void ShowComplex() const;
};

Complex::Complex(int real, int image)
{
	this->real = real; this->image = image;
}

void Complex::ShowComplex() const
{
	cout << real << "." << image << "i" << endl;
}

void CopyComplex(Complex *pdst, Complex src)  // ���� function(dst, src) �ΰ�����
{
	*pdst = src;
}

int main()
{
	Complex x(10, 20), y(30, 40);
	x.ShowComplex();
	y.ShowComplex();

	cout << "CopyComplex(&y,x)" << endl;
	CopyComplex(&y, x);
	x.ShowComplex();
	y.ShowComplex();

	system("pause");
	return 0;
}
*/




/*
//�Ű������� ��ü�� �Լ�.
// ������ �ڷ������� ����� ��ü������ ���Կ����ڷ� ���� ġȯ �����ϴ�.
#include <iostream>
using namespace std;
class Complex {
private:
	int real;
	int image;
public:
	Complex(int r = 0, int i = 0);
	void ShowComplex() const;
	void SetComplex(int ,int);
};

Complex::Complex(int r, int i)
{
	real = r;
	image = i;
}

void Complex::ShowComplex() const
{
	cout << real << "." << image << "i" << endl;
}

void Complex::SetComplex(int r, int i)
{
	real = r;
	image = i;
}

void main()
{
	Complex x(10, 20), y(50, 60);
	x.ShowComplex();
	y.ShowComplex();
	cout << "�����ϸ�" << endl;
	y = x;
	x.ShowComplex();
	y.ShowComplex();
	cout << "Y ���� �Է��ϸ�" << endl;

	y.SetComplex(1, 2);
	x.ShowComplex();
	y.ShowComplex();
	
	system("pause");
}
*/



/*
// ��ü�� �ڷ����� Ŭ������°Ż���� �ٸ� �Ϲ� ������ �����ϴ�. �׷��ϲ� �����͵� �ִ�. ��ü ������        
// Ŭ������ ����Լ��� �ش� Ŭ������ü���� �����ϴ°��� �׷��� �Լ� ���� ����������� � ��ü�Ҽ������� ��� �Ƴ�..
// �װŴ� �����Ϸ��� ���� �����Ǵ� this ������ ����ؼ� �Ѵ�. this �� "����Լ��� ȣ���� ��ü�� �ּ�" �� ��ư �����Ϸ��� �˾Ƽ� this -> real = 4;   this->image = 3; �̷� �������� �˾Ƽ� ���� this �� ����Լ� �������� ��밡����.
// ����Լ����� this �����Ͱ� �ִ�. this �� �� ����ؾ� �ϴ� ����   �Լ��� �Ű������� ��������� �̸��� �Ȱ������̴�.
//this �� �ѹ� �������� ��������� ����غ���

#include <iostream>
using namespace std;
class Complex {
private:
	int real;
	int image;
public:
	Complex(int real = 0, int image = 0);
	void ShowComplex() const;
};

Complex::Complex(int real, int image)
{
	this->real = real;
	this->image = image;
}

void Complex::ShowComplex() const
{
	cout << this->real << "." <<this->image << "i" << endl;
}

int main()
{
	Complex x(4,2);
	x.ShowComplex();

	system("pause");
	return 0;
}

*/





/*
#include <iostream>
using namespace std;
class Crect {
private:
	int left;
	int top;
	int right;
	int bottom;
public :
	void print()const;
	void setRect(int ,int ,int ,int	);
};

void Crect::print() const {
	cout << left << " " << top << " " << right << " " << bottom << endl;

}

void Crect::setRect(int l, int t, int r, int b) {
	left = l;
	top = t;
	right = r;
	bottom = b;
}

int main()
{
	Crect obj_1;
	

	obj_1.setRect(1, 2, 3, 4);
	obj_1.print();

	system("pause");
	return 0;
}
*/




/*
#include <iostream>
using namespace std;
class Crect {
private:
	int left;
	int top;
	int right;
	int bottom;
public:
	Crect(int t0 = 0, int t1 = 0, int t2 = 0, int t3 = 0);
	~Crect();
	void input(int,int,int,int);
	void print()const;
};

void Crect::print()const {
	cout << left << " " << top << " " << right << " " << bottom << endl;

}

void Crect::input(int t0, int t1, int t2, int t3) {
	
	left = t0;
	top = t1;
	right = t2;
	bottom = t3;
}
Crect::Crect(int t0, int t1, int t2, int t3)
{
	cout << "������ ȣ��" << endl;
	left = t0;
	top = t1;
	right = t2;
	bottom = t3;
}
Crect::~Crect()
{
	cout << "�Ҹ��� ȣ��" << endl;
	system("pause");
}
void main() {
	Crect obj_1, obj_2;
	obj_1.input(1, 2, 3, 4);
	obj_2.input(5,3,4,5);
	
	obj_1.print();
	obj_2.print();

	system("pause");
	return;
}
*/



//������� ����


/*
//�Ҹ���. Destructor �Ҹ��ڴ� ��ü�� �Ҹ��Ҷ� �ڵ�ȣ��  
// �����ڰ� ��ü�� �ʱ�ȭ�ϱ� ���� ����Լ���� �Ҹ��ڴ� ��ü�� ������ �ִ� (���ҽ�)�� �����Ѵٵ��� �ϴ� �۾��� �ϴ� ����Լ��̴� . ������
// cpp �����Ϸ��� �Ҹ��ڵ� �������ִµ� �����ڿ� �Ȱ��� �ƹ��͵� ���ϴ� �Ҹ��ڶ�  ��ü�� �����Ҷ� �� �ؾ������� ������ ��������� ����������Ѵ�. ���Ҹ��ڴ� �Ű����� ���� X �����ε� X  ~���̸� �ȴ� Ŭ�����̸� �տ�

#include <iostream>
using namespace std;

class Complex
{
private :
	int real;
	int image;
public :
	Complex(int r = 0, int i = 0);
	~Complex();
	void ShowComplex() const;
};

Complex::Complex(int r, int i)
{
	real = r;
	image = i;
}

Complex::~Complex()
{
	cout << "�Ҹ��� ȣ��" << endl;
	system("pause");

}

void Complex::ShowComplex() const
{
	cout << real << "." << image << "i" << endl;
}

void main()
{
	Complex x(40, 20), y(2), z;
	x.ShowComplex();
	y.ShowComplex();
	z.ShowComplex();

	
	system("pause");
	return;
}
*/



/*
//�ݷ��ʱ�ȭ ;; �̰Ŵ� ����� ��������;;�� �׷���
#include <iostream>
using namespace std;
 
class Complex {
private:
	int real;
	int image;
public :
	Complex(int r = 0, int i = 0);
	void ShowComplex()const;
};

Complex::Complex(int r, int i) : real(r), image(i) // ���� �ɱ� �׷���.
{

}
*/


/*
#include <iostream>
using namespace std;

class Complex
{
private :
	int real;
	int image;
public :
	Complex(int r = 0, int i = 0); // �̷��� �Ҽ��� �ִ� . �̷��� �ϸ� ������ ���� ���۷ε� �ؼ� ������ �����ʿ䰡 ����������ִ� ��
	void ShowComplex() const;
};

Complex::Complex(int r, int i)
{
	real = r;
	image = i;
}

void Complex::ShowComplex() const
{
	cout << real << "." << image << "i" << endl;
}

void main()
{
	Complex x(40, 20), y(4), z;

	x.ShowComplex();
	y.ShowComplex();
	z.ShowComplex();

	
	system("pause");
	return;
}

*/




/*
#include <iostream>
using namespace std;
class Complex
{
private:
	int real;
	int image;
public :
	Complex();
	Complex(int r, int i);
	void ShowComplex() const;
};

Complex::Complex() // ��.. �̷� �Ǽ��� �ϴٴ�...     ������ ���Ǻκп� int real = 0; �̶�� �Լ��ȿ� ������ �� �����߾��� �� �̷��ϱ� �����Ⱚ������ , ��..
{
	real = 0;
		image = 0;
}

Complex::Complex(int r, int i)
{
	real = r;
	image = i;
}
void Complex::ShowComplex() const
{
	cout << real << "." << image << "i" << endl;
}

void main()
{
	Complex x(10, 20);
	Complex y(30, 40);
	Complex z;
	x.ShowComplex();
	y.ShowComplex();
	z.ShowComplex();

	system("pause");
	return;
}

*/




/*
// �Ű������� ���� ������
#include <iostream>
using namespace std;
class Complex
{
private: 
	int real;
	int image;
public:
	Complex(int r, int i);
	Complex();
	void ShowComplex() const;
};

Complex::Complex(int r, int i)
{
	real = r;
	image = i;
}


Complex::Complex()
{
	real = 0;
	image =0;
}

void Complex::ShowComplex() const
{
	cout << real << "." << image << "i" << endl;
}

void main()
{
	Complex x(4,7), y;

	x.ShowComplex();
	y.ShowComplex();
	
	system("pause");
	return;
}
*/






/*
//�������� �����Ϸ����� ����Ʈ �����ڸ� �ڵ����� ������������. �̰Ŵ� �����Ⱚ�� ���ܼ� ��������� �ؾ��ҰŴ� �����ؾ��Ѵ�.
#include <iostream>
using namespace std;
class Complex
{
private:
	int real;
	int image;
public:
	Complex(); //������ ����
	void ShowComplex() const;
};          

Complex::Complex() // ������ ����
{
	real = 5;
	image = 20;
}

void Complex::ShowComplex() const // const�� ShowComplex���ο��� Complex Ŭ���� ���ΰ� ���ٲٰ�
{
	cout << real << "." << image << "i" << endl;
}

int main()
{
	Complex x; // x��� ��ü�� ���鶧 ������ ����.

	x.ShowComplex();

	system("pause");
	return 0;
}
*/







/*
#include <iostream> //default initialize experiment of functions
using namespace std;
void print(int x = 99, int y = 99, int z = 99) {
	cout << x << " " << y << " " << z << endl;
	return;
}


void main() {
	

	print(1, 2, 3 );
	print(5, 6);
	print(7);
	print();

	system("pause");
	return;
}*/
/*
void print(int x, int y, int z) { // �Լ��� ����Ʈ �ʱⰪ�� ������ ����ο��� ����ߴ��. ����ٰ� ������� ��������. �̹��� �ּ� �����ص� �۵��Ѵ�. 
	cout << x << " " << y << " " << z << endl;
	return;
}// ������ ����ٰ� void print(int x=99 �̷��� ������������
*/




/*
//�Ű������� ������ �ٸ� �����ε�
#include <iostream>
using namespace std;
inline void print(int);
inline void print(int, int);
inline void print(int, int, int);

void main() {
	
	int a = 10, b = 20, c = 30;
	
	print(a);
	print(a, b);
	print(a, b, c);
	system("pause");
	return;
}
inline void print(int num) {
	cout << num << endl;
}
inline void print(int num, int num2) {
	cout << num << " " << num2 << endl;
}
inline void print(int num, int num2, int num3) {
	cout << num << " " << num2 << " " << num3 << endl;
}
*/





/*
#include <iostream> // �Ű������� �ڷ����� �ٸ� overloading
using namespace std;

void absolute(int num);
void absolute(double num);
void absolute(long int num); // long �ڷ��� long int ��� �ϴ±���.. �ٸ���.

int main() {
	
	for (int i = 0; i < 3; i++) { // �������� ������ �غ��� �����غ��ϱ� �� for���� �������̴�.
		
		switch (i) {
		case 0:absolute(-3); break;
		case 1:absolute(-4.2); break;
		default: absolute(-403000000); break;
		}
		
	}
	
	system("pause");
	return 0;
}

void absolute(int num) {
	if (num < 0)
		cout << -(num) << endl;
	cout << "int ��� �ν���" << endl;
}
void absolute(double num) {
	if (num < 0)
		cout << -(num) << endl;
	cout << "double " << endl;
}
void absolute(long int num) {
	if (num < 0)
		cout << -(num) << endl;
	cout << "long int �۵���!!!" << endl;
}
*/






/*
//�Լ���  signature  �����Ϸ��� �Լ��� �����ϴ� ������. 1.�Լ��� �̸� 2. �Ű������� ���� 3. �Ű������� �ڷ���
#include <iostream> // �Լ��� �������� �˾ƺ��� ���� �ڵ带 �ۼ��غ��ҽ��ϴ�.
using namespace std; // 

void printstr(const char *);
void printstr(char, int); //�Ű��������� ���⼭�� �������ص� �Ǵ±���..... �Ƥ�,,,,����?

int main()
{
	printstr("Sorry i'm sorry"); // �� c++ å �� ��ģ���ϳ� .    "sorry i'm sorry" �̰� ���ڿ� ����� ��� const �ù�  �׷��� ����ϴ� �Լ��� �ǳ��ٶ� �� �Ű����� �ڷ������ٰ� const �ٿ����� ��....
	printstr('a', 4);
	system("pause");
	return 0;

}
void printstr(const char *the_string) {
	cout << the_string << endl;
}
void printstr(char the_char, int repeat_cnt) { // �ϸ鼭 ������ ����.. ��� root �� ���� �н��ؾ߰ڴ�... �׸��̾�..
	for (int i = 0; i < repeat_cnt; i++)
		cout << the_char << endl;

}
*/






/*
//class ����
#include <iostream>
using namespace std;
class Complex // Complex Ŭ���� ����
{
private: 
	int real;
	int image;

public:
	void SetComplex(); // public Complex Ŭ���� ����Լ� ����
	void ShowComplex() const; // ShowComplex �Լ��� ��ü ������ ���� �ƹ��͵� �����ϸ� �ȵǴ� �Լ��̴� �׷��Ƿ� const ���� �տ��� ������Ѵ�.
	inline void SetReal(int r); // real image�� ���� ���� �Է��Ҽ��ְ� �Ѵ�.
	void SetImage(int i); // ���ῡ ���� �ȿ��ٰ� ���Ǳ����ϸ� �װ��� inline �Լ��� �ȴ�. ª�� �Լ��϶��� inline ����� �������� �� �ؼ� ��ư ȿ���� ���� ��� ū�Ÿ��� ���α׷��� �뷮�� Ŀ����. ��������� inline �����൵ �ȴ�.
};

void Complex::SetComplex() {
	real = 3;
	image = 6;
}
void Complex::ShowComplex() const {
	cout << "print Complex " << endl;
	cout << real << "." << image << "i" << endl;
}
inline void Complex::SetReal(int r) {   // ����� inline �����ָ� �ȴ�.
	real = r;
}
void Complex::SetImage(int i) {
	image = i;
}
int main()
{
	Complex x, y;

	x.SetComplex();
	y.SetComplex();
	
	y.SetReal(1);
	y.SetImage(2);

	x.ShowComplex();
	y.ShowComplex();

	system("pause");
	return 0;
}
*/



// ����ü �迭�� call by reference �� �Լ��� ���� �����ϴ� �̷���
/*
void func(structTest (&ref)[100] // �̰� �����Ͱ� �ƴ϶� ���۷����� �� �迭�� ũ�⸦ ����������.
{
refer[0].weight = 10;
}

func(test)   // ȣ�� call
*/




/*
1. ������ �����ϱ� ���� ����ü�� �����϶� ����ü �̸� stuRecord > ������� name kor eng mat tot ave
2. 1�� ������ �ʱⰪ �ְ� ������ ����� ���ϰ�(3. �̰� �� �Լ��� ������ ����) �̸� ����Ϸ� 4. ��µ� �Լ��� �϶� prn 5.�Էµ� init �Լ� ���� �Ҽ��ְ� �׳� ���������� ����� �̾��� ���� �ֵ��� ����ü �迭��
���ξƤö�������ʸ���������;�Ӥ�������;�Ӥ��ȷ�; �Ӿƴ� ���� strcpy �� ���� �ȴٰ� ���� ���� �� ���η� ������ å ��������� �� ���о��� ���η� �ƴ� ���η� �����ε鵵 �Ȱ�������̾߹�ģ �ɱ����� ���� ������ ���� �̲��̲� ���������� ����
���� ����� ���ϰ� ��Ҹ��� ���η� ��� ������ ���
*/
/*
#include <iostream>
#define headnum 3
using namespace std;
struct sturecord {
	char name[20];
	int kor;
	int eng;
	int mat;
	int tot;
	double ave;
};

void init(sturecord *p, int num);
void cal(sturecord *p, int num);
void prn(sturecord *p, int num);

int main() {

	sturecord a[headnum]; // a��� ���ڵ屸��ü �迭 ���� 
	
	init(a, headnum); //init ȣ��
	prn(a, headnum); //prn ȣ�� ��� headnum ��ũ�λ���� �����ؼ� �Լ� �Ű������� �������� �ʿ�� ���µ� �׳� ��г��� ����.

	system("pause");
	return 0;
}

void init(sturecord *p, int num) {
	cout << endl << " init �Լ� ȣ��0��°�� �ʱ�ȭ���� ����" <<endl;
	strcpy_s(p[0].name, "ȫ�浿");
	p[0].kor = 82;
	p[0].eng = 93;
	p[0].mat = 91;

	for (int i = 1; i < headnum; i++) {
		cout <<"\n"<< i << endl;
		cout << "�̸� �Է�";
		cin >> p[i].name;
		cout << "\n���� �Է�";
		cin >> p[i].kor;
		cout << "\n���� �Է�";
		cin >> p[i].eng;
		cout << "\n���� �Է�";
		cin >> p[i].mat;
	}
	cout << endl << "��� ���� cal() �Լ� ȣ��"<<endl;
	cal(p, headnum);
	cout << endl << "main �Լ��� ����" << endl;
	return;
}

void cal(sturecord *p, int num) {
	for (int i = 0; i < headnum; i++) {
		p[i].tot = p[i].kor + p[i].eng + p[i].mat;
		p[i].ave = (double)((double)(p[i].tot) / 3);
	}
	cout << endl << "��� �� init()�Լ��� ����";
	return;
}

void prn(sturecord *p, int num) {
	cout << endl << "prn �Լ� ȣ��... �л��� �����̴�." << endl;
	cout << "\t�̸�\t����\t����\t����\t����\t���\n";
	for (int i = 0; i < headnum; i++) {
		cout << "\t" << p[i].name << "\t" << p[i].kor << "\t" << p[i].eng << "\t" << p[i].mat << "\t" << p[i].tot << "\t" << p[i].ave << "\n";
	}
	
	cout << "\n�������� ����\n";
	return;
}
// �� ��foot�������
*/