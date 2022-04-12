#include<iostream>
#include<cmath>
using namespace std;
int subsequence(string s,string output[]){
    if(s.size()==0){
        output[0]=="";
        return 1;
    }
    int sc = subsequence(s.substr(1),output);
    for(int i=0;i<sc;i++){
        output[sc+i]=s[0]+output[i];
    }
    return 2*sc;
}


int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int outputSize = pow(2,n);
    string *output = new string[outputSize];
    int outputSizeU = subsequence(s,output);
    for(int i=0;i<outputSize;i++){
        cout<<output[i]<<" ->"<<i<<endl;
    }
    return 0;
}