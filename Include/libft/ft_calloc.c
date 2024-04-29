/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:41:47 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/16 15:18:34 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		if (ptr != NULL)
			ft_bzero(ptr, 1);
		return (ptr);
	}
	total_size = nmemb * size;
	if (nmemb == total_size / size)
	{
		ptr = malloc(total_size);
		if (ptr == NULL)
			return (NULL);
		ft_bzero(ptr, total_size);
		return (ptr);
	}
	else
		return (NULL);
}
