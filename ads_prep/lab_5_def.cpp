#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int> &heap, int i){
    int size = heap.size();
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;

    if(l < size && heap[largest] < heap[l]){
        largest = l;
    }
    if(r < size && heap[largest] < heap[r]){
        largest = r;
    }

    if(largest != i){
        swap(heap[i], heap[largest]);
        heapify(heap, largest);
    }
}

void insert(vector<int> &heap, int num){
    heap.push_back(num);
    int cur = heap.size() - 1;

    while(cur > 0){
        int parent = (cur - 1) / 2;
        if(heap[parent] < heap[cur]){
            swap(heap[parent], heap[cur]);
            cur = parent;
        }
        else{
            break;
        }
    }
}

void pop(vector<int> &heap, int num){
    int size = heap.size();
    if(size == 0){
        return;
    }

    heap[0] = heap[size - 1];

    heap.pop_back();

    heapify(heap, 0);
}

int main(){


    vector<int> heap = {2, 4, 3, 9, 1, 5};

    heapify(heap, 0);

    cout << heap[0];
    
    return 0;
}