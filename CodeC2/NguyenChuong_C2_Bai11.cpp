#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node* link;
};
Node* front, * rear;

//Khoi tao Queue rong 
void init()
{
	front = NULL;
	rear = NULL;
}

//Kiem tra Queue rong 
int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}

//Them phan tu vao Queue
int Push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
	return 1;
}

//Lay mot phan tu
int Pop(int& x)
{
	if (front != NULL)
	{
		Node* p;
		p = front;
		x = p->info;
		front = front->link;
		delete p;
		return 1;
	}
}

// Xuat cac phan tu trong Queue 
void Process_Queue()
{
	Node* p = front;
	while (p)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}
int main()
{
	int x, choice, i;
	do
	{
		system("cls");
		cout << "\n =======Menu======= \n"
			<< " 1. Khai bao Queue \n "
			<< "2. Kiem tra Queue rong \n "
			<< "3. Them mot phan tu \n"
			<< " 4. Xoa mot phan tu \n "
			<< "5. Xuat phan tu \n "
			<< "6. Thoat \n ";

		cout << " Moi ban chon cac option tren (1->5) ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << " Khoi tao thanh cong " << endl;
			break;
		case 2:
			i = isEmpty();
			if (i == 1)
				cout << " Queue rong " << endl;
			else
				cout << " Queue khong rong " << endl;
			break;
		case 3:
			cout << " Nhap phan tu can them " << endl;
			cin >> x;
			i = Push(x);
			if (i == 1)
			{
				cout << " Them phan tu " << x << " thanh cong " << endl;
				cout << " Queue sau khi them vao la " << endl;
				Process_Queue();
			}
			else
				cout << " Them khong thanh cong " << endl;
			break;
		case 4:
			i = Pop(x);
			if (i == 1)
			{
				cout << " Lay phan tu " << x << " thanh cong " << endl;
				cout << " Queue sau khi lay ra la " << endl;
				Process_Queue();
			}
			else
				cout << " Lay khong thanh cong " << endl;
			break;
		case 5:
			cout << " Cac phan tu co trong queue la " << endl;
			Process_Queue();
			break;
		case 6:
			cout << " Cam on ban da su dung " << endl;
			break;
		default:
			cout << " Ban nhap sai option. Hay chon lai tu (1 -> 5) " << endl;
			break;
		}
		system("pause");

	} while (choice != 6);
	return 0;
}