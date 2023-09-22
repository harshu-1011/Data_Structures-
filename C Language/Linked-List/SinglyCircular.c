#include<stdio.h>
#include<stdlib.h>
struct Node    
{
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
    PNODE temp=*Head;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->Data = no;
    newn->Next = NULL;
    
    if(*Head == NULL)
    {
        *Head = newn;
        newn->Next = newn;
        printf("\nFirst Node Inserted Successfully With value : %d",newn->Data);
    }
    else
    {
        while(temp->Next != NULL)
        {
            temp=temp->Next;
        }
        newn->Next = *Head;
        *Head = newn;
        temp->Next = newn;
        printf("\nFirst Node Inserted Successfully With value : %d ",newn->Data);
    }
    Choice();
}


void InsertLast(PPNODE Head,int no)
{
    printf("\nLast Node Inserted Successfully With value :  ");
    PNODE temp = *Head;
    PNODE newn = NULL;
    newn  = (PNODE)malloc(sizeof(NODE));
    newn->Data = no;
    newn->Next = NULL;
    
    if(*Head==NULL)
    {
        *Head = newn;
        newn->Next = newn;
        printf("\nLast Node Inserted Successfully With value : %d ",newn->Data);
    }
    else
    {
         
        while(temp!=NULL)
        {
            temp = temp->Next;
        }
         temp->Next = newn;
         newn->Next=*Head;
         printf("\nLast Node Inserted Successfully With value : %d ",newn->Data);
    }
    Choice();
}


void InsertAtPos(PPNODE Head,int no)
{
    int pos =0,iCount=1,Result=0;
    int ch;
    Display(*Head);
    Result = Count(*Head);
    if(*Head==NULL)
    {
      printf("\nLinkesd List Is Empty No Position There");
      printf("\n Do You Wish to add it at First Position(Press 1/0)?? : ");
      scanf("%d",&ch);
      if(ch==1)
      {
          PNODE newn = NULL;
          newn = (PNODE)malloc(sizeof(NODE));
          newn->Data = no;
          newn->Next = NULL;
    
          *Head = newn;
           printf("\nNode Inserted Successfully At Position 1 With value : %d ",newn->Data);
           Choice();
      }
      else if(ch==0)
      {
          Choice();
      }
      else
      {
          printf("\n *** Invalid Choice !! ***");
          Choice();
      }
    }
   else
   {
        printf("\nEnter Position  1 To %d For Insert NODE : ",(Result+1));
        scanf("%d",&pos);
        
        if((pos<=(Result+1))&&(pos>0))
        {
           
            PNODE newn = NULL;
            PNODE prev = NULL;
            PNODE temp = *Head;
            newn = (PNODE)malloc(sizeof(NODE));
            newn->Data = no;
            newn->Next = NULL;
            
            if(pos==(Result+1))
            {
                while(temp->Next!=NULL)
                {
                    temp = temp->Next;
                }
                temp->Next = newn;
                printf("\nNode Inserted Successfully At Position %d With value : %d ",pos,newn->Data);
            }
            else if(pos==1)
            {
                newn->Next = *Head;
                *Head = newn;
                printf("\nNode Inserted Successfully At Position %d With value : %d ",pos,newn->Data);
            }
            else
            {
              while(pos!=iCount)
              {
                  prev = temp;
                  temp = temp->Next;
                  iCount++;
              }
              newn->Next = temp;
              prev->Next = newn;
              printf("\nNode Inserted Successfully At Position %d With value : %d ",pos,newn->Data);
            }
        }
        else
        {
            printf("\nInvalid Position!!!");
            InsertAtPos(&*Head,no);
        }
   }
}


void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;
    if(*Head==NULL)
    {
        printf("\nLinked List Is Empty Nothing To Delete");
    }
    else
    {
       PNODE prev=*Head;
        temp=temp->Next;
        *Head=temp;
        while(temp->Next!=NULL)
        {
         temp=temp->Next;   
        }
        temp->Next=*Head;
        
        printf("\nFirst Node Deleted Succesfullly With Value : %d",prev->Data);
        free(prev);
    }
    Choice();
}


