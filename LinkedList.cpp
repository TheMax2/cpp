#include <iostream>
#include <string>

using namespace std;

// A struct to represent a single Node in the list.
struct Node{
    int value;
    Node* next;
};

// A class implementing many functions for a linked list.
class LinkedList{

    Node* head;
    public:
        // constructor to create the list.
        LinkedList(){head = nullptr;}
        
        // returns the head of the list
        Node* getHead(){return head;}

        // returns the node at position p
        Node* getNode(int pos){
            Node* c = new Node(); // current
            c -> next = head;
            for (int i = 0; i <= pos; i++){
                c = c -> next;
                if (c == nullptr){
                    cout << "Index out of bounds" << endl;
                    return nullptr;
                }
            }
            return c;
        }

        // adds node n to the end of the list
        void add(Node* n){
            // if head is null set the new node to be the head
            if (head == nullptr){        
                head = n;
            } else {
                Node* t = head; // t = temp
                while (t->next != nullptr) t = t->next; // iterate to the end of list
                t->next = n; // set the new node to be the next node of the last node
            }
        }

        // creates a new node with value v and adds it to the end of the list
        void add(int v){
            Node* n = new Node; // heap?
            n -> value = v;
            add(n);
        }

        // inserts a new node into position pos. Does not delete any nodes
        void insert(Node* n, int pos){
            Node* c = getNode(pos-1); // current
            // inserts n right after c;
            Node* next = c -> next;
            c -> next = n;
            n -> next = next;
            if (pos == 0) head = n;
        }

        // replaces node at position pos with node n
        void replace(Node* n, int pos){
            Node* c = getNode(pos-1); // current
            // replaces c with n;
            Node* next = c -> next -> next;
            c -> next = n;
            n -> next = next;
            if (pos == 0) head = n;
        }

        // removes an item at position pos from the list
        void remove(int pos){
            Node* c = getNode(pos-1); // current
            // deletes c -> next
            if (c -> next) c -> next = c -> next -> next;
            if (pos == 0) head = head -> next;
        }

        // iterates once through the list and reverses the pointers. 
        // runs in O(n) time
        void reverse(){
            Node* p = head; // previous
            Node* c = head -> next; // current
            head -> next = nullptr; // head = the new tail
            //iterate once through the list and change c -> next to previous;
            while (c -> next != nullptr){ 
                Node * t = c -> next; // temp
                c -> next = p;
                p = c; c = t;
            }
            c -> next = p;
            head = c;
        }

        // returns true if the list is empty
        bool isEmpty(){
            return head == NULL;
        }

        // returns true if the list contains a cycle
        bool isCycle(){
            Node* fast = head;
            Node* slow = head;
            while (fast -> next != nullptr && slow -> next != nullptr){
                fast = fast -> next -> next -> next; 
                slow = slow -> next -> next;
                if (slow == fast) return true;
            }
            return false;
        }

        // Algorithm: merge sort
        void sort(){
            head = mergeSort(head, nullptr);
        }

        // Returns a pointer to a sorted list.     
        Node* mergeSort(Node* start, Node* end){
            // base case: list size = 1;
            if (start->next == end){
                start -> next = nullptr;
                return start;
            }
            // divides list in 2     
            Node* mid = getMid(start, end);
            // sorts the two halfs of the list
            Node* firstSortedList = mergeSort(start, mid);           
            Node* secondSortedList = mergeSort(mid, end);  
            // merges the 2 sorted lists       
            return merge(firstSortedList, secondSortedList);
        }

        // merges two sorted lists into one sorted list
        Node* merge(Node* start, Node* mid){
            Node* n1 = start; // iterator through first list
            Node* n2 = mid;   // iterator through second list
            Node* res = new Node(); // result list. This will get returned
            Node* cur = res;  // iterator through result list
            
            // iterates through both lists and creates result list
            while (n1 != nullptr && n2 != nullptr){       
                if (n1 -> value < n2 -> value){
                    cur -> next = n1;
                    n1 = n1 -> next;
                } else {
                    cur -> next = n2;
                    n2 = n2 -> next;
                }
                cur = cur -> next;
            }
            // iterates through remaining items if any
            while (n1){
                cur -> next = n1;
                n1 = n1 -> next;
                cur = cur -> next;
            }
            while (n2){              
                cur -> next = n2;
                n2 = n2 -> next;
                cur = cur -> next;
            }
            // returns resulting list
            cur -> next = nullptr;
            start = res -> next;
            return res -> next;
        }

        /* 
        Finds the middle of the list.
        Iterates once through the list with a fast pointer and a slow pointer.
        Runs in O(1/2n) Time
        Used as a helper method for mergeSort.
        */
        Node* getMid(Node* start, Node* end){
            Node* fast = start; 
            Node* slow = start;      
            while (fast != end) { 
                fast = fast->next; 
                if (fast != end) { 
                    slow = slow->next; 
                    fast = fast->next; 
                } 
            }
            return slow;
        }

        // prints list to console
        void print(){
            Node* n = head;
            int stopper = 0; // if the list is a cycle it wont print forever;
            while (n != NULL && stopper < 100) { 
                cout << n->value << " "; 
                n = n->next; 
                stopper ++;
            }
            if (stopper >= 99) cout << "...";
            cout << endl;
        }
};


int main(){
    printf("running test.cpp\n");

    LinkedList myList = LinkedList();
    Node n1 = {1, nullptr}; // struct Node n = {1,nullptr}; // ??? 
    myList.add(&n1);
    // for (int i = 2; i <= 5; i++) myList.add(i);
    Node example = {42, nullptr};
    
    myList.add(4);
    myList.add(3);
    myList.add(2);
    myList.add(7);
    myList.add(5);
    myList.add(11);
    myList.add(8);
    myList.add(4);

    //cout << "is empty? " << myList.isEmpty() << endl;

    //myList.getHead() -> next -> next -> next -> next = myList.getHead(); // creates a cycle

    //cout << "is cycle? " << myList.isCycle() << endl;

    //myList.reverse();

    //myList.replace(&example, 9);

    //myList.remove(9);

    //myList.add(&example);
    
    //myList.sort(); 

    myList.print();
}