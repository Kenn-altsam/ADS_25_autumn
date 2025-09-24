#include <iostream>
 
using namespace std;
 
struct Node{
    int data;
    Node* next;

    Node(){
        data = 0, 
        next = nullptr;
    } 
    Node(int x){
        data = x;
        next = nullptr;
    }
    Node(Node* new_next){
        data = 0;
        next = new_next;
    }
    Node(int x, Node* new_next){
        data = x;
        next = new_next;
    }
};


 
Node* insert(Node* head, Node* node, int k){
    if(head == NULL){
        if(k == 0){
            head = node;
            return head;
        }
        return head;
    }

    if(k == 0){ // when the position to insert is 0
        node->next = head;
        head = node;
        return head;
    }

    int cnt = 0;
    Node* cur = head;
    while(cnt != k - 1 && cur != NULL){ // reach the element before the position to insert
        cur = cur->next;
        cnt++;
    }

    node->next = cur->next; // add the new element to the desired position by 1. connecting new node to cur's next
    cur->next = node; // 2. connecting cur's next to new node
    return head;
}
 
Node* remove(Node* head, int k){
    if(head == NULL){
        return head;
    }   
    if(k == 0){ // when the position to remove is 0
        Node* temp = head;
        head = head->next; // move head to the next node
        delete temp; // delete the temp from the memory
        return head;
    }

    int cnt = 0;
    Node* cur = head;
    while(cnt != k - 1){ // reach the element before the element that is going to be removed
        cur = cur->next;
        cnt++;
    }

    Node* temp = cur->next; // save the node that is going to be removed to a temp variable

    cur->next = cur->next->next; // connect cur's next to the element that is after the element that is going 
    delete temp;                 // to be removed
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    if(head == NULL){
        return head;
    }

    if(p1 == 0){ // if the pos of p1 is 0
        Node* node = head;
        head = head->next; // move head to the next node

        if(p2 == 0){ // if the pos of p2 is also 0
            node->next = head; // just add the node as the first node
            head = node; // make head the added node
            return head;
        }  
        
        int cnt = 0; // if the inserting position is not the first position
        Node* temp = head;
        while(cnt != (p2 - 1)){ // reach the position before the position to be inserted
            temp = temp->next;
            cnt++;
        }

        node->next = temp->next; // connect the node that is going to be added to the next of the cur
        temp->next = node; // connect cur's next to the node that is going to be inserted
        return head;
    }
    else{ // if the element that is going to be removed is not the 0th
        int cnt = 0;
        Node* temp_2 = head;
        while(cnt != (p1 - 1)){ // reach the 1 position before of the element that is going to be removed
            temp_2 = temp_2->next;
            cnt++;
        }

        Node* needed_node = temp_2->next; // saving the data of the node that we need to insert, this is the node just before the node that we need 
        temp_2->next = temp_2->next->next; // connect the cur to the next element of the element that is going to be removed

        if(p2 == 0){ // if the pos of p2 is also 0
            needed_node->next = head;
            head = needed_node;
            return head;
        }  
        
        cnt = 0; // if the inserting position is not the first position
        Node* temp = head;
        while(cnt != (p2 - 1)){ 
            temp = temp->next;
            cnt++;
        }

        needed_node->next = temp->next;
        temp->next = needed_node;
        return head;
    }
}
 
Node* reverse(Node* head){
    if(head == NULL){
        return head;
    }
    Node* prev_node = NULL;
    Node* cur = head;
    Node* front;
    
    while(cur != NULL){ 
        front = cur->next; // we need front node to not lose the next node
        cur->next = prev_node; // moving arrow to the previous node
        prev_node = cur; // moving prev node to one node forward
        cur = front; // moving cur to one node forward
    }

    return prev_node; // at the end the new head will be prev_node;
}
 
void print(Node* head){
    if(head == NULL){ // if there's nothing, return nothing 
        return;
    }

    while(head != NULL){ // print every element of LL 
        cout << head->data << ' ';
        head = head->next;
    }

    cout << endl;
}

Node* find_nth_node(Node* temp, int n){
    int cnt = 1;
    while(temp != NULL){ // there's no difference between temp != NULL and temp->next != NULL here;
        if(cnt == n){
            return temp;
        }
        cnt++;
        temp = temp->next;
    }
    return temp;
}
 
Node* cyclic_right(Node* head, int k){
    if(head == NULL || k == 0){ // if head == NULL means - there's nothing it's pointing to,
        return head;            // k == 0 means - we don't have to make any rotations
    } 

    Node* tail = head;
    int len = 1; // we set len equal to 1, because at the moment of the first loop in while loop -> 
                 // we would already be at the 1st element in our list 
    while(tail->next != NULL){ // Finding the length of the linked list
        len++; 
        tail = tail->next;
    }

    k = k % len;
    if(k == 0){ // finding how many times we need to do shifts
        return head;
    }

    tail->next = head; // 1. Connect the tail with head

    Node* temp = head;

    Node* new_tail = find_nth_node(head, len - k); // 2. Find the new tail 

    head = new_tail->next; // 3. Make the next element of the new_tail - the new head

    new_tail->next = NULL; // 4. Make the new_tail's next element NULL, which makes it now the 'actual' tail

    return head;
}

Node* cyclic_left(Node* head, int k){ // cyclic shift k times -> means cyclic right (len - k) times
    if(head == NULL || k == 0){ // if head == NULL means - there's nothing it's pointing to,
        return head;            // k == 0 means - we don't have to make any rotations
    }

    int len = 1;
    Node* tail = head;
    while(tail->next != NULL){
        len++;
        tail = tail->next;
    }

    k = k % len;
    k = len - k; // cyclic shift k times -> means cyclic right (len - k) times

    if(k == 0){ // finding how many times we need to do shifts
        return head;
    }

    tail->next = head; // 1. Connect tail to head

    Node* new_tail = find_nth_node(head, len - k); // 2. Find new tail

    head = new_tail->next; // 3. Make head the new_tail's next element

    new_tail->next = NULL; // 4. Make new_tail's next element the NULL

    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; 
        cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; 
            cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; 
            cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; 
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; 
            cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; 
            cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}