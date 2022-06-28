#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;
struct Node{
	long data;
    char letters;
	Node* left;
	Node* right;
    Node()
    {
        data = INT_MIN;
        left = NULL;
        right = NULL;
    }
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    void NodeRight(int value)
    {
        right->data = value;
    }
    void NodeLeft(int value)
    {
        left->data = value;
    }
};
struct NodeH
{
    Node * root,*temp;
    NodeH()
    {
        root = NULL;
    }
    Node * initialize(Node*root)
    {
        
        root = new Node();
        return root;
        
    }
    Node * insert(Node*root,int value1,int value2,Node * combine)
    {
        //combine = NULL;
        if(root == NULL)
        {
            root = new Node(value1);
            //combine = new Node(value1); 
        }
        else{
            if(combine != NULL)
            {
                Node * temp1 = new Node(value1 + value2);
                //traverse(root);
                if(value1 <= value2) 
                {
                    if(combine->data == value1)
                    {
                        temp1->left = combine;
                        temp1->right = root;
                        root = temp1;
                        
                        
                    }
                    else if(combine->data == value2)
                    {
                        temp1->right = combine;
                        temp1->left = root;
                        root = temp1;
                        
                    }
                    
                }
                else if(value2 < value1)
                {
                    if(combine->data == value1)
                    {
                        temp1->right = combine;
                        temp1->left = root;
                        root = temp1;
                        
                        
                    }
                    else if(combine->data == value2)
                    {
                        temp1->left = combine;
                        temp1->right = root;
                        root = temp1;
                        
                        
                    }
                    
                }
                //traverse(root);
                return root;
            }
            else if(value1 < value2)
            {
                combine = new Node(value1+value2);
                // if(combine != NULL){
                    
                // }
                //else if(root->data == value1)
                if(root->data == value1)
                {
                    // root->left = root;
                    // temp = new Node(value2);
                    //root->right = temp;
                    combine->left = root;
                    temp = new Node(value2);
                    combine->right = temp;
                    root = combine;

                }
                else if (root->data == value2)
                {
                    // root->right = root;
                    // temp = new Node(value1);
                    // root->left = temp;
                    combine->right = root;
                    temp = new Node(value1);
                    combine->left = temp;
                    root = combine;
                }
                else{
                    temp = new Node(value1);
                    root->left = temp;
                    temp = new Node(value2);
                    root->right = temp;
                    //root = combine;
                    // temp = new Node(value1);
                    // root->left = temp;
                    // temp = new Node(value2);
                    // root->right = temp;
                }
            }
            else if (value1 > value2)
            {
                combine = new Node(value1+value2);
                // if(combine != NULL)
                // {

                // }
                // else if(root->data == value1)
                if(root->data == value1)
                {
                    // root->right = root;
                    // temp = new Node(value2);
                    // root->left = temp;
                    combine->right = root;
                    temp = new Node(value2);
                    combine->left = temp;
                    root = combine;
                }
                else if (root->data == value2)
                {
                    // root->left = root;
                    // temp = new Node(value1);
                    // root->right = temp;
                    combine->left = root;
                    temp = new Node(value1);
                    combine->right = temp;
                    root = combine;
                }
                else{
                    temp = new Node(value1);
                    root->right = temp;
                    temp = new Node(value2);
                    root->left = temp;
                    // temp = new Node(value1);
                    // root->right = temp;
                    // temp = new Node(value2);
                    // root->left = temp;
                }
            }
            
        }
        //root = combine;
        return root;
    }
    void codes(Node * root, int arr[], int top,char letter,int whatLetter,int * arr1)
    {
        //looks at left node
        if (root->left) {
    
            arr[top] = 0;
            codes(root->left, arr, top + 1,char('A'+whatLetter),whatLetter,arr1);
        }
        //looks at right node
        if (root->right) {
    
            arr[top] = 1;
            codes(root->right, arr, top + 1,char('A'+whatLetter),whatLetter,arr1);
        }
        //looks at if the current node is a leaf
        if (leaf(root)) {
            if(arr1[whatLetter] == root->data)//checks if the root is the same as the letter
            {
                cout << char('A'+whatLetter)<<':';
                printArr(arr, top);
            }
        }
    }
    void printArr(int arr[], int n)
    {
        //print arr
        for (int i = 0; i < n; ++i)
        {
            cout<< arr[i];
        }
        cout<<"\n";
    }
    int leaf(Node * root)
    {
        return !(root->left) && !(root->right);//checks if the node is a leaf
    }
    void traverse(Node * root){
        //traverse
        if (root != NULL){
            traverse(root->left);
            std::cout << root->data << std::endl;
            traverse(root->right);
        }
    }
};
int extractMIN(int*arr1,int size,int & point)
{
    //extract min
    int new1 = size - 1;
    int * tempARR = (int*) malloc (new1*sizeof(int));
    int min = INT_MAX;
    for(int i =0;i<size;i++)
    {
        if(min > *(arr1+i))
        {
            min = *(arr1+i);
            point = i;
        }
    }
    *(arr1+ point) = INT_MAX;
    return (min);
}




