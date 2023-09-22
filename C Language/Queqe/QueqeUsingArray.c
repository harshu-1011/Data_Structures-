#include<stdio.h>
int rear = -1,front=0;

void ADD(int arr[],int size)
{
	if(rear==(size-1))
	{
		printf("\n Queqe Overflow...!!");
	}
	else
	{
		int val=0;	
		printf("\n Enter Value : ");
		scanf("%d",&val);
		if(rear==(size-1))
		{
			rear = 0;
			arr[rear]=val;
		}
		else
		{
			rear++;
			arr[rear]=val;
			
		}
		printf("\n %d Added in Queqe...!!",val);
	}
}
void Remove(int arr[])
{
	if((rear==-1) || (front==(rear+1)))
	{
		printf("\n Queqe UnderFlow..!! \n Nothing to Remove...!!");
	}
	else if(front==rear)
	{
		printf("\n *** Element Removed : %d ***",arr[front]);
		printf("\n Now...Queqe was fully Empty...!!");
		front = 0;
		rear = -1;
	}
	else{
		printf("\n *** Element Removed : %d ***",arr[front]);
		front++;
		rear--;
	}
}
void Display(int arr[],int size)
{
	if(rear==-1)
	{
		printf("\n*** Queqe UnderFlow...!! \n Nothing to Dispay...!! ***");
	}
	else
	{
		int point = front;
		printf("\n Elements of Queqe : ");
		while(point != (rear+1))
		{
			printf("\n%d",arr[point]);
			point++;
		}
	}
}
void Search(int arr[],int size)
{
	if(front==0 && rear==-1)
	{
		printf("\n *** Queqe UnderFlow...!!\n Plz,Enter Some Elements in Queqe..!! ***\n");
	}
	else
	{
		int cnt = front,val=0,flag = 0;
		printf("\n Enter Value to be Value : ");
		scanf("%d",&val);
		
		while(cnt != (rear+1))
		{
			if(val==arr[cnt])
			{
				flag=1;
				printf("%d Found At Pos : %d\n",val,(cnt+1));
			}
			cnt++;
		}
		if(flag==0)
		{
			printf("\n *** Element Not Found...!! *** \n");
		}
	}
}
void isFull(int size)
{
	if(rear==(size-1))
	{
		printf("\n isFull : TRUE \n");
	}
	else
	{
		printf("\n isFull : FALSE \n");
	}
}
void isEmpty(int size)
{
	if(rear==-1)
	{
		printf("\n isEmpty : TRUE \n");
	}
	else
	{
		printf("\n isEmpty : FALSE \n");
	}
}

int main()
{
	printf("\n Welcome in DSA World...Queqe Using Array...!! \n");
	int size = 0,ch = 0;
	printf("\n Enter the Size of Queue : ");
	scanf("%d",&size);
	int arr[size];
	do{
	printf("\n ---- MY MENU ----");
	printf("\n -----------------");
	printf("\n 1.ADD ");
	printf("\n 2.Remove ");
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
			ADD(arr,size);
			break;
		case 2:
			Remove(arr);
			break;
		case 3:
			Display(arr,size);
			break;
		case 4:
			Search(arr,size);
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
