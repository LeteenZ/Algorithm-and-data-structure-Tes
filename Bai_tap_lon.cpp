#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

typedef struct node
{
	int info;
	struct node *prev;
	struct node *next;
}NODE;
typedef NODE*  NodePtr;


/*
	Additional library
*/

void Init(NodePtr pHead);						//1.				 
int Check_Empty(NodePtr pHead);					//2.
void Show_Node(NodePtr p);						//3.
NodePtr Create_Node(int value);					//4.
void Add_Node(NodePtr pHead, int value);		//5.
void End_Again();								//6.
void Show_List(NodePtr pHead);					//7.
void Show_Reverse(NodePtr pHead);				//8.
void Swap(NodePtr p, NodePtr q);				//9.

/*
	Soft library
*/

void Selection(NodePtr pHead);					//1.
void Bubble(NodePtr pHead);						//2.
void Insertion(NodePtr pHead);					//3.
void Quick(NodePtr pHead);						//4.
void Heap(NodePtr pHead);						//5.
//2 cai cuoi chua xong


/*
	Origin library
*/

//1.Enter a list
void Enter_List(NodePtr pHead)
{
	int n, value;
	//tao so phan tu cua danh sach
	cout<<"Enter the number of list : ";
	cin>>n;
	cout<<endl;
	NODE* temp = pHead;		//dung lam prev cua node moi
	//nhap danh sach
	for(int i = 0; i < n ; i++)
	{
		cout<<"Enter value ["<<i<<"] : ";
		cin>>value;
		pHead->info = value;
		pHead->next = Create_Node({NULL});
		pHead = pHead->next;
		pHead->prev = temp;
		temp = pHead;
		cout<<endl;
	}  
}
 
//2. Show full list
void Show(NodePtr pHead)
{
	if(Check_Empty(pHead) == 0)
	{
		cout<<"List's empty";
		return;
	}
	cout<<"\nList : \n\n";
	//in danh sach
	Show_List(pHead);
	cout<<"\n";
	//in danh sach nguoc
	cout<<"\nReverse : \n\n";
	Show_Reverse(pHead);
	cout<<endl;
}


//3.Count the number of nodes of the list
int Count_Node(NodePtr pHead)
{
	//tao roi dem node
	int count=0;
	while(pHead->info != '\0')
	{
		count++;
		pHead = pHead->next;
	}
	return count;
}

//4.Add a new node with information 'x' at the end of the list
void Add(NodePtr pHead)
{
	int x;
	cout<<"\nEnter the 'x' : ";
	cin>>x;
	//chen vao cuoi
	Add_Node(pHead, x);
}

//5.Remove the node at the end of the list
void Remove(NodePtr pHead)
{
	//kiem tra ds co rong ko
	if(Check_Empty(pHead) == 0)
	{
		cout<<"List's empty";
		return;
	}
	NodePtr temp;
	while(pHead->info != '\0')
	{
		pHead = pHead->next;
		temp = pHead->prev;
	}
	pHead = temp;
	pHead->info = '\0';
	cout<<"\nRemove complete.....\n";
}

//6.Sort the list in descending order of the info
void Soft(NodePtr pHead)
{
	//kiem tra ds co rong ko
	if(Check_Empty(pHead) == 0)
	{
		cout<<"List's empty";
		return;
	}
	//menu de chon cach thuc sap  xep
	int n;
	cout<<"\n\t\t\tAlgorithm:";
	cout<<"\n\t\t\t1.Selection soft";
	cout<<"\n\t\t\t2.Bubble soft";
	cout<<"\n\t\t\t3.Insertion soft";
	cout<<"\n\t\t\t4.Quick soft <update next time>";
	cout<<"\n\t\t\t5.Heap soft <update next time>";
	cout<<"\n\n\t\t\tChoose option : ";
	da:
	cin>>n;
	switch(n)
	{
		case 1:
		{
			Selection(pHead);
			break;
		}
		case 2:
		{
			Bubble(pHead);
		}
		case 3:
		{
			Insertion(pHead);
			break;
		}	
		case 4:
		{
			/*
			Quick(pHead);
			break;
			*/
		}	
		case 5:
		{
			/*
			Heap(pHead);
			break;
			*/
		}	
		default:
		{
			cout<<"Choose again......";
			goto da;
		}
	}	
}

