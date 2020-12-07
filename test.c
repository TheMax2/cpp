
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 3

// int funct1(int *array, int arrayLength);
// int funct2(char *array);
// int* replaceNextLargest(int* a, int arrayLength);
// int printArray(int*a, int l);





int funct1(int *array, int arrayLength){
    array = array + arrayLength-1;
    int largest = 0;
    for(int i=arrayLength; i >= 0; i= i-1){
        if (*array > largest){
            printf("%d\n", *array);
            largest = *array;
        }   
        array = array -1;
    }
    printf("\n");
    
}

int funct2(char *array){
    while (*array != '\0'){
        printf("%c", *array);
        array++;
    }
    printf("\n");
    
}

int* replaceNextLargest(int* a, int arrayLength){
    int *newArray = malloc(arrayLength * sizeof(int));
    for (int i=0; i<arrayLength; i++){
        int nextLargest = -1;
        for (int j=0; j<arrayLength; j++){
            if (*(a+j) > *(a+i) && (*(a+j) < nextLargest || nextLargest == -1)){
                nextLargest = *(a+j);
            }
        }
        newArray[i] = nextLargest;
    }
    return newArray;
}


int printArray(int*a, int l){
    printf("{");
    for (int i=0; i<l-1; i++){
        printf("%d,", *(a+i));
    }
    printf("%d", *(a+l-1));
    printf("}\n");
}

int countVotes(char* arr, int leng){
    
	char delim[] = " ";
	char *ptr = strtok(arr, delim);

	while(ptr != NULL)
	{
		printf("'%s': %d\n", ptr, 1);
		ptr = strtok(NULL, delim);
	}
}



int* mergeSort(int* arr, int l, int r){


    int m = (l+r)/2;

    int* left;
    int* right;

    mergeSort(left, l, m);
    mergeSort(right, m+1, r);

}

char* largestSub(char* s, int length){
    char* res;
    
    for (char* i = s; i < s+length; i++){
        char temp[length];
        int counter = 0;
        for (char* j = i; j < s+length; j++){
            // if *j is in temp {
                // break
            // } else {
                // temp[counter] = *j;
                // counter ++;
            // }
        }
        // if size of temp > res {
            // res = temp
        // }
        //delete(temp);
    }



}

double median(int* a, int* b, int lenA, int lenB){
    int i=0;
    int j=0;
    int combinedArr[(lenA + lenB)/2 +1];
    int counter = 0;
    while (counter < (lenA + lenB)/2 +1){
        if (j >= lenB || *(a+i)<*(b+j)){
            combinedArr[counter] = *(a+i);
            i++;
        } else if (i >= lenA || *(b+j)<*(a+i)){
            combinedArr[counter] = *(b+j);
            j++;
        }
        counter++;

    }
    counter --;
    double answer;
    if ((lenA+lenB) % 2 == 0){
        answer = (double)(combinedArr[counter] + combinedArr[counter-1])/2;
        
    } else {
        answer = combinedArr[counter];
    }
    printf("\n%f\n", answer);
    return answer;

}

int* findTriplet(int* arr, int leng){

    int a = 0;
    int b = 0;
    int c = 0;

    while (a<leng-2){
        if (c >= leng){
            if (b >= leng-1){
                a++;
                b = a+1;
            }
            b++;
            c = b+1;
        } else {
            c++;
        }
        if (*(arr+a)+*(arr+b)+*(arr+c) == 0){
            printf("[%d,%d,%d]\n", *(arr+a),*(arr+b),*(arr+c));
        }
    }

}

/** returns 1 if string s matches pattern p and 0 if it does not**/
int wildCard(char* s, char* p){
    int res = 0; // init result to false;
    char* nxt;
    while (*s != '\0' && *p != '\0'){
        if (*p == '*'){
            nxt = p+1;
            if (*(nxt) == '\0'){
                res = 1;
            } else if (*(nxt) == '?') {
                nxt ++;
            } else {
                if (*(nxt) == *(s+1)){
                    p++;
                }   
                //res = 0;
            }
            s++;
        } else if (*p == *s || *p == '?'){ 
            s++;
            p++;
            res = 1;
        } else {
            return 0;
        }
        
    }
    return res;

}

