#include<iostream>
using namespace std;
class MyException
{
	
	public:
		MyException(string s)
		{
			cout<<"Error: "<<s<<endl;
			exit(0);
		}
};
//=========================================================================================================
class DMatrix
{
	int *arr,n;
	public:
		DMatrix()
		{
			arr=0;
			n=0;
		}
		DMatrix(int N)
		{
			n=N;
			arr=new int[n];
		}
		
//=========================================================================================================
		void set(int i,int j,int v)
		{
			if(i<1||j<1||i>n||j>n)
			throw MyException("Rows and columns must be in the range of 1-size");
			
			if(i-j==0)
			arr[i-1]=v;
			else if(v!=0)
			throw MyException("Non Diagonal elements should be 0 only!!");
			
		}
//=========================================================================================================		
		int get(int i,int j)
		{
			if(i<1||j<1||i>n||j>n)
			throw MyException("Rows and columns must be in the range of 1-size");
			
			if(i-j==0)
			return arr[i-1];
			else 
			return 0;
		}
//=========================================================================================================		
		void input()
		{
			cout<<"Enter the size of the diagonal matrix: ";
			cin>>n;
			arr=new int[n];
			cout<<"Enter "<<n<<" array elements i.e. non zero elements: ";
			for(int i=0;i<n;i++)
			{
				cin>>arr[i];
			}
		}
//=========================================================================================================		
		void print()
		{
			cout<<"The diagonal matrix is:\n";
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i==j)
					cout<<arr[i];
					else
					cout<<0;
					cout<<" ";
				}
				cout<<endl;
			}
		}
};
//=========================================================================================================
int main()
{
	DMatrix d;
	d.input();
	d.print();
	int c,i,j,v;
	try
	{
	do
	{
		cout<<"Enter your choice:\n1.Change an element by entering the position\n2.Get an element by entering the position\n";
		cin>>c;
		switch(c)
		{
			case 1:
				cout<<"Enter the position to change the element at followed by new value:";
				cin>>i>>j;
				
				cin>>v;
				d.set(i,j,v);
				cout<<"After changing the element ";
				d.print();
				break;
			case 2:
				cout<<"Enter the position to get the element: ";
				cin>>i>>j;
				cout<<"The element at position "<<i<<","<<j<<"is: "<<d.get(i,j);
				break;
			default:
			        cout<<"Wrong choice!!";
			       break;
		}
		cout<<"\nEnter 1 for another choice.To exit enter anything else: ";
		cin>>c;
	}
	while(c==1);
	}
	catch(MyException m){}
	
	return 0;
}
				
	
				
	
