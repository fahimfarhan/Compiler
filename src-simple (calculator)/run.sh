bison -d -y parser.y    
echo '1'
g++ -w -c y.tab.c -o parser.out
echo '2'
flex scanner.l
echo '3'
g++ -w -c lex.yy.c -o scanner.out
# if the above command doesn't work try g++ -fpermissive -w -c -o l.o lex.yy.c
echo '4'
g++ parser.out scanner.out -o compiler.out # -lfl -ly  # comment out -lfl -ly of you get errors. I got errors. so I've alreay commented them out
echo '5'
./compiler.out