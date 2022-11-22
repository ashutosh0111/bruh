/*Definition Section*/
%{
#include<stdio.h>
%}

%%

\/\/(.*) {};					

\/\*(.*\n)*.*\*\/  {};			
%%

/*call the yywrap function*/
int yywrap()
{
return 1;
}



int main()
{
yyin=fopen("test.c","r");
yyout=fopen("out.c","w");
/*call the yylex function.*/
yylex();
return 0;
}