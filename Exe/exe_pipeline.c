#include "../Include/MiniShell.h"
#include <fcntl.h>

/***************************************************************
    !!!!!!!!!!!!!!!!!!!!!!! LIS MOI CA !!!!!!!!!!!!!!!!!!!!!!!!!
    STDIN_FILENO est utilisé pour lire les données entrantes.
    STDOUT_FILENO est utilisé pour écrire les données de sortie.
    STDERR_FILENO est utilisé pour écrire les messages d'erreur.
*****************************************************************/

void wait_for_children(int last, pid_t pid[]) 
{
    int j = 0; 
    int status;
    
    while (j < last) 
    {
        waitpid(pid[j], &status, 0);
        j++;
    }
}

void create_pipe(int pipe_fd[2], int i, int last) 
{
    if (i < (last - 1))
    {
        if (pipe(pipe_fd) == -1) 
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }
}

void close_pipes_in_parent(int i, t_data *data, int *input_fd) 
{
    if (i != data->first)
        close(*input_fd);
    if (i < data->last) 
    {
        close(data->pipe_fd[1]);
        *input_fd = data->pipe_fd[0];
    }
}


pid_t   fork_process_pipe(int i, t_data *data, t_Token *curr, t_Token *lst_tok) 
{
    pid_t pid = fork();

    if (pid == 0)
    { 
        if(data->pipe_bf_redi == 1)
        {
            dup2(data->pipe_fd[0], STDIN_FILENO);
            close(data->pipe_fd[1]);
            close(data->pipe_fd[0]);
        }
        else if ((i != data->first)) 
        {
                dup2(data->input_fd, STDIN_FILENO);
                close(data->input_fd);
        }
        if(i < data->last) 
        {
                dup2(data->pipe_fd[1], STDOUT_FILENO);
                close(data->pipe_fd[0]);
                close(data->pipe_fd[1]);
        }
        data->path_exe = ft_get_reading(data, curr);
        if(!data->path_exe)
            ft_no_patch(data, lst_tok);
        if(check_builtins(lst_tok, data->envp) == 1)
        {   
            if (execve(data->path_exe, data->cmd, data->envp) == -1) 
                free_for_fail_exe_exit(data, lst_tok, curr); 
        }
        free(curr->Token_str);
        free_token(lst_tok);
    }
    return (pid);
}
//ls > sssss | ddd a fix