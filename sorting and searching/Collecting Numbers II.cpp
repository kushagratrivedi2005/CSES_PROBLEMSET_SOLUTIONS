
#include<stdio.h>
#include<stdlib.h>
int min(int a,int b){
    return a>b?b:a;
}
int max(int a,int b){
    return a<b?b:a;
}
int main(){
    int n,k; scanf("%d %d",&n,&k);
    int values[n+1]; for(int i=1;i<n+1;i++)scanf("%d",&values[i]);
    int position[n+1];for(int i=1;i<n+1;i++){position[values[i]]=i;}
    int count=0;
    for(int i=1;i<n;i++){
        if(position[i]>position[i+1])count++;
    }
    count++;
    // printf("%d\n",count);
    while(k--){
        int x,y; scanf("%d %d",&x,&y);
        int x1=values[x]; int y1=values[y]; 
        if(x1!=1){if(position[x1-1]>position[x1])count--;}
        if(x1!=n){if(position[x1+1]<position[x1])count--;}
        if(y1!=1){if(position[y1-1]>position[y1])count--;}
        if(y1!=n){if(position[y1+1]<position[y1])count--;}
        if(max(x1,y1)-min(x1,y1)==1 && position[min(x1,y1)]>position[max(x1,y1)])count++;
        // printf("%d\n",count);
        int temp=values[x];
        values[x]=values[y];
        values[y]=temp;
        position[values[x]]=x;
        position[values[y]]=y;
        if(x1!=1){if(position[x1-1]>position[x1])count++;}
        if(x1!=n){if(position[x1+1]<position[x1])count++;}
        if(y1!=1){if(position[y1-1]>position[y1])count++;}
        if(y1!=n){if(position[y1+1]<position[y1])count++;}
        if(max(x1,y1)-min(x1,y1)==1 && position[min(x1,y1)]>position[max(x1,y1)])count--;
        printf("%d\n",count);
    }
} 
