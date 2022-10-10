#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data=val;
            next=NULL;
        }
};
boolean search(node* &head,int key)
{
    node* temp=head;
    while(temp->data!=key)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    return false;
    else 
    return true;
}
void insertAt_Head(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;
}

//insert element at the end of linked list
void tail(node* &head, int val){
    
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;


}

//deletion function
void deletion(node* &head, int val)
{
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
}


//display all element present in the linked list
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;

    }
    cout<<"NULL";
    cout<<endl;
}
int main(){
    node* head=NULL;
    tail(head,1);
    tail(head,2);
    tail(head,3);
    display(head);
    deletion(head,3);
    insertAt_Head(head,0);
    insertAt_Head(head,-1);
    insertAt_Head(head,-2);
    search(head ,0);
    display(head);

    return 0;
}