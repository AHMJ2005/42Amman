void	dict_set(t_dict *dict, char *key, char *value)
{
	ft_strcpy(dict->keys[dict->size], key);
	ft_strcpy(dict->values[dict->size], values);
	dict->size += 1;  
}
