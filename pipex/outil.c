/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:44:46 by hrakik            #+#    #+#             */
/*   Updated: 2022/12/11 16:44:47 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size != 0 && count >= SIZE_MAX / size)
	{
		return (NULL);
	}	
	p = malloc(count * size);
	if (p == 0)
		return (0);
	ft_bzero (p, (count * size));
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*sr;

	sr = (char *)s;
	i = 0;
	while (i < n)
	{
		sr[i] = '\0';
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			return (((unsigned char )*(s1 + i)) - ((unsigned char )*(s2 + i)));
		}
		i++;
	}
	return (0);
}

char	*ft_strcpy1(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	char	*b;
	char	*all;
	int		lend;
	int		lens;

	d = (char *)s1;
	b = (char *)s2;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lend = ft_strlen(d);
	lens = ft_strlen(b);
	all = malloc(lend + lens + 1);
	if (all == 0)
		return (0);
	ft_strcpy1 (all, d);
	ft_strcpy1 (all + lend, b);
	all[lens + lend] = '\0';
	return (all);
}
