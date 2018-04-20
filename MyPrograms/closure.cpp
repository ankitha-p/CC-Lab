#include<iostream>
#include<string>
using namespace std;

char a[8],b[7];
int c[12][5];
int w=0,e=0,x=0,y=0;
int st2[12][2],st3[12];
char sta[12],ch;
void v1(char,int);
void v2(char,int,int,int);

int main()
{
        int l=0,m=0,p=1,f=0,g,v=0,jj[12];

        cout<<"\n\n\t*******Enter the Grammar Rules (max=3)*******\n\t";
        for(int i=0;i<3;i++)
        {
             cin>>a[i]
             printf("\t");
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<a[i].length;j++)
            {
                for(int k=0;k<a[i].length;k++)
                {
                    if(p==k)
                    {
                        b[l][m]='.';
                        m+=1;
                        b[l][m]=a[i][k];
                        m+=1;
                    }
                    else
                    {
                        b[l][m]=a[i][k];
                        m++;
                    }
                }
                p++;
                l++;
                m=0;
             }
            p=1;
        }
        int i=0,p=0;
        while(l!=i)
        {
            for(int j=0;j<strlen(b[i]);j++)
            {
                if(b[i][j]=='.') p++;
            }
            if(p==0)    b[i][b[i].length]='.';
            i++;
            p=0;
        }
        cout<<"\n\t*******Your States will be*******\n\t";
        for(int i=0;i<l;i++) cout<<i<<" --> "<<b[i]<<"\t";
        cout<<"\n";

        v1('A',l);
        p=c[0][0];
        for(int m=0;m<6;m++)
        {
            for(int i=0;i<st3[m];i++)
            {
                for(int j=0;j<b[p].length;j++)
                {
                    if(b[p][j]=='.')
                    {
                        st2[x][0]=m;
                        if(isalpha(b[p][j+1]))
                        {
                            sta[x]=b[p][j+1];
                            v2(b[p][j+1],j,l,f);
                        }
                        else
                        {
                            sta[x]='S';
                            st2[x][1]=m;
                        }
                        x++;
                    }
                }
                p=c[m][i+1];
            }
            m++;
            p=c[m][0];
        }
        g=0;
        p=0;
        m=0;
        x=0;
        return 0;
}

void v1(char ai,int kk)
{
    int i,j;
    for(i=0;i<kk;i++)
    {
        if(b[i][2]==ai&&b[i][1]=='.')
        {
            c[w][e]=i;
            e++;
            if(isupper(b[i][2]))
            {
                for(j=0;j<kk;j++)
                {
                    if(b[j][0]==ai && b[j][1]=='.')
                    {
                        c[w][e]=j;
                        e++;
                    }
                }
            }
        }
    }
    st3[w]=e;
    w++;
    e=0;
}

void v2(char ai,int ii,int kk,int tt)
{
    int i,j,k;
    for(i=0;i<kk;i++)
    {
        if(b[i][ii]=='.'&& b[i][ii+1]==ai)
        {
            for(j=0;j<kk;j++)
            {
                if(b[j][ii+1]=='.' && b[j][ii]==ai)
                {
                    c[w][e]=j;
                    e++;
                    st2[tt][1]=j;
                    if(b[j][ii+2]>=65 && b[j][ii+1]<=90)
                    {
                        for(k=0;k<kk;k++)
                        {
                            if(b[k][0]==b[j][ii+2] && b[k][1]=='.')
                            {
                                c[w][e]=k;
                                e++;
                            }
                        }
                    }
                }
            }
            if((b[i][ii+1]>=65 && b[i][ii+1]<=90) && tt==1)
            {
                for(k=0;k<kk;k++)
                {
                    if(b[k][0]==ai && b[k][1]=='.')
                    {
                        c[w][e]=k;
                        e++;
                    }
                }
            }
        }
    }
    st3[w]=e;
    w++;
    e=0;
}
