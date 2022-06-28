// Ralphilou Tatoy
// CSE-100
#include <iostream>
using namespace std;

// while (j > 0 && array[j-1] > array[j] && j < num)
void merge(int * array,int beg, int mid, int end)
{
    int n1 = mid-beg+1;
    int n2 = end-mid;
    int L[n1+1],R[n2+1];
    for(int i = 0;i<n1;i++)
    {
        L[i]=array[beg+i-1];
    }
    for(int j = 0;j<n2;j++)
    {
        R[j] = array[mid+j];
    }
    
    L[n1] = 1000000;
    R[n2] = 1000000;
    int i = 0;
    int j = 0;
    for(int k = beg-1;k<end;k++)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i = i+1;
        }
        else
        {
            array[k] = R[j];
            j = j+1;
        }
    }
    

}
void mergeSort(int * array,int beg, int end)
{
    if(beg < end)
    {
        int mid = (beg+end)/2;
        mergeSort(array,beg,mid);
        mergeSort(array,mid+1,end);
        merge(array,beg,mid,end);
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
    mergeSort(Sequence,1,arraySize);
    
    for(int x=0; x < arraySize; x++)
    {
        cout << Sequence[x] << ";";
        
    }
    // cout << endl;  
}
//while (j > 0 && array[j-1] > array[j] && j < num)

