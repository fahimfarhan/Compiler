/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#ifndef MYHEADER
#define MYHEADER
/* contents of the header file */
    #include "myHeader.h"
#endif

#define YYSTYPE Token *   /* yyparse() stack type */

#define MYDEBUG true
extern FILE *yyin;
extern int LineNo;
extern int ErrorCount;

FILE *fin;
FILE *logfile;
FILE *errorfile;
FILE *tablefile;
ofstream logout("zlog.md");

SymbolTable *table;

void yyerror(const char *s){
	ErrorCount++;
	fprintf(errorfile, "yyError at Line %d: %s\n", LineNo, s);

}

void printer(string s){    logout<<"Line Number "<<LineNo<<": "<<s<<"\n";  }

int yylex(void);

string calc(string s1, string sign, string s2){
    int n1 = stoi(s1);
    int n2 = stoi(s2);

    if(sign == "+"){    n1+=n2; }
    else if(sign == "-"){   n1-=n2; }
        else if(sign == "*"){   n1+=n2; }
    else if(sign == "/"){   n1/=n2; }

    string ret = to_string(n1);
    return ret;
}

/*
%union{
Token *token;
}
*/
// %token NEWLINE NUMBER ADDOP MULOP LPAREN RPAREN


#line 120 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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

/* Copy the second part of user declarations.  */

#line 271 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    53,    51,     2,    52,     2,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    72,    72,    75,    76,    79,    80,    81,    84,    87,
      90,    91,    92,    93,    94,    97,    98,   101,   129,   130,
     131,   134,   140,   150,   155,   164,   165,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   179,   180,   183,   184,
     187,   188,   191,   192,   195,   196,   199,   200,   203,   204,
     207,   208,   209,   212,   213,   214,   215,   216,   217,   218,
     219,   222,   223,   224
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DO",
  "BREAK", "INT", "CHAR", "FLOAT", "DOUBLE", "VOID", "RETURN", "SWITCH",
  "CASE", "DEFAULT", "CONTINUE", "NEWLINE", "WHITESPACE", "CONST_INT",
  "CONST_FLOAT", "SPECIAL_CONST_CHAR", "CONST_CHAR", "RELOP", "ID",
  "STRING", "TOO_MANY_DOTS", "OTHERS_DOT", "ILL_FORMED_FLOAT",
  "UnfinishedChar", "MultiCharacterConstantError", "UnfinishedString",
  "UnfinishedComment", "ADDOP", "MULOP", "LPAREN", "RPAREN", "INCOP",
  "ASSIGNOP", "LOGICOP", "NOT", "LCURL", "RCURL", "LTHIRD", "RTHIRD",
  "COMMA", "SEMICOLON", "DECOP", "PRINTLN", "'+'", "'-'", "'*'", "'/'",
  "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "parameter_list", "compound_statement",
  "var_declaration", "type_specifier", "declaration_list", "statements",
  "statement", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    43,    45,    42,    47
};
# endif

