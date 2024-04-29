/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:01:01 by vandre            #+#    #+#             */
/*   Updated: 2024/04/26 03:02:56 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/MiniShell.h"

int     pipe_check(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '|')
        {
            while (str[i] == ' ' || str[i] == '\t')
                i++;
            if (str[i + 1] == '|')
            {
                printf("Syntax error\n");
                return (0);
            }
            i++;
            while (str[i] == ' ' || str[i] == '\t')
                i++;
            if (str[i] == '\0' || str[i] == '|')
            {
                printf("Syntax error\n");
                return (0);
            }
        }
        i++;
    }
    return (1);
}

int    redirection_check_sup(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i] == '>') 
        {
            if (str[i + 1] == '>')
                i++;
            i++;
            while (str[i] == ' ' || str[i] == '\t')
                i++;
            if (str[i] == '\0' || str[i] == '>' || str[i] == '|')
            {
                printf("Syntax error\n");
                return (0);
            }
        }
        i++;
    }
    return (1);
}

/*
int   redirection_check_inf(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i] == '<') 
        {
            i++;
            while (str[i] == ' ' || str[i] == '\t')
                i++;
            if (str[i] == '\0' || str[i] == '<' || str[i] == '|')
            {
                printf("Syntax error\n");
                return (0);
            }
        }
        i++;
    }
    return (1);
}
*/

int check_quote(char *str)
{
    int i;
  
    i = 0;
    while (str[i])
    {
        if (str[i] == '"')
        {
            i++;
            while (str[i] != '"')
            {
                if (str[i] == '\0')
                {
                    printf("Syntax error\n");
                    return (0);
                }
                i++;
            }
        }
        i++;
    }
    return (1);
}

int syntaxize_moi_ca(char *str)
{
    if (str == NULL)
        return (0);
    if (check_quote(str) == 0)
        return (0);
    if (pipe_check(str) == 0)
        return (0);
    if (redirection_check_sup(str) == 0)
        return (0);
    /*if (redirection_check_inf(str) == 0)
        return (0);
    */
    return (1);
}