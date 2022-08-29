#include<iostream> 
#include <conio.h>
#define Max 100 
using namespace std;
//Khởi tạo danh sách
void init(int arr[], int& stack)
{
	stack = -1;
}

void inputX(int &value)
{
	cout << "Nhap phan tu can them: ";
	cin >> value;
}

void process_list(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
		if (i < n - 1)
		{
			cout << ", ";
		}
	}
}

int  isEmpty(int arr[], int stack)
{
	if (stack != -1)
		return  1; 
	return  0;
}

int isFull(int arr[], int stack)
{
	if (stack != Max - 1)
		return 1;
	return 0;
}

int Push(int arr[], int& stack, int value)
{
	if (stack < Max - 1)
	{
		arr[++stack] = value; 
		return 1;
	}
	return 0;
}

int Pop(int arr[], int& stack, int value)
{
	if (stack != -1)//stack khác rỗng
	{
		value = arr[stack--];
		return 1;
	}
	return 0;
}

void Menu()
{
	int arr[Max], stack, value;
	int op;
	bool check = false;
	do 
	{
		system("cls");
		cout << "\n\t\t==========MENU==========\n";
		cout << "\t\t1.Khoi tao danh sach \n";
		cout << "\t\t2.Kiem tra stack day\n";
		cout << "\t\t3.Kiem tra stack rong\n";
		cout << "\t\t4.Them phan tu vao stack\n";
		cout << "\t\t5.Lay phan tu khoi stack\n";
		cout << "\t\t6.Duyet danh sach hien tai\n";
		cout << "\t\t7.Thoat chuong trinh\n";
		cout << "\t\t===========================\n";
		cout << "=> Moi ban lua chon: ";
		cin >> op;
		switch (op)
		{
			case 1: 
				init(arr, stack);
				cout << "=> Khoi tao danh sach thanh cong\n";
				check = true;
				break;
			case 2:
				if (check)
				{
					if(isFull)
						cout << "=> Danh sach chua  day\n";
					else
						cout << "<!> Danh sach da day\n";
				}
				else
					cout << "<!> Vui long khoi tao danh sach truoc\n";
				break;
			case 3:
				if (check)
				{
					if (isEmpty)
						cout << "=>Danh sach da co phan tu\n";
					else
						cout << "<!> Danh sach chua co phan tu\n";
				}
				else
					cout << "<!> Vui long khoi tao danh sach truoc\n";
				break;
			case 4:
				if (check)
				{
					inputX(value);
					int result = Push(arr, stack, value);
					if(result)		
						cout << "=> Them phan tu vao stack thanh cong\n";
					else 
						cout << "<!> Them phan tu vao stack khong thanh cong\n";
				}
				else
					cout << "<!> Vui long khoi tao danh sach truoc\n";
				break;
			case 5:
				if (check)
				{
					if (Pop(arr, stack, value))
						cout << "=> Xoa phan tu vao stack thanh cong\n";
					else
						cout << "<!> Xoa phan tu vao stack khong thanh cong\n";
				}
				else
					cout << "<!> Vui long khoi tao danh sach truoc\n";
				break;
			case 6:
				if (check)
				{
					process_list(arr, stack+1);
				}
				else
					cout << "<!> Vui long khoi tao danh sach truoc\n";
				break;
			
			default:
				cout << "=>Khong co chuc nang<=" << endl;
		}
		_getch();
	} while (op != 7);
}
int main()
{	
	Menu();
	return 0;
}