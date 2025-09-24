// Doubly linked list
// Implement the doubly linked list data structure. 

#include <iostream>
using namespace std;

struct Node{
    string data;
    Node* next;
    Node* prev;

    Node(string new_data){
        data = new_data;
        next = nullptr;
        prev = nullptr;
    }
};

Node* head = nullptr;
Node* tail = nullptr;
int cnt = 0; // cnt is for counting the length

bool empty(){ 
    if(cnt == 0){
        return true;
    }
    else{
        return false;
    }
}

void add_front(string x){
    Node* node = new Node(x);
    if(head == nullptr){
        head = tail = node;
    }
    else{ // 0 5 10 15 
        node->next = head;
        head->prev = node;
        head = node;
    }
    cnt++;

    cout << "ok" << endl;
}   

void add_back(string x){
    Node* node = new Node(x);

    if(head == nullptr){
        head = tail = node;
    }
    else{ // 5 10 15 20
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    cnt++;

    cout << "ok" << endl;
}

void erase_front(){ // 5 10 15
    if(empty()){
        cout << "error" << endl;
        return;
    }
    Node* temp = head;
    string temp_data = head->data;
    if(head == tail){
        head = tail = nullptr;
    }
    else{
        head = head->next; // moving head to the second element
        head->prev = nullptr; // second element has the prev pointing to the first element and now it must be null
    }
    
    delete temp;
    cnt--;

    cout << temp_data << endl;
}

void erase_back(){
    if(empty()){
        cout << "error" << endl;
        return;
    }
    Node* temp = tail;
    string temp_data = tail->data;
    if(head == tail){
        head = tail = nullptr;
    }
    else{
        tail = tail->prev; // moving tail to the second last element
        tail->next = nullptr; // second last element has the next pointing to the first element and now it must be null
    }
    delete temp;
    cnt--;

    cout << temp_data << endl;
}

string front(){
    if(!empty()){
        return head->data;
    }
    else{
        return "error"; 
    } 
}

string back(){
    if(!empty()){
        return tail->data;
    }
    else{
        return "error";
    }
}

void erase(){
    while(!empty()){
        Node* temp = head;
        if(head == tail){
            head = tail = nullptr;
        }
        else{
            head = head->next; // moving head to the second element
            head->prev = nullptr; // second last element has the next pointing to the first element and now it must be null
        }

        delete temp;
        cnt--;
    }
}

int main(){

    string command, x;

    while(true){
        cin >> command;
        if(command == "exit"){
            cout << "goodbye";
            break;
        }
        else if(command == "add_front"){
            cin >> x;
            add_front(x);
        }
        else if(command == "add_back"){
            cin >> x;
            add_back(x);
        }
        else if(command == "erase_front"){
            erase_front();
        }
        else if(command == "erase_back"){
            erase_back();
        }
        else if(command == "front"){
            cout << front() << endl;
        }
        else if(command == "back"){
            cout << back() << endl;
        }
        else if(command == "clear"){
            erase();
            cout << "ok" << endl;
        }
        
    }

    return 0;
}