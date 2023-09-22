#include<stdio.h>
#include<stdlib.h>
int front = 0, rear = -1;

struct node
{
	int data;
	struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;


void Enqueqe(PPNODE head,int size)
{
	if(rear==(size-1))
	{
		printf("\n*** Circular Queqe OverFlow...!! *** \n");
	}
	else
	{
		rear++;
		int val = 0;
		printf("\n Enter Value : ");
		scanf("%d",&val);
		PNODE newn = NULL;
		newn = (PNODE) malloc(sizeof(NODE));
		if(rear==0)
		{
			newn->data = val;
			newn->next = newn;
			*head = newn;
		}
		else
		{
			PNODE temp = *head;
			while(temp->next != *head)
			{
				temp = temp->next;
			}
			temp->next = newn;
			newn->data = val;
			newn->next = *head;
		}
		printf("\n %d Enqueqe SuccessFully..!!",val);
	}
}

void Dequeqe(PPNODE head,int size)
{
	if((*head==NULL) || (front==0 && rear==-1))
	{
		printf("\n *** Circular Queqe UnderFlow...Plz,Enter Some Elements...!!");
	}
	else if(front==(rear))
	{
		printf("\n This is the Last Item...!!");
		PNODE temp = *head;
		printf("\n Dequeqe SuccessFul With Value : %d",temp->data); 
		free(temp);
		*head = NULL;
		printf("\n Now...Circular Queqe is Empty...!! ");
		
		front = 0;
		rear = -1;
	}
	else
	{
		front++;
		PNODE first = *head;
		PNODE temp = first->next;
		*head = temp;
		while(temp->next != first)
		{
			temp = temp->next;
		}
		temp->next = first->next;
		printf("\n Dequeqe SuccessFul with Value : %d",first->data);
		free(first);
	}
}
void Display(PNODE head,int size)
{
	if((head==NULL) || (front==0 && rear==-1))
	{
		printf("\n *** Circular Queqe UnderFlow...Plz,Enter Some Elements...!!");
	}
	else
	{
		PNODE temp = head;
		printf("\n Elements in Cirucular Queqe as Follows - ");
		while((temp->next != head))
		{
			printf("\n %d",temp->data);
			temp = temp->next;
		}
		printf("\n %d",temp->data);
	}
}
void Search(PNODE head,int size)
{
	if((head==NULL) || (front==0 && rear==-1))
	{
		printf("\n *** Circular Queqe UnderFlow...Plz,Enter Some Elements...!!");
	}
	else
	{
		PNODE temp = head;
		int val = 0,flag = 0,iCnt = 0;
		printf("\n Enter Value To be Search : ");
		scanf("%d",&val);
		while(temp->next != head)
		{
			iCnt++;
			if(val == temp->data)
			{
				flag = 1;
				printf("%d Found At Position : %d\n",val,iCnt);
			}
			temp = temp->next;
		}
		if(val == temp->data)
			{
				flag = 1;
				printf("%d Found At Position : %d\n",val,(++iCnt));
			}
		if(flag == 0)
		{
			printf("\n *** Element Not Found...!! ***");
		}
	}
}

int main()
{
	PNODE First = NULL;
	unsigned int size = 0,ch = 0;
	printf("\n Welcome in DSA World...!! Circular Queqe Using Linked List..!! \n");
	
	printf("\n Enter the Size of Queqe : ");
	scanf("%d",&size);
	
	do{
	printf("\n ---- My Menu ----");
	printf("\n -----------------");
	printf("\n 1.Enqueqe");
	printf("\n 2.Dequeqe");
	printf("\n 3.Display");
	printf("\n 4.Search");
	printf("\n 5.Exit");
	printf("\n -----------------");
	printf("\n Enter Your Choice : ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			Enqueqe(&First,size);
			break;
		case 2:
			Dequeqe(&First,size);
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
	return 0;
}
