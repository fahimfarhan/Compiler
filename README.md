# Compiler
In this project, we build a simple compiler that compiles a subset of C language into Assembly x86.
The project demonstrates various parts / working mechanism of a compiler such as scanning, semantic analysis etc.

The project can be divided into 4 parts. Each part can be viewed on its corresponding branch for the sake of convenience. 
You can find the main codes in the following files:
1. Token.h
2. ScopeTable.h
3. SymbolTable.h
4. myheader.h
5. lexer.l

The branches are described below:

1. Compiler1:
Here we develop a `Symble Table` that holds various `Tokens`. A `Token` is a pair `<TOKEN_NAME , TOKEN_ATTRIBUTE>`. 
To run the code, fire up your linux terminal  and run the following commands:
```
$ cd src
$ g++ start.cpp
$ ./a.out < zinput.txt > zoutput.txt
```
The commands are in a file named `1script.sh` and so you can also run it.

2. Compiler2:
Here we use `Flex` to write pattern matching codes that convert our source program into `Tokens` and shows verbous description with error detection in a log file.
 Input: C code 
 Output: Tokens, log file

 Sample input: src/zinput.txt 
 Sample output: src/ztoken.txt (tokens) , zlog.txt (the log file)

To run the code, fire up your linux terminal  and run the following commands:
```
$ cd src
$ flex lexer.l 
$ g++ lex.yy.c
$ ./a.out zinput.txt ztokenout.txt
```


