#include<iostream>
using namespace std;
#define N 8
int ans=0,num=0,flag=0;
int a[N]={};
void quest(int x,int y)
{
    //cout<<"S";
    if(x)//not first,if the previous points have influence on this point
    {
        for(int i=0;i<x;i++)
        {
            if(y==a[i]||y==a[i]+x-i||y==a[i]-x+i)
            {
                return;
            }
        }//if no influence
        //cout<<"T";
        if(x>=num-1)
        {
            flag=1;
            ans++;
            for(int i=0;i<num;i++)
            {
                for(int j=0;j<num;j++)
                {
                    if(a[i]==j)cout<<" 1 ";
                    else cout<<" 0 ";
                }
                cout<<endl;
            }
            return;
        }//the last one
        a[x]=y;
        x++;
        int q=x;
        if(x>(num-1)/2)q=num-1-q;
        for(int i=num/2+q,j=num/2-1-q;i<=num-1,j>=0;i++,j--)
        {
            if(flag) return;
            quest(x,i);
            if(flag) return;
            quest(x,j);
        }
        if(num%2) quest(x,num-1);
        for(int i=num/2+q-1,j=num/2-q;i>j;i--,j++)
        {
            if(flag) return;
            quest(x,i);
            if(flag) return;
            quest(x,j);
        }
    }
    else
    {
        a[x]=y;
        x++;
         int q=x;
        if(x>(num-1)/2)q=num-1-q;
        for(int i=num/2+q,j=num/2-1-q;i<=num-1,j>=0;i++,j--)
        {
            if(flag) return;
            quest(x,i);
            if(flag) return;
            quest(x,j);
        }
        if(num%2) quest(x,num-1);
        for(int i=num/2+q-1,j=num/2-q;i>j;i--,j++)
        {
            if(flag) return;
            quest(x,i);
            if(flag) return;
            quest(x,j);
        }
        //the first time so you do not need to estimate
    }
}
int main()
{
    cout<<"The number of Queens:"<<endl;
    cin>>num;
    for(int i=num/2,j=num/2-1;i<=num-1,j>=0;i++,j--)
        {
            if(flag) return 0;
            quest(0,i);
            if(flag) return 0;
            quest(0,j);
        }
        if(num%2) quest(0,num-1);
    //DFS num branches
    cout<<endl<<ans;
    return 0;
}
