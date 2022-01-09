//#include<iostream>
//using namespace std;

template <class type>
class Stack {
private:
     // creating node for singly linked list = | data | next |
    class Node {
    public:
        type data;
        Node *next;

        Node(type data) {
            this->data = data;
            this->next = NULL;
        }
    };

    // creating head pointer and top pointer
    Node *head = NULL;
    Node *top = NULL;

    int size;

public:
	Stack() {
		size = 0;
	}
    // if head is null then the stack is empty
    bool isEmpty() {
        return head == NULL;
    }

    // pushing element in stack
    void push(type n) {
        if(isEmpty()) { // if the stack is empty then assign new node to head
            Node *newNode = new Node(n);
            head = newNode;
            top  = head;
        } else {
            Node *newNode = new Node(n);
            top->next = newNode;
            top = newNode;
        }
        size ++;
    }

    // popping element form stack and returning it
    type pop() {
        if(!isEmpty()){ // if the stack is not empty then perform pop operation
            type removed = top->data;
            if(head != top) {
                //Node *temp = top->previous;
				Node *temp = head;
				while(temp->next != top) {
					temp = temp->next;
				}
				
                temp->next = NULL;
                // deleting element
                delete top;
                top = temp;

                size --;
            } else {
                delete top;
                top = head = NULL;
            }

            return removed;
        }
        return 0;
    }

//    void display() {
//        if(!isEmpty()) { // if the stack is not empty then perform display operation
//            Node *pre = top;
//            cout<<endl;
//            while(pre != NULL) {
//                cout<<" |\t"<<pre->data<<"\t|"<<endl;
//                pre = pre->previous;
//            }
//            cout<<"--------------------"<<endl;
//        } else {
//            cout<<endl<<"Stack is Empty"<<endl;
//        }
//    }

    int getSize() { // return the size of array
        return size;
    }

    type peek() { // return top element
        if(!isEmpty()) {
            return top->data;
        }
    }
};


