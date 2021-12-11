#ifndef XORLIST_XORLIST_H
#define XORLIST_XORLIST_H

enum DIRECTIONS {
    forward,
    backward
};

enum MODES {
    showAndMove,
    justMove
};

enum WHICH_NODE {
    first,
    actual,
    last
};

struct Node {
    int key;
    Node * xorPtr;
    explicit Node(int key);
};

class XorList {
    Node *beg, *end, *act, *prev;
public:
    XorList();

    //given pointer and xor in the neighbour, returns a pointer to the next one
    //given pointers to neighbours of node, returns xor that should it contain
    static Node* giveXor(Node* first, Node* sec);

    void ADD_BEG(int key);

    void ADD_END(int key);

    void ADD_ACT(int key);

    //prints a value of act node
    void ACTUAL() const;

    //move act pointer to next node
    void NEXT();

    //move act pointer to prev node, or if it's beg node, to the end node
    //modes: justMove or showAndMove
    void PREV(MODES mode);

    //prints whole list, forward or backward
    void PRINT(DIRECTIONS direction) const;

    //delete nodes with arguments: first, actual or last
    void DEL(WHICH_NODE which);

    //delete node with value = key
    void DEL_VAL(int key);

    //delete node. Needed pointer to a node to delete, and to the previous one.
    static void DEL_NODE(Node * nodeToDel, Node * firstBefore);

};


#endif //XORLIST_XORLIST_H
