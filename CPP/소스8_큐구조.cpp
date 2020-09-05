
// ť�� ���Լ���
// ��(front)��    ��(rear)��      put get
// ���� ť�� ����ť  circular queue 
// ����ť�� �ϳ� ���ָ� �ڿ���� �� �����ο;���. ��ǻ�Ͱ� ������ �۾� �ؼ� ������
// ����ť�� �׳� �����Ͱ� ����Ű�³��� ���̶������ϸ� ��
// ���� �� ���� �������� ���� ���°� �����ϸ� �� ��
// ���� ť ����
/*
#include <iostream>
using namespace std;
#define MAX 10


class Queue {
private:
	double queueDat[MAX];
	int front;
	int rear; // ����Ű���ִ� ���ذ���.
	bool is_this_full; // �̰� ������ �ʿ����. ����� �ִ� . 


public:
	Queue();
	bool Put(double data);
	bool Get(double &data);
	void ShowQueue();
};


Queue::Queue() {
	for (int i = 0; i < MAX; i++) {
		queueDat[i] = NULL;
	}
	front = 0; // ó���� front�� 10 rear �� 0
	rear = 0; // �� ���ù� �ΚǾ�~~~ �����ڿ��ٰ� ���������� ����� ��¼�� ������������������
	is_this_full = false;
}


bool Queue::Put(double data) {
	if (is_this_full == true) {
		cout << "ERROR: ����ť�� �� ���� ���� ������ ����."<<endl;
		return false;
	}else {
		queueDat[rear] = data;
		rear = (++rear) % MAX; // �� �Ӹ� ����.
			if (front == rear) {
				is_this_full = true;
			}
			this->ShowQueue();
			return true;
	}	
}


bool Queue::Get(double &data) {
	if (is_this_full == false && front == rear) {
		cout << "ERROR: ����ť�� �� �������� ����" << endl;
		return false;
	}else {
		data = queueDat[front];
		queueDat[front] = NULL;
		front = (++front) % MAX;
		is_this_full = false;
		this->ShowQueue();
		return true;
	}
}


void Queue::ShowQueue(){
	cout << "ShowQueue ȣ��";
	for (int i = 0; i < MAX; i++) {
	cout << i << "::" << queueDat[i] << "\t";
	}
	cout << endl;
	return;
}


void main() {
	Queue Qobj;
	double data = 20;
	bool temp = true;
	cout << "���� ��" << endl;

	Qobj.ShowQueue();

	Qobj.Put(data);
	Qobj.Put(23);
	Qobj.Put(123);
	Qobj.Put(64);
	Qobj.Put(534);

	Qobj.Put(90);
	Qobj.Put(12);
	Qobj.Put(145);
	Qobj.Put(132);
	Qobj.Put(51);

	Qobj.Put(12);
	Qobj.Put(23);

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Put(17);
	Qobj.Put(27);
	Qobj.Put(29);
	Qobj.Put(23);
	Qobj.Put(294);

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Get(data);
	cout << data << endl;

	Qobj.Put(29);
	Qobj.Put(23);
	Qobj.Put(294);
}

*/








/*
// ������ ��� ������ ����� is this full ?? �� �ʿ������ʴ�.

// ������������������ ������ ������������������ rear�� 9�϶� 9��°�� �ȳ־��� Put�ȴ�
//���������������������������������� ���� +1�� �����ڴ� Get��; �ȵ� ������������������������
// �� ������ �ؾ���.

#include <iostream>
using namespace std;
#define MAX 10

class Queue {
private:
	char queue[MAX];
	int front;
	int rear;

public:
	Queue();
	bool Put(char data);
	bool Get(char &data);
	void PrnQueue() {
		for (int i = 0; i < MAX; i++) {
			cout << i << "::" << queue[i]<<"\t";
		}
		cout << endl;
	}
};


Queue::Queue() {
	front = 0;
	rear = 0;
	for (int i = 0; i < MAX; i++) {
		queue[i] = NULL;
	}
}


bool Queue::Put(char data) {
	if (front == ((rear + 1) % MAX)) {
		cout << "ERROR: ����ť�� ����" << endl;
		return false;
	}else {
		queue[rear] = data;
		rear = ++rear % MAX;
		PrnQueue();
		return true;
	}
}


bool Queue::Get(char &data) {
	if (rear == ((front + 1) % MAX)) {
		cout <<"ERROR: ����ť�� �����" <<endl;
			return false;
	}else {
		data = queue[front];
		queue[front] = NULL;
		front = ++front % MAX;
		PrnQueue();
		cout << data << endl;
		return true;
	}
}


void main()
{
	Queue qObj;
	char Data;
	
	qObj.Put('A');
	qObj.Put('B');
	qObj.Put('C');
	qObj.Put('D');

	qObj.Get(Data);
	qObj.Get(Data);

	qObj.Put('E');
	qObj.Put('F');
	qObj.Put('G');
	qObj.Put('H');
	qObj.Put('I');
	qObj.Put('J');
	qObj.Put('K');
	qObj.Put('L');

	qObj.Put('M'); // �Ƹ� ����
	qObj.Put('M');


	qObj.Get(Data);
	qObj.Get(Data);
	qObj.Get(Data);
	qObj.Get(Data);
	qObj.Get(Data);
	qObj.Get(Data);
	qObj.Get(Data);
	qObj.Get(Data);
	qObj.Get(Data);
	qObj.Get(Data);

	qObj.Get(Data);
	qObj.Get(Data); // �Ƹ� ���� 

	qObj.Put('A'); // ����


}


*/