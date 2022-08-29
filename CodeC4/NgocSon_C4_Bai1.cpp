#include <iostream>
#define COUNT 10 
using namespace std;

struct Node
{
	int info;
	Node* left;
	Node* right;
};

Node* root;

void init()
{
	root = NULL;
}

void inputX(int &x)
{
	cout << "- Nhap x can tim/xoa: ";
	cin >> x;
}

//Them phan tu vao cay
//void insertNode(Node*& p, int x)
//{
//	if (p != NULL)
//	{
//		p = new Node;
//		p->info = x;
//		p->left = NULL;
//		p->right = NULL;
//	}
//	else
//	{
//		if (p->info == x)
//			return;
//		else if (p->info > x)
//			return insertNode(p->left, x);
//		else
//			return insertNode(p->right, x);
//	}
//}

int insertNodeRecursive(Node *q, int x)
{
	if (q->info == x)
		return 0;
	else if (q->left == NULL)
	{
		if (q->left == NULL)
		{
			Node* p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->left = p;
			return 1;
		}
		else
			return insertNodeRecursive(q->left, x);
	}
	else
	{
		if (q->right == NULL)
		{
			Node* p = new Node;
			p->info = x;
			p->right = NULL;
			q->right = p;
			return 1;
		}
		else
			return insertNodeRecursive(q->right, x);
	}
}
//Tim kiem phan tu trong cay
Node* search(Node* p, int x)
{
	while (p != NULL)
	{
		if (p->info == x)
			return p;
		else if (p->info > x)
			p = p->left;
		else
			p = p->right;
	}
	return NULL;
}

//Xoa Node trong cay
void searchStandFor(Node*& p, Node*& q)
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
int Delete(Node*& T, int x)
{
	if (T == NULL) return 0;
	if (T->info == x)
	{
		Node* p = T;
		if (T->left == NULL)
			T = T->right;
		else if (T->right == NULL)
			T = T->left;
		else // có 2 con
			searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x) return Delete(T->right, x);
	if (T->info > x) return Delete(T->left, x);
}

//Dueyt cay NLR
void duyetNLR(Node *p)
{
	if (p != NULL)
	{
		cout << p->info << "/t";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}

void duyetLNR(Node* p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << "/t";
		duyetLNR(p->right);
	}
}

void duyetLRN(Node* p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info << "\t";
	}
}

void print2DUtil(Node* p, int space)
{
	if (p == NULL)
		return;
	space += COUNT;

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
void Menu()
{
	int op, x;
	bool check = false;
	do
	{
		cout << "\t\t================MENU================\n";
		cout << "\t\t1.Tao cay rong\n";
		cout << "\t\t2.Them phan mot phan tu vao cay\n";
		cout << "\t\t3.Tim mot phan tu trong cay\n";
		cout << "\t\t4.Xoa phan tu trong cay\n";
		cout << "\t\t5.Duyet cay theo thu tu NLR\n";
		cout << "\t\t6.Duyet cay theo thu tu LNR\n";
		cout << "\t\t7.Duyet cay theo thu tu LRN\n";
		cout << "\t\t8.Xuat cay\n";
		cout << "\t\t9.Thoat chuong trinh\n";
		cout << "\t\t====================================\n";
		cout << "- Moi ban lua chon: ";
		cin >> op;
		switch (op)
		{
		case 1:
			init();
			cout << "- Khoi tao danh sach thanh cong! " << endl;
			check = true;
			break;
		case 2:
			if (check)
			{
				inputX(x);
				insertNodeRecursive(root, x);
				cout << "=> Them phan tu vao cay thanh cong " << endl;
			}
			else
				cout << "<!> Vui long khoi tao danh sach! " << endl;
			break;
		case 3:
			if (check)
			{
				inputX(x);
				if (search(root, x) != NULL)
					cout << "=> Tim thay " << x << "trong cay" << endl;
				else
					cout << "<!> Khong tim thay " << x << "trong cay" << endl;
			}
			else
				cout << "<!> Vui long khoi tao danh sach! " << endl;
			break;
		case 4:
			if (check)
			{
				inputX(x);
				int result = Delete(root, x);
				if (result == 0)
					cout << "Khong tim thay " << x << " de xoa! " << endl;
				else
					cout << "Tim thay " << x << "va xoa thanh cong! " << endl;
			}
			else
				cout << "<!> Vui long khoi tao danh sach! " << endl;
			break;
		case 5:
			if (check)
			{
				duyetNLR(root);
			}
			else
				cout << "<!> Vui long khoi tao danh sach! " << endl;
			break;
		case 6:
			if (check)
			{
				duyetLNR(root);
			}
			else
				cout << "<!> Vui long khoi tao danh sach! " << endl;
			break;
		case 7:
			if (check)
			{
				duyetLRN(root);
			}
			else
				cout << "<!> Vui long khoi tao danh sach! " << endl;
			break;
		case 8:
			if (check)
			{
				process_tree();
			}
			else
				cout << "<!> Vui long khoi tao danh sach! " << endl;
			break;
		case 9: 
			cout << "==THOAT CHUONG TRINH==" << endl;
		}
	} while (op != 8);
}
int main()
{
	Menu();
	return 0;
}