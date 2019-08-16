/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    DO = 262,
    BREAK = 263,
    INT = 264,
    CHAR = 265,
    FLOAT = 266,
    DOUBLE = 267,
    VOID = 268,
    RETURN = 269,
    SWITCH = 270,
    CASE = 271,
    DEFAULT = 272,
    CONTINUE = 273,
    NEWLINE = 274,
    WHITESPACE = 275,
    CONST_INT = 276,
    CONST_FLOAT = 277,
    SPECIAL_CONST_CHAR = 278,
    CONST_CHAR = 279,
    RELOP = 280,
    ID = 281,
    STRING = 282,
    TOO_MANY_DOTS = 283,
    OTHERS_DOT = 284,
    ILL_FORMED_FLOAT = 285,
    UnfinishedChar = 286,
    MultiCharacterConstantError = 287,
    UnfinishedString = 288,
    UnfinishedComment = 289,
    ADDOP = 290,
    MULOP = 291,
    LPAREN = 292,
    RPAREN = 293,
    INCOP = 294,
    ASSIGNOP = 295,
    LOGICOP = 296,
    NOT = 297,
    LCURL = 298,
    RCURL = 299,
    LTHIRD = 300,
    RTHIRD = 301,
    COMMA = 302,
    SEMICOLON = 303,
    DECOP = 304,
    PRINTLN = 305
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define INT 264
#define CHAR 265
#define FLOAT 266
#define DOUBLE 267
#define VOID 268
#define RETURN 269
#define SWITCH 270
#define CASE 271
#define DEFAULT 272
#define CONTINUE 273
#define NEWLINE 274
#define WHITESPACE 275
#define CONST_INT 276
#define CONST_FLOAT 277
#define SPECIAL_CONST_CHAR 278
#define CONST_CHAR 279
#define RELOP 280
#define ID 281
#define STRING 282
#define TOO_MANY_DOTS 283
#define OTHERS_DOT 284
#define ILL_FORMED_FLOAT 285
#define UnfinishedChar 286
#define MultiCharacterConstantError 287
#define UnfinishedString 288
#define UnfinishedComment 289
#define ADDOP 290
#define MULOP 291
#define LPAREN 292
#define RPAREN 293
#define INCOP 294
#define ASSIGNOP 295
#define LOGICOP 296
#define NOT 297
#define LCURL 298
#define RCURL 299
#define LTHIRD 300
#define RTHIRD 301
#define COMMA 302
#define SEMICOLON 303
#define DECOP 304
#define PRINTLN 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
