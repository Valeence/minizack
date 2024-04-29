/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:44:19 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/03 17:29:11 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> 
#include <ctype.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
int main()
{
	char c = '1';

	if (ft_isalpha(c))
	{
    		printf("1\n", c);
	}
	else
	{
    		printf("%0\n", c);
	}	
	
	if (isalpha(c))
	{
    		printf("Isalpha = Le caractère %c est alphabétique.\n", c);
	}
	else
	{
    		printf("Isalpha = Le caractère %c n'est pas alphabétique.\n", c);
	}

}*/
