#include <stdio.h>
#include <stdlib.h>

#define DefaultSize 5

typedef struct{
    int *data;
    int maxSize;
    int length;
} SeqList;

// 初始化
void InitList (SeqList *list) {
    (*list).data = (int *)malloc(DefaultSize * sizeof(int));
    (*list).maxSize = DefaultSize;
    (*list).length = 0;
}

// 扩容
void IncreaseSize(SeqList *list, int size){
    int *p = list->data;
    list->data = (int *)malloc((list->maxSize + size) * sizeof(int));
    for (int i = 0; i < list->length; i++) {
        list->data[i] = p[i];
    }
    free(p);
    list->maxSize += size;
}

// 增
int Insert(SeqList *list, int i, int val)
{
    if (i > list->length + 1 || i > list->maxSize || i <= 0 || list->length == list->maxSize)
    {
        return 1;
    }

    for (int a = (*list).length; a >= i; a--)
    {
        (*list).data[a] = (*list).data[a - 1];
    }
    (*list).data[i - 1] = val;
    (*list).length++;
    return 0;
}

// 删（带回删除的值）
int Delete(SeqList *list, int i, int *val)
{
    if (i > (*list).length || i <= 0)
    {
        *val = -1;
        return 1;
    }

    *val = (*list).data[i - 1];
    for (int a = i; a < (*list).length; a++)
    {
        (*list).data[a - 1] = (*list).data[a];
    }
    (*list).length -= 1;

    return 0;
}

// 改
int Update(SeqList *list, int i, int val)
{
    if (i > list->length || i <= 0)
    {
        return 1;
    }

    (*list).data[i - 1] = val;

    return 0;
}

// 按值查找
int FindByVal(SeqList *list, int val)
{
    for (int a = 0; a < list->length; a++)
    {
        if (list->data[a] == val)
        {
            return a + 1;
        }
    }
    return 0;
}

// 按位查找
int FindByLoc(SeqList *list, int i)
{
    if (i > list->length)
    {
        return 0;
    }
    return list->data[i - 1];
}

int main(void){
    SeqList list;
    InitList(&list);

    Insert(&list, 1, 55);
    Insert(&list, 1, 44);
    Insert(&list, 1, 33);
    Insert(&list, 1, 22);
    Insert(&list, 1, 11);
    Insert(&list, 1, 88988);    // 越界，插入无效

    // IncreaseSize(&list, 5); // 扩容
    // Insert(&list, 1, 8888);
    // Insert(&list, 1, 9999);

    // int e = -1;
    // Delete(&list, 1, &e);
    // printf("删除了：%d\n", e);
    // Delete(&list, list.length + 1, &e);
    // printf("删除了：%d\n", e);

    // Update(&list, 1, 111);
    // Update(&list, 3, 333);
    // Update(&list, list.length + 1, 666);

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

    for (int i=0; i < list.length; i++) {
        printf("%d\n", list.data[i]);
    }
    printf("长度：%d\n", list.length);
    printf("容量：%d\n", list.maxSize);
}