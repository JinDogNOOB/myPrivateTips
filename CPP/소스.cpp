
/*
#include <iostream>
using namespace std;
void test(int *p);

void main()
{
	int a[2] = { 1,2, };
	test(a);
	system("pause");
	return;
}

void test(int *p)
{
	cout << p[0];
	cout << p[1];
	return;
}
*/



/*
void cal(stuRecord* p, int num);
void prn(stuRecord* p, int num); // &temp = stu[0] �����δ� �Ǵµ� 
�׳� �迭 �̸� ��ü�� �ѱ�°Ŵ� �ȵǳ� �׷��ϱ� call by address �ٲ��ȴ��  �迭�� �ȴ볪����..�������� ���ä��� �ñ��ϴ�
*/
/*
1. ������ �����ϱ� ���� ����ü�� �����϶� ����ü �̸� stuRecord > ������� name kor eng mat tot ave
2. 1�� ������ �ʱⰪ �ְ� ������ ����� ���ϰ�(3. �̰� �� �Լ��� ������ ����) �̸� ����Ϸ� 4. ��µ� �Լ��� �϶� prn 5.�Էµ� init �Լ� ���� �Ҽ��ְ� �׳� ���������� ����� �̾��� ���� �ֵ��� ����ü �迭�� 
*/
/*
#include <iostream>
using namespace std;
struct stuRecord {
	char name[20];
	int kor;
	int eng;
	int mat;
	int tot;
	double ave;
};
void initial();

int main() {


	return 0;
}
*/

/*
int main()
{
	stuRecord stu[headnum]; // stu ����ü �迭 ����
	
	cin >> stu[0].name;

	init(stu, headnum); //init ȣ�� 
	
	system("pause");
	
	return 0;


}
// ����ü�迭�� �ּҷ� �Լ��� �� 
*/


 
/*
// 2���� ����ü �迭
#include <iostream>
#define ROW 2
#define COL 3
using namespace std;
struct namecard {
	char name[20];
	char job[20];
};

void main() {
	namecard a[ROW][COL];
	namecard (*p)[COL];
	p = a;
	
	cout << endl << "�Է�" << endl;
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++) {
			cout << "\n �ַο� ������ ��� " << endl;
			cin >> *(*(p + i) + j)->name;
			cin >> *(*(p + i) + j)->job; // �ַο� ������ ���

			cout << "\n �� ������ ��� " << endl;
			cin >> (*(*(p + i) + j)).name;
			cin >> (*(*(p + i) + j)).job;
		}

	cout << endl << "���" << endl;
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++) {
			cout << "\n �ַο� ������ ��� " << endl;
			cout << *(*(p + i) + j)->name << endl;
			cout << *(*(p + i) + j)->job << endl; // �ַο� ������ ���

			cout << "\n �� ������ ��� " << endl;
			cout << (*(*(p + i) + j)).name << endl;
			cout << (*(*(p + i) + j)).job << endl;
		}

	system("pause");
	return;
}
*/




/*
// ����ü �迭 
#include <iostream>
using namespace std;
#define headnum 2
struct namecard {
	char name[20];
	char job[20];
	char tel[20];
	char email[50];
};

void namecardInput(namecard *p);
void namecardPrint(namecard &temp);

void main()
{
	namecard info[headnum];
	
	cout << "���� �Է� �ܰ�"<<endl;
	for (int i = 0; i < headnum; i++)
		namecardInput(&info[i]);

	cout << "���� ��� �ܰ�" << endl;
	for (int i = 0; i < headnum; i++)
		namecardPrint(info[i]);

	system("pause");
	return;
}

void namecardInput(namecard *p) {
	cout << " �Է� �̸� ���� ��ȭ �̸��� ����" << endl;
	cin >> (*p).name;
	cin >> p->job;
	cin >> (*p).tel;
	cin >> p->email;
	return;
}
void namecardPrint(namecard &temp){
	cout << " ��� �̸� ���� ��ȭ �̸��� ����" << endl;
	cout << temp.name << endl << temp.job << endl << temp.tel << endl << temp.email << endl;
	return;
}
*/





// ����ü �����ʹ� (*p).member   �������� ����� ȣ���ؾ��Ѵ� �ֳ��ϸ� . �����ڰ� *�����ں��� �켱������ ����. -> �̰ɷ� �ᵵ�ȴ�.
/*
call by address 
void structInput(namecard *p){ cin >> p->name ��� �̷��� �ϸ� �ȴ�    cin >> (*p).name ����ڷ� return;
�Լ�ȣ���Ҷ� �̷��� �����ָ�ȴ�    structInput(&x); �̷��� ����
*/

