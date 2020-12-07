#include <iostream>
#include <string>
#include <map>
using namespace std;

int mostCommon(int* arr, int l){

    map<int, int> myMap;
    for (int i = 0; i < l; i++){
        myMap[*(arr+i)] += 1;
    }
    pair<int, int> res;
    for (auto const& x : myMap){
        if (x.second > res.second) res = x;
    }
    return res.first;
}

int main(){
    printf("running test.cpp\n");
    int myArr[] = {0, 0, 1, 4, 5, 0, 3, 6, 7, 5, 5, 9, 2, 1, 5};
    cout << mostCommon(myArr, 15) << endl;
}