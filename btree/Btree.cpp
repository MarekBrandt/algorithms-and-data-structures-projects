#include "Btree.h"

Btree::Btree(int T)
    :root(nullptr), T(T){
}

Node *Btree::search(int key) {
    if(root!= nullptr) return root->search(key);
    else return nullptr;
}

void Btree::print() {
    if(root != nullptr) root->goThroughTheTree(0);
}

void Btree::addKey(int key) {
    if(root == nullptr) {
        root = new Node(T, true);
        root->keys[0] = key;
        root->numberOfKeys = 1;
    }
    else {
        if (root->numberOfKeys == 2*T -1) {
            Node *newRoot = new Node(T, false);

            newRoot->children[0] = root;

            newRoot->splitChild(0, root);

            int i = 0;
            if (newRoot->keys[0] < key) i++;
            newRoot->children[i]->addKeyToNodeWhichIsNotFull(key);

            root = newRoot;
        }
        else root->addKeyToNodeWhichIsNotFull(key);
    }
}

Btree::~Btree() {
    if(root != nullptr) root->goThroughTheTree(1);
}


