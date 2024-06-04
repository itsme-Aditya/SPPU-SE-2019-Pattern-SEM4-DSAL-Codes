#include <iostream>
using namespace std;

class graph {
    int g[4][4];
public:
    graph() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                g[i][j] = -1;
            }
        }
    }
    void display() {
        for (int i = 0; i < 4; i++) {
            cout << endl;
            for (int j = 0; j < 4; j++) {
                cout << " " << g[i][j];
            }
        }
        cout << endl;
    }
    void addedge(int x, int y, int z) {
        if ((x < 0) || (x >= 4)) {
            cout << "Vertex" << x
                 << " does not exist!";
        }
        if ((y < 0) || (y >= 4)) {
            cout << "Vertex" << y
                 << " does not exist!";
        }
        if (x == y) {
            cout << "Same Vertex!";
        }
        else {
            g[y][x] = z;
            g[x][y] = z;
        }
    }
    void prims() {
        int mincost = 0, row, col;
        int visit[4] = {0};
        visit[0] = 1;
        for (int k = 0; k < 3; k++) {
            int min = 9999;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (visit[i] == 1 && visit[j] == 0) {
                        if (g[i][j] != -1 && min > g[i][j]) {
                            min = g[i][j];
                            row = i;
                            col = j;
                        }
                    }
                }
            }
            mincost += min;
            visit[col] = visit[row] = 1;
            g[row][col] = g[col][row] = -1;
            cout << row << "->" << col << endl;
        }
        cout << "\nMinimum Cost: " << mincost;
    }
    
};

int main() {
    graph g;
    g.addedge(0, 1, 5);
    g.addedge(0, 2, 4);
    g.addedge(0, 3, 7);
    g.addedge(1, 2, 2);
    g.addedge(1, 3, 3);
    g.addedge(2, 3, 6);
    g.display();
    cout << endl << endl;
    g.prims();
    g.display();    
    return 0;
}
