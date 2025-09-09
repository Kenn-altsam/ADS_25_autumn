#include <iostream>
#include <queue> 
using namespace std;

int main(){

    queue<int> first, second;

    int num, cnt = 0;

    for(int i = 0; i < 5; i++){ // adding input values to the queue
        cin >> num;
        first.push(num);
    }

    for(int i = 0; i < 5; i++){
        cin >> num;
        second.push(num);
    }

    while(cnt <= 1000000 && !first.empty() && !second.empty()){ // checking the operation until we hit 100,000 or
        cnt++;                                                  // one of them has no cards left 

        if ((first.front() == 0 && second.front() == 9) || (first.front() > second.front() && !(first.front() == 9 && second.front() == 0))){
            first.push(first.front()); // if the Boris has 0 and Nursik has 9, Boris wins OR 
            first.push(second.front()); // if the Boris has a greater card than Nursik, and those cards are not 9 in Boris' hands and 0 in Nursik's hands 
            
            first.pop(); // we put cards of Boris and Nursik's cards at the winner's deck and remove the cards 
            second.pop(); // at the front of the deck 
        }
        else{
            second.push(first.front()); // the same thing is here, but Nursik here wins
            second.push(second.front());

            first.pop();
            second.pop();
        }
    }

    if(cnt >= 1000000){
        cout << "Blin nichya"; // if we count more than 100,000, we show the message /
    }
    else if(first.empty()){
        cout << "Nursik " << cnt; // if Boris has no cards - Nursik wins
    }
    else{
        cout << "Boris " << cnt; // if Nursik has no cards - Boris wins
    }

    return 0;
}