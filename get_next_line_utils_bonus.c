/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:48:40 by yeham             #+#    #+#             */
/*   Updated: 2022/08/23 19:33:46 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	j = gnl_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (j + 1));
	if (s2 == NULL)
		return (0);
	while (i < j)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*sc;

	if (s1 == 0 || s2 == 0)
		return (0);
	j = 0;
	i = 0;
	sc = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (sc == NULL)
		return (0);
	while (s1[i])
	{
		sc[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		sc[i + j] = s2[j];
		j++;
	}
	sc[i + j] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (sc);
}
