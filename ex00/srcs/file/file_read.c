
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft.h"

#define BUF_SIZE 4096


//return returns the size of the file (bytes)
ssize_t	file_size(char *file)
{
	ssize_t	bytes_read;
	char	buffer[BUF_SIZE];
	int		fd;

	fd = open(file, O_RDONLY);
	bytes_read = read(fd, buffer, BUF_SIZE);
	close (fd);
	return (bytes_read);
}
//return str read from the file
char	*file_read(char *file)
{
	int		fd;
	char	*buffer;
	ssize_t	bytes_read;

	bytes_read = file_size(file);
	if (bytes_read == -1)
	{
		ft_error("Error\n");
		return (NULL);
	}
	fd = open(file, O_RDONLY);
	buffer = (char *)malloc(bytes_read);
	bytes_read = read(fd, buffer, bytes_read);
	if (bytes_read == -1)
	{
		ft_error("Error\n");
		close(fd);
		return (NULL);
	}
	close(fd);
	return (buffer);
}
