#include<iostream>
using namespace std;

int subsetSumK(int a[],int n,int k,int **output){
    if(n==0){
        if(k==0){
            output[0][0]=0;
            return 1;
        }
        else return 0; 
    }


    int s1 = subsetSumK(a+1,n-1,(k-a[0]),output);
 
    for (int i=0;i<s1;i++){
        
        output[i][0] = output[i][0] + 1;
        for (int j = output[i][0]; j > 1; j--)
        {
            output[i][j] = output[i][j - 1];

        }
        output[i][1] = a[0];
    }

    
    int s2 = subsetSumK(a+1,n-1,k,output+s1);

 return s1+s2; 
}


int main()
{
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;

    int **output = new int *[1000];
    for (int i = 0; i < 1000; i++)
    {
        output[i] = new int[100];
    }

        int size = subsetSumK(a,n,k,output);
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}