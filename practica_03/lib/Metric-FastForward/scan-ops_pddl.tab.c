/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         ops_pddlparse
#define yylex           ops_pddllex
#define yyerror         ops_pddlerror
#define yydebug         ops_pddldebug
#define yynerrs         ops_pddlnerrs
#define yylval          ops_pddllval
#define yychar          ops_pddlchar

/* First part of user prologue.  */
#line 24 "scan-ops_pddl.y"

#ifdef YYDEBUG
  extern int yydebug=1;
#endif


#include <stdio.h>
#include <string.h> 
#include "ff.h"
#include "memory.h"
#include "parse.h"


#ifndef SCAN_ERR
#define SCAN_ERR
#define DOMDEF_EXPECTED            0
#define DOMAIN_EXPECTED            1
#define DOMNAME_EXPECTED           2
#define LBRACKET_EXPECTED          3
#define RBRACKET_EXPECTED          4
#define DOMDEFS_EXPECTED           5
#define REQUIREM_EXPECTED          6
#define TYPEDLIST_EXPECTED         7
#define LITERAL_EXPECTED           8
#define PRECONDDEF_UNCORRECT       9
#define TYPEDEF_EXPECTED          10
#define CONSTLIST_EXPECTED        11
#define PREDDEF_EXPECTED          12 
#define NAME_EXPECTED             13
#define VARIABLE_EXPECTED         14
#define ACTIONFUNCTOR_EXPECTED    15
#define ATOM_FORMULA_EXPECTED     16
#define EFFECT_DEF_EXPECTED       17
#define NEG_FORMULA_EXPECTED      18
#define NOT_SUPPORTED             19
#define ACTION                    20
#endif


#define NAME_STR "name\0"
#define VARIABLE_STR "variable\0"
#define STANDARD_TYPE "OBJECT\0"
 

static char *serrmsg[] = {
  "domain definition expected",
  "'domain' expected",
  "domain name expected",
  "'(' expected",
  "')' expected",
  "additional domain definitions expected",
  "requirements (e.g. ':STRIPS') expected",
  "typed list of <%s> expected",
  "literal expected",
  "uncorrect precondition definition",
  "type definition expected",
  "list of constants expected",
  "predicate definition expected",
  "<name> expected",
  "<variable> expected",
  "action functor expected",
  "atomic formula expected",
  "effect definition expected",
  "negated atomic formula expected",
  "requirement %s not supported by this FF version",  
  "action definition is not correct",
  NULL
};


void opserr( int errno, char *par );


static int sact_err;
static char *sact_err_par = NULL;
static PlOperator *scur_op = NULL;
static Bool sis_negated = FALSE;


int supported( char *str )

{

  int i;
  char * sup[] = { ":STRIPS", ":NEGATION", ":EQUALITY",":TYPING", 
		   ":CONDITIONAL-EFFECTS", ":NEGATIVE-PRECONDITIONS", ":DISJUNCTIVE-PRECONDITIONS", 
		   ":EXISTENTIAL-PRECONDITIONS", ":UNIVERSAL-PRECONDITIONS", 
		   ":QUANTIFIED-PRECONDITIONS", ":ADL", ":FLUENTS", ":ACTION-COSTS",
		   NULL };     

  for (i=0; NULL != sup[i]; i++) {
    if ( SAME == strcmp(sup[i], str) ) {
      return TRUE;
    }
  }
  
  return FALSE;

}


