#include <iostream>
#include <fstream>
using namespace std;
#define MAX 20
int A[MAX][MAX];//mang 2 chieu
int n;//so dinh cua do thi
char vertex[MAX];
struct Node {
	int info;
	Node* link;
 };
Node* sp;
Node* front, * rear;
//Stack
void InitStack() {
	sp = NULL;
}
int isEmptyS()
{
	if (sp == NULL)
		return 1;
	else return 0;
}
void PushS(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int PopS(int &x)
{
	if(sp!=NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//end Stack
//Queue
void InitQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
 }
void PushQ(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else rear->link = p;
	rear = p;
}
int PopQ(int x)
{
	if (front != NULL)
	{
		Node* p = front;
		front = p->link;
		x = p->info;
		if (front == NULL) {
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
//end Queue
void InitGraph()
{
	n = 0;
}
//4.1 Nhap MTK bang bay
void inputGraph()
{
	cout << "nhap so dinh so thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "nhap ten dinh";
		cin >> vertex[i];
		cout << "nhap vao dong thu " << i + 1 << ":  ";
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
}
//nhap MTK tu file txt
void inputGraphFromText()
{
	string line;
	ifstream myfile("mtk1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> A[i][j];
		}
	}
}
//4.2 Xuat MTK
void outputGraph()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
			cout << endl;
		}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << vertex[a[i]] << " ";
	}
}
//3.4 Duyet BFS (QUEUE)
int C[100], bfs[100];
int nbfs = 0;
void InitC()
{
	for (int i = 0; i < n; i++)
		C[i];
}
void BFS(int v) //v  la dinh bat dau //xai queue
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w=0;w<n;w++)
			if (C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}
//cau 4.4 Duyet DFS (stack)
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (isEmptyS() == 0)
	{
		if (v == n)
			PopS(u);
		for(v=0;v<n;v++)
			if (A[u][v] != 0 && C[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;

			}
	}
}
//4.5 tim su dung BFS
void Search_by_BFS(int x, int v)//v la dinh bat dau
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		if (x == p)
		{
			cout << "tim thay x= " << x << endl;
			return;
		}
		for (w=0;w<n;w++)
			if (C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}
int main()
{
	int a[MAX];
	int b[MAX];
	int choice, sp, sp_b, x, i;
	system("cls");
	cout << "-------BAI TAP 4,CHUONG 5, DO THI------" << endl;
	cout << "1.khoi tao MA TRAN KE rong" << endl;
	cout << "2.Nhap MA TRAN KE tu file text" << endl;
	cout << "3.nhap MA TRAN KE " << endl;
	cout << "4.xuat MA TRAN KE " << endl;
	cout << "5.duyet do tu theo chieu rong BFS-DSLK" << endl;
	cout << "6.duyet do thi theo chieu sau DFS-DSLK" << endl;
	cout << "tim dinh co gia tri x thoe BFS" << endl;
	cout << "8.thoat" << endl;
	do
	{
		cout << "\n voi long nahp su lua chon" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			InitGraph();
				cout << "ban vua khoi tao MA TRAN KE rong thanh cong!\n";
				break;
		case 2:
			inputGraphFromText();
			cout << "ban vua nhap MA TRAN KE tu file: \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			InitQueue();
			InitC();
			cout << "vui long nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "thu tu dinh sau khi duyet BFS: "<<endl;
			output(bfs, n);
			break;
		case 6:
			InitStack();
			InitC();
			cout << "vui long nhap dinh xuat phat: " << endl;
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "thu tu dinh sau khi duyet la DFS: " << endl;
			output(dfs, n);
			break;
		case 7:
			cout << "vui long nhap gia tri x can tim: ";
			cin >> x;
			Search_by_BFS(x, 0);
			break;
		case 8:
			cout << "goodbye  !" << endl;
			break;
		default:
			break;
	    }
	} while (choice != 8);
	return 0;
}
