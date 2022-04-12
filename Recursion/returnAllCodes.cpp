#include<iostream>
using namespace std;

// '1'-'0'=1=i
// 'a'+i-1

string* allCode(string s){


int i = s[0]-'0';
if(i<=26){
    char temp = 'a'+i-1;
}
string* p = allCode(s.substr(1)); 
for(int i=0;)


}

int main()
{   
    string s;
    cin>>s;
    allCode(s);
    
    return 0;
}