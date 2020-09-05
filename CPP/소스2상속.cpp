













//����
/*
#include <iostream>
using namespace std;

class Base {
public:
	virtual void prn();
	// void prn(); // virtual �Ⱥ��̸� ������ �Ű����������ͺ����� ���� ���󰣴�. 
};
void Base::prn()
{
	cout << "Base Prn" << endl;
}

class Derived : public Base {
public:
	void prn();
};

void Derived::prn() {
	cout << "Derived Prn" << endl;
}

void func1(Base &bRef) {
	bRef.prn();
}

void func2(Base *bPtr) {
	bPtr->prn();
}

void main()
{
	Base bObj;
	Derived dObj;
	func1(bObj);
	func1(dObj);

	func2(&bObj);
	func2(&dObj);
}
*/









/*
#include <iostream>
using namespace std;

class Parent {
protected:
public:
	void prn();
	~Parent() {}; //��ĳ���û�Ȳ������ �Ҹ��� ���������� �����Լ�ó����
};

void Parent::prn() {
	cout << "Parent Method" << endl;
}

class Child : public Parent {
public:
	void prn();
};
void Child::prn() {
	cout << "Child Method" << endl;
}

void main()
{
	{
		Parent pObj;
		Child cObj;
		Parent *pPtr = &cObj; // �Ͻ��� ��ĳ���� ����
		pPtr->prn();
		cObj.prn();
	}

	// Child *cPtr = &pObj; // �ٿ�ĳ���� �ȵ�.
	// Child *cPtr = (Child *)&pObj; �ϵ簡 ��� ��������
	
	Parent * pPtr = new Child; //�����Ҵ� delete ������� ������ ��ĳ�����̱⶧���� �Ļ��Ҹ��ڰ� ȣ��ɼ��ְ� �����Լ�ó��������� ��ݿ��ٰ�
	Child *cPtr = (Child *)pPtr;
	cPtr->prn();
	pPtr->prn();

	delete pPtr;


	return;
}
*/





/*

//�Ϲ� �Ҹ����� ������ Ŭ���� ��ĳ���û�Ȳ�� 
#include <iostream>
using namespace std;

class Base {
public:
	Base() { cout << "��� Ŭ���� ������" << endl; }
	virtual ~Base() { cout << "��� Ŭ���� �Ҹ���" << endl; }
};

class Derived : public Base {
public:
	Derived() { cout << "�Ļ� Ŭ���� ������" << endl; }
	~Derived() { cout << "�Ļ� Ŭ���� �Ҹ���" << endl;}
};

void main() {

	Base *BasePtr = new Derived; // �̷��� new �����Ҵ����� �������� ������ delete �� �Ἥ ���־��Ѵ�.
	delete BasePtr;
	
	return;
}
// ��� Ŭ���� ������   ������ ��������δ� �Ļ�Ŭ���� �Ҹ��ڰ� ȣ���� �ȵȴ�. �ֳ��ϸ� �������ε��� ���ؼ�
// �Ļ� Ŭ���� ������   BasePtr �� BaseŬ���� ���̱⶧���� ��ư �׷���. �����ڴ� ������ ���� .
// ��� Ŭ���� �Ҹ���
// �׷��� �Ҹ��ڵ� �����Լ��� �����Ͽ�   ����Ҹ��ڸ� ���������Ѵ�. ~Base() �ʿ��ٰ� virtual �� �ٿ�����

*/




