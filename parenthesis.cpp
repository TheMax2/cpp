#include <iostream>
#include <string>
using namespace std;

//open if open is less than n, close if close is less than open
long getParenth(string s, int open, int close, int n){
    int res = 0;
    if (open < n) res += getParenth(s+'(',open+1,close,n);
    if (close < open) res += getParenth(s+')',open,close+1,n);
    if (open == close && open == n) {cout << s << endl; return res + 1;}
    return res;
}

int main(){
    printf("running parenthesis.cpp\n");
    int n;
    cout << "enter a number for n: ";
    cin >> n;
    cout << getParenth("",0,0,n) << endl;
}