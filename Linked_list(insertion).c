#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
//o(n)
struct node* insertion(struct node *root , int x , int pos){
	struct node *tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = x;
	tmp->next = NULL;
	if(pos == 0){
		root = tmp;
	}else{
		struct node *curr = root;
		for(int i = 0 ; i < pos-1 ;i++){
			if(curr->next != NULL){
				curr = curr->next;
			}
		}
		tmp->next = curr->next;
		curr->next = tmp;
	}
	return root;
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
	printf("Number of element: ");
	scanf("%d", &n);
	for(int i = 1 ; i <= n;i++){
		int x , pos;
		printf("Element: ");
		scanf("%d", &x);
		printf("Position: ");
		scanf("%d" , &pos);
		root = insertion(root , x , pos);
	}
	print(root);

  return 0;
}
