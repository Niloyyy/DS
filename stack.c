#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *head = NULL;

void push(int val){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = val;
	new_node->next = head;
	head = new_node;
}

void pop(){
	if(head == NULL){
		printf("stack is empty\n");
	}else{
		struct node *temp = head;
		head = head -> next;
		free(temp);
	}
}

int top(){
	return head->data;
}

void show_top(){
	printf("%d" , head->data);
}

void print_stack(){
	if(head == NULL)
		printf("stack is empty\n");
	else{
		struct node *curr = head;
		while(curr != NULL){
			printf("%d " , curr->data);
			curr = curr->next;
		}
	}
}

int main(){
	push(3);
	push(6);
	push(9);
	push(11);
	print_stack();
	printf("\n");
	pop();
	print_stack();
	printf("\n");
	show_top();
	

}
