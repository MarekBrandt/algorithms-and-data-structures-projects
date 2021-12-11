#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "XorList.h"

int main() {
    char cmd[20];
    int key;
    XorList list;

    while (scanf("%s", &cmd) != EOF)
    {
        if (strcmp(cmd, "ADD_BEG") == 0) {
            scanf("%d", &key);
            list.ADD_BEG(key);
        }
        else if (strcmp(cmd, "ADD_END") == 0) {
            scanf("%d", &key);
            list.ADD_END(key);
        }
        else if (strcmp(cmd, "ADD_ACT") == 0) {
            scanf("%d", &key);
            list.ADD_ACT(key);
        }
        else if (strcmp(cmd, "PRINT_FORWARD") == 0) {
            list.PRINT(forward);
        }
        else if (strcmp(cmd, "PRINT_BACKWARD") == 0) {
            list.PRINT(backward);
        }
        else if (strcmp(cmd, "ACTUAL") == 0) {
            list.ACTUAL();
        }
        else if (strcmp(cmd, "NEXT") == 0) {
            list.NEXT();
        }
        else if (strcmp(cmd, "PREV") == 0) {
            list.PREV(showAndMove);
        }
        else if (strcmp(cmd, "DEL_BEG") == 0) {
            list.DEL(first);
        }
        else if (strcmp(cmd, "DEL_END") == 0) {
            list.DEL(last);
        }
        else if (strcmp(cmd, "DEL_ACT") == 0) {
            list.DEL(actual);
        }
        else if (strcmp(cmd, "DEL_VAL") == 0) {
            scanf("%d", &key);
            list.DEL_VAL(key);
        }
    }

    return 0;
}
