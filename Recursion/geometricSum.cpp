#include<iostream>
#include<cmath>
using namespace std;

float GSum(int k){
    if(k==0){
        return 1;
    }
    float smallOutput = GSum(k-1);
    return smallOutput+(1/(pow(2,k)));
}

int main()
{
    int k;
    cin>>k;
    cout<<GSum(k);
    return 0;
}