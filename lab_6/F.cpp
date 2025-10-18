#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Person{
    string name;
    string surname;
    double gpa;  
};

bool comparison(Person a, Person b){
    if(a.gpa != b.gpa){
        return a.gpa < b.gpa;
    }
    if(a.surname != b.surname){
        return a.surname < b.surname;
    }
    return a.name < b.name;
}

int main(){

    int n;
    cin >> n;

    string name_, surname_, mark;

    int subjects, credit, sum_of_credits;
    double sum_of_gpa;
    double gpa_;

    vector<Person> people;


    for(int i = 0; i < n; i++){
        cin >> surname_ >> name_ >> subjects;
        gpa_ = 0;
        sum_of_credits = 0;
        sum_of_gpa = 0;
        for(int i = 0; i < subjects; i++){
            cin >> mark >> credit;
            if(mark == "A+"){
                sum_of_gpa += 4.0 * credit;
            }
            else if(mark == "A"){
                sum_of_gpa += 3.75 * credit;
            }
            else if(mark == "B+"){
                sum_of_gpa += 3.5 * credit;
            }
            else if(mark == "B"){
                sum_of_gpa += 3.0 * credit;
            }
            else if(mark == "C+"){
                sum_of_gpa += 2.5 * credit;
            }
            else if(mark == "C"){
                sum_of_gpa += 2.0 * credit;
            }
            else if(mark == "D+"){
                sum_of_gpa += 1.5 * credit;
            }
            else if(mark == "D"){
                sum_of_gpa += 1.0 * credit;
            }
            else if(mark == "F"){
                sum_of_gpa += 0.0 * credit;
            }

            sum_of_credits += credit;
        }

        gpa_ = sum_of_gpa / double(sum_of_credits);

        Person person;
        person.surname = surname_;
        person.name = name_;
        person.gpa = gpa_;

        people.push_back(person);
    }

    sort(people.begin(), people.end(), comparison);

    for(int i = 0; i < n; i++){
        cout << fixed << setprecision(4);
        cout << people[i].surname << ' ' << people[i].name << ' ' << people[i].gpa << endl;
    }

    return 0;
}