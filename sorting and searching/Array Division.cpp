
#include<stdio.h>
#define int long long
int ispossible(int *arr,int n,int sum1,int k){
    int count=1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];if(sum>sum1){count++;sum=arr[i];}    
    }
    // printf("%d %d\n",count,sum1);
    return count<=k;
}
 
int search(int *arr,int n,int k){
    int l=arr[0]; int r=arr[0];
    for(int i=1;i<n;i++){if(arr[i]>l)l=arr[i];r+=arr[i];}
    int ans=0;
    // printf("%d %d",l,r);
    while(l<=r){
        int mid=(l+r)/2;
        // printf("%d\n",ispossible(arr,n,mid));
        if(ispossible(arr,n,mid,k)){r=mid-1;ans=mid;}
        else{l=mid+1;}
    }
    return ans;
}
 
signed main(){
    int n,k; scanf("%lld %lld",&n,&k);
    int values[n];
    for(int i=0;i<n;i++)scanf("%lld",&values[i]);
    printf("%lld",search(values,n,k));
    return 0;
}
