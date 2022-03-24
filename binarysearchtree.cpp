#include<iostream>
#define SIZE 1000

using namespace std;

struct bst{
	bst* Lchild;
	int data;
	bst* Rchild;
};

bst* root, *temp;

bst* GetNode(int n){
	bst* temp = new bst();
	temp->data = n;
	temp->Lchild=NULL;
	temp->Rchild=NULL;
	return temp;
}

bst* insert(bst* node ,int n){
    if(node == NULL){
        node = GetNode(n);
    }else if(node->data>=n){
        node->Lchild = insert(node->Lchild,n);
    }else if(node->data<n){
        node->Rchild = insert(node->Rchild,n);
    }
    return node;
}

void Inorder_rec(bst* ptr){
        if(ptr!=NULL){ 
            Inorder_rec(ptr->Lchild);
		    cout << ptr->data << endl;
            Inorder_rec(ptr->Rchild);
        }
}

bool search(bst*node,int x){
    if(node==NULL) return false;
    else if(node->data>x){
        node = node->Lchild;
        return search(node,x);
    }else if(node->data<x){
        node = node->Rchild;
        return search(node,x);
    }else return true;
}

int main(){
    root = NULL;
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,8);
    root = insert(root,12);
    Inorder_rec(root);
    cout << endl;
    int num;
    cout<<"Enter the number you want to search: ";
    cin >> num;
    if(search(root,num)){
        cout << "found the number" <<endl;
    }else{
        cout << "Not found" << endl;
    }

}