/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:22:59 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/04 12:26:58 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
La fonction memchr, recherche un caractère spécifié dans une 
zone mémoire de taille donnée, et renvoie un pointeur vers la première 
occurrence de ce caractère. La fonction peut être utilisée pour 
rechercher un caractère dans une zone mémoire qui ne se termine pas 
nécessairement par un caractère de fin de chaîne '\0.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = (const unsigned char *)s;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*str = "Hello, world!";
	char	*ptr;
	int		c = 'o';

	ptr = ft_memchr(str, c, 5); // 	ptr = ft_memchr(str, c, strlen(str));
	
    if (ptr != NULL)
		printf("(ft_memchr) caractère '%c' a été trouvé à l'adresse %p.\n\n", c, ptr);
	else
		printf("(ft_memchr) caractère '%c' n'a pas été trouvé.\n\n", c);

	ptr = memchr(str, c, 5);

	if (ptr != NULL)
		printf("(memchr) caractère '%c' a été trouvé à l'adresse %p.\n", c, ptr);
	else
		printf("(memchr)Le caractère '%c' n'a pas été trouvé.\n", c);

	return (0);
}
 */
