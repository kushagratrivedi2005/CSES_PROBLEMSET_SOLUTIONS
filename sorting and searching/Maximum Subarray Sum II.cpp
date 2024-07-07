
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define int long long
 
struct queue{
    int size;
    int * elements;
    int left;
    int right;
};
typedef struct queue * Q;
 
Q createqueue(int size1){
    Q new1=(Q)malloc(sizeof(struct queue));
    new1->elements=(int*)malloc(sizeof(int)*size1);
    new1->left=0;
    new1->right=0;
    new1->size=0;
    return new1;
}
 
int popright(Q q1){
    q1->size--;
    return q1->elements[--q1->right];
}
 
int popleft(Q q1){
    q1->size--;
    return q1->elements[q1->left++];
}
 
void pushright(Q q1,int value){
    q1->size++;
    q1->elements[q1->right++]=value;
}
 
int right(Q q1){
    return q1->elements[q1->right-1];
}
 
int left(Q q1){
    return q1->elements[q1->left];
}
 
signed main(){
    int n ;scanf("%lld",&n); int l,r;scanf("%lld %lld",&l,&r);
    int values[n];for(int i=0;i<n;i++){scanf("%lld",&values[i]);}
    int prefix[n+1];
    prefix[0]=0;
    for(int i=0;i<n;i++){prefix[i+1]=prefix[i]+values[i];}
    // for(int i=0;i<n+1;i++){printf("%d ",prefix[i]);}
    Q q1=createqueue(n+1);
    int maxi=-(__LONG_LONG_MAX__-3);
    for(int i=l;i<n+1;i++){
        if(i-left(q1)>r){popleft(q1);}
        while(q1->size!=0 && prefix[i-l]<prefix[right(q1)]){popright(q1);}
        pushright(q1,i-l);
        if(prefix[i]-prefix[left(q1)]>maxi)maxi=prefix[i]-prefix[left(q1)];
    }
    printf("%lld",maxi);
    return 0;
}
