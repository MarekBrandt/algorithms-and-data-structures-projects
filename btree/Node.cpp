#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int T, bool isALeaf)
    : T(T), isALeaf(isALeaf), numberOfKeys(0){
    children = new Node *[2 * T];
    keys = new int[2*T-1];
}

Node *Node::search(int key) {
    int i = 0;
    while (i < numberOfKeys && key > keys[i])
        i++;

    if (keys[i] == key)
        return this;

    //if not found, and node is leaf, then not found
    if (isALeaf)
        return nullptr;

    return children[i]->search(key);
}

void Node::goThroughTheTree(int mode) {
    int i;
    for(i = 0; i < numberOfKeys; i++) {
        //going through n keys, but if it is not a leaf
        //go to a subtree before key
        if(!isALeaf) {
            children[i]->goThroughTheTree(mode);
        }
        if(mode == 0) cout << keys[i] << " "; //print keys
    }
    //go to n+1 child subtree
    if(!isALeaf) {
        children[i]->goThroughTheTree(mode);
    }
    if( mode ) { //used to release node memory
        delete this;
    }
}

void Node::addKeyToNodeWhichIsNotFull(int key) {
    //index will be last key index
    int i = numberOfKeys-1;

    if(isALeaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i+1] = keys[i];
            i--;
        }

        //now i+1 will be place, where we found a place
        keys[i+1] = key;
        numberOfKeys++;
    }
    else {
        while (i >= 0 && keys[i] > key) i--;

        //check, if found node is full
        if (children[i + 1]->numberOfKeys == 2 * T - 1 ) {
            splitChild(i+1, children[i + 1]);
            if (keys[i+1] < key) i++;
        }
        children[i + 1]->addKeyToNodeWhichIsNotFull(key);
    }
}

void Node::splitChild(int indexInChildrensArray, Node *nodeToSplit) {
    //make a node, which will contain half of the nodes of y
    Node *newNode = new Node(nodeToSplit->T, nodeToSplit->isALeaf);
    newNode->numberOfKeys = T-1;

    //copy T-1 keys from y to newNode
    for (int i = 0; i < T-1; i++) {
        newNode->keys[i] = nodeToSplit->keys[i+T];
    }

    if(!(nodeToSplit->isALeaf)) {
        for (int i = 0; i < T; i++) {
            newNode->children[i] = nodeToSplit->children[i + T];
        }
    }
    nodeToSplit->numberOfKeys = T-1;

    //make space in children array for newNode
    for (int i = numberOfKeys; i >= indexInChildrensArray+1; i--) {
        children[i + 1] = children[i];
    }

    children[indexInChildrensArray + 1] = newNode;

    //make space in this node for middle key of splitted one
    for (int i = numberOfKeys-1; i >= indexInChildrensArray; i--) {
        keys[i+1] = keys[i];
    }
    keys[indexInChildrensArray] = nodeToSplit->keys[T-1];
    numberOfKeys++;
}

Node::~Node() {
    delete [] children;
    delete [] keys;
}
