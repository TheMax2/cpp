#include <iostream>

using namespace std;

namespace bitUtils{

    // turns on the nth bit
    int turnOnBit(unsigned int number, short bit){
        unsigned int mask = 1 << bit;
        return number | mask;
    }

    // turns off the nth bit
    int turnOffBit(unsigned int number, short bit){
        unsigned int mask = 1 << bit;
        return number & ~mask;
    }

    // returns true (1) if the nth bit is a 1
    bool checkBit(unsigned int number, short bit){
        unsigned int mask = 1 << bit;
        return number & mask;
    }

    // returns the number of on bits (1s)
    int countBits(unsigned int number){
        int res = 0;
        for (short i = 0; i < 32; i++){
            res += checkBit(number, i);
        }
        return res;
    }

    // returns the integer as binary representation of 0s and 1s
    // only works for small numbers (under 1024)
    int intToBits(unsigned int number){
        int res = 0;
        for (short i = 16; i >= 0; i--){       
            res *= 10;
            res += checkBit(number, i);      
        }
        return res;
    }

    // returns a pointer to a boolean array representation of the number, also prings out the number.
    bool* intToBitString(unsigned int number){
        bool s[32];
        for (short i = 31; i >= 0; i--){       
            s[i] = checkBit(number, i);
            cout << s[i];
            if (i % 4 == 0) cout << " ";
        }
        cout << endl;
        bool* res = s;
        return res;
    }
}

int main(){
    cout << bitUtils::intToBits(25) << endl;
}