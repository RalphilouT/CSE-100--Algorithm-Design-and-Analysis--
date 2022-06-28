#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
void countSORT(vector<vector<int>> &x);
void radixSORT(vector<vector<int>> &x, int d, int vectorSize)
{
    for(long i = d-1;i>=0;--i)
    {
        for(long j = 1; j <vectorSize;j++)
        {
            long z = j;
            while (z > 0 && (x[z-1][i] > x[z][i])){
                x[z-1].swap(x[z]);
                z = z - 1;
            }
        }
        
    }
}

int main(int argc,char **argv)
{
    int vectorSize = 1;
    cin >> vectorSize;
    vector<vector<int>> x;
    for(int i = 0;i<vectorSize;i++)
    {
        vector<int> v;
        for(int j =0; j <10;j++)
        {
            int input;
            cin >> input;
            v.push_back(input);
        }
        x.push_back(v);
    }
    radixSORT(x,10,vectorSize);
    for(int i = 0;i<vectorSize;i++)
    {
        for(int j =0; j <10;j++)
        {
            cout<< x[i][j] <<';';
        }
        cout << endl;
    }
}