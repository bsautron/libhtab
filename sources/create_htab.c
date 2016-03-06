#include <htab.h>


t_htab		create_htab(int length_max, int (*hash)(char *s))
{
	t_htab		htab;

	ft_bzero(&htab, sizeof(t_htab));
	htab.length_max = length_max;
	htab.hash = hash;
	htab.array = (t_plist **)malloc(sizeof(t_plist *) * length_max);
	return (htab);
}
