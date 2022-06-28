#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <limits.h>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
map<int,vector<int>> edge;
int min(int v1, int v2, int uandweight)
{
    int min3 = 3;
    
    int dud = INT_MAX-100000;
    
    int * findmin = (int*)malloc(min3*sizeof(int));
    *(findmin+0)=v1;
    *(findmin+1)=v2;
    *(findmin+2)=uandweight;
    for(int i=0;i<min3;i++)
    {
        if(dud > *(findmin+i))
        {        
            dud = *(findmin+i);
        }
    }
    return dud;
}
int bellmanFORD(int vectorNUM,int source,int**weight,int**d)
{
    *(*(d+source)+source) = 0;
    // for(int i=0;i<vectorNUM;i++)
    // {
    //     for(int j=0;j<vectorNUM;j++)
    //     {
    //         cout << *(*(weight+i)+j) << " ";
    //     }
    //     cout << endl;
    // }
    // for(int i=0;i<vectorNUM;i++)
    // {
    //     for(int j=0;j<vectorNUM;j++)
    //     {
    //         cout << *(*(d+i)+j) << " ";
    //     }
    //     cout << endl;
    // }
   
    for(int i =0;i<=vectorNUM-2;i++)
    {
        for(int j=0;j<vectorNUM;j++)
        {
            for(int end:edge[j])
            {
                //cout <<*(*(d+i)+j)+*(*(weight+j)+end)<<endl;
                *(*(d+i+1)+end) = min(*(*(d+i)+end),*(*(d+i+1)+end),*(*(d+i)+j)+*(*(weight+j)+end));
            }
        }
    }
    // for(int i = 0;i<vectorNUM;i++)
    // {
    //     cout << *(*(d+vectorNUM-2)+i)<<endl;
    //     cout << *(*(d+vectorNUM-1)+i)<<endl;
    //     cout<<endl;
    // }
    for(int i = 0;i<vectorNUM;i++)
    {
        if(*(*(d+vectorNUM-1)+i) != *(*(d+vectorNUM-2)+i))
        {
            return 0;
        }
        
    }
    return 1;
    
}
int main(int argc,char **argv){
    int vectors,edge1,weight,decision;
    cin >> vectors;
    cin >> edge1;
    int * vectorBEG = (int*)malloc(edge1*sizeof(int));
    int * vectorEND = (int*)malloc(edge1*sizeof(int));
    int ** weights1 = (int**)malloc((vectors)*sizeof(int*));
    int ** d = (int**)malloc((vectors+1)*sizeof(int*));
    for(int i=0;i<vectors;i++)
    {
        *(weights1+i) = (int*)malloc(vectors*sizeof(int));
        *(d+i) = (int*)malloc(vectors*sizeof(int));
    }
    for(int i=0;i<vectors;i++)
    {
        for(int j=0;j<vectors;j++)
        {
            *(*(weights1+i)+j) = 0;
            *(*(d+i)+j) = INT_MAX-100000;
        }
    }
    for(int i=0;i<edge1;i++)
    {
        cin>>*(vectorBEG+i);
        cin>>*(vectorEND+i);
        //DIRECTED
        edge[*(vectorBEG+i)].push_back(*(vectorEND+i));
        //edge[*(vectorEND+i)].push_back(*(vectorBEG+i));
        cin>> weight;
        //STORE WEIGHTS
        *(*(weights1+*(vectorBEG+i))+*(vectorEND+i)) = weight;
        //*(*(weights1+*(vectorEND+i))+*(vectorBEG+i)) = weight;
    }
    decision = bellmanFORD(vectors,0,weights1,d);
    //unsigned int dud = -1;
    //(int)dud;
    //cout<<(int)dud;
    if(decision!=0)
    {
        cout<<"TRUE"<<endl;
        for(int i = 0;i<vectors;i++)
        {
            if(*(*(d+vectors-1)+i) >= INT_MAX-100000)
            {
                cout <<"INFINITY"<<endl;
            }
            else
            {
                cout << *(*(d+vectors-1)+i)<<endl;
            }
        }
    }
    else{
        cout<<"FALSE"<<endl;
    }
    
    // for(int i=0;i<vectors;i++)
    // {
    //     for(int j=0;j<vectors;j++)
    //     {
    //         cout << *(*(weights1+i)+j) << " ";
    //     }
    //     cout << endl;
    // }

}