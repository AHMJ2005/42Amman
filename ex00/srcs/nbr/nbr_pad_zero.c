#include <stdlib.h>

char	*nbr_pad_zero(char c, int zeros)
{
	char	*p;
	int		i;
	int		len;

	len = 1 + zeros;
	p = malloc(len + 1);
	p[0] = c;
	i = 1;
	while (i < len)
	{
		p[i] = '0';
		i++;
	}
	p[i] = '\0';
	return (p);
}
