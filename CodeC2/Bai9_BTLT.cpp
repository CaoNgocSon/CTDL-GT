//#include <iostream>
//#define max 100
//using namespace std;
//class NODE
//{
//    int v;
//    char a, b, c;
//public:
//    NODE(int V = 1, char A = 'A', char B = 'B', char C = 'C')
//    {
//        a = A, b = B, c = C, v = V;
//    }
//    NODE operator = (const NODE& node)
//    {
//        if (this != &node)
//        {
//            v = node.v; a = node.a;
//            b = node.b; c = node.c;
//        }
//        return *this;
//    }
//    NODE first() { return NODE(v - 1, c, b, a); };
//    NODE second() { return NODE(1, a, b, c); };
//    NODE three() { return NODE(v - 1, a, c, b); };
//    void list() { 
//        int count = 0;
//        cout << ++count << a << b;
//    }
//    int getv() { return v; }
//};
//
//class STACK :public NODE
//{
//    int top;
//    NODE node[max];
//public:
//    STACK() { top = -1; }
//    NODE pop() { return node[top--]; }
//    void push(const NODE& a) { node[++top] = a; }
//    int empty() { return top == -1; }
//    int overflow() { return top == max; }
//    void execute(int n);
//    void list() { while (!empty())pop().list(); }
//};
//void STACK::execute(int n)
//{
//    STACK b;
//    push(NODE(n));
//    int stop = 0;
//    while (!stop)
//    {
//        int Top = top;
//        while (Top >= 0 && node[Top].getv() == 1)Top--;
//        if (Top == -1) stop = 1;
//        else
//        {
//            while (top > Top) b.push(pop());
//            NODE d = pop();
//            push(d.first());
//            push(d.second());
//            push(d.three());
//            while (!b.empty())push(b.pop());
//        }
//    }
//}
//
//int main()
//{
//    STACK s;
//    s.execute(10);
//    s.list();
//    return 0;
//}