#line 180 "scan-ops_pddl.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int ops_pddldebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DEFINE_TOK = 258,              /* DEFINE_TOK  */
    DOMAIN_TOK = 259,              /* DOMAIN_TOK  */
    REQUIREMENTS_TOK = 260,        /* REQUIREMENTS_TOK  */
    TYPES_TOK = 261,               /* TYPES_TOK  */
    NUMBER_TOK = 262,              /* NUMBER_TOK  */
    EITHER_TOK = 263,              /* EITHER_TOK  */
    CONSTANTS_TOK = 264,           /* CONSTANTS_TOK  */
    PREDICATES_TOK = 265,          /* PREDICATES_TOK  */
    FUNCTIONS_TOK = 266,           /* FUNCTIONS_TOK  */
    ACTION_TOK = 267,              /* ACTION_TOK  */
    VARS_TOK = 268,                /* VARS_TOK  */
    IMPLIES_TOK = 269,             /* IMPLIES_TOK  */
    PRECONDITION_TOK = 270,        /* PRECONDITION_TOK  */
    PARAMETERS_TOK = 271,          /* PARAMETERS_TOK  */
    EFFECT_TOK = 272,              /* EFFECT_TOK  */
    AND_TOK = 273,                 /* AND_TOK  */
    NOT_TOK = 274,                 /* NOT_TOK  */
    WHEN_TOK = 275,                /* WHEN_TOK  */
    FORALL_TOK = 276,              /* FORALL_TOK  */
    IMPLY_TOK = 277,               /* IMPLY_TOK  */
    OR_TOK = 278,                  /* OR_TOK  */
    EXISTS_TOK = 279,              /* EXISTS_TOK  */
    LE_TOK = 280,                  /* LE_TOK  */
    LEQ_TOK = 281,                 /* LEQ_TOK  */
    EQ_TOK = 282,                  /* EQ_TOK  */
    GEQ_TOK = 283,                 /* GEQ_TOK  */
    GE_TOK = 284,                  /* GE_TOK  */
    MINUS_TOK = 285,               /* MINUS_TOK  */
    AD_TOK = 286,                  /* AD_TOK  */
    MU_TOK = 287,                  /* MU_TOK  */
    DI_TOK = 288,                  /* DI_TOK  */
    ASSIGN_TOK = 289,              /* ASSIGN_TOK  */
    SCALE_UP_TOK = 290,            /* SCALE_UP_TOK  */
    SCALE_DOWN_TOK = 291,          /* SCALE_DOWN_TOK  */
    INCREASE_TOK = 292,            /* INCREASE_TOK  */
    DECREASE_TOK = 293,            /* DECREASE_TOK  */
    NAME = 294,                    /* NAME  */
    VARIABLE = 295,                /* VARIABLE  */
    NUM = 296,                     /* NUM  */
    OPEN_PAREN = 297,              /* OPEN_PAREN  */
    CLOSE_PAREN = 298              /* CLOSE_PAREN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 130 "scan-ops_pddl.y"


  char string[MAX_LENGTH];
  char *pstring;
  ParseExpNode *pParseExpNode;
  PlNode *pPlNode;
  FactList *pFactList;
  TokenList *pTokenList;
  TypedList *pTypedList;


#line 282 "scan-ops_pddl.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE ops_pddllval;

int ops_pddlparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEFINE_TOK = 3,                 /* DEFINE_TOK  */
  YYSYMBOL_DOMAIN_TOK = 4,                 /* DOMAIN_TOK  */
  YYSYMBOL_REQUIREMENTS_TOK = 5,           /* REQUIREMENTS_TOK  */
  YYSYMBOL_TYPES_TOK = 6,                  /* TYPES_TOK  */
  YYSYMBOL_NUMBER_TOK = 7,                 /* NUMBER_TOK  */
  YYSYMBOL_EITHER_TOK = 8,                 /* EITHER_TOK  */
  YYSYMBOL_CONSTANTS_TOK = 9,              /* CONSTANTS_TOK  */
  YYSYMBOL_PREDICATES_TOK = 10,            /* PREDICATES_TOK  */
  YYSYMBOL_FUNCTIONS_TOK = 11,             /* FUNCTIONS_TOK  */
  YYSYMBOL_ACTION_TOK = 12,                /* ACTION_TOK  */
  YYSYMBOL_VARS_TOK = 13,                  /* VARS_TOK  */
  YYSYMBOL_IMPLIES_TOK = 14,               /* IMPLIES_TOK  */
  YYSYMBOL_PRECONDITION_TOK = 15,          /* PRECONDITION_TOK  */
  YYSYMBOL_PARAMETERS_TOK = 16,            /* PARAMETERS_TOK  */
  YYSYMBOL_EFFECT_TOK = 17,                /* EFFECT_TOK  */
  YYSYMBOL_AND_TOK = 18,                   /* AND_TOK  */
  YYSYMBOL_NOT_TOK = 19,                   /* NOT_TOK  */
  YYSYMBOL_WHEN_TOK = 20,                  /* WHEN_TOK  */
  YYSYMBOL_FORALL_TOK = 21,                /* FORALL_TOK  */
  YYSYMBOL_IMPLY_TOK = 22,                 /* IMPLY_TOK  */
  YYSYMBOL_OR_TOK = 23,                    /* OR_TOK  */
  YYSYMBOL_EXISTS_TOK = 24,                /* EXISTS_TOK  */
  YYSYMBOL_LE_TOK = 25,                    /* LE_TOK  */
  YYSYMBOL_LEQ_TOK = 26,                   /* LEQ_TOK  */
  YYSYMBOL_EQ_TOK = 27,                    /* EQ_TOK  */
  YYSYMBOL_GEQ_TOK = 28,                   /* GEQ_TOK  */
  YYSYMBOL_GE_TOK = 29,                    /* GE_TOK  */
  YYSYMBOL_MINUS_TOK = 30,                 /* MINUS_TOK  */
  YYSYMBOL_AD_TOK = 31,                    /* AD_TOK  */
  YYSYMBOL_MU_TOK = 32,                    /* MU_TOK  */
  YYSYMBOL_DI_TOK = 33,                    /* DI_TOK  */
  YYSYMBOL_ASSIGN_TOK = 34,                /* ASSIGN_TOK  */
  YYSYMBOL_SCALE_UP_TOK = 35,              /* SCALE_UP_TOK  */
  YYSYMBOL_SCALE_DOWN_TOK = 36,            /* SCALE_DOWN_TOK  */
  YYSYMBOL_INCREASE_TOK = 37,              /* INCREASE_TOK  */
  YYSYMBOL_DECREASE_TOK = 38,              /* DECREASE_TOK  */
  YYSYMBOL_NAME = 39,                      /* NAME  */
  YYSYMBOL_VARIABLE = 40,                  /* VARIABLE  */
  YYSYMBOL_NUM = 41,                       /* NUM  */
  YYSYMBOL_OPEN_PAREN = 42,                /* OPEN_PAREN  */
  YYSYMBOL_CLOSE_PAREN = 43,               /* CLOSE_PAREN  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_file = 45,                      /* file  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_domain_definition = 47,         /* domain_definition  */
  YYSYMBOL_48_2 = 48,                      /* $@2  */
  YYSYMBOL_domain_name = 49,               /* domain_name  */
  YYSYMBOL_optional_domain_defs = 50,      /* optional_domain_defs  */
  YYSYMBOL_predicates_def = 51,            /* predicates_def  */
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_predicates_list = 53,           /* predicates_list  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_functions_def = 55,             /* functions_def  */
  YYSYMBOL_56_5 = 56,                      /* $@5  */
  YYSYMBOL_functions_list = 57,            /* functions_list  */
  YYSYMBOL_58_6 = 58,                      /* $@6  */
  YYSYMBOL_59_7 = 59,                      /* $@7  */
  YYSYMBOL_require_def = 60,               /* require_def  */
  YYSYMBOL_61_8 = 61,                      /* $@8  */
  YYSYMBOL_62_9 = 62,                      /* $@9  */
  YYSYMBOL_require_key_star = 63,          /* require_key_star  */
  YYSYMBOL_64_10 = 64,                     /* $@10  */
  YYSYMBOL_types_def = 65,                 /* types_def  */
  YYSYMBOL_66_11 = 66,                     /* $@11  */
  YYSYMBOL_constants_def = 67,             /* constants_def  */
  YYSYMBOL_68_12 = 68,                     /* $@12  */
  YYSYMBOL_action_def = 69,                /* action_def  */
  YYSYMBOL_70_13 = 70,                     /* $@13  */
  YYSYMBOL_71_14 = 71,                     /* $@14  */
  YYSYMBOL_param_def = 72,                 /* param_def  */
  YYSYMBOL_action_def_body = 73,           /* action_def_body  */
  YYSYMBOL_74_15 = 74,                     /* $@15  */
  YYSYMBOL_75_16 = 75,                     /* $@16  */
  YYSYMBOL_adl_goal_description = 76,      /* adl_goal_description  */
  YYSYMBOL_adl_goal_description_star = 77, /* adl_goal_description_star  */
  YYSYMBOL_adl_effect = 78,                /* adl_effect  */
  YYSYMBOL_adl_effect_star = 79,           /* adl_effect_star  */
  YYSYMBOL_f_head = 80,                    /* f_head  */
  YYSYMBOL_f_exp = 81,                     /* f_exp  */
  YYSYMBOL_literal_term = 82,              /* literal_term  */
  YYSYMBOL_atomic_formula_term = 83,       /* atomic_formula_term  */
  YYSYMBOL_term_star = 84,                 /* term_star  */
  YYSYMBOL_term = 85,                      /* term  */
  YYSYMBOL_name_plus = 86,                 /* name_plus  */
  YYSYMBOL_predicate = 87,                 /* predicate  */
  YYSYMBOL_typed_list_name = 88,           /* typed_list_name  */
  YYSYMBOL_typed_list_variable = 89        /* typed_list_variable  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  240

#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   204,   204,   204,   215,   214,   228,   238,   240,   242,
     244,   246,   248,   250,   257,   256,   266,   269,   268,   298,
     297,   307,   310,   309,   335,   334,   364,   368,   363,   379,
     383,   382,   396,   395,   409,   408,   424,   428,   423,   442,
     446,   460,   463,   482,   481,   488,   487,   502,   510,   518,
     526,   534,   542,   555,   561,   567,   573,   583,   598,   618,
     622,   635,   643,   651,   659,   667,   675,   688,   694,   709,
     728,   732,   744,   757,   765,   770,   776,   783,   790,   797,
     808,   814,   823,   830,   843,   845,   856,   862,   872,   879,
     891,   902,   904,   914,   925,   945,   947,   956,   967
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DEFINE_TOK",
  "DOMAIN_TOK", "REQUIREMENTS_TOK", "TYPES_TOK", "NUMBER_TOK",
  "EITHER_TOK", "CONSTANTS_TOK", "PREDICATES_TOK", "FUNCTIONS_TOK",
  "ACTION_TOK", "VARS_TOK", "IMPLIES_TOK", "PRECONDITION_TOK",
  "PARAMETERS_TOK", "EFFECT_TOK", "AND_TOK", "NOT_TOK", "WHEN_TOK",
  "FORALL_TOK", "IMPLY_TOK", "OR_TOK", "EXISTS_TOK", "LE_TOK", "LEQ_TOK",
  "EQ_TOK", "GEQ_TOK", "GE_TOK", "MINUS_TOK", "AD_TOK", "MU_TOK", "DI_TOK",
  "ASSIGN_TOK", "SCALE_UP_TOK", "SCALE_DOWN_TOK", "INCREASE_TOK",
  "DECREASE_TOK", "NAME", "VARIABLE", "NUM", "OPEN_PAREN", "CLOSE_PAREN",
  "$accept", "file", "$@1", "domain_definition", "$@2", "domain_name",
  "optional_domain_defs", "predicates_def", "$@3", "predicates_list",
  "$@4", "functions_def", "$@5", "functions_list", "$@6", "$@7",
  "require_def", "$@8", "$@9", "require_key_star", "$@10", "types_def",
  "$@11", "constants_def", "$@12", "action_def", "$@13", "$@14",
  "param_def", "action_def_body", "$@15", "$@16", "adl_goal_description",
  "adl_goal_description_star", "adl_effect", "adl_effect_star", "f_head",
  "f_exp", "literal_term", "atomic_formula_term", "term_star", "term",
  "name_plus", "predicate", "typed_list_name", "typed_list_variable", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
#endif

#define YYPACT_NINF (-113)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -113,     5,   -26,  -113,    11,  -113,   -12,    30,  -113,     2,
      37,     8,    80,  -113,  -113,    37,    37,    37,    37,    37,
      37,  -113,  -113,  -113,  -113,     3,    12,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,    21,    34,    34,    77,  -113,    78,
    -113,    79,  -113,    -4,    81,    82,    83,    84,    83,    85,
    -113,    87,    90,   105,  -113,  -113,  -113,    -2,    91,  -113,
     106,  -113,   134,  -113,   108,    90,   109,    34,    90,   116,
    -113,  -113,    92,   115,    44,    87,  -113,  -113,    34,  -113,
     113,    83,     3,   151,    12,    83,   117,   118,   125,   126,
    -113,  -113,    83,  -113,  -113,  -113,  -113,   128,    83,   114,
    -113,  -113,  -113,   127,  -113,  -113,  -113,  -113,    12,  -113,
     129,   118,   118,   131,   118,   118,   132,    46,    46,    54,
      46,    46,  -113,    59,    44,   125,   133,   118,   135,    59,
     136,   136,   136,   136,   136,    44,  -113,    44,   118,   137,
     138,   139,    83,   118,   140,    83,  -113,    32,  -113,    46,
      46,  -113,  -113,    46,   141,    59,    46,    46,   142,  -113,
     125,   143,   -14,   139,   125,    83,   148,    46,    46,    46,
      46,    46,  -113,  -113,  -113,  -113,  -113,  -113,   145,   146,
    -113,   147,    46,    46,    46,    46,    59,   149,   150,   152,
    -113,  -113,   153,   154,  -113,  -113,  -113,   155,   156,   157,
     158,   159,   160,   161,   118,  -113,   118,   -20,    46,    46,
      46,   162,  -113,  -113,  -113,  -113,  -113,  -113,   125,  -113,
    -113,  -113,  -113,  -113,   163,   164,  -113,   165,   166,   167,
     168,  -113,   169,  -113,  -113,  -113,  -113,  -113,  -113,  -113
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     0,     0,     4,     0,
       0,     0,     0,     7,     5,     0,     0,     0,     0,     0,
       0,     6,    26,    32,    34,    16,    21,    36,    11,    12,
       8,    10,     9,    13,     0,    91,    91,     0,    14,     0,
      19,     0,    27,    91,     0,     0,    95,     0,    95,     0,
      37,    29,     0,     0,    94,    33,    35,    95,     0,    15,
       0,    20,    39,    30,     0,    88,     0,    91,     0,     0,
      98,    17,    22,     0,    41,    29,    28,    89,    91,    93,
       0,    95,    16,     0,    21,    95,     0,     0,     0,     0,
      31,    92,    95,    97,    18,    24,    23,     0,    95,     0,
      43,    52,    81,     0,    45,    66,    38,    96,    21,    40,
       0,    59,     0,     0,     0,    59,     0,     0,     0,    84,
       0,     0,    90,    84,    41,    70,     0,     0,     0,    84,
       0,     0,     0,     0,     0,    41,    25,    41,    59,     0,
       0,     0,    95,     0,     0,    95,    73,     0,    74,     0,
       0,    86,    87,     0,     0,    84,     0,     0,     0,    44,
      70,     0,     0,     0,     0,    95,     0,     0,     0,     0,
       0,     0,    46,    42,    60,    53,    55,    80,     0,     0,
      54,     0,     0,     0,     0,     0,    84,     0,     0,     0,
      83,    85,     0,     0,    82,    71,    67,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,    47,    48,    49,    50,    51,    69,     0,    61,
      62,    63,    64,    65,     0,     0,    75,     0,     0,     0,
       0,    72,     0,    58,    57,    77,    76,    78,    79,    68
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int8 yypgoto[] =
{
    -113,  -113,  -113,  -113,  -113,  -113,    95,  -113,  -113,    86,
    -113,  -113,  -113,   -77,  -113,  -113,  -113,  -113,  -113,   101,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,   -91,
    -113,  -113,   -85,  -106,   -87,    19,   -29,  -101,   -88,  -102,
    -112,  -113,    10,  -113,   -28,   -45
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    10,     8,    14,    15,    47,    38,
      82,    16,    49,    40,    84,   108,    17,    34,    51,    64,
      75,    18,    35,    19,    36,    20,    41,    62,    74,    89,
     124,   135,   138,   139,   160,   161,   148,   149,   101,   102,
     154,   155,    66,   123,    44,    58
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     105,   104,   100,    60,    52,     3,    68,    96,    45,   144,
     141,   158,    70,   129,     6,    54,     4,   150,   153,   156,
     157,   146,   147,   226,   163,   122,    53,   140,    69,   143,
       7,   136,   174,   159,     9,    43,    93,   105,    57,    79,
      97,    11,   164,   191,   172,    37,   173,   107,   187,   188,
      91,    21,   189,   110,    39,   192,   193,    86,   179,    87,
      42,    88,   182,   183,   184,   185,   199,   200,   201,   202,
     203,   186,   105,    43,   211,    77,   105,   197,    80,    12,
      13,   207,   208,   209,   210,    22,    23,   146,   147,    24,
      25,    26,    27,   151,   152,   146,   147,   178,   151,   152,
     181,   167,   168,   169,   170,   171,   227,   228,   229,   230,
      28,    29,    30,    31,    32,    33,    46,    48,    50,   224,
     198,   225,    83,    57,    55,    56,    63,    59,    61,    65,
     105,   232,   111,   112,    71,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    67,   125,   126,   127,   128,    72,
      73,    76,    78,   122,   129,    81,    92,    85,    95,    98,
      99,   130,   131,   132,   133,   134,   122,   103,    94,   106,
       0,   109,   137,   142,   145,   162,    90,   165,   166,   195,
     175,   176,   177,   180,   190,   194,   196,   186,   204,   205,
     206,     0,   212,   213,     0,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   231,   233,   234,   235,   236,
     237,   238,   239
};

static const yytype_int16 yycheck[] =
{
      88,    88,    87,    48,     8,     0,     8,    84,    36,   115,
     112,   123,    57,    27,     3,    43,    42,   118,   119,   120,
     121,    41,    42,    43,   126,    39,    30,   112,    30,   114,
      42,   108,   138,   124,     4,    39,    81,   125,    40,    67,
      85,    39,   127,   155,   135,    42,   137,    92,   149,   150,
      78,    43,   153,    98,    42,   156,   157,    13,   143,    15,
      39,    17,    30,    31,    32,    33,   167,   168,   169,   170,
     171,    39,   160,    39,   186,    65,   164,   164,    68,    42,
      43,   182,   183,   184,   185,     5,     6,    41,    42,     9,
      10,    11,    12,    39,    40,    41,    42,   142,    39,    40,
     145,   130,   131,   132,   133,   134,   207,   208,   209,   210,
      15,    16,    17,    18,    19,    20,    39,    39,    39,   204,
     165,   206,    30,    40,    43,    43,    39,    43,    43,    39,
     218,   218,    18,    19,    43,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    39,    18,    19,    20,    21,    43,
      16,    43,    43,    39,    27,    39,    43,    42,     7,    42,
      42,    34,    35,    36,    37,    38,    39,    42,    82,    43,
      -1,    43,    43,    42,    42,    42,    75,    42,    42,   160,
      43,    43,    43,    43,    43,    43,    43,    39,    43,    43,
      43,    -1,    43,    43,    -1,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    46,     0,    42,    47,     3,    42,    49,     4,
      48,    39,    42,    43,    50,    51,    55,    60,    65,    67,
      69,    43,     5,     6,     9,    10,    11,    12,    50,    50,
      50,    50,    50,    50,    61,    66,    68,    42,    53,    42,
      57,    70,    39,    39,    88,    88,    39,    52,    39,    56,
      39,    62,     8,    30,    88,    43,    43,    40,    89,    43,
      89,    43,    71,    39,    63,    39,    86,    39,     8,    30,
      89,    43,    43,    16,    72,    64,    43,    86,    43,    88,
      86,    39,    54,    30,    58,    42,    13,    15,    17,    73,
      63,    88,    43,    89,    53,     7,    57,    89,    42,    42,
      76,    82,    83,    42,    78,    82,    43,    89,    59,    43,
      89,    18,    19,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    39,    87,    74,    18,    19,    20,    21,    27,
      34,    35,    36,    37,    38,    75,    57,    43,    76,    77,
      76,    83,    42,    76,    77,    42,    41,    42,    80,    81,
      81,    39,    40,    81,    84,    85,    81,    81,    84,    73,
      78,    79,    42,    83,    76,    42,    42,    80,    80,    80,
      80,    80,    73,    73,    77,    43,    43,    43,    89,    76,
      43,    89,    30,    31,    32,    33,    39,    81,    81,    81,
      43,    84,    81,    81,    43,    79,    43,    78,    89,    81,
      81,    81,    81,    81,    43,    43,    43,    81,    81,    81,
      81,    84,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    76,    76,    43,    81,    81,    81,
      81,    43,    78,    43,    43,    43,    43,    43,    43,    43
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    46,    45,    48,    47,    49,    50,    50,    50,
      50,    50,    50,    50,    52,    51,    53,    54,    53,    56,
      55,    57,    58,    57,    59,    57,    61,    62,    60,    63,
      64,    63,    66,    65,    68,    67,    70,    71,    69,    72,
      72,    73,    73,    74,    73,    75,    73,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    80,    81,    81,    81,    81,    81,    81,    81,
      82,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      87,    88,    88,    88,    88,    89,    89,    89,    89
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     5,     4,     1,     2,     2,
       2,     2,     2,     2,     0,     5,     0,     0,     6,     0,
       5,     0,     0,     6,     0,     8,     0,     0,     7,     0,
       0,     3,     0,     5,     0,     5,     0,     0,     8,     0,
       4,     0,     5,     0,     4,     0,     4,     5,     5,     5,
       5,     5,     1,     4,     4,     4,     5,     7,     7,     0,
       2,     5,     5,     5,     5,     5,     1,     4,     7,     5,
       0,     2,     4,     1,     1,     4,     5,     5,     5,     5,
       4,     1,     4,     4,     0,     2,     1,     1,     1,     2,
       1,     0,     5,     4,     2,     0,     5,     4,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 204 "scan-ops_pddl.y"
{ 
  //opserr( DOMDEF_EXPECTED, NULL ); 
}
#line 1513 "scan-ops_pddl.tab.c"
    break;

  case 4:
#line 215 "scan-ops_pddl.y"
{ 
}
#line 1520 "scan-ops_pddl.tab.c"
    break;

  case 5:
#line 218 "scan-ops_pddl.y"
{
  if ( gcmd_line.display_info >= 1 ) {
    printf("\ndomain '%s' defined\n", gdomain_name);
  }
}
#line 1530 "scan-ops_pddl.tab.c"
    break;

  case 6:
#line 229 "scan-ops_pddl.y"
{ 
  gdomain_name = new_Token( strlen((yyvsp[-1].string))+1 );
  strcpy( gdomain_name, (yyvsp[-1].string));
}
#line 1539 "scan-ops_pddl.tab.c"
    break;

  case 14:
#line 257 "scan-ops_pddl.y"
{
}
#line 1546 "scan-ops_pddl.tab.c"
    break;

  case 15:
#line 260 "scan-ops_pddl.y"
{ 
}
#line 1553 "scan-ops_pddl.tab.c"
    break;

  case 16:
#line 266 "scan-ops_pddl.y"
{}
#line 1559 "scan-ops_pddl.tab.c"
    break;

  case 17:
#line 269 "scan-ops_pddl.y"
{

  TypedListList *tll;

  if ( gparse_predicates ) {
    tll = gparse_predicates;
    while ( tll->next ) {
      tll = tll->next;
    }
    tll->next = new_TypedListList();
    tll = tll->next;
  } else {
    tll = new_TypedListList();
    gparse_predicates = tll;
  }

  tll->predicate = new_Token( strlen( (yyvsp[-2].string) ) + 1);
  strcpy( tll->predicate, (yyvsp[-2].string) );

  tll->args = (yyvsp[-1].pTypedList);

}
#line 1586 "scan-ops_pddl.tab.c"
    break;

  case 19:
#line 298 "scan-ops_pddl.y"
{
}
#line 1593 "scan-ops_pddl.tab.c"
    break;

  case 20:
#line 301 "scan-ops_pddl.y"
{ 
}
#line 1600 "scan-ops_pddl.tab.c"
    break;

  case 21:
#line 307 "scan-ops_pddl.y"
{}
#line 1606 "scan-ops_pddl.tab.c"
    break;

  case 22:
#line 310 "scan-ops_pddl.y"
{

  TypedListList *tll;

  if ( gparse_functions ) {
    tll = gparse_functions;
    while ( tll->next ) {
      tll = tll->next;
    }
    tll->next = new_TypedListList();
    tll = tll->next;
  } else {
    tll = new_TypedListList();
    gparse_functions = tll;
  }

  tll->predicate = new_Token( strlen( (yyvsp[-2].string) ) + 1);
  strcpy( tll->predicate, (yyvsp[-2].string) );

  tll->args = (yyvsp[-1].pTypedList);

}
#line 1633 "scan-ops_pddl.tab.c"
    break;

  case 24:
#line 335 "scan-ops_pddl.y"
{

  TypedListList *tll;

  if ( gparse_functions ) {
    tll = gparse_functions;
    while ( tll->next ) {
      tll = tll->next;
    }
    tll->next = new_TypedListList();
    tll = tll->next;
  } else {
    tll = new_TypedListList();
    gparse_functions = tll;
  }

  tll->predicate = new_Token( strlen( (yyvsp[-4].string) ) + 1);
  strcpy( tll->predicate, (yyvsp[-4].string) );

  tll->args = (yyvsp[-3].pTypedList);

}
#line 1660 "scan-ops_pddl.tab.c"
    break;

  case 26:
#line 364 "scan-ops_pddl.y"
{ 
  //opserr( REQUIREM_EXPECTED, NULL ); 
}
#line 1668 "scan-ops_pddl.tab.c"
    break;

  case 27:
#line 368 "scan-ops_pddl.y"
{ 
  if ( !supported( (yyvsp[0].string) ) ) {
    //opserr( NOT_SUPPORTED, $4 );
    yyerror();
  }
}
#line 1679 "scan-ops_pddl.tab.c"
    break;

  case 30:
#line 383 "scan-ops_pddl.y"
{ 
  if ( !supported( (yyvsp[0].string) ) ) {
    //opserr( NOT_SUPPORTED, $1 );
    yyerror();
  }
}
#line 1690 "scan-ops_pddl.tab.c"
    break;

  case 32:
#line 396 "scan-ops_pddl.y"
{ 
  //opserr( TYPEDEF_EXPECTED, NULL ); 
}
#line 1698 "scan-ops_pddl.tab.c"
    break;

  case 33:
#line 400 "scan-ops_pddl.y"
{
  gparse_types = (yyvsp[-1].pTypedList);
}
#line 1706 "scan-ops_pddl.tab.c"
    break;

  case 34:
#line 409 "scan-ops_pddl.y"
{ 
  //opserr( CONSTLIST_EXPECTED, NULL ); 
}
#line 1714 "scan-ops_pddl.tab.c"
    break;

  case 35:
#line 413 "scan-ops_pddl.y"
{
  gparse_constants = (yyvsp[-1].pTypedList);
}
#line 1722 "scan-ops_pddl.tab.c"
    break;

  case 36:
#line 424 "scan-ops_pddl.y"
{ 
  //opserr( ACTION, NULL ); 
}
#line 1730 "scan-ops_pddl.tab.c"
    break;

  case 37:
#line 428 "scan-ops_pddl.y"
{ 
  scur_op = new_PlOperator( (yyvsp[0].string) );
}
#line 1738 "scan-ops_pddl.tab.c"
    break;

  case 38:
#line 432 "scan-ops_pddl.y"
{
  scur_op->next = gloaded_ops;
  gloaded_ops = scur_op; 
}
#line 1747 "scan-ops_pddl.tab.c"
    break;

  case 39:
#line 442 "scan-ops_pddl.y"
{ 
  scur_op->params = NULL; 
}
#line 1755 "scan-ops_pddl.tab.c"
    break;

  case 40:
#line 447 "scan-ops_pddl.y"
{
  TypedList *tl;
  scur_op->parse_params = (yyvsp[-1].pTypedList);
  for (tl = scur_op->parse_params; tl; tl = tl->next) {
    /* to be able to distinguish params from :VARS 
     */
    scur_op->number_of_real_params++;
  }
}
#line 1769 "scan-ops_pddl.tab.c"
    break;

  case 42:
