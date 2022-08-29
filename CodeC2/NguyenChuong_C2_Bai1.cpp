#include <iostream>
using namespace std;
struct node {
	int value;
	node* next;
	node* prev;
};
node* crenode(int x)
{
	node* p = new node;
	p->value = x;
	p->next = nullptr;
	p->prev = nullptr;
	return p;
}
void input(node*& head, node*& tail)
{
	head = nullptr;
	tail = nullptr;
}
bool isempty(node* head)
{
	return head == nullptr;
}
void addhead(node*& head, node*& tail, int x)
{
	node* p = crenode(x);
	p->next = head;
	if (isempty(head))
	{
		tail = p;
	}
	else head->prev = p;
	head = p;
}
void addtail(node*& head, node*& tail, int x)
{
	node* p = crenode(x);
	p->prev = tail;
	if (isempty(tail))
	{
		head = p;
	}
	else tail->next = p;
	tail = p;
}
void output1(node* head)
{
	node* p = head;
	while (p != nullptr)
	{
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}
void output2(node* tail)
{
	node* p = tail;
	while (p != nullptr)
	{
		cout << p->value << " ";
		p = p->prev;
	}
	cout << endl;
}
void delhead(node*& tail, node*& head)
{
	if (!isempty(head))
	{
		node* p = head;
		head = p->next;
		p->next = nullptr;
		if (head != nullptr)
			head->prev = nullptr;
		else
			tail = nullptr;
		delete p;
	}
}
void deltail(node*& tail, node*& head)
{
	if (!isempty(head))
	{
		node* p = tail;
		tail = p->prev;
		p->prev = nullptr;
		if (tail != nullptr)
			tail->next = nullptr;
		else
			head = nullptr;
		delete p;
	}
}
void clear(node*& head, node*& tail)
{
	while (head != nullptr && tail != nullptr)
		delhead(tail, head);
}
int main1()
{
	node* head, * tail;
	input(head, tail);
	addhead(head, tail, 1);
	addhead(head, tail, 2);
	addhead(head, tail, 3);
	addtail(head, tail, 78);
	addtail(head, tail, 100);
	output1(head);
	delhead(tail, head);
	deltail(tail, head);
	output1(head);
	output2(tail);
	clear(head, tail);
	output1(head);
	system("pause");
	return 0;
}