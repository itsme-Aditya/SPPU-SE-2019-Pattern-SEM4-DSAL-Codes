#include <iostream>
using namespace std;

class stack {
public:
    int data[5], top;
    stack() {
        top = -1;
    }
    int isempty() {
        if (top == -1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int isfull() {
        if (top >= 5) {
            return 1;
        }
        else {
            return 0;
        }
    }
    void push(int x) {
        if (!isfull()) {
            top++;
            data[top] = x;
        }
        else {
            cout << "Stack is full!";
        }
    }
    int pop() {
        if (!isempty()) {
            int x = data[top];
            top--;
            return x;
        }
        else {
            cout << "Stack is already empty!";
            return 0;
        }
    }
    int topelem() {
        return data[top];
    }
};
class graph {
    int g[5][5];
public:
    graph() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == j) {
                    g[i][j] = -1;
                }
                else {
                    g[i][j] = 0;
                }
            }
        }
    }
    void display() {
        for (int i = 0; i < 5; i++) {
            cout << endl;
            for (int j = 0; j < 5; j++) {
                cout << " " << g[i][j];
            }
        }
        cout << endl;
    }
    void addedge(int x, int y) {
        if ((x < 0) || (x >= 5)) {
            cout << "Vertex" << x
                 << " does not exist!";
        }
        if ((y < 0) || (y >= 5)) {
            cout << "Vertex" << y
                 << " does not exist!";
        }
        if (x == y) {
            cout << "Same Vertex!";
        }
        else {
            g[y][x] = 1;
            g[x][y] = 1;
        }
    }
    void dfs(int start) {
        stack s;
        bool visit[5] = {false};
        s.push(start);
        visit[start] = true;
        cout << "DFS starting from vertex " << start << ": ";
        while(!s.isempty()) {
            int current = s.topelem();
            s.pop();
            cout << current << " ";
            for (int i = 0; i < 5; i++) {
                if (g[current][i] == 1 && !visit[i]) {
                    s.push(i);
                    visit[i] = true;
                }
            }
        }
        cout << endl;
    }
};
int main(){
    graph obj;
    obj.addedge(0, 1);
    obj.addedge(0, 2);
    obj.addedge(0, 3);
    obj.addedge(1, 2);
    obj.addedge(4, 2);
    obj.display();
    obj.dfs(0);
    return 0;
}

