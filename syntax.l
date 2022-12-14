%option noyywrap
%{
#include<stdio.h>
%}
ws [ \t]+
string \"[^\n"]+\"
digits [0-9]
letter [a-zA-Z]
alphanum [a-zA-Z0-9]
operator [+|-|*|/|%|=]
%%
{ws} /* skip blanks and tabs */
(int|char|float|double|if|for) printf("\n keyword: %s ", yytext);
{digits}*\.{digits}+ printf("\n float number: %s ", yytext);
(-|\+)*{digits}+ printf("\n int number: %s ", yytext);
{letter}(_|{alphanum})* printf("\n identifer: %s ", yytext);
{string} printf("\n string: %s ",yytext);
{operator} printf("\n operator: %s ",yytext);
'.' printf("\n character: %s ", yytext);
. {

	printf("\n Special symbols: %s ", yytext);
}

%%
int main()
{
printf("\n Enter input program:");
yylex();
return 0;
}