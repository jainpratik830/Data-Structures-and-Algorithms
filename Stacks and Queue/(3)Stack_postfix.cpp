#include<iostream>
using namespace std;

class Int_stack
{
private:
	int arr[1000];
	int size, top;
public:
	Int_stack()
	{
		top = -1;
		size = 0;
	}

	void push(int elem)
	{
		if(size == 1000)
		{
            cout << "Stack full" << endl;
		}
		else
		{
			top++;
			arr[top] = elem;
			size++;
		}
	}

	int pop()
	{
		if(size == 0)
        {
            cout << "stack underflow" << endl;
            return '\0';
        }
		else
		{
			int temp = arr[top];
			top--;
			size--;
			return temp;
		}
	}


	int get_top()
	{
		if(size == 0)	return -1;
		else
			return arr[top];
	}
};


int main()
{
	Int_stack num;
	char temp[100];
	cin >> temp;
	int i=0;
	while(temp[i] != '\0')
	{
		if(temp[i] != ' ')
		{
		    int a=(int) temp[i]-48;
			if(a >= 0 && a <=9)
			{
				num.push(a);
			}
			else
			{
				switch(temp[i])
				{
					case '+':
						num.push(num.pop() + num.pop());
						break;
					case '*':
						num.push(num.pop() * num.pop());
						break;
					case '-':
					{
						int a = num.pop();
						int b = num.pop();
						num.push(b-a);
						break;
					}
					case '/':
					{
						int a = num.pop();
						int b = num.pop();
						num.push(b/a);
						break;
					}
					default:
						cout <<"Error\n"<< endl;
						break;
				}

			}
		}
				i++;
	}
	cout<<  num.pop();
	return 0;
}

