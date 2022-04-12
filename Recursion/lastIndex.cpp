#include<iostream>
using namespace std;

int lastIndex(int a[],int n,int x){
    if(n==0){
        return -1;
    }
    int Ans =lastIndex(a,n-1,x);
    if(a[n-1]==x){
        return n-1;
    }
    return Ans;
}

int main()
{
    int n,x;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>x;
    cout<<lastIndex(a,n,x)<<endl;

    return 0;
}