//assignment 4 a queue (23103) arrays
#include<iostream>
using namespace std;
class queue
{
public:
    int n;
    int *a;
    int top, rear;
    queue(int size)
    {
        n = size;
        a = new int[n];
        top = -1;
        rear = -1;
    }
    void enqueue(int data);
    void dequeue();
    void empty();
    void display();
    void front();
};
void queue::enqueue(int data)
{
    if (rear == n - 1)
    {
        cout << "queue is full";
    }
    else if (top == -1)
    {
        top++;
        rear++;
        a[top] = data;
    }
    else
    {
        rear++;
        a[rear] = data;
    }
}
void queue::dequeue()
{
    if (top == -1 || top > rear)
    {
        cout << "queue is empty";
    }
    cout << "dequeued ele=" << a[top]<<endl;
    top++;
}
void queue::display()
{
    for (int i = top; i <= rear; i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
}
void queue::empty()
{
    if (top == -1)
    {
        cout << "array is empty\n";
    }
    else
    {
        cout << "array is not empty\n";
    }
}
void queue::front()
{
    cout << "top ele is=" << a[top]<<endl;
}
int main()
{

    int n;
    cout << "Enter n=";
    cin >> n;
    queue q(n);
    int x;
    do
    {
        cout << "Enter 1 to push element in queue.\n";
        cout << "Enter 2 to pop elelment from queue.\n";
        cout << "Enter 3 to see the list.\n";
        cout << "Enter 4 to check if list is empty.\n";
        cout << "Enter 5 to see front element.\n";
        cin >> x;
        switch (x)
        {
        case 1:
            int data;
            cout << "enter val=";
            cin >> data;
            q.enqueue(data);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            q.empty();
            break;
        case 5:
            q.front();
            break;
        default:
            cout << "invalid choice";
        }
  } while (x != 6);
 }