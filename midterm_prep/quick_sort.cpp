#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &my_vector){

}

void quickSort(vector<int> &my_vector){
    int pivot = my_vector.size() - 1;
    

}

int main(){   

    vector<int> my_vector = {1, 23, 91, 95, 62, 72, 10};

    quickSort(my_vector);

    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << ' ';
    }

    return 0;
}