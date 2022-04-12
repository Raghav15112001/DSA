#include<iostream>
using namespace std;

int multiplication(int n,int m){
    if(m==0){
        return 0;
    }
    int smallOutput = multiplication(n,m-1);
    return smallOutput+n;
}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<multiplication(n,m);
    return 0;
}