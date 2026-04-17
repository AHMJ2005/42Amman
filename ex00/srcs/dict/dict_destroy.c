#include <stdlib.h>
#include "dict.h"

void	dict_destroy(t_dict *dict)
{
	int	i;

	i = 0;
	while (i < dict -> size)
	{
		free(dict->keys[i]);
		free(dict->values[i]);
		i++;
	}
	free(dict);
}
