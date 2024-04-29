/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:45:10 by zachamou          #+#    #+#             */
/*   Updated: 2023/05/18 22:47:36 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
striteri  applique une fonction donnée (*f) à chaque caractère d'une chaîne 
de caractères s, en passant également l'indice 
de chaque caractère à la fonction

char	ft_print_char(unsigned int i, char *c)
{
	printf("%u is: %c\n", i, *c);
}
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == 0 || f == 0)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int main(void)
{
	char *str = "LES CORROTE SONT CUITTTEE!";

	ft_striteri(str, ft_print_char);

	return (0);
}*/
