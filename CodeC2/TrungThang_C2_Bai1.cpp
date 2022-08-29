#include <iostream>
#include<conio.h>
#define Max 100
using namespace std;
void inputArr(int a[], int &n)
{
	cout << "Nhap kich thuoc mang: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
}
void outputArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
		if (i < n - 1)
			cout << ", ";
	}
}
void inputX(int &x)
{
	cout << "- Nhap x can chen/tim/xoa:  ";
	cin >> x;
}
int Search(int a[], int n, int &x)
{
	int i = 0;
	cout << "Nhap gia tri x can tim: ";
	cin >> x;
	while (i < n && a[i] != x)
	{
		i++;
		if (i == n)
			return -1;
		return  i;
	}
}
int insert_last(int a[], int &n, int x)
{
	if (n < Max)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;
}
int delete_last(int a[], int &n)
{
	if (n > 0 && n<=Max)
	{
		n--;
		return 1;
	}
	return 0;
}
int delete_pos(int a[], int& n, int i)
{
	if (i >= 0 && i < n)
	{
		for (int j = i; j < n; j++)
		{
			a[j] = a[j + 1];
		}
		n--;
		return 1;
	}
	return 0;
}
int insert_delete(int a[], int& n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			delete_pos(a, n, x);
			return 1;
		}
	}
	return 0;
}
void Menu()
{
	int a[Max], n, op, x;
	bool flag = false;
	do
	{
		system("cls");
		cout << "\n===============MENU===============\n";
		cout << "1.Nhap danh sach\n";
		cout << "2.Xuat danh sach\n";
		cout << "3.Tim kiem phan tu trong danh sach\n";
		cout << "4.Chen phan tu vao cuoi danh sach\n";
		cout << "5.Xoa phan tu cuoi danh sach\n";
		cout << "6.Xoa phan tu tai vi tri i\n";
		cout << "7.Tim va xoa phan tu(neu co)\n";
		cout << "8.Thoat chuong trinh\n";
		cout << "===================================\n";
		cout << "Moi ban chon chuc nang: ";
		cin >> op;
		switch (op)
		{
		case 1:
			inputArr(a, n);
			flag = true;
		   break;
		case 2:
			if (flag)
			{
				cout << "- Danh sach luu tru: ";
				outputArr(a, n);
			}
			else
				cout << "==>Vui long nhap danh sach truoc " << endl;
			break;

		case 3:
			if (flag)
			{
				int result = Search(a, n, x);
				if (result != -1)
					cout << "Tim thay " << x << " trong danh sach " << endl;
				else
					cout << "Khong tim thay  " << x << " trong danh sach" << endl;
			}
			else 
				cout << "==>Vui long nhap danh sach truoc<== " << endl;
			break;
		case 4:
			if (flag)
			{
				inputX(x);
				if (insert_last(a, n, x))
					cout << "Them phan tu vao cuoi danh sach thanh cong(Chon op 2 de xem kq) " << endl;
				else 
					cout << "Them phan tu vao cuoi danh sach khong thanh cong! " << endl;
			}
			else
				cout << "==>Vui long nhap danh sach truoc " << endl;
			break;
		case 5:
			if (flag)
			{
				if (delete_last(a, n))
					cout << "Xoa phan tu cuoi danh sach thanh cong(Chon op 2 de xem kq)" << endl;
				else
					cout << "Xoa phan tu cuoi danh sach khong thanh cong" << endl;
			}
			else
				cout << "==>Vui long nhap danh sach truoc<==" << endl;
			break;
		case 6:
			if (flag)
			{
				inputX(x);
				if (delete_pos(a, n, x))
					cout << "Xoa phan tu tai vi tri bat ki trong danh sach thanh cong(Chon op 2 de xem kq)" << endl;
				else
					cout << "Xoa phan tu bat ki trong danh sach khong thanh cong" << endl;
			}
			else
				cout << "==>Vui long nhap danh sach truoc<== " << endl;
			break;
		case 7:
			if (flag)
			{
				inputX(x);
				if (insert_delete(a, n, x))
					cout << "Tim va xoa thanh cong " << endl;
				else
					cout << "Tim va xoa khong thanh cong " << endl;
			}
			else
				cout << "==>Vui long nhap danh sach truoc<== " << endl;
			break;

		case 8:
			cout << "==THOAT CHUONG TRINH== " << endl;
			break;
		default:
			cout << "=>KHONG CO CHUC NANG <= " << endl;
		}
		_getch();
	} while (op != 8);
}
int main()
{	
	Menu();
	system("pause");
	return 0;
}