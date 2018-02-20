#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

struct Stack_node{
	 	int val; 
	 	Stack_node *next;
	};
	Stack_node *top;
class Stack{
	public:
	int pop(){
		int val = top->val;
		top = top->next;
		return val;

	}
	void push(int val){
		Stack_node *node_to_push =  new  struct Stack_node;
		node_to_push->val = val;
		node_to_push->next = top;
		top = node_to_push; 
	}

	int peek(){
		return top->val;
	}
	bool isEmpty(){
		if (top == NULL)
			return true;
		return false; 
	}
	void printStack(){
		Stack_node *temp_head = top;
		while(temp_head != NULL){
			cout<<temp_head->val<<" ";
			temp_head = temp_head->next;
		}
			
	}

};


int main()
{
    Stack stack;
    int val;
    int choice;
    while (1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Stack"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Pop element from Stack"<<endl;
        cout<<"2.Push element into Stack"<<endl;
        cout<<"3.Peek at top of Stack"<<endl;
        cout<<"4.Check if Stack is empty"<<endl;
        cout<<"5.Print the Stack"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        	if(stack.isEmpty()){
        		cout<<"Stack is empty, Nothing to pop"<<endl;
        		break;
        	}
        	else{
	           cout<<"The element that was popped was: " << stack.pop() << endl;
	            break;
	        }
        case 2:
            cout<<"Enter element to be pushed: ";
            cin>>val;
            stack.push(val);
            break;
        case 3:
        	if(stack.isEmpty()){
        		cout<<"Stack is empty, Nothing to peek"<<endl;
        		break;
        	}
        	else{
           		cout<<"The element at the top of the stack is: "<< stack.peek() <<endl;
           		 break;
           	}
        case 4:
        	if(stack.isEmpty()){
        		cout<<"Stack is empty"<<endl;
        	}
        	else
        		cout<<"Stack is not empty"<<endl;
        	break;
        case 5:
        	if(stack.isEmpty()){
        		cout<<"Stack is empty, Nothing to print"<<endl;
        	}
        	else
        		cout<<"The Stack contains the following elements: ";
        		stack.printStack();
        	break;

        case 6:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}

