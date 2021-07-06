#include<iostream>
using namespace std;

typedef struct PNode
{
    float coef; //系数
    int expn; //指数
    struct PNode *next;
} PNode, *Polynomial;

//创建有序表 时间复杂度O(n ^ 2)
void CreatePolyn(Polynomial &p, int n)
{
    PNode *s, *pre, *q;
    p = new PNode;
    p->next = NULL;
    for(int i = 1; i < n; i++)
    {
        s = new PNode;
        cin >> s->coef >> s->expn;
        pre = p;
        q = p->next;
        while (q && q->expn < s->expn)
        {
            pre = q;
            q = q->next;
        }
        s->next = q;
        pre->next = s;
    }
}

//多项式加法 时间复杂度O(m + n)
void AddPolyn(Polynomial &Pa, Polynomial &Pb)
{
    PNode *p1 = Pa->next, *p2 = Pb->next, *r;
    PNode *p3 = Pa;
    float sum;
    while (p1 && p2)
    {
        if(p1->expn == p2->expn)
        {
            sum = p1->coef + p2->coef;
            if(sum != 0)
            {
                p1->coef = sum;
                p3->next = p1;
                p3 = p1;
                p1 = p1->next;
                r = p2;
                p2 = p2->next;
                delete r;
            }
            else
            {
                r = p1; p1 = p1->next; delete r;
                r = p2; p2 = p2->next; delete r;
            }
        }
        else if(p1->expn < p2->expn)
        {
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
    }
    p3->next = p1 ? p1 : p2;
    delete Pb;
}