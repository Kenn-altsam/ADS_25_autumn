// Classroom of the Elite
// Print single line: the name of the fraction without quotes.
// “SAKAYANAGI” — if Sakayanagi will win.
// “KATSURAGI” — if Katsuragi will win.

#include <iostream>
#include <queue>
using namespace std;

int main(){

    int n;
    string input;

    cin >> n >> input;

    queue<int> S, K;

    for(int i = 1; i <= n; i++){ // SSKKK
        if(input[i - 1] == 'S'){     // S -> 1, 2    -> 2, 6 -> 6, 7 -> 7 -> 12
            S.push(i);               // K -> 3, 4, 5 -> 4, 5 -> 5    -> 10 -> []
        }                        
        else{
            K.push(i);
        }
    }

    while(!S.empty() && !K.empty()){ // each has to vote, but the previous student already banned you, are 
        if(S.front() < K.front()){   // out of the game 
            S.push(S.front() + n);   // What we do: we go until one of the queues is empty  
            K.pop();                 // if the id of the S is less than K, i.e. the student we are checking in S
            S.pop();                 // comes before the student we are checking in K, we remove the student from the opponent team 
        }                            // and put the student who banned the other one to the end of the queue
        else{                        // we add n, because for example if there are 5 people, and first votes
                                     // the next time, he/she votes is 6th index(after all other 4 people)
            K.push(K.front() + n); // the same here 
            S.pop();
            K.pop();
        }
    }

    if(S.empty()){ // The team with student left - wins
        cout << "KATSURAGI";
    }
    else{
        cout << "SAKAYANAGI";
    }

    


    return 0;
}