#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int COUNT;
//1.1 hai bao cau truc nhi phan tim kem
struct node {
	int info;
	node* left, * right;
};
node* root;

//1.2 khoi tao cay rong
void tree_empty()
{
	root = NULL;
}
//1.3 them mot phan tu vao cay
void InsertNode(node*& p, int x)
{
	if (p == NULL)
	{
		p = new node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return;
		else if (p->info > x)
			return InsertNode(p->left, x);
		else
			return InsertNode(p->right, x);
	}
}
//1.4 tim mot phan tu  trong cay
node* p = root;
node* search(node* p, int x)
{
	
	if (p!= NULL)
	{
		if (p->info == x)
			return p;
		else
			if (x > p->info)
				return search(p->right, x);
			else
				return search(p->left, x);
	}
	return NULL;
}
//1.5 xoa mot mut trong cay 
void searchStandFor(node*& p, node*& q)//tim cuc traiben phai
{
	if (q->left == NULL)
	{
		p->info == q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
int Delete(node*& T, int x)
{
	if (T == NULL) return 0;
	if (T->info == x)
	{
		node* p = T;
		if (T->left == NULL)
			T = T->right;
		else if (T->right == NULL)
			T = T->left;
		else //co hai con
			searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x) return Delete(T->right, x);
	if (T->info > x) return Delete(T->left, x);
}
//1.6 duyet cay theo thu tu NLR
void duyetNLR(node* p)
{
	if (p != NULL)
	{
		cout << p->info <<" ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
//1,7 duyet cay theo LNR
void duyetLNR(node *p)
{	
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info <<"";
		duyetLNR(p->right);
	}
}

//1.8 duyet cay theo LRN
void duyetLRN(node* p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info << " ";
	}
}
void print2DUtil(node *p, int space)
{
	if (p == NULL)
		return;
	space +=COUNT;
	print2DUtil(p->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << "\n";
	print2DUtil(p->left, space);
}
void process_tree()
{
	print2DUtil(root, 0);
}
void menu()
{
	cout << "1.khoi tao cay rong" << endl;
	cout << "2.them mot phan tu vao cay" << endl;
	cout << "3.tim phan tu co gia tri x trong cay NPTK" << endl;
	cout << "4.xoa phan tu co gia tri x trong cay NPTK" << endl;
	cout << "5.duyet cay NPTK theo NLR" << endl;
	cout << "6.duyet cay NPTK theo LNR" << endl;
	cout << "7.duyet cay NPTK theo LRN" << endl;
	cout << "8.xuat cay NPTK" << endl;
	cout << "9.thoat" << endl;
}
int main()
{
	node* k;
	int choice,i, x;
	menu();
	do
	{
		cout << "Nhap su lua chon" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
			 tree_empty();
				cout << "- Khoi tao danh sach thanh cong! " << endl;
				break;
			 case 2:
			 {
				cout << "nhap so ban muon them vao cay" << endl;
				cin >> x;
				InsertNode(root, x);
				cout << "da them thanh cong x=" << x << " trong mang" << endl;
				cout << "cay sau khi them x la" << endl;
				process_tree();
			 }
				break;
			case 3:
			{
				cout << "Nhap so x ban muon tim vao cay" << endl;
				cin >> x;
				k = search(root,x);
				if (k == NULL)
				{
					cout << "khong tim thay x trong mang" << endl;
				}
				else 
				{
					cout << "tim thay x trong cay" << endl;
				}
			}
				break;
			case 4:
			 cout << "vui long nhap gia tri x can xoa";
			 cin >> x;
			 i = Delete(root, x);
			 {
				 if (i == 0)
					 cout << "khong tim thay x=" << x << "de xoa" << x << endl;
				 else
				 {
					 cout << "Da xoa thanh cong phan tu x="<<x<<" trong cay" << endl;
					 cout << "cay NPTK sau khi xoa la:" << endl;
					 process_tree();
				 }

			 }
			 break;
			case 5:
			 {
				cout << "cay duoc duyet theo NLR la" << endl;
				duyetNLR(root);
			
			 }
			break;
			case 6:
			{
				cout << "cay duoc duyet theo LNR la" << endl;
				duyetLNR(root);
			}
			break;
			case 7:
			{
				cout << "cay duoc duyet theo LRN la" << endl;
				duyetLRN(root);
			}
			break;
			case 8:
			{
				cout << "cay duoc xuat la" << endl;
				process_tree();
			}
			break;
			case 9:
			{
				cout << "goodbye" << endl;
			}
			break;
			default:
				break;
			}
	} while (choice!=9);
	return 0;
}