/*
call by reference 
void structInput(namecard &temp) { cin >> temp.name     ��� �̷��� �ϸ� �ȴ�    �׳� ����ü ��� �θ��°�ó�� �ϸ� �ȴ� ��û���ϴ� �޸𸮵� �߰��� �Ҵ� ���ϰ� ����.    return;
*/
/*
#include <iostream>
using namespace std;
struct namecard {
	char name[20];
	char job[30];
	char tel[20];
	char email[40];
};

void structPrn(namecard temp);
namecard structInput();
void main()
{
	namecard x = structInput();
	namecard y = structInput();
	structPrn(x);
	structPrn(y);
	
	namecard *xp;
	namecard *yp;
	xp = &x;
	yp = &y;

	cout << "\n x �� ũ���" << sizeof(x);
	cout << "\n y �� ũ���" << sizeof(y);

	cout << "\n xp �� ũ���" << sizeof(xp);
	cout << "\n *xp�� ũ���" << sizeof(*xp) << endl;
	
	cout << sizeof(xp->name);

	cout << x.name << endl;
	cout << xp->name << endl;
	cout << (*xp).name << endl;

	system("pause");
	return;
}

void structPrn(namecard temp) {
	cout << temp.name << "\t" << temp.job << "\t" << temp.tel << "\t" << temp.email << endl;
	return;
}

namecard structInput() {
	namecard temp;
	cout << "�̸��� �Է��Ͻÿ�";
	cin >> temp.name;
	cout << "������ �Է��Ͻÿ�";
	cin >> temp.job;
	cout << "��ȭ��ȣ�� �Է��Ͻÿ�";
	cin >> temp.tel;
	cout << "email�� �Է��Ͻÿ�";
	cin >> temp.email;
	return (temp);
}
*/



//structInput �Լ� �����ؼ� ���� �Է��غ���
/*
#include <iostream>
using namespace std;
struct namecard {
	char name[20];
	char tel[20];
	char email[50];
};
namecard structInput(void) {
	namecard temp;
	cout << "what's your name" << endl;
	cin >> temp.name;
	cout << "what's your phone Number" << endl;
	cin >> temp.tel;
	cout << "email" << endl;
	cin >> temp.email;
	return temp;
}
void structPrint(namecard temp) {
	cout << temp.name << endl << temp.tel << endl << temp.email << endl;
	return;
}
void main() {
	namecard x;
	x = structInput();
	structPrint(x);

	system("pause");
	return;
}
*/


//structprn �Լ� �����ؼ� ��½��� �غ���
/*
#include <iostream>
using namespace std;
struct namecard {
	char name[20];
	char tel[20];
	char email[50];
};
void structprn(namecard temp);
void main() {
	namecard x = { "aaa", "aaaa" , "aaaaa" };
	namecard y = { "bbb", "bbbb", "bbbbb" };
	namecard z = { "ccc", "ccc", "ccc" };

	structprn(x);
	structprn(y);
	structprn(z);

	system("pause");
	return;
}
void structprn(namecard temp) {
	cout << temp.name << endl << temp.tel << endl << temp.email << endl;
	return;
}
*/


//����ü������ �� �����ϱ�
/*
#include <iostream>
using namespace std;
struct namecard {
	char name[20];
	char tel[20];
	char email[50];
};
void main() {
	namecard x = { "�̵���", "010-xxxx-xxxx", "mrrnd@naver.com" };
	namecard y;

	cout << x.name << "\t" << x.tel << "\t" << x.email << endl;
	cout << y.name << "\t" << y.tel << "\t" << y.email << endl;

	y = x;
	cout << y.name << "\t" << y.tel << "\t" << y.email << endl;

	system("pause");
	return;
}
*/


/*
// ����ü ������ �����Ҷ� �ʱ�ȭ�� �ء�������.
#include <iostream>
using namespace std;
struct namecard {
	char name[20];
	char tel[20];
	char email[50];
};
void main() {
	
	namecard x = { "�̵���", "1111", "lksjf@naer.coj" },
		y = { "������", "2222", "adkf@dgadf.d" },
		z = { "alsone", "3333", "skdf@dddam.cc" };
	
	cout << x.name << x.tel << x.email << endl;
	cout << y.name << y.tel << y.email << endl;
	cout << z.name << z.tel << z.email << endl;

	system("pause");
	return;
}
*///�̰Ŵ� �̰Ŵ�
//�̰Ŵ� �̰Ŵ�

/*
//struct �� �̿��ؼ� ����� �ڷ����� �����.   ��ġ int float ���� bool
// ����ü �����Ҷ� Ʋ�� ����� �Ŷ� �ʱⰪ ������ ���ϰ� ���ÿ� �޸� �Ҵ絵 �ȵȴ�.
#include <iostream>
using namespace std;
struct namecard {
	char name[20];
	char job[30];
	char tel[20];
	char email[40];
	int test[5];
};

void main()
{
	struct namecard man;

	cout << " �̸��� �Է��ϼ���. =>";
	cin >> man.name;
	cout << " ������ �Է��ϼ���. =>";
	cin >> man.job;
	cout << " ��ȭ��ȣ�� �Է��ϼ���. =>";
	cin >> man.tel;
	cout << " Email�� �Է��ϼ��� =>";
	cin >> man.email;
	for (int i = 0; i < 6; i++) {
		man.test[i] = i + 1;
	}

	cout << "\n �Է¹��� �����͸� ����մϴ�.";
	cout << "\n �̸�\t����\t����ó\t�̸���";
	cout << "\n " << man.name << "\t" << man.job << "\t" << man.tel << "\t" << man.email << endl << endl;
	
	cout << "\n sizeof(namecard) =>\t" << sizeof(namecard);
	cout << "\n sizeof(man) =>\t" << sizeof(man);
	cout << "\n sizeof(man.test) =>\t" << sizeof(man.test);

	system("pause");
	return;
}
*/



