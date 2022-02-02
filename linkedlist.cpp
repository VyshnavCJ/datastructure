#include<stdio.h>
#include<stdlib.h>

typedef struct node1{
    int data;
    struct node1*link;
}node;

node* CreateNode(int n){
    node* header = (node*) malloc(sizeof(node));
    node* ptr = header;
    header->data = 0;
    header->link = NULL;
    for(int i=0; i<n;i++){
        node* temp = (node*) malloc(sizeof(node));
        printf("Enter the element: ");
        scanf("%d", &temp->data);
        temp->link = NULL;
        ptr->link = temp;
        ptr = ptr->link;
    }
    return header;
}

void DeleteNode(node* header, int pos){
    node* ptr = header->link;
    if(pos==1){
        header->link = ptr->link;
        free(ptr);
    }
    else{
        int i=1;
        while(ptr->link!=NULL && i<pos-1){
            ptr = ptr->link;
            i++;
        }
        if(ptr->link==NULL){
            printf("invalid positon\n");
        }
        else{
            node* temp = ptr->link;
            ptr->link = temp->link;
            free(temp);
        }
    }

}

void TraverseNode(node* header){
    node* ptr = header->link;
    printf("The element are: \n");
    while(ptr!=NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
node* ReverseNode(node* header){
    node* current,*prev,*next;
    current = header->link;
    prev = NULL;
    while(current!=NULL){
        next = current->link;
        current->link =prev;
        prev = current;
        current = next;
    }
    header->link=prev;
    return header;
}

node* reverserec(node* header){
    if(header->link==NULL || header==NULL){
        return header;
    }
    node* temp = reverserec(header->link);
    header->link->link=header;
    header->link=NULL;
    return temp;

}

int main()
{
    printf("Enter the number of nodes you want in the linked list: ");
    int x;
    scanf("%d",&x);
    node* header = CreateNode(x);
    TraverseNode(header);
    header->link = reverserec(header->link);
    TraverseNode(header);
    return 0;
}