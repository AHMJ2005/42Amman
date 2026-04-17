#include "dict.h"
#include "ft.h"

char	*dict_get(t_dict *dict, char *key)
{
	int	i;

	i = 0;
	while (i < dict->size)
	{
		if (ft_strcmp(key, dict->keys[i] == 0))
			return (dict->values[i]);
		i++;
	}
	return (0);
}
