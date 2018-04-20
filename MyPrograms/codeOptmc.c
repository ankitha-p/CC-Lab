#include<stdio.h>
int tc[10],fb=0,i=0,j=0,k=0,p=0,fstar=0,c=-1,c1=0,c2=0,t1,t2,t3,t4,f0=0;
char m[30],temp[30],opt[10][4];
int operator1(char,char);
void main()
{
   int a,d;
   for(i=0;i<10;i++)
   tc[i]=-1;
   printf("\n code stmt evaluation following precedence:");
   printf("\n 1.() with in the () stmet should be of the form: x op z");
   printf("\n 2.*,/ equal precedence");
   printf("\n 3.+,- equal precedence");
   printf("\n enter ur code stmt-");
   scanf("%s",m);
   i=0;
   while(m[i]!='\0')
   {
     if(m[i++]=='(')
     {
       fb++;
       break;
     }
   }
   i=0;
   printf("\n the intermediate code may be generated as-");
   if(fb==1)
   {
   while(m[i]!='\0')
   if(m[i]=='(')
   {
   temp[j++]='T';
   i++;
   t3=i;
   while(m[i]!=')')
   opt[c1][c2++]=m[i++];
   for(t4=c1-1;t4>=0;t4--)
   if(strcmp(opt[c1],opt[t4])==0)
   {
   tc[p++]=t4;
   f0=1;
   }
   if(f0==0)
   {
   tc[p++]=k++;
   printf("\n T%d=",k-1);
   while(m[t3]!=')')
   printf("%c",m[t3++]);
   }
   i++;
          c1++;
          c2=f0=0;
          }
          else if (m[i]!='(')
          temp[j++]=m[i++];
          if(fb==1)
         {
         temp[j]='\0';
         for(i=0;temp[i]!='\0';i++)
         m[i]=temp[i];
         m[i]='\0';
         }
         }
         /*end of evaluating sub emxp*/
         a=operator1('*','/');
         d=operator1('+','-');
         if(a==0 && d==0 && m[1]=='=')
         printf("\n%s%d",m,k-1);
         }
         /*function to evaluate operatores*/
         int operator1(char haj,char haj1)
         {
         m1:for(i=0;m[i]!='\0';i++)
         if(m[i]==haj|| m[i]==haj1)
         {
         fstar++;
         break;
         }
         if(fstar==1)
        {
         for(j=0;j<i;j++)
         if(m[j]=='T')
         c++;
         printf("\n T%d=",k);
         if(m[i-1]=='T'&&m[i+1]=='T')
         {
         printf("\n%c%d%c%c%d",m[i-1],tc[c],m[i],m[i+1],tc[c+1]);
         tc[c]=k++;
         for(t2=c+1;t2<9;t2++)
         tc[t2]=tc[t2+1];
         }
         else if(m[i-1]!='T' &&m[i+1]!='T')
         {
         printf("%c%c%c",m[i-1],m[i],m[i+1]);
         if(c==-1)
         {
         for(t1=9;t1>0;t1--)
         tc[t1]=tc[t1-1];
         tc[0]=k++;
         }
         else if(c>=0)
         {
         for(t1=9;t1>c+1;t1--)
         tc[t1]=tc[t1-1];
         tc[t1]=k++;
         }
         }
         else if(m[i-1]=='T' && m[i+1]!='T')
         {
         printf("%c%d%c%c",m[i-1],tc[c],m[i],m[i+1]);
         tc[c]=k++;
         }
         else if(m[i-1]!='T'&& m[i+1]=='T')
         {
         printf("%c%c%c%d",m[i-1],m[i],m[i+1],tc[c+1]);
   	  tc[c+1]=k++;
         }
         for(t1=0;t1<i-1;t1++)
         temp[t1]=m[t1];
         temp[t1++]='T';
         for(t2=i+2;m[t2]!='\0';t2++)
         temp[t1++]=m[t2];
         temp[t1++]='\0';
         fstar=0;
         for(i=0;temp[i]!='\0';i++)
         m[i]=temp[i];
         m[i]='\0';
         c=-1;
         goto m1;
         }
         else
         return 0;
         }
