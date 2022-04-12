#include<iostream>
using namespace std;

int AllIndex(int a[],int n ,int x,int output[]){
    if(n==0){
        return 0;
    }
    int ans = AllIndex(a+1,n-1,x,output);
    if(a[0]==x){
        ans = ans + 1;
        for (int i =ans-1;i>0;i--){
            output[i]=output[i-1]+1;
        }
        output[0]=0;
    }
    else{
        for (int i =0;i<ans;i++){
            output[i]=output[i]+1;
        }
    }
    return ans;
}

int main()
{
    int n,x;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>x;
    int output[n];
    int FAns = AllIndex(a,n,x,output);

    for(int i =0 ; i<FAns;i++){
        cout<<output[i]<<" ";
    }
    return 0;
}