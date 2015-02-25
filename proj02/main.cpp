#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct node {
    int key;
    node * LL;
    node * RL;
    node(int keyy ) {
        key = keyy;
        LL = nullptr;
        RL = nullptr;
        cout << "node being created, with key = " << key << endl;
    }
};
class BST {
    public:
        BST() {root = nullptr;}
        ~BST() {destroy_BST(root);};
        node * getRoot() { return root;}
        void insert(int key) {
            if(root!=nullptr) {
                insert(key,root);
            }
            else {
                root = new node(key);
           }
        }
        void preorder() {
            if (root == nullptr) {
                cout << "Tree is smpty" << endl;
            }
            else {
                preorder(root);
                cout << endl;
            }
        }
        void inorder() {
            if(root == nullptr) {
                cout << "Tree is empty" << endl;
            }
            else {
                inorder(root);
                cout << endl;
            }
        }
        void postorder() {
            if(root == nullptr) {
                cout << "Tree is empty" << endl;
            }
            else {
                postorder(root);
                cout << endl;
            }
        }
        void display(node * ptr, int level) {
            int i;
            if(ptr != nullptr) {
                display(ptr->RL, level + 1);
                cout << endl;
                if (ptr == root) {
                    cout << "Root->: ";
                }
                else {
                    for(i = 0; i < level; i++) {
                        cout << "        ";
                    }
                }
                cout << ptr->key;
                display(ptr->LL, level+1);
            }
        }
    private:
        node* root;
        void preorder(node* ptr) {
            if(ptr == nullptr) {
            }
            else {
                cout << ptr->key << " ";
                preorder(ptr->LL);
                preorder(ptr->RL);
            }
        }
        void inorder(node* ptr) {
            if(ptr != nullptr) {
                inorder(ptr->LL);
                cout << ptr->key << " ";
                inorder(ptr->RL);
            }     
        }
        void postorder(node* ptr) {
            if(ptr != nullptr) {
            postorder(ptr->LL);
            postorder(ptr->RL);
            cout << ptr->key << " ";
        }
        }
        void destroy_BST(node * leaf) {
            if(leaf != nullptr) {
                destroy_BST(leaf->LL);
                destroy_BST(leaf->RL);
                delete leaf;
            }
        }
         void insert(int key, node * inputNode) {
            if(inputNode == nullptr) {
                inputNode = new node(key);
            }
            else if(key < inputNode->key) {
                if(inputNode->LL != nullptr) {
                    insert(key, inputNode->LL);
                }
                else {
                    inputNode->LL = new node(key);
                }
            }
            else if (key > inputNode->key) {
                if(inputNode->RL != nullptr) {
                    insert(key, inputNode->RL);
                }
                else {
                    inputNode->RL = new node(key);
                }
            }
        } 
};


int main() {
    string filename = "";
    string intstring = "";
    int keyint;
    cout << "Please enter a file name: " << endl;
    cin >> filename;
    ifstream file(filename);
    BST* btree = new BST();
    while(file >> intstring) {
        keyint = stoi(intstring);
        btree->insert(keyint);
    }
    btree->display(btree->getRoot(), 1);
    cout << endl;
    btree->preorder();
    btree->inorder();
    btree->postorder();
}
