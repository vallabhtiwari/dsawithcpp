#include<iostream>
#include<exception>
using namespace std;
//=====================================================================================================
class LinkedList;
class Node
{
	 int el;
	Node *next;
	public:
		Node();
		Node(int);
	friend class LinkedList;
	//friend void increase(LinkedList,LinkedList);
};
//=====================================================================================================
Node ::Node()
{
	next=NULL;
}

Node::Node(int e)
{
	el=e;
	next=NULL;
}
//=====================================================================================================
class LinkedList
{
	Node  *top;
	//int count;
	public:
		LinkedList();
		void input(int*,int);
		void insertBeg(int);
		void remBeg();
		void insertI(int,int);
		void remI(int);
		int search(int);
		LinkedList operator+(LinkedList);
		void print();
		
		//friend void increase(LinkedList,LinkedList);
		//~LinkedList();
};
/*LinkedList:: ~LinkedList()
{
	Node *t=new Node();
	t=top;
	while(top!=NULL)
	{
		top=top->next;
		delete t;
		t=top;
	}
}*/
//===================================================================================================== 
LinkedList ::LinkedList()
{
	top=NULL;
	//count=0;
}
//=====================================================================================================
void LinkedList ::insertBeg( int e)
{
	Node  *t=new Node(e);		//new node with element e
	t->next=top;
	top=t;
	//count++;
}
//=====================================================================================================
void LinkedList :: remBeg()
{
	if(top==NULL)
	{
		cout<<"List is empty!!\n";
		return;
	}
	Node  *t=new Node();		//temporary node pointer to delete the node
	t=top;
	top=top->next;
	//count--;
	delete t;
}
//=====================================================================================================
void LinkedList ::insertI( int e,int i)
{
	if(i<1)
	{
		cout<<"Position cannot be less than 1!!\n";
		return;
	}
	//count++;
	Node *newN=new Node(e);		//new node with element e
	if(top==NULL||i==1)
	{
		if(top==NULL)
		cout<<"List is empty!! Element inserted at top\n";
		newN->next=top;
		top=newN;
		return;
	}
	
	int c=1;
	Node *t=new Node();		//t is used for traversing the list
	t=top;
	while(t->next!=NULL)
	{
		c++;
		if(c==i)
		break;
		t=t->next;
	}
	
	if(c<i)
	cout<<"List contains only "<<c<<" nodes.So new element inserted at the last.\n";
	newN->next=t->next;		//adding the node above the remaining list
	t->next=newN;			//joining the new list from new node to last
	
}
//=====================================================================================================
void LinkedList ::remI( int i)
{
	if(i<1)
	{
		cout<<"Position cannot be less than 1!!\n";
		return;
	}
	//count--;
	Node  *t=new Node();
	t=top;
	if(top==NULL||i==1)
	{
		if(top==NULL)
		{
			cout<<"List is empty!!\n";
			return;
		}
		
		top=top->next;
		delete t;
		return;
	}
	
	int c=1;
	while(t->next!=NULL)
	{
		c++;
		if(c==i)
		break;
		t=t->next;
	}
	if(c<i)
	{
		cout<<"List contains only "<<c<<" nodes.\n";
		return;
	}
	
	Node *temp=new Node();		//temporary node for deletetion
	temp=t;
	temp=temp->next;		//node to be deleted must be secured first for clearing memory
	t->next=(t->next)->next;	//updating the list with next nodes
	delete temp;			//deleting the ith node
}
//=====================================================================================================
int LinkedList::search(int s)
{
	Node *t=new Node();
	t=top;
	int c=1;
	while(t!=NULL)
	{
		if(t->el==s)
		{
			return c;
		}
		c++;
		t=t->next;
	}
	return 0;
}
//=====================================================================================================
LinkedList LinkedList::operator+(LinkedList b)
{
	LinkedList c;		//resulting list after concatnation
	if(top==NULL)
	{
		
		c.top=b.top;
		return c;
	}
	else if(top==b.top)		//if both lists are same we have to increase the list by itself
	{				//if we link a list to itself it will create infinite loop
		Node *t=new Node();
		t=top; int count=1;
		while(t!=NULL)
		{
			insertI(t->el,count++);		//inserting elements in the list from the list itself
			t=t->next;
		}
		return *this;
	}
	else
	c.top=top;		//at the top of first list
	
	while(top->next!=NULL)
	{
		top=top->next;		//going to the last of first list
	}
		
	top->next=b.top;		//last node of first list should point to top of second list
	
	return c;
}
//=====================================================================================================
void LinkedList ::print()
{
	if(top==NULL)
	{
		cout<<"List is empty!!\n";
		return;
	}
	Node  *t=new Node();		//t is used for traversing the list
	t=top;
	while(t!=NULL)
	{
		cout<<t->el<<endl;
		t=t->next;
	}
	cout<<"\n";
}

