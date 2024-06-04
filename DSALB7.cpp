#include <iostream>
using namespace std;

class node {
public:
    char data;
    node *left, *right;
};
class stack {
    node *data[20];
    int top;
public:
    stack() {
        top = -1;
    }
    int isfull() {
        if (top >= 19) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int isempty() {
        if (top == -1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    void push(node *x) {
        if (isfull()) {
            cout << "Stack is full";
        }
        else {
            top++;
            data[top] = x; 
        }
    }
    node *pop() {
        if (isempty()) {
            cout << "Stack is already empty";
            return 0;
        }
        else {
            node *x = data[top];
            top--;
            return x;
        }
    }
};
class tree {
public:
    node *temp;
    void expression(char prefix[]) {
        stack s;
        node *t1,*t2;
        int length = strlen(prefix);
        for (int i = length - 1; i >= 0; i--) {
            temp = new node;
            temp->left = temp->right = NULL;
            if (isalpha(prefix[i])) {
                temp->data = prefix[i];
                s.push(temp);
            }
            else {
                if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/') {
                    temp = new node;
                    t1 = s.pop();
                    t2 = s.pop();
                    temp->data = prefix[i];
                    temp->left = t1;
                    temp->right = t2;
                    s.push(temp);
                }
            }
        }
        temp = s.pop();
    }
    void display(node *T) {
        stack s1, s2;
        s1.push(T);
        while (!s1.isempty()) {
            node *current = s1.pop();
            s2.push(current);
            if (current->left) {
                s1.push(current->left);
            }
            if (current->right) {
                s1.push(current->right);
            }
        }
        while (!s2.isempty()) {
            node *a = s2.pop();
            cout << a->data;
        }
    }
};
int main() {
    tree t;
    char exp[50];
    cin >> exp;
    t.expression(exp);
    t.display(t.temp);
    return 0;
}