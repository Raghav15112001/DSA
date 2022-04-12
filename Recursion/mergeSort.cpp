#include<iostream>
using namespace std;

void Merge(int a[],int si,int mid,int ei){
    int b[ei+1];
    int i=si,j = mid+1 ,k=si;
    while(i<=mid&&j<=ei){
        if(a[i]<a[j]){
            b[k]=a[i];i++;
        }
        else{
            b[k]=a[j];j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ei){
            b[k]=a[j];
            k++; j++;
        }
    }
    else{
        while(i<=mid){
            b[k]=a[i];
            k++; i++;
        }
    }

    for(int z=si;z<=ei;z++){
        a[z]=b[z];
    }
}


void MergeSort(int a[],int si,int ei){
if(si>=ei){
    return;
}
int mid = (si+ei)/2;
MergeSort(a,si,mid);
MergeSort(a,mid+1,ei);
Merge(a,si,mid,ei);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    MergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}