#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;
// void matrixchainORDER(int * p,int n, int **s, int **m)
// {
//     int q,j;
    
//     // for(int i = 1; i<n;i++)
//     // {
//     //     *(*(m+i)+i) = 0; 
//     // }
//     for(int l = 2; l<n;l++)
//     {
//         for(int i = 1; i< n-l+1;i++)
//         {
//             j = i + l - 1;
//             *(*(m+i)+j)= INT_MAX;
//             for(int k = i; k <= j-1;k++)
//             {
//                 q = *(*(m+i)+k) + *(*(m+(k+1))+j) + p[i-1] * p[k] * p[j];

//                 if(q < *(*(m+i)+j))
//                 {
//                     *(*(m+i)+j) = q;
//                     *(*(s+i)+j) = k;
//                 }
//             }
//         }
//     }
//     //return m[1][n - 1];  
// }
int** matrixchainORDER1(int * p,int n, int **s)
{
    //pseudocode, also in lab
    int q,j;
    int ** m =(int**)malloc(n * sizeof(int));
    for(int i = 0; i<n;i++)
    {
        *(m+i) = (int *)malloc(n * sizeof(int)); 
    }
    for(int i = 1; i<n;i++)
    {
        *(*(m+i)+i) = 0; 
    }
    for(int l = 2; l<n;l++)
    {
        for(int i = 1; i< n-l+1;i++)
        {
            j = i + l - 1;
            *(*(m+i)+j)= INT_MAX;
            for(int k = i; k <= j-1;k++)
            {
                q = *(*(m+i)+k) + *(*(m+(k+1))+j) + p[i-1] * p[k] * p[j];

                if(q < *(*(m+i)+j))
                {
                    *(*(m+i)+j) = q;
                    *(*(s+i)+j) = k;
                }
            }
        }
    }
    return m;  
}
void printoptimalPARENS(int**s,int i, int j,int n)
{
    //pseudocode
    if(i==j)
    {
        cout << 'A'<< i-1;
        //cout << 'A';
    }
    else{
        cout << "(";
        printoptimalPARENS(s,i,*(*(s+i)+j),n);
        printoptimalPARENS(s,*(*(s+i)+j)+1,j,n);
        cout << ")";
    }
}
int main(int argc,char **argv)
{
    int size,largest,m;
    cin >> size;
    int size2 = size +1;
    int * size1 = (int*)malloc(size2*sizeof(int));
    int **m1=(int**)malloc(size2 * sizeof(int));
    int **s1=(int**)malloc((size2) * sizeof(int));
    for(int i = 0; i<size2;i++)
    {
        //*(m1+i) = (int *)malloc(size2 * sizeof(int)); 
		*(s1+i) = (int *)malloc((size2)* sizeof(int));
    }
    for(int i = 1; i<size2;i++)
    {
        //*(*(m1+i)+i) = 0; 
        *(*(s1+i)+i) = 0;
    }
    int cost;
    for(int i = 0;i < size2;i++)
    {
        cin >> *(size1+i);
    }
    //matrixchainORDER(size1, size2,s1,m1);
    m1 = matrixchainORDER1(size1, size2,s1);
    cout <<  *(*(m1+1)+size2-1) << endl;
    printoptimalPARENS(s1,1,size2-1,size2);
    cout <<endl;
    //free(m1);
    //free(s1);
    return 0;
}