/*

#include <iostream>
using namespace std;

class Shape { //�߻�Ŭ������ �ν��Ͻ��� �����Ҽ�����. ������ ������ ������ ������ �����ϴ�. �̿Ͱ��� �������� �������� ��¼��..
protected:
	double area;
public:
	virtual void Draw() = 0;
	virtual double GetSize() = 0;
};

class Rect : public Shape {
protected:
	int width;
	int height;
public:
	Rect(int new_width =0, int new_height=0);
	void Draw();
	double GetSize();
};
Rect::Rect(int new_width, int new_height) {
	width = new_width;
	height = new_height;
}
void Rect::Draw() {
	cout << "�簢���� �׸���" << endl;
}

double Rect::GetSize() {
	int Area = width * height;
	return Area;
}


class Circle : public Shape {
protected:
	int radius;
public:
	Circle(int new_radius=0);
	void Draw();
	double GetSize();
};
Circle::Circle(int new_radius) {
	radius = new_radius;
}
void Circle::Draw() {
	cout << "���� �׸���" << endl;
}
double Circle::GetSize() {
	int Area = radius * radius * 3.14;
	return Area;
}

void CommonPrn(Shape * ptr)
{
	ptr->Draw();
	cout << "ũ��" << ptr->GetSize() << endl;
}

int main()
{
	Rect RectObj(8, 3);
	RectObj.Draw();
	cout << "ũ��" << RectObj.GetSize() << endl;

	Circle CircleObj(6);
	CircleObj.Draw();
	cout << "ũ��" << CircleObj.GetSize() << endl;

	CommonPrn(&RectObj); // �Ϲ��Լ� CommonPrn ȣ��   �Ű������� Shape ������ ������ �޴´�. ��ĳ����
	CommonPrn(&CircleObj); // ������ �׽�Ʈ 
	system("pause");
	return 0;
}

*/








// ���� �����Լ��� pure virtual function  �Լ��� ���� ���� �Լ��� �������� ���Ŭ������ �����س��°��̴�
// ex) virtual ��ȯ fuction() = 0;
// ���� �����Լ��� �ּ� �Ѱ� �̻� ���� Ŭ�����δ� ��ü�� �����������Ѵ�.
// ���࿡ ��ü�� �����Ǹ� �Լ��� ���ǰ� ���� ��� �������� �𸣴� ���� �����Լ��� ȣ���� ���� �ֱ� �����̴�. �׷���
// �̸� �����ϱ� ���� ���� �����Լ��� ���� Ŭ�����δ� ��ü�� ���������� ���ϵ��� �ϰ� �̸� �߻�Ŭ����(Abstract Class)��� �θ���.
// ����� ���� ���Ŭ������ ���δ�.
// �Ļ�Ŭ������ �ݵ�� �� ��� Ŭ������ �����Լ����� �������̵� �ؾ��Ѵ�. �ƴϸ� �ڱ� �ڽŵ� �߻�Ŭ������ �Ǿ������.



/*
#include <iostream>
using namespace std;
class Calc {
protected:
	int a;
	int b;
public:
	Calc();
	Calc(int new_A, int new_B);
	virtual void Prn()const; // ��� Ŭ�������� Prn()�� �����Լ��� ����
};
Calc::Calc()
{
	a = 0;
	b = 0;
}
Calc::Calc(int new_A, int new_B)
{
	a = new_A;
	b = new_B;
}
void Calc::Prn()const
{
	cout << "Calc Prn" << endl;
	cout << a << "NulL" << b << endl;
}

class Add : public Calc{
protected:
	int c;
public:
	Add();
	Add(int new_A, int new_B);
	void Sum();
	void Prn()const;
};
Add::Add()
{
	a = 0;
	b = 0;
	c = 0;
}
Add::Add(int new_A, int new_B) : Calc(new_A, new_B)
{
	c = 0;
}
void Add::Sum()
{
	c = a + b;
}
void Add::Prn()const
{
	cout << "Add Prn" << endl;
	cout << a << "+" << b << "=" << c << endl;
}


int main()
{
	Calc *CalcPtr;
	Add AddObj(3, 10);
	CalcPtr = &AddObj; // �Ͻ��� ��ĳ����
	AddObj.Sum();
	//CalcPrn->Sum(); // �̰͵� �ϰ�������� Sum()�� ���Ŭ������ CalcŬ������ �����Լ��� �����صθ�ȴ� ����
	CalcPtr->Prn(); // ���� �����Ϸ��� �и��� Calc::Prn() ����Ű���ִ� ������ �����Լ��̱⶧����...
	AddObj.Prn();
	system("pause");
	return 0;
}
*/




