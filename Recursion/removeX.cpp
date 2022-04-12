#include<iostream>
using namespace std;

void removeX(char s[]){
    if(s[0]=='\0'){
        return;
    }
    removeX(s+1);
    if(s[0]=='x'){
        int i;
        for(i=0;s[i]!='\0';i++){
            s[i]=s[i+1];
        }
        removeX(s);
    }
}
int main()
{
    char s[100];
    cin>>s;
    
    removeX(s);
    cout<<s;
    return 0;
}