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
class LowerTMatrix
{
	int *arr,n,s;
	public:
		LowerTMatrix()
		{
			arr=0;
			n=s=0;
		}
		LowerTMatrix(int N)
		{
			s=N;
			n=(n*(n+1))/2;
			arr=new int[n];
		}
//=========================================================================================================			
		void input()
		{
			cout<<"Enter the size of Lower Triangular Matrix: ";
			cin>>s;
			n=(s*(s+1))/2;
			arr=new int[n];
			cout<<"Enter "<<n<<" array elements i.e. non zero elements: \n";
			for(int i=0;i<n;i++)
			{
				cin>>arr[i];
			}
		}
//==========================================================================================================		
		void print()
		{
			cout<<"The Lower Triangular matrix is:\n";
			int c=0;
			for(int i=0;i<s;i++)
			{
				for(int j=0;j<s;j++)
				{
					if(i>=j)
					cout<<arr[c++];
					else
					cout<<0;
					cout<<" ";
				}
				cout<<endl;
			}
		}
//==========================================================================================================
		void set(int i,int j,int v)
		{
			if(i<1||j<1||i>s||j>s)
			throw MyException("Rows and columns must be in the range of 1-size");
			
			if(i>=j)
			arr[(i*(i-1))/2 +j-1]=v;
			else if(v!=0)
			throw MyException("Elements above the main diagonal should be 0 only!!");
		}
//==========================================================================================================
		int get(int i,int j)
		{
			if(i<1||j<1||i>s||j>s)
			throw MyException("Rows and columns must be in the range of 1-size");
			
			if(i>=j)
			return arr[(i*(i-1))/2 +j-1];
			else 
			return 0;
		}
		
		void transpose()
		{
		 	int *t=new  int[n];
		 	int c=0;
			for(int i=0;i<s;i++)
			{
				for(int j=0;j<s;j++)
				{
					
					if(j>=i)
					t[c++]=arr[(j*(j+1))/2 +i];
					
				}
			}
			
			for(int i=0;i<n;i++)
			cout<<t[i];
		}
		
};
//==========================================================================================================
int main()
{
	LowerTMatrix d;
	d.input();
	d.print();
	cout<<"\n\n";
	//d.transpose();
	int c,i,j,v;
	try
	{
	do
	{
		cout<<"Enter your choice:\n1.Change an element by entering the position\n2.Get an element by entering the position\n3.Print the matrix\n";
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
				v=d.get(i,j);
				cout<<"The element at position ("<<i<<","<<j<<") is: "<<v;
				break;
				   case 3:
		          d.print();
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
