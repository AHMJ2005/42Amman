#include <unistd.h>
#include "ft.h"

void	ft_error(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}
