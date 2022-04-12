#include<iostream>
using namespace std;
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void printSubsetSumK(int a[],int n,int k,int output[],int m=0){
    if(n==0){
        if(k==0){
        printArray(output,m);
        }
        return;
    }
    int newOutput[m+1];
    for(int i=1;i<=m;i++){
        newOutput[i]=output[i-1];
    }
    newOutput[0]=a[0];
    printSubsetSumK(a+1,n-1,k-a[0],newOutput,m+1);
    printSubsetSumK(a+1,n-1,k,output,m);
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    int output[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    printSubsetSumK(a,n,k,output);
    return 0;
}