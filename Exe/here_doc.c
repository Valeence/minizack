#include "../Include/MiniShell.h"

int  cont_nb_here(t_Token *curr)
{
    t_Token     *shr_here; 
    int i = 0;

    shr_here = curr;
    while(shr_here != NULL)
    {   
        if (shr_here->type == E_HEREDOC)
            i++;
        if(shr_here->Token_str[0] == '|' || shr_here->type == E_OUT || shr_here->type == E_APPEND)
            break;
        shr_here = shr_here->next;
    }    
    return(i);
}

void exe_cmd(t_data *data, t_Token *lst_tok, char **envp, char *s)
{
    if (execve(data->path_exe, data->cmd, envp) == -1) 
    {
        perror("Erreur lors de l'exécution de la commande");
        free_token(lst_tok);
        free(data->path_exe);
        free(s);
        exit(EXIT_FAILURE);
    }
}


void execute_command_in_child(t_data *data, t_Token *curr, t_Token *lst_tok, char **envp, char *str) 
{
        int fd[2];
        pipe(fd);
        pid_t pid = fork();

        if (pid == 0) 
        {   
            close(fd[1]); 
            dup2(fd[0], STDIN_FILENO);  
            close(fd[0]);
            data->path_exe = ft_get_reading(data, curr);
            if (!data->path_exe) 
            {
                fprintf(stderr, "Bash : commande introuvable : %s\n", data->cmd[0]);// fprintf a refaire
                free_token(lst_tok);
                free(str);
                exit(EXIT_FAILURE);
            }
            exe_cmd(data, lst_tok, envp, str);
        } 
        else 
        {
            close(fd[0]);  
            write(fd[1], str, strlen(str));
            close(fd[1]);
            waitpid(pid, 0, 0);
        }
}

int fork_here(t_Token *curr, t_data *data, char **envp, t_Token *lst_tok, t_here *here) 
{   
    char *str = malloc(1);
    if (str == NULL) 
        return -1;
    *str = '\0';    
    char *line;
    size_t len = 0; 

    while (1) 
    { 
        line = readline (">" );
        if (strcmp(line, here->delim[0]) == 0) 
        {
            free(line);
            break;
        }
        len += ft_strlen(line) + 1; // +1 pour le '\n'
          char *new_str = realloc(str, len + 1); // +1 pour le '\0' final
        if (new_str == NULL) 
        {
            free(str);
            free(line);
            return -1;
        }
        str = new_str;
        strcat(str, line);
        strcat(str, "\n"); 
        free(line);
    }
    if (here->exe == 1)
        execute_command_in_child(data, curr, lst_tok, envp, str); 
    free(str);
    return 0;
}



void init_here_doc(t_data *data, t_Token *curr, int nb, t_here *here)
{
    int i = 0;
    t_Token *tmp = curr;
    int temp_i;

    while (i < nb)
    { 
        if (tmp->type == E_WORD && tmp->next->type == E_HEREDOC) 
        {  
                here[i].delim = ft_split(tmp->next->next->Token_str, ' ');
               if (tmp->next->next->next != NULL && (tmp->next->next->next->type == E_HEREDOC))
                {
                    tmp = tmp->next->next;
                    data->flag_here = 1;
                    here[i].exe = 0;
                }
                else
                    here[i].exe = 1;
            i++;
        }
        else if(tmp->type == E_HEREDOC)
        {
            
            here[i].delim = ft_split(tmp->next->Token_str, ' ');
            temp_i = i + 1;
            if(data->flag_here == 1 && temp_i == nb)
                here[i].exe = 1;
            else
                here[i].exe = 0;
            i++;
        }
        tmp = tmp->next;
    }
}


void lanch_her(t_Token *curr, t_data *data, t_Token *lst_tok)
{
    int grab_hd = cont_nb_here(curr);
    data->here = malloc(sizeof(t_here) * grab_hd);
    init_here_doc(data, curr, grab_hd, data->here);
    int i = 0;
    
    while (i < grab_hd)
    {   
        fork_here(curr, data, data->envp, lst_tok, &data->here[i]);
        i++;
    }
}