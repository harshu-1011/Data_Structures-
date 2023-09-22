#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node* Prev;
    int Data; 
    struct Node* Next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

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
       newn->Prev = NULL;
       newn->Next = NULL;
    }
    else
    {
        newn->Next = temp;
        newn->Prev = NULL;
        temp->Prev = newn;
        *Head = newn;
        printf("\nFirst Node Inserted Successfully With Value %d ",newn->Data);
    }
}

void InsertLast(PPNODE head,int no)
{
    PNODE temp=*head;
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->Prev=NULL;
    newn->Data=no;
    newn->Next=NULL;
    
    if(*head==NULL)
    {
        *head=newn;
        newn->Prev=NULL;
        newn->Next=NULL;
        printf("\nLast Node inserted Sucessfully with value :%d",newn->Data);
    }
    else
    {
         while(temp->Next!=NULL)
         {
             temp=temp->Next;
         }
         temp->Next=newn;
         newn->Prev=temp;
         newn->Next=NULL;
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
    	printf("\nDoubly Linked List Is Empty!!!\nDo You Wish To Add It At First Position(press 1 or 0): ");
    	scanf("%d",&ch);
    	if(ch==1)
    	{
    		
    		PNODE newn = NULL;
		    newn = (PNODE)malloc(sizeof(NODE));
		    newn->Prev  = NULL;
		    newn->Data = no;
		    newn->Next = NULL;
	    
	        *Head = newn;
	        newn->Prev = NULL;
	        newn->Next = NULL;
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
	    PNODE newn = NULL;
	    newn = (PNODE)malloc(sizeof(NODE));
	    newn->Prev  = NULL;
	    newn->Data = no;
	    newn->Next = NULL;
	    
	    if(pos==1)
        {
            temp = *Head;
	        newn->Prev = NULL;
	        newn->Next = temp;
	        *Head = newn;
	        printf("\nNode Inserted Successfully At Pos First  With Value %d",newn->Data);
        }
        else if(pos==(iCnt+1))
        {
            while(temp->Next!= NULL)
            {
                temp = temp->Next;
            }
            temp->Next = newn;
            newn->Prev = temp;
            newn->Next = NULL;
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
 PNODE temp = *Head;
 if(*Head==NULL)
 {
     printf("\nDoubly Linked List is Empty Nothing to Delete!!!!");
 }
 else
 {
     *Head=temp->Next;
     temp->Next->Prev=NULL;
     printf("\nFirst node is Deleted Successfully with values :%d",temp->Data);
     free(temp);
 }
}

void DeleteLast(PPNODE head)
{
    PNODE prev = NULL;
    PNODE temp=*head;
    if(*head==NULL)
    {
        printf("\nDoubly Linked List is Empty Nothing to Delete!!!!");
    }
    else
    {
        while(temp->Next!=NULL)
        {
            prev = temp;
            temp=temp->Next;
        }
        prev->Next=NULL;
        printf("\nLast node is Deleted Successfully with values :%d",temp->Data);
        free(temp);
    }
}

void DeleteAtPos(PPNODE head)
{
    int pos = 0 ,iCount = 1;
    PNODE temp = *head;
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
                 while(temp->Next!=NULL)
                 {
                    prev = temp;
                    temp = temp->Next;
                 }
                   prev->Next = NULL;
                   printf("\nLast node is Deleted Successfully with values :%d",temp->Data);
                   free(temp);
               }
                else if(pos==1)
                {
                    *head=temp->Next;
                     temp->Next->Prev=NULL;
                     printf("\nFirst node is Deleted Successfully with values :%d",temp->Data);
                     free(temp);
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
        printf("\nDoubly Linked List Is Empty So Nothing To Display!!!");
    }
    else
    {
         printf("\nDoubly Linked Is : ");
         while(temp!=NULL)
         {
             printf("%d\t",temp->Data);
             temp = temp->Next;
         }
    }
}

int Count(PNODE Head)
{
    int cnt=1;
    PNODE temp=Head;
    if(Head==NULL)
    {
        printf("\n LL is Empty...Nothing to Count...!!");
    }
    else
    {
        while(temp->Next != NULL)
        {
            cnt++;
            temp=temp->Next;
        }
    }
    return cnt;
}


void Search(PNODE Head)
{
    PNODE temp=Head;
    if(Head==NULL)
    {
        printf("\n Nothing to Search...LL is Empty...!!");
    }
    else
    {
        int data=0,flag=1,cnt=0,iCnt=0;
        printf("\n Enter Data to Search : ");
        scanf("%d",&data);
        while(temp != NULL)
        {
            iCnt++;
            if(temp->Data==data)
            {
                cnt++;
                flag=0;
                printf("\n %d is Found At %d",data,iCnt);
            }
            temp=temp->Next;
        }
        if(flag==1)
        {
            printf("\n Element Not Found..!!");
        }
        printf("\n %d is Present %d Times...!!",data,cnt);
    }
}


PNODE First = NULL;
void Choice()
{
    int ch = 0,cnt = 0,No = 0,No1 = 0,No2 = 0 ;
    printf("\n------Doubly Linked List Menu------");
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
    printf("\nEnter Choice : ");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 1 :            
            printf("Enter Data : ");
            scanf("%d",&No);
            InsertFirst(&First,No);
            Choice();
            break;
        
        case 2 :
            printf("\nEnter Data : ");
            scanf("%d",&No1);
            InsertLast(&First,No1);
            Choice();
            break;
        
        case 3 :
            printf("\nEnter Data  : ");
            scanf("%d",&No2);
            InsertAtPos(&First,No2);
            Choice();
            break;
        
        case 4 :
            DeleteFirst(&First);
            Choice();
            break;
        
        case 5 :
            DeleteLast(&First);
            Choice();
            break;
        
        case 6 :
            DeleteAtPos(&First);
            Choice();
            break;
        
        case 7 :
            Display(First);
            Choice();
            break;
        
        case 8 :
            
            cnt = Count(First);
            printf("\n Count of Total Number of Nodes : %d",cnt);
            Choice();
            break;
        
        case 9 :
            Search(First);
            Choice();
            break;
        
        case 10:
            printf("\n *** Thank You..!! ***\n");
            exit(1);
            break;
        
        default:
            printf("\n------Invalid Choice------");
            printf("\nEnter Valid Choice!!!");
            Choice();
    }
}

int main()
{
    Choice();
    return 0;
}
