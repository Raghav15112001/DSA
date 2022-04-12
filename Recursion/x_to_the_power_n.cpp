#include<iostream>
using namespace std;
int xPower_n(int x,int n){
    if(n==0){
        return 1;
    }
    int smalloutput = xPower_n(x,n-1);
    int large = x*smalloutput;
    return large;
}

int main()
{
    int x,n;
    cin>>x>>n;
    cout<<xPower_n(x,n);
    return 0;
}