//������ �ܰ迡���� ������ �ڷ��� �̷��Ÿ� ����, �߿�����  �� �����鿡 �� ������ �ʴ´�. 
// �� ��°Ŵ� ���� �ܰ迡�� �ϴ°ű⶧�� ��ư
// �����ϴܰ迡�� �Լ��� ȣ���� �����ϱ�   
// �Լ��� �⺻������ �������ε��� ��        ��ư �����ϴܰ迡�� CalcPtr->Prn(); �ϸ� �ϴ� CalcPtr�� ������ ����Ű������ �𸣰� �߿��������ʴ� �ܰ���
// �׷��� ������ �ܰ迡�� Calc::Prn()���� �����ǰ� �̿� ���� ����ܰ迡���� Calc::Prn �� ȣ��ȴ� ���� ���ε� ����

// �׷��� �̸� �ذ��ϱ� ���ؼ��� �������ε��� �ؾ��Ѵ�. ����ܰ迡�� �̸� ��������!!! ���� �ǰ� ��ǻ�����忡���� �ǰ��ҵ�.
// ���� ���ε��� �ϰ��� �ϴ� �Լ� �տ� virtual ���� ���̸� �ȴ�. �̶� virtual ���� ���� �Լ��� '�����Լ�' ��� �Ѵ�.
// ��ư ���Ŭ���� Prn ���� virtual ���̸� �Ļ�Ŭ������ Prn���� �����Լ�Ư¡�� ��ӵȴ�.

//��� �����Լ��� ���Ŭ������ �������̵��� �Լ� �տ� virtual�� ���̸� �ȴ�.
// virtual  ����� �Լ�    �����ϴܰ迡�� �ش� �Լ��� ���������ʴ´ٰ� �ϸ� �����ͺ����� Ŭ���������� ȣ��� �Լ��� �����������ϴٰ�
// ���� ������ ��ü ������ ������ � ��ü�� ����Ű�� �ִ��Ŀ� ���� � �Լ��� ���ε����� ������ �� �ֵ��� �Ѵ�.


/*

//�� ĳ���ð� �������̵�
// �� ĳ������ CalcPtr �� �������̵��� Prn�Լ� ȣ���ϸ� �����ͺ��� ���������� ����� �ڷ����� Prn�� ȣ��ȴ�   Calc::Prn();
// �̰� �Ͼ�� ������ ���ε� ���������ε� ��¼����¼�� �̸� �ذ��Ұ� �����Լ� ��¼��
#include <iostream>
using namespace std;
class Calc {
protected:
	int a;
	int b;
	int c;
public:
	Calc(int new_A, int new_B);
	Calc();
	void Prn()const;

};
Calc::Calc(int new_A, int new_B) { a = new_A; b = new_B; c = 0; }
Calc::Calc() { a = 0; b = 0; c = 0; }
void Calc::Prn()const
{
	cout << a << "NULL" << b << c << endl;
}

class Add : public Calc {
public:
		Add(int new_A, int new_B);
		Add();
		void Sum();
		void Prn()const;
};
Add::Add(int new_A, int new_B) : Calc(new_A, new_B){}
Add::Add() : Calc(){}
void Add::Sum() { c = a + b; }
void Add::Prn()const
{
	cout << a << "+" << b << "=" << endl;
}



int main()
{
	
	Add AddObj(70, 12);
	AddObj.Sum();
	Calc *CalcPtr = &AddObj; // �Ͻ��� ����ȯ     ��ĳ����

	// �� ���¿��� Prn�� ȣ���غ���

	CalcPtr->Prn();


	// Calc::Prn(); �� ȣ��ȴ�.
	// �׷� �����ͺ����� �ڷ����� �ƴ϶� ��ü �ν��Ͻ��� �ڷ����� ���ؼ� ȣ��� �Լ��� �����Ϸ��� ��� �ؾ��ұ�...????
	// �ٷ� �̷� �䱸�� ���ؼ� ��������� �����Լ�����.   �� �� �� �� virtual functions
	// �����Լ��� ��ü�� ������ Ŭ�������� ���ؼ� �Լ��� ȣ��ɼ��ְ� ���ش�. 
	// �׷��� ���ؼ� �Լ��� ���ε��� ���ؼ� �˾ƺ���. 

	system("pause");
	return 0;

}

*/






