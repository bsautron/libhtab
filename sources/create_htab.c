#include <htab.h>


t_htab		create_htab(int length_max, int (*fn_hash)(char *s))
{
	t_htab		htab;

	ft_bzero(&htab, sizeof(t_htab));
	htab.length_max = length_max;
	htab.hash = fn_hash;
	htab.array = (t_dhtab **)malloc(sizeof(t_dhtab *) * length_max);
	return (htab);
}
