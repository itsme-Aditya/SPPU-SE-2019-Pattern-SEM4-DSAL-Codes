#include <iostream>
using namespace std;

class node {
public:
    int key;
    string value;
    node *left, *right;
    node(int key, string value) {
        this->key = key;
        this->value = value;
        left = right = NULL;
    }
};
class bst {
public:
    node *root;
    bst() {
        root = NULL;
    }
    bool insert(int key, string value) {
        if (root == NULL) {
            root = new node(key, value);
            return 1;
        }
        else {
            node *temp, *prev;
            temp = prev = root;
            while (temp != NULL) {
                prev = temp;
                if (temp->key == key) {
                    return 0;
                }
                else if (temp->key > key) {
                    temp = temp->left;
                }
                else {
                    temp = temp->right;
                }
            }
            if (prev->key > key) {
                prev->left = new node(key, value);
            }
            else {
                prev->right = new node(key, value);
            }
            return 1;
        }
    }
    node *deleteNode(node *root, int key) {
        if (root == NULL) {
            return root;
        }
        if (root->key < key) {
            deleteNode(root->left, key);
        }
        else if (root->key > key) {
            deleteNode(root->right, key);
        }
        else {
            if (root->left == NULL) {
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->left == NULL) {
                node *temp = root->left;
                delete root;
                return temp;
            }
            node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->value = temp->value;
            deleteNode(root->right, temp->key);
        }
        return root;
    } 
    node* minValueNode(node* node) {
        node* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }
    void display(node *starting) {
        if (starting == NULL) {
            return;
        }
        else {
            display(starting->left);
            cout << starting->key << " : " << starting->value << endl;
            display(starting->right);
        }
    }
    string search(int key) {
        node *temp = root;
        while (temp != NULL) {
            if (temp->key == key) {
                return temp->value;
            }
            else if (temp->key < key) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }
        return "\0";
    }
    bool update(int key, string value) {
        node *temp = root;
        while (temp != NULL) {
            if (temp->key == key) {
                temp->value = value;
                return 1;
            }
            else if (temp->key < key) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }
        return 0;
    }
};
int main () {
    bst obj;
    obj.insert(10, "A");
    obj.insert(5, "B");
    obj.insert(15, "C");
    obj.insert(3, "D");
    obj.display(obj.root);
    obj.update(15, "E");
    cout << endl << endl;
    obj.display(obj.root);
    return 0;
}