/*
// �� ĳ���ð� �ٿ� ĳ����
// �� ĳ������ ���Ŭ���������Ͱ�ü������ =  & AddObj     �Ļ�Ŭ������ü�� �ּҸ� �����ϴ°�츦 ��ĳ�����̶���Ѵ�.
// ���� ���Ŭ������ �� �Ļ�Ŭ������ �Ʒ��ε�   �����ϴ� ȭ��ǥ�� ���� ���ϴϱ�   ��ĳ�����̶� �Ѵ�.
// ��ĳ���� ���� main() �� �ؿ� �ٿ�ĳ���� ���� ����
#include <iostream>
using namespace std;
class Calc {
protected:
	int a;
	int b;
	int c;
public:
	Calc(int new_A, int new_B);
	Calc();
	void CalcPrn()const;
};
Calc::Calc(int new_A, int new_B) { a = new_A; b = new_B; c = 0; }
Calc::Calc() { a = 0; b = 0; c = 0; }
void Calc::CalcPrn()const { cout << a << "Null" << b << "=" << c << endl; }
 
class Add : public Calc {
public :
	Add(int new_A, int new_B);
	Add();
	void Sum();
	void AddPrn()const;
};
Add::Add(int new_A, int new_B) : Calc(new_A, new_B){}
Add::Add() : Calc(){}
void Add::Sum()
{
	c = a + b;
}
void Add::AddPrn()const
{
	cout << a << "+" << b << "=" << c << endl;
}

class Mul : public Calc {
public:
	Mul(int new_A, int new_B);
	Mul();
	void Times();
	void MulPrn()const;
};
Mul::Mul(int new_A, int new_B) : Calc(new_A, new_B){}
Mul::Mul():Calc(){}
void Mul::Times() {
	c = a * b;
}
void Mul::MulPrn()const
{
	cout << a << "*" << b << "=" << c << endl;
}


int main()
{

	Mul MulObj(3, 12);
	MulObj.Times();

	Calc *CalcPtr;
	CalcPtr = &MulObj; // ��ĳ������ �Ͻ������� �Ͼ    CalcPtr = &(Calc)MulObj; ������   
	// ��ĳ�������ϸ�
	// 1. �Ļ���ü�� �����Ͱ� ��ݰ�ü�� �����ͷ� ����ȯ�Ǵ°���
	// 2. �� ĳ������ �ϸ� ���� ������ ������ ���Ŭ������ ������ ��ҵȴ�.
	// 3. �� ĳ������ �����Ϸ��� ���ؼ� �ڵ� ����ȯ �ȴ�.
	
	CalcPtr->CalcPrn();
	//CalcPtr->MulPrn();
	// CalcPtr �� �Ļ�Ŭ������ ����Լ��� ����Ҽ����°Ͱ���.

	cout << "//***********************************" << endl;
	cout << " ������� �ٿ� ĳ���� ����" << endl;
	// �ٿ� ĳ������ ��ݰ�ü�� �ּҸ� �Ļ�Ŭ������ü�����Ϳ� ����ִ°ǵ� 
	// �����Ϸ��� �ڵ����� ����ȯ �����ش�. ���� �׳� �ϸ� ������ ��������.

	Calc Obj(4, 3);
	Add * AddPtr;
	// AddPtr = &Obj; // ������ ��������.
	//  Calc ��ü�� ���� �����Ǹ� Calc Ŭ������ ���ؼ� ������ ������ Calc ����������
	// Add ��ü�� ���� ������ �������� �ʴ´�.
	// ���࿡ �����Ϸ��� ������ �ȻѸ����� �����ͺ����� ���ؼ� ���������� �ʴ� ������ �����Ϸ����ϴ� ��ó���� ���� ��Ȳ�� �Ͼ. 
	
	// ���� ����ȯ  ������ ����������ȯ �ϸ� �ȵȴ�.  ������ ���� ��쿡�� ���ش�.
	
	Calc *CalcPtr = new Add(5, 7); // �����ͺ��� CalcPtr �� ���ο� Add ��ü�� ����Ų��. ���⼭ ��ĳ���õȴ�.
								   // ���⼭�� CalcPtr �� Calc Ŭ���� ����� ���� �����ϴ�.
								   // CalcPtr->Sum(); �����̰� CalcPtr->AddPrn(); ���� �����̴�
                                   // Add * AddPtr = CalcPtr;   �� �ϸ� �ȵȴ�. ������ ���� �ؾ��Ѵ�.
	
	Add *AddPtr = (Add *)CalcPtr; // �ٿ�ĳ���� ��������� ����ȯ ������Ѵ�. �ٿ�ĳ�����Ϸ��� �ö󰬴� ���������Ѵ�..
	// ���Ŭ������ü�� �ּҸ� �Ļ�Ŭ������ü�����ͺ����� �����ϴ� ������ �ٿ�ĳ������ �Ҽ����ִµ� �������� �����Ͽ����� ���Ҽ��־ ����뿡�������ܴ�.
	// ex) AddPtr = (Add *)&CalcObj;
	



	system("pause");
	return 0;
}
*/





