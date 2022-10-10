#include<iostream>
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
void front(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    n->next=head;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;

    }
    cout<<"NULL";
    cout<<endl;
}

int main(){
    node* head=NULL;
    front(head,3);
    front(head,2);
    front(head,1);
    display(head);

    return 0;
}