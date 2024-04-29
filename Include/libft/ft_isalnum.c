/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:17:22 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/18 22:47:34 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char c = '+';

	if (ft_isalnum(c))
	{
    		printf("ft_isalnum  = Le caractère %c est alphanumérique.\n", c);
	}
	else
	{
    		printf("ft_isalnum = Le caractère %c n'est pas alphanumérique.\n", c);
	}	
	
	if (isalnum(c))
	{
    		printf("isalnum  = Le caractère %c est alphanumérique.\n", c);
	}
	else
	{
    		printf("isalnum  = Le caractère %c n'est pas alphanumérique.\n", c);
	}

}
*/
