
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

struct node{
	int val;
	node* next;
}; struct node *root;

class LinkedList{
	
	public:

	struct node* create_Node(int val){ // create new node
		struct node *new_node = new (struct node);
		new_node->val = val;
		new_node->next = NULL;
		return new_node;
	}
	void add_Node(int val){
		if(root == NULL){
			root = create_Node(val);
		}
		else{
			struct node *node_to_be_added = create_Node(val);
			struct node *temp_root = root;
			while(temp_root->next != NULL)
				temp_root = temp_root->next; 
			temp_root->next = node_to_be_added;
		}
	}
	bool delete_Node_by_value(int val){
		struct node *temp_root = root;
		if(temp_root->val == val){
			root = root->next;
			return true;
		}
			
		while(temp_root->next != NULL){
			if(temp_root->next->val == val){
				temp_root->next = temp_root->next->next;
				return true;
			} 
			temp_root = temp_root->next;
		} 
		return false;
	}
	bool search_by_element(int val){
		struct node *temp_root = root;
		while(temp_root != NULL){
			if(temp_root->val ==  val){
				return true;
			}
			temp_root = temp_root->next;
		} return false;
	}
	bool isEmpty(){
		return root == NULL;
	}
	void printList(){
		struct node *temp_root = root;
		while(temp_root != NULL){
			cout<<temp_root->val<<" ";
			temp_root = temp_root->next;
		}
			
	}

};

int main() //TODO: add functionality 
{
    LinkedList list;
    int val;
    int choice;
    while (1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Stack"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Add element to LinkedList"<<endl;
        cout<<"2.Delete element from LinkedList"<<endl;
        cout<<"3.Search for element in LinkedList"<<endl;
        cout<<"4.Check if LinkedList is empty"<<endl;
        cout<<"5.Print LinkedList"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        		cout<<"Enter value to be added to list: ";
        		cin >> val;
        		list.add_Node(val);
	            break;
	        
        case 2:
        	if(list.isEmpty()){
        		cout<<"List is Empty, Nothing to be deleted"<<endl;
        		break;
        	}
        	else{
        		cout<<"Enter element to be deleted: ";
	            cin>>val;
	            if(list.delete_Node_by_value(val))
	            	cout<<"Element "<< val<< " was deleted"<<endl;
	            else
	            	cout<<"Element "<< val<< " was not deleted because it is not in list"<<endl;
	            break;
        	}
            
        case 3:
        	if(list.isEmpty()){
        		cout<<"List is empty, Nothing to searched"<<endl;
        	}
        	else{
        		cin >> val;
        		if(list.search_by_element(val))
           			cout<<"The element is in the list"<<endl;
           		 else{
           		 	cout<<"The element is not in the list"<<endl;
           		 }
           	}
           	break;
        case 4:
        	if(list.isEmpty()){
        		cout<<"List is empty"<<endl;
        	}
        	else
        		cout<<"List is not empty"<<endl;
        	break;
        case 5:
        	if(list.isEmpty()){
        		cout<<"List is empty, Nothing to print"<<endl;
        	}
        	else{
        		cout<<"The List contains the following elements: ";
        		list.printList();
        	}
        	break;

        case 6:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}


