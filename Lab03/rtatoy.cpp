#include <iostream>
using namespace std;
int maxCross(int*A, int low, int mid, int high)
{
    int leftSUM = -100000,rightSUM = -100000,maxLEFT,sum = 0,maxRIGHT;
    for (int i = mid; i > low-1; i--)
    {
        sum = sum + A[i];
        if(sum > leftSUM)
        {
            leftSUM = sum;
            maxLEFT = i;
        }
    }
    sum = 0;
    for(int j = mid+1; j<high; j++)
    {
        sum = sum + A[j];
        if(sum > rightSUM)
        {
            rightSUM = sum;
            maxRIGHT = j;
        }
    }
    return (maxLEFT,maxRIGHT,leftSUM+rightSUM);
}
int maxSUB(int *A, int low, int high)
{
    int mid,leftLOW, leftHIGH,leftSUM,rightLOW, rightHIGH,rightSUM,crossLOW,crossHIGH,crossSUM;
    if(high == low)
    {
        return (low,high,A[low-1]);
    }
    else
    {
        mid = (low+high)/2;
        (leftLOW, leftHIGH,leftSUM) = maxSUB(A,low,mid);
        (rightLOW,rightHIGH,rightSUM) = maxSUB(A, mid+1,high);
        (crossLOW,crossHIGH,crossSUM) = maxCross(A,low,mid,high);
        if(leftSUM >= rightSUM && leftSUM >= crossSUM)
        {
            return(leftLOW,leftHIGH,leftSUM);
        }
        else if(rightSUM >= leftSUM && rightSUM >= crossSUM)
        {
            return(rightLOW,rightHIGH,rightSUM);
        }
        else
        {
            return(crossLOW,crossHIGH,crossSUM);
        }
    }
}
int main(int argc,char **argv)
{
    int low,high,sum;
    int * Sequence;
    int arraySize = 1;
    cin >> arraySize;
    Sequence = new int[arraySize]; 
    for(int i=0; i < arraySize; i++)
    {
        cin >> Sequence[i];  
    }
    (low,high,sum) = maxSUB(Sequence,1,arraySize);
    cout << sum;
}