#line 464 "scan-ops_pddl.y"
{
  TypedList *tl = NULL;

  /* add vars as parameters 
   */
  if ( scur_op->parse_params ) {
    for( tl = scur_op->parse_params; tl->next; tl = tl->next ) {
      /* empty, get to the end of list 
       */
    }
    tl->next = (yyvsp[-2].pTypedList);
    tl = tl->next;
  } else {
    scur_op->parse_params = (yyvsp[-2].pTypedList);
  }
}
#line 1790 "scan-ops_pddl.tab.c"
    break;

  case 43:
#line 482 "scan-ops_pddl.y"
{ 
  scur_op->preconds = (yyvsp[0].pPlNode); 
}
#line 1798 "scan-ops_pddl.tab.c"
    break;

  case 45:
#line 488 "scan-ops_pddl.y"
{ 
  scur_op->effects = (yyvsp[0].pPlNode); 
}
#line 1806 "scan-ops_pddl.tab.c"
    break;

  case 47:
#line 503 "scan-ops_pddl.y"
{
  (yyval.pPlNode) = new_PlNode(COMP);
  (yyval.pPlNode)->comp = LE;
  (yyval.pPlNode)->lh = (yyvsp[-2].pParseExpNode);
  (yyval.pPlNode)->rh = (yyvsp[-1].pParseExpNode);
}
#line 1817 "scan-ops_pddl.tab.c"
    break;

  case 48:
