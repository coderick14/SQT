#include <iostream>
#define endl '\n'
using namespace std;
struct node
{
  int data;
  struct node* next;
};
void insert(node** head,int data,int pos)
{
  struct node *p,*q;
  node* newNode=new node;
  int k=1;
  if(!newNode)
  {
    cout<<"Memory allocation error\n";
    return;
  }
  newNode->data=data;
  p=*head;
  if(pos==1)
  {
    newNode->next=*head;
    *head=newNode;
  }
  else
  {
    while((p!=NULL) && k<pos)
    {
      q=p;
      p=p->next;
      k++;
    }
    if(p==NULL)     //insert at end
    {
      q->next=newNode;
      newNode->next=NULL;
    }
    else
    {
      q->next=newNode;
      newNode->next=p;
    }
  }
}
void del(node** head,int pos)
{
  struct node *p,*q;
  p=*head;
  int k=1;
  if(p==NULL)
  {
    cout<<"List empty\n";
    return;
  }
  if(pos==1)
  {
    *head=(*head)->next;
    delete p;
  }
  else
  {
    while((p!=NULL)&& k<pos)
    {
      q=p;
      p=p->next;
      k++;
    }
    if(p==NULL)
    {
      cout<<"Position exceeds length of list\n";
      return;
    }
    else
    {
      q->next=p->next;
      delete p;
    }
  }
}
void traversal(node** head)
{
  node* temp=new node;
  temp=*head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
  delete temp;
}
void deleteList(node** head)
{
  struct node *p=new node;
  p=*head;
  if(p==NULL)
    return;
  while(p->next!=NULL)
  {
    node* temp=new node;
    temp=p->next;
    p->next=temp->next;
    delete temp;
  }
  delete p;
}
int main()
{
  int pos,val,ch;
  struct node* head=NULL;
  do
  {
    cout<<"1. Insertion\n2. Deletion\n3. Traversal\n4. Exit\n";
    cin>>ch;
    switch (ch)
    {
      case 1: cout<<"Enter value and position\n";
              cin>>val>>pos;
              insert(&head,val,pos);
              break;
      case 2: cout<<"Enter position\n";
              cin>>pos;
              del(&head,pos);
              break;
      case 3: traversal(&head);
              break;
      case 4: break;
    }
  }while(ch!=4);
  deleteList(&head);
  return 0;
}