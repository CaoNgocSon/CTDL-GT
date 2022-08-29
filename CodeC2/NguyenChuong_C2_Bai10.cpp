#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node* link;
};
Node* sp;

void init()
{
	sp == NULL;
}

int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}

int Push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
	return 1;
}

int Pop(int& x)
{

	if (sp != NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

void Process_stack()
{
	Node* p = sp;
	do
	{
		cout << p->info << " <-- ";
		p = p->link;
	} while (p != NULL);
	cout << "\n ";
}

int main()
{

	int choice, x;
	int i;
	do
	{
		system("cls");
		cout << "1. Khai bao cau truc stack \n "
			<< "2. Them mot phan tu  \n "
			<< "3. Lay mot phan tu  \n "
			<< "4. Kiem tra stack rong hay khong \n "
			<< "5. Xuat stack  \n "
			<< "6. Thoat \n ";
		cout << " Vui long chon so de thuc hien ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << " Khoi tao Stack thanh cong ";
			break;
		case 2:
			cout << " Nhap phan tu can them ";
			cin >> x;
			i = Push(x);
			if (i == 1)
			{
				cout << " Them " << x << " vao stack thanh cong ";
				cout << " Stack sau khi them la: " << endl;
				Process_stack();
			}
			else
				cout << " Them khong thanh cong " << endl;
			break;
		case 3:
			cout << " Nhap phan tu can lay ra   ";
			cin >> x;
			i = Pop(x);
			if (i == 1)
			{
				cout << " Lay ra tu stack thanh cong, gia tri lay ra la  " << x;
				cout << " Stack sau khi lay ra  la: " << endl;
				Process_stack();
			}
			else
				cout << " Lay khong thanh cong " << endl;
			break;
		case 4:
			i = isEmpty();
			if (int i = 1) cout << " Stack rong \n";
			else
				cout << " Stack khong rong  \n ";
			break;
		case 5:
			cout << " Stack la " << endl;
			Process_stack();
			break;
		case 6:
			cout << " Goodbye " << endl;
			break;
		default:
			cout << " Khong co lua chon ";
			break;
		}
		system("pause");
	} while (choice != 7);
	return 0;
}