#line 511 "scan-ops_pddl.y"
{
  (yyval.pPlNode) = new_PlNode(COMP);
  (yyval.pPlNode)->comp = LEQ;
  (yyval.pPlNode)->lh = (yyvsp[-2].pParseExpNode);
  (yyval.pPlNode)->rh = (yyvsp[-1].pParseExpNode);
}
#line 1828 "scan-ops_pddl.tab.c"
    break;

  case 49:
#line 519 "scan-ops_pddl.y"
{
  (yyval.pPlNode) = new_PlNode(COMP);
  (yyval.pPlNode)->comp = EQ;
  (yyval.pPlNode)->lh = (yyvsp[-2].pParseExpNode);
  (yyval.pPlNode)->rh = (yyvsp[-1].pParseExpNode);
}
#line 1839 "scan-ops_pddl.tab.c"
    break;

  case 50:
#line 527 "scan-ops_pddl.y"
{
  (yyval.pPlNode) = new_PlNode(COMP);
  (yyval.pPlNode)->comp = GEQ;
  (yyval.pPlNode)->lh = (yyvsp[-2].pParseExpNode);
  (yyval.pPlNode)->rh = (yyvsp[-1].pParseExpNode);
}
#line 1850 "scan-ops_pddl.tab.c"
    break;

  case 51:
