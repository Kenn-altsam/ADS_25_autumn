#include <iostream>
#include <map>
using namespace std;

int main(){

    int n;
    cin >> n;

    string f, s;
    map<string, string> my_map;

    for(int i = 0; i < n; i++){
        cin >> f >> s;

        bool ok = false;
        map<string, string>::iterator it;
        for(it = my_map.begin(); it != my_map.end(); it++){
            if(it->second == f){
                my_map[it->first] = s;
                ok = true;
                break;
            }
        }

        if(!ok){
            my_map[f] = s;
        } 
    }

    cout << my_map.size() << endl;
    map<string, string>::iterator it;
    for(it = my_map.begin(); it != my_map.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}