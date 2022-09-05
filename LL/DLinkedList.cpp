typedef int E;
#include<iostream>
using namespace std;
class DNode
{
	E el;
	DNode *next;
	DNode *prev;
	public:
		DNode();
		DNode(E);
	friend class DLinkedList;
};

DNode ::DNode()
{
	next=prev=NULL;
}

DNode::DNode(E e)
{
	el=e;
	next=prev=NULL;
}

class DLinkedList
{
	DNode *head,*tail;
	public:
		DLinkedList();
		void insertBeg(E);
		void insertEnd(E);
		void insertI(E,int);
		void remBeg();
		void remEnd();
		void remI(int);
		int search(E);
		DLinkedList operator+(DLinkedList);
		
		void input(E*,int);
		void print();
		void printR();
		
};
DLinkedList ::DLinkedList()
{
	head= new DNode;
	tail = new DNode;
	head->next=tail;
	tail->prev=head;
}

void DLinkedList::insertBeg(E e)
{
	DNode *t=new DNode(e);
	t->next=(head->next);
	head->next=t;
	(t->next)->prev=t;
	t->prev=head;
	
	
}
void DLinkedList::remBeg()
{
	if(head->next==tail)
	{
		cout<<"Doubly Linked List is empty!!\n";
		return;
	}
	DNode *t=new DNode();
	t=head->next;
	head->next=t->next;
	(head->next)->prev=t->prev;
	delete t;
}
void DLinkedList::insertEnd(E e)
{
	DNode *t=new DNode(e);
	t->prev=tail->prev;
	tail->prev=t;
	(t->prev)->next=t;
	t->next=tail;
	
}
void DLinkedList::remEnd()
{
	if(tail->prev==head)
	{
		cout<<"Doubly Linked List is empty!!\n";
		return;
	}
	DNode *t=new DNode();
	t=tail->prev;
	tail->prev=t->prev;
	(tail->prev)->next=t->next;
	delete t;
}

void DLinkedList ::insertI(E e,int i)
{
	if(i<1)
	{
		cout<<"Position cannot be less than 1!!\n";
		return;
	}
	DNode *newN=new DNode(e);
	
	if(head->next==tail||i==1)
	{
		if(head->next==tail)
		cout<<"Doubly Linked List is empty!! Element inserted at top\n";
		newN->next=(head->next);
		head->next=newN;
		(newN->next)->prev=newN;
		newN->prev=head;
		return;
	}
	
	int c=1;
	DNode *t=new DNode();		//t is used for traversing the Doubly Linked List
	t=head->next;
	
	while(t->next!=tail)
	{
		c++;
		if(c==i)
		break;
		t=t->next;
	}
	
	if(c<i)
	cout<<"Doubly Linked List contains only "<<c<<" nodes.So new element inserted at the last.\n";
	newN->next=t->next;
	t->next=newN;
	
	/*(newN->next)->prev=newN;
	newN->prev=t;*/
	
	t=newN->next;
	newN->prev=t->prev;
	t->prev=newN;
}

void DLinkedList ::remI( int i)
{
	if(i<1)
	{
		cout<<"Position cannot be less than 1!!\n";
		return;
	}
	
	DNode  *t=new DNode();
	t=head->next;
	if(head->next==tail||i==1)
	{
		if(head->next==tail)
		{
			cout<<"Doubly Linked List is empty!!\n";
			return;
		}
		
		head->next=t->next;
		(head->next)->prev=t->prev;
		delete t;
		return;
	}
	
	int c=1;
	while(t->next!=tail)
	{
		c++;
		if(c==i)
		break;
		t=t->next;
	}
	
	if(c<i)
	{
		cout<<"Doubly Linked List contains only "<<c<<" nodes.\n";
		return;
	}
	
	DNode *temp=new DNode();		//temporary node for deletetion
	temp=t;
	temp=temp->next;		//node to be deleted must be secured first for clearing memory
	t->next=(t->next)->next;
	(t->next)->prev=temp->prev;
	delete temp;
}
//=============================================================================================
void DLinkedList::print()
{
	if(head->next==tail)
	{
		cout<<"Doubly Linked List is empty!!\n";
		return;
	}
	
	DNode *t=new DNode();
	t=head;
	while(t->next!=tail)
	{
		t=t->next;
		cout<<t->el<<endl;
	}
	
	cout<<endl;
	
}
void DLinkedList:: printR()
{
	if(tail->prev==head)
	{
		cout<<"Doubly Linked List is empty!!\n";
		return;
	}
	DNode *t=new DNode();
	t=tail;
	while(t->prev!=head)
	{
		t=t->prev;
		cout<<t->el<<endl;
	}
	cout<<endl;
}

