#ifndef BTREE_BTREE_H
#define BTREE_BTREE_H
#include "Node.h"
#include <iostream>


class Btree {
    Node *root;
    int T;
public:
    Btree(int T);
    Node * search(int key);
    void print();

    void addKey(int key);

    ~Btree();
};


#endif //BTREE_BTREE_H
