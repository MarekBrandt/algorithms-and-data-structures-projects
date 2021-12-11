#include <cstdio>
#include "XorList.h"

Node::Node(int key)
        : key(key), xorPtr(nullptr) {}

XorList::XorList()
        : beg(nullptr), end(nullptr), act(nullptr), prev(nullptr) {}

Node* XorList::giveXor(Node* first, Node* sec) { //on given pointers, it gives a xor of middle element,
    return (Node*)((uintptr_t)first ^ (uintptr_t)sec); //given adr of left el and xor of the middle it returns ptr to right
}

void XorList::ADD_BEG(int key) {
    Node* newNode = new Node(key);
    newNode->xorPtr = beg;
    if (beg == nullptr) { //no elements
        beg = act = end = newNode;
    }
    else if (beg == end) { //one element.
        beg->xorPtr = newNode;
        prev = beg = newNode;
    }
    else { //more elements
        Node* next = beg->xorPtr;
        beg->xorPtr = giveXor(newNode, next);
        if(act == beg) { prev = newNode;}
        beg = newNode;
    }
}

void XorList::ADD_END(int key) {
    Node* newNode = new Node(key);
    newNode->xorPtr = end;
    if (end == nullptr) { //no elements
        beg = act = end = newNode;
    }
    else if (beg == end) { //one element
        end->xorPtr = newNode;
        end = newNode;
    }
    else { //more elements
        Node* predecessor = end->xorPtr;
        end->xorPtr = giveXor(newNode, predecessor);
        end = newNode;
    }
}

void XorList::ADD_ACT(int key) {
    Node* newNode = new Node(key);
    if (end == nullptr) { //no elements
        beg = act = end = newNode;
    }
    else if (beg == end) { //one element
        ADD_BEG(key);
    }
    else { //more elements
        if (act == beg) { ADD_BEG(key); prev = beg; }
        else
        {
            Node * firstBeforeNew = prev, * secondBeforeNew, * firstAfterNew = act, * secondAfterNew;

            //insert a node and change xor values
            newNode->xorPtr = giveXor(firstBeforeNew, firstAfterNew);
            secondBeforeNew = giveXor(firstBeforeNew->xorPtr, firstAfterNew);
            firstBeforeNew->xorPtr = giveXor(secondBeforeNew, newNode);
            secondAfterNew = giveXor(firstAfterNew->xorPtr, firstBeforeNew);
            firstAfterNew->xorPtr = giveXor(secondAfterNew, newNode);

            prev = newNode;
        }
    }
}

void XorList::ACTUAL() const{
    if (act == nullptr) { printf("NULL\n"); }
    else { printf("%d\n", act->key); }
}

void XorList::NEXT() {
    if (act == nullptr) { printf("NULL\n"); }
    else {
        Node* temp = act;
        act = giveXor(act->xorPtr, prev);
        prev = temp;

        if (act == nullptr) { act = beg; prev = nullptr; }

        printf("%d\n", act->key);
    }
}

void XorList::PREV(MODES mode) { //modes showAndMove or justMove
    if (act == nullptr) { printf("NULL\n"); }
    else {
        if (prev == nullptr) { act = end; prev = end->xorPtr; }
        else
        {
            Node* temp = giveXor(prev->xorPtr, act);
            act = prev;
            prev = temp;
        }

        if (mode == showAndMove) printf("%d\n", act->key);
    }
}

void XorList::PRINT(DIRECTIONS direction) const{
    if (beg == nullptr) { printf("NULL\n"); return;}
    Node* predecessor, * curr, * successor;
    predecessor = nullptr;
    direction == forward ? curr = beg : curr = end;
    while (curr != nullptr) { //loop through the list
        printf("%d ", curr->key);
        successor = giveXor(predecessor, curr->xorPtr);
        predecessor = curr;
        curr = successor;
    }
    printf("\n");
}

void XorList::DEL(WHICH_NODE which) {
    Node* nodeToDel = nullptr, *beforeNodeToDel = prev;
    switch (which) {
        case first:
            nodeToDel = beg; break;
        case actual:
            nodeToDel = act; break;
        case last:
            nodeToDel = end; break;
    }

    if (nodeToDel == nullptr) { //no elements
        return;
    }

    else if (beg == end) { //one element.
        beg = act = end = prev = nullptr;
        delete nodeToDel;
    }
        //more elements

        //first node to del
    else if (which == first) {
        if (act == beg) { PREV(justMove); }

        Node* firstAfter = beg->xorPtr, * secondAfter = giveXor(firstAfter->xorPtr, beg);
        firstAfter->xorPtr = secondAfter;
        beg = firstAfter;

        delete nodeToDel;
    }
        //last node to del
    else if ( which == last ) {
        if (act == end) { PREV(justMove); }

        Node* firstAfter = end->xorPtr, * secondAfter = giveXor(firstAfter->xorPtr, end); //firstAfter is element behind end, etc.
        firstAfter->xorPtr = secondAfter;
        end = firstAfter;

        delete nodeToDel;
    }
        //actual node to del
    else {
        if (beg == act) { DEL(first); }
        else if (act == end) { DEL(last); }
        else {

            PREV(justMove);
            DEL_NODE(nodeToDel, beforeNodeToDel);
        }
    }
}

void XorList::DEL_NODE(Node * nodeToDel, Node * firstBefore) {

    //it fills the xor cells in neighbours

    Node * secondBefore, * firstNext, * secondNext;
    secondBefore = giveXor(nodeToDel, firstBefore->xorPtr);
    firstNext = giveXor(nodeToDel->xorPtr, firstBefore);
    secondNext = giveXor(firstNext->xorPtr, nodeToDel);
    firstBefore->xorPtr = giveXor(secondBefore, firstNext);
    firstNext->xorPtr = giveXor(firstBefore, secondNext);

    delete nodeToDel;
}

void XorList::DEL_VAL(int key) {
    Node* predecessor = nullptr, * curr = beg, * successor;
    while (curr != nullptr) { //loop through the list
        if (curr->key == key)
        {
            if (beg == end) { delete curr; beg = prev = act = end = nullptr; break;}
            else if (curr == act) { DEL(actual); }
            else if (curr == beg) { DEL(first);  curr = nullptr;}
            else if (curr == end) { DEL(last); break; }//end of list, so end of iterating loop
            else {
                Node * toDel = curr;
                Node * firstBeforeToDel = predecessor;
                Node * secondBeforeToDel = giveXor(firstBeforeToDel->xorPtr, toDel);

                if(curr == prev) {prev = firstBeforeToDel;}

                DEL_NODE(toDel, firstBeforeToDel);

                curr = firstBeforeToDel;
                predecessor = secondBeforeToDel;
            }
        }
        if(curr == nullptr) { curr = beg; predecessor = nullptr;} // first element was deleted, so loop doesnt have to increment
        else
        {
            //going to next node
            successor = giveXor(predecessor, curr->xorPtr);
            predecessor = curr;
            curr = successor;
        }
    }
}



