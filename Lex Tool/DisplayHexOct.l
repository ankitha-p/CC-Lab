%{
/*program to identify octal and hexadecimal numbers*/
%}
Oct [o][0-7]+
NotOct [o][0-9]+
Hex [0][x|X][0-9A-Fa-f]+
NotHex [0][x|X][0-9g-zG-Z]+
Dec [0-9]+
%%
{Hex} printf("\n%s is a hexadecimal number",yytext);
{Oct} printf("\n%s is an octal number",yytext);
{Dec} printf("\n%s is a decimal number\n",yytext);
{NotHex} printf("\n%s is incorrect hexadecimal number",yytext);
{NotOct} printf("\n%s is an incorrect octal number",yytext);

%%

main()
{
        yylex();
}
int yywrap()
{
        return 1;
}
