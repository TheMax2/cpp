#include <iostream>
#include <string>

using namespace std;

void set(int** theArr, int row, int collumn, int value){
    *(*(theArr+collumn)+row) = value;
}

// flips left to right
void invert(int** theArr, int length){
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length/2; j++){
            int temp = *(*(theArr+i)+j);
            *(*(theArr+i)+j) = *(*(theArr+i)+(length-j-1));
            *(*(theArr+i)+(length-j-1)) = temp;
        }
    }
}

// flips upside down
void flip(int** theArr, int length){
    for (int i = 0; i < length/2; i++){
        for (int j = 0; j < length; j++){
            int temp = *(*(theArr+i)+j);
            *(*(theArr+i)+j) = *(*(theArr+(length-i-1))+j);
            *(*(theArr+(length-i-1))+j) = temp;
        }
    }
}

// rotates the array left
void rotateLeft(int** theArr, int length){
    for (int i = 0; i < length / 2; i++){
        for (int j = i; j < (length-(2*i)-1)+i; j++){
            int x = j, y = i, t = theArr[x][y], l = length-1;
            for (int k = 0; k < 3; k++){
                theArr[x][y] = theArr[y][l-x];
                int tx = x;
                x = y; y = l-tx;
            }theArr[x][y] = t;
        }
    }
}

// rotates the array left
void rotateRight(int** theArr, int length){
    for (int i = 0; i < length / 2; i++){
        for (int j = i; j < (length-(2*i)-1)+i; j++){
            int x = j, y = i, t = theArr[x][y], l = length-1;
            for (int k = 0; k < 3; k++){
                theArr[x][y] = theArr[l-y][x];
                int tx = x;
                x = l-y; y = tx;
            }theArr[x][y] = t;
        }
    }
}

// prints out the array to the console
void print(int** theArr, int length){
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            cout << *(*(theArr+i)+j) << " ";
        }
        cout << endl;
    }
    cout << endl;  
}

int main(){
    printf("running doubleArray.cpp\n");
    
    int length = 5;
    int testArr1[][length] = {{0,1,2,3,4},
                              {1,2,3,4,5},
                              {2,3,4,5,6},
                              {3,4,5,6,7},
                              {4,5,6,7,8}};

    int testArr2[][length] = {{0,1,2,3},
                              {3,2,1,0},
                              {2,3,4,5},
                              {5,4,3,2}};

    int testArr3[][length] = {{0,1,2},
                              {3,4,5},
                              {6,7,8}};

    int *a[length];
    for(int i=0; i<length; ++i) a[i]=testArr1[i];

    rotateLeft(a,length);

    print(a,length);
}