/*
// ���� �ټ��� �Է� �ް�  �ִ� �ּ� �Ǵ�
#include <iostream>
using namespace std;
int main() {
	int num[5] = { 0, };
	int misscount = 0;
	int temp = 0;

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "��° ���� �Է�"<<endl;
		cin >> num[i];
	}
	for (int i = 0; i < 5; i++) {
		
		if (num[i] > num[0]) { // �ִ븦 ���ϴ� if'
			temp = num[0];
			num[0] = num[i];
			num[i] = temp;
		}
		else if (num[i] < num[4]) { // �ּҸ� ���ϴ� if
			temp = num[5];
			num[5] = num[i];
			num[i] = temp;
		}
		else
			misscount++;

	}
	cout << "max num\t" << num[0] << endl;
	cout << "min num\t" << num[4] << endl;
	cout << "equal count" << misscount << endl;
	system("pause");
	return 0;
}
*/


/*
#include <iostream>
using namespace std;
void main() {
	int a[5];

	for (int i = 1; i < 6; i++) {
		a[i] = i * 5;
	}
	int sum = 0;
	for (int i = 1; i < 6; i++) {
		cout << a[i] << endl;
		sum += a[i];

	}
	cout << sum;
	system("pause");
	return;
}
*/


/*
#include <iostream>
using namespace std;
void main() {
	int a[3] = { 1,2,3 };
	int b[3] = { 0, };
	for (int i = 0; i < 3; i++) {
		b[i] = a[i];
	}

	for (int i = 0; i < 3; i++) {
		cout << b[i] << endl;
	}

	system("pause");
	return;
}
*/


/*
//2���� �迭�� ����ϴ� �Լ������ 
#include <iostream>
#define ROW 3
#define COL 4
using namespace std;
void prn(int (*p)[COL]);  // �̰� void prn(int p[][COL]) ������ �ص��ȴ� �ٵ�  �̰Ŵ� �Լ� �Ű����������θ� ����Ѵ� �ٸ��뼭 �̷��� ���� �����Ϸ����� �ĸ´´�.

int main() {
	int a[ROW][COL] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };

	prn(a); // prn �Ű������� �迭�ּҸ� �޴� ����Ʈ�Լ� �ٵ��̰� �����͸��� ���۷����� �ǳ�?��������

	system("pause");
	return 0;
}
void prn(int(*p)[COL]) {   
	for (int i = 0; i < ROW; i++) {
		cout << endl;
		for (int j = 0; j < COL; j++) {
			cout <<"*((p + "<<i<<") + "<<j<<") = > "<<*(*(p + i) + j) << endl;
		}
	}
	return;
}
*/


/*
#include <iostream>
using namespace std;
int main() {
	int	a[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	int(*p)[4];
	p = a;
	
	for (int i = 0; i < 3; i++) {
		cout << endl;
		for (int j = 0; j < 4; j++) {
			cout << "*(*(a + "<<i<<") + "<<j<<") = > "<<*(*(p + i) + j)<<"\t";
		}
	}
	system("pause");
	return 0;
} // 2���� �迭�̶� 2���� �����͹迭�̶� �Ȱ��� ������ ����
*/



/*
// a[i][j] == *(*(a+i)+j)
#include <iostream>
using namespace std;
#define ROW 3
#define COL 4
int main() {
	int a[ROW][COL] = { {1,2,3,0},{4,5,6,0},{7,8,9,0} };

	for (int i = 0; i < ROW; i++) {
		cout << endl;
		for (int j = 0; j < COL; j++) {
			cout << "*(*(a + " << i << ") + " << j << ") = " << *(*(a + i) + j)<<"\t";
		}
	}
	system("pause");
	return 0;
}
*/


/*
// a[i][j]  �϶�    a+1 �ϸ�      4*j ��ŭ �ּҰ� ��������. �̶��� ������� �ȴٴ� �� ������ �迭
#include <iostream>
using namespace std;
#define ROW 3
#define COL 4
int main() {
	int a[3][4] = { {90,48,65,23,}, {12,14,15,17}, {24,23,21,20	 } };
	
	cout << "\n a\t = " << a;
	cout << "\n *a\t = " << *a;
	cout << "\n **a\t = " << **a;

	cout << "\n a + 1\t = " << a + 1;
	cout << "\n a + 2\t = " << a + 2 << endl;

	system("pause");
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
#define ROW 2
#define COL	4

int main() {
	int a[ROW][COL] = { 0, };
	
	for (int i = 0; i < ROW; i++) {
		cout << "a[" << i << "] = "<< a[i]<< "\t";
		
		cout << "&a[" << i << "][0] = " << &a[i][0] << endl;

		
	}
	system("pause");
	return 0;
}
*/


/*
// 2���� �迭 �ּҰ� ���
#include <iostream>
using namespace std;
#define ROW 3
#define COL 6

int main()
{
	int a[ROW][COL] = { 0, };
	
	for (int temp = 0; temp < ROW; temp++) {
		for (int ttemp = 0; ttemp < COL; ttemp++) {
			cout << "a[" << temp << "]" << "[" << ttemp << "] = " << &a[temp][ttemp] << endl;
		}
	}
	system("pause");
	return 0;
}
*/



