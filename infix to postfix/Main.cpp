#include<iostream>
using namespace std;

#include "stack.h"
#include "infixToPostfix.h"

int main() {
    string infix;
    string postfix;

    //infix = "(a+b*c)+c/d";
	cout<<"Enter any Infix Expression:"<<endl<<">\t";
	cin>>infix;
	
    postfix = (new InfixToPostfix(infix))->getPostfix();

    cout<<endl<<infix<<"    ->    "<<postfix<<endl;

}
