#include "../Include/MiniShell.h"
/*
int getSubArraySize(char *subArray) 
{
    int size = 0;
    while (subArray[size] != -1) 
        size++;

    return size;
}
*/

void    ft_no_patch(t_data *data, t_Token  *lst_tok)     
{
        printf("Bash : command not found in : %s\n", data->cmd[0]);
        ft_free_tabtab(data->cmd);
        free_token(lst_tok);
        exit(EXIT_FAILURE);
}

bool  verif_pipe(t_Token *curr)
{
    t_Token     *shr_pipe; 

    shr_pipe = curr;
    while(shr_pipe != NULL && shr_pipe->next != NULL)
    {   
        if (shr_pipe->next->Token_str[0] == '|')
            return(true);
        shr_pipe = shr_pipe->next;
    }    
    return(false);
}

char **copy_array_arrays(char **src) 
{
    if (!src) 
        return NULL;
    int count = 0;
    while (src[count] != NULL)
        count++;
    char **dest = malloc((count + 1) * sizeof(int *));
    if (!dest)
        exit(EXIT_FAILURE);
    int i = 0;
    while (i < count) 
    {
        int subArraySize = ft_strlen(src[i]);// -1
        dest[i] = malloc((subArraySize + 1) * sizeof(int));
        if (!dest[i]) 
            exit(EXIT_FAILURE);
        int j = 0;
        while(j <= subArraySize)
        {   
            dest[i][j] = src[i][j];
            j++;
        }
        i++;
    }
    dest[count] = NULL;
    return dest;
}

void free_for_fail_exe_exit(t_data *data, t_Token *lst, t_Token *curr)
{
    if (data->cmd[0] != NULL && data->cmd[0][0] != '\0')
        ft_free_tabtab(data->cmd);
    free(data->path_exe);
    free(curr);
    free_token(lst);
    exit(EXIT_FAILURE);
}