/*
// 2���� ������     int a    int *p      int **pp             a�� �Ϲݺ���      &a 1���� ������     p 1���� ������   &p 2���� ������  pp 2���� ������     & �� �ΰ��̻� ������, *�� ���������� ���ϼ�����   *�Ҷ����� ���� �������� & �� ���� �ö�
// ����
#include <iostream>
using namespace std;
void main() {
	int a = 20;
	int *p = &a;
	int **pp = &p;
	
	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
	cout << "p = " << p << endl;
	cout << "&p = " << &p << endl;
	cout << "pp = " << pp << endl;

	cout << " *p    and    **pp\t" << *p << "\t" << **pp << endl;
	system("pause");
	return;
}
*/





/*
// �ٸ� ǥ������ �ִ� void prn (int p[]) �� �ִ� �̰� ���� �����迭������ ����� �����Ϸ��� �ؼ��ϸ��� void prn(int *p) �̴�   �׷��ϱ�
// VOID PRN( INT P[])  ==  void prn(int *p) �̴� �׷��ϱ� �򰥸��������... �Ʒ��� ����
#include <iostream>
using namespace std;
void prn(int p[], int size);
int main()
{
	int a[5] = { 0,1,2,3,4 };
	prn(a, 5);

	system("pause");
	return 0;

}
void prn(int p[], int size) { // void prn(int p[] == void prn(int *p
	for (int i = 0; i < size; i++) {
		cout << *(p + i) << endl;
	}
}
*/


/*
#include <iostream>
using namespace std;
void prn(int *p, int num);
int main()// �Լ��� �Ű������� �����ͷ� �Ǿ��ؼ� �ּҷ� �޴´�. num �� �迭�� ũ�⸦ �ذŴ� .��.
{
	int arr[5] = { 1,2,3,4,5 };
	
	prn(arr, 5);
	system("pause");
	return 0;
}

void prn(int *p, int num) {

	for (int i = 0; i < num; i++) {
		cout << *(p + i) << endl;
	}
}
*/



/*
#include <iostream>
using namespace std;
int main()
{
	int a[5] = { 1,3,5,7,9 };
	int *ap;
	ap = a;

	cout << "\t *ap\t => \t" << *ap << endl;
	cout << "\t a[0]\t => \t" << a[0] << endl;
	
	cout << "\t *(p+1)\t => \t" << *(ap + 1) << endl;
	cout << "\t a[1]\t => \t" << a[1] << endl;

	cout << "\t *(p+2)\t => \t" << *(ap + 2) << endl;
	cout << "\t a[2]\t => \t" << a[2] << endl;
	
	system("pause");
	return 0;
}
*/


/*
#include <iostream>
using namespace std;
int main() {
	int arr[5] = { 1,3,5,7,9 }; 
	int *parr = arr;
	
	for (int i = 0; i < 5; i++) {
		cout << "arr + "<<i<<" = 0x" << arr + i << "\t&arr["<<i<<"] = 0x" << &arr[i] << endl;
	}

	for (int i = 0; i < 5; i++) {
		cout << "*(arr+i) = " << *(arr + i) << "\tarr[i] = " << arr[i] << endl;
	}

	system("pause");
	return 0;
}  
*/
/* ���� �ڵ��� ��� ���.
arr + 0 = 0x00CFF9AC    &arr[0] = 0x00CFF9AC
arr + 1 = 0x00CFF9B0    &arr[1] = 0x00CFF9B0
arr + 2 = 0x00CFF9B4    &arr[2] = 0x00CFF9B4
arr + 3 = 0x00CFF9B8    &arr[3] = 0x00CFF9B8
arr + 4 = 0x00CFF9BC    &arr[4] = 0x00CFF9BC
*(arr+i) = 1    arr[i] = 1
*(arr+i) = 3    arr[i] = 3
*(arr+i) = 5    arr[i] = 5
*(arr+i) = 7    arr[i] = 7
*(arr+i) = 9    arr[i] = 9
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/



/*
//   *a    *a+1   *(a+1) �� ���̸� �˾ƺ���.
#include <iostream>
using namespace std;
int main()
{
	int a[5] = { 1,3,5,7,9 };
	cout << "*a = " << *a << endl;
	cout << "*a+1 = " << *a + 1 << endl;
	cout << "*(a+1) = " << *(a + 1) << endl;

	system("pause");
	return 0; // ����� 1  2  3 ���´�.
}
*/



/*
#include <iostream>
using namespace std;
int main()
{
	int a[5] = { 0, };

	for (int i = 0; i < 5; i++) {
		cout << "a + " << i << " == " << a + i << "\t &a[" << i << "] == " << &a[i] << endl;
	}
	system("pause");
	return 0;
}
*/

