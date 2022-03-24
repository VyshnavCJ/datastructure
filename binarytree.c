#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000


typedef  struct bin{
	struct bin* Lchild;
	char data;
	struct bin* Rchild;
}BT;

BT* ROOT;

BT* GetNode(){
	BT* temp = (BT*)malloc(sizeof(BT));
	temp->data='\0';
	temp->Lchild=NULL;
	temp->Rchild=NULL;
	return temp;
}
/*
int top=-1;
BT* stack[SIZE];

void push(BT* x )
{
        if(top==SIZE-1)
                printf("Stack overflow\n");
        else
                stack[++top]=x;
}

BT* pop()
{
        if(top==-1)
                printf("Stack underflow\n");
        else
        {
                return stack[top];
                top--;
        }
}
*/


binarytree_creation(BT* bt, char data){
	if(bt!=NULL){
		bt->data = data;
		A:
		printf("Do you want a Left child for %c (Y/N): ",bt->data);
		char option;
		getchar();
		scanf("%c",&option);
		if(option == 'Y' || option == 'y'){
			bt->Lchild = GetNode();
			printf("Enter the value for the left child of %c : ",bt->data);
			char value;
			getchar();
			scanf("%c",&value);
			binarytree_creation(bt->Lchild,value);
		}else if(option == 'N' || option == 'n'){
			bt->Lchild = NULL;
			binarytree_creation(NULL,'\0');
		}else{ 
                        printf("Invalid option\n");
			goto A;
                }

		B:
		printf("Do you want a Rigth child for %c (Y/N): ",bt->data);
                getchar();
		scanf("%c",&option);
                if(option == 'Y' || option == 'y'){ 
                        bt->Rchild = GetNode();
                        printf("Enter the value for the Rigth child of %c: ",bt->data);
                        char value;
			getchar();
                        scanf("%c",&value);
                        binarytree_creation(bt->Rchild,value);
                }else if(option == 'N' || option == 'n'){ 
                        bt->Rchild = NULL;
                        binarytree_creation(NULL,'\0');
                }else{
			printf("Invalid option\n");
			goto B;
		}
	}
}

void Preorder_rec(BT* ptr){
	if(ptr!=NULL){
		printf("%c\t",ptr->data);
		Preorder_rec(ptr->Lchild);
		Preorder_rec(ptr->Rchild);
	}
}

void Postorder_rec(BT* ptr){
        if(ptr!=NULL){ 
                Postorder_rec(ptr->Lchild);
                Postorder_rec(ptr->Rchild);
		printf("%c\t",ptr->data);
        }
}

void Inorder_rec(BT* ptr){
        if(ptr!=NULL){ 
                Inorder_rec(ptr->Lchild);
		printf("%c\t",ptr->data);
                Inorder_rec(ptr->Rchild);
        }
}
/*void Inorder(){
	BT* ptr = ROOT;
	while(ptr!=NULL || top > -1){
		while(ptr!=NULL){
			push(ptr);
			ptr = ptr->Lchild;
		}
		if(top>-1){
			BT* item = pop();
			printf("%c\t",item->data);
			ptr = item->Rchild;
		}
	}
}
void Preorder(){ 
        BT* ptr = ROOT;
        while(ptr!=NULL || top > -1){ 
                while(ptr!=NULL){ 
                        printf("%c\t",ptr->data);
			push(ptr);
                        ptr = ptr->Lchild;
                }
                if(top>-1){
                        BT* item = pop();
                        ptr = item->Rchild;
                }
        }
}
void Postorder(){ 
        BT* ptr = ROOT;
        while(ptr!=NULL || top > -1){ 
                while(ptr!=NULL){ 
                        push(ptr);
                        ptr = ptr->Lchild;
                }
                if(top>-1){
                        BT* item = pop();
                        ptr = item->Rchild;
			printf("%c\t",item->data);
                }
        }
}
*/
int main(){
	printf("Creating Binary tree-------\n");
	printf("Creating root node\n");
	printf("Enter the value in  Root node: ");
	ROOT = GetNode();
	char data;
	scanf("%c",&data);
	printf("Creating Subtrees\n: ");
	binarytree_creation(ROOT,data);
	printf("\nPreorder Traversal: ");
	Preorder_rec(ROOT);
	printf("\n");
	//Preorder();
	printf("\n");
	printf("\nPostorder Traversal: ");
	Postorder_rec(ROOT);
	printf("\n");
     //Postorder();
    printf("\n");
	printf("\nInorder Traversal: ");
	Inorder_rec(ROOT);
	printf("\n");
    //Inorder();
    printf("\n");

}
