#include<stdio.h>
#include<string.h>
char ip[20],op[20],arg1[20],arg2[20],res[20];
char r[5]={'1','2','3','4','5'};
int l,p,j=0;
void rep(int,int,int);
void repl(int,int,int);
void check(int,char);
int oppr(char);
void main()
{
    int i;
    printf("Enter the input Expression\n");
    scanf("%s",ip);
    l=strlen(ip);
    for(i=0;i<l;i++)
    {
            p=oppr(ip[i]);
            if(p==5)
            {
                    check(i,ip[i]);
            }
    }
    for(i=0;i<l;i++)
    {
            p=oppr(ip[i]);
            if(p==6)
            {
                    rep(i-1,i,i+1);
                    i=0;
            }
    }
    for(i=0;i<l;i++)
    {
            p=oppr(ip[i]);
            if(p==5)
            {
                    rep(i-1,i,i+1);
                    i=0;
            }
    }
    for(i=0;i<l;i++)
    {
            p=oppr(ip[i]);
            if(p==4)
            {
                    rep(i-1,i,i+1);
                    i=0;
            }
    }
    printf("The triple notation is \n");
    printf("op\targ1\targ2\n");
    for(i=0;i<j;i++)
    printf("%c\t%c\t%c\n",op[i],arg1[i],arg2[i]);

}
int oppr(char c)
{
        if(c=='*'||c=='/')
return(6);
        else if(c=='+'||c=='-')
                return(5);
        else if(c=='=')
                return(4);
}
void rep(int a,int b,int c)
{
        int i,k;
        op[j]=ip[b];
        arg1[j]=ip[a];
        arg2[j]=ip[c];
        ip[a]=r[j];
        k=b;
        k++;
        for(i=b;i<l;i++)
        {
                ip[i]=ip[k+1];
                k++;
        }
        l=l-2;
        j++;
}

void check(int i,char c)
{
        int a,b;
        if(c=='-')
        {
                if(!isalpha(ip[i-1]))
                {
                        op[j]='m';
                        arg1[j]=ip[i+1];
                        ip[j]=r[j];
                        b=i;
                        b++;
                        for(a=i+1;a<l;a++)
                        {
                                ip[a]=ip[b+1];
                                b++;
                        }
                        l--;
                        j++;
                }
        }
}
