#include<stdio.h>

	struct Node{
		int data;
		struct Node* left;
		struct Node* right;
	};
	typedef struct Node node;
	node *createNode(int n){
		node *NewNode;
		NewNode=(node*)malloc(sizeof(node));
		NewNode->data=n;
		NewNode->left=NULL;
		NewNode->right=NULL;
		return NewNode;
	}
	node* insert(node *root,int n)
	{
		
		if(root==NULL)
		{
			root=createNode(n);
		}
		else if(n<=root->data)
		{
			root->left=insert(root->left,n);
		}
		else
		{
			root->right=insert(root->right,n);
		}
		return root;
	}
	void preorder(node *root){
		if(root==NULL){
			return;
		}
		else{
			printf("%d\t",root->data);
			preorder(root->left);
			preorder(root->right);
			
		}
		
	}
	void inorder(node *root){
		if(root==NULL){
			return;
		}
		else{
			inorder(root->left);
			printf("%d\t",root->data);
			inorder(root->right);
			
		}
	}
	void postorder(node *root){
		if(root==NULL){
			return;
		}
		else{
			postorder(root->left);
			postorder(root->right);
			printf("%d\t",root->data);
			
			
		}
	}
int main(){
	node *root=NULL;
	int n,choice;
	char ch;
	do{
	
	printf("Enter 1 for Insert:\nEnter 2 for preorder:\nEnter 3 for inorder:\nEnter 4 for postorder:\nEnter 5 for Exit:\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Enter Your choice you want to do:\n");
	scanf("%d",&choice);
	switch(choice)
	{
	    case 1:
			printf("Enter a Number To insert:\n");
			scanf("%d",&n);
			root=insert(root,n);
			break;
		case 2:printf("Preorder function\n");
			preorder(root);
			printf("\n");
			break;
		case 3:
			printf("Inorder function\n");
			inorder(root);
			printf("\n");
			break;
		case 4:
			printf("Postorder function\n");
			postorder(root);
			printf("\n");
			break;
		case 5:
			printf("Exit Console\n");
			exit(0);
			break;
		default:
			printf("Wrong Choice/Input\n");
	}
	printf("Do you want to continue Y/N\n");
	ch=getche();
	}while(ch=='Y' || ch!='N');
}
