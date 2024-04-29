#include "../Include/MiniShell.h"

int shr_not_cmd(char *str)
{
	int i = 0;

	while(str[i])
	{
		if(str[i] == '.' || str[i] == '/')
			return (1);
		i++;
	}
	return(0);
}


int	ft_cont_w(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
		{
			count++;
			while (s[i] && s[i] != ' ')
				i++;
		}
		else
			i++;
	}
	if(count > 2)
		count = 3;
	return (count);
}

void ft_analy_type_redi_in(t_data *data, t_Token **current) 
{
    if (*current == NULL) 
        return;
    (*current)->type = E_IN;
    if ((*current)->next != NULL) 
    {
        int size = ft_cont_w((*current)->next->Token_str);
        if (size > 1) 
        {
            insertNodesAtCurrent(*current, size);
            (*current)->next->type = E_FILE;
            if ((*current)->next->next != NULL)
                (*current)->next->next->type = E_WORD;
        } 
        else 
            (*current)->next->type = E_FILE;
        *current = (*current)->next;
        data->nb_file_in += 1;
    }
}

void ft_analy_type_else(t_data *data, t_Token **current)
{
	if(shr_not_cmd((*current)->Token_str) == 1)
		(*current)->type = E_NOT_CMD;
	else
	{	
		(*current)->type = E_WORD;
		data->nb_cmd += 1;
	}
}	
