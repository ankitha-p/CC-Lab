#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
        FILE *input, *output;
        int t=1;
        int j=0;
        int i,flag;
        char ch,str[20];
        input = fopen("sample.txt","r");
        output = fopen("output.txt","w");
        char keyword[32][30] = {"int","switch","if","else","do","while","case","break","default","auto","double","struct","long","enum","register","typedef","char","extern","return","union","const","float","short","unsigned","continue","for","signed","void","goto","sizeof","volatile","static"};
        fprintf(output,"Serial no.\t Token\t\t Lexeme\t\t Pattern\n\n");
        while(!feof(input))
        {
                i=0;
                flag=0;
                ch=fgetc(input);
                if( ch=='+' || ch== '-' || ch=='*' || ch=='/' )
                {
                        fprintf(output,"%7d\t\t Operator\t %7c\t Binary Operators\n",t,ch);
                        t++;
                }
                else if( ch==';' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch=='?' || ch=='@' || ch=='!' || ch=='%')
                {
                        fprintf(output,"%7d\t\t Special symbol\t %7c\t Special Symbol%7c\n",t,ch,ch);
                        t++;
                }
                else if(isdigit(ch))
                {
                        fprintf(output,"%7d\t\t Digit\t\t %7c\t Numeric Constant\n",t,ch);
                        t++;
                }
                else if(isalpha(ch))
                {
                        str[i]=ch;
                        i++;
                        ch=fgetc(input);
                        while(isalnum(ch) && ch!=' ')
                        {

                                 str[i]=ch;
                                  i++;
                                ch=fgetc(input);
                        }
                        str[i]='\0';
                        for(j=0;j<=31;j++)
                       {
                                if(strcmp(str,keyword[j])==0)
                                {
                                        flag=1;
                                        break;
                                }
                        }
                        if(flag==1)
                        {
                                fprintf(output,"%7d\t\t Keyword\t %7s\t Word with special meaning\n",t,str);
                                t++;
                        }
                        else
                        {
                                fprintf(output,"%7d\t\t Identifier\t %7s\t Letters and digits\n",t,str);
                                t++;
                        }
                }
        }
        fclose(input);
        fclose(output);
        return 0;
}


