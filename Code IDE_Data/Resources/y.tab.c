
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "kYacc.y"



	#include <stdarg.h>

	#include "compiler.c"

	#include<math.h> 



	

	  int yylex(void);
	extern int CURRENT_LINE;


		/* prototypes */
	nodeType *opr(int oper, int nops, ...);
	nodeType *id( int flag, char name[], int per);
	nodeType *getid(char name[]);
	nodeType *con(char* s, int flag);


	void freeNode(nodeType *p);
	int ex(nodeType *p);



		/*Braces*/

	#define nestingStackMaxLength 15
	int NestingStack[15];
	int level = -1; //The level of the scope  ( we can Inc and Dec this variable)
	int scopeId = 0; //The ID of the scope   (We can only Inc this variable to ensure we have a unique identifer for each scope)

	int isLogical = 0;
	int isDeclaration = 0 ;
	void openScope();
	void closeScope();

	/*End of Braces */



/* Line 189 of yacc.c  */
#line 119 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_VALUE = 258,
     FLOAT_VALUE = 259,
     CHAR_VALUE = 260,
     STRING_VALUE = 261,
     COMMENT = 262,
     IDENTIFIER = 263,
     INT = 264,
     CHAR = 265,
     FLOAT = 266,
     STRING = 267,
     BOOLEAN = 268,
     DOUBLE = 269,
     SINGLE_QUOTE = 270,
     DOUBLE_QUOTE = 271,
     SEMI_COLON = 272,
     OPENED_BRACKET = 273,
     CLOSED_BRACKET = 274,
     OPENED_BRACE = 275,
     CLOSED_BRACE = 276,
     OPENED_SQ_BRACKET = 277,
     CLOSED_SQ_BRACKET = 278,
     COMMA = 279,
     TWO_DOTS = 280,
     AND_AND = 281,
     OR_OR = 282,
     EQUAL_EQUAL = 283,
     NOT_EQUAL = 284,
     GREATER_THAN = 285,
     GREATER_THAN_EQUAL = 286,
     SMALLER_THAN = 287,
     SMALLER_THAN_EQUAL = 288,
     NOT = 289,
     PLUS_PLUS = 290,
     MINUS_MINUS = 291,
     PLUS = 292,
     MINUS = 293,
     MULTIPLY = 294,
     DIVIDE = 295,
     REMAINDER = 296,
     PLUS_EQUAL = 297,
     MINUS_EQUAL = 298,
     MULTIPLY_EQUAL = 299,
     DIVIDE_EQUAL = 300,
     IF = 301,
     ELSE = 302,
     DO = 303,
     WHILE = 304,
     FOR = 305,
     SWITCH = 306,
     CASE = 307,
     DEFAULT = 308,
     BREAK = 309,
     TRUE = 310,
     FALSE = 311,
     MAIN = 312,
     VOID = 313,
     EQUAL = 314
   };
#endif
/* Tokens.  */
#define INT_VALUE 258
#define FLOAT_VALUE 259
#define CHAR_VALUE 260
#define STRING_VALUE 261
#define COMMENT 262
#define IDENTIFIER 263
#define INT 264
#define CHAR 265
#define FLOAT 266
#define STRING 267
#define BOOLEAN 268
#define DOUBLE 269
#define SINGLE_QUOTE 270
#define DOUBLE_QUOTE 271
#define SEMI_COLON 272
#define OPENED_BRACKET 273
#define CLOSED_BRACKET 274
#define OPENED_BRACE 275
#define CLOSED_BRACE 276
#define OPENED_SQ_BRACKET 277
#define CLOSED_SQ_BRACKET 278
#define COMMA 279
#define TWO_DOTS 280
#define AND_AND 281
#define OR_OR 282
#define EQUAL_EQUAL 283
#define NOT_EQUAL 284
#define GREATER_THAN 285
#define GREATER_THAN_EQUAL 286
#define SMALLER_THAN 287
#define SMALLER_THAN_EQUAL 288
#define NOT 289
#define PLUS_PLUS 290
#define MINUS_MINUS 291
#define PLUS 292
#define MINUS 293
#define MULTIPLY 294
#define DIVIDE 295
#define REMAINDER 296
#define PLUS_EQUAL 297
#define MINUS_EQUAL 298
#define MULTIPLY_EQUAL 299
#define DIVIDE_EQUAL 300
#define IF 301
#define ELSE 302
#define DO 303
#define WHILE 304
#define FOR 305
#define SWITCH 306
#define CASE 307
#define DEFAULT 308
#define BREAK 309
#define TRUE 310
#define FALSE 311
#define MAIN 312
#define VOID 313
#define EQUAL 314




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 47 "kYacc.y"
     


	int   intValue;	    	/* integer value */
	float floatValue;    	/* float value */
	char  charValue;    	/* char value */
	char* stringValue;  	/* string value*/
	char* identifier;       /* identifier name */
	char* comment;
	char* DataType;
	nodeType* nPtr;




