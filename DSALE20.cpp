#include <iostream>
using namespace std;

class PriorityQueue {
    string pqueue[10];
    int priority_array[10], f, r;
public:
    PriorityQueue() {
        f = r = -1;
    }
    int isfull() {
        if (r >= 9) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int isempty() {
        if (r == -1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    void enqueue(string data, int priority) {
        if (isfull()) {
            cout << "Stack is full";
        }
        else if (isempty()) {
            f = r = 0;
            pqueue[r] = data;
            priority_array[r] = priority;
        }
        else {
            int i;
            for (i = r; i >= 0; i--) {
                if (priority_array[i] < priority) {
                    priority_array[i + 1] = priority_array[i];
                    pqueue[i + 1] = pqueue[i];
                }
                else {
                    break;
                }
            }
            priority_array[i + 1] = priority;
            pqueue[i + 1] = data;
            r++;
        }
    }
    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty";
        }
        cout << pqueue[f];
        if (f == r) {
            f = r = -1;
        }
        else {
            f++;
        }
    }
};
int main() {
    PriorityQueue obj;
    obj.enqueue("Least", 0);
    obj.enqueue("Medium", 1);
    obj.enqueue("Highest", 2);
    obj.enqueue("Medium", 1);
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
}
