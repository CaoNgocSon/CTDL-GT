#include<iostream>
using namespace std;
//khai bao cau truc stack
# define MAX 100
int a[MAX];
// khoi tap stack rong
void init(int a[],int &sp)
{
	sp = -1;
}
// kiem tra stack rong
int isEmpty(int a[],int sp)
{
	if (sp== -1)
		return 1;
	return 0;
}
//kiem tra stack day
int isFull(int a[],int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}
// them mot phan tu vao stack
int Push(int a[], int& sp, int x)
{
	if(sp<MAX-1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
// lay mot phan tu ra stack
int Pop(int a[], int& sp, int& x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
// xuat stack
void Process_stack(int a[], int sp)
{
	for (int i = 0; i < sp + 1; i++)
		cout << a[i] << "<--" << endl;
}
int main()
{

	int choice,sp,x,i;
	system("cls");
	cout << "--Bai tap 5 chuonng 2--";
	cout << "1.Khoi tao Stack rong" << endl;
	cout << "2.Them phan tu vao Stack" << endl;
	cout << "3.Lay phan tu ra khoi Stack" << endl;
	cout << "4.Kiem tra Stack rong hay khong" << endl;
	cout << "5.Kiem tra stack co day hay khong" << endl;
	cout << "6.Xuat Stack" << endl;
	cout << "7.Thoat" << endl;
	do
	{
		cout << "vui long nhap lua chon";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a, sp);
			cout << "khoi tao thanh cong!!!" << endl;
			break;
		case 2:
			cout << "Nhap phan tu can them x=";
			cin >> x;
			i = Push(a, sp, x);
			
				if (i == 1)
				{  
					cout << "Them thanh cong x=" << x << "vao Stack" << endl;
				cout << "Stack sau khu them la" << endl;
				Process_stack(a, sp);
			    }
			    else 
				cout << "Them phan tu khng thanh cong";
				break;
		case 3:
			i = Pop(a, sp, x);
			if (i == 1)
			{
				cout << "Lay ra phan tu trong Stack thanh cong, gia tri lay ra la x=" << x << endl;
				cout << "Stack sau khi lay ra mot phan tu la:" << endl;
				Process_stack(a, sp);
			}
			else
				cout << "Lay ra khong thanh cong" << endl;
			break;
		case 4:
			i = isEmpty(a, sp);
			if (i == 1)
				cout << "Stack rong"<<endl;
			else
				cout << "Stack khong rong" << endl;
			break;
		case 5:
			i = isFull(a, sp);
			if (i == 1)
				cout << "Stack day" << endl;
			cout << "Stack khong day" << endl;
			break;
			case 6:
				Process_stack(a, sp);
				break;
			case 7:
				cout << " chuong trinh ket thuc" << endl;
				break;
			default:
				break;
		}
	} while (choice!=7);
	return 1;
}