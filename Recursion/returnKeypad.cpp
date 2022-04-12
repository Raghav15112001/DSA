#include <iostream>
using namespace std;

string sArray[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int returnKeypad(int num, string output[])
{
    if (num == 0||num==1)
    {
        output[0] = sArray[0];
        return 1;
    }
    int smallNum = num / 10;
    string smallString = sArray[num % 10];
    int smallOutput = returnKeypad(smallNum, output);
    for (int i = 0; i < smallOutput; i++)
    {   
        string temp = output[i];
        output[i] = temp + smallString[0];
        output[i + smallOutput] = temp + smallString[1];
        output[i + 2 * smallOutput] = temp + smallString[2];
    
        if (smallString.size() == 4)
        {
            output[i + 3 * smallOutput] = temp + smallString[3];
            
        }
    }
        if(smallString.size()==4)return 4 * smallOutput;
        return 3 * smallOutput;
    }


int main()
{
    int num;
    cin >> num;
    string *output = new string[1000];
    int outputSize = returnKeypad(num, output);
    for (int i = 0; i < outputSize; i++)
    {
        cout << output[i] << " ->" << i << endl;
    }
    return 0;
}