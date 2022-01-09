//#include "stack.h"

class InfixToPostfix {
private:

    int i;
    Stack<char> stack;

    string infix;

    string postfix;

    int checkPrecedence(char ch) {
        int precedence = 0;
            switch(ch) {
            case '+':
                precedence = 1;
                break;

            case '-':
                precedence = 1;
                break;

            case '*':
                precedence = 2;
                break;

            case '/':
                precedence = 2;
                break;

            case '%':
                precedence = 2;
                break;

            case '^':
                precedence = 3;
                break;

            case '(':
                precedence = 4;
                break;

            case ')':
                precedence = 4;
                break;

            default:
                precedence = 0;
        }
        return precedence;
    }

    void performOperation() {
        for(i = 0; i < infix.length(); i++) {
            //getting single char from string infix
            char ch = infix[i];

            // checking the precedence of char and (is it operator or not)
            int precedence = checkPrecedence(ch);

            if(precedence == 0) { // precedence 0 = character is operand
                postfix += ch;
            } else { // precedence > 0 then character is operator
                if(precedence >= checkPrecedence(stack.peek())) { // pushing operator in stack according to precedence
                    if(ch == ')') { // if operator is ')' then pop all elements till '(' encounters;
                        while(true) {
                            if(stack.peek() != '(') {
                                char ch = stack.pop();
                                if(ch == '(' || ch == ')') {}  // ignoring to add '(' and ')' in postfix expression
                                else postfix += ch;
                            } else {
                                break;
                            }
                        }
                    }
                    stack.push(ch);
                } else { // if precedence is lower.. then pop elements until precedence matches
                    while(precedence < checkPrecedence(stack.peek())) {
                        if(stack.peek() != '(') { // if opening parenthesis is on top then push new operator else pop until precedence matches
                            char ch = stack.pop();
                            if(ch == '(' || ch == ')') {} // ignoring to add '(' and ')' in postfix expression
                            else postfix += ch;
                        } else {
                            stack.push(ch);
                        }

                        if(stack.isEmpty()) { // if stack is empty then break pop operation
                            break;
                        }
                    }
                }
            }
        }
        // popping up all items from stack
        if(!stack.isEmpty()) {
            while(!stack.isEmpty()) {
                char ch = stack.pop();
                if(ch == '(' || ch == ')') {} // ignoring to add '(' and ')' in postfix expression
                else postfix += ch;
            }
        }
    }

public:
    InfixToPostfix(string infix) {
        this->infix = infix;
        performOperation();
    }

    string getPostfix() {
        return this->postfix;
    }
};


/*
#include "infixToPostfix.h"

int main() {
    string infix;
    string postfix;

    infix = "(a+b*c)+c/d";
    postfix = (new InfixToPostfix(infix))->getPostfix();

    cout<<endl<<infix<<"    ->    "<<postfix<<endl;

}

*/

