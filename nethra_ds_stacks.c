#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* top=NULL;
void push(int ele){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=ele;
	newnode->next=NULL;
	if (top==NULL)
	{
		top=newnode;
		printf("%d is inserted successfully\n",newnode->data);
	}
	else{
		newnode->next=top;
		top=newnode;
		printf("%d is inserted successfully\n",newnode->data);
	}

}
int isempty(){
	if(top==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
void pop(){
	if(isempty()){
		printf("Stack is underflown\n");
	}
	else{
		struct node* temp=top;
		top=top->next;
		printf("%d is deleted successfully\n",temp->data);
		free(temp);
	}
}
void peek(){
	if(isempty()){
		printf("Stack is underflown\n");
	}
	else{
		printf("Top element is %d\n",top->data);
	}
}
void display(){
	if(isempty()){
		printf("STack is underflown\n");
	}
	else{
		struct node* temp=top;
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
void search(int ele){
	if(isempty()){
		printf("Stack is empty\n");
	}
	int flag=0;
	struct node* temp=top;
	while(temp!=NULL){
		if(temp->data==ele){
			flag=1;
			break;
		}
		temp=temp->next;
	}
	if(flag==1){
		printf("%d is found in stack",ele);
	}
	else{
		printf("%d is not found",ele);
	}
}
int main(){
	push(10);
	push(20);
	display();
	pop();
	peek();
	search(10);
	return 0;
}