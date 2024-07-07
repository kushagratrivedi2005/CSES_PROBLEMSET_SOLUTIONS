
// this program first assigns the maximum value to the count variable and then subtracts each repeated value - KUSHAGRA TRIVEDI 
#include<stdio.h>
#include<stdlib.h>
using namespace std;
 
 
int compare(const void*x_void, const void*y_void ){
    int x=*(int *)x_void;
    int y=*(int *)y_void;
    return x-y;
}
 
int main(){
int n;
scanf("%d",&n);
int a[n];
 
 
for (int i = 0; i < n; i++)
{
    scanf("%d",&a[i]);
}
qsort(a,n ,sizeof(int),compare);
int count=n;
int res=a[0];
for (int i = 1; i < n; i++)
{
    if((res^a[i])==0)
        {count--;
        res=a[i];}
    else
    res=a[i];
}
printf("%d",count);
 
 
 
return 0;
}
