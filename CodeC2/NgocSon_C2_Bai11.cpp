//#include <iostream>
//#include <conio.h>
//#define Max 100
//using namespace std;
//struct Node  
//{
//	int info;
//	Node* link;
//};
//Node  *front , *rear; //fornt vị trí xóa, rear vị trí thêm
//void init()
//{
//	front = NULL;
//	rear = NULL;
//}
//void input(int& x)
//{
//	cout << "- Nhap gia tri can them: ";
//	cin >> x;
//}
//void process_list()
//{
//	Node* p = front;
//	while (p != NULL)
//	{
//		cout << p->info;
//		p = p->link;
//		if (p != NULL)
//			cout << ",";
//	}
//}
//void Push(int value)
//{
//	Node* p = new Node;
//	p->info = value;
//	p->link = NULL;
//	if (rear == NULL)
//		front = p;
//	else
//		rear->link = p;
//	rear = p;
//}
//int Pop(int &x)
//{
//	if (front != NULL)
//	{
//		Node* p = new Node;
//		x = p->info;
//		front = front->link; // dời phần tử ra sau 
//		if (front == NULL)
//			rear = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;	
//}
//int isEmpty()
//{
//	if (front != NULL)
//		return 1;
//	return 0;
//}
//void Delete_queue()
//{
//	while (front != NULL)
//	{
//		Node* p = front;
//		front = front->link;
//		delete p;
//	}
//	cout << "Xoa phan tu trong danh sach thanh cong " << endl;
//}
//void Menu()
//{
//	int op, x;
//	bool flag = false;
//	do
//	{
//		system("cls");
//		cout << "===========MENU===========" << endl;
//		cout << "1.Khoi tao queue " << endl;
//		cout << "2.Duyet danh sach " << endl;
//		cout << "3.Them phan tu vao queue " << endl;
//		cout << "4.Xoa phan tu khoi queue " << endl;
//		cout << "5.Kiem tra queue rong " << endl;
//		cout << "7.Xoa het phan tu trong queue " << endl;
//		cout << "6.Thoat chuong trinh  " << endl;
//		cout << "==========================" << endl;
//		cout << "Moi ban chon chuc nang: ";
//		cin >> op;
//		switch (op)
//		{
//		case 1:
//			init();
//			cout << "==Khoi tao danh sach thanh cong==" << endl;
//			flag = true;
//		   break;
//		case 2:
//			if (flag)
//			{
//				cout << "-> Danh sach: ";
//				process_list();
//			}
//			else
//				cout << "<!>Vui long khoi tao danh sach truoc " << endl;
//		   break;
//		case 3:
//			if (flag)
//			{
//				input(x);
//				Push(x);
//				cout << "==>Them phan tu vao queue thanh cong " << endl;
//			}
//			else
//				cout << "<!>Vui long khoi tao danh sach truoc " << endl;
//			break;
//		case 4:
//			if (flag)
//			{
//				if (Pop(x))
//					cout << "==>Xoa phan tu khoi queue thanh cong " << endl;
//				else
//					cout << "-->Xoa phan tu khoi queue khong thanh cong " << endl;
//			}
//			else
//				cout << "<!>Vui long khoi tao danh sach truoc " << endl;
//			break;
//		case 5:
//			if (flag)
//			{
//				if (isEmpty())
//					cout << "==>Danh sach co phan tu " << endl;
//				else
//					cout << "-->Danh sach rong " << endl;
//			}
//			else
//				cout << "<!>Vui long khoi tao danh sach truoc " << endl;
//			break;
//		case 6:
//			if (flag)
//			{
//				Delete_queue();
//			}
//			else
//				cout << "<!>Vui long khoi tao danh sach truoc " << endl;
//			break;
//		case 7: 
//			cout << "<==THOAT CHUONG TRINH==>" << endl;
//			break;
//		default: 
//			cout << "<!>Khong co chuc nang " << endl;
//		}
//		_getch();
//	} while (op != 6);
//}
//int main()
//{
//	Menu();
//	system("pause");
//	return 0;
//}