/* Line 214 of yacc.c  */
#line 289 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 301 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   338

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    11,    14,    15,    17,    19,    21,    23,
      25,    27,    30,    33,    36,    40,    46,    52,    58,    62,
      66,    70,    74,    78,    82,    86,    88,    90,    92,    94,
      96,    98,   102,   106,   110,   114,   118,   122,   126,   130,
     134,   138,   141,   145,   147,   149,   151,   153,   155,   159,
     163,   167,   171,   175,   179,   181,   184,   187,   190,   193,
     201,   213,   221,   224,   226,   228,   229,   239,   241,   244,
     247,   257,   265,   273,   275,   281,   283,   285,   287,   289,
     291,   293,   295,   297,   299,   301,   303,   305,   307,   309,
     311
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      61,     0,    -1,    58,    57,    18,    19,    84,    62,    85,
      -1,    62,    63,    -1,    -1,    72,    -1,    71,    -1,    78,
      -1,    75,    -1,    79,    -1,    64,    -1,    65,    17,    -1,
      66,    17,    -1,    70,    17,    -1,    86,     8,    17,    -1,
      86,     8,    59,     8,    17,    -1,    86,     8,    59,    82,
      17,    -1,    86,     8,    59,    68,    17,    -1,     8,    59,
       8,    -1,     8,    59,    82,    -1,     8,    59,    68,    -1,
       8,    43,    69,    -1,     8,    42,    69,    -1,     8,    45,
      69,    -1,     8,    44,    69,    -1,     8,    -1,     6,    -1,
       5,    -1,    87,    -1,     3,    -1,     4,    -1,    67,    27,
      67,    -1,    67,    26,    67,    -1,    67,    29,    67,    -1,
      67,    28,    67,    -1,    69,    29,    69,    -1,    69,    28,
      69,    -1,    69,    30,    69,    -1,    69,    31,    69,    -1,
      69,    32,    69,    -1,    69,    33,    69,    -1,    34,    67,
      -1,    18,    67,    19,    -1,    69,    -1,    67,    -1,     8,
      -1,     3,    -1,     4,    -1,    69,    38,    69,    -1,    69,
      37,    69,    -1,    69,    40,    69,    -1,    69,    39,    69,
      -1,    69,    41,    69,    -1,    18,    69,    19,    -1,    70,
      -1,    35,     8,    -1,    36,     8,    -1,     8,    35,    -1,
       8,    36,    -1,    46,    18,    67,    19,    84,    74,    85,
      -1,    46,    18,    67,    19,    84,    74,    85,    47,    84,
      74,    85,    -1,    49,    18,    67,    19,    84,    74,    85,
      -1,    73,    63,    -1,    63,    -1,    73,    -1,    -1,    50,
      18,    76,    77,    69,    19,    84,    74,    85,    -1,    64,
      -1,    65,    17,    -1,    67,    17,    -1,    48,    84,    74,
      85,    49,    18,    67,    19,    17,    -1,    51,    18,     8,
      19,    84,    80,    85,    -1,    52,    82,    25,    74,    54,
      17,    80,    -1,    81,    -1,    53,    25,    74,    54,    17,
      -1,    83,    -1,     6,    -1,     5,    -1,    87,    -1,     3,
      -1,     4,    -1,    20,    -1,    21,    -1,     9,    -1,    11,
      -1,    12,    -1,    10,    -1,    13,    -1,    14,    -1,    55,
      -1,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   111,   115,   120,   121,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   138,   146,   153,   160,   170,   171,
     172,   178,   179,   180,   181,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   207,   208,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   226,   227,   228,   229,   236,
     237,   244,   247,   247,   249,   250,   252,   256,   257,   261,
     264,   274,   277,   278,   281,   286,   287,   288,   289,   292,
     293,   296,   298,   300,   301,   302,   303,   304,   305,   308,
     309
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_VALUE", "FLOAT_VALUE", "CHAR_VALUE",
  "STRING_VALUE", "COMMENT", "IDENTIFIER", "INT", "CHAR", "FLOAT",
  "STRING", "BOOLEAN", "DOUBLE", "SINGLE_QUOTE", "DOUBLE_QUOTE",
  "SEMI_COLON", "OPENED_BRACKET", "CLOSED_BRACKET", "OPENED_BRACE",
  "CLOSED_BRACE", "OPENED_SQ_BRACKET", "CLOSED_SQ_BRACKET", "COMMA",
  "TWO_DOTS", "AND_AND", "OR_OR", "EQUAL_EQUAL", "NOT_EQUAL",
  "GREATER_THAN", "GREATER_THAN_EQUAL", "SMALLER_THAN",
  "SMALLER_THAN_EQUAL", "NOT", "PLUS_PLUS", "MINUS_MINUS", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "REMAINDER", "PLUS_EQUAL", "MINUS_EQUAL",
  "MULTIPLY_EQUAL", "DIVIDE_EQUAL", "IF", "ELSE", "DO", "WHILE", "FOR",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "TRUE", "FALSE", "MAIN", "VOID",
  "EQUAL", "$accept", "main", "body", "leftfactor", "declaration",
  "assignment", "mathassignment", "logicalexpr", "expr", "mathexpr", "pp",
  "ifstmt", "whilestmt", "leftfactorlist", "bodyloop", "forstmt", "a", "b",
  "dowhilestmt", "switchstmt", "casestmt", "defaultstmt", "val", "number",
  "OPENBRACE", "CLOSEBRACE", "datatype", "boolean", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    64,    64,    64,    65,    65,
      65,    66,    66,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    70,    70,    71,
      71,    72,    73,    73,    74,    74,    75,    76,    76,    77,
      78,    79,    80,    80,    81,    82,    82,    82,    82,    83,
      83,    84,    85,    86,    86,    86,    86,    86,    86,    87,
      87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     0,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     5,     5,     5,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     1,     2,     2,     2,     2,     7,
      11,     7,     2,     1,     1,     0,     9,     1,     2,     2,
       9,     7,     7,     1,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,    81,     4,     0,
       0,    83,    86,    84,    85,    87,    88,    82,     0,     0,
       0,     0,     0,     0,     0,     3,    10,     0,     0,     0,
       6,     5,     8,     7,     9,     2,     0,    57,    58,     0,
       0,     0,     0,     0,    55,    56,     0,    65,     0,     0,
       0,    11,    12,    13,     0,    46,    47,    45,     0,    22,
      54,    21,    24,    23,    46,    47,    27,    26,    45,     0,
       0,    89,    90,    44,    20,    43,    19,    75,    28,    46,
      47,    27,    26,    45,     0,     0,    28,    63,    64,     0,
       0,     0,    67,     0,     0,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
       0,    68,     0,     0,     0,    45,     0,     0,    53,    49,
      48,    51,    50,    52,    42,    32,    31,    34,    33,    36,
      35,    37,    38,    39,    40,    65,     0,    65,    69,     0,
       0,    15,    17,    16,     0,     0,     0,     0,     0,     0,
       0,    73,    59,     0,    61,    65,    79,    80,    77,    76,
       0,    78,    65,    71,     0,     0,     0,    65,     0,    65,
      70,    66,     0,     0,     0,     0,    74,    60,     0,    72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    87,    26,    27,    28,    73,    74,    85,
      60,    30,    31,    88,    89,    32,    94,   123,    33,    34,
     160,   161,    76,    77,     8,    35,    36,    86
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -137
static const yytype_int16 yypact[] =
{
     -50,   -47,    30,     1,  -137,    23,    43,  -137,  -137,     4,
     122,  -137,  -137,  -137,  -137,  -137,  -137,  -137,    49,    68,
      74,    43,    87,    88,    89,  -137,  -137,    61,    63,    92,
    -137,  -137,  -137,  -137,  -137,  -137,   102,  -137,  -137,   202,
     202,   202,   202,    90,  -137,  -137,   144,   179,   144,   324,
     103,  -137,  -137,  -137,    11,  -137,  -137,    13,   202,   157,
    -137,   157,   157,   157,   272,   294,  -137,  -137,   255,   144,
     144,  -137,  -137,   221,  -137,   277,  -137,  -137,  -137,    18,
     190,  -137,  -137,   251,     5,   277,  -137,  -137,   179,    93,
      55,    54,  -137,    98,   144,   104,  -137,   168,   220,   202,
     202,   202,   202,   202,   156,   203,  -137,   144,   144,   144,
     144,   202,   202,   202,   202,   202,   202,    43,  -137,    78,
      43,  -137,   302,   202,    43,   268,   111,   112,  -137,    62,
      62,  -137,  -137,  -137,  -137,  -137,  -137,    60,    60,   157,
     157,   157,   157,   157,   157,   179,   121,   179,  -137,   226,
      37,  -137,  -137,  -137,    93,   144,    93,    43,    17,   115,
      93,  -137,    94,   227,  -137,   179,  -137,  -137,  -137,  -137,
     118,  -137,   179,  -137,    43,   127,    93,   179,    97,   179,
    -137,  -137,    99,   138,    93,   142,  -137,  -137,    37,  -137
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,  -137,    -3,   120,   128,  -137,   -43,    64,    19,
      -9,  -137,  -137,  -137,  -136,  -137,  -137,  -137,  -137,  -137,
     -28,  -137,   -90,  -137,   -20,   -85,  -137,   -41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -31
static const yytype_int16 yytable[] =
{
      29,    47,    78,    84,   119,    90,    25,   127,     1,   154,
       3,   156,    10,    11,    12,    13,    14,    15,    16,     5,
     166,   167,   168,   169,   117,    17,   104,   106,    96,   176,
       4,   107,   108,   109,   110,   -29,   178,   -29,    29,    18,
      19,   182,     6,   184,   -29,   -29,   -29,   -29,    37,    38,
      20,   122,    21,    22,    23,    24,    78,    44,    59,    61,
      62,    63,    75,     7,   135,   136,   137,   138,   170,   162,
      97,   164,    71,    72,   120,   173,    45,    98,    51,    29,
      52,   107,   108,   109,   110,   118,   107,   108,   105,   158,
     159,   181,    46,    64,    65,    66,    67,   145,    68,   187,
     147,   101,   102,   103,   150,    48,    49,    50,    69,    53,
      54,    95,   163,    43,    17,   121,    75,   171,   129,   130,
     131,   132,   133,   124,    70,    18,    19,   146,   152,   153,
     139,   140,   141,   142,   143,   144,    29,   165,    29,   155,
     172,   174,   149,   177,   180,    71,    72,    79,    80,    81,
      82,   183,    83,   185,   179,   186,    29,    37,    38,   188,
     189,   126,    69,    29,    39,    40,    41,    42,    29,    92,
      29,    64,    65,    66,    67,   134,   125,    93,    70,    18,
      19,    43,   107,   108,   109,   110,    69,    10,    11,    12,
      13,    14,    15,    16,    99,   100,   101,   102,   103,    71,
      72,     0,    70,    18,    19,    55,    56,   -30,     0,   -30,
      57,     0,     0,     0,    18,    19,   -30,   -30,   -30,   -30,
      58,     0,   128,    71,    72,    20,     0,    21,    22,    23,
      24,   111,   112,   113,   114,   115,   116,    18,    19,   128,
      99,   100,   101,   102,   103,   157,   175,   107,   108,   109,
     110,     0,     0,   107,   108,   109,   110,    99,   100,   101,
     102,   103,     0,    99,   100,   101,   102,   103,   -25,     0,
     -25,     0,   -18,     0,     0,     0,     0,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   151,    37,    38,     0,   -29,
      37,    38,     0,     0,   -25,   -25,   -25,   -25,   -29,   -29,
     -29,   -29,     0,    37,    38,   111,   112,   113,   114,   115,
     116,   -30,     0,     0,    99,   100,   101,   102,   103,   148,
     -30,   -30,   -30,   -30,     0,     0,     0,     0,   107,   108,
     109,   110,    91,    11,    12,    13,    14,    15,    16
};

static const yytype_int16 yycheck[] =
{
       9,    21,    43,    46,    89,    48,     9,    97,    58,   145,
      57,   147,     8,     9,    10,    11,    12,    13,    14,    18,
       3,     4,     5,     6,    19,    21,    69,    70,    17,   165,
       0,    26,    27,    28,    29,    17,   172,    19,    47,    35,
      36,   177,    19,   179,    26,    27,    28,    29,    35,    36,
      46,    94,    48,    49,    50,    51,    97,     8,    39,    40,
      41,    42,    43,    20,   107,   108,   109,   110,   158,   154,
      59,   156,    55,    56,    19,   160,     8,    58,    17,    88,
      17,    26,    27,    28,    29,    88,    26,    27,    69,    52,
      53,   176,    18,     3,     4,     5,     6,   117,     8,   184,
     120,    39,    40,    41,   124,    18,    18,    18,    18,    17,
       8,     8,   155,    59,    21,    17,    97,   158,    99,   100,
     101,   102,   103,    19,    34,    35,    36,    49,    17,    17,
     111,   112,   113,   114,   115,   116,   145,   157,   147,    18,
      25,    47,   123,    25,    17,    55,    56,     3,     4,     5,
       6,    54,     8,    54,   174,    17,   165,    35,    36,    17,
     188,    97,    18,   172,    42,    43,    44,    45,   177,    49,
     179,     3,     4,     5,     6,    19,     8,    49,    34,    35,
      36,    59,    26,    27,    28,    29,    18,     8,     9,    10,
      11,    12,    13,    14,    37,    38,    39,    40,    41,    55,
      56,    -1,    34,    35,    36,     3,     4,    17,    -1,    19,
       8,    -1,    -1,    -1,    35,    36,    26,    27,    28,    29,
      18,    -1,    19,    55,    56,    46,    -1,    48,    49,    50,
      51,    28,    29,    30,    31,    32,    33,    35,    36,    19,
      37,    38,    39,    40,    41,    19,    19,    26,    27,    28,
      29,    -1,    -1,    26,    27,    28,    29,    37,    38,    39,
      40,    41,    -1,    37,    38,    39,    40,    41,    17,    -1,
      19,    -1,    17,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    26,    27,    28,    29,    17,    35,    36,    -1,    17,
      35,    36,    -1,    -1,    26,    27,    28,    29,    26,    27,
      28,    29,    -1,    35,    36,    28,    29,    30,    31,    32,
      33,    17,    -1,    -1,    37,    38,    39,    40,    41,    17,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,     8,     9,    10,    11,    12,    13,    14
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,    61,    57,     0,    18,    19,    20,    84,    62,
       8,     9,    10,    11,    12,    13,    14,    21,    35,    36,
      46,    48,    49,    50,    51,    63,    64,    65,    66,    70,
      71,    72,    75,    78,    79,    85,    86,    35,    36,    42,
      43,    44,    45,    59,     8,     8,    18,    84,    18,    18,
      18,    17,    17,    17,     8,     3,     4,     8,    18,    69,
      70,    69,    69,    69,     3,     4,     5,     6,     8,    18,
      34,    55,    56,    67,    68,    69,    82,    83,    87,     3,
       4,     5,     6,     8,    67,    69,    87,    63,    73,    74,
      67,     8,    64,    65,    76,     8,    17,    59,    69,    37,
      38,    39,    40,    41,    67,    69,    67,    26,    27,    28,
      29,    28,    29,    30,    31,    32,    33,    19,    63,    85,
      19,    17,    67,    77,    19,     8,    68,    82,    19,    69,
      69,    69,    69,    69,    19,    67,    67,    67,    67,    69,
      69,    69,    69,    69,    69,    84,    49,    84,    17,    69,
      84,    17,    17,    17,    74,    18,    74,    19,    52,    53,
      80,    81,    85,    67,    85,    84,     3,     4,     5,     6,
      82,    87,    25,    85,    47,    19,    74,    25,    74,    84,
      17,    85,    74,    54,    74,    54,    17,    85,    17,    80
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 120 "kYacc.y"
    { fprintf(yyout," "); int error = ex((yyvsp[(2) - (2)].nPtr));freeNode((yyvsp[(2) - (2)].nPtr)); if(error == -1) return; }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 121 "kYacc.y"
    { (yyval.nPtr) = opr(9999, 0);}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 138 "kYacc.y"
    {
									isDeclaration = 1;
								if ((yyvsp[(1) - (3)].DataType) == "int" ) (yyval.nPtr) = id( 0, (yyvsp[(2) - (3)].identifier), 0);
								else if((yyvsp[(1) - (3)].DataType) == "float") (yyval.nPtr) = id(1, (yyvsp[(2) - (3)].identifier), 0);
								else if  ((yyvsp[(1) - (3)].DataType) == "char") (yyval.nPtr) = id(2, (yyvsp[(2) - (3)].identifier), 0);
								else if  ((yyvsp[(1) - (3)].DataType) == "string") (yyval.nPtr) = id(3, (yyvsp[(2) - (3)].identifier), 0);
								else if((yyvsp[(1) - (3)].DataType) == "boolean" ) (yyval.nPtr) = id( 4, (yyvsp[(2) - (3)].identifier), 0);
							}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 146 "kYacc.y"
    {
							if ((yyvsp[(1) - (5)].DataType) == "int") {(yyval.nPtr) = opr(EQUAL, 2, id(0, (yyvsp[(2) - (5)].identifier), 0), getid((yyvsp[(4) - (5)].identifier)));}
							else if ((yyvsp[(1) - (5)].DataType) == "float") {(yyval.nPtr) = opr(EQUAL, 2, id( 1, (yyvsp[(2) - (5)].identifier), 0), getid((yyvsp[(4) - (5)].identifier)));}
	  					else if ((yyvsp[(1) - (5)].DataType) == "char") {(yyval.nPtr) = opr(EQUAL, 2, id(2, (yyvsp[(2) - (5)].identifier), 0), getid((yyvsp[(4) - (5)].identifier)));}
	  					else if ((yyvsp[(1) - (5)].DataType) == "string") {(yyval.nPtr) = opr(EQUAL, 2, id(3, (yyvsp[(2) - (5)].identifier), 0), getid((yyvsp[(4) - (5)].identifier)));}
							else if ((yyvsp[(1) - (5)].DataType) == "boolean") {(yyval.nPtr) = opr(EQUAL, 2, id(4, (yyvsp[(2) - (5)].identifier), 0), getid((yyvsp[(4) - (5)].identifier)));}
						  }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 153 "kYacc.y"
    {
							  if( (yyvsp[(1) - (5)].DataType) == "int")  (yyval.nPtr) = opr(EQUAL, 2, id(0, (yyvsp[(2) - (5)].identifier), 0), (yyvsp[(4) - (5)].nPtr));
							  else if((yyvsp[(1) - (5)].DataType) == "float") (yyval.nPtr) = opr(EQUAL, 2, id(1, (yyvsp[(2) - (5)].identifier), 0), (yyvsp[(4) - (5)].nPtr));
	  						else if((yyvsp[(1) - (5)].DataType) == "char")  (yyval.nPtr) = opr(EQUAL, 2, id( 2, (yyvsp[(2) - (5)].identifier), 0), (yyvsp[(4) - (5)].nPtr));
	  						else if((yyvsp[(1) - (5)].DataType) == "string") (yyval.nPtr) = opr(EQUAL, 2, id( 3, (yyvsp[(2) - (5)].identifier), 0), (yyvsp[(4) - (5)].nPtr));
	  						else if((yyvsp[(1) - (5)].DataType) == "boolean") (yyval.nPtr) = opr(EQUAL, 2, id(4, (yyvsp[(2) - (5)].identifier), 0), (yyvsp[(4) - (5)].nPtr));
		  															}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 160 "kYacc.y"
    {
								if ((yyvsp[(1) - (5)].DataType) == "int")  (yyval.nPtr) = opr(EQUAL, 2, id(0, (yyvsp[(2) - (5)].identifier), 0), (yyvsp[(4) - (5)].nPtr));
								else if ((yyvsp[(1) - (5)].DataType) == "float")   (yyval.nPtr) = opr(EQUAL, 2, id(1, (yyvsp[(2) - (5)].identifier), 0), (yyvsp[(4) - (5)].nPtr));
								else if ((yyvsp[(1) - (5)].DataType) == "char")   (yyval.nPtr) = opr(EQUAL, 2, id(2, (yyvsp[(2) - (5)].identifier), 0), (yyvsp[(4) - (5)].nPtr));
								else if ((yyvsp[(1) - (5)].DataType) == "string") (yyval.nPtr) = opr(EQUAL, 2, id(3, (yyvsp[(2) - (5)].identifier), 0), (yyvsp[(4) - (5)].nPtr));
								else if ((yyvsp[(1) - (5)].DataType) == "boolean") (yyval.nPtr) = opr(EQUAL, 2, id(4, (yyvsp[(2) - (5)].identifier), 0), (yyvsp[(4) - (5)].nPtr));
						}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 170 "kYacc.y"
    { (yyval.nPtr) = opr(EQUAL, 2, getid((yyvsp[(1) - (3)].identifier)), getid((yyvsp[(3) - (3)].identifier)));}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 171 "kYacc.y"
    { (yyval.nPtr) = opr(EQUAL, 2, getid((yyvsp[(1) - (3)].identifier)), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 172 "kYacc.y"
    { (yyval.nPtr) = opr(EQUAL, 2, getid((yyvsp[(1) - (3)].identifier)), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 178 "kYacc.y"
    { (yyval.nPtr) = opr(MINUS_EQUAL, 2, getid((yyvsp[(1) - (3)].identifier)), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 179 "kYacc.y"
    { (yyval.nPtr) = opr(PLUS_EQUAL, 2, getid((yyvsp[(1) - (3)].identifier)), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 180 "kYacc.y"
    { (yyval.nPtr) = opr(DIVIDE_EQUAL, 2, getid((yyvsp[(1) - (3)].identifier)), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 181 "kYacc.y"
    { (yyval.nPtr) = opr(MULTIPLY_EQUAL, 2, getid((yyvsp[(1) - (3)].identifier)), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 187 "kYacc.y"
    {isLogical=1; (yyval.nPtr) = getid((yyvsp[(1) - (1)].identifier));}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 188 "kYacc.y"
    { isLogical=1; (yyval.nPtr) = con((yyvsp[(1) - (1)].stringValue),3);}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 189 "kYacc.y"
    { char *pChar = malloc(sizeof((yyvsp[(1) - (1)].charValue)));isLogical=1; (yyval.nPtr) = con(pChar,2);}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 190 "kYacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 191 "kYacc.y"
    { char c[] = {}; myitoa((yyvsp[(1) - (1)].intValue), c, 10); isLogical=1; (yyval.nPtr) = con(c,0);}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 192 "kYacc.y"
    {char c[] = {}; myftoa((yyvsp[(1) - (1)].floatValue), c, 10);isLogical=1;   (yyval.nPtr) = con(c,1);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 193 "kYacc.y"
    { (yyval.nPtr) = opr(OR_OR, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 194 "kYacc.y"
    { (yyval.nPtr) = opr(AND_AND, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 195 "kYacc.y"
    { (yyval.nPtr) = opr(NOT_EQUAL, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 196 "kYacc.y"
    { (yyval.nPtr) = opr(EQUAL_EQUAL, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 197 "kYacc.y"
    { (yyval.nPtr) = opr(NOT_EQUAL, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 198 "kYacc.y"
    { (yyval.nPtr) = opr(EQUAL_EQUAL, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 199 "kYacc.y"
    { (yyval.nPtr) = opr(GREATER_THAN, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 200 "kYacc.y"
    { (yyval.nPtr) = opr(GREATER_THAN_EQUAL, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 201 "kYacc.y"
    { (yyval.nPtr) = opr(SMALLER_THAN, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 202 "kYacc.y"
    { (yyval.nPtr) = opr(SMALLER_THAN_EQUAL, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 203 "kYacc.y"
    { (yyval.nPtr) = opr(NOT,1, (yyvsp[(2) - (2)].nPtr));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 204 "kYacc.y"
    { (yyval.nPtr) =(yyvsp[(2) - (3)].nPtr); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 207 "kYacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 208 "kYacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 214 "kYacc.y"
    { (yyval.nPtr) = getid((yyvsp[(1) - (1)].identifier));}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 215 "kYacc.y"
    { char c[] = {}; myitoa((yyvsp[(1) - (1)].intValue), c, 10);  (yyval.nPtr) = con(c,0);}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 216 "kYacc.y"
    {char c[] = {}; myftoa((yyvsp[(1) - (1)].floatValue), c, 10);   (yyval.nPtr) = con(c,1);}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 217 "kYacc.y"
    { (yyval.nPtr) = opr(MINUS, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 218 "kYacc.y"
    { (yyval.nPtr) = opr(PLUS, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 219 "kYacc.y"
    { (yyval.nPtr) = opr(DIVIDE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 220 "kYacc.y"
    { (yyval.nPtr) = opr(MULTIPLY, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 221 "kYacc.y"
    { (yyval.nPtr) = opr(REMAINDER, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 222 "kYacc.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 223 "kYacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 226 "kYacc.y"
    { (yyval.nPtr) = opr(PLUS_PLUS, 1,getid((yyvsp[(2) - (2)].identifier)));}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 227 "kYacc.y"
    { (yyval.nPtr) = opr(MINUS_MINUS, 1,getid((yyvsp[(2) - (2)].identifier)));}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 228 "kYacc.y"
    { (yyval.nPtr) = opr(PLUS_PLUS, 1,getid((yyvsp[(1) - (2)].identifier)));}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 229 "kYacc.y"
    { (yyval.nPtr) = opr(MINUS_MINUS, 1,getid((yyvsp[(1) - (2)].identifier)));}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 236 "kYacc.y"
    { (yyval.nPtr) = opr(IF, 2, (yyvsp[(3) - (7)].nPtr),(yyvsp[(6) - (7)].nPtr)); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 237 "kYacc.y"
    { (yyval.nPtr) = opr(IF, 3, (yyvsp[(3) - (11)].nPtr),(yyvsp[(6) - (11)].nPtr),(yyvsp[(10) - (11)].nPtr)); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 244 "kYacc.y"
    {(yyval.nPtr) = opr(WHILE,2 ,(yyvsp[(3) - (7)].nPtr),(yyvsp[(6) - (7)].nPtr)) ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 247 "kYacc.y"
    { (yyval.nPtr)=(yyvsp[(2) - (2)].nPtr);}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 247 "kYacc.y"
    { (yyval.nPtr)=(yyvsp[(1) - (1)].nPtr);}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 249 "kYacc.y"
    { (yyval.nPtr)=opr(SEMI_COLON,1,(yyvsp[(1) - (1)].nPtr));}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 250 "kYacc.y"
    { (yyval.nPtr) = opr(9999, 0);}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 252 "kYacc.y"
    {(yyval.nPtr) = opr(FOR,4,(yyvsp[(3) - (9)].nPtr),(yyvsp[(4) - (9)].nPtr),(yyvsp[(5) - (9)].nPtr),(yyvsp[(8) - (9)].nPtr)) ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 256 "kYacc.y"
    {(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 257 "kYacc.y"
    {(yyval.nPtr) = (yyvsp[(1) - (2)].nPtr) ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 261 "kYacc.y"
    {(yyval.nPtr) = (yyvsp[(1) - (2)].nPtr) ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 264 "kYacc.y"
    {(yyval.nPtr) = opr(DO,2,(yyvsp[(3) - (9)].nPtr),(yyvsp[(7) - (9)].nPtr)) ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 274 "kYacc.y"
    {(yyval.nPtr) = opr(SWITCH,2,getid((yyvsp[(3) - (7)].identifier)),(yyvsp[(6) - (7)].nPtr));}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 277 "kYacc.y"
    {(yyval.nPtr) = opr(CASE,4, (yyvsp[(2) - (7)].nPtr),(yyvsp[(4) - (7)].nPtr),opr(BREAK,0),(yyvsp[(7) - (7)].nPtr));}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 278 "kYacc.y"
    { (yyval.nPtr)=(yyvsp[(1) - (1)].nPtr);}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 281 "kYacc.y"
    {(yyval.nPtr) =opr(DEFAULT,2,(yyvsp[(3) - (5)].nPtr),opr(BREAK,0));}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 286 "kYacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr) ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 287 "kYacc.y"
    { (yyval.nPtr) = con((yyvsp[(1) - (1)].stringValue),3);}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 288 "kYacc.y"
    { char *pChar = malloc(sizeof((yyvsp[(1) - (1)].charValue))); (yyval.nPtr) = con(pChar,2);}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 289 "kYacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr) ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 292 "kYacc.y"
    { char c[] = {}; myitoa((yyvsp[(1) - (1)].intValue), c, 10);  (yyval.nPtr) = con(c,0);}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 293 "kYacc.y"
    { char c[] = {}; myftoa((yyvsp[(1) - (1)].floatValue), c, 10);  (yyval.nPtr) = con(c,1);}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 296 "kYacc.y"
    {openScope();}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 298 "kYacc.y"
    {closeScope();}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 300 "kYacc.y"
    {(yyval.DataType) = "int";}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 301 "kYacc.y"
    { (yyval.DataType) = "float";}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 302 "kYacc.y"
    {(yyval.DataType) = "string";}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 303 "kYacc.y"
    {(yyval.DataType) = "char"; }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 304 "kYacc.y"
    {(yyval.DataType) = "boolean";}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 305 "kYacc.y"
    {(yyval.DataType) ="double";}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 308 "kYacc.y"
    {  (yyval.nPtr) = con("true",4);}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 309 "kYacc.y"
    {  (yyval.nPtr) = con("false",4);}
    break;



/* Line 1455 of yacc.c  */
#line 2272 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 312 "kYacc.y"



#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)

nodeType *con(char* s, int flag) {
	nodeType *p;

	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");

	/* copy information */
	p->type = typeCon;
	p->con.value = strdup(s);
	p->con.flag = flag;
	p->con.isLogical = isLogical;
	isLogical = 0;
	return p;
}

nodeType *id( int flag, char name[], int per) {

	//Implementing new entry in the symbol table :)
	struct symbol_info *STEntry = malloc(sizeof(struct symbol_info));
	(*STEntry).name = name;
	printf("\n %s ",(*STEntry).name);
	(*STEntry).classtype = flag;
	if(level!=-1)
		(*STEntry).scopeId = NestingStack[level];
	if(per == -2)
		(*STEntry).isFinal = true;
	else
		(*STEntry).isFinal = false;


	nodeType *p;

	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");


	if( cInsert(STEntry) )
	{
		p->type = typeId;
		p->id.scopeId = NestingStack[level];
		p->id.name = strdup(name);
		p->id.permission = per;
		p->id.flag = flag;
		p->id.isDeclaration = isDeclaration;
		isDeclaration = 0;
		return p;

	}

	p->id.name = strdup(name);
	p->type = typeId;
	p->id.permission = -3;
	return p;
}

nodeType *getid(char name[]) {
	nodeType *p;

	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");

	int *errorMsg;
	struct symbol_info *STEntry = valSearch(name,NestingStack,level,errorMsg);
	p->type = typeId;
	p->id.name = strdup(name);
	if(*errorMsg == 404){
		p->id.permission = -1;
		return p;
	}
	else if((*STEntry).isFinal == true)
				p->id.permission = -2;
	else
				p->id.permission = 43;

	p->id.flag = STEntry->classtype;
	p->id.scopeId = STEntry->scopeId;
	p->id.name = strdup(name);


	p->type = typeId;

	isLogical=0;
	return p;
}

nodeType *opr(int oper, int nops, ...) {
	va_list ap;
	nodeType *p;
	int i;

	/* allocate node, extending op array */
	if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
		yyerror("out of memory");

	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
		p->opr.op[i] = va_arg(ap, nodeType*);

	va_end(ap);

	return p;
}

void freeNode(nodeType *p) {
	int i;
	if (!p)
		return;

	if (p->type == typeOpr) {
		for (i = 0; i < p->opr.nops; i++)
			freeNode(p->opr.op[i]);
	}

	free (p);
}


void openScope(){
	level = level + 1;
	printf("\n new level %d ",level);
	if(level!=-1)
		NestingStack[level] = scopeId;
	scopeId = scopeId + 1;

}


void closeScope(){

	printf("\n close level %d ",level);
	level = level -1;

	if(level ==-1)
		showSymbolTable();

}






 int yyerror(char *msg){
  fprintf(stderr," %s at line : << %d >> \n",msg,CURRENT_LINE);
return 1;
}



int main(){

yyin = fopen("testcase.txt", "r");
	yyout = fopen("symbolTable.txt", "w");
	if(yyin==NULL)
		 fprintf(yyout, "Error file not found!");
	else
	{
		printf("Hello file opened");

		yyparse();

	}
	return 0;
}
