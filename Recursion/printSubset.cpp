#include<iostream>
using namespace std;
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void printSubset(int a[],int n,int output[],int m=0){
    if(n==0){
        printArray(output,m);
        return;
    }
    int newOutput[m+1];
    for(int i=0;i<m;i++){
        newOutput[i]=output[i];
    }
    newOutput[m]=a[0];
    printSubset(a+1,n-1,newOutput,m+1);
    printSubset(a+1,n-1,output,m);
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int output[n];
    printSubset(a,n,output);
    return 0;
}