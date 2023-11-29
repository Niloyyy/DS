
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    struct node *l , *r;
};

struct node* new_node(int x){
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->val = x;
    tmp->l = NULL;
    tmp->r = NULL;
    return tmp;
}
struct node* insertion(struct node *root , int x){
    if(root == NULL) return new_node(x);
    
    if(x > root->val)
    root->r = insertion(root->r , x);
    else
    root->l = insertion(root->l , x);
    
    return root;
}

void preorder(node *root){
    if(root == NULL) return;
    cout << root->val<<" ";
    preorder(root->l);
    preorder(root->r);
}

void inorder(node *root){
    if(root == NULL) return;
    inorder(root->l);
    cout << root->val<<" ";
    inorder(root->r);
}

void postorder(node *root){
    if(root == NULL) return;
    postorder(root->l);
    postorder(root->r);
    cout << root->val<<" ";
}

struct node* search(struct node *root , int x){
    if(root == NULL || root->val == x) return root;

    if(x > root->val) return search(root->r , x);
    else return search(root->l , x);
}


int main() {
    struct node *root = NULL;
    cout<<"Number of element: ";
    int n; cin >> n;
    for(int i = 1 ;i <= n;i++){
        int x ; cin >> x;
        root = insertion( root , x);
    }
  
    cout<<"Inorder traversing: ";
    inorder(root);
    cout<<endl;
  
    cout<<"Preorder traversing: ";
    preorder(root);
    cout<<endl;
  
    cout<<"Postorder traversing: ";
    postorder(root);
    cout<<endl;

    cout<<"Which element you wanna find: ";
    int key; cin >>key;
    if(search(root , key) == NULL) 
        cout <<"Not found";
    else cout <<"Found";

    return 0;
}
