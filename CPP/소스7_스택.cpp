// ���ñ���.
// ���� ���� first in first out 
// �׻� top�� �׻� ���Ե� �ڷḦ ������ �ڷ�� ����Ų��.
// pop() ���� ������ push()�� �ְ�.
// pop ����
// push ����

// c++�� ĸ��ȭ. Ŭ������ ���������� ��� ���ư������� ����.
// ����Լ��� �� �����ְ� �˾Ƽ� .

/*

#include <iostream>
using namespace std;

#define MAX 10

class Stack {
private:
	double item[MAX];
	int top;
public:
	Stack(); // ���ʿ� push �ɱ� top+1�� �ǹǷ�    �����ڿ��� top = -1�� �ʱ�ȭ�س���.
	bool Push(double data); // �۾��� ������ ���и� �˼��ֵ��� ��ȯ���� bool�� ����
	bool Pop(double &data); // �Ű������� �����;��ϹǷ�
	void ShowStack() {
		cout << top << endl;
		for (int i = 0; i < MAX; i++) {
			cout << i << ": " << item[i] << endl;
		}
	}
};

Stack::Stack(){
	top = -1;
}

bool Stack::Push(double data) {
	if (top >= MAX - 1) {
		cout << "Error: ������ ���� á��" << endl;;
		return false;
	}
	else {
		++top;
		item[top] = data;
		return true;
	}
}

bool Stack::Pop(double &data) {
	if (top < 0) {
		cout << "Error: ������ �����."<<endl;
		return false;
	}
	else {
		data = item[top];
		item[top] = NULL;
		--top;
		return true;
	}
}

void main()
{
	double data;
	Stack stackObj;

	stackObj.ShowStack();
	
	stackObj.Push(10);
	stackObj.Push(12);
	stackObj.Push(231);

	stackObj.ShowStack();

	stackObj.Pop(data);
	cout << data << endl;
	stackObj.ShowStack();
}

*/