//7.The End
void End()
{
	//mang hinh thuc giai tri nhe :3
	int n;
	cout<<"\n\t\t\t1.Yes";
	cout<<"\n\t\t\t2.NO";
	kono:
	cout<<"\n\t\t\tChoose 1/2: ";
	cin>>n;
	switch(n)
	{
		case 1:
		{
			End_Again();
			break;
		}
		case 2:
		{
			return;
		}
		default:
		{
			cout<<"Choose again......";
			goto kono;
		}
	}
}

/*
		MENU
*/

void menu()
{
	NodePtr pHead = new NODE;
	int x;
	Init(pHead);
	menu:
	cout<<"\n\t\t\t __________________________________________________________________";
	cout<<"\n\t\t\t/_________________________________________________________________/|";
	cout<<"\n\t\t\t|                            -MENU-                               ||";
	cout<<"\n\t\t\t|-----------------------------------------------------------------||";
	cout<<"\n\t\t\t|                                                                 ||";
	cout<<"\n\t\t\t|1.Enter a list                                                   ||";
	cout<<"\n\t\t\t|                                                                 ||";
	cout<<"\n\t\t\t|2.Show full list                                                 ||";
	cout<<"\n\t\t\t|                                                                 ||";
	cout<<"\n\t\t\t|3.Count the number of nodes of the list                          ||";
	cout<<"\n\t\t\t|                                                                 ||";
	cout<<"\n\t\t\t|4.Add a new node with information 'x' at the end of the list     ||";
	cout<<"\n\t\t\t|                                                                 ||";
	cout<<"\n\t\t\t|5.Remove the node at the end of the list                         ||";
	cout<<"\n\t\t\t|                                                                 ||";
	cout<<"\n\t\t\t|6.Sort the list in descending order of the info                  ||";
	cout<<"\n\t\t\t|                                                                 ||";
	cout<<"\n\t\t\t|7.The End                                                        ||";
	cout<<"\n\t\t\t|_________________________________________________________________|/";
	dio:
	cout<<"\n\t\t\t< Type '0'-zero if u want to see menu again >";
	cout<<"\n\n\t\t\tChoose your function: ";
	cin>>x;
	switch(x)
	{
		case 0:
			goto menu;
		case 1:
		{
			Enter_List(pHead);
			goto dio;
		}
		case 2:
		{
			Show(pHead);
			goto dio;
		}	
		case 3:
		{
			cout<<"\nThe number of nodes of the list is: "<<Count_Node(pHead)<<endl;
			goto dio;
		}	
		case 4:
		{
			Add(pHead);
			goto dio;
		}	
		case 5:
		{
			Remove(pHead);
			goto dio;
		}	
		case 6:
		{
			Soft(pHead);
			goto dio;
		}
		case 7:
		{
			cout<<"\n\t\t\tAre u sure u want to end this ?";
			End();
			goto dio;
		}
		default:
		{
			cout<<"Choose again......";
			goto dio;	
		}
	}
	
}

//day la ham  main chinh- dung hoi tai sao co them tu chinh vi tui thay quen mieng

int main()
{
	menu();
	return 0;
}

//day la ham  main chinh- dung hoi tai sao co them tu chinh vi tui thay quen mieng

/*
	Additional item
*/

//1.
void Init(NodePtr pHead)
{
	//bien pHead thanh null
	pHead->prev = Create_Node({NULL});
	pHead->info = '\0';
}	

//2.
int Check_Empty(NodePtr pHead)
{
	//kiem tra xem danh sach co rong ko
	if(pHead->info == '\0')
		return 0;
	else
		return 1;
}

//3.		
void Show_Node(NodePtr p)
{
	//in ra truong info
	cout<<p->info<<"\t";
}

//4.				
NodePtr Create_Node(int value)
{
	//tao node moi va bien thanh null
	NodePtr New_Node = new NODE;
	New_Node->info = value;
	New_Node->next = NULL;
	New_Node->prev = NULL;
	return New_Node;
}

