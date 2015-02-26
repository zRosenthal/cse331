#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//node struct
//3 attributes: a left and right ptr, and a node key
struct node {
    int key;
    node * LL;
    node * RL;
    //node constructor
    //sets LL and RL to nullptr and sets key
    node(int keyy ) {
        key = keyy;
        LL = nullptr;
        RL = nullptr;
        cout << "node being created, with key = " << key << endl;
    }
};
//BST class
//one attribute - ptr to root node
class BST {
    public:
        //constructor sets root = nullptr
        BST() {root = nullptr;}
        //destructor calls destroy_BST
        ~BST() {destroy_BST(root);};
        //returns root node
        node * getRoot() { return root;}
        //if BST is emtpy root is set to a new node with key passed in
        //otherwise a call is made to the private insert function
        void insert(int key) {
            if(root!=nullptr) {
                insert(key,root);
            }
            else {
                root = new node(key);
           }
        }
        //checks if bst is empty else call private preorder
        void preorder() {
            if (root == nullptr) {
                cout << "Tree is smpty" << endl;
            }
            else {
                preorder(root);
                cout << endl;
            }
        }
        //checks if bst is empty else calls private inorder
        void inorder() {
            if(root == nullptr) {
                cout << "Tree is empty" << endl;
            }
            else {
                inorder(root);
                cout << endl;
            }
        }
        //checks if bst is empty else calls private postorder
        void postorder() {
            if(root == nullptr) {
                cout << "Tree is empty" << endl;
            }
            else {
                postorder(root);
                cout << endl;
            }
        }
        //an attept to display the tree
        //not part of the project you can ignore it
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
        //private preorder function
        //recursive function checks if ptr is equal to nullptr else
        //outputs the nodes key and calls preorder on the LL and then RL
        void preorder(node* ptr) {
            if(ptr == nullptr) {
            }
            else {
                cout << ptr->key << " ";
                preorder(ptr->LL);
                preorder(ptr->RL);
            }
        }
        //checks if ptr = nullptr
        //recursive function then calls itself for the LL then outputs 
        //the key and calls itself on the RL
        void inorder(node* ptr) {
            if(ptr != nullptr) {
                inorder(ptr->LL);
                cout << ptr->key << " ";
                inorder(ptr->RL);
            }     
        }
        //recursive postorder function
        //checks if ptr is equal to nullptr
        //then calls itself on the LL then on the RL then outputs its key 
        void postorder(node* ptr) {
            if(ptr != nullptr) {
            postorder(ptr->LL);
            postorder(ptr->RL);
            cout << ptr->key << " ";
        }
        }
        //recursive function calls itself on LL then RL then deletes the
        //node
        void destroy_BST(node * leaf) {
            if(leaf != nullptr) {
                destroy_BST(leaf->LL);
                destroy_BST(leaf->RL);
                delete leaf;
            }
        }

        //inserts a new key into the tree rotted by inputNode
        //checks if input node is == to nullptr then sets a new node
        //with key as the inputNode
        //else if key is less then inputNodes key
        //calls itself on the LL if LL is not equal to nullptr
        //else sets the LL = to a new node with key = key
        //if key > inputNodes key and RL != nullptr then call itself
        //else set RL = to a new node with key = key
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
