#include<iostream>
using namespace std;
#define N 20
int  num;
int a[N][N]={},ans=0,b[N]={};
void quest(int x,int y)
{
    int m,n,k;
    cout<<" s ";
    if(x!=0)
    {
        if(a[x][y])
        {
            return;
        }
    }
    cout<<" R ";
    if(x>=num-1)
    {
        ans++;
        return;
    }
    else
    {
        b[x]=y+1;
        for(k=0;k<=num-1;k++)
        {
            a[x][k]=x+1+a[x][k];
        }
        for(k=0;k<=num-1;k++)
        {
            a[k][y]=x+1+a[k][y];
        }
        for(m=x,n=y;m>=0&&n>=0;m--,n--)
        {
            a[m][n]=x+1+a[m][n];
        }
        for(m=x,n=y;m<=num-1&&n>=0;m++,n--)
        {
            a[m][n]=x+1+a[m][n];
        }
        for(m=x,n=y;m>=0&&n<=num-1;m--,n++)
        {
            a[m][n]=x+1+a[m][n];
        }
        for(m=x,n=y;m<=num-1&&n<=num-1;m++,n++)
        {
            a[m][n]=x+1+a[m][n];
        }
        cout<<" OK "<<endl;
        int p,q;
        cout<<endl;
        for(p=0;p<=num-1;p++)
        {
            for(q=0;q<=num-1;q++)
            {
                cout<<"  "<<a[p][q]<<"   ";
            }
            cout<<endl;
        }
        x++;
        for(int j=0;j<num;j++)
        {
            quest(x,j);
        }
        cout<<" BACK ";
        x--;
        b[x]=0;
        for(k=0;k<=num-1;k++)
        {
            a[x][k]=a[x][k]-x-1;
        }
        for(k=0;k<=num-1;k++)
        {
            a[k][y]=a[k][y]-x-1;
        }
        for(m=x,n=y;m>=0&&n>=0;m--,n--)
        {
            a[m][n]=a[m][n]-x-1;
        }
        for(m=x,n=y;m<=num-1&&n>=0;m++,n--)
        {
            a[m][n]=a[m][n]-x-1;
        }
        for(m=x,n=y;m>=0&&n<=num-1;m--,n++)
        {
            a[m][n]=a[m][n]-x-1;
        }
        for(m=x,n=y;m<=num-1&&n<=num-1;m++,n++)
        {
            a[m][n]=a[m][n]-x-1;
        }
        cout<<endl;
        for(p=0;p<=num-1;p++)
        {
            for(q=0;q<=num-1;q++)
            {
                cout<<"  "<<a[p][q]<<"   ";
            }
            cout<<endl;
        }
    }
    return;
}
int main()
{
    cout<<"please input the quality of queens"<<endl;
    cin>>num;
    for(int i=0;i<num;i++)
    quest(0,i);
    cout<<endl<<ans<<endl;
    return 0;
}
