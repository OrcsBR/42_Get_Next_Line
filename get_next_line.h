/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peduardo < peduardo@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:02:11 by peduardo          #+#    #+#             */
/*   Updated: 2021/09/18 23:17:47 by peduardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

/**
 * @brief Reads a line from a file descriptor
 *
 * @param fd File descriptor to read.
 * @return Return a string including \\n if is a line. In case of the file
 * dont have \\n return a string without \\n, NULL if the file is empty
 * or error occurred.
 */
char	*get_next_line(int fd);

/**
 * @brief The strlen() function calculates the length of the string pointed to
 * by s, excluding the terminating null byte ('\0').
 * @param s The pointer to the string to be measured.
 * @return The ammount of bytes that makes up for the lenght of the string;
*/
size_t	ft_strlen(const char *s);

/**
* @brief The strdup() function returns a pointer to a new string which is a
* duplicate of the string s
* @param src, the pointer to string to be duplicated.
* @return pointer to the new string. It returns NULL if insufficient memory was
 available, with errno set to indicate the error.
*/
char	*ft_strdup(char *src);

/**
* @brief        The strchr() function returns a pointer to the first occurrence
* of the character c in the string s.
* @param s, the string to be matched upon.
* @param c, the char to match, passed as an int.
* @return pointer to the first occurrence of the character c in the string str,
or NULL if the character is not found.
*/
char	*ft_strchr(const char *s, int c);

/**
* @brief The ft_memmove() function copies n bytes from memory area src to the
* memory area dest. The memory areas may overlap, as the bytes in src are first
* copied into a temporary array that does not overlap src or dest, then copied
* over to dest.
* @param dest the pointer to the start of memory to receive the copied bytes
* @param src, the pointer to the start of memory area to be copied.
* @param n, length in bytes to be copied.
* @return pointer to dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of ’s1’ and ’s2’.
 * @param s1 the prefix string.
 * @param s2 the suffix string.
 * @return new string which is the concatenation of both above.
 */
char	*ft_strjoin(char const *s1, char const *s2);

#endif
