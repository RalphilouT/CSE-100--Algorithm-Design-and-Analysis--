// Ralphilou Tatoy
// CSE-100
#include <iostream>
using namespace std;

// while (j > 0 && array[j-1] > array[j] && j < num)
void insertSort(int * array,int num)
{
    
       for(long x = 1; x < num;x++)
        {
            long j = x;
            while (j > 0 && array[j-1] > array[j]){
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                j = j - 1;
            }
        }
}
int main(int argc,char **argv)
{
    int * Sequence;
    int arraySize = 1;
    cin >> arraySize;
    Sequence = new int[arraySize]; 
    for(int i=0; i < arraySize+1; i++)
    {
        cin >> Sequence[i];
        if(i >= 2)
        {
            insertSort(Sequence,i);
            for(int x=0; x < i; x++)
            {
                cout << Sequence[x] << ";";
            }
            cout << endl;
        }
    }
    
    
}
//while (j > 0 && array[j-1] > array[j] && j < num)

