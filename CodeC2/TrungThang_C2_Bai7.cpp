//#include <iostream>
//#include <conio.h>
//#define Max 100
//using namespace std;
//void init(int a[], int& front, int& rear)
//{
//	front = -1;
//	rear = -1;
//}
//
//void input(int& x)
//{
//	cout << "- Nhap gia tri can them: ";
//	cin >> x;
//}
//
//void process_list(int a[], int front, int rear)
//{
//	for (int i = front; i <= rear; i++)
//	{
//		cout << a[i];
//		if (i < rear)
//			cout << ","; 
//	}
//}
////pp t?nh ti?n
//int push(int a[], int& front, int& rear, int x)
//{
//	if (rear - front == Max - 1) //h�ng ??i ??y
//		return 0;
//	else
//	{
//		if (front == -1) //h�ng ??i r?ng 
//			front = 0;
//		if (rear == Max - 1) //h�ng ??i tr�n
//		{
//			for (int i = front; i <= rear; i++)
//				a[i - front] = a[i];
//			rear = Max - 1 - front;
//			front = 0;
//		}
//		a[++rear] = x;
//		return 1;
//	}
//}
////pp t?nh ti?n
//int pop(int a[], int& front, int& rear, int x)
//{
//	if (front != -1) // h�ng ??i kh�c r?ng
//	{
//		x = a[front++];
//		if (front > rear)
//		{
//			front = -1;
//			rear = -1;
//		}
//		return 1;
//	}
//	return 0;
//}
////c? ch? v�ng 
//int pushAround(int a[], int& front, int& rear, int x)
//{
//	if (rear - front == Max - 1 || rear - front == -1) //h�ng ??i ??y
//		return 0;
//	else
//	{
//		if (front == -1) //h�ng ??i r?ng
//			front = 0;
//		if (rear == Max - 1) //h�ng ??i ??y
//			rear = -1;
//		a[++rear] = x; //th�m ph?n t? m?i t?i rear
//	}
//	return 1;
// }
//int popAround(int a[], int& front, int& rear, int x)
//{
//	if (front != -1)
//	{
//		x = a[front];
//		if (front == rear)
//		{
//			front = -1;
//			rear = -1;
//		}
//		else
//		{
//			front++;
//			if (front > Max - 1)
//				front = 0;
//		}
//		return 1;
//	}
//	return 0;
//}
//int isEmpty(int a[], int front)
//{
//	if (front != -1)
//		return 1;
//	return 0;
//}
//int isFull(int a[], int front, int rear)
//{
//	if (rear - front != Max - 1)
//		return 1;
//	return 0;
//}
//void Menu()
//{
//	int a[Max], front, rear,x;
//	int op;
//	bool flag = false;
//	do
//	{
//		system("cls");
//		cout << "\n\t\t==============MENU==============" << endl;
//		cout << "\t\t1.Khoi tao danh sach queue" << endl;
//		cout << "\t\t2.Duyet danh sach queue" << endl;
//		cout << "\t\t3.Kiem tra queue rong " << endl;
//		cout << "\t\t4.Kiem tra queue day " << endl;
//		cout << "\t\t5.Them phan tu bang pp tinh tien " << endl;
//		cout << "\t\t6.Xoa phan tu bang pp tinh tien " << endl;
//		cout << "\t\t7.Them phan tu bang pp vong " << endl;
//		cout << "\t\t8.Xoa phan tu bang pp vong " << endl;
//		cout << "\t\t9.Thoat chuong trinh " << endl;
//		cout << "\t\t==========================" << endl;
//		cout << "=> Moi ban chon chuc nang: ";
//		cin >> op;
//		switch (op)
//		{
//		case 1:
//			init(a, front, rear);
//			cout << "=> Khoi tao danh sach thanh cong";
//			flag = true;
//			break;
//		case 2:
//			if (flag)
//			{
//				cout << "- Danh sach: ";
//				process_list(a, front, rear);
//			}
//			else 
//			cout << "<!> Vui long khoi tao danh sach truoc " << endl;
//			break;
//		case 3:
//			if (flag)
//			{
//				if (isEmpty(a, front))
//					cout << "=> Danh sach da co phan tu " << endl;
//				else
//					cout << "-> Danh sach rong " << endl;
//			}
//			else
//			cout << "<!> Vui long khoi tao danh sach truoc " << endl;
//			break;
//		case 4:
//			if (flag)
//			{
//				if (isFull(a, front, rear))
//					cout << "==>Danh sach chua day " << endl;
//				else
//					cout << "-->Danh sach da day " << endl;
//			}
//			else 
//			cout << "<!> Vui long khoi tao danh sach truoc " << endl;
//			break;
//		case 5:
//			if (flag)
//			{
//				input(x);
//				if (push(a, front, rear, x))
//					cout << "=>Them thanh cong bang pp tinh  tinh tien" << endl;
//				else
//					cout << "->Khong the them " << endl;
//			}
//			else 
//				cout << "<!> Vui long khoi tao danh sach truoc " << endl;
//			break;
//		case 6:
//			if (flag)
//			{
//				if (pop(a, front, rear, x))
//					cout << "=> Xoa thanh cong bang pp tinh tien " << endl;
//				else
//					cout << "-> Khong the xoa" << endl;
//			}
//			else 
//			cout << "<!> Vui long khoi tao danh sach truoc " << endl;
//			break;
//		case 7:
//			if (flag)
//			{
//				input(x);
//				if (pushAround(a, front, rear, x))
//					cout << "=>Them thanh cong bang pp vong " << endl;
//				else
//					cout << "->Khong the them " << endl;
//			}
//			else 
//				cout << "<!> Vui long khoi tao danh sach truoc " << endl;
//			break;
//		case 8:
//			if (flag)
//			{
//				if (popAround(a, front, rear, x))
//					cout << "=> Xoa thanh cong bang pp vong " << endl;
//				else
//					cout << "-> Khong the xoa" << endl;
//			}
//			else 
//				cout << "<!> Vui long khoi tao danh sach truoc " << endl;
//			break;
//		}
//		_getch();
//	} while (op != 9);
//}
//int main()
//{
//	Menu();
//	system("pause");
//	return 0;
//}