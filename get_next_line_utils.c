/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peduardo < peduardo@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:01:14 by peduardo          #+#    #+#             */
/*   Updated: 2021/09/22 21:50:36 by peduardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == 0)
		return (0);
	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*src_copy;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	src_copy = (char *) malloc(sizeof(char) * (len + 1));
	if (!(src_copy))
		return (NULL);
	while (i < len)
	{
		src_copy[i] = src[i];
		i++;
	}
	src_copy[i] = '\0';
	return (src_copy);
}

char	*ft_strchr(const char *s, int c)
{
	char	*s_ptr;
	char	ch;

	if (!s)
		return (NULL);
	s_ptr = (char *)s;
	ch = (char)c;
	while (*s_ptr)
	{
		if (*s_ptr == ch)
			return (s_ptr);
		s_ptr++;
	}
	if (*s_ptr == ch)
		return (s_ptr);
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dest;
	if (src == NULL && dest == NULL)
		return (dest);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
		return (dest);
	}
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (s1[i])
		result[j++] = s1[i++];
	i = 0;
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = '\0';
	return (result);
}
