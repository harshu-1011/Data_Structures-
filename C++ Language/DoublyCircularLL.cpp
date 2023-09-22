#include<iostream>
using namespace std;

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE head)
{	
	int val=0;
	cout<<"\n I'm In InsertFirst Function"<<endl;
	
	PNODE newn = NULL;
	newn = (PNODE) malloc(sizeof(NODE));
	newn->prev=NULL;
	newn->data=0;
	newn->next=NULL;
	
	cout<<"\n Enter a Data : ";
	cin>>val;
	
	if(*head == NULL)
	{	
		cout<<"\n Linked List was firstly Empty...Now, Inserted "<<val<<" at First Position...!!"<<endl;
		*head=newn;
		newn->prev=*head;
		newn->data = val;
		newn->next = *head;
	}
	else
	{
		PNODE temp = *head;
		newn->next=*head;
		cout<<val<<" inserted at First Position..!!"<<endl;
		newn->data = val;
		while(temp->next != *head)
		{
			temp= temp->next;
		}
		*head=newn;
		temp->next = *head;
		newn->prev = temp;
	}
}

void InsertLast(PPNODE head)
{
	int val = 0;
	cout<<"I'm in InsertLast function "<<endl;
	
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->prev = NULL;
	newn->data = 0;
	newn->next = NULL;
	
	cout<<"\n Enter a Data : ";
	cin>>val;
		
	if(*head == NULL)
	{
		cout<<"\n Linked List was firstly Empty...Now, Inserted "<<val<<" at Last Position...!!"<<endl;
		*head = newn;
		newn->prev = *head;
		newn->data = val;
		newn->next = *head;
	}
	else
	{	
		PNODE temp = *head;
		while(temp->next != *head)
		{
			temp = temp->next;
		}
		temp->next = newn;
		newn->prev = temp;
		newn->data = val;
		newn->next = *head;
		cout<<val<<" inserted at Last..!!"<<endl;
	}
}

void InsertAtPos(PPNODE head,int cnt)
{
	int val = 0, pos = 0, iCnt = 1;
	cout<<"I'm in InsertAtPos function "<<endl;
	
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = 0;
	newn->next = NULL;
	
	cout<<"\n Enter a Data : ";
	cin>>val;
	
	if(*head == NULL)
	{
		cout<<"\n Linked List was firstly Empty...Now, Inserted "<<val<<" at First Position...!!"<<endl;
		*head = newn;
		newn->prev = *head;
		newn->data = val;
		newn->next = *head;
	}
	else
	{
		PNODE temp = *head, prev = NULL;
		cout<<"\n Enter Position Between 1-"<<cnt<<" :"<<endl;
		cin>>pos;
		if(pos<1 || pos>cnt)
		{
			cout<<"INVALID POSITION...!!"<<endl;
		}
		else
		{
			while(iCnt != pos)
			{
				iCnt++;
				prev = temp;
				temp = temp->next;
			}
			prev->next = newn;
			newn->prev = prev;
			newn->next = temp;
			temp->prev = newn;
			newn->data = val;
			cout<<val<<" entered at Position "<<pos<<endl;
		}
	}
}

void DeleteFirst(PPNODE head)
{
	if(*head==NULL)
	{
		cout<<"\n Linked List is empty,Nothing to delete...Plz, Enter Some nodes First...!!"<<endl;
	}
	else
	{
	    	PNODE first = *head;
    		PNODE temp = *head;
		while(temp->next != *head)
		 {
		     temp=temp->next;
		 }
		 *head=first->next;
		 first->next->prev=temp;
		 temp->next = *head;
		 printf("\nFirst node is Deleted Successfully with values :%d",first->data);
		 free(first);
	}
}

void DeleteLast(PPNODE head)
{
	if(*head==NULL)
	{
		cout<<"\n Linked List is empty,Nothing to delete...Plz, Enter Some nodes First...!!"<<endl;
	}
	else
	{
		PNODE temp = *head;
		PNODE first = *head;
		PNODE prev = NULL;
		while(temp->next != *head)
		{	
			prev=temp;
			temp=temp->next;
		}
		prev->next=*head;
		first->prev = prev;
		cout<<temp->data<<" deleted SucessFully from the last...!!"<<endl;
		free(temp);
	}	
}

