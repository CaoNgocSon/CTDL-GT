#include <iostream>
#define  MAX 100
using namespace std;

//viet thu tuc khoi tao queue rong
void init(int a[], int& front, int& rear)
{
	front = -1;
	rear = -1;
}
//viet thu tuc kiem tra queue rong 
int isEmpty(int a[], int front, int rear)
{
	if (rear == front)
		return 1;
	return 0;
}
//viet thu tuc kiem tra queue day
int isFull(int a[], int front, int rear)
{
	if ((front == 0 && rear == MAX - 1) || (front - rear == 1))
		return 1;
	return 0;

}
//viet thu tu them mot phan tu vao queue
int Push(int a[], int& front, int& rear, int x)
{
	if (rear - front == MAX - 1)
		return 0;
	else
	{
		if (front == -1)
			front = 0;
		if (rear == MAX - 1)
		{
			for (int i = front; i <= rear; i++)
				a[i - front] = a[i];
			rear = MAX - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
}
//viet thu tuc xoa mot phan thu trong stack
int Pop(int a[], int& front, int& rear, int x)
{
	if (front == -1)
		return 0;
	else
	{
		x = a[front++];
		if (front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
}


// xaut stack
void Process_stack(int a[], int f, int r)
{
	cout << "front= " << f << "\t rear=" << r << endl;
	if (f <= r && f != -1)
	{
		cout << " <-- ";
		for (int i = f; i < r + 1; i++)
			cout << a[i] << " <-- ";
		cout << "<-- \n";
	}

}

void menu()
{
	cout << "1. Khai bao cau truc Queue \n "
		<< "2. Them mot phan tu  \n "
		<< "3. Lay mot phan tu  \n "
		<< "4. Kiem tra Queue rong hay khong \n "
		<< "5. Kiem tra Queue day hay khong  \n "
		<< "6. Xuat Queue \n "
		<< "7. Thoat \n ";

}

int main()
{
	int a[MAX];
	int choice, f, r, x;
	int i;
	do
	{
		system("cls");
		menu();
		cout << " Vui long chon so de thuc hien ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(a, f, r);
			cout << " Khoi tao queue thanh cong ";
			system("pause");
			break;
		case 2:
			cout << " Nhap phan tu can them ";
			cin >> x;
			i = Push(a, f, r, x);
			if (i == 1)
			{
				cout << " Them " << x << " vao queue thanh cong ";
				cout << " Queue sau khi them la: " << endl;
				Process_stack(a, f, r);
			}
			else
				cout << " Them khong thanh cong " << endl;
			system("pause");
			break;
		case 3:
			cout << " Nhap phan tu can lay ra   ";
			cin >> x;
			i = Pop(a, f, r, x);
			if (i == 1)
			{
				cout << " Lay ra tu queue thanh cong, gia tri lay ra la  " << x;
				cout << " Queue sau khi lay ra  la: " << endl;
				Process_stack(a, f, r);
			}
			else
				cout << " Lay khong thanh cong " << endl;
			system("pause");
			break;
		case 4:
			i = isEmpty(a, f, r);
			if (int i = 1) cout << " Queue khong rong \n";
			else
				cout << " Queue rong  \n ";
			system("pause");
			break;
		case 5:
			i = isFull(a, f, r);
			if (int i = 1) cout << " Queue khong day  \n";
			else
				cout << " Queue day  \n ";
			system("pause");
			break;
		case 6:
			cout << " Queue la " << endl;
			Process_stack(a, f, r);
			system("pause");
			break;
		case 7:
			cout << " Goodbye " << endl;
			system("pause");
			break;
		default:
			cout << " Khong co lua chon ";
			system("pause");
			break;

		}

	} while (choice != 7);
	return 0;
}