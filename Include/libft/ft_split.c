/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:25:30 by zachamou          #+#    #+#             */
/*   Updated: 2024/03/30 07:23:42 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_strndupx(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc((n + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	ft_free_tab(char **tab, int size)
{
	while (size > 0)
		free(tab[--size]);
	free(tab);
}

static void	ft_popu_tab(const char *s, char c, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > k)
		{
			tab[j++] = ft_strndupx(s + k, i - k);
			if (tab[j - 1] == NULL)
			{
				ft_free_tab(tab, j);
				tab = NULL;
				return ;
			}
		}
	}
	tab[j] = NULL;
}

char	** ft_split(const char *s, char c)
{
	char	**tab;
	int		count;

	if (s == NULL)
		return (NULL);
	count = ft_count_words(s, c);
	tab = (char **)malloc((count + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	ft_popu_tab(s, c, tab);
	return (tab);
}

