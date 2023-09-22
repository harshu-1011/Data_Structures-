#include<stdio.h>
#include<stdlib.h>


struct node
{
    struct node* Prev;
    int Data;
    struct node* Next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

//Function Prototype Declaration Ex. of Some Functions
void Display();
int Count();
void Choice();

void InsertFirst(PPNODE Head,int no)
{
    PNODE temp = *Head;
    
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->Prev = NULL;
    newn->Data = no;
    newn->Next = NULL;
    
    if(*Head==NULL)
    {
       printf("\nFirst Node Inserted Successfully With Value %d ",newn->Data);
       *Head = newn;
       newn->Prev = newn;
       newn->Next = newn;
    }
    else
    {
        while(temp->Next != *Head)
        {
            temp = temp->Next;
        }
        newn->Next = *Head;
        newn->Prev = temp;
        temp->Next = newn;
        *Head = newn;
        printf("\nFirst Node Inserted Successfully With Value %d ",newn->Data);
    }
}
void InsertLast(PPNODE head,int no)
{
    PNODE temp=*head,first=*head;
    
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->Prev=NULL;
    newn->Data=no;
    newn->Next=NULL;
    
    if(*head==NULL)
    {
        *head=newn;
        newn->Prev=newn;
        newn->Next=newn;
        printf("\nLast Node inserted Sucessfully with value :%d",newn->Data);
    }
    else
    {
         while(temp->Next!=*head)
         {
             temp=temp->Next;
         }
         temp->Next=newn;
         newn->Prev=temp;
         newn->Next=*head;
         first->Prev = temp;
         printf("\nLast Node inserted Sucessfully with value :%d",newn->Data);
    }
}
void InsertAtPos(PPNODE Head,int no)
{
    int pos = 0 ,iCount = 1;
    int iCnt=0,ch=0;
    iCnt = Count(*Head);
    Display(*Head);
    PNODE prev = NULL;
    PNODE temp = *Head;
   
   
    if(*Head==NULL)
    {
    	printf("\nDoubly Circular Linked List Is Empty!!!\nDo You Wish To Add It At First Position(press 1 or 0): ");
    	scanf("%d",&ch);
    	if(ch==1)
    	{
    		
    		PNODE newn = NULL;
		    newn = (PNODE)malloc(sizeof(NODE));
		    newn->Prev  = NULL;
		    newn->Data = no;
		    newn->Next = NULL;
	    
	        *Head = newn;
	        newn->Prev = newn;
	        newn->Next = newn;
	        printf("\nNode Inserted Successfully At Pos First  With Value %d",newn->Data);
	        Choice();
    	}
	    else if(ch==0)
	    {
	    	Choice();
		}
		else
		{
			printf("\n *** Invalid Choice...!! ***");
			Choice();
		}
    }
    
     printf("\nEnter Position 1-to-%d For Insert Data : ",(iCnt+1));
     scanf("%d",&pos);
     
     if((pos>0)&&(pos<=(iCnt+1)))
     {
        PNODE first = *Head;
	    PNODE newn = NULL;
	    newn = (PNODE)malloc(sizeof(NODE));
	    newn->Prev  = NULL;
	    newn->Data = no;
	    newn->Next = NULL;
	    
	    if(pos==1)
        {
            temp = *Head;
            while(temp->Next != *Head)
            {
                temp=temp->Next;
            }
            first->Prev = newn;
	        newn->Prev = temp;
	        newn->Next = first;
	        temp->Next = newn;
	        *Head = newn;
	        printf("\nNode Inserted Successfully At Pos First With Value %d",newn->Data);
        }
        else if(pos==(iCnt+1))
        {
            while(temp->Next!= *Head)
            {
                temp = temp->Next;
            }
            temp->Next = newn;
            newn->Prev = temp;
            newn->Next = first;
            first->Prev = newn;
            printf("\nNode Inserted Successfully At Pos %d  With Value %d",newn->Data,(iCnt+1));
        }
        else
        {
            while(iCount!=pos)
            {
                prev = temp;
                temp = temp->Next;
                iCount++;
            }
            prev->Next = newn;
            newn->Prev = prev;
            newn->Next = temp;
            temp->Prev = newn;
            printf("\nNode Inserted Successfully At Pos %d  With Value %d",pos,newn->Data);
        }
     }
    else
    {
        printf("\nInvalid Position!!!");
        InsertAtPos(&*Head,no);
	}
}
void DeleteFirst(PPNODE Head)
{
    PNODE first = *Head;
    PNODE temp = *Head;
     if(*Head==NULL)
     {
         printf("\nDoubly Circular Linked List is Empty Nothing to Delete!!!!");
     }
     else
     {
         while(temp->Next != *Head)
         {
             temp=temp->Next;
         }
         *Head=first->Next;
         first->Next->Prev=temp;
         temp->Next = *Head;
         printf("\nFirst node is Deleted Successfully with values :%d",first->Data);
         free(first);
     }
}
void DeleteLast(PPNODE head)
{
    PNODE prev = NULL;
    PNODE temp=*head;
    PNODE first = *head;
    
    if(*head==NULL)
    {
        printf("\nDoubly Circular Linked List is Empty Nothing to Delete!!!!");
    }
    else
    {
        while(temp->Next!= *head)
        {
            prev = temp;
            temp=temp->Next;
        }
        prev->Next=*head;
        first->Prev = temp;
        printf("\nLast node is Deleted Successfully with values :%d",temp->Data);
        free(temp);
    }
}
void DeleteAtPos(PPNODE head)
{
    int pos = 0 ,iCount = 1;
    PNODE temp = *head;
    PNODE first = *head;
    PNODE prev = NULL;
    
    if(*head==NULL)
    {
        printf("\n LL IS EMPTY...Nothing to delete...!!");
        Choice();
    }
        int iCnt=0;
        iCnt = Count(*head);
        Display(*head);
        printf("\nEnter Position 1-to-%d For Delete Data : ",iCnt);
        scanf("%d",&pos);
        
    if((pos>0)&&(pos<=iCnt))
    {
                if(pos == iCnt)
               {
                 while(temp->Next!=*head)
                 {
                    prev = temp;
                    temp = temp->Next;
                 }
                   prev->Next = *head;
                   first->Prev = prev;
                   printf("\nLast node is Deleted Successfully with values :%d",temp->Data);
                   free(temp);
               }
                else if(pos==1)
                {
                    while(temp->Next != *head)
                    {
                        temp=temp->Next;
                    }
                    *head=first->Next;
                     first->Next->Prev=temp;
                     temp->Next = *head;
                     printf("\nFirst node is Deleted Successfully with values :%d",first->Data);
                     free(first);
                }
                else
                {
                    while(iCount!=pos)
                    {
                        iCount++;
                        prev = temp;
                        temp=temp->Next;
                    }
                    prev->Next = temp->Next;
                    temp->Next->Prev = prev;
                    printf("\n Deleted Node Successfully with value : %d",temp->Data);
                    free(temp);
                }
    }
    else
    {
        printf("\nInvalid Position!!!");
        Choice();
    }
}
void Display(PNODE Head)
{
    PNODE temp = Head;
  if(Head==NULL)
  {
  printf("\n Doubly Circular Linked List Is Empty!!! Nothing To Display!!");
  }
  else
  {
      printf("\n Doubly Circular Linked List Is : ");
      while(temp->Next != Head)
      {
          printf("%d\t",temp->Data);
          temp = temp->Next;
      }
      printf("%d\t",temp->Data);
  }
}
int Count(PNODE Head)
{
    PNODE temp = Head;
  int iCnt = 0;
  if(Head==NULL)
  {
     printf("\n Doubly Circular Linked List Is Empty Zero Node Is Present");
  }
  else
  {
      iCnt = 1;
      while(temp->Next!=Head)
      {
          temp = temp->Next;
          iCnt++;
      }
  }
  return iCnt;
}
void Search(PNODE head)
{
    int cnt=0;
    if(head==NULL)
    {
        printf("\n LL is Empty !! Nothing to Search...!!");
        Choice();
    }
    else
    {
        PNODE temp = head;
        int data=0,flag=0,iCnt=0;
        printf("\n Enter Data to Search : ");
        scanf("%d",&data);
        
        while(temp->Next != head)
        {
            iCnt++;
            if(temp->Data == data)
            {
                cnt++;
                flag = 1;
                printf("\n*** %d is Found At Pos %d ***",data,iCnt);
            }
            temp=temp->Next;
        }
        if(temp->Data == data)
            {
                cnt++;
                flag = 1;
                printf("\n*** %d is Found At Pos %d ***",data,iCnt);
            }
        if(flag==1)
        {
            printf("\n %d is Found with Occurence Count : %d",data,cnt);
        }
        else
        {
            printf("\n Element Not Found...!!");
        }
        printf("\n Total Count of Nodes : %d",cnt);
    }
    Choice();
}

PNODE First = NULL;

void Choice()
{
    printf("\n------------ Doubly Circular Linked List ------------");
    int ch = 0,cnt = 0,data = 0,data1 = 0,data2 = 0 ;
    printf("\n1.InsertFirst");
    printf("\n2.InsertLast");
    printf("\n3.InsertAtPos");
    printf("\n4.DeleteFirst");
    printf("\n5.DeleteLast");
    printf("\n6.DeleteAtPos");
    printf("\n7.Display");
    printf("\n8.Count");
    printf("\n9.Search");
    printf("\n10.Exit");
    printf("\n-----------------------------------------------------");
    printf("\nEnter Choice : ");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 1:
        printf("\nEnter Element : ");
        scanf("%d",&data);
        InsertFirst(&First,data);
        Choice();
        break;
        
        case 2:
        printf("\nEnter Element : ");
        scanf("%d",&data);
        InsertLast(&First,data);
        Choice();
        break;
        
        case 3:
        printf("\nEnter Element : ");
        scanf("%d",&data);
        InsertAtPos(&First,data);
        Choice();
        break;
        
        case 4:
        DeleteFirst(&First);
        Choice();
        break;
        
        case 5:
        DeleteLast(&First);
        Choice();
        break;
        
        case 6:
        DeleteAtPos(&First);
        Choice();
        break;
        
        case 7:
        Display(First);
        Choice();
        break;
        
        case 8:
            cnt = Count(First);
            printf("\n Count of Total Number of Nodes : %d",cnt);
            Choice();
            break;
        
        case 9:
        Search(First);
        break;
        
        case 10:
        printf("\n --- Thank You..!! ---");
        exit(1);
        break;
        
        default:
        printf("\nInvalid Choice!!!");
        printf("\nEnter Valid Choice!!!");
        Choice();
    }
}

int main()
{
    Choice();
    return 0;
}
