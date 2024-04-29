/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:57:51 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/18 22:49:04 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
strnstr  permet de rechercher la première 
occurrence 
d'une sous-chaîne dans une chaîne de caractères jusqu'à une longueur 
maximale donnée.
La fonction strnstr renvoie un pointeur vers la première occurrence 
de la sous-chaîne 
dans la chaîne de caractères de recherche si celle-ci est trouvée, 
ou un pointeur nul si la sous-chaîne n'est pas trouvée.
*/

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (*s2 == '\0')
		return ((char *)s1);
	if (n == 0)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s2[j] && s1[i + j] == s2[j] && (i + j) < n)
				j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}

/*
int main() 
{
    char str1[] = "Hello, world!";
    char str2[] = "wo";
    
    char *result;
    
    result = ft_strnstr(str1, str2, 3); 
   // result = strnstr(str1, str2, strlen(str1));

    if (result == NULL) 
    {
        printf("La sous-chaîne n'a pas été trouvée.\n");
    } 
    else 
    {
        printf("La sous-chaîne a été trouvée à l'adresse : %p\n", result);
    }
    return (0);
}
*/