// �迭 int a[5]       ����    a == &a[0] �̰͵� ���� �ǹ��� a �� ��ü�� �����ּҸ� �ǹ�   *a == a[0]          a+i ==    &a[i]
/*
//1���� �迭�� �ּҰ��� �˾ƺ��� short �� int �� ���� ����
#include <iostream>
using namespace std;
int main()
{
	int arrshort[5] = { 1,2,3,4,5 };
	int arrint[5] = { 6,7,8,9,10 };
	
	cout << " short �� ���\t";
	for (int i = 0; i < 5; i++)
		cout << arrshort[i] << "\t";
	cout << endl;
	cout << " short �ּ� ���\t";
	for (int i = 0; i < 5 ; i++)
		cout << &arrshort[i] << "\t";
	cout << endl;
	cout << " int �� ���\t";
	for (int i = 0; i < 5; i++)
		cout << arrint[i] << "\t";
	cout << endl;
	cout << " int  �ּ� ���\t";
	for (int i = 0; i < 5 ; i++)
		cout << &arrint[i] << "\t";
	cout << endl;

	system("pause");
	return 0;

}
*/




/*
// �����Է� ���α׷� �������� �ϱ� ���Ͽ� ROW COL�� ��ũ�λ���� �����س���.
#include <iostream>
#define ROW 3
#define COL 5
using namespace std;

int main()
{
	cout << "������ �Է����� �л� ��ȣ ���� ���� ����" << endl;
	int arr[ROW][COL] = { 0, };
		for (int i = 0; i < ROW; i++){
			arr[i][0] = i + 1;
			for (int j = 1; j < COL; j++) {
				cout << arr[i][0] << "�� �л��� "<< (j) << "�� ������ ������ �Է��ϼ���" << endl;
				cin >> arr[i][j];

			}
	}
		
		cout << "�Է� ����" << endl;
		cout << "\t��ȣ\t����\t����\t����\t" << endl;;
			for (int i = 0; i < ROW; i++) {
				cout << "\t";
				for (int j = 0; j < COL; j++) {
					cout << arr[i][j] << "\t";
				}
				cout << endl;
		}

			system("pause");
			return 0;
}
*/





/*
// 2���� �迭 
#include <iostream>
using namespace std;
int main()
{

	int arr[3][4] = { {48,59,69,48}, {98,78,37,27}, {76,25,90,89} };

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 4; c++) {
			cout << arr[r][c] << "\t";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
*/




/*
// �迭�� �̿��Ͽ� �Է¹��� 5���� ���� �ִ븦 ���ϴ� �ڵ�
#include <iostream>
using namespace std;
void main()
{

	int arr[] = { 412,123,548,239,408 };
	int max = 0;
	for (int i = 0; i < 5; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	cout << "max number is " << max << endl;
	system("pause");
	return;
}
*/




/*
//��¥ ������ �迭 
#include <iostream>
using namespace std;
void main()
{
	int arr[5];
	for (int i = 10, j=0; i > 5; i--,j++) {
		arr[j] = i;
	}

	for (int i = 0; i < 5; i++) {
		cout <<"arr["<<i<<"] = "<< arr[i] << endl;
	}
	system("pause");
	return;
}
*/



/*
// ���� ���ϱ� �Լ��� absolute �Լ��� ����µ� call by reference �� call by address �Ѵ� ������.
#include <iostream>
using namespace std;
void absoluteP(int *ap);
void absoluteR(int &br);
void main()
{
	int a = -43;
	cout << a << endl;
	absoluteP(&a);
	cout << a << endl;
	int b = -78;
	cout << b << endl;
	absoluteR(b);
	cout << b << endl;
	system("pause");
	return;
}
void absoluteP(int *ap)
{
	if (*ap < 0)
		*ap = -(*ap);
}
void absoluteR(int &br)
{
	if (br < 0)
		br = -(br);
}
*/


/*
// Call by Reference �� ����� ���� ��ȯ �Լ�
#include <iostream>
using namespace std;
void swap(int &ar, int &br);

void main()
{
	int a = 64;
	int b = 32;
	cout << a << b << endl;
	swap(a, b);
	cout << a << b << endl;
	system("pause");
	return;
}

void swap(int &ar, int &br)
{
	int temp = ar;
	ar = br;
	br = temp;
	return;
}
*/




// reference ���� ����� ����ÿ� �޸𸮿� �ö����ʴ´�. �ٽø��ϸ� �ϳ��� �ּҿ� �����̸��� ���̴°Ŵ� ������ ������ �������� ���⼭�� & ���������� ���� �����Ϳ��� ���� &�ּҿ����ڰ� �ƴϴ�!!!!!!
// ���� ����ÿ� & �̰� ���̸� ���������ڶ�� �Ǵ��ϰ�    �̹� ����� ���� �տ� & �̰� ������ �ּҿ����ڶ�� �Ǵ��Ѵٰ��Ѵ�. 
// ���۷������� �����Ҷ��� ������ �ʱⰪ ����Ѵ� �ϳ��� �����̱� ������.
/*
//���۷��� ��
#include <iostream>
using namespace std;
void main()
{
	int a = 294;
	int &b = a;
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	b = 395;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << "&a" << &a << endl;
	cout << "&b" << &b << endl;

	system("pause");
	return;
}
*/



/*
//��ȯ�Լ� call by Address	
#include <iostream>
using namespace std;
void swap(int *ap, int *bp);

void main()
{
	int a = 1;
	int b = 2;
	cout << a << b << endl;
	swap(&a, &b);
	cout << a << b << endl;

	system("pause");
	return;
	
}
void swap(int *ap, int *bp)
{
	int temp = 0;
	temp = *ap;
	*ap = *bp;
	*bp = temp;
	return;
}
*/




