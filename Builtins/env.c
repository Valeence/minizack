/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:43:22 by vandre            #+#    #+#             */
/*   Updated: 2024/04/18 03:32:46 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/MiniShell.h"

int ft_env(char **envp)
{
    t_env *env;
    int i;
    
    i = 0;
    while(envp[i])
        i++;
    env = malloc(sizeof(t_env));
    env->env = malloc(sizeof(char *) * (i + 1));
    i = 0;
    while(envp[i])
    {
        env->env[i] = envp[i];
        i++;
    }
    env->env[i] = NULL;
    i = 0;
    while(env->env[i])
    {
        printf("%s\n", env->env[i]);
        i++;
    }
    return (0);
}