#define YYPACT_NINF -67

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      64,   -67,   -67,   -67,    22,    64,   -67,   -67,   -67,   -67,
       0,   -67,   -67,     6,    -9,    64,    21,    31,   -67,   -13,
      32,    17,    27,    11,    64,   -67,   -67,    41,    65,   -67,
     -67,    54,    35,    30,    45,    46,   125,   -67,   -67,   -67,
      15,   125,   125,   125,   -67,   -67,    47,   -67,   -67,    59,
      90,   -67,   -67,   -29,    40,   -67,    49,   -17,    58,   -67,
     -67,   -67,   -67,   125,    -7,   125,    44,   125,   125,   -26,
     -67,    60,   -67,    71,    61,   -67,   -67,   -67,   125,   -67,
     -67,   125,   125,   125,   125,    67,    -7,    72,   -67,   -67,
      -2,    73,   -67,    79,   -67,   -67,    87,    58,   -67,   115,
     125,   115,   -67,   125,   -67,    75,   126,    93,   -67,   -67,
     -67,   115,   115,   -67,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,    19,    20,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    23,     0,    14,     0,     0,    17,     0,
      13,     0,    21,     0,     0,    12,    24,     0,     0,     8,
       9,    11,     0,     0,     0,     0,     0,    56,    57,    58,
      38,     0,     0,     0,    16,    36,     0,    29,    27,     0,
       0,    25,    28,    53,     0,    40,    42,    44,    46,    48,
      52,    10,    22,     0,     0,     0,     0,    63,     0,    53,
      50,     0,    51,     0,    23,    15,    26,    59,     0,    60,
      37,     0,     0,     0,     0,     0,     0,     0,    35,    62,
       0,     0,    55,     0,    41,    43,    45,    47,    49,     0,
       0,     0,    54,     0,    39,     0,    31,     0,    33,    61,
      34,     0,     0,    32,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   130,   -67,   -67,   -67,   119,    56,    16,
     -67,   -67,   -46,   -62,   -34,   -36,   -66,    62,    63,    70,
     -38,   -67,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    19,    47,    48,    49,
      14,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      66,    89,    86,    70,    76,    72,    71,    69,    82,    69,
      77,    78,    94,    77,    37,    38,    10,    39,    83,    40,
      79,    10,    11,    79,   100,    23,    13,    85,    41,    87,
      42,    20,    91,    69,    24,    43,   102,   109,    17,    18,
      31,    45,    21,    15,    69,   103,    98,    69,    69,    69,
      69,    16,    67,   106,    28,   108,     9,    22,    25,    29,
      68,     9,    32,    26,   107,   113,   114,    63,    33,    69,
      34,    35,    27,     1,     1,     2,     2,     3,     3,    36,
      61,    62,    64,    65,    73,    74,    37,    38,    80,    39,
      81,    40,    88,    33,    84,    34,    35,    93,    92,     1,
      41,     2,    42,     3,    36,    99,    16,    43,    28,    44,
     101,    37,    38,    45,    39,    46,    40,   105,    33,   104,
      34,    35,    83,   110,     1,    41,     2,    42,     3,    36,
     111,   112,    43,    28,    75,    12,    37,    38,    45,    39,
      46,    40,    30,    95,     0,    96,    37,    38,     0,    39,
      41,    40,    42,    97,     0,     0,     0,    43,    28,     0,
      41,     0,    42,    45,     0,    46,     0,    43
};