/*
// ���������� * ���������� + ����ϰ�ʹ�. �׷��� ���Ŭ������ Prn()����Լ���  �������̵��ϸ�ȴ�. �����ε��� �ƴϴ�. �����ε��� �Ű������� �ٸ������ִ°Ű�
// �������̵��� ���Ǹ� �ٽ��ϴ°Ŵ�.
#include <iostream>
using namespace std;
class Calc {
protected:
	int a;
	int b;
	int c;
public:
	Calc(int new_A, int new_B);
	Calc();
	void Prn()const;
};
Calc::Calc(int new_A, int new_B)
{
	a = new_A; b = new_B; c = 0;
}
Calc::Calc()
{
	a = 0; b = 0; c = 0;
}
void Calc::Prn()const
{
	cout << a << "NULL" << b << " " << c << endl;
}

class Add : public Calc {
public:
	Add(int new_A, int new_B);
	Add();
	void Sum();
	void Prn() const; // Prn() �Լ� �������̵�
};
Add::Add(int new_A, int new_B) : Calc(new_A, new_B)
{}
Add::Add() : Calc()
{}
void Add::Sum() {
	c = a + b;
}
void Add::Prn()const {
	cout << a <<"+" << b << "=" << c << endl;
}

class Mul : public Calc {
public:
	Mul(int new_A, int new_B);
	Mul();
	void Times();
	void Prn() const; // overriding
};
Mul::Mul(int new_A, int new_B) : Calc(new_A, new_B){}
Mul::Mul() : Calc() {}
void Mul::Times()
{
	c = a * b;
}
void Mul::Prn() const
{
	cout << a << "*" << b << "=" << c << endl;
}


int main()
{
	Add x(4, 6);
	Mul y(3, 7);
	Calc z(3, 4);
	
	x.Sum();
	x.Prn();
	x.Calc::Prn(); // �������̵��ص� �̷��� ���Ŭ������ ����Լ��� �����ͼ� �����ִ�..

	y.Times();
	y.Prn();
	y.Calc::Prn();


	z.Prn(); // �ٵ� ���Ŭ������ü������ �Ļ�Ŭ�������� �����ü������°Ͱ��� ����
	
	system("pause");
	return 0;
}
*/








/*
#include <iostream>
using namespace std;
class Calc {
protected:
	int a;
	int b;
	int c;
public:
	Calc(int new_A, int new_B);
	Calc();
	void Prn()const;
};
Calc::Calc(int new_A, int new_B)
{
	a = new_A;
	b = new_B;
	c = 0;
}
Calc::Calc()
{
	a = 0; b = 0; c = 0;
}
void Calc::Prn()const
{
	cout << a << " " << b << " " << c << endl;
}

// public ���� ���� �����غ���
class Add : public Calc{
public:
	Add();
	Add(int new_A, int new_B);
	void Sum();
};
Add::Add() : Calc() // ��������� ����Ʈ ������ ȣ�� �ֳ��ϸ� ���Ŭ������ �Ű������ִ� �����ڰ� �־�׷�
{
}
Add::Add(int new_A, int new_B) : Calc(new_A, new_B) // ���� ����ϰ� ��
{
}
void Add::Sum()
{
	c = a + b;
}


void main(){
	Add x(4, 2), y;
	x.Sum();
	y.Sum();
	x.Prn();
	y.Prn();

	system("pause");
	return;
}
*/



