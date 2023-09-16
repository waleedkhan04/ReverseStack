#include <iostream>
using namespace std;
template <class T>
class stack
{
private:
    int top;
    int size;
    int capacity;
    bool reverse;
    T *arr;

public:
    stack(int s)
    {
        top = -1;
        size = 0;
        capacity = s;
        reverse = false;
        arr = new T[capacity];
    }
    bool isempty()
    {
        return size == 0;
    }
    void push(T data)
    {
        if (reverse && !isempty())
        {
            T *temp = new T[capacity];
            for (int i = (size - 1); i > -1; i--)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            reverse = false;
        }
        if (size == capacity)
        {
            T *temp = new T[capacity * 2];
            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            capacity = capacity * 2;
            cout << "Capacity doubled" << endl;
        }
        top++;
        arr[top] = data;
        size++;
    }
    bool pop()
    {
        if (isempty())
        {
            cout << "Stack is empty" << endl;
            return false;
        }
        if (reverse)
        {
            T *temp = new T[capacity];
            for (int i = (size - 1); i > -1; i--)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            reverse = false;
        }
        top--;
        size--;
        if (size < capacity / 2)
        {
            T *temp = new T[capacity / 2];
            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            capacity = capacity / 2;
            cout << "Capacity halved" << endl;
        }
    }
    void flipstack()
    {
        reverse = true;
    }
    void print()
    {
        if (reverse)
        {
            for (int i = (size - 1); i > -1; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    stack<int> s(5);
    cout << "Input elements to push into stack" << endl;
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }
    s.print();
    s.flipstack();
    s.print();
    