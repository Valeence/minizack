/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 00:09:34 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/30 00:09:38 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(long long nb, int base)
{
	int	len;

	len = 1;
	if (nb < 0 && base == 10)
	{
		len += 1;
		nb = -nb;
	}
	while (nb / base > 0)
	{
		len++;
		nb /= base;
	}
	return (len);
}

static char	*allocate_result(int len)
{
	char	*result;

	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	return (result);
}

static void	fill_result(char *result, long long nb, int base, int len)
{
	const char	*digits;

	digits = "0123456789abcdef";
	while (nb != 0)
	{
		if (nb < 0 && base == 10)
			result[--len] = digits[-(nb % base)];
		else
			result[--len] = digits[nb % base];
		nb /= base;
	}
	if (nb < 0 && base == 10)
		result[0] = '-';
}

char	*ft_itoa_base(long long nb, int base)
{
	int		len;
	char	*result;

	if (base < 2 || base > 16)
		return (NULL);
	len = get_num_len(nb, base);
	result = allocate_result(len);
	if (!result)
		return (NULL);
	if (nb == 0)
	{
		result[0] = '0';
		return (result);
	}
	fill_result(result, nb, base, len);
	return (result);
}
