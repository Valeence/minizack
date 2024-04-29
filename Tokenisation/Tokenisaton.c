#include "../Include/MiniShell.h"

char	*ft_put_neg(char *str)
{
	int		i;
	char	s_or_d;

	i = 0;
	while(str[i])
	{
		if(str[i] == Single_Quotes || str[i] == Double_Quotes)
		{
			s_or_d = str[i];
			i++;
			while(str[i] && str[i] != s_or_d)
			{
				str[i] = str[i] * -1;
				i++;
			}
		}
		i++;
	}
	return (str);
}

// DEBUG DEBUG DEBUG DEBUG  DEBUG 
void	print_list(t_Token *begin)
{
	t_Token	*current;

	current = begin;
	while (current != NULL)
	{
		printf("------------------------------\n");
		printf("str = [%s] type = %d\n", current->Token_str, current->type);
		printf("-------------------------------\n");

		current = current->next;
	}
}
// DEBUG DEBUG DEBUG DEBUG  DEBUG 


// re code strcmp
void	ft_analy_type(t_data *data, t_Token **list_tok) 
{
    t_Token	*current;
    current = *list_tok;

    while (current != NULL) 
	{
        if (strcmp(current->Token_str, pip) == 0) 
            ft_analy_type_pipe(data, &current);
        else if (strcmp(current->Token_str, rdi_in) == 0) // <
            ft_analy_type_redi_in(data, &current);
        else if (strcmp(current->Token_str, rdi_out) == 0)// re faire strmcp
            ft_analy_type_redi_out(&current);
        else if (strcmp(current->Token_str, ">>") == 0)
            ft_analy_type_redi_append(&current);
        else if(strcmp(current->Token_str, "<<") == 0)
            ft_analy_type_redi_heredoc(&current);
        else if (strcmp(current->Token_str, "\0") == 0 || strcmp(current->Token_str, "") == 0)
            current->type = E_EMPTY;
        else
            ft_analy_type_else(data, &current);
        if (current != NULL)
            current = current->next;
    }
}

void pre_add_special_tok(const char *readline, t_Token **list_token)
{
	char *token = NULL;
    t_Token *temp_token = NULL;

	token = ft_strndup(readline, 2); 
    temp_token = Creat_noed_Token(token);
    add_token(list_token, temp_token);

}


int handle_special_tok(const char *readline, t_Token **list_token, int i)
{
	char *token = NULL;
    t_Token *temp_token = NULL;

	if (readline[i] == '>' && readline[i + 1] == '>') 
	{
		pre_add_special_tok(&readline[i], list_token);
        i += 2;
    }
	else if (readline[i] == '<' && readline[i + 1] == '<')
	{
		pre_add_special_tok(&readline[i], list_token);
        i += 2;
	}
	else 
	{
		token = ft_strndup(&readline[i], 1);
        temp_token = Creat_noed_Token(token);
        add_token(list_token, temp_token);
        free(token);
        i++;
    }
	return(i);
}

void ft_tokenize_moi_ca(char *readline, t_Token **list_token, t_data *data) 
{
    int i = 0;
    char *token = NULL;
    t_Token *temp_token = NULL;
    data->in_single_quote = 0; 
    data->in_double_quote = 0; //a mettre dans init

    while (readline[i]) 
    {
        if (ft_isspace(readline[i])) 
        {
            i++;
            continue;
        }
        i = extract_token(readline, i, &token, data);
        temp_token = Creat_noed_Token(token);
        add_token(list_token, temp_token);
        free(token);        
        if (readline[i] == '\'')
        {
            data->in_single_quote = !data->in_single_quote;
        }
        else if (readline[i] == '"')
             data->in_double_quote = !data->in_double_quote;
        if (ft_is_del(readline[i])) 
        {
            if (data->in_single_quote == 1 || data->in_double_quote == 1) 
            {
                char del = readline[i];
                del *= -1;
                readline[i] = del;
                i++;
            } 
            else
                i = handle_special_tok(readline, list_token, i);
        }
    }
}


void	ft_lexer(t_data *data, t_Token **list_token)
{
	ft_tokenize_moi_ca(data->pronpt, list_token, data);
	ft_analy_type(data, list_token);
	ft_supp_noed_empy(list_token);
}