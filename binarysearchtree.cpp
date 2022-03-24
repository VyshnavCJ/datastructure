#include<iostream>
#include<algorithm>
#include<queue>
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

int max(bst* node){
    if(node==NULL){
        cout << "The tree is empty" << endl;
        return -1;
    }
    while(node->Rchild!=NULL){
        node = node->Rchild;
    }
    return node->data;
}

int min(bst* node){
    if(node==NULL){
        cout << "The tree is empty" << endl;
        return -1;
    }
    while(node->Lchild!=NULL){
        node = node->Lchild;
    }
    return node->data;
}

int min_rec(bst* node){
    if(node==NULL){
        cout << "The tree is empty" << endl;
        return -1;
    }
    if(node->Lchild!=NULL){
        return min_rec(node->Lchild);
    }else{
        return node->data;
    }
}

int max_rec(bst* node){
    if(node==NULL){
        cout << "The tree is empty" << endl;
        return -1;
    }
    if(node->Rchild!=NULL){
        return max_rec(node->Rchild);
    }else{
        return node->data;
    }
}

int find_height(bst* node){
    if(node==NULL){
        return -1;
    }
    return std::max(find_height(node->Lchild),find_height(node->Lchild)) + 1;
}

void level_order_traversal(bst* node){ //breadth first traversal
    if(node==NULL) return;
    queue<bst*>q;
    q.push(node);
    while (!q.empty())
    {
        bst* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->Lchild) q.push(temp->Lchild);
        if(temp->Rchild) q.push(temp->Rchild);
    }
    
}
bool IsSubtreelesser(bst* root,int value){
    if(root==NULL) return true;
    if(root->data <= value && IsSubtreelesser(root->Lchild,value) && IsSubtreelesser(root->Rchild,value))
        return true;
    else
        return false;
}

bool IsSubtreeGreater(bst* root,int value){
    if(root==NULL) return true;
    if(root->data > value && IsSubtreeGreater(root->Lchild,value) && IsSubtreeGreater(root->Rchild,value))
        return true;
    else
        return false;
}

bool IsBinarysearch(bst* root){
    if(root==NULL) return true;
    if(IsSubtreelesser(root->Lchild,root->data) && IsSubtreeGreater(root->Rchild,root->data) && IsBinarysearch(root->Lchild) && IsBinarysearch(root->Rchild))
        return true;
    else
        return false;
}

int main(){
    root = NULL;
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,8);
    root = insert(root,12);
    root = insert(root,22);
    root = insert(root,21);
    root = insert(root,7);
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
    if(max(root)!=-1)
        cout <<"The max element in the tree is "<< max(root) <<endl;
    if(min(root)!=-1)
        cout <<"The min element in the tree is "<< min(root) <<endl;
    if(max_rec(root)!=-1)
        cout <<"The max element in the tree is "<< max_rec(root) <<endl;
    if(min_rec(root)!=-1)
        cout <<"The min element in the tree is "<< min_rec(root) <<endl;
    cout << "Heigth of the tree : " << find_height(root) << endl;
    cout << "Breadth order traveral: ";
    level_order_traversal(root);
    cout << endl;
    if(IsBinarysearch(root))
        cout<<"The binary tree is binarysearchtree" << endl;
    else
        cout<<"Not binarysearchtree" << endl;
}