int isNumber(char* s){
    int e = 1; // char *s can be e;
    int m = 1; // char *s can be a minus sign;
    int p = 1; // char *s can be a plus sign;
    int d = 1; // char *s can be a decimal;
    int n = 1; // char *s can be a digit;

    int hade = 0; // says if the string already had a e
    int hadm = 0; // says if the string already had a m
    int hadp = 0; // says if the string already had a p
    int hadd = 0; // says if the string already had a d
    while(*s != '\0'){
        if (*s == 'e' && e && !hade){
            hade = 1;
            hadd = 0;
            e = 0;
            m = 1;
            p = 1;
            d = 0;
            n = 1;
        } else if (*s == '-' && m && !hadm) {
            hadm = 1;
            e = 0;
            m = 0;
            p = 0;
            d = 0;
            n = 1;
        } else if (*s == '+' && p && !hadp) {
            hadp = 1;
            e = 0;
            m = 0;
            p = 0;
            d = 0;
            n = 1;
        } else if (*s == '.' && d && !hadd) {
            hadd = 1;
            e = 0;
            m = 0;
            p = 0;
            d = 0;
            n = 1;
        } else if (isdigit(*s) && n) {
            e = 1;
            m = 0;
            p = 0;
            d = 1;
            n = 1;  
        } else {
            return 0;
        }
        if (*(s+1) == '\0' && !isdigit(*s)) return 0;
        s++;
    }
    return 1;
}

int helper(int N, int K, int* arr, int l){

    if (K < l)return *(arr+K-1); // base case

    l = l*2;
    int newArr[l];
    for (int i = 0; i < l; i+=2){
        if (*(arr+i) == 0){
            newArr[i] = 0;
            newArr[i+1] = 1;
        } else {
            newArr[i] = 1;
            newArr[i+1] = 0;
        }
    }
    return helper(N, K, newArr, l);
    
}

int kthGrammar(int N, int K){
    int arr[] = {0}; // first row;
    int length = 1;
    return helper(N, K, arr, length);
}

//int main(){

    // int myArray[] = {0, 2, 5, 1, 3};
    // int l = 5;
    // printf("old array: ");
    // printArray(myArray, l);
    // int* newArray = replaceNextLargest(myArray, 5);
    // printf("new array: ");
    // printArray(newArray, 5);

    // int a[] = {0,1,2};
    // int b[] = {4,4,5,6};
    //median(a,b,3,4);

    // int arr[] = {0, -1, 2, 1, -2, -1, 3, -4, -3, 1};
    // findTriplet(arr, 10);

    // char* myString = "hello world";
    // char* myPattern = "h*lo world";
    // printf("%d\n", wildCard(myString,myPattern));


    // char* myNumb = "23e-0.1";
    // printf("%s\n", myNumb);
    // printf("%d\n", isNumber(myNumb));

    //printf("%d\n", kthGrammar(3,3));




    // int arr[3][3] = { { 9, 6, 1 }, { 144, 70, 50 }, {10, 12, 78} };
    // int* arrptr = &arr;

    // int  var[] = {10, 100, 200};
    // int i, *ptr[MAX];
    
    // for ( i = 0; i < MAX; i++) {
    //     ptr[i] = &var[i]; /* assign the address of integer. */
    // }
    
    // for ( i = 0; i < MAX; i++) {
    //     printf("Value of var[%d] = %d\n", i, *ptr[i] );
    // }

    //printf("%d\n", arr[1][2]);

//}

void takeNormArr(int* arr){
    printf("%d\n", *arr);
}

void takeTwoDArr(int** arr){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("2DArr[%d][%d] = %d\n",i,j, *(*(arr+i)+j));
        }
    }
    
}

struct Date{
    
    int month;
    int day;
    int year;
};

void displayDate(struct Date date){
    char months[][10] = {"January", "Febuary", "March", "April", "May", "June"};
    printf("%s %d, %d\n", months[date.month], date.day, date.year);
}

int main(){
    // int normArr[2] = {0,1};
    // int twoDArr[2][2] = {{0,1},{2,3}};

    // // this seems to work but it also seems really sketchy
    // int len = 2;
    // int* ptr[len];
    // for ( int i = 0; i < len; i++) {
    //   ptr[i] = twoDArr[i];
    // }

    // takeNormArr(normArr); // This works fine
    // takeTwoDArr(ptr); // This also works

    // int v = 10;
    // int * pointer = &v;
    // printf("\n%d\n", *pointer);

    int daysInMonth[] = {31,28,31,30,31,30};

    struct Date halfYear[200]; // year with 200 days max
    int c = 0; // counter;

    for (int i = 0; i < 6; i++){
        for (int j = 1; j < daysInMonth[i]+1; j++){
            struct Date d = {i, j, 2020};
            halfYear[c] = d;
            c++;
        }
    }

    struct Date newYear = {0,1,2020};
    displayDate(halfYear[999]);
}

