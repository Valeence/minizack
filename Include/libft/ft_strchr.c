/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:36:47 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/18 22:48:27 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
strchr, permet de rechercher la première occurrence d'un caractère spécifié c
 dans une chaîne de caractères s.
*/

char	*ft_strchr(const char *s, int c)
{	
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (NULL);
}
/*
int	main(void)
{
	char str[] ="Bonjour, test, plus d'inspiii";
	char x = 'x';
	char *p;
	char *j;


	
	p = strchr(str, x);
	
	if (p != NULL)
		printf("Le caractère '' été trouvé\n");
	else
		printf("Le caractère '' n'a pas été trouvé.\n");
	

	j  = ft_strchr(str, x);

	if (j != NULL)
		printf("(ft_strchr)Le caractère '' a été trouvé\n");
	else
		printf("(ft_strchr)Le caractère '' n'a pas été trouvé.\n");
	return (0);
}*/
