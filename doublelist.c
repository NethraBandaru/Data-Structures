#include<stdio.h>
#include<stdlib.h>
struct node{
	char data;
	struct node* next;
	struct node* prev;
};
void forwardList(struct node* head){
	struct node* temp=head;
	while(temp!=NULL){
		printf("%c->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
void backward(struct node* tail){
	struct node* temp=tail;
	while(temp!=NULL){
		printf("%c->",temp->data );
		temp=temp->prev;
	}
	printf("NULL\n");
}
struct node* insertAtbegin(struct node* head,struct node* *tail,char val){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL){
		head=newnode;
		*tail=newnode;
		return head;
	}
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
	return head;
}
struct node* insertAtEnd(struct node* tail,struct node* *head,char val){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(tail==NULL){
		*head=newnode;
		tail=newnode;
		return tail;
	}
	tail->next=newnode;
	newnode->prev=tail;
	tail=newnode;
	return tail;
}
struct node* deleteAtbegin(struct node* head,struct node* *tail){
	if(head==NULL){
		return NULL;
	}
	if(head->next==NULL){
		free(head);
		return NULL;
	}
	struct node* temp=head;
	head=head->next;
	temp->next=NULL;
	free(temp);
	return head;
}
struct node* deleteAtEnd(struct node* tail,struct node* *head){
	if(tail==NULL){
		return NULL;
	}
	if(tail->prev==NULL){
		free(tail);
		return NULL;
	}
	struct node* temp=tail;
	tail=tail->prev;
	tail->next=NULL;
	free(temp);
	return tail;
}
int main(){
	struct node *head,*tail;
	head=NULL;
	tail=NULL;
	printf("INitial double linked list:\n");
	printf("Forward List : ");
	forwardList(head);
	printf("Backward List : ");
	backward(tail);
	head=insertAtbegin(head,&tail,'U');
	head=insertAtbegin(head,&tail,'G');
	head=insertAtbegin(head,&tail,'R');
	printf("After insertion of three nodes at beginning:\n");
	printf("Forward :");
	forwardList(head);
	printf("Backward : ");
	backward(tail);
	tail=insertAtEnd(tail,&head,'K');
	tail=insertAtEnd(tail,&head,'T');
	printf("After insertion of two nodes at end \n");
	printf("Forward :");
	forwardList(head);
	printf("Backward : ");
	backward(tail);
	head=deleteAtbegin(head,&tail);
	head=deleteAtbegin(head,&tail);
	printf("After deletion of two nodes at beginning\n");
	printf("Forward :");
	forwardList(head);
	printf("Backward : ");
	backward(tail);
	tail=deleteAtEnd(tail,&head);
	tail=deleteAtEnd(tail,&head);
	printf("After deletion of two nodes at end \n");
	printf("Forward :");
	forwardList(head);
	printf("Backward : ");
	backward(tail);
	return 0;
}
