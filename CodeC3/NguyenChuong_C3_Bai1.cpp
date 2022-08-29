#include <iostream>
using namespace std;
//1.1 khai bao cau truc danh sach
#define Max 100
int a[Max];
int n;
//1.2 nhap danh sach
void input(int a[],int &n)
{
	cout << "nhap so phan tu muon nhap n=" << endl;
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "phan tu thu " << i + 1 << " la: ";
		cin >> a[i];
		cout << endl;
	}
}
//1.2* tao tu dong
void init(int a[], int& n)
{
	cout << "nhap so luong phan tu cua DS: ";
	cin >> n;
	for(int i=0;i<n;i++)
	{
		a[i] = rand() % 10000 + 1;
	}
	cout << "DS them vao ngau nhien la: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
//1,3 xuat danh sach
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "phan thu thu " << i + 1 << " la: " << a[i] << endl;
	}
}
//1.4 xap xep tang dan insert sort
// swap
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void InsertionSort(int a[], int n)
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
//copy 
void copyarray(int a[], int b[],int n)
{
	for (int i=0;i<n;i++)
	{ 
		b[i] = a[i];
	}
}
//1.5 xep tang dan SelectionSort.
void SelectionSort(int a[], int n)
{
	int  min_pos, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j; 
		swap(a[i], a[min_pos]);
	}
}

//1.6 xep tang dan InterchangeSort.
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
// Cau 1.7 Bubble Sort
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(a[i], a[j - 1]);
	}
}
//1.8 Quick Sort
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j) {
			swap(a[i], a[j]);
				i++; j--;
		}
	}
	if (left < j) QuickSort(a, left, j);
	if (i < right) QuickSort(a, i, right);
}

//1.9 Heap sort
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
	int i = (n / 2) - 1;
	while (i >= 0)
	{
		shift(a, i, n);
		i--;
	}
	int r = n - 1;
	while (r > 0)
	{
		swap(a[0], a[r]);
		r--;
		if (r > 0)
			shift(a, 0, r);
	}
}
//1.10 tim kiem tuan tu
int search(int a[], int n, int x)
{
	int i = 0;
	while (i < n && i != x)
	{
		i++;
	};
	if (i < n)
		return i;
	return -1;
}
//1.11 tim kiem nhi phan
int binary_search(int a[],int n, int x)
{
	int left = 0, right = n - 1, mid;
	while(left<=right)
	 {
		mid = (left + right) / 2;
		if (a[mid] == x) return mid;
		if (x > a[mid]) left = mid + 1;
		else right = mid - 1;
     }
	return -1;
}
int main()
{
	int b[Max];
	clock_t start;
	double duration;
	int choice,x,k;
	system("cls");
	cout << "_____BT Chuong 3, Sap xep & tim kiem______________" << endl;
	cout << "0.khoi tao DS ngau nhien"<<endl;
	cout << "1.Nhap DS tu ban phim"<<endl;
	cout << "2.Xuat DS"<<endl;
	cout << "3.Xep thu tu SELECTTIN SORT"<<endl;
	cout << "4.Xep thu tu INSERT SORT"<<endl;
	cout << "5.Xep thu tu BUBBLE SORT" << endl;
	cout << "6.Xep thu tu INTERCHANDE SORT" << endl;
	cout << "7.Xep thu tu QUICK SORT" << endl;
	cout << "8.Xep thu tu HEAP SORT" << endl;
	cout<<"9.TIm kiem tua tu"<<endl;
	cout << "10.Tim kiem nhi phan" << endl;
	cout << "11>Thoat" << endl;
	do
	{
		cout << "nhap lua chon" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
		{
			init(a, n);
			break;
		}
		case 1:
		{
			input(a, n);
			break;
		}
		case 2:
		{
			cout << "DS dang co la: " << endl;
			output(a, n);
			break;
		}
		case 3:
		{
			copyarray(a, b, n);
			start = clock();
			SelectionSort(b, n);
			duration = (clock()-start )/ (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi sap xep voi SELECT SORT la" << endl;
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "Thoi gian SELECTION SORT la " << duration * 1000000 << "Miliseconds" << endl;
			}
			break;
		}
		case 4:
		{
			copyarray(a, b, n);
			start = clock();
			InsertionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi sap xep voi INSERTION SORT la" << endl;
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "Thoi gian INSERTION SORT la " << duration * 1000000 << "Miliseconds" << endl;
			}
			break;
		}
		case 5:
		{
			copyarray(a, b, n);
			start = clock();
			BubbleSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi sap xep voi BUUBLE SORT la" << endl;
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "Thoi gian BUBBLE SORT la " << duration * 1000000 << "Miliseconds" << endl;
			}
			break;
		}
		case 6:
		{
			copyarray(a, b, n);
			start = clock();
			InterchangeSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi sap xep voi INTERCHANGE SORT la" << endl;
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "Thoi gian Interchange Sort la " << duration * 1000000 << "Miliseconds" << endl;
			}
			break;
		}
		case 7:
		{
			copyarray(a, b, n);
			start = clock();
			QuickSort(b,0,n-1);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi sap xep voi Quick Sort la" << endl;
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "Thoi gian Quick Sort la " << duration * 1000000 << "Miliseconds" << endl;
			}
			break;
		}
		case 8:
		{
			copyarray(a, b, n);
			start = clock();
			HeapSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi sap xep voi Heap sort la" << endl;
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "Thoi gian Heap Sort la " << duration * 1000000 << "Miliseconds" << endl;	
			}
			break;
		}
		case 9:
		{
			cout << "nhap so can tim trong mang" << endl;
			cin >> x;
			k = search(a, n, x);
			if (k == -1) {
				cout << "khong tim thay so x=" <<x<< " trong mang"<<endl;
			}
			else {
				cout << "Da tim thay phant tu trong mang o vi tri " << k + 1 << " trong mang" << endl;
			}
			break;
		}
		case 10:
		{
			cout << "nhap phan tu ban can tin trong mang" << endl;
			cin >> x;
			k = binary_search(a, n, x);
			if (k == -1) {
				cout << "khong tim phay x=" << x << " trong mang" << endl;
			}
			else {
				cout << "da tim thay x trong mang" << endl;
			}
			break;
		}
		case 11:
		{
			cout << "goodbye";
			break;
		}
	default:
		break;
		}
	} while (choice != 9);
	return 0;
}