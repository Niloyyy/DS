#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

//appending with O(1);
struct node* append(struct node *root , int x ){
	struct node *tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = x;
	tmp->next = NULL;
	if(root != NULL){
	    root->next = tmp;
	}
	return tmp;
}

void print(struct node *root){
	struct node *curr_node = root;
	while(curr_node != NULL){
		printf("%d " , curr_node->data);
		curr_node =curr_node->next;
	}
}
	
int main(){
	struct node *root = NULL , *curr = NULL;
	int n;
	printf("Number of element ");
	scanf("%d" , &n);
	for(int i = 1 ; i <= n;i++){
	    int x;
	    scanf("%d" , &x);
	    curr = append(curr , x);
	    if(i == 1) root = curr;
	}
	print(root);
	
	return 0;
}
