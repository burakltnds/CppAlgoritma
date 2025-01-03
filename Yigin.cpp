#include <iostream>
#include <string>
#define MAX
using namespace std;

#include <iostream>
using namespace std;

template <class T>
struct StackNode
{
    T data;
    StackNode<T>* sonra;
    StackNode(T value) : data(value), sonra(nullptr) {}
};

template <class T>
class Stack
{
    StackNode<T>* top;
public:
    Stack() : top(nullptr) {}

    ~Stack()
    {
        while (top)
        {
            pop();
        }
    }

    void push(T value)
    {
        StackNode<T>* yeni = new StackNode<T>(value);
        yeni->sonra = top;
        top = yeni;
    }

    void pop()
    {
        if (top==nullptr)
        {
            cout << "Stack boş.\n";
            return;
        }
        StackNode<T>* temp = top;
        top = top->sonra;
        delete temp;
    }

    void listele()
    {
        if (top==nullptr)
        {
            cout << "Stack bos\n";
            return;
        }
        StackNode<T>* temp = top;
        while (temp)
        {
            cout << temp->data << endl;
            current = temp->sonra;
        }
    }
};

int main()
{
    Stack<int>i;
    Stack<char>c ;
    Stack<string>s;
    i.push(14);
    i.push(10);
    i.push(5);
    i.push(7);
    i.pop();
    i.listele();
    cout << "***************" << endl;
    //
    c.push('@');
    c.push('$');
    c.push('#');
    c.push('*');
    c.pop();
    c.listele();
    cout << "***************" << endl;
    //
    s.push("TAM");
    s.push("BAGIMSIZ");
    s.push("KIZIL ELMA");
    s.push("TOGG");
    s.pop();
    s.listele();
}