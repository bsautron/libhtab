#include <htab.h>

void	htab_set(t_htab *htab, t_dhtab *value)
{
	int		index;

	index = htab->hash(value->key) % htab->length_max;
	LIST_PUSH_BACK(&htab->array[index], value);
	htab->length++;
}
