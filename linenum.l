%option noyywrap
%{
#include<stdio.h>
int line_number = 1; 
%}

	

%%
[\n] { printf("%10d %s", line_number++, yytext); }

%%

int main(int argc, char*argv[])
{
extern FILE *yyin; 
yyin = fopen("test.txt","r"); 
yylex();

return 0;
}

