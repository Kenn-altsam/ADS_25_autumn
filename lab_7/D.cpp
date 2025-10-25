#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Person{
    string surname;
    string name;
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

    int n, m, credit;
    cin >> n;

    string surname, name, mark;

    double sum_of_gpa, gpa;
    int sum_of_credit;

    vector<Person> result;

    for(int i = 0; i < n; i++){
        cin >> surname >> name >> m;

        sum_of_credit = 0;
        sum_of_gpa = 0.0;

        for(int j = 0; j < m; j++){
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
                sum_of_gpa += 0;
            }
            sum_of_credit += credit;
        }
        gpa = sum_of_gpa / (double)sum_of_credit;
        Person person;
        person.gpa = gpa;
        person.surname = surname;
        person.name = name;
        result.push_back(person);
    }

    sort(result.begin(), result.end(), comparison);

    for(int i = 0; i < result.size(); i++){
        cout << result[i].surname << ' ' << result[i].name << ' ' << fixed << setprecision(3) << result[i].gpa << endl;
    }

    return 0;
}