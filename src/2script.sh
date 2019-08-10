rm a.out
rm lex.yy.c

flex lexer.l 
g++ lex.yy.c
./a.out zinput.txt ztokenout.txt
