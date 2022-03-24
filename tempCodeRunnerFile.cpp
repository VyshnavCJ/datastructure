bool IsSubtreelesser(bst* root,int value){
//     if(root==NULL) return true;
//     if(root->data <= value && IsSubtreelesser(root->Lchild,value) && IsSubtreelesser(root->Rchild,value))
//         return true;
//     else
//         return false;
// }

// bool IsSubtreeGreater(bst* root,int value){
//     if(root==NULL) return true;
//     if(root->data > value && IsSubtreeGreater(root->Lchild,value) && IsSubtreeGreater(root->Rchild,value))
//         return true;
//     else
//         return false;
// }

// bool IsBinarysearch(bst* root){
//     if(root==NULL) return true;
//     if(IsSubtreelesser(root->Lchild,root->data) && IsSubtreeGreater(root->Rchild,root->data) && IsBinarysearch(root->Lchild) && IsBinarysearch(root->Rchild))
//         return true;
//     else
//         return false;
// }