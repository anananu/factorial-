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
        (*S).top++;
        (*S).content[(*S).top] = value;
        return 1;
    }
    return 0;
}

int pop(stiva* S, int* value)
{
    if((*S).top >= 1)
    {
        *value = (*S).content[(*S).top];
        (*S).top--;
        return 1;
    }
    return 0;
}

int n;
int fost;
int directie = 1;
int old;

int main()
{
    cout<<"n=";cin>>n;
    s.top = 0;
    push(&s,n);

    if(n >= 12)
    {
        n--;
        cout<<n;
        return 0;
    }

    while(s.top >= 1)
    {
        if (directie == 1)
        {
            pop(&s,&fost);
            push(&s,fost);
            fost+=2;
            push(&s,fost);
        }
        else
        {
            pop(&s,&fost);
            if(!pop(&s,&old)) break;
            fost--;
            push(&s,fost);
            if(s.top == 1) break;
        }
        if(fost >= 12) directie = 0;
        else directie = 1;
    }
    cout<<s.content[1];
}
