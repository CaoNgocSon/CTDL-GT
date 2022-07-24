#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#define Max 5000
using namespace std;
void inputArr(int a[], int &n)
{
	do
	{
		cout << "- Nhap kich thuoc mang: ";
		cin >> n;
		if (n< 1 || n > Max)
			cout << "Vui long nhap tu 1 den " << Max << endl;
	} while (n < 1 || n > Max);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
	/*	cout << a[i];
		if (i < n - 1)
			cout << ", ";*/
		a[i] = rand() % 100 + 1;
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
void insertionSort(int a[], int n)
{
	int x, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
// Độ phúc tạp của thuat toán la: o(n^2)

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void selectionSort(int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		if (min != i)
			swap(a[min], a[i]);
	}
}
// Độ phúc tạp của thuat toán la: o(n^2)

void interchanSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}
// Độ phúc tạp của thuat toán la: o(n^2)

void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])  
				swap(a[j], a[j - 1]);
}
// Độ phúc tạp của thuat toán la: o(n^2)

void quickSort(int a[], int left, int right)
{
	int i, j, x;
	x = a[(left + right) / 2];
	i = left;
	j = right;
	while (i <= j) 
	{
		while (a[i] < x)
			i++;
		while (a[j] > x) 
			j--;
		if (i <= j)
		{ 
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		quickSort(a, left, j);
	if (i < right)
		quickSort(a, i, right);
}
// Độ phúc tạp của thuat toán la: o(n logn)

void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;

	if (j >= n)
		return;
	if (j + 1 < n)
		if (a[j] < a[j + 1])
			j++;
	if (a[i] >= a[j])
		return;

	else 
	{
		swap(a[i], a[j]);
		shift(a, j, n);
	}
}

void heapSort(int a[], int n)
{
	int i = n / 2;
	while (i >= 0)
	{
		shift(a, i, n - 1);
		i--;
	}

	int right = n - 1;
	while (right > 0)
	{
		if (a[0] > a[right])
			swap(a[0], a[right]);
		right--;
		if (right > 0)
			shift(a, 0, right);
	}
}
// Độ phúc tạp của thuat toán la: o(n logn)

void inputX(int &x)
{
	cout << "\n- Nhap x can tim: ";
	cin >> x;
}

int Search(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i < n)
		return i;
	return -1;
}
// Độ phúc tạp của thuat toán la: o(n)

int BinarySearch(int a[], int n, int x)
{
	int left = 0, right = n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
			return mid;
		if (x > a[mid]) 
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return -1; // không tìm thấy x trong danh sách a;
}
// Độ phúc tạp của thuat toán la: o(log n)

int main()
{
	int a[Max], n, x;
	int op;
	bool check = false;
	do
	{	
		system("cls");
		cout << "\n\t\t=====================MENU=====================\n";
		cout << "\t\t1.Khoi tao danh sach" << endl;
		cout << "\t\t2.Xuat danh sach" << endl;
		cout << "\t\t3.Sap xep tang dan theo pp insertionSort" << endl;
		cout << "\t\t4.Sao xep tang dan thep pp selectionSort" << endl;
		cout << "\t\t5.Sap xep tang dan theo pp interchanSort" << endl;
		cout << "\t\t6.Sap xep tang dan theo pp bubbleSort" << endl;
		cout << "\t\t7.Sap xep tang dan theo pp QuickSort" << endl;
		cout << "\t\t8.Sap xep tang dan theo pp HeapSort " << endl;
		cout << "\t\t9.Tim kiem bang pp tuan tu" << endl;
		cout << "\t\t10.Tim kiem bang pp tim kiem nhi phan" << endl;
		cout << "\t\t11.Thoat chuong trinh" << endl;
		cout << "\t\t=============================================\n";
		cout << "- Moi ban lua chon: ";
		cin >> op;
		switch (op)
		{
		case 1:
			inputArr(a, n);
			cout << "Khoi tao danh sach thanh cong" << endl;
			check = true;
			break;
		case 2:
			if (check)
			{
				cout << "- Mang luu tru: ";
				outputArr(a, n);
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc " << endl;
			break;
		case 3:
			if (check)
			{
				cout << "\n => Mang sap xep tang dan theo insertionSort ";
				insertionSort(a, n);
				outputArr(a, n);
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc " << endl;
			break;
		case 4:
			if (check)
			{
				cout << "\n => Mang sap xep tang dan theo selectionSort: ";
				selectionSort(a, n);
				outputArr(a, n);
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc " << endl;
			break;
		case 5:
			if (check)
			{
				cout << "\n => Mang sap xep tang dan theo interchanSort: ";
				interchanSort(a, n);
				outputArr(a, n);
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc " << endl;
			break;
		case 6:
			if (check)
			{
				cout << "\n => Mang sap xep tang dan theo bubbleSort: ";
				bubbleSort(a, n);
				outputArr(a, n);
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc " << endl;
			break;
		case 7:
			if (check)
			{
				quickSort(a, 0, n - 1);
				cout << "\n => Mang sap xep tang dan bang thuat toan QuickSort: ";
				outputArr(a, n);
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc " << endl;
			break;
		case 8:
			if (check)
			{
				heapSort(a, n);
				cout << "\n => Mang sap xep tang dan bang thuat toan HeapSort: ";
				outputArr(a, n);
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc " << endl;
			break;
		case 9:
			if (check)
			{
				inputX(x);
				int result1 = Search(a, n, x);
				if (result1 != -1)
					cout << "=> Tim thay " << x << " trong mang " << endl;
				else
					cout << " <!> Khong tim thay " << x << " trong mang " << endl;
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc " << endl;
			break;
		case 10:
			if (check)
			{
				inputX(x);
				int result2 = BinarySearch(a, n, x);
				if (result2 != -1)
					cout << "=> Tim thay " << x << " trong mang " << endl;
				else
					cout << " <!> Khong tim thay " << x << " trong mang " << endl;
			}
			else
				cout << "<!> Vui long khoi tao danh sach truoc " << endl;
			break;
		case 11:
			cout << "==THOAT CHUON TRINH==" << endl;
			break;
		default:
			cout << "<!> Khong co chuc nang " << endl;
		}
		_getch();
	} while (op != 11);
	return 0;
}





