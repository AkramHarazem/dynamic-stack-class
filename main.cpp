#include <iostream>

using namespace std;

class Stack
{
private:
    int* pointerSt;
    int Size;
    int top;
    static int objectCounter;
    static int counterOperat;
    int isFull();
    int isEmpty();
public:

    Stack ()
    {
        top = 0;
        Size = 5;
        pointerSt = new int [Size];
        objectCounter++;
    }

    Stack (int s)
    {
        top = 0;
        Size = s;
        pointerSt = new int [Size];
        objectCounter++;
    }

//    Stack (int x=7)
//    {
//        top = 0;
//        Size = x;
//        pointerSt = new int [Size];
//    }

    void setSize (int x)
    {
        Size=x;
    }
    int getSize ()
    {
        return Size;
    }



    static int getCounter ()
    {
        return objectCounter;
    }
    static int getCounterOperat ()
    {
        return counterOperat;
    }


    void push(int);
    int pop();
    void printStack(int);

    ~Stack ()
    {
        delete [] pointerSt;
    }
};

int Stack::objectCounter = 0;
int Stack::counterOperat=0;

// FUNCTIONS DECLERATION

int Stack::isFull()
{
    if (top==Size)
    {
        return 1;

    }
    else
    {
        return 0;
    }
}

int Stack::isEmpty()
{
    if (top==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Stack::push (int n)
{

    if (Stack::isFull())
    {

        cout<< "\nStack memory is full"<<endl;
    }
    else
    {
        pointerSt[top]=n;
        top++;
        counterOperat++;
    }
}

int Stack:: pop ()
{
    int retuenVal = 0;
    if (Stack::isEmpty())
    {
        cout<< "\nStack memory is empty"<<endl;

    }
    else
    {
        top--;
        retuenVal=pointerSt[top];
    }

    return retuenVal;
}


void Stack:: printStack(int x)
{

    cout<<pointerSt[x]<<endl;

}



int main()
{
    cout<<"\ns1 Stack push"<<endl;
    Stack s1;
    for (int i=0; i<6; i++)
    {
        s1.push(i);
        s1.printStack(i);
    }

    cout<<"\ns2 Stack push"<<endl;
    Stack s2(7);
    for (int i=0; i<8; i++)
    {
        s2.push(i);
        s2.printStack(i);
    }

    int n;
    Stack s3;
    cout<<"enter size of stack "<<endl;
    cin>>n;
    s3.setSize(n);
    cout<<"\ns3 Stack push"<<endl;
    for (int i=0; i<=n; i++)
    {
        s3.push(i);
        s3.printStack(i);
    }


    cout<<"\ns1 Stack pop"<<endl;
    for (int i=0; i<6; i++)
    {
        cout<<s1.pop()<<endl;
    }
    cout<<"\ns2 Stack pop"<<endl;
    for (int i=0; i<8; i++)
    {
        cout<<s2.pop()<<endl;
    }
    cout<<"\ns3 Stack pop"<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<s3.pop()<<endl;
    }


    cout<<endl;
    cout << Stack::getCounter();
    cout<<endl;
    cout << Stack::getCounterOperat();

    return 0;
}
