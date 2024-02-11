/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:12:18 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/12/07 17:44:43 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//1. calculating the number of words we have

static int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

//allocates sufficient memory, copies the string and terminates
//with 0. 
static char	*ft_strndup( const char *s, size_t n)
{
	char	*str;
	size_t	i;
	size_t	m;

	i = 0;
	m = ft_strlen(s);
	if (m == 0 || n <= 0 || n > m)
		return (0);
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] && i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_freemem(char **nstr, int beg)
{
	beg = 0;
	while (nstr[beg])
	{
		free(nstr[beg]);
		beg++;
	}
	free(nstr);
	return (NULL);
}
//had to move this small part to a new function to make the code shorter.

static int	ft_beg(char const *s, char c, int beg)
{
	while (s[beg] && s[beg] != c)
		beg++;
	return (beg);
}

char	**ft_split(char const *s, char c)
{
	int		beg;
	int		end;
	int		tab;
	char	**nstr;

	beg = 0;
	tab = 0;
	nstr = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (nstr == NULL)
		return (NULL);
	while (s && s[beg])
	{
		while (s[beg] == c)
			beg++;
		end = beg;
		beg = ft_beg(s, c, beg);
		if (beg > end)
		{
			nstr[tab++] = (char *)ft_strndup(s + end, beg - end);
			if (nstr[tab - 1] == NULL)
				return (ft_freemem(nstr, beg));
		}
	}
	nstr[tab] = NULL;
	return (nstr);
}
//the array of pointers cannot be terminated with '\0' but
//need to be terminated with NULL (nstr[tab]).
