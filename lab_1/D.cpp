// Balanced sequence of letters
// Print “YES” if string is balanced, otherwise print “NO”

#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack<char> my_stack;
    string input; 

    cin >> input;

    for(int i = 0; i < input.size(); i++){ // adding elements to the stack 
        if(my_stack.empty()){
            my_stack.push(input[i]); // if the stack is empty, just add the element to the top 
        }
        else if(my_stack.top() == input[i]){ // if the element at the top and the element we're checking are the same
            my_stack.pop();                  // remove the one from the top
        }
        else{
            my_stack.push(input[i]); // if the elements are different, just add the one being checked to the top
        }
    }

    if(my_stack.empty()){ // if the stack is empty at the end, it's balanced 
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}