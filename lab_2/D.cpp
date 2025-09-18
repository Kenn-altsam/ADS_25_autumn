//  List modes

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

    for(int i = 0; i < n; i++){
        cin >> x;
        
        my_map[x]++;
        if(my_map[x] > max){
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

    while(cur != nullptr){
        // Miras, Miras, Kenzhe, Olzhas, Olzhas, Sanzhar
        if(my_map[cur->data] == max){
            my_set.insert(cur->data);
        }
        cur = cur->next;
    }

    set<int>::reverse_iterator it;
    for(it = my_set.rbegin(); it != my_set.rend(); it++){
        cout << *it << " ";
    }

    return 0;
}