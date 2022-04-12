#include<iostream>
using namespace std;
int stairWays(int n){
    if(n<=3){
        return n;
    }
    int x = stairWays(n-1);
    int y = stairWays(n-2);
    int z = stairWays(n-3);
    return(x+y+z+1);

}

int main()
{
    int n;
    cin>>n;
    cout<<stairWays(n);
    
    return 0;
}