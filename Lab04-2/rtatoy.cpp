#include <iostream>
#include <stdlib.h>
using namespace std;

int partition(int*array, int p, int r)
{
    int x = array[r];
    int i = p-1;
    for(int j = p; j< r;j++)
    {
        if(array[j] <= x)
        {
            i++;
            int k = array[i];
            array[i] = array[j];
            array[j] = k;
        }
    }
    int l = array[i+1];
    array[i+1] = array[r];
    array[r] = l;
    return (i+1);
}
void quickSORT(int * array,int p,int r)
{
    
    if(p < r)
    {
        int q = partition(array,p,r);
        quickSORT(array,p,q-1);
        quickSORT(array,q+1,r);
    }
}

int randomizedPARTITION(int*array,int p , int r)
{
    int random = p + rand() % (r - p);
    int j = array[r];
    array[r] = array[random];
    array[random] = j;
    return (partition(array,p,r));
}
void randomizedQUICKSORT(int*array, int p, int r)
{
    if(p < r)
    {
        int q = randomizedPARTITION(array,p,r);
        randomizedQUICKSORT(array,p,q-1);
        randomizedQUICKSORT(array,q+1,r);
    }
}
int main(int argc,char **argv)
{
    int * Sequence;
    int arraySize = 1;
    cin >> arraySize;
    Sequence = new int[arraySize]; 
    for(int i=0; i < arraySize; i++)
    {
        cin >> Sequence[i];  
    }
    //quickSORT(Sequence,0,arraySize-1);
    randomizedQUICKSORT(Sequence,0,arraySize-1);
    for(int x=0; x < arraySize; x++)
    {
        cout << Sequence[x] <<';';
    }
}