static const yytype_int8 yycheck[] =
{
      36,    67,    64,    41,    50,    43,    42,    41,    25,    43,
      39,    40,    78,    39,    21,    22,     0,    24,    35,    26,
      49,     5,     0,    49,    86,    38,    26,    63,    35,    65,
      37,    15,    68,    67,    47,    42,    38,   103,    47,    48,
      24,    48,    21,    37,    78,    47,    84,    81,    82,    83,
      84,    45,    37,    99,    43,   101,     0,    26,    26,    48,
      45,     5,    21,    46,   100,   111,   112,    37,     3,   103,
       5,     6,    45,     9,     9,    11,    11,    13,    13,    14,
      26,    46,    37,    37,    37,    26,    21,    22,    48,    24,
      41,    26,    48,     3,    36,     5,     6,    26,    38,     9,
      35,    11,    37,    13,    14,    38,    45,    42,    43,    44,
      38,    21,    22,    48,    24,    50,    26,    38,     3,    46,
       5,     6,    35,    48,     9,    35,    11,    37,    13,    14,
       4,    38,    42,    43,    44,     5,    21,    22,    48,    24,
      50,    26,    23,    81,    -1,    82,    21,    22,    -1,    24,
      35,    26,    37,    83,    -1,    -1,    -1,    42,    43,    -1,
      35,    -1,    37,    48,    -1,    50,    -1,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    11,    13,    56,    57,    58,    59,    60,    63,
      64,     0,    58,    26,    65,    37,    45,    47,    48,    61,
      64,    21,    26,    38,    47,    26,    46,    45,    43,    48,
      62,    64,    21,     3,     5,     6,    14,    21,    22,    24,
      26,    35,    37,    42,    44,    48,    50,    62,    63,    64,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    26,    46,    37,    37,    37,    70,    37,    45,    69,
      75,    70,    75,    37,    26,    44,    67,    39,    40,    49,
      48,    41,    25,    35,    36,    70,    68,    70,    48,    71,
      77,    70,    38,    26,    71,    72,    73,    74,    75,    38,
      68,    38,    38,    47,    46,    38,    67,    70,    67,    71,
      48,     4,    38,    67,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    59,    60,
      61,    61,    61,    61,    61,    62,    62,    63,    64,    64,
      64,    65,    65,    65,    65,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     6,
       4,     3,     2,     1,     0,     3,     2,     3,     1,     1,
       1,     3,     6,     1,     4,     1,     2,     1,     1,     1,
       7,     5,     7,     5,     5,     3,     1,     2,     1,     4,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       2,     2,     1,     1,     4,     3,     1,     1,     1,     2,
       2,     3,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 72 "parser.y" /* yacc.c:1646  */
    {printer("start : program");}
#line 1446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 75 "parser.y" /* yacc.c:1646  */
    {printer("program :program unit");}
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 76 "parser.y" /* yacc.c:1646  */
    {    printer("program :unit");  }
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 79 "parser.y" /* yacc.c:1646  */
    { printer("unit : var_declaration"); table->PrintAllScopeTable();  }
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 80 "parser.y" /* yacc.c:1646  */
    { printer("unit : func_declaration"); }
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 81 "parser.y" /* yacc.c:1646  */
    { printer("unit : funnc_definition"); }
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 84 "parser.y" /* yacc.c:1646  */
    {}
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 87 "parser.y" /* yacc.c:1646  */
    {}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 90 "parser.y" /* yacc.c:1646  */
    {}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 91 "parser.y" /* yacc.c:1646  */
    {}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 92 "parser.y" /* yacc.c:1646  */
    {}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 93 "parser.y" /* yacc.c:1646  */
    {}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 94 "parser.y" /* yacc.c:1646  */
    {}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 97 "parser.y" /* yacc.c:1646  */
    {}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 98 "parser.y" /* yacc.c:1646  */
    {}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 101 "parser.y" /* yacc.c:1646  */
    {
    printer("var_declaration : type_specifier declaration_list SEMICOLON");
    if((yyvsp[-2])->TokenName != "void"){
        string setTypeSpecifier=(yyvsp[-2])->TokenName;
        int dlsize = (yyvsp[-1])->declarationList.size();
        for(int i=0; i<dlsize; i++){
            (yyvsp[-1])->declarationList[i].TokenName = setTypeSpecifier;
            int resizevalue = (yyvsp[-1])->declarationList[i].ArraySize;
            if( resizevalue != 0){
                if(setTypeSpecifier == "int"){ (yyvsp[-1])->declarationList[i].intArray.resize(resizevalue+1);  }
                else{   (yyvsp[-1])->declarationList[i].floatArray.resize(resizevalue+1);  }
            }
            
            bool b = table->Insert((yyvsp[-1])->declarationList[i]);
            if(!b){
                ErrorCount++;
                fprintf(errorfile, ". Rule: yyError at Line %d: same variable declared multiple times\n", LineNo);
            
            }
        }
        
    }else{
        ErrorCount++;
        fprintf(errorfile, ". Rule: yyError at Line %d: variable type cannot be void\n", LineNo);
    }
}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 129 "parser.y" /* yacc.c:1646  */
    {   printer("type_specifier :INT"); (yyval)->TokenName ="int"; (yyval)->TokenAttr ="int";   }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 130 "parser.y" /* yacc.c:1646  */
    {   printer("type_specifier :FLOAT"); (yyval)->TokenName ="float"; (yyval)->TokenAttr ="int";   }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 131 "parser.y" /* yacc.c:1646  */
    {   printer("type_specifier :void"); (yyval)->TokenName ="void";(yyval)->TokenAttr ="int";       }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 134 "parser.y" /* yacc.c:1646  */
    {
             	printer("declaration_list : declaration_list COMMA ID");
             	(yyval) = (yyvsp[-2]);
                (yyval)->declarationList.push_back(*(yyvsp[0]));
             	
}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 140 "parser.y" /* yacc.c:1646  */
    {
 		  
 		    printer("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
 		    (yyvsp[-1])->setValue();
 		    (yyvsp[-3])->ArraySize = (yyvsp[-1])->value;
 		    (yyvsp[-3])->isArray = true;
 		    (yyvsp[-5])->declarationList.push_back(*(yyvsp[-3]));
 		    (yyval) = (yyvsp[-5]);
 		  
 		  }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 150 "parser.y" /* yacc.c:1646  */
    {
             	printer("declaration_list : ID");
             	
             	(yyval)->declarationList.push_back(*(yyvsp[0]));	  
 		  }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 155 "parser.y" /* yacc.c:1646  */
    {
 		    printer("declaration_list : ID LTHIRD CONST_INT RTHIRD");
 		    (yyvsp[-1])->setValue();
 		    (yyvsp[-3])->ArraySize = (yyvsp[-1])->value;
 		    (yyvsp[-3])->isArray = true;
 		    (yyval) = (yyvsp[-3]);
 		  }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 164 "parser.y" /* yacc.c:1646  */
    {}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 165 "parser.y" /* yacc.c:1646  */
    {}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 168 "parser.y" /* yacc.c:1646  */
    {}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 169 "parser.y" /* yacc.c:1646  */
    {}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 170 "parser.y" /* yacc.c:1646  */
    {}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 171 "parser.y" /* yacc.c:1646  */
    {}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 172 "parser.y" /* yacc.c:1646  */
    {}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 173 "parser.y" /* yacc.c:1646  */
    {}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 174 "parser.y" /* yacc.c:1646  */
    {}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 175 "parser.y" /* yacc.c:1646  */
    {}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 176 "parser.y" /* yacc.c:1646  */
    {}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 179 "parser.y" /* yacc.c:1646  */
    {}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 180 "parser.y" /* yacc.c:1646  */
    {}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 183 "parser.y" /* yacc.c:1646  */
    {}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 184 "parser.y" /* yacc.c:1646  */
    {}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 187 "parser.y" /* yacc.c:1646  */
    {}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 188 "parser.y" /* yacc.c:1646  */
    {}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 191 "parser.y" /* yacc.c:1646  */
    {}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 192 "parser.y" /* yacc.c:1646  */
    {}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 195 "parser.y" /* yacc.c:1646  */
    {}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 196 "parser.y" /* yacc.c:1646  */
    {}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 199 "parser.y" /* yacc.c:1646  */
    {}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 200 "parser.y" /* yacc.c:1646  */
    {}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 203 "parser.y" /* yacc.c:1646  */
    {}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 204 "parser.y" /* yacc.c:1646  */
    {}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 207 "parser.y" /* yacc.c:1646  */
    {}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 208 "parser.y" /* yacc.c:1646  */
    {}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 209 "parser.y" /* yacc.c:1646  */
    {}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 212 "parser.y" /* yacc.c:1646  */
    {}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 213 "parser.y" /* yacc.c:1646  */
    {}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 214 "parser.y" /* yacc.c:1646  */
    {}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 215 "parser.y" /* yacc.c:1646  */
    {}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 216 "parser.y" /* yacc.c:1646  */
    {}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 217 "parser.y" /* yacc.c:1646  */
    {}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 218 "parser.y" /* yacc.c:1646  */
    {}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 219 "parser.y" /* yacc.c:1646  */
    {}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 222 "parser.y" /* yacc.c:1646  */
    {}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 223 "parser.y" /* yacc.c:1646  */
    {}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 224 "parser.y" /* yacc.c:1646  */
    {}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1865 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 228 "parser.y" /* yacc.c:1906  */

            
main()
{
    table = new SymbolTable;
    table->EnterScope();
    yyin = fopen("zin.c", "r");
    //logfile = fopen("zlog.txt", "w");
    errorfile= fopen("zerror.txt", "w");
    //tablefile= fopen("zsymtab.txt", "w");
    freopen("zsymtab.txt","w",stdout);
    yyparse();
    table->PrintAllScopeTable();
    fclose(yyin);

    fclose(errorfile);
    logout.close();

    exit(0);

}

/*

start 	: program	{}
		;

program : program unit {} 
	| unit {}
	;
	
unit : var_declaration {}
     | func_declaration {}
     | func_definition {}
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {}
		 ;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement {}
 		 ;
 		 
parameter_list  : parameter_list COMMA type_specifier ID {}
		| parameter_list COMMA type_specifier	 {}
 		| type_specifier ID 					{}
 		| type_specifier						{}
 		|										{}
 		;
 		
compound_statement : LCURL statements RCURL		{}
 		    | LCURL RCURL						{}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON		{}
 		 ;
 		 
type_specifier	: INT		{}
 		| FLOAT				{}
 		| VOID				{}
 		;
 		
declaration_list : declaration_list COMMA ID 		{}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD 	{}
 		  | ID													{}
 		  | ID LTHIRD CONST_INT RTHIRD							{}
 		  ;
 		  
statements : statement								{}
	   | statements statement						{}
	   ;
	   
statement : var_declaration					{}
	  | expression_statement				{}
	  | compound_statement					{}
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement	{}
	  | IF LPAREN expression RPAREN statement												{}
	  | IF LPAREN expression RPAREN statement ELSE statement								{}
	  | WHILE LPAREN expression RPAREN statement											{}
	  | PRINTLN LPAREN ID RPAREN SEMICOLON													{}
	  | RETURN expression SEMICOLON															{}
	  ;
	  
expression_statement 	: SEMICOLON						{}
			| expression SEMICOLON 						{}
			;
	  
variable : ID 							{}
	 | ID LTHIRD expression RTHIRD 		{}
	 ;
	 
 expression : logic_expression			{}
	   | variable ASSIGNOP logic_expression		{} 	
	   ;
			
logic_expression : rel_expression 	{}
		 | rel_expression LOGICOP rel_expression	{} 	
		 ;
			
rel_expression	: simple_expression 		{}
		| simple_expression RELOP simple_expression		{}	
		;
				
simple_expression : term 					{}
		  | simple_expression ADDOP term 	{}
		  ;
					
term :	unary_expression					{}
     |  term MULOP unary_expression			{}
     ;

unary_expression : ADDOP unary_expression  {}
		 | NOT unary_expression 			{}
		 | factor 							{}
		 ;
	
factor	: variable 							{}
	| ID LPAREN argument_list RPAREN		{
	                                            printer("factor : ID LPAREN argument_list RPAREN");
                                                Token *temp = table->LookUp($1->TokenAttr);
                                                if( (temp!=NULL) && ($1->idtype == "FUNCTION") ){
                                                    vector<string> *declared_arguments = temp->arglist;
				                                    int size1 = declared_arguments->size();
				                                    int size2 = $3->arglist->size();
				                                    if(size1 != size2) {
				                                        ErrorCount++;
				                                        fprintf(errorfile, "BisonError at Line %d: %s\n", LineNo, yytext);
                     
				                                    }else{
				                                        for(int i = 0; i < size1; ++i){
				                                            if(declared_arguments[i] != ($3)->arglist[i]){
				                                                error_count++;
				    fprintf(errorfile, "Error at Line %d: %dth argument mismatch in func %s\n", line_count, i+1, temp->getname().c_str());
				    break;
				                                            }
				                                        }
				                                        $$->TokenName = temp->functionreturn;
				                                    }
                                                }   
                                            }
	| LPAREN expression RPAREN				{
	                                            printer("factor : LPAREN expression RPAREN");
                                                $$ = $2;   
                                            }
	| CONST_INT 							{
	                                            printer("factor : CONST_INT");
                                                $$ = $1;   
                                            }
	| CONST_FLOAT							{   
	                                            printer("factor : CONST_FLOAT");
                                                $$ = $1;    
                                        	}
	| CONST_CHAR							{
                printer("factor : CONST_CHAR");
                $$ = $1;    
            }
	| variable INCOP 						{
        printer("factor : INCOP");
        $1->value = $1->value-1;
    }
	| variable DECOP						{
        printer("factor : DECOP");
        $1->value = $1->value-1;
    }
	;

	
argument_list : argument_list COMMA logic_expression	{
            printer("argument_list : argument_list COMMA logic_expression\n");
			$$ = $1;
			$$->arglist->push_back($3->TokenName);
                                        }
	      | logic_expression	{
                                    printer("argument_list : logic_expression\n");
                                    vector<string> *temp = new vector<string>();
                                    $$->arglist = temp;
                                    $$->arglist->push_back($1->TokenName);
                                }
	      |     {   
                    printer("argument_list");
                    vector<string> *temp = new vector<string>();
                    $$->arglist = temp;
                            
                }
	      ;

 */

