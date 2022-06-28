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
void findingMST(int numVECTORS,int parent,int**values)
{
    //cout <<"her";
    int counter = numVECTORS;
    vector<int> visit(numVECTORS,false);
    int * save = (int*)malloc(numVECTORS*sizeof(int));
    int min = INT_MAX;
    int oldP = parent;
    visit[parent] = true;
    while(counter>=0)
    {   
        //FOR EVERY ITERATION, YOU ARE LOOKING FOR MIN VALUES
        min = INT_MAX;
        //oldP = parent;
        for(int i=0;i<numVECTORS;i++)
        {
            if(visit[i]==true)
            {
                //OUTPUTS ALL THE NODES NODE I CAN GET TO J
                for(int j:edge[i])
                {
                    if(visit[j]==false)
                    {
                        //FINDING THE MIN AND UPDATES IF IT IS BIGGER THAN THE ONE WE ARE LOOKING AT
                        if(min > *(*(values+i)+j))
                        {
                            min = *(*(values+i)+j);
                            parent = j;
                            oldP = i;
                            // cout << oldP<<" ";
                            // cout << parent<< " ";
                            // cout << min;
                            // cout<<endl;
                            
                        }
                    }
                }
            }
        }
        // cout << oldP<<" ";
        // cout << parent<< " ";
        // cout << min;
        // cout<<endl;
        //WHEN MIN VALUE IS FOUND, YOU ALSO SAVED THE PARENT AND OLD P 
        // FOR SAVE AND MAKING THE NEWLY FIND PATH TO A NODE TRUE STATEMENT SO WE DO NOT MAKE A LOOP
        *(save+parent) = oldP;
        visit[parent] = true;
        //EVERYTIME A NODE IS ADDED TO MST, IT WILL REDUCT THE NUMBER
        counter--;
    }
    for(int i=1;i<numVECTORS;i++)
    {
        cout << *(save+i)<<endl;
    }
    //visit[parent] = true;
}
int main(int argc,char **argv){
    int vectors,edge1,weight;
    cin >> vectors;
    cin >> edge1;
    int * vectorBEG = (int*)malloc(edge1*sizeof(int));
    int * vectorEND = (int*)malloc(edge1*sizeof(int));
    int ** weights1 = (int**)malloc(vectors*sizeof(int*));
    for(int i=0;i<vectors;i++)
    {
        *(weights1+i) = (int*)malloc(vectors*sizeof(int));
    }
    for(int i=0;i<vectors;i++)
    {
        for(int j=0;j<vectors;j++)
        {
            *(*(weights1+i)+j) = 0;
        }
    }
    for(int i=0;i<edge1;i++)
    {
        cin>>*(vectorBEG+i);
        cin>>*(vectorEND+i);
        //UNDIRECTED
        edge[*(vectorBEG+i)].push_back(*(vectorEND+i));
        edge[*(vectorEND+i)].push_back(*(vectorBEG+i));
        cin>> weight;
        //STORE WEIGHTS
        *(*(weights1+*(vectorBEG+i))+*(vectorEND+i)) = weight;
        *(*(weights1+*(vectorEND+i))+*(vectorBEG+i)) = weight;
    }
    // for(int i=0;i<vectors;i++)
    // {
    //     for(int j: edge[i])
    //     {
    //         cout << j <<endl;
    //     }
    //     cout << endl;
    // }
    // for(int i=0;i<vectors;i++)
    // {
    //     for(int j=0;j<vectors;j++)
    //     {
    //         cout << *(*(weights1+i)+j) << " ";
    //     }
    //     cout << endl;
    // }
    int root = 0;
    findingMST(vectors,root,weights1);
}