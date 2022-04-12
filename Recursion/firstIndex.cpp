#include<iostream>
using namespace std;

int firstIndex(int a[],int n,int x){
    if(n==0){
        return -1;
    }
    if(a[0]==x){
        return 0;
    }
    int Ans =firstIndex(a+1,n-1,x);
    if(Ans==-1){
        return -1;
    }
    return Ans+1;
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
    cout<<firstIndex(a,n,x)<<endl;

    return 0;
}