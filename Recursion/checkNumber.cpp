#include<iostream>
using namespace std;
bool checkNumber(int a[],int n,int x){
    if(n==0){
        return false;
    }
    bool smallOutput = checkNumber(a+1,n-1,x);
    if(!smallOutput){
        if(a[0]==x){
            return true;
        }
    }
    return smallOutput;
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

    cout<<checkNumber(a,n,x);
    return 0;
}