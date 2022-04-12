#include<iostream>
using namespace std;
int BinarySearch(int a[],int si,int ei,int x){
if(si>ei){
    return -1;
}
int mid = (si+ei)/2;
if(a[mid]==x){
    return mid;
}
if(a[mid]>x){
    return BinarySearch(a,si,mid-1,x);
}
if(a[mid]<x){
    return BinarySearch(a,mid+1,ei,x);
}
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    int pos = BinarySearch(a,0,n-1,x);
    cout<<pos;
    return 0;
}