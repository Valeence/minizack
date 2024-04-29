#include "../Include/MiniShell.h"

void    ft_analy_type_pipe(t_data *data, t_Token **current)
{
        (*current)->type = E_PIPE;
		data->nb_pipe++;
}


void    ft_analy_type_redi_out(t_Token **current)
{
    	(*current)->type = E_OUT;
		if ((*current)->next != NULL)
            (*current)->next->type = E_FILE;
		(*current) = (*current)->next;
}

void    ft_analy_type_redi_append(t_Token **current)
{
        (*current)->type = E_APPEND;
		if ((*current)->next != NULL)
            (*current)->next->type = E_FILE;
		(*current) = (*current)->next;
}

void    ft_analy_type_redi_heredoc(t_Token **current)
{
       (*current)->type = E_HEREDOC;
		if ((*current)->next != NULL)
            (*current)->next->type = E_OEF_HERE;
		(*current) = (*current)->next;
}
