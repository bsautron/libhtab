#include <htab.h>

typedef struct	s_perso
{
	void			*next;
	char			*key;
	char			*fname;
	char			*lname;
	unsigned int	age;
	char			*job;
}				t_perso;

int		main(void)
{
	t_htab	htab;
	t_perso	*me;

	ft_bzero(&htab, sizeof(t_htab));

	htab.hash = &hash_pour_les_nuls;
	htab.length_max = 100;
	htab.array = (t_perso **)malloc(sizeof(t_perso *) * htab.length_max);

	me = LIST_NEW(t_perso);
	
	me->key = ft_strdup("Bruno");
	me->lname = ft_strdup("Sautron");
	me->fname = ft_strdup("Bruno");
	me->age = 20;
	me->job = ft_strdup("Developer");

	HTAB_SET(&htab, me);
	dprintf(1, "%s\n", ((t_perso *)htab_get(htab, "Bruno"))->job);
	return(0);
}
