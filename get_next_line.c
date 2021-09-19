/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peduardo < peduardo@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:55:59 by peduardo          #+#    #+#             */
/*   Updated: 2021/09/19 03:35:18 by peduardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	partwrite_action(char **result_line, char *curr_read, int i)
{
	char	*aux;
	char	holder;

	if (!result_line)
	{
		holder = curr_read[i++];
		curr_read[i] = '\0';
		*result_line = ft_strjoin(curr_read, "");
		curr_read[i] = holder;
	}
	else
	{
		holder = curr_read[i++];
		curr_read[i] = '\0';
		aux = ft_strdup(*result_line);
		*result_line = ft_strjoin(aux, curr_read);
		curr_read[i] = holder;
		free(aux);
	}
}

static void	partwrite(char *curr_read, char **result_line, int *bytes_read)
{
	int	i;

	i = 0;
	while(curr_read[i] != '\n' && curr_read[i])
		i++;
	if(!curr_read[i])
		partwrite_action(&result_line, curr_read, i);
	else
	{
		partwrite_action(&result_line, curr_read, i);
		*bytes_read = 0;
	}
	i++;
	curr_read = ft_memmove(curr_read, curr_read[i], BUFFER_SIZE - i); //aqui tinha que ser o endereço de curr_read[i] (&curr_read[i]) - deixa pro debug! E SEM A ATRIBUIÇÃO NO COMEÇO POIS CURR_READ É UMA CONST STRING
	curr_read[BUFFER_SIZE - i] = '\0';
}

static void	fullwrite(char *curr_read, char **result_line)
{
	char	*aux;

	if (!result_line)
		*result_line = ft_strjoin(curr_read, "");
	else
	{
		aux = ft_strdup(*result_line);
		*result_line = ft_strjoin(aux, curr_read);
		free(aux);
	}
	curr_read[0] = '\0';
}

char	*get_next_line(int fd)
{
	static char	*curr_read; //diff
	char		*result_line;
	int			bytes_read;

	result_line = NULL;
	if (*curr_read)
		partwrite(curr_read, &result_line, &bytes_read);
	curr_read = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1); // diff
	if (!curr_read)
		return (NULL);
	bytes_read = 1;
	while(bytes_read)
	{
		bytes_read = read(fd, curr_read, BUFFER_SIZE);
		curr_read[BUFFER_SIZE + 1] = '\0'; //aqui eu errei, é [bytes_read], é claro, pois o bytes_read pode ser menor - mas deixa ir pro debug. E não precisa do +1 tmb. Faltou tmb a proteção de retorno de erro (-1) de read, acima. Ver código do JoFelipe.
		if (bytes_read == BUFFER_SIZE && !ft_strchr(curr_read, '\n'))
			fullwrite(curr_read, &result_line);
		else if (bytes_read != BUFFER_SIZE || ft_strchr(curr_read, '\n'))
			partwrite(curr_read, &result_line, &bytes_read);
	}
	return (result_line);
}
