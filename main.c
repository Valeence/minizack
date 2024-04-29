#include "./Include/MiniShell.h"

void init_data(t_data *data)
{
 	data->pipe_bf_redi = 0;
    data->redi_out_bf_pipe = 0;
	data->first = 0;
	data->nb_cmd = 0;
	data->nb_file_in = 0;
	data->nb_pipe = 0;
}

// void    signal_handle()
// {
//     printf("\n");
//     rl_on_new_line();
//     rl_replace_line("", 0);
//     rl_redisplay();
// }

int	main(int ac, char **av, char **env)
{
	t_data	data;
	t_Token	*list_token = NULL;

	(void)ac;
	(void)av;
	// signal(SIGINT, signal_handle);
	// signal(SIGQUIT, SIG_IGN);
	// char **envp_copy

	while (1)
	{
		data.envp = env;
		list_token = NULL;
		init_data(&data);
		data.pronpt = readline("Mini_Shell :");
		if (!data.pronpt)
			break;
		if (!*data.pronpt)
			continue ;
		if (syntaxize_moi_ca(data.pronpt) == 1)
		{
			ft_lexer(&data, &list_token);
			//print_list(list_token);
			if(list_token != NULL)	
			{	
				ft_lanch_exe(&data, list_token);
				add_history(data.pronpt);
				free(data.pronpt);
				free_token(list_token);

			}
		}
	}
	// free_token(list_token);
	// free(data.str);
	// rl_clear_history();
	return (0);
}

/*
[ls][|][ls][>][avion][|][grep a] 
nbmaxpipe =0
while(node)
{
	while (i != nbmaxpipe)
	{
		if (node->type == PIPE)
			i++;
		node = node->next;
	}
	pipe(pipe)
	// if node->type == COMMAND
	if node->type == PIPE && node->next->type == WORD ou i = 0 && node->type == WORD 
		i++;
}
*/
/*
[ls][|][cat > avion][|][grep a] 
while(node)
{
	if (node->type == PIPE)
		node = node->next;
	pipe(pipe)
	fork
	//
		while (node && nbmaxpipe != numerodecommande)
		{
			if (node->type == PIPE)
				nbmaxpipe++
			node = node->next;
		}
	node = node->next;
	numerodecommande++;
}
*/