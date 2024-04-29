/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:52:58 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/18 22:48:46 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
strlcat est utilisée pour concaténer deux chaînes de caractères de
 manière sécurisée, en évitant les débordements de mémoire est toujours
terminée par un caractère nul.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	while (dst[i] && i < size -1)
		i++;
	while (src[j] && i < size -1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + src_len);
}
/*
int main(void)
{
	char str1[20]="xxxxxk";
	char str2[20]="xxxxr";

	strlcat(str1, str2, 20);
	printf("strlcat = %s\n", str1);

	ft_strlcat(str1, str2, 20);
	printf("ft_strlcat = %s", str1);

	return (0);
}
*/
