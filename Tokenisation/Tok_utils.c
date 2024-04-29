#include "../Include/MiniShell.h"

bool ft_isspace(char c) 
{
    return (c ==   32 || c ==   9);
}

bool ft_is_del(char c) 
{
    return (c == '|' || c == '<' || c == '>');
}

bool ft_is_qote(char c)
{
	return (c ==  '\'' || c ==  '"');
}

int	skip_begin_spaces_prompt(const char *readline, int start)
{
	while (ft_isspace(readline[start]))
		start++;
	return (start);
}

int	extract_token(const char *readline, int start, char **token, t_data *data)
{
	int	end;

	end = start;
	while (readline[end] && !ft_is_del(readline[end]))
	{	
		if (readline[end] == '\'')
            data->in_single_quote = !data->in_single_quote;
        else if (readline[end] == '"')
            data->in_double_quote = !data->in_double_quote;	
		if(!ft_is_del(readline[end]) && (data->in_single_quote == 1 || data->in_double_quote == 1))
				end++;
		end++;	
	}
	*token = ft_strndup(readline + start, end - start);
	return (end);
}