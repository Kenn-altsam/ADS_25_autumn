#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Date{
    int date;
    int month;
    int year;
};

bool compare(Date a, Date b){
    if(a.year != b.year){
        return a.year < b.year;
    }
    if(a.month != b.month){
        return a.month < b.month;
    }
    else{
        return a.date < b.date;
    }
}

int main(){

    int n; 
    cin >> n;

    string my_string;

    vector<Date> my_vector;

    for(int i = 0; i < n; i++){
        cin >> my_string;
        int date_ = (my_string[0] - '0') * 10 + (my_string[1] - '0');
        int month_ = (my_string[3] - '0') * 10 + (my_string[4] - '0');
        int year_ = (my_string[6] - '0') * 1000 + (my_string[7] - '0') * 100 + (my_string[8] - '0') * 10 + (my_string[9] - '0');

        Date my_date;
        my_date.date = date_;
        my_date.month = month_;
        my_date.year = year_;

        my_vector.push_back(my_date);
    }

    sort(my_vector.begin(), my_vector.end(), compare);

    for(int i = 0; i < n; i++){
        if(my_vector[i].date < 10){
            cout << 0 << my_vector[i].date << '-';
        }
        else{
            cout << my_vector[i].date << '-';
        }
        if(my_vector[i].month < 10){
            cout << 0 << my_vector[i].month << '-';
        }
        else{
            cout << my_vector[i].month << '-';
        }
        cout << my_vector[i].year << endl;
    }

    return 0;
}