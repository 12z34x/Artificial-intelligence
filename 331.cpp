#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct question
{
    struct question *next;
    struct question *last;
    int missionary;
    int savage;
    int vessel;
}Tree;
int ans=0;
Tree *head,*Rear;

int b[3]={};
void carry(int x,int y,int z,int i,int m,int n,int l,int k,int t)
{
    if(ans) return;
    if(i)
    {
        b[0]+=x;
        b[1]+=y;
        b[2]+=z;
        cout<<" S";
        cout<<b[0]<<b[1]<<b[2];
        if( ((b[0]>0&&b[0]<t)&&(b[1]!=b[0]))||((m-b[0]>0)&&(m-b[0]<t)&&(m-b[0])!=(m-b[1])) || b[0]<0||b[0]>t||b[1]<0||b[1]>t)
        {
            b[0]-=x;
            b[1]-=y;
            b[2]-=z;
            cout<<" illegal ";
            return;
        }
        Tree *p;
        p=(Tree*)malloc(sizeof (Tree));
        m-=x;
        n-=y;
        l-=z;
        p->missionary=m;
        p->savage=n;
        p->vessel=l;
        Tree *q;
        q=(Tree*)malloc(sizeof (Tree));
        q=head;
        while(q!=NULL)
        {
            if(q->missionary==p->missionary&&q->savage==p->savage&&q->vessel==p->vessel)
            {
                m+=x;
                n+=y;
                l+=z;
                b[0]-=x;
                b[1]-=y;
                b[2]-=z;
                cout<<" repeated ";
                return;
            }
            q=q->next;
        }
        Rear->next=p;
        p->last=Rear;
        Rear=p;
        Rear->next=NULL;
        if((Rear->missionary==0)&&(Rear->savage==0)&&(Rear->vessel==0))
        {
            cout<<"  OVER!"<<endl;
            ans=i;
            return;
        }
        cout<<"T";
    }
    i++;
    if(i%2!=0)
    {
        for(int a=0;a<=k;a++)
        {
            int b=0;
            if(a==0) b=1;
            for(;b<=k-a;b++)
            {
                carry(a,b,1,i,m,n,l,k,t);
                if(ans) break;
            }
            if(ans) break;
        }
    }
    else
    {
        for(int a=0;a<=k;a++)
        {
            int b=0;
            if(a==0) b=1;
            for(;b<=k-a;b++)
            {
                carry(-a,-b,-1,i,m,n,l,k,t);
                if(ans) break;
            }
            if(ans) break;
        }
    }
    if(ans) return;
    cout<<"F"<<endl;
    if(i==1) {ans=-1;return;}
    m+=x;
    n+=y;
    l+=z;
    b[0]-=x;
    b[1]-=y;
    b[2]-=z;
    Rear->last->next=NULL;
    Rear=Rear->last;
    return ;
}
int main()
{
    int m,n,k,num;
    cout<<"please input the quantity of churchman,savage and the limits of the ship"<<endl;
    cin>>m>>n>>k;
    head=(Tree*)malloc(sizeof (Tree));
    Rear=(Tree*)malloc(sizeof (Tree));
    head->missionary=m;
    head->savage=m;
    head->vessel=1;
    Rear=head;
    num=m>n?m:n;
    carry(0,0,0,0,m,n,1,k,num);
    if(ans==-1) cout<<endl<<"NO ANSWER!";
    else if(ans)
    {
        Tree *q;
        q=(Tree*)malloc(sizeof (Tree));
        q=head;
        cout<<endl;
        while(q!=NULL)
        {
            cout<<"("<<q->missionary<<","<<q->savage<<","<<q->vessel<<")";
            if(q->next) cout<<"-->";
            q=q->next;
        }
    }
    return 0;
}

