#include<iostream>
using namespace std;
void swap(int a[],int i,int j){
    int temp = a[i];
    a[i]=a[j];
    a[j]=temp;
    
}

int Partition(int a[],int si,int ei){
    int count =si;
    for(int i=si;i<=ei;i++){
        if(a[si]>a[i]){
            count++;
        }
    }
    // puting on prtiton index
    swap(a,si,count);
// Setting two pointer for arranging numbers
    int i=si,j=ei;
    int pivot = a[count];
    while(i<count&&j>count){
        while(a[i]<pivot){i++;}
        while(a[j]>=pivot){j--;}
        if(i<j) swap(a,i,j);
        
    }
    
    return count;
}


void QuickSort(int a[],int si,int ei){
    if(si>=ei){
        return;
    }
    int x = Partition(a,si,ei);
    QuickSort(a,si,x-1);
    QuickSort(a,x+1,ei);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}