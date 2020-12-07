#include <iostream>
#include <string>
using namespace std;

template<typename T>
T sum(T* a, int length){
    if (length < 1) return 0;
    T res = a[0];
    for (int i = 1; i < length; i++){
        res += a[i];
    }
    return res;
}

int main(){
    printf("running test.cpp\n");
    double da[5] = {0,1.1,2.2,3.3,4.4};
    int ia[5] = {1,2,3,4,1};
    cout << sum<double>(da,5) << endl;
    cout << sum<int>(ia,5) << endl;
}