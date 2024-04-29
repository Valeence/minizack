#ifndef MINI_SHELL
# define MINI_SHELL

# define pip    "|"
# define rdi_in "<"
# define rdi_out ">"
# define app_out ">>"
# define her_int "<<"
# define Single_Quotes '\''
# define Double_Quotes '\"'
# define Expand "$"

#include "./libft/libft.h"
#include "Struct.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <string.h>
#include <signal.h>
#include <string.h>

// debug
void print_list(t_Token *begin);


// ENVIRONEMENT

//-----TOKANISATION------ 

//Tokinistation.c
void    ft_lexer(t_data *data, t_Token **list_token);
//Tok_utils.c
int     extract_token(const char *readline, int start, char **token, t_data *data);
int     skip_begin_spaces_prompt(const char *readline, int start);
bool    ft_is_del(char c);
bool    ft_isspace(char c);

//List_tok.c
t_Token *Creat_noed_Token(char *token);
void    add_token(t_Token **begin, t_Token *new_token);
void    free_token(t_Token *begin); 
void    ft_supp_noed_empy(t_Token **list_tok);
void    free_token(t_Token *begin);
int     ft_size_list_token(t_Token *list_token);
void    free_lst(t_Token *lst);
void    insertNodesAtCurrent(t_Token* current, int size);

bool  shr_out_in_redi(t_Token *curr);
bool search_redi(t_Token *curr);



//analy_utils_1.c
void    ft_analy_type_pipe(t_data *data, t_Token **current);
void    ft_analy_type_redi_out(t_Token **current);
void    ft_analy_type_redi_append(t_Token **current);
void    ft_analy_type_redi_heredoc(t_Token **current);

//analy_utils_1.c
void    ft_analy_type_else(t_data *data, t_Token **current);
void    ft_analy_type_redi_in(t_data *data, t_Token **current);

//-------EXE-------
void    ft_lanch_exe(t_data *data, t_Token *list_token);
void    ft_simple_cmd(t_data *data, t_Token *list_token);
char    *ft_get_reading(t_data *data, t_Token *list_token);

void    ft_free_tabtab(char **split_result); 
int     ft_verify_pipe_separation(t_Token *list_token);
void    execute_pipeline_redirection(t_data *data, t_Token *list_token);

pid_t   fork_process_redi_out(t_data *data, t_Token *curr, t_Token *lst_tok);
pid_t   fork_process_redi_in(t_data *data, t_Token *curr, t_Token *lst_tok);
pid_t   fork_process_pipe(int i, t_data *data, t_Token *curr, t_Token *lst_tok);
void    create_pipe(int pipe_fd[2], int i, int last);
void    close_pipes_in_parent(int i, t_data *data, int *input_fd);
void    wait_for_children(int last, pid_t pid[]);
char	*build_executable_path(char *cmd, char *path);

void    ft_no_patch(t_data *data, t_Token  *lst_tok);     


char    **copy_array_arrays(char **src);
void    free_for_fail_exe_exit(t_data *data, t_Token *lst, t_Token *curr);

void    close_fd_in(t_data *data);
int     *creat_fd_in(t_data *data, t_Token *curr);

int     *creat_fd_out(t_data *data, t_Token *curr);
void    close_fd_out(t_data *data);

bool    verif_pipe(t_Token *curr);
void    lanch_her(t_Token *curr, t_data *data, t_Token *lst_tok);
char    *ft_get_reading_in(t_data *data, t_Token *curr);

void    execute_double_in_1(t_data *data, t_Token *list_token, t_Token **curr);
void    execute_double_in_2(t_data *data, t_Token *list_token, t_Token **curr);//pas necessaire
void    execute_in(t_data *data, t_Token *list_token, t_Token **curr, pid_t *pid);
void    execute_redi_out_and_append(t_data *data, t_Token *list_token, t_Token **curr, pid_t *pid);
void    execute_pipe(t_data *data, t_Token *list_token, t_Token **curr, pid_t *pid);




//PARSING
int     syntaxize_moi_ca(char *str);
int     check_builtins(t_Token *curr, char **envp);

//BUILTINS
int     ft_cd(t_Token *curr);
int		ft_pwd();
int     ft_echo(t_Token *curr , char **envp);
int     ft_env(char **envp);

//signal

void    signal_handle();

/*
void add_var(t_env **begin, t_env *new_var);
t_env *create_node_env(char *var, char *content);
void free_env(t_env *begin);
*/

#endif
