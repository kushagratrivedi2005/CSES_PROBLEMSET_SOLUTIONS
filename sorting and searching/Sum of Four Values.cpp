
#include<stdio.h>
#include<stdlib.h>
typedef struct pair{
    int first;
    int second;
}pair;
int comp(const void *a,const void *b){
    return (*(pair*)a).first-(*(pair *)b).first;
}
int main(){
    int n,z;scanf("%d %d",&n,&z);
    pair values[n]; for(int i=0;i<n;i++){scanf("%d",&values[i].first);values[i].second=i+1;}
    qsort(values,n,sizeof(pair ),comp);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            long long int sum=values[i].first+values[j].first;
            int k=j+1;int l=n-1;
            while(k<l){
            if(sum+values[k].first+values[l].first>z){l--;}
            else if(sum+values[k].first+values[l].first==z){printf("%d %d %d %d",values[i].second,values[j].second,values[k].second,values[l].second);return 0;}
            else{
                k++;
            }
 
            }
        }
    }
    printf("IMPOSSIBLE");
}
