#ifndef HTAB_H
# define HTAB_H

# include <libft.h>
# include <liblist.h>
# include <stdio.h>//

# define HTAB_CREATE(Y, Z)	create_htab(Z, Y);
# define HTAB_SET(Y, Z)			htab_set(Y, (t_dhtab *)Z);
# define HTAB_GET(X, Y, Z)	(Y *)htab_get(X, Z);

typedef struct	s_dhtab
{
	void		*next;
	char		*key;
}				t_dhtab;

typedef struct	s_htab
{
	t_dhtab	**array;
	char		*type;
	int			length;
	int			length_max;
	int			(*hash)(char *);
}				t_htab;

int		hash_pour_les_nuls(char *s);
t_htab	create_htab(int length_max, int (*hash)(char *));
void	htab_set(t_htab *htab, t_dhtab *value);
t_dhtab	*htab_get(t_htab htab, char *key);

#endif
