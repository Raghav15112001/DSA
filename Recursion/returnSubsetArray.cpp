#include <iostream>
#include <cmath>
using namespace std;

int subsetArrays(int a[], int n, int **output)
{
    if (n == 0)
    {
        output[0][0] = 0;
        return 1;
    }
    // int col = n-1;
    // int row = pow(2,n);
    int smallOutput = subsetArrays(a + 1, n - 1, output);
     // after calling recursion we will assume ki recursion has done there work and it has filled the output array now just have to make copy of it and put the array[0] value in front of it.

    // shifting and stting values in output array
    for (int i = 0; i < smallOutput; i++)
    {
        output[i + smallOutput][0] = output[i][0] + 1;
        for (int j = output[i + smallOutput][0]; j > 1; j--)
        {
            output[i + smallOutput][j] = output[i][j - 1];
        }
        output[i + smallOutput][1] = a[0];
    }
    return 2 * smallOutput;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int **output = new int *[1000];
    for (int i = 0; i < 1000; i++)
    {
        output[i] = new int[100];
    }
    int size = subsetArrays(a, n, output);

   
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }

        // Newline for new row
        cout << endl;
    }

    return 0;
}