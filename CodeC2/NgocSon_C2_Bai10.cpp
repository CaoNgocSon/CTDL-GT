#include <iostream> 
#include <conio.h>
using namespace std;
struct Node
{
	int info; 
	Node* link;
};
Node* stack;

void inputX(int& value)
{
	cout << "- Nhap gia tri can them: ";
	cin >> value;
}
void init()
{
	stack = NULL;
}

void Push(int value)
{
	Node* p = new Node;
	p->info = value;
	p->link = stack;
	stack = p;
}

int Pop(int& value)
{
	if (stack != NULL)
	{
		Node* p = stack;
		value = p->info;
		stack = p->link;
		delete p;
		return 1;
	}
	return 0;
}

int isEmpty()
{
	if (stack != NULL)
		return 1;
	return 0;
}

void Delete_Stack()
{
	while (stack != NULL)
	{
		Node* p = new Node;
		stack = stack->link;
		delete p;
	}
}

int Dec_Bin(int Dec)
{
	if (stack != NULL)
		Delete_Stack();
	int Bin = 0;
	while (Dec != 0)
	{
		int temp = Dec % 2;
		Push(temp);
		Dec /= 2;
	}
	int res;
	while (stack != NULL)
	{
		if (!Pop(res))
			return INT_MIN;
		Bin = Bin * 10 + res;
	}
	return Bin;
}

void process_list()
{
	Node* p =  stack;
	while (p != NULL)
	{
		cout << p->info;
		p = p->link;
		if (p != NULL)
			cout << ",";
	}
}

void menu()
{
	int op, value, temp;
	bool check = false;
	do
	{
		system("cls");
			cout << "\n\t\t============MENU============" << endl;
			cout << "\t\t 1.Khoi tao stack " << endl;
			cout << "\t\t 2.Them phan tu vao stack " << endl;
			cout << "\t\t 3.Lay phan tu ra khoi stack " << endl;
			cout << "\t\t 4.Kiem tra stack rong " << endl;
			cout << "\t\t 5.He 10 to he 2 " << endl;
			cout << "\t\t 6.Duyet danh sach " << endl;
			cout << "\t\t 7.Thoat chuong trinh " << endl;
			cout << "\t\t=============================" << endl;
			cout << "=> Moi ban chon chuc nang: ";
			cin >> op;
			switch (op)
			{
				case 1:
					init();
					cout << "=> Khoi tao danh sach thanh cong\n";
					check = true;
					break;
				case 2:
					if (check)
					{
						inputX(value);
						Push(value);
						cout << "=> Them phan tu vao stack thanh cong " << endl;
					}
					else
						cout << "<!> Vui long khoi tao danh sach truoc " << endl;
				 break;
				case 3:
					if (check)
					{
						if (Pop(value))
							cout << "=> Xoa phan tu khoi stack thanh cong " << endl;
						else
							cout << "<!> Xoa phan tu khoi stack khong thanh cong " << endl;
					}
					else
						cout << "<!> Vui long khoi tao danh sach truoc " << endl;
				break;
				case 4:
					if (check)
					{
						if (isEmpty())
							cout << "=>Stack co phan tu " << endl;
						else
							cout << "<!> Stack rong " << endl;
					}
					else
						cout << "<!> Vui long khoi tao danh sach truoc " << endl;
					break;
				case 5:
					inputX(value);
					temp = Dec_Bin(value);
					if(temp != INT_MIN)
						cout << "He nhi phan: " << temp << endl;
		
					break;
				case 6:
					if (check)
					{
						cout << "- Danh sach: ";
						process_list();
					}
					else
						cout << "<!> Vui long khoi tao danh sach truoc " << endl;
					break;
				case 7:
					cout << "=>THOAT CHUONG TRING<=" << endl;
				default:
					cout << "<!> Khong co chuc nang " << endl;
			}
			_getch();
	} while (op != 7);
}
int main()
{
	menu();
	return 0;
}