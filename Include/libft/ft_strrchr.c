/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:44:23 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/05 13:00:05 by zachamou"         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

/*strrchr est utilisée pour rechercher la dernière occurrence de la chaine s et 
renvoie donc un pointeur vers la dernière occurrence du caractère spécifié dans
la chaîne*
renvois la denier occ stocker dans last_occ*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occ;

	last_occ = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_occ = s;
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	else if (last_occ != NULL)
		return ((char *)last_occ);
	else
		return (NULL);
}
/*
int	main(void)
{
	char str[] ="Bonjour, test, plus d'inspiii";
	char *p;
	char *j;
	char x;

	x = 'u';
	
	p = strrchr(str, x);
	
	if (p != NULL)
		printf("Le caractère '' été trouvé\n");
	else
		printf("Le caractère '' n'a pas été trouvé.\n");
	
	j  = ft_strrchr(str, x);

	if (j != NULL)
		printf("(ft_strchr)Le caractère a été trouvé\n");
	else
		printf("(ft_strchr)Le caractère n'a pas été trouvé.\n");
	return (0);
}
*/
