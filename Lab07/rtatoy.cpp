#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;
int max(int a, int b)
{
    //finds max
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int cutROD(int * p, int n)
{
    //pseudocode
    int length;
    if (n == 0){
        return 0;
    }
    int q = INT_MIN;
    for(int i = 0; i<n;i++)
    {
        q = max(q, *(p+i) + cutROD(p,n-1-i));
        
    }
    return q;
}
int * extendedBOTTOMUPCUTROD(int*p, int n)
{
    //pseudocode
    int * r = (int*)malloc(n * sizeof(int));
    int *s = (int*)malloc(n * sizeof(int));
    
    int q = 0;
    *(r+0) = 0;
    for(int i = 1;i<=n;i++)
    {
        q = INT_MIN;
        for(int j = 0;j<i;j++)
        {
            if(q < (*(p+j)+ *(r+(i)-j-1)))
            {
                q = (*(p+j) + *(r+(i)-j-1));
                *(s+i) = j+1;
            }
        }
        *(r+i) = q;
    }
    return (r,s);
}
void printCUTRODSOL(int * p, int n)
{
    //pseudocode
    int *r;
    int *s;
    (r,s) = extendedBOTTOMUPCUTROD(p,n);
    
    while(n>0){
        cout << *(s+n) << " ";
        n = n - *(s+n);
    }
    cout <<-1 <<endl;  
}



int main(int argc,char **argv){
    int length,largest;
    cin >> length;
    int * prices = (int*)malloc(length *sizeof(int));
    for(int i = 0;i < length;i++)
    {
        cin >> prices[i];
    }
    largest = cutROD(prices, length);
    cout << largest <<endl;
    printCUTRODSOL(prices, length);
}