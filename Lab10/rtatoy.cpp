#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <limits.h>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

map<int,vector<int>> edge,edgeREV;
//container with stored elements with combination of values associated with elements
//unordered_map<int,vector<int>> edge,edgeREV;
void DFS(int i, vector<int>&visit,stack<int>&theSTACK, int kind,int & minVALUE,int * printSAVE,int *save,int & counter)
{
    //First DFS
    if(kind == 1)
    {
        visit[i] = true;
        for(int j: edge[i]) //every edge
        {
            // cout << i << endl;
            // cout << j << endl;
            // cout << endl;
            if(visit[j]==false)
            {
                //cout << j << endl;
                DFS(j,visit,theSTACK,kind,minVALUE,printSAVE,save,counter);
            }
        }
        theSTACK.push(i);
    }
    else{
        //Second DFS
        *(save+counter) = i;//copies which vector is in the specific SCC
        
        counter++;
        if(minVALUE > i)
        {
            minVALUE = i;
        }
        for(int j = 0; j <counter;j++)
        {
            *(printSAVE+*(save+j)) = minVALUE;//save to print for print later
        }
        
        visit[i] = true;
        for(int j: edgeREV[i])//every transpose edge
        {
            
            if(visit[j]==false)
            {
                
                DFS(j,visit,theSTACK,kind,minVALUE,printSAVE,save,counter);
            }
        }
    }
}

void strongconnectedCOMP(int numVectors)
{
    stack<int> theSTACK;
    stack<int> theSTACK1;
    vector<int> visit(numVectors,false);
    int * save = (int*)malloc(numVectors*sizeof(int));
    int * printSAVE = (int*)malloc(numVectors*sizeof(int));
    int minValue = 0;
    int counter = 0;
    //DFS
    for(int i=0;i<numVectors;i++)
    {
        if(visit[i]==false)
        {
            // cout << i << endl;
            DFS(i,visit,theSTACK,1,minValue,printSAVE,save,counter);
        }
    }
    //reverse
    for(int i = 0; i <numVectors;i++)
    {
        for(int j: edge[i])
        {
            edgeREV[j].push_back(i);
        }
    }
    theSTACK1 = theSTACK;
    for(int i=0;i<numVectors;i++)
    {
        visit[i] = false;
        
    }
    // while(!theSTACK1.empty())
    // {
    //     cout <<theSTACK1.top() <<endl;
    //     theSTACK1.pop();
    // }
    //DFS
    while(!theSTACK.empty())
    {
        int numNODE = theSTACK.top();
        minValue = INT_MAX;
        counter = 0;
        theSTACK.pop();
        if(visit[numNODE] == false)
        {
            
            DFS(numNODE,visit,theSTACK,2,minValue,printSAVE,save,counter);
            
        }
        
    }
    //Print
    for(int i = 0;i<numVectors;i++)
    {
        cout << *(printSAVE+i);
        cout <<endl;
    }
}
int main(int argc,char **argv)
{
    //Collect information
    int vectors,edge1;
    cin >> vectors;
    cin >> edge1;
    int * vectorBEG = (int*)malloc(edge1*sizeof(int));
    int * vectorEND = (int*)malloc(edge1*sizeof(int));
    int * print = (int*)malloc(edge1*sizeof(int));
    for(int i=0;i<edge1;i++)
    {
        cin>>*(vectorBEG+i);
        cin>>*(vectorEND+i);
        edge[*(vectorBEG+i)].push_back(*(vectorEND+i));
        
    }
    strongconnectedCOMP(vectors);
    // for (auto x : edge)
    // {
    //     cout << x.first << " " << x.second[0] << endl;
    //     if(x.second.size()>1)
    //     {
    //         cout << x.first << " " << x.second[1] << endl;
    //     }
    //     else if(x.second.size()>2)
    //     {
    //         cout << x.first << " " << x.second[3] << endl;
    //     }
    // }
    // for (auto x : edge)
    // {
    //     cout << x.first << " " << x.second[1] << endl;  
    // }
        
    

}