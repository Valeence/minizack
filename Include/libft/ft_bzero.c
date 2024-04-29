/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:14:27 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/18 22:48:30 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*bzero remplit les n premiers octets de la zone mémoire pointée par s avec 
 des zéros. */
void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	count;

	count = n;
	p = s;
	while (count > 0)
	{
		*p = 0;
		p++;
		count--;
	}
}
/*
int main() 
{
    char str[50] = "This is my function!";

    printf("Avant my_bzero : %s\n", str);

    ft_bzero(str, sizeof(str));

    printf("Après my_bzero : %s\n", str);

    return 0;
}*/
