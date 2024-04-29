/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:44:54 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/18 22:48:23 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Elle commence par Alloue de l'espace pour une nouvelle chaîne,
en définissant la même taille que la chaîne d'origine puis Copie
la chaîne d'origine dans le nouvel espace alloué, y compris 
le caractère nul ( \0)
*/

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		j;
	int		i;

	j = 0;
	j = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (j + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main(void)
{
    char src[12] = "Ooga booga!";
    char *dup;
    char *dup2;
    int o_len;
    int d_len;

    dup = ft_strdup(src);
    dup2 = strdup(src);

    o_len = strlen(dup2);
    d_len = strlen(dup);

    printf("Original Strdup = %s (%d)\n", dup2, o_len);
    printf("My fonction strdup = %s (%d)\n", dup, d_len);

    free(dup);
    free(dup2);
    return 0;
}
*/