#line 535 "scan-ops_pddl.y"
{
  (yyval.pPlNode) = new_PlNode(COMP);
  (yyval.pPlNode)->comp = GE;
  (yyval.pPlNode)->lh = (yyvsp[-2].pParseExpNode);
  (yyval.pPlNode)->rh = (yyvsp[-1].pParseExpNode);
}
#line 1861 "scan-ops_pddl.tab.c"
    break;

  case 52:
#line 543 "scan-ops_pddl.y"
{ 
  if ( sis_negated ) {
    (yyval.pPlNode) = new_PlNode(NOT);
    (yyval.pPlNode)->sons = new_PlNode(ATOM);
    (yyval.pPlNode)->sons->atom = (yyvsp[0].pTokenList);
    sis_negated = FALSE;
  } else {
    (yyval.pPlNode) = new_PlNode(ATOM);
    (yyval.pPlNode)->atom = (yyvsp[0].pTokenList);
  }
}
#line 1877 "scan-ops_pddl.tab.c"
    break;

  case 53:
#line 556 "scan-ops_pddl.y"
{ 
  (yyval.pPlNode) = new_PlNode(AND);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 1886 "scan-ops_pddl.tab.c"
    break;

  case 54:
#line 562 "scan-ops_pddl.y"
{ 
  (yyval.pPlNode) = new_PlNode(OR);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 1895 "scan-ops_pddl.tab.c"
    break;

  case 55:
#line 568 "scan-ops_pddl.y"
{ 
  (yyval.pPlNode) = new_PlNode(NOT);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 1904 "scan-ops_pddl.tab.c"
    break;

  case 56:
#line 574 "scan-ops_pddl.y"
{ 
  PlNode *np = new_PlNode(NOT);
  np->sons = (yyvsp[-2].pPlNode);
  np->next = (yyvsp[-1].pPlNode);

  (yyval.pPlNode) = new_PlNode(OR);
  (yyval.pPlNode)->sons = np;
}
#line 1917 "scan-ops_pddl.tab.c"
    break;

  case 57:
#line 586 "scan-ops_pddl.y"
{ 

  PlNode *pln;

  pln = new_PlNode(EX);
  pln->parse_vars = (yyvsp[-3].pTypedList);

  (yyval.pPlNode) = pln;
  pln->sons = (yyvsp[-1].pPlNode);

}
#line 1933 "scan-ops_pddl.tab.c"
    break;

  case 58:
#line 601 "scan-ops_pddl.y"
{ 

  PlNode *pln;

  pln = new_PlNode(ALL);
  pln->parse_vars = (yyvsp[-3].pTypedList);

  (yyval.pPlNode) = pln;
  pln->sons = (yyvsp[-1].pPlNode);

}
#line 1949 "scan-ops_pddl.tab.c"
    break;

  case 59:
#line 618 "scan-ops_pddl.y"
{
  (yyval.pPlNode) = NULL;
}
#line 1957 "scan-ops_pddl.tab.c"
    break;

  case 60:
#line 623 "scan-ops_pddl.y"
{
  (yyvsp[-1].pPlNode)->next = (yyvsp[0].pPlNode);
  (yyval.pPlNode) = (yyvsp[-1].pPlNode);
}
#line 1966 "scan-ops_pddl.tab.c"
    break;

  case 61:
#line 636 "scan-ops_pddl.y"
{
  (yyval.pPlNode) = new_PlNode( NEF );
  (yyval.pPlNode)->neft = ASSIGN;
  (yyval.pPlNode)->lh = (yyvsp[-2].pParseExpNode);
  (yyval.pPlNode)->rh = (yyvsp[-1].pParseExpNode);
}
#line 1977 "scan-ops_pddl.tab.c"
    break;

  case 62:
#line 644 "scan-ops_pddl.y"
{
  (yyval.pPlNode) = new_PlNode( NEF );
  (yyval.pPlNode)->neft = SCALE_UP;
  (yyval.pPlNode)->lh = (yyvsp[-2].pParseExpNode);
  (yyval.pPlNode)->rh = (yyvsp[-1].pParseExpNode);
}
#line 1988 "scan-ops_pddl.tab.c"
    break;

  case 63:
#line 652 "scan-ops_pddl.y"
{
  (yyval.pPlNode) = new_PlNode( NEF );
  (yyval.pPlNode)->neft = SCALE_DOWN;
  (yyval.pPlNode)->lh = (yyvsp[-2].pParseExpNode);
  (yyval.pPlNode)->rh = (yyvsp[-1].pParseExpNode);
}
#line 1999 "scan-ops_pddl.tab.c"
    break;

  case 64:
#line 660 "scan-ops_pddl.y"
{
  (yyval.pPlNode) = new_PlNode( NEF );
  (yyval.pPlNode)->neft = INCREASE;
  (yyval.pPlNode)->lh = (yyvsp[-2].pParseExpNode);
  (yyval.pPlNode)->rh = (yyvsp[-1].pParseExpNode);
}
#line 2010 "scan-ops_pddl.tab.c"
    break;

  case 65:
#line 668 "scan-ops_pddl.y"
{
  (yyval.pPlNode) = new_PlNode( NEF );
  (yyval.pPlNode)->neft = DECREASE;
  (yyval.pPlNode)->lh = (yyvsp[-2].pParseExpNode);
  (yyval.pPlNode)->rh = (yyvsp[-1].pParseExpNode);
}
#line 2021 "scan-ops_pddl.tab.c"
    break;

  case 66:
#line 676 "scan-ops_pddl.y"
{ 
  if ( sis_negated ) {
    (yyval.pPlNode) = new_PlNode(NOT);
    (yyval.pPlNode)->sons = new_PlNode(ATOM);
    (yyval.pPlNode)->sons->atom = (yyvsp[0].pTokenList);
    sis_negated = FALSE;
  } else {
    (yyval.pPlNode) = new_PlNode(ATOM);
    (yyval.pPlNode)->atom = (yyvsp[0].pTokenList);
  }
}
#line 2037 "scan-ops_pddl.tab.c"
    break;

  case 67:
#line 689 "scan-ops_pddl.y"
{ 
  (yyval.pPlNode) = new_PlNode(AND);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 2046 "scan-ops_pddl.tab.c"
    break;

  case 68:
#line 697 "scan-ops_pddl.y"
{ 

  PlNode *pln;

  pln = new_PlNode(ALL);
  pln->parse_vars = (yyvsp[-3].pTypedList);

  (yyval.pPlNode) = pln;
  pln->sons = (yyvsp[-1].pPlNode);

}
#line 2062 "scan-ops_pddl.tab.c"
    break;

  case 69:
#line 710 "scan-ops_pddl.y"
{
  /* This will be conditional effects in FF representation, but here
   * a formula like (WHEN p q) will be saved as:
   *  [WHEN]
   *  [sons]
   *   /  \
   * [p]  [q]
   * That means, the first son is p, and the second one is q. 
   */
  (yyval.pPlNode) = new_PlNode(WHEN);
  (yyvsp[-2].pPlNode)->next = (yyvsp[-1].pPlNode);
  (yyval.pPlNode)->sons = (yyvsp[-2].pPlNode);
}
#line 2080 "scan-ops_pddl.tab.c"
    break;

  case 70:
#line 728 "scan-ops_pddl.y"
{ 
  (yyval.pPlNode) = NULL; 
}
#line 2088 "scan-ops_pddl.tab.c"
    break;

  case 71:
#line 733 "scan-ops_pddl.y"
{
  (yyvsp[-1].pPlNode)->next = (yyvsp[0].pPlNode);
  (yyval.pPlNode) = (yyvsp[-1].pPlNode);
}
#line 2097 "scan-ops_pddl.tab.c"
    break;

  case 72:
#line 745 "scan-ops_pddl.y"
{
  (yyval.pParseExpNode) = new_ParseExpNode( FHEAD );
  (yyval.pParseExpNode)->atom = new_TokenList();
  (yyval.pParseExpNode)->atom->item = new_Token( strlen((yyvsp[-2].string))+1 );
  strcpy( (yyval.pParseExpNode)->atom->item, (yyvsp[-2].string) );
  (yyval.pParseExpNode)->atom->next = (yyvsp[-1].pTokenList);
}
#line 2109 "scan-ops_pddl.tab.c"
    break;

  case 73:
#line 758 "scan-ops_pddl.y"
{ 
  (yyval.pParseExpNode) = new_ParseExpNode( NUMBER );
  (yyval.pParseExpNode)->atom = new_TokenList();
  (yyval.pParseExpNode)->atom->item = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy( (yyval.pParseExpNode)->atom->item, (yyvsp[0].string) );
}
#line 2120 "scan-ops_pddl.tab.c"
    break;

  case 74:
#line 766 "scan-ops_pddl.y"
{
  (yyval.pParseExpNode) = (yyvsp[0].pParseExpNode);
}
#line 2128 "scan-ops_pddl.tab.c"
    break;

  case 75:
#line 771 "scan-ops_pddl.y"
{
  (yyval.pParseExpNode) = new_ParseExpNode( MINUS );
  (yyval.pParseExpNode)->leftson = (yyvsp[-1].pParseExpNode);
}
#line 2137 "scan-ops_pddl.tab.c"
    break;

  case 76:
#line 777 "scan-ops_pddl.y"
{
  (yyval.pParseExpNode) = new_ParseExpNode( AD );
  (yyval.pParseExpNode)->leftson = (yyvsp[-2].pParseExpNode);
  (yyval.pParseExpNode)->rightson = (yyvsp[-1].pParseExpNode);
}
#line 2147 "scan-ops_pddl.tab.c"
    break;

  case 77:
#line 784 "scan-ops_pddl.y"
{
  (yyval.pParseExpNode) = new_ParseExpNode( SU );
  (yyval.pParseExpNode)->leftson = (yyvsp[-2].pParseExpNode);
  (yyval.pParseExpNode)->rightson = (yyvsp[-1].pParseExpNode);
}
#line 2157 "scan-ops_pddl.tab.c"
    break;

  case 78:
#line 791 "scan-ops_pddl.y"
{
  (yyval.pParseExpNode) = new_ParseExpNode( MU );
  (yyval.pParseExpNode)->leftson = (yyvsp[-2].pParseExpNode);
  (yyval.pParseExpNode)->rightson = (yyvsp[-1].pParseExpNode);
}
#line 2167 "scan-ops_pddl.tab.c"
    break;

  case 79:
#line 798 "scan-ops_pddl.y"
{
  (yyval.pParseExpNode) = new_ParseExpNode( DI );
  (yyval.pParseExpNode)->leftson = (yyvsp[-2].pParseExpNode);
  (yyval.pParseExpNode)->rightson = (yyvsp[-1].pParseExpNode);
}
#line 2177 "scan-ops_pddl.tab.c"
    break;

  case 80:
#line 809 "scan-ops_pddl.y"
{ 
  (yyval.pTokenList) = (yyvsp[-1].pTokenList);
  sis_negated = TRUE;
}
#line 2186 "scan-ops_pddl.tab.c"
    break;

  case 81:
#line 815 "scan-ops_pddl.y"
{
  (yyval.pTokenList) = (yyvsp[0].pTokenList);
}
#line 2194 "scan-ops_pddl.tab.c"
    break;

  case 82:
#line 824 "scan-ops_pddl.y"
{ 
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = (yyvsp[-2].pstring);
  (yyval.pTokenList)->next = (yyvsp[-1].pTokenList);
}
#line 2204 "scan-ops_pddl.tab.c"
    break;

  case 83:
#line 831 "scan-ops_pddl.y"
{
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = new_Token( 5 );
  (yyval.pTokenList)->item = "=";
  (yyval.pTokenList)->next = (yyvsp[-1].pTokenList);
}
#line 2215 "scan-ops_pddl.tab.c"
    break;

  case 84:
#line 843 "scan-ops_pddl.y"
{ (yyval.pTokenList) = NULL; }
#line 2221 "scan-ops_pddl.tab.c"
    break;

  case 85:
#line 846 "scan-ops_pddl.y"
{
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = (yyvsp[-1].pstring);
  (yyval.pTokenList)->next = (yyvsp[0].pTokenList);
}
#line 2231 "scan-ops_pddl.tab.c"
    break;

  case 86:
#line 857 "scan-ops_pddl.y"
{ 
  (yyval.pstring) = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy( (yyval.pstring), (yyvsp[0].string) );
}
#line 2240 "scan-ops_pddl.tab.c"
    break;

  case 87:
#line 863 "scan-ops_pddl.y"
{ 
  (yyval.pstring) = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy( (yyval.pstring), (yyvsp[0].string) );
}
#line 2249 "scan-ops_pddl.tab.c"
    break;

  case 88:
#line 873 "scan-ops_pddl.y"
{
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy( (yyval.pTokenList)->item, (yyvsp[0].string) );
}
#line 2259 "scan-ops_pddl.tab.c"
    break;

  case 89:
#line 880 "scan-ops_pddl.y"
{
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = new_Token( strlen((yyvsp[-1].string))+1 );
  strcpy( (yyval.pTokenList)->item, (yyvsp[-1].string) );
  (yyval.pTokenList)->next = (yyvsp[0].pTokenList);
}
#line 2270 "scan-ops_pddl.tab.c"
    break;

  case 90:
#line 892 "scan-ops_pddl.y"
{ 
  (yyval.pstring) = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy( (yyval.pstring), (yyvsp[0].string) );
}
#line 2279 "scan-ops_pddl.tab.c"
    break;

  case 91:
#line 902 "scan-ops_pddl.y"
{ (yyval.pTypedList) = NULL; }
#line 2285 "scan-ops_pddl.tab.c"
    break;

  case 92:
#line 905 "scan-ops_pddl.y"
{ 

  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-4].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-4].string) );
  (yyval.pTypedList)->type = (yyvsp[-2].pTokenList);
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2298 "scan-ops_pddl.tab.c"
    break;

  case 93:
#line 915 "scan-ops_pddl.y"
{
  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-3].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-3].string) );
  (yyval.pTypedList)->type = new_TokenList();
  (yyval.pTypedList)->type->item = new_Token( strlen((yyvsp[-1].string))+1 );
  strcpy( (yyval.pTypedList)->type->item, (yyvsp[-1].string) );
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2312 "scan-ops_pddl.tab.c"
    break;

  case 94:
