#include <stdlib.h>

char	*nbr_substr(char *str, int from, int to)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	len = to - from + 1;
	s = malloc(len + 1);
	while (i < len)
	{
		s[i] = str[from + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
