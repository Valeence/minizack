#include "../Include/MiniShell.h"

void ft_free_tabtab(char **split_result) 
{
    if (split_result == NULL) 
        return;
    
    int i = 0;
    while (split_result[i] != NULL) 
    {   
        free(split_result[i]);
        i++;
    }
    free(split_result);
}


void ft_simple_cmd(t_data *data, t_Token *list_token)
{
    pid_t	pid;

    data->path_exe = ft_get_reading(data, list_token);
    if(!data->path_exe)
    {
        printf("\n\n%s\n\n", data->cmd[0]);
        printf("%s: command not found \n", data->cmd[0]);
        ft_free_tabtab(data->cmd);
        return;
    }
    else
    {    
        pid = fork();                   
        if (pid == 0)                   
        {
            if (execve(data->path_exe, data->cmd, data->envp) == -1) 
                return;   
        }
        else                             
        {
            wait(NULL); 
            ft_free_tabtab(data->cmd); 
            free(data->path_exe);
        }
    }
}