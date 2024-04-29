/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <zack@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:29:00 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/11 18:03:28 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*p_dest;
	const char	*p_src;

	if (!dest && !src)
		return (NULL);
	p_dest = dest;
	p_src = src;
	while (n--)
	{
		*p_dest = *p_src;
		p_dest++;
		p_src++;
	}
	return (dest);
}
/**
nt	main(void)
{
	char src[]="Hello libft";
	char dest[20];
	
	memcpy(dest, src, 7);
	printf("memcpy = %s\n",dest);
		
	ft_memcpy(dest, src, 7);
	printf("ft_memcpy = %s\n",dest);
	
	return (0);
}
*/
