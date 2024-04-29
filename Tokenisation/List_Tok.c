#include "../Include/MiniShell.h"

int ft_size_list_token(t_Token *list_token)
{
    int i;
    t_Token *curr;

    i = 0;
    curr = list_token;
    while (curr->next != NULL)
    {
        curr = curr->next;
        i++;
    }
    return(i);    
}

void add_token(t_Token **begin, t_Token *new_token) 
{
    t_Token *current;

    if(!*begin) 
        *begin = new_token;
    else 
    {
        current = *begin;
        while (current->next != NULL)
            current = current->next;
        current->next = new_token;    
    }
}

t_Token *Creat_noed_Token(char *token) 
{   
    t_Token *noed = malloc(sizeof(t_Token));
    if (!noed) 
        return NULL;
    noed->Token_str = ft_strdup(token);
    noed->next = NULL;
    return noed;
}

void free_token(t_Token *begin) 
{
    t_Token *current = begin;
    t_Token *next;

    while (current != NULL) 
    {
        next = current->next; 
        free(current->Token_str); 
        free(current); 
        current = next;
    }
}

void ft_supp_noed_empy(t_Token **list_tok)
{
    t_Token *current = *list_tok;
    t_Token *prev = NULL;
    t_Token *next_node = NULL;

    while (current != NULL)
    {
        next_node = current->next; 
        if (current->type == E_EMPTY)
        {
            if (prev == NULL)
                *list_tok = next_node;
            else
                prev->next = next_node;
            free(current->Token_str);
            free(current);
        }
        else
            prev = current;
        current = next_node;
	}
}

void insertNodesAtCurrent(t_Token* current, int size) 
{
    if (current == NULL || current->next == NULL) 
        return;
    int i = 0;
	char **str_in;
	str_in = ft_split(current->next->Token_str, ' ');
	t_Token* last_inserted = current;
    t_Token* original_next = current->next->next;

    while (i < size) 
	{
        t_Token* new_node = malloc(sizeof(t_Token));
        if (new_node == NULL) 
        {
            printf("failed inser noed\n");
            return;
        }
        new_node->Token_str = strdup(str_in[i]); 
        new_node->next = last_inserted->next;
        last_inserted->next = new_node;
        last_inserted = new_node;  
		i++;
    }
    last_inserted->next = original_next;    
    ft_free_tabtab(str_in);
}