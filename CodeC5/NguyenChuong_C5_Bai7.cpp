#include <iostream>
#include <string>
#include <math.h>
using namespace std;
#define MAX 20
struct Node {
	int info;
	Node* link;
};
Node* first[MAX];
//khoi tao danh sach
int n;//so ding tren so thi
void init()
{
	for (int i = 0; i < n; i++)
		first[i] = NULL;
}
// nhap danh sach
void insert_first(Node*& f, int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = f;
	f = p;
}
void input()
{
	int d, x, m;
	cout << "nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nnhap dinh thu " << i + 1 << " : ";
		cin >> d;
		insert_first(first[i], d);
	}
	cout << "nhap vao so dinh ke cua " << d << " : ";
	cin >> m;
	for (int j = 0; j < m; j++)
	{
		cin >> x;
		insert_first(first[j], x);
	}
}

//xuat danh sach ra man hinh
void output_list(Node* f)
{
	if (f != NULL)
	{
		Node* p = f;
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
	}
}
void output()
{
	if (n > 0)
		for (int i = 0; i < n; i++)
		{
			cout << endl << "Danh sach thu " << i + 1 << ": ";
			output_list(first[i]);
		}
	else
		cout << "rong";
}

int main()
{

	return 0;
}
