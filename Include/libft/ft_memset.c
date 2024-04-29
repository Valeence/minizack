/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:43:25 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/18 22:48:03 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	char	*p;

	p = pointer;
	while (count)
	{
		*p = (unsigned char) value;
		p++;
		count--;
	}
	return (pointer);
}
/*
int main () 
{
   char str[50];

   strcpy(str,"This is string.h library function");
   puts(str);

   ft_memset(str,'0', 4);	
   puts(str);
   memset(str,'0', 4);
   puts(str);

   
   return(0);
}*/