#line 926 "scan-ops_pddl.y"
{
  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-1].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-1].string) );
  if ( (yyvsp[0].pTypedList) ) {/* another element (already typed) is following */
    (yyval.pTypedList)->type = copy_TokenList( (yyvsp[0].pTypedList)->type );
  } else {/* no further element - it must be an untyped list */
    (yyval.pTypedList)->type = new_TokenList();
    (yyval.pTypedList)->type->item = new_Token( strlen(STANDARD_TYPE)+1 );
    strcpy( (yyval.pTypedList)->type->item, STANDARD_TYPE );
  }
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2330 "scan-ops_pddl.tab.c"
    break;

  case 95:
#line 945 "scan-ops_pddl.y"
{ (yyval.pTypedList) = NULL; }
#line 2336 "scan-ops_pddl.tab.c"
    break;

  case 96:
#line 948 "scan-ops_pddl.y"
{ 
  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-4].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-4].string) );
  (yyval.pTypedList)->type = (yyvsp[-2].pTokenList);
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2348 "scan-ops_pddl.tab.c"
    break;

  case 97:
#line 957 "scan-ops_pddl.y"
{
  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-3].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-3].string) );
  (yyval.pTypedList)->type = new_TokenList();
  (yyval.pTypedList)->type->item = new_Token( strlen((yyvsp[-1].string))+1 );
  strcpy( (yyval.pTypedList)->type->item, (yyvsp[-1].string) );
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2362 "scan-ops_pddl.tab.c"
    break;

  case 98:
#line 968 "scan-ops_pddl.y"
{
  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-1].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-1].string) );
  if ( (yyvsp[0].pTypedList) ) {/* another element (already typed) is following */
    (yyval.pTypedList)->type = copy_TokenList( (yyvsp[0].pTypedList)->type );
  } else {/* no further element - it must be an untyped list */
    (yyval.pTypedList)->type = new_TokenList();
    (yyval.pTypedList)->type->item = new_Token( strlen(STANDARD_TYPE)+1 );
    strcpy( (yyval.pTypedList)->type->item, STANDARD_TYPE );
  }
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2380 "scan-ops_pddl.tab.c"
    break;


#line 2384 "scan-ops_pddl.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 985 "scan-ops_pddl.y"

#include "lex.ops_pddl.c"


/**********************************************************************
 * Functions
 **********************************************************************/

/* 
 * call	bison -pops -bscan-ops scan-ops.y
 */


int yyerror( char *msg )

{

  fflush(stdout);
  fprintf(stderr, "\n%s: syntax error in line %d, '%s':\n", 
	  gact_filename, lineno, yytext);

  if ( NULL != sact_err_par ) {
    fprintf(stderr, "%s %s\n", serrmsg[sact_err], sact_err_par);
  } else {
    fprintf(stderr, "%s\n", serrmsg[sact_err]);
  }

  exit( 1 );

}



void load_ops_file( char *filename )

{

  FILE * fp;/* pointer to input files */
  char tmp[MAX_LENGTH] = "";

  /* open operator file 
   */
  if( ( fp = fopen( filename, "r" ) ) == NULL ) {
    sprintf(tmp, "\nff: can't find operator file: %s\n\n", filename );
    perror(tmp);
    exit( 1 );
  }

  gact_filename = filename;
  lineno = 1; 
  yyin = fp;

  yyparse();

  fclose( fp );/* and close file again */

}