/*
#include <iostream>
using namespace std;
void main()
{
	int a = 40;
	int *p = &a;

	cout << a << endl;
	*p = 20;
	cout << a << endl;
	cout << *p << endl;

	a = 60;
	*p = a;
	cout << *p << endl;

	system("pause");
	return;
}
*/







/*
#include <iostream>
using namespace std;
void main()
{
	int a = 40;
	int *p = &a;
	
	cout << "a\t" << a << endl;
	cout << "&a\t" << &a << endl;
	cout << "p\t" << p << endl;
	cout << "*p\t" << *p << endl;

	system("pause");
	return;
}
*/





/*
// ������ �⺻ 
#include <iostream>
using namespace std;
void main()
{
	int a = 30;
 // int b = &a �غôµ� �Ϲ� ���������� �ּҸ� ��������������. �� ������ int *  ������ϴµ� ��
	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
	cout << "*&a = " << *&a << endl;
	cout << "&*&a = " << &*&a << endl;
    
	system("pause");
	return;
}
*/




/*
// Call by Value ���� ���� ���޹��
#include  <iostream>
using namespace std;
int sum(int x, int b);
int main()
{
	int a = 0, b = 0;
	cin >> a;
	cin >> b;
	int an = sum(a, b);
	cout << an << endl;

	system("pause");
	return 0;
}

int sum(int x, int b)
{
	int t = 0;
	t = x + b;
	return (t);
}
*/









/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@��������� ���� �⺻�̾����ϴ�.!@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/



/*
// �ΰ��� ������ �Է¹ް� ����� �Ǽ��� ��ȯ�ϴ� �Լ��� ����.
#include <iostream>
using namespace std;
double avg(int a, int b);

int main()
{
	int a = 0, b = 0;
	cout << "�� ������ �Է�";
	cin >> a;
	cin >> b;
	
	double avgfact = avg(a, b);
	cout << avgfact << endl;
	system("pause");
	return 0;
}

double avg(int a, int b)
{
	return (double)((double)(a + b) / 2);
}
*/



/*
#include <iostream>
using namespace std;
void gogodan(int dan);

int main()
{
	int temp;
	cout << "input =";
	cin >> temp;
	gogodan(temp);

	system("pause");
	return 0;
}

void gogodan(int dan)
{

	for (int i = 1; i <= 9; i++) {
		cout <<dan<<"X"<<i<<"="<<(dan*i) << endl;
	}
}
*/



/*
#include <iostream>
using namespace std;
void prn();
int main()
{
	prn();
	system("pause");
	return 0;
}
void prn()
{
	cout << "�� �̸��� YangCK�� " << endl;

}
*/







//�ڵ����� auto    �������� extern    ��������? static:�ܺ��� ���ϰ�� �ش� �ڵ����� �ȿ����� �۵� �ȿ����Ұ�� ��ư �� �޸𸮿� �Ҵ�� ���  �������ͺ��� register cpu register�� �����Ժ����� 
// #define ��ũ�� ����� ��ũ�� �Լ�      inline �Լ�  ����ó���� #�����͵� �� ó���ȴ�. �׷��� ���� �ڵ�� ��ġ�Ǽ� �����ϵǱ⶧���� ���α׷� �ӵ� ��� ������ ��. ��Ÿ �Լ��� �� ������ �״�� �����ϵǼ� �����ɸ� ... �Դٸ����ٸ���
// ex)  #define PI 3.141592      ���      #define add(x,y) 2*(x+y)  ����ڷ� inline �Լ��� �Ϲ� �Լ�ó�� �����ؼ� ����ȴ�. �ٸ� ���������� �տ��ٰ� inline �� �ٿ��ָ� �ȴ�. �������� 



/*
//for ���� �̿��Ͽ� 1! 2! .... 10! �� ���Ͽ��� �����ϸ� ���� ����ӵ��� �÷����� 
#include <iostream>
using namespace std;
int main()
{
	for (int fac = 1, fact; fac <= 10; fac++)
	{
		fact = 1;
		for (int temp = 1; temp <= fac; temp++)
			fact *= temp;

		cout << fact << endl;
	}
	system("pause");
	return 0;
}
*/





/*
//���ĺ� A to Z ���� ����ϱ� 
#include <iostream>
using namespace std;
int main()
{
	int A = (int)'A';
	int Z = (int)'Z';
	
	for (; A <= Z; A++)
		cout << (char)A<< "\t";

	system("pause");
	return 0;
}
*/




/*
// do while ��� 
#include <iostream>
int main()
{
	int a = 0;
	int sum = 0;
	

	do { // �ϴ� �����϶�.... 
		std::cout << a << std::endl;
		sum += a;
		std::cout << sum << std::endl<< std::endl;
		a++;
	} while (sum < 50);


	system("pause");
	return 0;
}
*/





