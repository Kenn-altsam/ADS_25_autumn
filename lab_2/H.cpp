// Zoro and Seven Sword Style

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int new_data){
        data = new_data;
        next = nullptr;
    }
};

int x, length = 0;
Node* head = nullptr;
Node* tail = nullptr;

Node* insert(Node* head, int x, int p){
    Node* node = new Node(x);
    if(p == 0){
        node->next = head;
        return node;
    }
    Node* cur = head; 
    for(int i = 0; i < p - 1; i++){
        cur = cur->next;
    }
    node->next = cur->next;
    cur->next = node;
    return head;
}

Node* remove(Node* head, int p){
    if(head == nullptr){
        return nullptr;
    }
    if(p == 0){
        Node* temp = head->next;
        delete head;
        return temp;
    }
    else{
        Node* cur = head;
        for(int i = 0; i < p - 1; i++){
            cur = cur->next;
        }
        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
        return head;
    }
}

void print(Node* head){
    if(head == nullptr){
        cout << -1 << endl;
    }
    else{
        while(head != nullptr){
            cout << head->data << ' ';
            head = head->next;
        }
    }
}

Node* replace(Node* head, int p1, int p2){
    if(head == nullptr || p1 == p2){
        return head;
    }

    Node* previous = NULL;
    Node* cur1 = head; 
    for(int i = 0; i < p1; i++){
        previous = cur1;
        cur1 = cur1->next;
    }

    if(previous != NULL){ // prev is not NULL, it means temp1 (the node we want to remove) is not the head node, so we
        previous->next = cur1->next; 
    }
    else{
        head = cur1->next; // This block is executed if previous is NULL, which means that temp1 is the head node of the list
    }

    Node* node = cur1;

    if(p2 == 0){
        node->next = head;
    }
    
    Node* cur2 = head;
    for(int i = 0; i < p2 - 1; i++){
        cur2 = cur2->next;
    }
    node->next = cur2->next; // this makes the next pointer of the new node (node) point to the node that comes after cur2
    cur2->next = node; // this updates the next pointer of cur2 to point to the new node (node)

    return head;
}

Node* reverse(Node* head){
    Node* previous = NULL;
    Node* cur = head;

    while(cur != NULL){ // swapping the directions of pointers
        Node* next = cur->next; // Save the next node, as we will change cur->next
        cur->next = previous; // Reverse the direction of the link: current node now points to the previous node
        previous = cur; // the current node is now the previous 
        cur = next; // This line moves the cur pointer to the next node in the original list
    }

    return previous;
}

Node* cyclic_left(Node* head, int x){
    if(head != NULL || head->next == nullptr){
        return head;
    }

    Node* tail = head;
    int len = 0;

    while(tail->next != nullptr){ // it works until the second last element of the list 
        tail = tail->next;
        len++;
    }
    len++; // this one is for the last element 

    x %= len;

    if(x == 0){
        return head;
    }
    else{
        tail->next = head;
        Node* new_tail = head;
        for(int i = 0; i < x - 1; i++){ // we have to move the xth element that will be at the front after x - 1 shifts
            new_tail = new_tail->next;
        }
        Node* new_head = new_tail->next; // new_tail->next is the xth element
        new_tail->next = nullptr;

        return new_head;
    }
}

Node* cyclic_right(Node* head, int x){
    if(head == NULL || head->next == nullptr){
        return head;
    }

    int len = 0;
    Node* tail = head;
    while(tail->next){ // measuring the size of the list 
        tail = tail->next;
        len++;
    }   
    len++;

    x %= len;
    if(x == 0){
        return head;
    }

    return cyclic_left(head, len - x); // performing cyclic left with (len - x) is the same as cyclic right with x

}



int main(){

    int x, p, command;

    while(true){
        if(command == 0){
            break;
        }
        else if(command == 1){
            cin >> x >> p;
            head = insert(head, x, p);
        }
        else if(command == 2){
            cin >> x >> p;
            head = remove(head, p);
        }
        else if(command == 3){
            print(head);
        }
        else if(command == 4){
            int p1, p2; 
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }
        else if(command == 5){
            head = reverse(head);
        }
        else if(command == 6){
            cin >> x;
            head = cyclic_left(head, x);
        }
        else if(command == 7){
            cin >> x;
            head = cyclic_right(head, x);
        }
    }

    return 0;
}