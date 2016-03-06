#include <htab.h>

t_dhtab	*htab_get(t_htab htab, char *key)
{
	t_dhtab		*tmp;

	tmp = ((t_dhtab **)htab.array)[htab.hash(key) % htab.length_max];
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
