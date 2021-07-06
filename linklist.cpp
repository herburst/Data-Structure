#include<stdlib.h>
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;

//单链表初始化
Status InitLink(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    return OK;
}

//单链表取值
Status GetElem(LinkList L, int i, int &e) {
    LinkList p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    e = p->data;
    return OK;
}

//单链表按值查找
LNode *LocateElem(LinkList L, int e)
{
    LinkList p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}

//单链表插入
Status ListInsert(LinkList &L, int i, int e)
{
    LinkList p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i - 1) return ERROR;
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

//单链表删除
Status ListDelete(LinkList &L, int i)
{
    LinkList p = L;
    int j = 0;
    while ((p->next) && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if(!(p->next) || (j > i - 1)) return ERROR;
    LNode *q = p->next;
    p->next = q->next;
    delete q;
    return OK;
}

//单链表头插法
void CreateList_H(LinkList &L, int n)
{
    L = new LNode;
    L->next = NULL;
    LNode *p;
    for(int i = 0; i < n; ++i)
    {
        p = new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

//单链表尾插法
void CreateList_R(LinkList &L, int n)
{
    LinkList L = new LNode;
    L->next = NULL;
    LNode *r = L;
    for(int i = 0; i < n; i++)
    {
        LNode *p = new LNode;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

//有序表合并 时间复杂度O(m+n) 空间复杂度O(1)
void MergeList_L(LinkList &LA, LinkList &LB, LinkList &LC)
{
    LNode *pa = LA->next;
    LNode *pb = LB->next;
    LC = LA;
    LNode *pc = LC;
    while (pa && pb)
    {
        if(pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    delete LB;
}

