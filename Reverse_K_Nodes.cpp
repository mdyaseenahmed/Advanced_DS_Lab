// Program to reverse every k nodes (where k is an input to the function) in the linked list. 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node 
{
	int data;
	struct node* next; 
};

typedef struct node *NODE;

NODE get_node()
{
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	return temp;
}

NODE create(NODE head,int data)
{
	NODE p = get_node();
	p->data = data;
	p->next = NULL;
	if(head == NULL)
	{
		head=p;
		return head;
	}	
	else
	{
		p->next = head;
		head = p;
		return head;
	}
}

void display(NODE head)
{
	while(head!=NULL)	
	{
		cout << head->data << "\t";
		head = head->next;
	}
}

int countNodes(NODE head)
{
	int count = 0;
	while(head!=NULL)
	{
		count+=1;
		head = head->next;
	}
	return count;
}

NODE reverse(NODE head,int k)
{
	NODE curr,nxtNode,prev;
	curr = head;
	prev = NULL;
	nxtNode = NULL;
	
	int count=0;
	int n = countNodes(head);
	if(k<=0)
	{
		return head;
	}
	if(k>=n)
	{
		while(curr!=NULL)
		{
			nxtNode = curr->next;
			curr->next = prev;
			prev=curr;
			curr=nxtNode;
		}
		return prev;
	}
	else
	{
		while(curr!=NULL && count<k)
		{
			nxtNode = curr->next;
			curr->next = prev;
			prev=curr;
			curr = nxtNode;
			count+=1;			
		}
		if(nxtNode!=NULL)
		{
			head->next=reverse(nxtNode,n-count);
		}
		return prev;
	}
}

int main()
{
	NODE head = NULL;
	int choice,item,k;

	while(1)
	{
		cout << "\n----------------------------\nThe Choices Are : " << endl;
		cout << "----------------------------";
		cout << "\n1. Create. \n2. Display. \n3. Reverse Every K Node. \n4. Exit\n--------------------------\n Enter Your Choice : ";
		cin >> choice;
		cout << "----------------------------\n";
		
		switch(choice)
		{
			case 1: cout << "Enter The Element to be Inserted : ";
					cin >> item;
					head = create(head, item);
					cout << "----------------------------\nInserted.!";
					break;
					
			case 2: if(head == NULL)		
					{
						cout << "List is Empty.!";
						break;
					}
					else
					{
						display(head);
						break;
					}
					
			case 3: if(head == NULL)
					{
						cout << "List is Empty.!";
						break;
					}
					else
					{
						cout << "Enter the Value of K : ";
						cin >> k;						
						cout << "----------------------------\n";
						head = reverse(head,k);					
						display(head);
						break;
					}
					
			case 4: exit(0);		
					
			default: cout << "Invalid choice.!"								;
		}
	}	
	
	return 0;
}
