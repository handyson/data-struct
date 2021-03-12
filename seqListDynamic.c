#include <stdio.h>
#include <stdlib.h>

#define DefaultSize 5

typedef struct{
    int *data;
    int maxSize;
    int length;
} SeqList;

void InitList (SeqList *list) {
    (*list).data = (int *)malloc(DefaultSize * sizeof(int));
    (*list).maxSize = DefaultSize;
    (*list).length = 0;
}


int main(void){
    SeqList list;
    InitList(&list);

    for (int i=0; i < list.length; i++) {
        printf("%d\n", list.data[i]);
    }
}