#include "bidirectionalList.h"
#include <cstdio>

bidirectionalList::bidirectionalList() : first(nullptr), last(nullptr), front(nullptr), back(nullptr) {}

void bidirectionalList::ADD(int key, where place) {
    Elem * newElem = new Elem(nullptr, nullptr, key);
    if(!first) {
        first = last = newElem;
        newElem->next = newElem->prev = newElem;
    }
    else {
        newElem->next = first;
        newElem->prev = last;
        first->prev = newElem;
        last->next = newElem;
        place == beg ? first = newElem : last = newElem;
    }
}

void bidirectionalList::PRINT_FORWARD() {
    if(!first) printf("NULL\n");
    else {
        Elem * tmp = first;
        while(tmp != last) {
            printf("%d ", tmp->key);
            tmp = tmp->next;
        }
        printf("%d\n", last->key);
    }
}

void bidirectionalList::PRINT_BACKWARD() {
    if(!first) printf("NULL\n");
    else {
        Elem * tmp = last;
        while(tmp != first) {
            printf("%d ", tmp->key);
            tmp = tmp->prev;
        }
        printf("%d\n", first->key);
    }
}

void bidirectionalList::DEL(where place) {
    if(!first) return;
    else if (first == last) {
        delete first;
        first = last = front = back = nullptr;
    }
    else {
        Elem * whichNode = (place == beg ? first : last);
        Elem * next = whichNode->next;
        Elem * prev = whichNode->prev;
        next->prev = prev;
        prev->next = next;
        place == beg ? first = next : last = prev;
        if(whichNode == back) {
            back = next;
        }
        else if(whichNode == front) {
            front = prev;
        }
        delete whichNode;
    }
}

int bidirectionalList::SIZE() {
    if(!first) return 0;
    int len = 1;
    Elem * tmp = first;
    while(tmp->next != first) {
        tmp = tmp->next;
        len++;
    }
    return len;
}

void bidirectionalList::PUSH(int key) {
    if(!last) {
        ADD(key,end);
        front = back = last;
    }
    else if (!back) {
        last->key = key;
        front = back = last;
    }
    else if (back->prev != front) {
        back = back->prev;
        back->key = key;
    }
    else {
        Elem * newNode = new Elem(nullptr, nullptr, key);
        front->next = newNode;
        back->prev = newNode;
        if(back == first) first = newNode;
        newNode->next = back;
        newNode->prev = front;
        back = newNode;
    }
}

void bidirectionalList::POP(int key) {
    if(!back) { printf("NULL\n"); }
    else if (front == back) {
        printf("%d\n", front->key);
        front = back = nullptr;
    }
    else {
        printf("%d\n", front->key);
        front = front->prev;
    }
}

void bidirectionalList::PRINT_QUEUE() {
    if(!front) printf("NULL\n");
    else {
        Elem *tmp = front;
        while (tmp != back) {
            printf("%d ", tmp->key);
            tmp = tmp->prev;
        }
        printf("%d\n", back->key);
    }
}

int bidirectionalList::COUNT() {
    if(!front) return 0;
    int len = 1;
    Elem * tmp = front;
    while(tmp != back) {
        tmp = tmp->prev;
        len++;
    }
    return len;
}

void bidirectionalList::GARBAGE_SOFT() {
    if(!front) {
        if(!first) return;
        Elem * tmp = first;
        while(tmp->next != first) {
            tmp->key = 0;
            tmp = tmp->next;
        }
        tmp->key = 0;
    }
    else {
        Elem * tmp = front->next;
        while(tmp != back) {
            tmp->key = 0;
            tmp = tmp->next;
        }
    }
}

void bidirectionalList::GARBAGE_HARD() {
    if(!front) {
        if(!first) return;
        Elem * tmp = first;
        while(tmp->next != first) {
            Elem * tmp2 = tmp;
            tmp = tmp->next;
            delete tmp2;
        }
        delete tmp;
        first = last = nullptr;
    }
    else {
        Elem * tmp = front->next;
        while(tmp != back) {
            Elem * tmp2 = tmp;
            tmp = tmp->next;
            delete tmp2;
        }
        front->next = back;
        back->prev = front;
    }
}