void DeleteAtPos(PPNODE head,int cnt)
{
	int val = 0, pos = 0, iCnt = 1;
	cout<<"I'm in DeletAtPos function "<<endl;
		
	if(*head == NULL)
	{
		cout<<"\n Linked List is Empty...!!\n Nothing To Delete..!!\n"<<endl;
	}
	else
	{
		PNODE temp = *head,prev = NULL;
		cout<<"\n Enter Position Between 1-"<<cnt<<" :"<<endl;
		cin>>pos;
		if(pos<1 || pos>cnt)
		{
			cout<<"INVALID POSITION...!!"<<endl;
		}
		else
		{
			while(iCnt != pos)
			{
				iCnt++;
				prev = temp;
				temp = temp->next;
			}
			prev->next=temp->next;
			temp->next->prev = prev;
			cout<<temp->data<<" deleted SuccessFully....!!";
			free(temp);
		}
	}
}

void Display(PNODE head)
{
	if(head==NULL)
	{
		cout<<"\n Linked List is Empty, Nothing to Display..!!"<<endl;
	}
	else
	{
		PNODE temp = head;
		cout<<"\n Elements of Linked List are as Follows : ";
		while(temp->next != head)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}	
		cout<<temp->data<<"\t";
	}
}

void search(PNODE head)
{
	int val = 0, flag = 0, cnt = 0;
	if(head==NULL)
	{
		cout<<"\n Linked List is Empty...Add Something To Search..!!";
	}
	else
	{
		PNODE temp = head;
		cout<<"\n Enter Value  to be Search : ";
		cin>>val;
		while(temp->next != head)
		{
			cnt++;
			if(temp->data == val)
			{
				flag = 1;
				cout<<temp->data<<" found at Position : "<<cnt;
			}
			temp= temp->next;
		}
		if(temp->data == val)
		{
			flag = 1;
			cout<<temp->data<<" found at Position : "<<(cnt+1);
		}
		if(flag==0)
		{
			cout<<"Element Not Found...!!"<<endl;
		}
	}
}

int Count(PNODE head)
{
	int cnt = 0;
	if(head==NULL)
	{
		cout<<"\n Linked List is Empty...Add Something To Count..!!";
	}
	else
	{
		PNODE temp = head;
		while(temp->next != head)
		{
			cnt++;
			temp= temp->next;
		}
		cnt++;
	}
	return cnt;
}

int main()
{
PNODE First = NULL;
int ch = 0, count = 0;
cout<<"Hello World...Welcome in DSA World...!!\nProgram to demonstrate Doubly Circular Linked List...!!\n";

do{
	cout<<"\n---- My Menu ----"<<endl;
	cout<<"1.Insert At First"<<endl;
	cout<<"2.Insert At Last"<<endl;
	cout<<"3.Insert At Certain Position"<<endl;
	cout<<"4.Delete At First"<<endl;
	cout<<"5.Delete At Last"<<endl;
	cout<<"6.Delete At Certain Position"<<endl;
	cout<<"7.Display Linked List"<<endl;
	cout<<"8.Search in Node"<<endl;
	cout<<"9.Count No. of Nodes"<<endl;
	cout<<"10.EXIT"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Enter Your Choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			InsertFirst(&First);
			break;
		case 2:
			InsertLast(&First);
			break;
		case 3:
			count = Count(First);
			InsertAtPos(&First,count);
			break;
		case 4:
			DeleteFirst(&First);
			break;
		case 5:
			DeleteLast(&First);
			break;
		case 6:
			count = Count(First);
			DeleteAtPos(&First,count);
			break;		
		case 7:
			Display(First);
			break;
		case 8:
			search(First);
			break;
		case 9:
			count = Count(First);
			cout<<"\n No. of Nodes : "<<count<<endl;
			break;
		case 10:
			return 0;
		default:
			cout<<"Plz...Enter Valid Choice And Try Again With valid Details...!!"<<endl;
	}
}while(ch!=10);
}
