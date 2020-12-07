#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<int>> readFromFile(string path){
    ifstream myReadFile;
    myReadFile.open(path);
    vector<vector<int>> arr;
    if (myReadFile.is_open()) {
        char ch;
        string val = "";
        vector<int> row;
        while (myReadFile.get(ch)) {  
                  
            if (ch == '\n'){
                row.push_back(stoi(val));
                arr.push_back(row);
                vector<int> newV;
                row = newV;
                val = "";
            } else if (ch == ' '){
                row.push_back(stoi(val));
                val = "";
            } else { //ch is a number
                val += ch;
            }
        }
    }
    cout << arr[1][1] << endl;
    cout << endl;
    myReadFile.close();
    return arr;
}

int main(){
    printf("running fileReader.cpp\n");

    vector<vector<int>> arr = readFromFile("array.txt");
    
}