/*
//��Ӽ� 
//private ���Ŭ������ ����
//protected: ������     �Ļ�Ŭ������ ���Ŭ������ ��밡��
//public ��� ����    ������ ����   private < protected < public 

//���Ŭ���� ���� ���� 
//���� ���� Ŭ������ ����� �κ��� ���Ŭ������ ���� ���� �ϸ�ȴ�.

#include <iostream>  

using namespace std;
class Calc { //���Ŭ����  Calc
protected:
	int a;
	int b;
	int c;
	char flag; // �� �Ļ�Ŭ������ �����ڰ� flag ��������� �ڱ��� ������ ����
public:
	Calc();
	~Calc();
	void Init(int new_A, int new_B);
	void Prn()const;
};
Calc::Calc() { // ��Ӱ��迡���� �����ڰ� ��ٷӴ� ������ �Ʒ��� �س��ڴ�.  
	a = 0;
	b = 0;
	c = 0;
	flag = '\0';
	cout << "��� ������ ȣ��"<<endl;
} // �����ڴ� ����Լ������� ��� �Ұ���,   �Ļ���ü�� �����ɶ� ���Ŭ������ �����ڱ��� �ڵ�ȣ���
// �Ļ� ��ü �����ϸ�   ��ݻ����� -> �Ļ�������    �Ҹ궧��    �Ļ��Ҹ��� -> ��� �Ҹ��� ������ ȣ���.
Calc::~Calc() {
	cout << "��� �Ҹ��� ȣ��"<<endl;
	system("pause");
}
void Calc::Init(int new_A, int new_B)
{
	a = new_A;
	b = new_B;
}
void Calc::Prn()const
{
	cout << a << "\t" << flag << "\t" << b << " = " << c << endl;
}

// class Add : public ���� �ϸ� ���Ŭ���� ������� ������ �״�� �������ִ�. 
class Add : public Calc { //Clac�� �Ļ�(derlived)Ŭ���� Add
public:
	Add();
	~Add();
	void Sum();
};
Add::Add()
{
	flag = '+';
	cout << "�Ļ�add ������ ȣ��"<<endl;
}
Add::~Add()
{
	cout << "�Ļ�add �Ҹ��� ȣ��"<<endl;
	system("pause");
}
void Add::Sum()
{
	c = a + b;
}



class Mul : public Calc { // Calc�� �Ļ�Ŭ���� Mul
public:
	Mul();
	~Mul();
	void Times();
};
Mul::Mul()
{
	flag = '*';
	cout << "�Ļ�Mul ������ ȣ��" << endl;
	
}
Mul::~Mul()
{
	cout << "�Ļ�Mul �Ҹ��� ȣ��"<<endl;
	system("pause");
}

void Mul::Times()
{
	c = a * b;
}

//���߿� �Ļ�Ŭ���� ��ü ������ �����Ҷ�  

 //Add::Add(int new_A, int new_B) : Calc(new_A, new_B)
 //{
 ////���� �ƹ��͵� ���ص��ȴ�. �ֳ��ϸ� ���Ŭ���������ڰ� ȣ��Ǵ°ſ� ���� �������ִ°ű⶧����  
 //// ���࿡ ��ݻ����ڶ� �Ļ������ڶ� �ϴ� ���� ����ϸ� �̷��� �Ѱ��ִ°͵� �ص��ȴ�.
 //}





void main() 
{
	
	Add x; // �Ļ�Ŭ������ ��ü�� ���鶧 ���Ŭ������ ����Ʈ �����ڸ� ȣ���Ѵ�   ex testClass();   �䷯��   ���࿡ ���Ŭ������   testClass(int a, int b) �̷��� ������
	Mul y; // �����Ϸ��� ����Ʈ �����ڸ� ȣ���ؾ��ϴµ� ��ã�Ƽ� �������� �׷��� �Ű����� �ΰ��ִ� �����ڸ� ��������ϸ��� �Ű��������� ����Ʈ�����ڵ� ���������Ѵ�.

	x.Init(4, 2);
	x.Sum();
	x.Prn();

	y.Init(600, 3);
	y.Times();
	y.Prn();

	
	system("pause");
	return; // ���⿡ �������������� �Ҹ��ڵ� ȣ��Ǳ� ������ 
}
*/

