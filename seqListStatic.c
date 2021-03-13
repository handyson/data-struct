#include <stdio.h>

#define SIZE 5

typedef struct {
    int data[SIZE];
    int length;
}SeqList;

void InitSeqList(SeqList *list){
    for (int i=0; i<SIZE; i++) {
        (*list).data[i] = 0;
    }
    (*list).length = 0;
}

// 增
int Insert(SeqList *list, int i, int val) {
    if (i > (*list).length + 1 || i <= 0 || i > SIZE || (*list).length == SIZE)
    {
        return 1;
    }

    for (int a = (*list).length; a >= i; a--) {
        (*list).data[a] = (*list).data[a - 1];  
    }
    (*list).data[i - 1] = val;
    (*list).length++;
    return 0;
}

// 删（带回删除的值）
int Delete(SeqList *list, int i, int *val){
    if (i > (*list).length || i <= 0)
    {
        *val = -1;
        return 1;
    }

    *val = (*list).data[i - 1];
    for (int a = i - 1; a < (*list).length - 1; a++)
    {
        (*list).data[a] = (*list).data[a + 1];
    }
    (*list).length -= 1;

    return 0;
}

// 改
int Update(SeqList *list, int i, int val){
    if (i > list->length || i <= 0) {
        return 1;
    }

    (*list).data[i - 1] = val;

    return 0;
}

// 按值查找
int FindByVal(SeqList *list, int val){
    for (int a = 0; a < list->length; a++)
    {
        if (list->data[a] == val) {
            return a + 1;
        }
    }
    return 0;
}

// 按位查找
int FindByLoc(SeqList *list, int i)
{
    if (i > list->length) {
        return 0;
    }
    return list->data[i - 1];
}

int main() {
    SeqList list;
    InitSeqList(&list);
    Insert(&list, 1, 55);
    Insert(&list, 1, 44);
    Insert(&list, 1, 33);
    Insert(&list, 1, 22);
    Insert(&list, 1, 11);
    Insert(&list, 1, 8888);

    // int e = -1;
    // Delete(&list, 2, &e);
    // printf("删除了：%d\n", e);
    // Delete(&list, SIZE + 1, &e);
    // printf("删除了：%d\n", e);

    // Update(&list, 1, 111);
    // Update(&list, 3, 333);
    // Update(&list, SIZE + 1, 666);

    // int loc = FindByVal(&list, 22);
    // if (loc == 0)
    // {
    //     printf("值不存在\n");
    // } else
    // {
    //     printf("是第%d个元素\n", loc);
    // }

    // int val;
    // val = FindByLoc(&list, 2);
    // printf("值为：%d\n", val);

    // 输出
    for (int i=0; i<list.length; i++) {
        printf("index-%d：%d\n", i, list.data[i]);
    }
    printf("长度：%d\n", list.length);

    return 0;
}
