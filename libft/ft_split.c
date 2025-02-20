/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:11:38 by jmader            #+#    #+#             */
/*   Updated: 2024/11/13 13:34:04 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	cpt;
	int		i;

	cpt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			cpt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cpt);
}

static char	**tab_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free (tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		global_i;
	int		i;
	int		start;
	char	**res;

	global_i = 0;
	i = 0;
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
			res[global_i] = ft_substr(s, start, i - start);
		if (start < i && !res[global_i++])
			return (tab_free(res, global_i - 2));
	}
	res[global_i] = NULL;
	return (res);
}
