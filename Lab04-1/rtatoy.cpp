#include <iostream>
using namespace std;
int parent(int i)
{
    return (i/2);
}
int left(int i)
{
    return (2*i);
}
int right(int i)
{
    return ((2*i)+1);
}
void maxHEAPIFY(int*array,int i,int size,int heapsize)
{
    
    int l = left(i),largest,r = right(i);
    if(l <= heapsize && array[l] > array[i])
    {
        largest = l;
    }
    else{
        largest = i;
    }
    if(r <= heapsize && array[r] > array[largest])
    {
        largest = r;
    }
    if(largest!=i)
    {
        int largest1 = array[largest];
        array[largest] = array[i];
        array[i] = largest1;
        maxHEAPIFY(array,largest,size,heapsize);
    }
}
void buildMAXHEAP(int *array,int size,int heapsize)
{
    heapsize = size;
    for(int i = size/2; i >= 0;--i)
    {
        maxHEAPIFY(array,i,size,heapsize);
    }
}
void heapSORT(int*array,int size)
{
    int heapsize = size;
    buildMAXHEAP(array, size, heapsize);
    for(int i = size;i>0; --i)
    {

        int first = array[0];
        array[0] = array[i];
        array[i] = first;
        heapsize = heapsize - 1;
        maxHEAPIFY(array,0,size,heapsize);
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
    
    heapSORT(Sequence,arraySize-1);
    for(int x=0; x < arraySize; x++)
    {
        cout << Sequence[x] << ";";
        
    }
}
