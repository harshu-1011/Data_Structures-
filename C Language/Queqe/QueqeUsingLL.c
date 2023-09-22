#include<stdio.h>
#include<stdlib.h>
int rear = 0, front = 0;
struct node
{
	int data;
	struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void ADD(PPNODE head,int size)
{
	if(size==rear)
	{
		printf("\n*** Queqe OverFlow...!! ***");
	}
	else
	{
		rear++;
		int val = 0;
		printf("\n Enter Value : ");
		scanf("%d",&val);
		
		PNODE newn = NULL;
		newn = (PNODE) malloc(sizeof(NODE));
		newn->next = NULL;
		
		if(rear==1){
		*head = newn;		
		newn->data = val;		
		}
		else
		{
			PNODE temp = *head;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newn;
			newn->data = val;
		}
		printf("\n Element Added in Queqe With Value : %d",val);
	}
}

void Remove(PPNODE head,int size)
{
	if((*head==NULL))
	{
		printf("\n *** Queqe UnderFlow...Nothing to Remove...!!\n plz,Add Some Elements in Queqe First..!!");
		rear = 0;
	}
	else
	{
		if(rear==1)
		{
			PNODE temp = *head;
			printf("\n %d Removed..!!",temp->data);
			*head = NULL;
			free(temp);
		}
		else
		{
			front++;
			PNODE first = *head;
			PNODE temp = first->next;
			*head = temp;
			printf("\n %d Removed...!!",first->data);
			free(first);
		}
	}
}

void Display(PNODE head,int size)
{
	if((head==NULL)&&(rear==0))
	{
		printf("\n *** Queqe UnderFlow...Nothing to Display...!!\n Plz, Add Elements in Queue.");
	}
	else
	{
		PNODE temp = head;
		printf("\n Elements in Queqe : ");
		while(temp->next != NULL)
		{
			printf("\n %d",temp->data);
			temp=temp->next;
		}
		printf("\n %d",temp->data);
	}
}

void Search(PNODE head,int size)
{
	if(head == NULL)
	{
		printf("\n *** Queqe UnderFlow...Nothing to Search...!!\n Plz,Add Some Elements in Queqe.");
	}
	else
	{
		int val = 0,cnt = 0, flag = 0;
		PNODE temp = head;
		printf("\n Enter Value To be Search : ");
		scanf("%d",&val);
		while(temp->next != NULL)
		{
			if(temp->data == val)
			{
				flag = 1;
				cnt++;
			}
			temp = temp->next;
		}
		if(temp->data == val)
			{
				flag = 1;
				cnt++;
			}
		if(flag==1)
		{
			printf("\n %d Found with Count : %d",val,cnt);
		}
		else
		{
			printf("\n *** Element Not Found...!! ***");
		}
	}
}

int main()
{
	PNODE First = NULL;
	int size = 0,ch = 0;
	
	printf("\n Welcome in DSA World...Queqe Using Linked List...!!\n");
	
	printf("\n Enter How Many Nodes You Want in Queqe : ");
	scanf("%d",&size);
	
	do{
	printf("\n ---- My Menu ----");
	printf("\n -----------------");
	printf("\n 1.ADD");
	printf("\n 2.Remove");
	printf("\n 3.Display");
	printf("\n 4.Search");
	printf("\n 5.Exit");
	printf("\n -----------------");
	printf("\n Enter Your Choice : ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			ADD(&First,size);
			break;
		case 2:
			Remove(&First,size);
			break;
		case 3:
			Display(First,size);
			break;
		case 4:
			Search(First,size);
			break;
		case 5:
			return 0;
			break;
		default:
			printf("\n *** Invalid Choice...!! ***");
	}
	}while(ch!=5);
}
