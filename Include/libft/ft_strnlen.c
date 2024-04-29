/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:16:47 by zachamou          #+#    #+#             */
/*   Updated: 2024/02/26 20:21:54 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strnlen(const char *str, int maxlen)
{
    int i;

    i = 0;
    while(i < maxlen && str[i])
        i++;
    return (i);
}