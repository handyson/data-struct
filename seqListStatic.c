#include <stdio.h>

#define SIZE 5

typedef struct {
    int ele[SIZE];
    int length;
}SeqList;

void InitSeqList(SeqList *list){
    for (int i=0; i<SIZE; i++) {
        (*list).ele[i] = 0;
    }
    (*list).length = 0;
}

int main() {
    SeqList list;
    InitSeqList(&list);

    for (int i=0; i<SIZE; i++) {
        printf("%d\n", list.ele[i]);
    }

    return 0;
}