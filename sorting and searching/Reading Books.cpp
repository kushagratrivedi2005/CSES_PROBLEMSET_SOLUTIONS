
#include<stdio.h>
#include<stdlib.h>
// #define int long long
int comp(const void*a,const void *b){
    return *(int*)a-*(int*)b
;}
int min(int a,int b){
    return a<b?a:b;
}
int max(int a,int b){
    return a>b?a:b;
}
signed main(){
    int n;scanf("%d",&n); long long values[n]; for(int i=0;i<n;i++)scanf("%lld",&values[i]);
    qsort(values,n,sizeof(long long),comp);
    long long sum=0;
    for(int i=0;i<n-1;i++)sum+=values[i];
    if(values[n-1]>=sum){printf("%lld",2*values[n-1]);return 0;}
    else{printf("%lld",sum+values[n-1]);}
}
