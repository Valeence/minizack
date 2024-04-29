/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <zack@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:22:57 by zachamou          #+#    #+#             */
/*   Updated: 2024/03/21 22:38:56 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char *ft_strndup(const char *s, size_t n)
{
    char *new_str;
    size_t i;


    new_str = ft_calloc(n +  1, sizeof(char));
    if (!new_str)
        return (NULL);

    i =  0;
    while (i < n && s[i])
    {
        new_str[i] = s[i];
        i++;
    }
    new_str[i] = '\0';

    return (new_str);
}
