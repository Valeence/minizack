/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:41:47 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/18 22:48:37 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main()
{
	char c = 127;

	if (ft_isascii(c))
	{
    		printf("ft_isascii = Le caractère %c est ascii.\n", c);
	}
	else
	{
    		printf("ft_isascii = Le caractère %c n'est pas ascii.\n", c);
	}	
	
	if (isascii(c))
	{
    		printf("isascii = Le caractère %c est ascii.\n", c);
	}
	else
	{
    		printf("isascii = Le caractère %c n'est pas ascii.\n", c);
	}

}
*/
