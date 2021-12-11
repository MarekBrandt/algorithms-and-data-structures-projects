#include <iostream>
#include "bidirectionalList.h"

int main() {
    char cmd[20];
    int key;
    bidirectionalList list;

    while (scanf("%s", &cmd) != EOF) {
        if (strcmp(cmd, "ADD_BEG") == 0) {
            scanf("%d", &key);
             list.ADD(key, beg);
        } else if (strcmp(cmd, "ADD_END") == 0) {
            scanf("%d", &key);
            list.ADD(key, end);
        } else if (strcmp(cmd, "PRINT_FORWARD") == 0) {
            list.PRINT_FORWARD();
        } else if (strcmp(cmd, "PRINT_BACKWARD") == 0) {
            list.PRINT_BACKWARD();
        } else if (strcmp(cmd, "DEL_BEG") == 0) {
            list.DEL(beg);
        } else if (strcmp(cmd, "DEL_END") == 0)
        {
            list.DEL(end);
        } else if (strcmp(cmd, "SIZE") == 0)
        {
            printf("%d\n", list.SIZE());
        } else if (strcmp(cmd, "PUSH") == 0) {
            scanf("%d", &key);
            list.PUSH(key);
        } else if (strcmp(cmd, "POP") == 0) {
            scanf("%d", &key);
            list.POP(key);
        } else if (strcmp(cmd, "PRINT_QUEUE") == 0) {
            list.PRINT_QUEUE();
        } else if (strcmp(cmd, "COUNT") == 0)
        {
            printf("%d\n", list.COUNT());
        } else if (strcmp(cmd, "GARBAGE_SOFT") == 0) {
            list.GARBAGE_SOFT();
        } else if (strcmp(cmd, "GARBAGE_HARD") == 0) {
            list.GARBAGE_HARD();
        }
    }
}