#include "../Include/MiniShell.h"

typedef enum e_type_token
{
    E_WORD      = 10, 
    E_IN        = 11, // <
    E_OUT       = 12, // >
    E_APPEND    = 13, // >>
    E_HEREDOC   = 14, // <<
    E_PIPE      = 15, // |
    E_FILE      = 16,
    E_EMPTY     = 17,
    E_OEF_HERE  = 20,
    E_NOT_CMD   = 21,
    E_NEG       = 22,
} t_type_token;

/**
typedef enum e_word_type
{
    E_CMD,
    E_OPTIONS,
    E_ARG,
} t_type_token;
*/

/*
typedef struct s_env
{
	char        *var;    
    char        *content;
    //int          hiden;
    struct s_env *next;
}                   t_env;
*/

typedef struct s_env
{
	char	**env;
}                   t_env;

typedef struct s_here 
{
    char **delim;
    int exe;
} t_here;

typedef struct s_Token 
{
    char                *Token_str;
    char                **file;
    t_type_token        type;
    struct s_Token      *next;
}                   t_Token;

typedef struct s_data
{
    t_here      *here;    
    int         nb_cmd;
    int         nb_file_out;
    int         nb_file_in;
    char        *pronpt;
    char        **envp;
    char        **cmd;
    char        **cmd2;            
    char        *path_exe;
    int         pipe_fd[2];
    int         first;
    int         last;
    int         *output_fd;
    int         *in_fd;
    int         input_fd;
    int         pipe_bf_redi;
    int         redi_out_bf_pipe;
    int         nb_pipe;
    int         flag_here;
    int         index;
    int         in_single_quote;
    int         in_double_quote;
}                   t_data;