int main(int argc,char **argv)
{
    //Collect information
    int symbols = 6;
    int symbols1 = symbols;
    int min1,min2,root1,point1,point2;
    int j = 1,point;
    int dummy = INT_MAX;
    NodeH HussTree[10];
    for(int i = 0;i<10;i++)
    {
        HussTree[i].root = HussTree[i].initialize(HussTree[i].root);
    }
    int *arr = (int*)malloc(symbols*(sizeof(int)));
    int *arr1 = (int*)malloc(symbols*(sizeof(int)));
    //char * letters = (char*)malloc(symbols*(sizeof(char)));
    char arr2[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
    //cout<<char('A'+1);
    for(int i = 0; i<6;i++)
    {
        cin >> *(arr+i);
        *(arr1+i) = *(arr+i);
    }
    // for(int i = 0; i<6;i++)
    // {
    //     cout << *(arr+i)<<endl;
    // }
    // cout << symbols1<<endl;
    // cout << endl;
    
    HussTree[9].root= NULL;
    HussTree[0].root = NULL;
    //extract initial two minimum
    (min1) = extractMIN(arr,symbols,point);
    (min2) = extractMIN(arr,symbols,point);
    root1 = min1 + min2;
    //make tree as the addition of both is the parent
    HussTree[0].root = HussTree[0].insert(HussTree[0].root,root1,0,HussTree[9].root);
    HussTree[0].root = HussTree[0].insert(HussTree[0].root,min1,min2,HussTree[9].root);
    //make parent or root to be in list of value left
    *(arr+point) = HussTree[0].root->data;
    symbols1--;
    HussTree[9].root = HussTree[9].initialize(HussTree[9].root);//Make not out of bounds so can use to comparison
    //Do for all values in arr
    while(symbols1 > 1)
    {
        //HussTree[9].root = NULL;
        (min1) = extractMIN(arr,symbols,point);
        (min2) = extractMIN(arr,symbols,point);

        if((min1 == HussTree[0].root->data) && min2 != HussTree[j].root->data)
        {
            root1 = HussTree[0].root->data + min2;
            HussTree[9].root = NULL;
            HussTree[0].root = HussTree[0].insert(HussTree[0].root,min1,min2,HussTree[9].root);
            *(arr+point) = HussTree[0].root->data;
            symbols1--;
            HussTree[9].root = HussTree[9].initialize(HussTree[9].root);
        }
        else if(min1 == HussTree[j].root->data && min2 != HussTree[0].root->data)
        {
            //HussTree[j].traverse(HussTree[j].root);
            root1 = HussTree[j].root->data + min2;
            HussTree[9].root = NULL;
            HussTree[j].root = HussTree[j].insert(HussTree[j].root,min1,min2,HussTree[9].root);
            *(arr+point) = HussTree[j].root->data;
            symbols1--;
            HussTree[9].root = HussTree[9].initialize(HussTree[9].root);
            //HussTree[9].root = HussTree[j].root;
            
     
        }
        else if(min2 == HussTree[j].root->data && min1 != HussTree[0].root->data)
        {
            
            root1 = min1 + HussTree[j].root->data;
            HussTree[9].root = NULL;
            HussTree[j].root = HussTree[j].insert(HussTree[j].root,min1,min2,HussTree[9].root);
            *(arr+point) = HussTree[j].root->data;
            symbols1--;
            HussTree[9].root = HussTree[9].initialize(HussTree[9].root);
            //HussTree[9].root = HussTree[j].root;
            //HussTree[9].traverse(HussTree[9].root);
        }
        else if ((min2==HussTree[0].root->data) && min1 != HussTree[j].root->data)
        {
            root1 = min1 + HussTree[0].root->data;
            HussTree[9].root = NULL;
            HussTree[0].root = HussTree[0].insert(HussTree[0].root,min1,min2,HussTree[9].root);
            *(arr+point) = HussTree[0].root->data;
            symbols1--;
            HussTree[9].root = HussTree[9].initialize(HussTree[9].root);
            
            
        }
        else if((min1==HussTree[0].root->data || min2 ==HussTree[0].root->data)&&(min1==HussTree[j].root->data || min2==HussTree[j].root->data))
        {
            HussTree[0].root = HussTree[0].insert(HussTree[0].root,min1,min2,HussTree[j].root);
            symbols1--;
            *(arr+point) = HussTree[0].root->data;
            
            //HussTree[1].traverse(HussTree[1].root);
        }
        else{
            root1 = min1 + min2;
            HussTree[9].root = NULL;       
            j++;
            HussTree[j].root = HussTree[0].root;
            HussTree[0].root = NULL;
            HussTree[0].root = HussTree[0].insert(HussTree[0].root,root1,0,HussTree[9].root);
            HussTree[0].root = HussTree[0].insert(HussTree[0].root,min1,min2,HussTree[9].root);
            symbols1--;
            *(arr+point) = HussTree[0].root->data;
            //HussTree[9].root = HussTree[j].root;
            
        }
        //HussTree[1].traverse(HussTree[1].root);
        
        

    }
    //print
    int arr3[100];
    for(int i = 0; i<6;i++)
    {
        HussTree[0].codes(HussTree[0].root,arr3,0,arr2[i],i,arr1);
    }
    
}
