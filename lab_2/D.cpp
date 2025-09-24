//  List modes
// You are given a list of integer numbers. Print its mode. 
// Mode is the number that occurs most frequently in the list. 
// If there is several modes, print them in descending order.

#include <iostream>
#include <map>
#include <set> 
#include <climits>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int new_data){
        data = new_data;
        next = nullptr;
    }
};

int main(){

    int n, x, max = INT_MIN;
    map<int, int> my_map;
    set<int> my_set;

    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0; i < n; i++){ // get the numbers
        cin >> x;
        
        my_map[x]++; // count the frequency of each number that occurs
        if(my_map[x] > max){ // compare the frequency of numbers with max
            max = my_map[x];
        }

        Node* node = new Node(x);

        if(head == nullptr){
            head = tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
    }

    Node* cur = head;

    while(cur != nullptr){ // work until we reach the end of LL
        // Miras, Miras, Kenzhe, Olzhas, Olzhas, Sanzhar
        if(my_map[cur->data] == max){ // finding the numbers that have the frequency equal to max 
            my_set.insert(cur->data);
        }
        cur = cur->next;
    }

    set<int>::reverse_iterator it; // printing those numbers with max frequency in a decreasing order
    for(it = my_set.rbegin(); it != my_set.rend(); it++){
        cout << *it << " ";
    }

    return 0;
}