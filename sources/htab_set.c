#include <htab.h>

void	htab_set(t_htab *htab, t_dhtab *value)
{
	int		index;

	index = htab->hash(value->key) % htab->length_max;
	((t_dhtab **)htab->array)[index] = value;
	htab->length++;
}
