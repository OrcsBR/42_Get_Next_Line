#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd);

int main(void)
{
	char	*temp;
	int	fd;

	fd = open("lorem.txt", O_RDONLY);

	while(1)
	{
		temp = get_next_line(fd);
		if (!temp)
		break ;
		printf("%s", temp);
		free(temp);
	}
	return (0);
}
