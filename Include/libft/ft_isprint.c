/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <zack@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:55:14 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/11 16:55:18 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char c = 6 ;

	if (ft_isprint(c))
	{
    		printf("ft_isprint = Le caractère %c est imprimable.\n", c);
	}
	else
	{
    		printf("ft_isprint = Le caractère %c n'est pas imprimable.\n", c);
	}	
	
	if (isprint(c))
	{
    		printf("isprint = Le caractère %c est imprimable.\n", c);
	}
	else
	{
    		printf("isprint = Le caractère %c n'est pas imprimable.\n", c);
	}
}
*/
