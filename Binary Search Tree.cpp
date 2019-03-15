//Including libraries
#include<iostream>
using namespace std;

//declaring class Node
class Node{
	public:
	//declaring the data and two pointers of each node
	int data;
	Node* left;
	Node* right;
	//default constructor to initialize NULL value to the pointers and 0 to the data
	Node(){
		data=0;
		left=NULL;
		right=NULL;
	}
};

//Declaring class BST (Binary Search Tree)
class BST{
	public:
	//delcaring root pointer to point to the first element of the tree, which has no parents
	Node* root;
	//default constructor to initialize root by NULL
	BST(){
	root=NULL;
	}
	public:

	//writing function to insert values, by calling a function insertHelper 
	void insert(int value){
		//passing starting node address and value to be input to insertHelper
		insertHelper(root, value);
	}
	//function which will actually insert the values by recursion
	void insertHelper(Node* current, int value){
		//first condition to check if binary tree is empty
		if(current==NULL){
			//new node formed and data stored
			current=new Node;
			current->data=value;
			//storing address of new node in root, making it the first node
			if(root==NULL) root=current;
			return;
		}
		//if tree is not empty
		else{
			//if the value to be inserted is lesser than the node, then moving left to insert it
			if(current->data>value){
				//if left of current Node is NULL insert it.
				if(current->left==NULL) {	
					current->left=new Node;
					current->left->data=value;
				}
				//if left of current node is not NULL, then move left till we reach appropriate node
				else insertHelper(current->left, value); //recursive function call
			}
			//if value to be inserted is greater than the node, then moving right
			if(current->data<value){
				//if right of current Node is NULL, insert it
				if(current->right==NULL){
					current->right=new Node;
					current->right->data=value;
				}
				// if right of current node is not NULL, then move right 
				else insertHelper(current->right, value); //recursive funtion call
			}
		}
	}

	//function to display binary search tree using another function display2
	void display(){
		//passing starting address to display2
		display2(root);
	}
	//funtion which actually displays the binary search tree elements in increasing order (or decreasing, as per code) by using recursion
	void display2(Node* current){
		//Base concdition
		//if current is NULL, then the function returns as there is nothing left to print
		if(current==NULL) return;
		//recursively calling function and moving it to the left of the tree, the function finishes the left half of each tree first
		display2(current->left);
		//displaying the data of current node, gets executed as the function returns, so left side first then right
		cout<<current->data<<",";
		//recursively calling function and moving it towards right of the tree
		display2(current->right);
	}

	//writing function to search for a particular value in the tree using a function search1
	Node* search(int value){
		//passing starting address and value to search to function search1
		return search1(value, root);
	}
	//function which will actually search the data in the tree using recursion
	Node* search1(int value1, Node* current){
		//search continues in some direction untio the fuction hits NULL, so if not NULL, then move appropriately in either direction or return the value if it matches with the search value 
		if(current!=NULL){
			//if value to search is lesser than the value of the current node, then moving function to the left of the node, recursively
			if(current->data>value1) search1(value1,current->left);
			//if value to search is greater than the value of the current node, then moving function to the right of the node, recursively
			if(current->data<value1) search1(value1,current->right);
			//if value to search matches the value of the current node, then returning the address of the current node
			if(current->data==value1) return current;
		}
	}						
};

//writing main/driver function
int main(){
	//declaring object of class BST
	BST b1;
	//inserting values
	b1.insert(7);
	b1.insert(6);
	b1.insert(3);
	b1.insert(9);
	b1.insert(2);
	b1.insert(1);
	//displaying the binary search tree in ascending order
	b1.display();
	cout<<endl;
	//searching for value 9 in the binary serach tree
	//if the value returned is not NULL, then required element found
	if(b1.search(9) != NULL) cout<<"Search element found."<<endl;
	//if value returned is NULL, then required element not found.
	else cout<<"Search element not found."<<endl;
	//retuirning any integer value to main function
	return 0;
}