void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;
    PNODE prev = NULL;
    if(*Head==NULL)
    {
        printf("\nSingly linked list Is Empty!!! Nothing To Delete.");
    }
    else
    {
         while(temp->Next!=NULL)
         {
             prev = temp;
             temp = temp->Next;
         }
         prev->Next = NULL;
         printf("\nLast Node Deleted Succesfullly With Value : %d",temp->Data);
         free(temp);
    }
    Choice();
}


void DeleteAtPos(PPNODE Head)
{
    int iResult = 0;
    iResult = Count(*Head);
    int count =1,pos = 0;
    PNODE temp = *Head;
    PNODE prev = NULL;
    
    Display(*Head);
    printf("\nEnter Position 1 To %d For Delete Node Data : ",iResult);
    scanf("%d",&pos);
    
    if(*Head==NULL)
    {
        printf("\nLinked list Is Empty!!! Nothing To Delete");
    }
    
    if((pos<=iResult)&&(pos>0))
    {
        if(pos==1)
        {
            PNODE temp = *Head;
            *Head = temp->Next;
             printf("\n%d Position Node Deleted Successfully With Data %d",pos,temp->Data);
            free(temp);
        }
        else
        {
            while(pos!=count)
            {
                prev = temp;
                temp = temp->Next;
                count++;
            }
            prev->Next = temp->Next;
            printf("\n%d Position Node Deleted Successfully With Data %d",pos,temp->Data);
            free(temp);
        }
    }
    else
    {
        printf("\nInvalid Position!!!");
        DeleteAtPos(&*Head);
    }
    Choice();
}


void Display(PNODE Head)
{
    PNODE temp = Head;
    if(Head==NULL)
    {
        printf("\nLinked List Empty!! Nothing To Display");
    }
    else
    {
       
        printf("\nSingly Linked List Is : ");
        
        while(temp!=NULL)
        {
            printf("%d\t",temp->Data);
            temp = temp->Next;
        }
    }
    printf("\n");
}


int Count(PNODE Head)
{
    PNODE temp = Head;
    int iCount = 1;
    if(Head==NULL)
    {
        printf("\nSingly Linked List Is Empty.Zero Node Are Present");
    }
    else
    {
        while(temp->Next!=NULL)
        {
            iCount++;
            temp = temp->Next;
        }
        
    }
    return iCount;
}


void Search(PNODE Head)
{
       int Data = 0,iCount = 1,cnt=0, flag=1;  
       PNODE temp = Head;
    
      if(temp == NULL)  
      {  
        printf("\nSingly Linked List Is Empty So Nothing To Search");  
      }  
      else
      {
          printf("\nEnter Node Data Which You Want To Search : ");   
          scanf("%d",&Data);
            while (temp != NULL)  
            {
               if(temp->Data == Data)  
                {  cnt++;
                    printf("\n%d Present At Position %d",Data,iCount);
                    flag=0;  
                }   
                iCount++;  
                temp = temp -> Next;  
            }
            
            if(flag==1)  
            {  
             printf("\nItem not found !!!");  
            }  
            printf("\n%d Is Present %d Times!!",Data,cnt);
      }
      Choice();
    
}


PNODE First = NULL;
void Choice()
{
    int ch = 0,cnt = 0,No = 0,No1 = 0,No2 = 0 ;
    printf("\n------Singly Linked List Menu------");
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
            break;
        
        case 2 :
            printf("\nEnter Data : ");
            scanf("%d",&No1);
            InsertLast(&First,No1);
            break;
        
        case 3 :
            printf("\nEnter Data  : ");
            scanf("%d",&No2);
            InsertAtPos(&First,No2);
            Choice();
            break;
        
        case 4 :
            DeleteFirst(&First);
            break;
        
        case 5 :
            DeleteLast(&First);
            break;
        
        case 6 :
            DeleteAtPos(&First);
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
