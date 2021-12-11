#include <iostream>
#include "Btree.h"

using namespace std;

int main() {
    char cmd[20];
    int key;
    bool exit = false;

    bool treeExists = false;
    Btree *t;

    while (exit == 0 && scanf("%s", &cmd) != EOF) {
        if (strcmp(cmd, "A") == 0) {
            scanf("%d", &key);
            t->addKey(key);
            treeExists = true;
        } else if (strcmp(cmd, "I") == 0) {
            scanf("%d", &key);
            if(treeExists) delete t;
            t = new Btree(key);
        } else if (strcmp(cmd, "?") == 0) {
            scanf("%d", &key);
            t->search(key) == nullptr ? printf("%d -\n", key ) : printf("%d +\n", key);
        } else if (strcmp(cmd, "P") == 0) {
            t->print();
        } else if (strcmp(cmd, "X") == 0) {
            if(treeExists) delete t;
            exit = true;
        }
    }

    return 0;
}
