#ifndef BTREE_NODE_H
#define BTREE_NODE_H


class Node {
    int *keys;
    Node ** children;
    int T;
    int numberOfKeys;
    bool isALeaf;
public:
    Node(int T, bool isALeaf);
    Node * search(int key);
    void goThroughTheTree(int mode); // mode 0 - print / mode 1 - release memory
    //assumption is that node is not full
    void addKeyToNodeWhichIsNotFull(int key);
    //split full child node
    void splitChild(int indexInChildrensArray, Node *nodeToSplit);
    friend class Btree;
    ~Node();
};


#endif //BTREE_NODE_H
