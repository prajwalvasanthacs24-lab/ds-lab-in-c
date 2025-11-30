#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void postorder(struct node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    printf("Postorder: ");
    postorder(root);
    return 0;
}
