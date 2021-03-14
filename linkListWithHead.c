#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} LNode, *LinkList;

// 尾插法建立单链表
LinkList CreateListByTailInsert();
// 头插法建立单链表
LinkList CreateListByHeadInsert();
// 插入
int Insert(LinkList list, int i, int data);
// 向后插入一个节点
int InsertNextNode(LNode *p, int data);
// 向前插入一个节点
int InsertPriorNode(LNode *p, int data);
// 删除指定节点
int DeleteByNode(LNode *node);
// 删除指定位序
int DeleteByIndex(LinkList list, int i);
// 按位查找
LNode * GetNodeByIndex(LinkList list, int i);
// 按值查找
LNode * GetNodeByValue(LinkList list, int data);
// 获取长度
int Length(LinkList lists);

int main()
{
    // LinkList L = (LinkList)malloc(sizeof(LNode));
    // L->next = NULL; // 注：NULL是在<stdlib.h>中定义的宏

    // 尾插法建立单链表
    LinkList L = CreateListByTailInsert();

    // // 头插法建立单链表
    // LinkList L = CreateListByHeadInsert();

    // Insert(L, 1, 11);
    // Insert(L, 2, 22);
    // Insert(L, 3, 33);
    // Insert(L, 4, 44);

    // // 测试前插
    // InsertPriorNode(L->next, 8888);

    // // 删除指定节点
    // LNode *node = L->next->next;
    // DeleteByNode(node);

    // // 按位序删除
    // DeleteByIndex(L, 2);

    // // 按位查找
    // int i = 5;
    // LNode *node = GetNodeByIndex(L, i);
    // if (node != NULL)
    // {
    //     printf("按位查找第%d个节点值为%d\n", i, node->data);
    // } else {
    //     printf("节点不存在\n");
    // }

    // // 按值查找
    // int val = 33;
    // LNode *node = GetNodeByValue(L, val);
    // if (node != NULL){
    //     printf("按值查找值为%d的节点成功\n", node->data);
    // }
    // else{
    //     printf("节点不存在\n");
    // }

    // 获取长度
    // printf("链表长度为：%d\n", Length(L));

    do
    {
        printf("%d\n", L->data);
        L = L->next;
    } while (L != NULL);
}

// 尾插法建立单链表
LinkList CreateListByTailInsert(){
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *node, *end = L;

    int input;
    scanf("%d", &input);
    while (input != 9999){ // 9999表示结束输入
        // 创建新节点
        node = (LNode *)malloc(sizeof(LNode));
        node->data = input;
        node->next = NULL;

        end->next = node;
        end = node; // end始终指向尾节点

        scanf("%d", &input);
    }

    return L;
}

// 头插法建立单链表
LinkList CreateListByHeadInsert(){
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    int input;
    scanf("%d", &input);
    while (input != 9999) {
        LNode *node = (LNode *)malloc(sizeof(LNode));
        node->data = input;
        node->next = L->next;
        L->next = node;

        scanf("%d", &input);
    }

    return L;
}

int Insert(LinkList list, int i, int data)
{
    LNode *p = GetNodeByIndex(list, i - 1);
    if (p==NULL) {
        return 1;
    }

    // 向后插入节点
    InsertNextNode(p, data);

    return 0;
}

// 向后插入一个节点
int InsertNextNode(LNode *p, int data)
{
    if (p == NULL) {
        return 1;
    }

    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = data;
    node->next = p->next;
    p->next = node;

    return 0;
}

// 向前插入一个节点
int InsertPriorNode(LNode *p, int data){
    if (p == NULL)
    {
        return 1;
    }

    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->next = p->next;
    p->next = node;
    // 两个值换位，实现O（1）复杂度的前插操作
    node->data = p->data;
    p->data = data;
}

// 删除指定节点
int DeleteByNode(LNode *node)
{
    if (node == NULL) {
        return 1;
    }
    LNode *nextNode = node->next;
    node->data = nextNode->data;
    node->next = nextNode->next;
    free(nextNode);

    return 0;
}

// 删除指定位序
int DeleteByIndex(LinkList list, int i){
    LNode *p = list;
    int j = 0;
    while (p != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    LNode *destroyNode = p->next;
    p->next = p->next->next;
    free(destroyNode);

    return 0;
}

// 按位查找
LNode * GetNodeByIndex(LinkList list, int i){
    if (i < 0)
    {
        return NULL;
    }
    LNode *p;
    p = list;
    int j = 0; // 指向头节点，即第0个
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode * GetNodeByValue(LinkList list, int data)
{
    LNode *p;
    p = list->next; // 跳过头节点
    while (p != NULL && p->data != data)
    {
        p = p->next;
    }
    return p;
}

// 获取长度
int Length(LinkList list)
{
    LNode *p = list->next;
    int length = 0;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}