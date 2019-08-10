rm a.out
rm lex.yy.c

flex test.l 
g++ lex.yy.c
./a.out zinput1.txt ztokenout.txt
