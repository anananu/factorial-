#include <iostream>
using namespace std;

typedef struct
{
    int top;
    int content[1000];
} stiva ;
stiva s;

int push(stiva* S, int value)
{
    if((*S).top < 1000)
    {
        (*S).content[(*S).top] = value;
        (*S).top++;
        return 1;
    }
    return 0;
}

int pop(stiva* S, int* value)
{
    if((*S).top >= 1)
    {
        (*S).top--;
        *value = (*S).content[(*S).top];
        return 1;
    }
    return 0;
}

int n;
int nr;
int directie = 1;
int old1,old2;

int main()
{
    cout<<"n=";cin>>n;
    s.top = 1;
    push(&s,n);
    while(s.top >= 1)
    {
        if (directie == 1)
        {
            pop(&s,&nr);
            push(&s,nr);
            nr--;
            push(&s,nr);
        }
        else
        {
            pop(&s,&old1);
            if(!pop(&s,&old2)) break;
            push(&s,old1*old2);
        }
        if(nr == 1) directie = 0;
    }
    cout<<s.content[1];
}

