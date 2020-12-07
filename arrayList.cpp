#include <iostream>
#include <string>
using namespace std;

template <typename T> class array_list
 {
    T* data = new T[1];
    private:
        int N = 1; // array length
        
    public:
        const T* begin() const { return data; }
        const T* end() const { return data + N; }
        int size() const { return N; }

        T& operator[](int idx)
        {
            if (idx < 0 || idx >= N)
            {
                int size = N;
                while (idx > size)
                {
                    size *= 2;
                }
                T* newArr = new T[size];
                for (int i = 0; i < N; i++)
                {
                    newArr[i] = data[i];
                }
                N = idx+1;
                // replace data with new arr
                T* temp = data;
                data = newArr;
                delete[] temp;
            }
            return data[idx];           
        }

        void print()
        {
            for (int i = 0; i < N; i++) cout << data[i] << " ";
            cout << endl;
        }
 };



int main(){
    printf("running arrayList.cpp\n");

    array_list<int> list;
    list[0]=1; list[1]=2; list[3]=3; list[10] = 50;

    // prints array
    list.print();

    // also prints array but uses foreach loop
    // for(int i : four) cout << i << " "; // 10 20 30 40
    // cout << endl;

    cout << "Size: " << list.size() << endl;
}