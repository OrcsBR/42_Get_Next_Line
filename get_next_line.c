/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peduardo < peduardo@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:55:59 by peduardo          #+#    #+#             */
/*   Updated: 2021/09/25 11:12:58 by peduardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	partwrite_action(char **result_line, char *curr_read, int i)
{
	char	*aux;
	char	holder;

	if (!*result_line)
	{
		holder = curr_read[i + 1];
		curr_read[i + 1] = '\0';
		*result_line = ft_strjoin(curr_read, "");
		curr_read[i + 1] = holder;
	}
	else
	{
		holder = curr_read[i + 1];
		curr_read[i + 1] = '\0';
		aux = *result_line;
		*result_line = ft_strjoin(aux, curr_read);
		curr_read[i + 1] = holder;
		free(aux);
	}
}

static void	partwrite(char *curr_read, char **result_line, int *bytes_read)
{
	int	i;

	i = 0;
	while (curr_read[i] != '\n' && curr_read[i])
		i++;
	if (!curr_read[i])
		partwrite_action(result_line, curr_read, i);
	else if (curr_read[i] == '\n')
	{
		partwrite_action(result_line, curr_read, i);
		*bytes_read = 0;
	}
	i++;
	ft_memmove(curr_read, &curr_read[i], BUFFER_SIZE - i);
	curr_read[BUFFER_SIZE - i] = '\0';
	//printf("%s is the string", curr_read);
}

static void	fullwrite(char *curr_read, char **result_line)
{
	char	*aux;

	if (!*result_line)
		*result_line = ft_strjoin(curr_read, "");
	else
	{
		aux = *result_line;
		*result_line = ft_strjoin(aux, curr_read);
		free(aux);
	}
	curr_read[0] = '\0';
	//printf("%s is the string", curr_read);
}

char	*get_next_line(int fd)
{
	static char	curr_read[BUFFER_SIZE + 1];
	char		*result_line;
	int			bytes_read;

	result_line = NULL;
	bytes_read = 1;
	if (*curr_read)
		partwrite(curr_read, &result_line, &bytes_read);
	while (bytes_read)
	{
		bytes_read = read(fd, curr_read, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		curr_read[bytes_read] = '\0';
		if (bytes_read == BUFFER_SIZE && !ft_strchr(curr_read, '\n'))
			fullwrite(curr_read, &result_line);
		else if (bytes_read)
			partwrite(curr_read, &result_line, &bytes_read);
	}
	return (result_line);
}
