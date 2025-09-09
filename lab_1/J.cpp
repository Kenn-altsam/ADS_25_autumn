#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){

    deque<int> dq; 
    char character;
    int digit;
    vector<string> result; 

    // + 1
    // - 9
    // + 2
    // *
    // + 2
    // - 6
    // + 3
    // - 9
    // *
    // *
    // *
    // *
    // !

    while(true){ 
        cin >> character;

        if (character == '!'){
            break;
        }
        else if(character == '+'){
            cin >> digit;
            dq.push_front(digit);
        }
        else if(character == '-'){
            cin >> digit;
            dq.push_back(digit);
        }
        else if(character == '*'){
            if(dq.empty()){
                result.push_back("error");
            }
            else{
                if(dq.size() >= 2){
                    result.push_back(to_string(dq.front() + dq.back()));
                    dq.pop_front();
                    dq.pop_back();
                }
                else{
                    result.push_back(to_string(dq.front() + dq.back()));
                    dq.pop_back();
                }
            }
        }
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }

    return 0;
}