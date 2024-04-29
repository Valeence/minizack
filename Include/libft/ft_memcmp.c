/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:46:09 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/18 22:47:42 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
memcmp compare les deux zones de mémoire octet par octet, 
en retournant un entier négatif si la première zone st inférieure à 
la seconde, un entier positif si 
la première zone est supérieure à la seconde et 0 si les deux 
zones sont identiques.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*pt1;
	const unsigned char	*pt2;

	pt1 = s1;
	pt2 = s2;
	while (n--)
	{
		if (*pt1 != *pt2)
			return (*pt1 - *pt2);
		pt1++;
		pt2++;
	}
	return (0);
}
/*
int main(void)
{
    char str1[]="bbb";
    char str2[]="aaa";

    printf("%d\n", memcmp(str1, str2, 1));
    printf("%d", ft_memcmp(str1, str2, 1));
}
*/
