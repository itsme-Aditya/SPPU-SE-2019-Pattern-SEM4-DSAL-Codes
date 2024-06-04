#include <iostream>
using namespace std;

class node {
public:
    string name;
    int chapters;
    node *child[10];
    node() {
        for (int i = 0; i < 10; i++) {
            child[i] = NULL;
        }
    }
};
class tree {
public:
    node *root;
    tree() {
        root = NULL;
    }
    void create() {
        root = new node;

        cout << "Enter name of the book: ";
        cin >> root->name;
        cout << "Enter number of chapters: ";
        cin >> root->chapters;

        for (int i = 0; i < root->chapters; i++) {

            root->child[i] = new node;
            cout << "Enter name of the chapter: ";
            cin >> root->child[i]->name;
            cout << "Enter number of sections: ";
            cin >> root->child[i]->chapters;

            for (int j = 0; j < root->child[i]->chapters; j++) {
                root->child[i]->child[j] = new node;
                cout << "Enter name of the section: ";
                cin >> root->child[i]->child[j]->name;
                cout << "Enter number of sub-sections: ";
                cin >> root->child[i]->child[j]->chapters;

                for (int k = 0; k < root->child[i]->child[j]->chapters; k++) {
                    root->child[i]->child[j]->child[k] = new node;
                    cout << "Enter name of the sub-section: ";
                    cin >> root->child[i]->child[j]->child[k]->name;
                }
            }
        }
    }
	void display() {
		cout << "Name of book: " << root->name;
		cout << "Number of chapters: " << root->chapters;
		for (int i = 0; root->chapters; i ++) {
			cout << "Name of chapter: " << root->child[i]->name;
			cout << "Number of sections: " << root->child[i]->chapters;
			for (int j = 0; root->chapters; j ++) {
				cout << "Name of section: " << root->child[i]->child[j]->name;
				cout << "Number of sub-sections: " << root->child[i]->child[j]->chapters;
				for (int k = 0; root->chapters; k ++) {
					cout << "Name of sub-section: " << root->child[i]->child[j]->child[k]->name;
				}
			}
		}
	}
};
int main() {
    tree book;
    book.create();
	book.display();
    return 0;
}
