#include<stdio.h>
int rear = -1, front = 0;

void Enqueqe(int arr[],int size)
{
	int val = 0;
	
	if(rear==-1 && front==0)
	{	rear++;
		printf("\n Enter Value : ");
		scanf("%d",&val);
		arr[rear]= val;
		printf("\n Enqueqe SuccessFul With Value : %d",val);
	}
	else if(rear==(size-1))
	{
		printf("\n*** Queqe OverFlow...!! ***");
	}
	else
	{
		rear++;
		printf("\n Enter Value : ");
		scanf("%d",&val);
		arr[rear]= val;
		printf("\n Enqueqe SuccessFul With Value : %d",val);
	}
}
void Dequeqe(int arr[],int size)
{
	if(front==rear)
	{
		printf("\n Dequeqe SuccessFul with Value : %d",arr[front]);
		printf("\n Now...Circular is Fully Empty...!!");
		rear=-1;
		front=0;
	}
	else if(rear==-1 && front==0)
	{
		printf("\n Queqe Underflow...!! , Plz Enter Some Elements.");
	}
	else
	{
		printf("\n Dequeqe SuccessFul with Value : %d",arr[front]);
		front++;
	}
}
void Display(int arr[],int size)
{
	if(rear==-1 && front==0)
	{
		printf("\nCircular Queqe UnderFlow...!! plz, Enter Some Element in Queqe.");
	}
	else
	{
		int i = 0;
		printf("\n Elements in Circular Queqe : ");
		for(i=front;i<=rear;i++)
		{
			printf("\n %d",arr[i]);
		}
	}
}
void Search(int arr[],int size)
{
	if(front==0 && rear==-1)
	{
		printf("\nCircular Queqe UnderFlow...!! plz, Enter Some Element in Queqe.");
	}
	else
	{
		int i = 0,val = 0,cnt = 0,flag = 0;
		printf("\n Enter Value To be Search : ");
		scanf("%d",&val);
		for(i=front;i<=rear;i++)
		{
			if(arr[i]==val)
			{
				cnt++;
				flag = 1;
			}
		}
		if(flag==1)
		{
			printf("%d Found with Occurence : %d",val,cnt);
		}
		else
		{
			printf("\n Element Not Found...!!");
		}
	}
}

int main()
{
	int size = 0,ch = 0;
	
	printf("\n Welcome in DSA World...Circular Queqe Using Array...!!\n");
	
	printf("\n Enter How Many Elements You Want in Circular Queqe : ");
	scanf("%d",&size);
	
	int arr[size];
	
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
			Enqueqe(arr,size);
			break;
		case 2:
			Dequeqe(arr,size);
			break;
		case 3:
			Display(arr,size);
			break;
		case 4:
			Search(arr,size);
			break;
		case 5:
			return 0;
			break;
		default:
			printf("\n *** Invalid Choice...!! ***");
	}
	}while(ch!=5);
}
