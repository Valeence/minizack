/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:38:30 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/16 15:22:06 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_count_nb(int n)
{
	long	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}	
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb_count;
	long	len;

	nb_count = n;
	len = ft_count_nb(nb_count);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	if (nb_count < 0)
		nb_count = -nb_count;
	while (len >= 0)
	{
		str[len] = (nb_count % 10) + '0';
		nb_count = nb_count / 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
