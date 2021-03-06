# Compiler of a Subset of C Language
In this project, we build a simple compiler that compiles a subset of C language into Assembly x86.
The project demonstrates various parts / working mechanism of a compiler such as scanning, semantic analysis etc.

## Useful tutorial
This looks promising! [link](https://steemit.com/utopian-io/@drifter1/writing-a-simple-compiler-on-my-own-combine-flex-and-bison)
# Prerequisites
0. Linux terminal
1. A good understanding of recursion
2. Basic graph theory
3. Topological sort
4. Theory slides
5. git version control system (otherwise your pc will be full of CompilerBackup1.zip, CompilerBackup2.zip, CompilerBackup2-1-backup-no-10000.zip, and so on...)

# The Compiler
The project can be divided into 4 parts. Each part can be viewed on its corresponding branch on github for the sake of convenience. You can download a branch in this way:

Fire up your terminal and type in:
```
$ git clone -b <branch-name> https://github.com/fahimfarhan/Compiler.git
```
So for example, to download the development branch, use:
```
$ git clone -b develop https://github.com/fahimfarhan/Compiler.git
```

You can find the main codes in the following files:
1. Token.h
2. ScopeTable.h
3. SymbolTable.h
4. myheader.h
(In Assignment 3, the previous 4 were merged into 1 file, named `MyHeader.h`, due to some technical issues/header related errors)
5. start.cpp
6. lexer.l (Assignment2 version)
7. scanner.l (modified lexer.l file/Assignment 3 version)
8. parser.y 

The branches are described below:

## 1. Compiler1:

Download command:
```
$ git clone -b Compiler1 https://github.com/fahimfarhan/Compiler.git
```

Here we develop a `Symble Table` that holds various `Tokens`. A `Token` is a pair `<TOKEN_NAME , TOKEN_ATTRIBUTE>`. 
To run the code, fire up your linux terminal  and run the following commands:
```
$ cd src
$ g++ start.cpp
$ ./a.out < zinput.txt > zoutput.txt
```
The commands are in a file named `1script.sh` and so you can also run it.

## 2. Compiler2:

Download command:
```
$ git clone -b Compiler2 https://github.com/fahimfarhan/Compiler.git
```

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
## 3. Compiler3:
16/08, Friday: So after a whole day of trials and errors, I am stuck with this error called `segmentation fault`. This is literally what I see on the terminal:
```
./run.sh: line 12: 10218 Segmentation fault      (core dumped) ./compiler.out
```
I now kinda understand how YACC/Bison works. But I'm out of luck, energy and will power to debug where the segmentation fault is occuring. Mission abort. A summary of what I did from starting of part 3 till today is written below:

Okay, this one is a bit tricky. So follow my instructions precisely:

```
$ git clone -b Compiler3 https://github.com/fahimfarhan/Compiler.git
```

Start with easy stuffs, add more stuffs as you advance. For example, I started from the demo simple calculator provided by teacchers. First I added the file I/O. Once everything was working, I moved on forward. Make sure you keep a backup / checkpoint after each successful changes, preferably using git,or else you are in a big trouble!
This small version is in src-simple folder. Once you are comfy with the skeleton, you know, input vs output is working without errors, proceed with the real grammar.txt file.

* `#define YYSTYPE Token *` Add this line to both of the flex and bison files. That will save you a lot of trouble.
* I was having some technical problems with 3 header files, so I merged them into one `MyHeader.h`.
* Be advised, code one thing at a time. Or else you are as good as dead. So for example, in `scanner.l`, add rules related to `CONST_INT` :
```
...
{CONST_INT}  {
        string s = yytext;
        Token *token = new Token;
        token->setTokenName("CONST_INT");
        token->setTokenAttr(s);
        token->setValue();
        yylval = (YYSTYPE)token;
        return CONST_INT;
	  }
...
```
And in your `parser.y` file maybe you can add:
```
factor:  ... ... // previously implemented codes
      | CONST_INT        {  // just add code for CONST_INT
                                table->Insert(*$1);
                                $$ = $1;
                           }
       ;
```
Then run 
```
$ ./delete.sh   # this will delete all the generated files like lex.yy.c, y.tab.c , ...
$ ./run.sh      # actually run 
```
If ok, proceed forward. 
Else, debug, make sure your code is working.

* If you keep your lexical errors from Assignment 2, make sure you keep a corresponding code segment in the bison file. So if you keep,
```
...
{ILL_FORMED_FLOAT}  {       
                    ErrorCount++;
                    fprintf(errorfile, "LexError at Line %d: %s\n", LineNo, yytext);
                    return ILL_FORMED_FLOAT;
                    }
...
```
, 
create a corresponding terminal in your parser.y file:
```
factor      :  ...
            |  ...
            ...
            | ILL_FORMED_FLOAT {    /*corresponding empty body, otherwise you'll get errors, and                              waste time like a lifeless person */ }
            |  ...
            ;

```
## 4. Compiler4:

Download command:
```
$ git clone -b Compiler4 https://github.com/fahimfarhan/Compiler.git
```

## Conclusion

I am literally out of will power to carry on anymore. Besides I need to focus on other works. I might come back again later and try to finish the unfinished works.
# THE END


