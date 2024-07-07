
#include<bits/stdc++.h>
using namespace std;
struct tree{
    int val;
    struct tree* left;
    struct tree* right;
};
map<int,int>quick;
typedef struct tree* tree1;
 
tree* buildtree(int *inorder, int *preorder, int instart, int inend) {
    static int preindex = 0;
    if (instart > inend) return NULL;
    tree1 new1 = new struct tree;
    new1->val = preorder[preindex];
    new1->left = new1->right = NULL;
    int x=preindex;
    preindex++; 
    if (instart == inend) return new1;
    int index = quick[preorder[x]];
    new1->left = buildtree(inorder, preorder, instart, index - 1);
    new1->right = buildtree(inorder, preorder, index + 1, inend);
    return new1;
}
 
void postorder(tree* t){
    if(t==NULL)return;
    postorder(t->left);
    postorder(t->right);
    printf("%d ",t->val);   
}
 
int main(){
        tree* t1=NULL;
        int n;scanf("%d",&n);
        int inorder[n]; int preorder[n];
        for(int i=0;i<n;i++){
            scanf("%d",&preorder[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&inorder[i]);
            quick[inorder[i]]=i;
        }
        t1=buildtree(inorder,preorder,0,n-1);
        postorder(t1);
}
