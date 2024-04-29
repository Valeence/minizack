/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vandre <vandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:43:18 by vandre            #+#    #+#             */
/*   Updated: 2024/04/05 22:50:26 by vandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/MiniShell.h"

int *fill_tab(char *str, int i, int *tab)
{
    int j;

    i += 2;
    j = 0;
    if (!str || !tab)
        return NULL;
    while (str[i] == ' ')
        i++;
    while (str[i] != ' ' && str[i] != '\0')
    {
        i++;
        j++;
    }
    tab[0] = i;
    tab[1] = j;
    return (tab);
}

int check_home(char *str)
{
    char *home;
    int i;

    i = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == 'c' && str[i + 1] == 'd')
    {
        i += 2;
        while (str[i] == ' ')
            i++;
        if (str[i] == '\0' || str[i] == '~')
        {
            home = ft_strjoin(getenv("HOME"), "/Minishell");
            chdir(home);
            return 1;
        }
    }
    return 0;
}

int *find_path_cd(char *str)
{
    int *tab;
    int i;
    
    i = 0;
    tab = malloc(sizeof(int) * 2);
    if (!tab)
        return NULL;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (str[i] == 'c' && str[i + 1] == 'd')
        {
            if (check_home(str) == 1)
            {
                tab[0] = -1;
                return (tab);
            }
            tab = fill_tab(str, i, tab);
            return (tab);
        }
        i++;
    }
    free(tab);
    return NULL;
}

char *fill_path(char *str, int j, int x)
{
    char *path;
    int i;

    if (!str)
        return NULL;
    path = malloc(sizeof(char) * x + 1);
    if (!path)
        return 0;
    i = 0;
    while (i < x)
    {
        path[i] = str[j];
        i++;
        j++;
    }
    path[i] = '\0';
    return (path);
}

int ft_cd(t_Token *curr)
{
    char *path;
    int *tab;
    int j;
    
    tab = find_path_cd(curr->Token_str);
    if (!tab)
        return 0;
    if (tab[0] == -1)
    {
        free(tab);
        return 0;
    }
    j = tab[0] - tab[1];
    path = fill_path(curr->Token_str, j, tab[1]);
    if (chdir(path) != 0)
    {
        printf("bash: cd: %s: No such file or directory\n", path);
        free(tab);
        free(path);
        return 0;
    }
    free(tab);
    free(path);
    return (1);
}
