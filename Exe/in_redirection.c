#include "../Include/MiniShell.h"

void close_fd_in(t_data *data)
{
    int i = 0;
    while(i < data->nb_file_in)
    {    
        close(data->in_fd[i]);
        i++;
    }
    free(data->in_fd);

}

int *creat_fd_in(t_data *data, t_Token *curr) 
{
    int i = 0;
    
    t_Token *tmp = curr;
    while (i < data->nb_file_in) 
    {   
        if (tmp->next->next->type == E_WORD)
        {
            tmp->next->file = ft_split(tmp->next->Token_str, ' ');
            data->in_fd[i] = open(tmp->next->file[0], O_RDONLY);
            if (tmp->next->file[1] != NULL && tmp->next->file[1][0] != '\0')
                data->cmd = copy_array_arrays(tmp->next->file);   
            i++;
        }
        else if(tmp->next->next->type == E_FILE) 
        {
            tmp->next->next->file = ft_split(tmp->next->next->Token_str, ' ');
            data->in_fd[i] = open(tmp->next->next->file[0], O_RDONLY);
            if (tmp->next->next->file[1] != NULL && tmp->next->next->file[1][0] != '\0')
                data->cmd = copy_array_arrays(tmp->next->next->file);   
            i++;
        }
        tmp = tmp->next->next;
    }
    return data->in_fd;
}

pid_t fork_process_redi_in(t_data *data, t_Token *curr, t_Token *lst_tok)
{
    pid_t pid = fork(); 
    data->in_fd = malloc(data->nb_file_in * sizeof(int)); 

    if (pid == 0)
    { 
        if (curr->type == E_IN && curr->next->type == E_FILE && curr->next->next->type == E_WORD)
            data->path_exe = ft_get_reading(data, curr->next->next);
        else if (curr->type == E_WORD)
            data->path_exe = ft_get_reading(data, curr);
        if(!data->path_exe)
            ft_no_patch(data, lst_tok);
        data->in_fd = creat_fd_in(data, curr);    
        dup2(data->in_fd[data->nb_file_in - 1], STDIN_FILENO);
        close(data->in_fd[data->nb_file_in - 1]);
        if(check_builtins(lst_tok, data->envp) == 1)
        {   
            if(execve(data->path_exe, data->cmd, data->envp) == -1)
            {           
                close_fd_in(data);
                free_for_fail_exe_exit(data, lst_tok, curr);
            }
        }
        free(data->path_exe);
        free_token(lst_tok);
        close_fd_in(data);
    }
    return (pid);
}