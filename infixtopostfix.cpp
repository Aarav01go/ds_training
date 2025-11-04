
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#define STACKSIZE 30
using namespace std;

struct stk{
    char item[STACKSIZE];
    int top=-1;
};
struct stk S;

// void Initialize(){
// Initialize the stack to be empty by setting top to -1
//S.top = -1;
// }

bool isEmpty(){
    return S.top==-1;
}

void push(char x){

    if(S.top==STACKSIZE-1) {
        cout<<"Stack Overflows"<<endl;
        return;
    }
    S.top++;
    S.item[S.top] = x;
}

char pop(){
    if(S.top==-1) {
        cout<<"Stack Underflows"<<endl;
        exit(1);
    }

    char x = S.item[S.top];
    S.top--;
    return x;
}

char stackTop(){
    return S.item[S.top];
}
bool pre(char stackOp, char incomingOp){
    auto prec = [](char op)->int {
        if(op=='+' || op=='-') return 1;
        if(op=='*' || op=='/') return 2;
        if(op=='^') return 3;
        return 0;
    };
    // '^' is right-associative: do not pop when both are '^'
    if(stackOp == '^' && incomingOp == '^') return false;
    return prec(stackOp) >= prec(incomingOp);
}

void infixToPostfix(char exp[]){
    vector<char>postfix;
    int i=0;
    while(exp[i]!='\0'){
        char symbol = exp[i];
        if((symbol>='a' && symbol<='z') || (symbol>='0' && symbol<='9')){
            // operand -> output
            postfix.push_back(symbol);
        } else if(symbol == '('){
            push(symbol);
        } else if(symbol == ')'){
            while(!isEmpty() && stackTop() != '('){
                postfix.push_back(pop());
            }
            if(!isEmpty() && stackTop() == '(') pop();
        } else { // operator
            while(!isEmpty() && pre(stackTop(), symbol)){
                postfix.push_back(pop());
            }
            push(symbol);
        }
        i++;
    }
    while(!isEmpty()){
        char x = pop();
        postfix.push_back(x);
    }

    for(size_t j=0;j<postfix.size();j++){
        cout<<postfix[j];
    }
    cout<<endl;
}



int main(){
    char infix[30];
    cin>>infix;
    infixToPostfix(infix);    

}