/*
// while ��� ���� 1 ���� 10�� ��
#include <iostream>
using namespace std;
void main()
{
	int a = 0;
	int sum = 0;

	while (a < 11) // () ���� ���̸� ��� �϶�..
	{
		cout << "���� ���� " << a << endl;
		
		sum += a;
		a++;
	}

	cout << "���� " << sum << endl;
	system("pause");

}
*/





/*
// for ���� �̿��ؼ� ������ ���
#include <iostream>
using namespace std;
void main()
{
	for (short A = 2; A < 10; A++)
	{
		for (short a = 1; a < 10; a++)
		{
			cout << A << "X" << a << "=" << (A*a) << endl;
		}
	}

	system("pause");

}
*/





/*
// 0���� �Է����� �� ������ Ȧ���� ���ϱ�	
#include <iostream>
using namespace std;
void main()
{
	int sum = 0;
	int num = 0;
	cout << "���Է� =";
	cin >> num;

	for (int temp = 0; temp < num+1; temp++)
	{
		cout << "���� �� =" << temp;
		if (temp % 2)
			cout << "���� �� =" << (sum += temp) << endl;
		else
			cout << "���� �� =" << sum << endl;

	} // �̷��� if �� Ȧ�� ������ �ǰ� ���� ���� �ð��� ���ϸ���... for �ʱ� ���� 1�� ���������δ�1 3 5 7 ����� �ǰ� +2�� �ϸ� �ɵ��ϴ�.  

	system("pause");
}
*/





/*
// for �� 1���� 5���� ���ϱ� ���������ΰ� ����ΰ� ��ư �Ѵ� �غ��� ��������������
#include <iostream>
using namespace std;
void main()
{
	int sum = 0;
	for (int num = 0; num < 6; num++)
	{
		cout << "���� ���� " << num << "�̴�" << endl;
		cout << "���� sum�� ��" << (sum += num) << "�̴�" << endl;

	}
	system("pause");
}
*/







/*
#include <iostream>
using namespace std;

void main()
{
	int num = 0;
	cout << "������ �Է� = ";
	cin >> num;

	switch (num / 10)
	{
	case 10: cout << "100" << endl;
	case 9: cout << "90" << endl;
	case 8: cout << "80" << endl;
	case 7: cout << "70" << endl;
	case 6: cout << "60" << endl;
	default: cout << "default" << endl;
	}
	cout << "70�� break; �Ǵ�" << endl;
		
	switch (num / 10)
	{
	case 10: cout << "100" << endl; 
	case 9: cout << "90" << endl;
	case 8: cout << "80" << endl;
	case 7: cout << "70" << endl; break;
	case 6: cout << "60" << endl;
	default: cout << "default" << endl;
	}

	// ���� ��� 90 �Է������� �̳��� case 9�� ���� break; ������ ���� ��  ���� �̳��� �������� ���� ����

	system("pause");
}
*/






/*
#include <iostream>
using namespace std;

void main() // ����ġ �� ���� ���� 
{

	int num = 0;
	cout << "������ �Է��϶� : ";
	cin >> num;
	
	switch (num / 10)
	{
	case 10: cout << "������ 100�����̴�." << endl; break; //break; �� ����� switch �� �������´� �̰� ���ϸ��� ���������� �Ƹ� ������ٵ� �����غ��� ���� 
	case 9: cout << "������ 90�����̴�." << endl; break;
	case 8: cout << "������ 80�����̴�." << endl; break;
	case 7: cout << "������ 70�����̴�." << endl; break;
	case 6: cout << "������ 60�����̴�." << endl; break;
	default: cout << "������ (-���Ѵ� ~ 59) �̰ų� (110 ~ ���Ѵ�) �̴�" << endl;
	}
	system("pause");
	
}
*/











/*
#include <iostream>
using namespace std;
int main() // if �� else if �� () ���� ���� ���϶� 0�� �ƴҶ� �۵��Ѵ� ex) 1 -1 2 3 4 ��� 
{
	int num;
	
	cout << "¦������ Ȧ������ �˾ƺ� ���� �Է��Ͻÿ� : ";
	cin >> num;
	
	if (!(num % 2))
		cout << num << " �� ¦���Դϴ�\n" << endl;
	else if ((num % 2))
		cout << num << " �� Ȧ���Դϴ�.\n" << endl;
	else
		cout << "�ϳ��� ������ �Է������ʾҴ� ���ҳ��." << endl;
	

	system("pause");
	return 0;
}
*/




/*
#include <iostream>
using namespace std;
void main()
{
	int a = 5;
	cout << a++ << endl;
	cout << ++a << endl;
	cout << a-- << endl;
	cout << --a << endl;
	
	system("pause");
// 5775 ��µ�. 	
}
	*/ 




/*
// �빮�ڸ� �ҹ��ڷ� �ҹ��ڴ� �״��. ���� �ƽ������� ����ؾߴ볪..
#include <iostream>
using namespace std;	

int main()
{
	char char_temp;
	cout << "���ڸ� �Է��ض�";
	cin >> char_temp;
	int char_gap = (int)'A' - (int)'a';

	((int)char_temp < (int)'a') ? cout << "��ȯ �Ϸ� " << char((int)char_temp + (int)((int)'a' - (int)'A')) << endl : cout << "��ȯ �Ϸ� " << char_temp << endl;
	
	system("pause");
	return 0;
// �̰ɷ� �˼��ִ°Ŵ� cout ������°������� �� �̻��� ������ �� �ص� �ȴٴ°ň����������� 		
}
*/







