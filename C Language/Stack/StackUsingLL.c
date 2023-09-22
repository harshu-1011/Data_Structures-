#include<stdio.h>
#include<stdlib.h>

int top = -1;

struct node
{
	int data;
	struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void PUSH(PPNODE head,int size)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->next = NULL;
	if((top==(size-1)))
	{
		printf("\n *** STACK OVERFLOW...!! ***");
	}	
	else if((top==-1)&&(top<(size)))
	{
		int val = 0;
		printf("\n Enter Value to PUSH : ");
		scanf("%d",&val);		
		newn->data = val;
		newn->next = *head;
		*head = newn;
		printf("\n %d Element Pushed At TOP of STACK...!!",val);
		top++;
	}
	else if(top<size)
	{
		int val1 = 0;
		printf("\n Enter Value to PUSH : ");
		scanf("%d",&val1);
		newn->data = val1;
		newn->next = *head;
		*head = newn;
		printf("\n %d Element Pushed At TOP of STACK...!!",val1);
		top++;
	}
}

void POP(PPNODE head,int size)
{
	if((*head==NULL)&&(top==-1))
	{
		printf("\n *** STACK UNDERFLOW...!!\n Nothing to POP...!!");
	}
	else
	{
		top--;
		PNODE first = *head,temp = NULL;
		temp = first->next;
		*head = temp;
		printf("\n POPED Element : %d",first->data);
		free(first);
	}
}


void Display(PNODE head,int size)
{
	if((head == NULL)&&(top == -1))
	{
		printf("\n*** STACK UNDERFLOW...!!\n Nothing to Display...!! ***");
	}
	else
	{
		PNODE temp = head;
		int top1 = top;
		printf("\n Stack Elements Are - ");
		while(top1 != -1)
		{
			printf("\n %d",temp->data);
			temp = temp->next;
			top1--;
		}
	}
}
void Search(PNODE head,int size)
{
	if((head==NULL)&&(top==-1))
	{
		printf("\n *** STACK UNDERFLOW...!!\n Nothing to Search...!! ***");
	}
	else
	{
		PNODE temp = head;
		int flag = 0,cnt = 0,iCnt = 0,top1= top,data = 0;
		printf("\n Enter Data to be Search : ");
		scanf("%d",&data);
		while(top1 != -1)
		{
		iCnt++;
			if(temp->data==data)
			{
				cnt++;
				flag = 1;
				printf("\n %d is Found At Pos : %d",data,cnt);
			}
		temp = temp->next;
		top1--;
		}
		if(flag==0)
		{
			printf("\n Element Not Found..!!");
		}
		printf("\n Total Count of %d is %d",data,cnt);
	}
}
void isEmpty(int size)
{
	if(top==-1)
	{
		printf("\n isEmpty : TRUE \n");
	}
	else
	{
		printf("\n isEmpty : FALSE \n");
	}
}
void isFull(int size)
{
	if(top==(size-1))
	{
		printf("\n isFull : TRUE \n");
	}
	else
	{
		printf("\n isFull : FALSE \n");
	}
}

int main()
{
	PNODE First=NULL;
	int size = 0, ch = 0;
	printf("\n Welcome in DSA World..!! Stack Using Linked List...!!\n");
	printf("\n Enter Number of the Nodes in LL : ");
	scanf("%d",&size);
	
	do{
	printf("\n ---- MY MENU ----");
	printf("\n -----------------");
	printf("\n 1.PUSH ");
	printf("\n 2.POP ");
	printf("\n 3.Display ");
	printf("\n 4.Search ");
	printf("\n 5.isFull ");
	printf("\n 6.isEmpty ");
	printf("\n 7.Exit ");
	printf("\n -----------------");
	printf("\n Enter Your Choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			PUSH(&First,size);
			break;
		case 2:
			POP(&First,size);
			break;
		case 3:
			Display(First,size);
			break;
		case 4:
			Search(First,size);
			break;
		case 5:
			isFull(size);
			break;
		case 6:
			isEmpty(size);
			break;
		case 7:
			return 0;
			break;
		default: 
			printf("\n *** Invalid Choice...!! ***");
	}
	}while(ch != 7);
	return 0;
}
