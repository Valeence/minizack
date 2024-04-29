/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:36:59 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/18 22:48:40 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int main(void)
{
	char c = '0';

	if (ft_isdigit(c))
	{
    		printf("ft_isalpha = Le caractère %c est digit.\n", c);
	}
	else
	{
    		printf("ft_isalpha = Le caractère %c n'est pas digit.\n", c);
	}	
	
	if (isdigit(c))
	{
    		printf("IsDigit = Le caractère %c est digit.\n", c);
	}
	else
	{
    		printf("Isalpha = Le caractère %c n'est pas digit.\n", c);
	}

}
*/
