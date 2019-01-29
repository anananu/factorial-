#include <iostream>
using namespace std;

typedef struct
{
    int top;
    int content1[1000];
    int content2[1000];
} stiva ;
stiva s;

int push(stiva* S, int value1, int value2)
{
    if((*S).top < 1000)
    {
        (*S).top++;
        (*S).content1[(*S).top] = value1;
        (*S).content2[(*S).top] = value2;
        return 1;
    }
    return 0;
}

int pop(stiva* S, int* value1, int* value2)
{
    if((*S).top >= 1)
    {
        *value1 = (*S).content1[(*S).top];
        *value2 = (*S).content2[(*S).top];
        (*S).top--;
        return 1;
    }
    return 0;
}

int n,m;
int directie;
int fost1,fost2,fost3,fost4;

int main()
{
    cout<<"m=";cin>>m;
    cout<<"n=";cin>>n;

    s.top = 0;
    push(&s,m,n);

    if(m != 0 && n != 0)
        directie = 0;
    else if(m != 0 && n == 0)
        directie = 1;
    else directie = 2;

    while(s.top >= 1)
    {
        if(directie == 0)
        {
            pop(&s,&fost1,&fost2);
            push(&s,fost1,fost2);
            fost2--;
            push(&s,fost1,fost2);
            cout<<fost1<<" "<<fost2<<endl;
        }
        else if(directie == 1)
        {
            pop(&s,&fost1,&fost2);
            fost1--;
            fost2 = 1;
            push(&s,fost1,fost2);
            cout<<fost1<<" "<<fost2<<endl;
        }
        else
        {
            pop(&s,&fost1,&fost2);
            if(!pop(&s,&fost1,&fost4)) break;
            fost1--;
            fost2++;
            push(&s,fost1,fost2);
            cout<<fost1<<" "<<fost2<<endl;
        }
        if((fost1 != 0 && fost2 != 0))
            directie = 0;
        if(fost1 != 0 && fost2 == 0)
            directie = 1;
        else if(fost1 == 0 && fost2 != 0)
            directie = 2;
    }
    s.content2[1]++;
    cout<<s.content2[1];
}
