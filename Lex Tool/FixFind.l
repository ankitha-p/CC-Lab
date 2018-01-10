%{
%}

infix [a-zA-Z][+\-\*\/][a-zA-Z]
postfix [a-zA-Z][a-zA-Z][+\-\*\/]
prefix [+\-\*\/][a-zA-Z][a-zA-Z]

%%
{prefix} printf("prefix found\n");
{postfix} printf("postfix found\n");
{infix} printf("infix found\n");
%%

main()
{
        yylex();
}
int yywrap()
{
        return 1;
}
