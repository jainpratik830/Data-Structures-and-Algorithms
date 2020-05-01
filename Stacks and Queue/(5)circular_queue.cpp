#include<iostream>
using namespace std;
int rear=-1,ffront=-1,n=5;
char cqueue[5];

void enqueue(int a)
{
    if((rear==n-1 && ffront==0) || (ffront==rear+1))
    {
        cout << "Queue is full" << endl;
    }
    if (ffront == -1)
        {
            ffront = 0;
            rear = 0;
        }
    else
    {
      if (rear == n - 1)
      rear = 0;
      else
      rear = rear + 1;
    }
    cqueue[rear]=a;

}

void dequeue()
{
    if(ffront==-1)
        cout << "Queue underflow\n";
    cout<<"Element deleted from queue is : "<<cqueue[ffront]<<endl;
    if (ffront == rear)
        {
            ffront = -1;
            rear = -1;
        }
    else
        {
            if (ffront == n - 1)
                ffront = 0;
            else
                ffront = ffront + 1;
        }

}

void display()
{
    int c=ffront,d=rear;
    if(ffront ==-1 && rear==-1)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Queue elements are ";
        if (c <= d)
            {
                while (c <= d)
                {
                cout<<cqueue[c]<<" ";
                c++;
                }
            }
        else
        {
            while (c <= n - 1)
            {
                cout<<cqueue[c]<<" ";
                c++;
            }
            c = 0;
            while (c <= d)
        {
         cout<<cqueue[c]<<" ";
         c++;
        }
        }
   cout<<endl;
    }
}

int main() {

   int ch, val;
   cout<<"1)Insert\n";
   cout<<"2)Delete\n";
   cout<<"3)Display\n";
   cout<<"4)Exit\n";
do {
   cout<<"Enter choice : "<<endl;
   cin>>ch;
   switch(ch) {
      case 1:
         cout<<"Input for insertion: "<<endl;
         cin>>val;
         enqueue(val);
         break;

      case 2:
         dequeue();
         break;

      case 3:
         display();
         break;

      case 4:
         cout<<"Exit\n";
         break;
         default:
         cout<<"Incorrect!\n";
   }
} while(ch != 4);
   return 0;
}
