#include<iostream>
using namespace std;
class illegalParameterException		//Custom Exception class for handling unknown situations
{
	public:
		illegalParameterException(string s)		//d contsins the message in exeption
		{
			cout<<s<<"\nProgram will terminate";
			exit(0);
		}
};

class Matrix 
{
	int *arr,ro,co;		//one dimensional pointer array for storing matrix in row major form
	public:
		Matrix()  		//default constructor
		{
			arr=0;
			ro=co=0;
		}
		Matrix(int r,int c)		//parameterized constructor
		{
			ro=r;
			co=c;
			arr=new int[ro*co];
		}
//================================================================================================		
		void input()
		{
			cout<<"Enter the number of rows and columns:\n";
			cin>>ro>>co;
			
			if(ro<0||co<0)		//number of rows and columns should be at least 0
			throw illegalParameterException("Enter valid number of rows and columns.");
			
			arr=new int[ro*co];
			cout<<"Enter "<<ro<<"*"<<co<<"="<<ro*co<<" array elements:\n";
			for(int i=0;i<ro*co;i++)
			cin>>arr[i];
		}
//================================================================================================
		void operator++(int)		//unary increment operator
		{
			for(int i=0;i<ro*co;i++)
			arr[i]++;
		}
//================================================================================================
		void operator--(int)		//unsry decrement operator
		{					
			for(int i=0;i<ro*co;i++)
			arr[i]--;
		}
//================================================================================================
		Matrix operator+(Matrix a)		//addition  of two matrices
		{
			Matrix temp(ro,co);
			if(a.ro==ro&&a.co==co)
			{
				for(int i=0;i<ro*co;i++)
				temp.arr[i]=arr[i]+a.arr[i];		//adding respective elements
				
			}
			else
				throw illegalParameterException("Rows and colums are not equal");
				
			return temp;
		}
//================================================================================================
		Matrix operator-(Matrix a)		//difference of two matrices
		{
		
			if(a.ro==ro&&a.co==co)
			{
				Matrix temp(ro,co);
				for(int i=0;i<ro*co;i++)
				temp.arr[i]=arr[i]-a.arr[i];
				return temp;
			}
			else
				throw illegalParameterException("Rows and columns are not equal");
				
			
		}
//================================================================================================
		Matrix operator+=(int a)
		{
			for(int i=0;i<ro*co;i++)
			arr[i]+=a;
			
			return *this;
		}
//================================================================================================
		Matrix operator-=(int a)
		{
			for(int i=0;i<ro*co;i++)
			arr[i]-=a;
			
			return *this;
		}
//================================================================================================
		Matrix operator*=(int a)const
		{
			if(a==0)
			{
				cout<<"0 cannot be multiplied.";
			}
			else
			for(int i=0;i<ro*co;i++)
			arr[i]*=a;
			
			return *this;
		}
//================================================================================================
		void print()
		{
			int c=0;
			for(int i=0;i<ro*co;i++)
			{
				cout<<arr[i]<<" ";
				c++;
				if(c==co)
				{
					cout<<endl;
					c=0;
				}
			}
		}
//================================================================================================
		Matrix operator*(Matrix a)		//multiplication of two matrices
		{
			if(this->ro != a.co)		//number of columns of first matrix should be equal to number of rows of second matrix
			throw illegalParameterException("Please enter valid dimensions for multiplication.");
			
		
			Matrix temp(this->ro,a.co);
			int c_this=0, c_a=0, c_temp=0;	//defining cursors for *this, matrix, and temp
			for(int i=0; i<this->ro;i++)
			{
				for(int j=0;j<a.co;j++)
				{
					int sum = arr[c_this]*a.arr[c_a];	
					
					for(int k = 1;k<this->co;k++)
					{
						c_this++;
						c_a += a.co;
						sum += arr[c_this]*a.arr[c_a];
					}	
					temp.arr[c_temp++] = sum;
					
					//Reset to start of row and next column
					c_this -= (this->co -1);
					c_a = j+1;		
				}
				//Reset to start of next row and first column
				c_this += this->co;
				c_a = 0;
			}
			return temp;		
		}
//================================================================================================		
};


int main()
{
	Matrix a,b,r;
	cout<<"Enter matrix a\n";
	a.input();
	cout<<"Enter matrix b\n";
	b.input();
	cout<<"Matrix a:\n";
	a.print();
	cout<<"Matrix b:\n";
	b.print();
	int c=0,k;
	
	
	
	
	try
	{
		do
		{
			cout<<"Enter your choice:\n1.++\n2.--\n3.+\n4.-\n5.+=\n6.-=\n7.*=\n8.*\n";
			cin>>c;
			switch(c)
			{
				case 1:
					a++;b++;
					cout<<"Matrix a:\n";
					a.print();
					cout<<"Matrix b:\n";
					b.print();
				break;
				case 2:
					a--;b--;
					cout<<"Matrix a:\n";
					a.print();
					cout<<"Matrix b:\n";
					b.print();
				break;
				case 3:
					r=a+b;
					cout<<"Result:\n";
					r.print();
				break;
				case 4:
					r=a-b;
					cout<<"Result:\n";
					r.print();
				break;
				case 5:
					cout<<"Enter value: ";
					cin>>k;
					a+=k;b+=k;
				        cout<<"Matrix a:\n";
					a.print();
					cout<<"Matrix b:\n";
					b.print();
				break;
					case 6:
					cout<<"Enter value: ";
					cin>>k;
					a-=k;b-=k;
			      	       cout<<"Matrix a:\n";
					a.print();
					cout<<"Matrix b:\n";
					b.print();
				break;
					case 7:
					cout<<"Enter value: ";
					cin>>k;
					a*=k;b*=k;
			  	        cout<<"Matrix a:\n";
					a.print();
					cout<<"Matrix b:\n";
					b.print();
				case 8:
					r=a*b;
					cout<<"Result:\n";
					r.print();
				break;
				default:
					cout<<"Wrong choice!!\n";
			}
			cout<<"Enter 1 for another choice.To exit enter anything else: ";
			cin>>c;
			cout<<endl;
		}while(c==1);
	}catch(illegalParameterException a)
	{
	
	}
	return 0;
	
}
