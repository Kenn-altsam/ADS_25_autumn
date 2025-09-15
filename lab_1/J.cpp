// Deque

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

    while(true){ // work until the ! character appers
        cin >> character;

        if (character == '!'){ // if the ! character appears -> break the loop
            break;
        }
        else if(character == '+'){ // if the + character appears -> add the element to the front
            cin >> digit;
            dq.push_front(digit);
        }
        else if(character == '-'){ // if the - character appears -> add the element to the back
            cin >> digit;
            dq.push_back(digit);
        }
        else if(character == '*'){ // if the * character appears -> then ...
            if(dq.empty()){ // if the dq is empty -> return "error"
                result.push_back("error");
            }
            else{
                if(dq.size() >= 2){ // if dq has two or more elements -> add the addition result to the 'result' vector
                    result.push_back(to_string(dq.front() + dq.back()));
                    dq.pop_front(); // and remove the elements from front and back of dq
                    dq.pop_back();
                }
                else{
                    result.push_back(to_string(dq.front() + dq.back())); // if dq has one element -> just add it only
                    dq.pop_back();
                }
            }
        }
    }

    for(int i = 0; i < result.size(); i++){ // print all the elements in the result vector
        cout << result[i] << endl;
    }

    return 0;
}