//5. 
void  Add_Node(NodePtr pHead, int value)
{
	NODE* temp = pHead;
	if(pHead->info == '\0')
	{
		pHead->info = value;
		pHead->next = Create_Node({NULL});
		pHead = pHead->next;
		pHead->prev = temp;
		return;
	}
	NodePtr new_node = Create_Node(value);
	while(pHead->info != '\0')
 	{                                    
	 	pHead = pHead->next;
 		temp = pHead->prev;
	}
	pHead = temp;
 	new_node->prev = pHead;
 	new_node->next = Create_Node({NULL});
 	temp = new_node;
	new_node = new_node->next;
 	new_node->prev = temp;
 	new_node = temp;
 	pHead->next = new_node;
 	cout<<"\nAdd complete....";
	return;
}

//6.
void End_Again()
{
	//mot chua giai tri
	int n;
	cout<<"\n\t\t\tDo u want to see some stuff ?";
	cout<<"\n\t\t\t1.Yes";
	cout<<"\n\t\t\t2.No";
	lol:
	cout<<"\n\t\t\tChoose 1/2:";
	cin>>n;
	switch(n)
	{
		case 1:
		{
			system("cls");
			string stuff = "D://some_stuff.txt";
			string lines;
			ifstream f(stuff);
			if(!f)
			{
        		cout << "Error: file can't open." << endl;
        		return;
    		}
    		while(!f.eof())
			{
				getline(f,lines);
				cout<<lines<<endl;
			}
			f.close();
			exit(1);
		}
		case 2:
		{
			exit(1);
			break;
		}
		default:
		{
			cout<<"Choose again.....";
			goto lol;
		}
	}
}

//7.
void Show_List(NodePtr pHead)
{
	//in danh sach
	while(pHead->info != '\0')
	{
		Show_Node(pHead);
		pHead = pHead->next;
	}
}

//8.
void Show_Reverse(NodePtr pHead)
{
	//in danh sach nguoc
	while(pHead->info != '\0')
	{
		pHead = pHead->next;
	}
	pHead = pHead->prev;
	while(pHead->info != '\0')
	{
		Show_Node(pHead);
		pHead = pHead->prev;
	}
}

//9.
void Swap(NodePtr p, NodePtr q)
{
	//doi cho 2 truong info 
	int tg;
	tg = p->info;
	p->info = q->info;
	q->info = tg;
}
/*
		Soft item
*/

//ap dung cong thuc la ra : la khong dung voi may giai thuat nay ="))))

//1.
void Selection(NodePtr pHead)
{
	int max = -99999999;
	int n = Count_Node(pHead), tg = 0;
	NODE* temp = pHead;
	NODE* head = pHead;
	for(int i = 0; i < n ; i++ )
	{
		while(pHead->info != '\0')
		{
			if(max < pHead->info )
			{
				max = pHead->info;
				temp = pHead;
			}
			pHead = pHead->next;
		}
		pHead = head;
		tg = pHead->info;
		pHead->info = max;
		pHead = temp;
		pHead->info = tg;
		pHead = head;
		pHead = pHead->next;
		head = pHead;
		max = -99999999;
	}
	cout<<"\nSoft complete......";
}

//2.
void Bubble(NodePtr pHead)
{
	int n = Count_Node(pHead);
	NODE* Tail = pHead;
	NODE* Head = pHead;
	NODE* num1;
	NODE* num2;
	while(pHead->info != '\0')
	{
		pHead = pHead->next;
	}
	pHead = pHead->prev;
	Tail = pHead;
	pHead = Head;
	for(int i = 0; i < n ; i++)
	{
		num1 = Tail;
		num2 = Tail->prev;
		while(num1 != pHead)
		{
			if(num1->info > num2->info)
			{
				Swap(num1, num2);
			}
			num1 = num1->prev;
			num2 = num1->prev;
		}
		pHead = pHead->next;
	}
}

//3.
void Insertion(NodePtr pHead)
{
	int n = Count_Node(pHead);
	NODE* temp = pHead;
	NODE* num1 = pHead->next;
	NODE* num2 = num1;
	for(int i=1; i < n; i++)
	{  
		while(temp->info != '\0')
		{
			if(num1->info > temp->info) 
			{
				Swap(num1,temp);
				num1 = temp;
			}
			temp = temp->prev;
		}
		num1 = num2;
		num1 = num1->next;
		num2 = num1;
		temp = num1->prev;
	}
}

//4.
void Quick(NodePtr pHead)
{
	//ko du thoi gian lam do phai di dem nhac chao tan sv :))
}

//5.
void Heap(NodePtr pHead)
{
	//ko du thoi gian lam do phai di dem nhac chao tan sv :))
}