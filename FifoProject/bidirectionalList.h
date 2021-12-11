//
// Created by marek on 20.04.2021.
//

#ifndef FIFOPROJECT_BIDIRECTIONALLIST_H
#define FIFOPROJECT_BIDIRECTIONALLIST_H

enum where {
    beg,
    end
};

struct Elem {
    int key;
    Elem * next, *prev;
    Elem(Elem * e, Elem * f, int k) : next(e), prev(f), key(k) {}
};

class bidirectionalList {
    Elem * first, *last, *front, *back;
public:
    bidirectionalList();

    void ADD(int key, where place);

    void PRINT_FORWARD();

    void PRINT_BACKWARD();

    void DEL(where place);

    int SIZE();

    void PUSH(int key);

    void POP(int key);

    void PRINT_QUEUE();

    int COUNT();

    void GARBAGE_SOFT();

    void GARBAGE_HARD();

};


#endif //FIFOPROJECT_BIDIRECTIONALLIST_H
