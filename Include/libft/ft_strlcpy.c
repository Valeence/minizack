/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:03:37 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/18 22:48:49 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
strlcpy copie jusqu'à size - 1 caractères de la chaîne src dans
la chaîne dst et ajoute toujours un caractère nul à la fin de dst. 
 Si src
est plus longue que size - 1, seuls size - 1 caractères seront copiés dans 
 dst, et dst sera terminé par un caractère nul. */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
	{
		return (src_len);
	}
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
int	main(void)
{
	char src[] = "Bonjour toiiz 4!";
	char dest[14] = "";
	
	printf("size = %zu, ch = %s", ft_strlcpy(dest, src, 16), dest);
	
	return (0);
}*/
