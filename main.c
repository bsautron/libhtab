#include <libhtab.h>

typedef struct	s_perso
{
	void 					*next;
	char					*key;
	char					*fname;
	char					*lname;
	unsigned int	age;
	char					*job;
}								t_perso;

int		main(void)
{
	t_htab	htab;
	t_perso	*me;
	t_perso	*she;
	t_perso	*getter;

	htab = HTAB_CREATE(100, &hash_pour_les_nuls);

	me = LIST_NEW(t_perso);
	me->key = ft_strdup("55555");
	me->lname = ft_strdup("Sautron");
	me->fname = ft_strdup("Bruno");
	me->age = 20;
	me->job = ft_strdup("Developer");

	she = LIST_NEW(t_perso);
	she->key = ft_strdup("45556");
	she->lname = ft_strdup("Termeau");
	she->fname = ft_strdup("Manue");
	she->age = 21;
	she->job = ft_strdup("Recruteur");

	HTAB_SET(&htab, me);
	HTAB_SET(&htab, she);
	getter = HTAB_GET(htab, t_perso, "45556");
	if (getter)
		ft_putendl(getter->job);
	else
		ft_putendl("not found");
	return(0);
}
