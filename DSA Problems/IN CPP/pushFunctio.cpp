#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;

        node(int val)
        {
            data=val;
            next=NULL;
        }

};
void pushFront(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;
}
void pushEnd(node* &head ,int val)
{
    node* n= new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;

}
void pushAt(node* &head,int key)
{
    node* n=new node(key);
    node* temp=head;
    while(temp->next->data!=key)
    {temp=temp->next;}
    temp->next=n;
}
void display(node* head)
{
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    node* head=NULL;
    pushFront(head,1);
    pushFront(head,2);
    pushFront(head,3);
    pushFront(head,4);
    pushFront(head,5);
    pushFront(head,6);
    pushAt(head,4);
    pushEnd(head,0);
    display(head);
    return 0;



}