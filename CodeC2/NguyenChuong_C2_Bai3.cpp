//chuong 2 bai 3 danh sach lien ket don
#include <iostream>
using namespace std;
// 3.1 khai bao cau truc danh sach
struct node
{
	int info;
	node* link;
};
node* first;
//3.2 khoi tao danh sach rong
void init()
{
	first = NULL;
}
//3.3 xuat danh sach
void process_list()
{
	node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}
//3.4 tim phan tu trong DS
node* search(int x)
{
	node* p = first;
	while (p != NULL && p->info == x)
	{
		p = p->link;
	}
	return p;
}
//3.5 them dau danh sach
void insert_first(int x)
{
	node* p;
	p = new node;
	p->info = x;
	p->link = first;
	first = p;
}
//3.6 xoa phan tu dau danh sach
int delete_first()
{
	if(first!= NULL)
	{
		node* p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
//3.7 them cuoi danh sach
void insert_last(int x)
{
	node* p;
	p = new node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
	{
		first = p;
	}
	else
	{
		node* q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
//cau 3.8 xoa cuoi danh sach
int delete_last()
{
	if (first != NULL)
	{
		node* p, * q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
		{
			q->link = NULL;
		}
		else first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//3.9 tim va xoa phan tu
int searchanddelete(int x)
{
	if (first != NULL)
	{
		node * p, * q;
		p = first;
		q = first;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if ( p!= first && p->link != NULL)
		{
			//ptu giua ds
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
		}
		else if (p == first)
		{
			//ptu dau ds
			first = p->link;
			delete p;
			return 1;
		}
		else if (p->link == NULL && p->info == x)
		{
			//ptu cuoi ds
			q->link = NULL;
			delete p;
			return 1;
		}
	}
	return 0;
}

int main33()
{
	int choice = 0;
	int x, i;
	node* p;
	system("cls");
	cout << "\n 1. Khoi tao danh sach LKD rong \n "
		<< "\n 2. Khoi tao DS LKD rong \n "
		<< "\n 3. Them phan tu vao cuoi danh sach \n "
		<< "\n 4. Xoa phan tu o dau danh sach \n "
		<< "\n 5. Xoa phan tu o cuoi danh sach \n"
		<< "\n 6. Xuat DSLK don \n "
		<< "\n 7. Tim gia tri trong danh sach lien ket \n "
		<< "\n 8. Tim va xoa gia tri trong danh sach lien ket \n"
		<< "\n 9. Thoat " << endl;
	do
	{
		cout << "vui long chon so thuc hien";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "ban vua khoi toa thanh cong DSLK don" << endl;
			break;
		case 2:
			cout << "vui long nhap=X";
			cin >> x;
			insert_first(x);
			cout << "sau khi themcuoi ds voi gia tri x=" << x << "la:";
			break;
		case 3:
			cout << "vui long nhap x=";
			cin >> x;
			insert_last(x);
			cout << "sau khi them cuoi ds voi gia tri x=" << x << "la:";
			process_list();
			break;
		case 4:
			i = delete_first();
			if (i == 0)
				cout << "xoa khong thanh cong, DS rong!" << endl;
			else
			{
				cout << "xoa thanh cong phan tu dau dsva danh sach sau khi xoa la:" << endl;
				process_list();
			}
			break;
		case 5:
			i = delete_last();
			if (i == 0)
				cout << "xoa khong thanh cong, ds rong!" << endl;
			else
			{
				cout << "xoa thanh cong phan tu cuoi danh sach va danh sach au khi xoa la:" << endl;
				process_list();
			}
			break;
		case 6:
			cout << "DSLK hien tai la:" << endl;
			process_list();
			break;
		case 7:
			cout << "vui long nhao gia tri can tim x=";
			cin >> x;
			p = search(x);
			if (p == NULL)
				cout << "khong tim thay x=" << x << "trong dslk!!" << endl;
			else
				cout << "tim thay x=" << x << "trong ds" << endl;
			break;

		case 8:
			cout << "vui long nhap gia tri can tim x=";
			cin >> x;
			i = searchanddelete(x);
			if (i == 0)
				cout << "khong tim thay x=" << x << "trong dslk" << endl;
			else
			{
				cout << "tim thay x=" << x << "trong dslk, va da xoa!" << endl;
				cout << "ds sau khi xoa la:" << endl;
				process_list();
			}
			break;
		case 9:
			cout << "goobye";
			break;
		default:
			break;
		}
	} while (choice != 9);
	return 0;

}