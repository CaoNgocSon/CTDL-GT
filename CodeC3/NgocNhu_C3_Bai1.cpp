#include<iostream>
#include<stdio.h>
#include<ctime>
using namespace std;

//1.1
# define MAX 5000
int a[MAX];
int b[MAX];
int n;
//1.2
void input(int a[], int &n)
{
	cout << "Nhap so phan tu can dung: ";
	cin >> n;
	cout << "Nhap " << n << " phan tu: ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void inputRandom(int a[], int &n)
{
	cout << "Nhap so phan tu can dung: ";
	cin >> n;
	cout << "Nhap " << n << " phan tu hoan thanh";
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10000 + 1;
}
//1.3
void output(int a[], int n)
{
	cout << "Danh sach hien tai la: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//1.4
void insertionSort(int a[], int n)
{
	int x, i, j;
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

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void copyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

//1.5
void SelectionSort(int a[], int n)
{
	int min_pos, i, j;
	for (int i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				swap(a[min_pos], a[j]);
	}
}

//1.6
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

//1.7
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

//1.8
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
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
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}

//1.9
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
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}
void HeapSort(int a[], int n)
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
		swap(a[0], a[right]);
		right--;
		if (right > 0)
			shift(a, 0, right);
	}
}
//1.10
int Search(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i < n)
		return i;
	return -1;
}
//1.11
int binarySearch(int a[], int n, int x)
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
	return -1;
}
int main()
{
	int choice = 0;
	int x, i;
	clock_t start;
	double duration;
	cout << "--------------Bai tap chuong 3 - Bai 1 - Tim kiem va Sap xep-----------------\n";
	cout << "1.Nhap danh sach\n";
	cout << "2.Xuat danh sach\n";
	cout << "3.Sap xep tang dan bang phuong phap InsertionSort\n";
	cout << "4.Sap xep tang dan bang phuong phap SelectionSort\n";
	cout << "5.Sap xep tang dan bang phuong phap InterchangeSort\n";
	cout << "6.Sap xep tang dan bang phuong phap BubbleSort\n";
	cout << "7.Sap xep tang dan bang phuong phap QuickSort\n";
	cout << "8.Sap xep tang dan bang phuong phap HeapSort\n";
	cout << "9.Tim kiem mot phan tu bang phuong phap tim kiem tuan tu\n";
	cout << "10.Tim kiem mot phan tu bang phuong phap tim kiem nhi phan\n";
	cout << "11.Nhap danh sach ngau nhien\n";
	cout << "12.Thoat\n";
	do {
		cout << "Nhap so de thuc nhien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			input(a, n);
			break;
		case 2:
			output(a, n);
			break;
		case 3:
			copyArray(a, b, n);
			start = clock();
			insertionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep bang phuong phap InsertionSort\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian InsertionSort: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 4:
			copyArray(a, b, n);
			start = clock();
			SelectionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep bang phuong phap SelectionSort\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian SelectionSort: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 5:
			copyArray(a, b, n);
			start = clock();
			InterchangeSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep bang phuong phap InterchangeSort\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian InterchangeSort: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 6:
			copyArray(a, b, n);
			start = clock();
			BubbleSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep bang phuong phap BubbleSort\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian BubbleSort: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 7:
			copyArray(a, b, n);
			start = clock();
			QuickSort(b, 0, n - 1);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep bang phuong phap QuickSort\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian QuickSort: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 8:
			copyArray(a, b, n);
			start = clock();
			HeapSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep bang phuong phap HeapSort\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian HeapSort: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 9:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			start = clock();
			i = Search(a, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong tim thay phan tu\n";
			else
				cout << "Phan tu " << x << " tai vi tri a[" << i << "]\n";
			if (duration > 0)
				cout << "Thoi gian tim kiem: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 10:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			start = clock();
			i = binarySearch(b, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong tim thay phan tu\n";
			else
				cout << "Phan tu " << x << " tai vi tri b[" << i << "]\n";
			if (duration > 0)
				cout << "Thoi gian tim kiem: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 11:
			inputRandom(a, n);
			cout << endl;
			break;
		case 12:
			cout << "Goodbye\n";
			break;
		default:
			break;
		}
	} while (choice != 13);
	return 0;
}