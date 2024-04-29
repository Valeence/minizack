/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:36:14 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/03 15:20:36 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	pdest = (unsigned char *)dest;
	psrc = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (pdest > psrc)
	{
		while (n--)
			pdest[n] = psrc[n];
	}
	else
	{
		while (n--)
			*pdest++ = *psrc++;
	}
	return (dest);
}
/*
int	 main(void)
{

	char src[] ="bien 000000000000000000000000000000000000000";	
	char dest[]="Le cluster silencieux c'est vraiment xxxx";

    	memmove(dest+37, src, 5);
	printf("memnouve = %s\n", dest);

	ft_memmove(dest+37, src, 5);
	printf("ft_memmouve =%s", dest);
        return (0);
}
*/
