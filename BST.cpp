#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <math.h>  
using namespace std;

struct Leaf_node{
	int val;
	Leaf_node *left_child;
	Leaf_node *right_child;
}; 
struct Leaf_node *root;
int size=0;
class BST{
	public:
		
		struct Leaf_node * create_Node(int val){
			struct Leaf_node *node = new struct Leaf_node;
			
			node->val = val;
			node->left_child = NULL;
			node->right_child = NULL;
			return node;
		}

		void search_for_spot(Leaf_node *temp_root, int val){
			if(temp_root->val > val){
				if(temp_root->left_child == NULL){
					temp_root->left_child = create_Node(val);
					cout<<"A left child was made"<<endl;
				}
				else
					search_for_spot(temp_root->left_child, val);
			
			}
			else{
				if(temp_root->right_child == NULL){
					temp_root->right_child = create_Node(val);
					cout<<"A right child was made"<<endl;
				}
				else{
					search_for_spot(temp_root->right_child, val);
				}
			}
		}

		void insert_node(int val){
			size++;
			if(root == NULL){
				root = create_Node(val);
				cout<<"root was set"<<endl;
			}
			else{
				search_for_spot(root, val);
			}
		}
		double depth_of_Tree(){
			return ceil(log2(size));
		}
		void preOrder(Leaf_node *node){
			if(node == NULL){
				return;
			}
			cout<< node->val;
			if(node->left_child != NULL)
				preOrder(node->left_child);
			if(node->right_child != NULL)
				preOrder(node->right_child);
			return;

		}
		void postOrder(Leaf_node *node){
			if(node == NULL)
				return;
			if(node->left_child != NULL)
				postOrder(node->left_child);
			
			if(node->right_child != NULL)
				postOrder(node->right_child);
			cout<< node->val;
			return;
		}
		void inOrder(Leaf_node *node){
			if(node == NULL)
				return;
			if(node->left_child != NULL)
				inOrder(node->left_child);
			cout<< node->val;
			if(node->right_child != NULL)
				inOrder(node->right_child);
			return;
		}
		void Order(int choice){
			Leaf_node *node = root;
			if(choice == 3)
				preOrder(node);
			else if(choice == 4)
				postOrder(node);
			else
				inOrder(node);
		}
};

int main(){
	 BST tree;
    int val;
    int choice;

    while (1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Stack"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Add element to BST"<<endl;
        cout<<"2.Return depth of BST"<<endl;
        cout<<"3.Print Pre Order"<<endl;
        cout<<"4.Print Post Order"<<endl;
        cout<<"5.Print In Order"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        	cout<<"Enter value to be inserted into BST: ";
        	cin >> val;
        	tree.insert_node(val);
        	break;
        case 2:
            cout<<"The depth of the dree is: "<< tree.depth_of_Tree();
            
            break;
        case 3:
        	cout<<"The Pre Order of the tree is: ";
        	tree.Order(choice);
        	break;
        case 4:
        	cout<<"The Post Order of the tree is: ";
        	tree.Order(choice);
        	break;
        case 5:
        	cout<<"The In Order of the tree is: ";
        	tree.Order(choice);
        	break;

        case 6:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}