/*
// ���ڸ� �Է��ؼ� ������ ����϶�
#include <iostream>
using namespace std;
int main()
{
	int num; // �Է¹��� ������ ���� ����
	cout << "������ ���� ���� �Է��϶�" << endl;
	cin >> num; // num �Է¹���.
	
	(num >= 0) ? cout << num << "�� ������ " << num << "�̴�" : cout << num << "�� ������ " << -num << "�̴�"; // ���� �Ǵ� ���
	
	cout << endl;
	
	system("pause");
	return 0;

}
*/




/*
#include <iostream>
using namespace std;
// ¦�� Ȧ�� �Ǵ��ϴ� �ڵ�. odd �� ¦���ε� ������ 
void main()
{

	int a;
	cout << "\nInput the number : ";
	cin >> a;

	(a%2==1) ? cout << a << " is odd number" : cout << a << " is even number"; // ���϶� �տ��� ���� . a is odd number ��� ���

	cout << endl;
	system("pause"); //vs2017 �̰� ����ģ�� �Ф�
	
	
}
*/











//�� ������ �����Ʈ�� �ĸԴ��� �˾ƺ��� �ڵ�. 
/*
#include <iostream>
using namespace std;
int main()
{
	int test_int = 30;
	short test_short = 20;
	long test_long = 40;

	float test_float = 30;
	double test_double = 40;

	char test_char = 'Q';
	char test_string[6] = "hello";
	
	bool test_bool = true;

	cout << "�̰Ŵ� �� ��ǻ�� x64ȯ�濡�� �޸𸮰� �󸶸�ŭ �Ҵ�Ǵ��� Ȯ���ϴ� �ڵ��̴پƾƾ�\n" << endl;


	cout << "test_short�� ��" << test_short << "\t test_short�� ũ��" << sizeof(test_short) << endl;
	cout << "test_int�� ��" << test_int << "\t test_int�� ũ��" << sizeof(test_int) << endl;
	cout << "test_long�� ��" << test_long << "\t test_long�� ũ��" << sizeof(test_long) << endl;
	
	cout << "test_float�� ��" << test_float << "\t test_float�� ũ��" << sizeof(test_float) << endl;
	cout << "test_double�� ��" << test_double << "\t test_double�� ũ��" << sizeof(test_double) << endl;
	
	cout << "test_char�� ��" << (char)test_char << "\t test_char�� ũ��" << sizeof(test_char) << endl;
	cout << "test_string�� ��" << test_string << "\t test_string�� ũ��" << sizeof(test_string) << endl;
	cout << "test_string�� �� ������ �ϳ��� �غ���, \t" << test_string[1] << "\t" << test_string[5]<< endl;

	cout << "test_bool�� ��" << test_bool << "\t test_bool�� ũ��" << sizeof(test_bool) << endl;



	system("pause");
	
	return 0;
	
}
*/











//this ������ ���� 
/*#include <iostream>
#include <string>
using namespace std;


class inventory {
	char item[20];
	double cost;
	int on_hand;

public:
	inventory(char *i, double c, int o)
	{
		strcpy(this->item, i); //this ������ ���
		this->cost = c;
		this->on_hand = o;
	}
	void show();

};

void inventory::show()
{
	cout << this->item;
	cout << ": $" << this->cost;
	cout << "  On hand: " << this->on_hand << "\n";

}

int main()
{
	inventory object(wrench, 4.95, 4);

	object.show();

	system("pause");
	return 0;
}*/









/*
#include <stdio.h>// �� iostream ����� �Ⱥ���
#include <iostream>	//.h ���̸� �ȴ� ������ <> ��⶧���ε� ������ �̰� ����ִ������̶� �׷��Ŷ�� ���� ���� ������� ���ִµ�

int main()
{
	int fact = 1;
	for (int i = 1; i < 6; i++)
		fact *= i;
	printf("factorial = %d \n", fact);
	system("pause"); //�Ȳ����� �ϴ� �ڵ���
	return 0;
}
/*�� � ������
�������
*/
// �׳� �ּ�  just comment 
//�����


/*

#include <iostream>
using namespace std;


int main() {


	int i, j;
	double d;



	i = 10;
	j = 20;
	d = 99.101;

	cout << "here are some values: ";
	cout << i << ' ' << j << ' ' << d;

	cin >> i;
	cin >> j;
	cin >> d;

	system("pause");

	return 0;





}




*/

/*

#include <iostream>
#include <string>
using namespace std;


class inventory {
	char item[20];
	double cost;
	int on_hand;

public:
	inventory(char *i, double c, int o) // const �ٿ����� ���� �׷��� �۵���  ���� 2019 
	{
		strcpy(this->item, i); //this ������ ���
		this->cost = c;
		this->on_hand = o;
	}
	void show();

};

void inventory::show()
{
	cout << this->item;
	cout << ": $" << this->cost;
	cout << "  On hand: " << this->on_hand << "\n";

}

int main()
{
	inventory object("wrench", 4.95, 4);

	object.show();

	system("pause");
	return 0;
}
*/
