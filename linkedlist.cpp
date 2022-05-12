#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;
};

// Print linked list
void printlist(Node *n){ 
    while(n!=NULL){
        cout<<n->value<<"--> ";
        n=n->next;
    }
    cout<<"NULL";
}

//Insert at head 
void insertAtHead(Node * &head,int val){
    Node* n= new Node();
    n->value = val;

    n->next=head;
    head=n;
}

//Insert at tail 
void insertAtTail(Node* &head,int val){ //take head by reference not by value as we want to modify linkedlist
    Node* n= new Node();
    n->value = val;

    if(head==NULL){ //when linked list is empty
        head=n;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){ //iterate to the last of linked list
        temp=temp->next;
    }
    temp->next=n;
}
void deleteAtHead(Node* &head){
    Node* todelete=head;
    head=head->next;

    delete todelete;
}
 //Deletion 
void deletion(Node* &head,int val){
    
    if(head==NULL){ //incase when linked list is empty
        return;
    }
    if(head->next==NULL){ //incase when linked list has only one node
        deleteAtHead(head);
        return;
    }
    Node* temp=head;
    while (temp->next->value!=val){ //from this loop we will reach to the node just before the node to delete.
        temp=temp->next;
    }
    Node* todelete=temp->next; // temp->next is the node to be deleted So,we store it in variable then will delete it from memory.
    temp->next=temp->next->next; //to temp->next we will assign the node which is next to deletion node.

    delete todelete;
    
}
//Reverse linked list (Iterative way)
/*  Initialize three pointers prev as NULL, curr as head and next as NULL.
    Iterate through the linked list. In loop, do following. 
    // Before changing next of current, 
    // store next node 
    next = curr->next
    // Now change next of current 
    // This is where actual reversing happens 
    curr->next = prev 
    // Move prev and curr one step forward 
    prev = curr 
    curr = next
*/
Node* reverseItr(Node* &head){
    Node* prevptr=NULL;
    Node* currptr=head;
    Node* nextptr;

    while (currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
    
}

//Reverse linked list (Recursive way)

Node* reverseRec(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newHead=reverseRec(head->next);
    head->next->next=head;
    head->next=NULL;

    return newHead;
}

//Reverse K Node at a time
Node* reverseK(Node* &head,int k){
    Node* prevptr=NULL;
    Node* currptr=head;
    Node* nextptr;
    int count=0;
    while(currptr!=NULL && count<k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next = reverseK(nextptr,k);
    }
    return prevptr;
    
}
int main()
{
    Node* head=new Node();
    Node* second=new Node();
    Node* third=new Node();
    
    head->value=1;
    head->next=second;

    second->value=2;
    second->next=third;

    third->value=3;
    third->next=NULL;


    //printlist(head);

    insertAtTail(head,4);

    //insertAtHead(head,4);

    printlist(head);
    cout<<endl;

    //deletion(head,2);
    //deleteAtHead(head);

    //Node* newHead= reverseItr(head);
    //Node* newHead= reverseRec(head);

    Node* newHead= reverseK(head,2);
    printlist(newHead);

}