int DLinkedList::search(E e)
{
	DNode *t=new DNode();
	t=head;
	
	int c=1;
	while(t->next!=tail)
	{
		t=t->next;
		if(t->el==e)
		return c;
		c++;
	}
	
	return 0;
}

DLinkedList DLinkedList:: operator+(DLinkedList b)
{
	DLinkedList c;
	if(head->next==tail)
	{
		c.head=b.head;
		c.tail=b.tail;
		return c;
	}
	else if(head==b.head)
	{
		DNode *t=new DNode();
		t=head; int count=1;
		while(t->next!=tail)
		{
			t=t->next;
			insertI(t->el,count++);
		}
		return *this;
	}
	else 
	{
		c.head=head;
		c.tail=b.tail;
	}
	
	while(head->next!=tail)
	{
		head=head->next;
	}
	
	head->next=b.head->next;
	(head->next)->prev=tail->prev;
	
	return c;
}

void DLinkedList::input(E *a,int n)
{
	
	head= new DNode;
	tail = new DNode;
	head->next=tail;
	tail->prev=head;
	for(int i=n-1;i>=0;i--)
	{
		insertBeg(a[i]);
	}
}
E* increase(E *a,int &s,int p,E d)
{
	if(p<0)
	return a;
	s++;
	E *t=new E[s];
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
E* decrease(E *a,int &s,int p)
{	
	if(p>=s)
	return a;
	s--;
	E *t=new E[s];
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
	
int main()
{
	DLinkedList  a,b,r;
	int i,c,p,n1,n2;
	E e,*a1,*a2;
	cin.exceptions(std::ios::failbit);
	try{
		
		cout<<"For First Doubly Linked List enter the number of elements:\n";
		cin>>n1;
		a1=new E[n1];
		cout<<"Enter the elements:\n";
		for(i=0;i<n1;i++)
		cin>>a1[i];
		
		cout<<"For Second Doubly Linked List enter the number of elements:\n";
		cin>>n2;
		a2=new E[n2];
		cout<<"Enter the elements:\n";
		for(i=0;i<n2;i++)
		cin>>a2[i];
	
	do
	{
	
		a.input(a1,n1);
		b.input(a2,n2);
		
		cout<<"First Doubly Linked Doubly Linked List:\n";
		a.print();
		cout<<"Second Doubly Linked Doubly Linked List:\n";
		b.print();
	
		cout<<"Form the list of operations:\n1.Insert one more element in the beggining\n2.Insert one more element at the end\n3.Insert one more element at ith position\n4.Remove an element from the beggining\n5.Remove an element from the end\n6.Remove an element from ith position\n7.Concatnate both the lists\n8.Search for an element\nEnter your choice: ";
	 	cin>>c;
	 	cout<<endl;
	 	switch(c)
	 	{
	 		case 1:
	 		do
	 		{
	 		cout<<"Insert at beggining in:\n1.First Doubly Linked List\n2.Second Doubly Linked List\nEnter your choice: ";
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
	 			cout<<"After inserting at beggining first Doubly Linked List:\n";
	 			a.print();
	 		}
	 		else
	 		{
	 			b.insertBeg(e);
	 			
	 			a2=increase(a2,n2,0,e);
	 			cout<<endl;
	 			cout<<"After inserting at beggining second Doubly Linked List:\n";
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
	 		cout<<"Insert at end in:\n1.First Doubly Linked List\n2.Second Doubly Linked List\nEnter your choice: ";
	 		cin>>c;
	 		if(c==1||c==2)
	 		{
	 		cout<<"Enter the element to be inserted: ";
	 		cin>>e;
	 		if(c==1)
	 		{
	 			a.insertEnd(e);
	 			
	 			a1=increase(a1,n1,n1-1,e);
	 			cout<<endl;
	 			cout<<"After inserting at end first Doubly Linked List:\n";
	 			a.print();
	 		}
	 		else
	 		{
	 			b.insertEnd(e);
	 			
	 			a2=increase(a2,n2,n2-1,e);
	 			cout<<endl;
	 			cout<<"After inserting at end second Doubly Linked List:\n";
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
	 		cout<<"Insert at ith position in:\n1.First Doubly Linked List\n2.Second Doubly Linked List\nEnter your choice: ";
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
	 			cout<<"After inserting first Doubly Linked List:\n";
	 			a.print();
	 		}
	 		else
	 		{
	 			b.insertI(e,p);
	 			
	 			a2=increase(a2,n2,p-1,e);
	 			cout<<endl;
	 			cout<<"After inserting second Doubly Linked List:\n";
	 			b.print();
	 		}
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
	 		cout<<"Remove from beggining in:\n1.First Doubly Linked List\n2.Second Doubly Linked List\nEnter your choice: ";
	 		cin>>c;
	 		if(c==1)
	 		{
	 			a.remBeg();
	 			
	 			a1=decrease(a1,n1,0);
	 			cout<<endl;
	 			cout<<endl;
	 			cout<<"After removing from beggining first Doubly Linked List:\n";
	 			a.print();
	 		}
	 		else if(c==2)
	 		{
	 			b.remBeg();
	 			
	 			a2=decrease(a2,n2,0);
	 			cout<<endl;
	 			cout<<"After removing from beggining second Doubly Linked List:\n";
	 			b.print();
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
	 		cout<<"Remove from end in:\n1.First Doubly Linked List\n2.Second Doubly Linked List\nEnter your choice: ";
	 		cin>>c;
	 		if(c==1)
	 		{
	 			a.remEnd();
	 			
	 			a1=decrease(a1,n1,n1-1);
	 			cout<<endl;
	 			cout<<"After removing from end first Doubly Linked List:\n";
	 			a.print();
	 		}
	 		else if(c==2)
	 		{
	 			b.remEnd();
	 			
	 			a2=decrease(a2,n2,n2-1);
	 			cout<<endl;
	 			cout<<"After removing from end second Doubly Linked List:\n";
	 			b.print();
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
	 		cout<<"Remove from ith position in:\n1.First Doubly Linked List\n2.Second Doubly Linked List\nEnter your choice: ";
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
	 			cout<<"After removing first Doubly Linked List:\n";
	 			a.print();
	 		}
	 		else
	 		{
	 			b.remI(p);
	 			
	 			a2=decrease(a2,n2,p-1);
	 			cout<<endl;
	 			cout<<"After removing second Doubly Linked List:\n";
	 			b.print();
	 		}
	 		}
	 		else
	 		cout<<"Wrong choice!! Enter again\n";
	 		cout<<endl;
	 		}
	 		while(c!=1&&c!=2);
	 		break;
	 		
	 		case 7:
	 		do
	 		{
	 		cout<<"Concatnate\n1.Second Doubly Linked List to first\n2.First Doubly Linked List to second\nEnter your choice: ";
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
	 		
	 		case 8:
	 		do
	 		{
	 		cout<<"Search in\n1.First Doubly Linked List\n2.Second Doubly Linked List\nEnter your choice: ";
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
