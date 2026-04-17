#include "ft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	c;

	c = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[c] = src[i];
		c++;
		i++;
	}
	dest[c] = '\0';
	return (dest);
}
