#include<stdlib.h>
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;

typedef struct
{
    float coef; //系数
    int expn; //指数
} Polynomial;

typedef struct
{
    Polynomial *elem;
    int length;
} SqList;

//初始化顺序表
Status InitList(SqList &L)
{
    L.elem = new Polynomial[MAXSIZE];
    if (!L.elem)
    {
        exit(OVERFLOW);
    }
    L.length = 0;
    return OK;    
}

//查找第i个元素
Status GetElem(SqList L, int i, Polynomial &e)
{
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }
    e = L.elem[i - 1];
    return OK;
}

//查找元素
int LocateElem(SqList L, Polynomial e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i].coef == e.coef && L.elem[i].expn == e.expn)
        {
            return i + 1;
        }
    }
    return 0;
}

//插入元素
Status ListInsert(SqList &L, int i, Polynomial e)
{
    if (i < 1 || i > L.length + 1) return ERROR;
    if(L.length == MAXSIZE) return ERROR;
    for (int j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j];
    L.elem[i - 1] = e;
    ++L.length;
    return OK;
}

//删除元素
Status ListDelete(SqList &L, int i)
{
    if (i < 1 || i > L.length) return ERROR;
    for(int j = i; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j];
    --L.length;
    return OK;
}

//有序表的合并 最坏时间复杂度O(m+n) 空间复杂度O(m+n)
void MergeList_Sq(SqList LA, SqList LB, SqList &LC)
{
    LC.length = LA.length + LB.length;
    LC.elem = new Polynomial[LC.length];
    Polynomial *pc = LC.elem;
    Polynomial *pa = LA.elem;
    Polynomial *pb = LB.elem;
    Polynomial *pa_last = LA.elem + LA.length - 1;
    Polynomial *pb_last = LB.elem + LB.length - 1;
    while ((pa <= pa_last) && (pb <= pb_last))
    {
        if(pa->coef <= pb->coef) *pc++= *pa ++;
        else *pc++=*pb++;
    }
    while (pa <= pa_last)
    {
        *pc++= *pa ++;
    }
    while (pb <= pb_last)
    {
        *pc++=*pb++;
    }
}


int main()
{
    cout<<"hello world"<<endl;
    return 0;
}