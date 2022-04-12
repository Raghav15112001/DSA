#include<iostream>
using namespace std;

int countZero(int n){
    if(n/10==0){
    if(n==0){
        return 1;
    }
    return 0;
    }
    int m = n/10;
    int smallOutput = countZero(m);
    if((n%10)==0){
        return smallOutput+1;
    }
    return smallOutput;
    
}

int main()
{
    int n;
    cin>>n;
    cout<<countZero(n);
    return 0;
}