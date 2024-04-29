#include "../Include/MiniShell.h"

void close_fd_out(t_data *data)
{
    int i= 0;
    
    while(i < data->nb_file_out)
    {    
        close(data->output_fd[i]);
        i++;
    }
    free(data->output_fd);
}

int *creat_fd_out(t_data *data, t_Token *curr)
{
    int i;
    i = 0;
    t_Token *tmp = curr;

    while(i < data->nb_file_out)
    { 
        if (tmp->next->next->type == E_FILE) 
        {       
            tmp->next->next->file = ft_split(tmp->next->next->Token_str, ' ');
            if(tmp->next->type == E_OUT)
                data->output_fd[i] =  open(tmp->next->next->file[0], O_CREAT | O_WRONLY | O_TRUNC, 0644);
            if (tmp->next->type == E_APPEND)
                data->output_fd[i] =  open(tmp->next->next->file[0], O_CREAT | O_WRONLY | O_APPEND, 0644);
            if (tmp->next->next->file[1] != NULL && tmp->next->next->file[1][0] != '\0')
                data->cmd = copy_array_arrays(tmp->next->next->file);
            i++;
        }
        tmp = tmp->next->next;
    }
    return(data->output_fd);
}

pid_t fork_process_redi_out(t_data *data, t_Token *curr, t_Token *lst_tok)
{
    pid_t pid = fork(); 
    data->output_fd = malloc(data->nb_file_out * sizeof(int)); 
    int fd[2];
    pipe(fd);

    if (pid == 0)
    {  
        data->path_exe = ft_get_reading(data, curr);
        if(!data->path_exe)
            ft_no_patch(data, lst_tok);   
        if(data->redi_out_bf_pipe == 1)
        {    
            dup2(fd[0], STDIN_FILENO);
            close(fd[1]);
            close(fd[0]);
        }
        data->output_fd = creat_fd_out(data, curr);
        dup2(data->output_fd[data->nb_file_out -1], STDOUT_FILENO);
        close(data->output_fd[data->nb_file_out -1]);
        if(check_builtins(lst_tok, data->envp) == 1)
        {   
            if(execve(data->path_exe, data->cmd, data->envp) == -1)
            {           
                close_fd_out(data);
                free_for_fail_exe_exit(data, lst_tok, curr);
            }
        }
        free(data->path_exe);
        free_token(lst_tok);
        close_fd_out(data);
        close(data->input_fd);
    }
    return (pid);
}