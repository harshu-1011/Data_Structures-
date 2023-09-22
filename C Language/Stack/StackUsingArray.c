#include<stdio.h>
int top=-1;
void PUSH(int arr[],int size)
{
	if(top==(size-1))
	{
		printf("\n *** STACK OVERFLOW..!! ***");
	}	
	else
	{
	int val =0;
		top++;
		printf("\n Enter Value to PUSH : ");
		scanf("%d",&val);
		arr[top]=val;
		printf("\n %d is Inserted at the Top of Stack..!!",val);
	}
}
void POP(int arr[])
{
	if(top==-1)
	{
		printf("\n *** STACK UNDERFLOW...!!\n Nothing to POP...!! ***\n");
	}
	else
	{
		printf("\n Popped Element : %d",arr[top]);
		top--;
		printf("\n POP SUCCESSFUL...!!\n");
	}
}
void Display(int arr[],int size)
{
	if(top==-1)
	{
		printf("\n  *** STACK UNDERFLOW...!!\nNothing to Display...!! *** \n");
	}
	else
	{
	printf("\n Stack Elements Are - ");
	int top1 = top;
		while(top1 != -1)
		{
			printf("\n %d",arr[top1]);
			top1--;
		}
	}
}
void Search(int arr[],int size)
{
	if(top==-1)
	{
		printf("\n *** STACK UNDERFLOW...!!\nNothing to Search...!! *** \n ");
	}
	else
	{
		int top1 = top, data = 0, flag = 0,Cnt =0,cnt =0;
		printf("\n Enter Data To be Search : ");
		scanf("%d",&data);
		while(top1 != -1)
		{
		Cnt++;
			if(arr[top1]==data)
			{
				cnt++;
				flag = 1;
				printf("\n %d is Found At Pos : %d ",data,Cnt);
			}
			top1--;
		}
		if(flag==0)
		{
			printf("\n *** Element Not Found...!! *** ");
		}
		printf("\n %d Element Found with Total Count of Occurence : %d",data,cnt);
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

int main()
{
	int size = 0, ch = 0;
	printf("\n Welcome in DSA World..!!");
	printf("\n Enter size of the Array : ");
	scanf("%d",&size);
	int arr[size];
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
			PUSH(arr,size);
			break;
		case 2:
			POP(arr);
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
