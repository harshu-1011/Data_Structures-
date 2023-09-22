import java.util.Scanner;
public class DoublyCircularLL
{
	Scanner sc = new Scanner(System.in);
	public class node
	{
		public node prev;
		public int data;
		public node next;
		
		public node(int data)
		{
			this.prev = null;
			this.data = data;
			this.next = null;
		}
	}
	
	public node head = null;
	public node tail = null;
	
	public void InsertFirst()
	{
		int data = 0;
		System.out.println("\n Enter Data : ");
		data = sc.nextInt();
		
		node newn = new node(data);
		newn.prev = null;
		newn.data=0;
		newn.next=null;
		
		if(head==null)
		{
			newn.data = data;
			head = newn;
			tail = newn;
			newn.prev=newn;
			newn.next=newn;
			System.out.println("\n Linked List Was Empty Firstly...Now Added a Node with value :'"+data+"' at First Place..!!");
		}
		else
		{
			node first = head;
			newn.data = data;
			first.prev = newn;
			newn.next = head;
						
			node current = head;
			while(current.next != head)
			{
				current = current.next;
			}
			newn.prev = current;
			head=newn;
			System.out.println("\n "+data+" inserted at First Position...!!");
		}
	}
	
	public void InsertLast()
	{
		int data = 0;
		System.out.println("\n Enter Data : ");
		data = sc.nextInt();
		
		node newn = new node(data);
		newn.prev = null;
		newn.data=0;
		newn.next=null;
		
		if(head==null)
		{
			newn.data = data;
			head = newn;
			tail = newn;
			newn.prev=newn;
			newn.next=newn;
			System.out.println("\n Linked List Was Empty Firstly...Now Added a Node with value :'"+data+"' at First Place..!!");
		}
		else
		{
			newn.data = data;
			tail.next = newn;
			newn.prev = tail;
			newn.next=head;
			tail = newn;
			System.out.println("\n "+data+" inserted at Last...!!");
		}
	}	
	
	public void InsertAtPos(int posn)
	{
		int data = 0,pos = 0,cnt = 1;
		System.out.println("\n Enter Data : ");
		data = sc.nextInt();
		
		node newn = new node(data);
		newn.prev = null;
		newn.data=0;
		newn.next=null;
		
		if(head==null)
		{
			newn.data = data;
			head = newn;
			tail = newn;
			newn.prev=newn;
			newn.next=newn;
			System.out.println("\n Linked List Was Empty Firstly...Now Added a Node with value :'"+data+"' at First Place..!!");
		}
		else
		{
			System.out.println("\n Enter Position (1-"+(posn+1)+") : ");
			pos = sc.nextInt();
			if((pos<1)||(pos>posn))
			{
				System.out.println("\n Invalid Selection...!! ");
			}
			else if(pos == 1)
			{
				node first = head;
				newn.data = data;
				first.prev = newn;
				newn.next = head;
				head=newn;
				System.out.println("\n "+data+" Inserted at Position : 1");
			}
			else if(pos == (posn+1))
			{
				newn.data = data;
				tail.next = newn;
				newn.prev = tail;
				tail = newn;
				System.out.println("\n "+data+" Inserted at Position : "+(posn+1));
			}
			else
			{
				node prev = null;
				node current = head;
				while(cnt != pos)
				{
					cnt++;
					prev = current;
					current = current.next;
				}
				prev.next = newn;
				newn.prev = prev;
				newn.next = current;
				current.prev = newn;
				newn.data = data;
				System.out.println("\n "+data+" Inserted at Position : "+pos);
			}
		}
	}
	
	public void DeleteFirst()
	{
		if((head == null)&&(tail == null))
		{
			System.out.println("\n Linked List is Empty...Nothing to Delete...!!");
		}
		else
		{
			System.out.println("\n First Node was Deleted with value : "+head.data);
			node current = head;
			while(current.next != head)
			{
				current = current.next;
			}
			head = head.next;
			node first = head;
			first.prev = current;
			current.next = first;
		}
	}
	
	public void DeleteLast()
	{
		if((head == null)&&(tail == null))
		{
			System.out.println("\n Linked List is Empty...Nothing to Delete...!!");
		}
		else
		{
			node first = head;
			node current = head;
			node prev = null;
			while(current.next != null)
			{
				prev = current;
				current = current.next;
			}
			tail = prev;
			System.out.println("\n Last Node was Deleted with value : "+current.data);
			tail.next = head;
			first.prev = tail;
		}
	}
	
