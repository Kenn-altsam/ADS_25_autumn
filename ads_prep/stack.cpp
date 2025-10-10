#include <iostream>
#include <stack>
using namespace std;

int main(){

    string my_string;
    stack<char> my_stack;

    cin >> my_string;
    bool is_ok = true;
    char c;

    for(int i = 0; i < my_string.size(); i++){
        if(my_string[i] == '{' || my_string[i] == '[' || my_string[i] == '('){
            my_stack.push(my_string[i]);
        }
        else if(my_string[i] == '}' || my_string[i] == ']' || my_string[i] == ')'){
            if(my_stack.empty()){
                is_ok = false;
                break;
            }
            c = my_stack.top();
            my_stack.pop();
            if(c == '{' && my_string[i] != '}' ||
               c == '[' && my_string[i] != ']' ||
               c == '(' && my_string[i] != ')'
            ){
                is_ok = false;
                break;
            }
        }
    }

    is_ok = is_ok && my_stack.empty();

    if(is_ok){
        cout << 0;
    }
    else{
        cout << 1;
    }

    return 0;
}