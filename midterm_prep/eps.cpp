#include <iostream>
#include <iomanip>
using namespace std;

double func(double x){
    return x * x * x + x - 1.0;
}

int main(){

    double left = 0, right = 1;
    double eps = 1e-9;
    double mid;

    while(right - left > eps){
        mid = left + (right - left) / 2.0;
        if(func(mid) < 0){
            left = mid;
        }
        else{
            right = mid;
        }
    }

    cout << fixed << setprecision(12) << left + (right - left) / 2.0;

    return 0;
}