	public void DeleteAtPos(int posn)
	{
		int pos = 0,cnt = 1;
		if((head == null)&&(tail == null))
		{
			System.out.println("\n Linked List is Empty...Nothing to Delete...!!");
		}
		else
		{
			System.out.println("\n Enter Position (1-"+posn+") : ");
			pos = sc.nextInt();
			if((pos<1)||(pos>posn))
			{
				System.out.println("\n Invalid Selection...!! ");
			}
			else if(pos == 1)
			{
				System.out.println("\n First Node was Deleted with value : "+head.data);
				node current = head;
				while(current.next != head)
				{
					current = current.next;
				}
				head = head.next;
				node first = head;
				first.prev = current;
				current.next = first;
			}
			else if(pos == posn)
			{
				node first = head;
				node current = head;
				node prev = null;
				while(current.next != null)
				{
					prev = current;
					current = current.next;
				}
				tail = prev;
				System.out.println("\n Last Node was Deleted with value : "+current.data);
				tail.next = head;
				first.prev = tail;
			}
			else
			{
				node prev = null;
				node current = head;
				while(cnt != pos)
				{
					cnt++;
					prev = current;
					current = current.next;
				}
				prev.next = current.next;
				current.next.prev = prev;
				System.out.println("\n "+current.data+" Deleted having Position : "+pos);
			}
		}
	}
	
	public void Display()
	{
		if((head == null)&&(tail == null))
		{
			System.out.println("\n Linked List is Empty..!! Nothing to Display...!! \n");
		}
		else
		{
			System.out.print("\n Nodes in Linked List : ");
			node current = head;
			while(current.next != head)
			{
				System.out.print(current.data+"\t");
				current = current.next;
			}
		}
	}
	
	public void Search()
	{
		int val = 0,flag = 0,cnt = 0;
		node current = head;
		if((head == null)&&(tail == null))
		{
			System.out.println("\n Linked List is Empty...Nothing to Search...!!");
		}
		else
		{
			System.out.println("\n Enter Data to search : ");
			val = sc.nextInt();
			
			while(current.next != head)
			{
				cnt++;
				if(current.data == val)
				{
					flag = 1;
					System.out.println("\n Node with data '"+val+"' Found at Position : "+cnt);
				}
				current = current.next;
			}
			if(flag == 0)
			{
				System.out.println("\n Node not Found...!!");
			}	
		}
	}
	
	public int Count()
	{
		int cnt = 0;
		if((head == null)&&(tail == null))
		{
			return 0;
		}
		else
		{
			node current = head;
			while(current.next != head)
			{
				cnt++;
				current = current.next;
			}
			return cnt;
		}
	}
	
	public static void main(String[] args)
	{
		int ch = 0,count = 0;
		System.out.println("\n Hello World..!! \n Doubly Linked List in JAVA...!! \n");		
		Scanner sc = new Scanner(System.in);
		SinglyLinkedList sl = new SinglyLinkedList();
		do{
			System.out.println("\n---- My Menu ---- ");
			System.out.println("1.Insert At First ");
			System.out.println("2.Insert At Last ");
			System.out.println("3.Insert At Certain Position ");
			System.out.println("4.Delete At First ");
			System.out.println("5.Delete At Last ");
			System.out.println("6.Delete At Certain Position");
			System.out.println("7.Display Linked List");
			System.out.println("8.Search in Node");
			System.out.println("9.Count No. of Nodes");
			System.out.println("10.EXIT");
			System.out.println("-----------------");
			System.out.println("Enter Your Choice : ");
			ch = sc.nextInt();
			switch(ch)
			{
				case 1:
					sl.InsertFirst();
					break;
				case 2:
					sl.InsertLast();
					break;
				case 3:
					count = sl.Count();
					sl.InsertAtPos(count);
					break;
				case 4:
					sl.DeleteFirst();
					break;
				case 5:
					sl.DeleteLast();
					break;
				case 6:
					count = sl.Count();
					sl.DeleteAtPos(count);
					break;		
				case 7:
					sl.Display();
					break;
				case 8:
					sl.Search();
					break;
				case 9:
					count = sl.Count();
					System.out.println("\n No. of Nodes : "+count);
					break;
				case 10:
					System.exit(0);
				default:
					System.out.println("Plz...Enter Valid Choice And Try Again With valid Details...!!");
			}
		}while(ch!=10);
	}
}