//=====================================================================================================
void LinkedList::input(int *a,int n)
{
	
	top=NULL;
	for(int i=n-1;i>=0;i--)
	{
		insertBeg(a[i]);
	}
}

//=====================================================================================================

int* increase(int *a,int &s,int p,int d)
{
	if(p<0)
	return a;
	s++;
	int *t=new int[s];
	int n=0;
	for(int i=0;i<s;i++)
	{
		if(i==p)
		{
			t[i]=d;
		}
		else
		{
			t[i]=a[n++];
		}
	}
	if(p>s)
	t[s-1]=d;
	return t;
}
int* decrease(int *a,int &s,int p)
{
	if(p>=s)
	return a;
	s--;
	int *t=new int[s];
	int n=0;
	for(int i=0;i<s+1;i++)
	{
		if(i!=p)
		{
			t[n++]=a[i];
		}
	}
	
	return t;
}
//=====================================================================================================
int main()
{
	LinkedList  a,b,r;
	int i,n,c,e,p;
	int *a1,*a2;
	int n1,n2;
	c=-1;
	cin.exceptions(std::ios::failbit);
	try{
		
		cout<<"For First list enter the number of elements:\n";
		cin>>n1;
		a1=new int[n1];
		cout<<"Enter the elements:\n";
		for(i=0;i<n1;i++)
		cin>>a1[i];
		
		cout<<"For Second list enter the number of elements:\n";
		cin>>n2;
		a2=new int[n2];
		cout<<"Enter the elements:\n";
		for(i=0;i<n2;i++)
		cin>>a2[i];
	
	do
	{
		/*if(c!=-1)
		{
			increase(a,b);
		}*/
	
		a.input(a1,n1);
		b.input(a2,n2);
		
		cout<<"First list:\n";
		a.print();
		cout<<"Second list:\n";
		b.print();
	
		cout<<"Form the list of operations:\n1.Insert one more element in the beggining\n2.Insert one more element at ith position\n3.Remove an element from the beggining\n4.Remove an element from ith position\n5.Concatnate both the lists\n6.Search for an element\nEnter your choice: ";
	 	cin>>c;
	 	cout<<endl;
	 	switch(c)
	 	{
	 		case 1:
	 		do
	 		{
	 		cout<<"Insert at beggining in:\n1.First List\n2.Second List\nEnter your choice: ";
	 		cin>>c;
	 		if(c==1||c==2)
	 		{
	 		cout<<"Enter the element to be inserted: ";
	 		cin>>e;
	 		if(c==1)
	 		{
	 			a.insertBeg(e);
	 			
	 			a1=increase(a1,n1,0,e);
	 			cout<<endl;
	 			cout<<"After inserting at beggining first list:\n";
	 			a.print();
	 		}
	 		else
	 		{
	 			b.insertBeg(e);
	 			
	 			a2=increase(a2,n2,0,e);
	 			cout<<endl;
	 			cout<<"After inserting at beggining second list:\n";
	 			b.print();
	 		}
	 		}
	 		else
	 		cout<<"Wrong choice!! Enter again\n";
	 		cout<<endl;
	 		}
	 		while(c!=1&&c!=2);
	 		break;
	 		
	 		case 2:
	 		do
	 		{
	 		cout<<"Insert at ith position in:\n1.First List\n2.Second List\nEnter your choice: ";
	 		cin>>c;
	 		if(c==1||c==2)
	 		{
	 		cout<<"Enter the element and position at to be inserted: ";
	 		cin>>e>>p;
	 		if(c==1)
	 		{
	 			a.insertI(e,p);
	 			
	 			a1=increase(a1,n1,p-1,e);
	 			cout<<endl;
	 			cout<<"After inserting at first list:\n";
	 			a.print();
	 		}
	 		else
	 		{
	 			b.insertI(e,p);
	 			
	 			a2=increase(a2,n2,p-1,e);
	 			cout<<endl;
	 			cout<<"After inserting second list:\n";
	 			b.print();
	 		}
	 		}
	 		else
	 		cout<<"Wrong choice!! Enter again\n";
	 		cout<<endl;
	 		}
	 		while(c!=1&&c!=2);
	 		break;
	 		
	 		case 3:
	 		do
	 		{
	 		cout<<"Remove from beggining in:\n1.First List\n2.Second List\nEnter your choice: ";
	 		cin>>c;
	 		if(c==1)
	 		{
	 			a.remBeg();
	 			
	 			a1=decrease(a1,n1,0);
	 			cout<<endl;
	 			cout<<"After removing from beggining first list:\n";
	 			a.print();
	 		}
	 		else if(c==2)
	 		{
	 			b.remBeg();
	 			
	 			a2=decrease(a2,n2,0);
	 			cout<<endl;
	 			cout<<"After removing from beggining second list:\n";
	 			b.print();
	 		}
	 		else
	 		cout<<"Wrong choice!! Enter again\n";
	 		cout<<endl;
	 		}
	 		while(c!=1&&c!=2);
	 		break;
	 		
	 		case 4:
	 		do
	 		{
	 		cout<<"Remove from ith position in:\n1.First List\n2.Second List\nEnter your choice: ";
	 		cin>>c;
	 		if(c==1||c==2)
	 		{
	 		cout<<"Enter the position for removing the element: ";
	 		cin>>p;
	 		if(c==1)
	 		{
	 			a.remI(p);
	 			
	 			a1=decrease(a1,n1,p-1);
	 			cout<<endl;
	 			cout<<"After removing first list:\n";
	 			a.print();
	 		}
	 		else
	 		{
	 			b.remI(p);
	 			
	 			a2=decrease(a2,n2,p-1);
	 			cout<<endl;
	 			cout<<"After removing second list:\n";
	 			b.print();
	 		}
	 		}
	 		else
	 		cout<<"Wrong choice!! Enter again\n";
	 		cout<<endl;
	 		}
	 		while(c!=1&&c!=2);
	 		break;
	 		
	 		case 5:
	 		do
	 		{
	 		cout<<"Concatnate\n1.Second list to first\n2.First list to second\nEnter your choice: ";
	 		cin>>c;
	 		if(c==1||c==2)
	 		{
	 			if(c==1)
	 			r=a+b;
	 			else
	 			r=b+a;
	 			cout<<endl;
	 			cout<<"Result after concatnation:\n";
	 			r.print();
	 		}
	 		else
	 		cout<<"Wrong choice!! Enter again\n";
	 		cout<<endl;
	 		}
	 		while(c!=1&&c!=2);
	 		break;
	 		
	 		case 6:
	 		do
	 		{
	 		cout<<"Search in\n1.First list\n2.Second list\nEnter your choice: ";
	 		cin>>c;
	 		
	 		if(c==1||c==2)
	 		{
	 			cout<<"Enter the element to be searched: ";
	 			cin>>e;
	 			if(c==1)
	 			p=a.search(e);
	 			else
	 			p=b.search(e);
	 			
	 			cout<<endl;
	 			if(p==0)
	 			cout<<"Element not found!!\n";
	 			else
	 			cout<<"Element found at position "<<p<<endl;
	 			
	 		}
	 		else
	 		cout<<"Wrong choice!! Enter again\n";
	 		cout<<endl;
	 		}
	 		while(c!=1&&c!=2);
	 		break;
	 		
	 		default:
	 		cout<<"Wrong choice!!\n";
	 		break;
	 	}
	 	cout<<"Enter 1 for another choice: ";
	 	cin>>c;
	 	cout<<endl;
	 	}while(c==1);
	 }
	catch(...){
		cout<<"\nIllegal input received!! Program will terminate.\n";
	}
	 	
	return 0; 	
}
//=====================================================================================================
