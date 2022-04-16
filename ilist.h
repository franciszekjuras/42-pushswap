#ifndef ILIST_H
# define ILIST_H

typedef struct s_ilist	t_ilist;

struct s_ilist
{
	int		v;
	t_ilist	*next;
};

t_ilist	*ilst_pop(t_ilist *front);
t_ilist	*ilst_add(t_ilist *front, int v);
t_ilist	*ilst_clear(t_ilist *front);

#endif