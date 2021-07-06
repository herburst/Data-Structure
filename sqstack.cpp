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
    int *base;
    int *top;
    int stacksize; //栈容量
}SqStack;

//初始化顺序栈
Status InitStack(SqStack &S)
{
    //构造一个空栈
    S.base = new int[MAXSIZE];
    if (!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

//入栈
Status Push(SqStack &S, int e)
{
    //插入元素e为新的栈顶元素
    if(S.top - S.base == S.stacksize) return ERROR;
    *S.top ++= e;
    return OK;
}

//出栈
Status Pop(SqStack &S, int &e)
{
    if(S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}

//取栈顶元素
int GetTop(SqStack S)
{
    //返回S的栈顶元素，不修改栈顶指针
    if(S.top != S.base)
        return *(S.top - 1);
}