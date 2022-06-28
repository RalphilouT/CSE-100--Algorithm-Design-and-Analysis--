#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;
struct Node{
	long data;
	Node* next;
	Node* prev;
	Node (){
		data = 0;
		next = NULL;
	}

	Node (long n){
		data = n;
		next = NULL;
	}
};
struct LinkedList{

	Node* head;
	Node* last;

	LinkedList(){
		head = NULL;
		last = NULL;
	}
    // LinkedList(const LinkedList& other){ 
	// 	head = NULL;

	// 	if (other.head != NULL){
	// 		Node* temp = other.head;
	// 		while (temp != NULL){
	// 			append(temp->data);
	// 			temp = temp->next;
	// 		}
	// 	}

	// 	last = other.last;
	// }
    
    
    void deleting(int index, int value)
	{	
		Node * node = head;
		if(head == NULL)
		{
			cout<<value<<":DELETE_FAILED;"<<endl;
			return;
		}
		if(index ==0)
		{
			
			Node * oldNode = head;
			oldNode = oldNode->next;
			head = oldNode;
			cout << value <<":DELETED;"<<endl;
		}
		else{
			Node * temp1 = head;
			Node * deleting;
			for(int i=0; i < index-1;i++)
			{
				temp1 = temp1->next;
			}
			if(temp1->next ==NULL)
			{
				cout<<value<<":DELETE_FAILED;"<<endl;
				return;
			}
			cout << value <<":DELETED;"<<endl;
			deleting = temp1->next;
			if(deleting->next == NULL)
			{
				temp1->next = NULL;
			}
			temp1->next = deleting ->next;
		}

	}
    void append (long n){
		if (head == NULL){
			head = new Node(n);
			last = head;
		}
		else{
			Node* theNode = new Node(n); 
			last->next = theNode;
			last = last->next;
		}
	}
	int get(int index)
	{
		Node * temp = head;
		for(int i=0; i < index;i++)
		{
			temp = temp->next;
		}
		return temp->data;
	}
    void insert(long n){
		Node* temp = new Node(n);
		temp->next = head;
		head = temp;
	}
    
    
    bool search(int value,int where,int &j){
		Node* temp = head;
		j = 0;
		while (temp != NULL){
			if (temp->data == value){
				
				return true;
			}
			j++;
			temp = temp->next;
		}
		
		return false;
	}
    void print()
	{
		Node *temp = head;
		// if(temp == NULL)
		// {
		// 	//cout <<';';
		// }
		while(temp != NULL)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		
		cout <<';';
	}
	
	// bool operator==(const LinkedList& other) const {
	// 	Node* ours = head;
	// 	Node* theirs = other.head;

	// 	while (ours != NULL){
	// 		if (theirs == NULL){
	// 			return false;
	// 		}
	// 		if (ours->data != theirs->data){
	// 			return false;
	// 		}
	// 		else{
	// 			ours = ours->next;
	// 			theirs = theirs->next;
	// 		}
	// 	}
	// 	return theirs == NULL;
	// }
    // ~LinkedList(){
	// 	Node* temp = head;
	// 	while (temp != NULL){
	// 		head = head->next;
	// 		delete temp;
	// 		temp = head;
	// 	}
	// }
};
// ostream& operator<< (ostream& os, const LinkedList& theList){
// 	Node* temp = theList.head;
// 	while (temp != NULL){
// 		os << temp->data << " ";
// 		temp = temp->next;
// 	}
// 	return os;
// }
int f(int key, int mod)
{
	return key % mod;
}
int main(int argc,char **argv)
{
    int m;
	int x,j;
	int where;
	int answer,answer1;
	string input = "";
    cin >> m;
	int myint1;
    LinkedList * mylist = (LinkedList*) malloc(m*sizeof(LinkedList));
	while(input != "e")
	{
		cin >> input;
		if(input[0] == 'i')
		{
			input.erase(input.begin() + 0);
			x = stoi(input);
			answer = f(x,m);
			mylist[answer].insert(x);
		}
		else if(input[0] == 'o')
		{
			for(int i = 0 ; i<m;i++)
			{
				cout << i <<':';
				mylist[i].print();
				cout << endl;
			}
			
		}
		else if (input[0]=='d')
		{
			input.erase(input.begin() + 0);
			x = stoi(input);
			answer = f(x,m);
			answer1 = mylist[answer].search(x,answer,j);
			mylist[answer].deleting(j,x);
		}
		else if(input[0] == 's')
		{
			
			input.erase(input.begin() + 0);
			x = stoi(input);
			answer = f(x,m);
			(answer1) = mylist[answer].search(x,answer,j);
			if(answer1 == true)
			{
				cout << x << ":FOUND_AT" <<answer<<',' << j << ';' <<endl;
			}
			else if(answer1 == false)
			{
				cout << x << ":NOT_FOUND;" <<endl;
			}

		}
		

	}
	
}