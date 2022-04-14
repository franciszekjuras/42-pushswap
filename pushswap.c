#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <libft/libft.h>
#include "utils.h"
#include "stack.h"
#include "ilist.h"

void	stk_sort_triple(t_pile *a)
{
	if (((a->t->v < a->t->next->v)
			+ (a->t->next->v < a->t->prev->v)
			+ (a->t->prev->v < a->t->v)) <= 1)
		a->t = stk_swap(a->t);
	if (a->t->v > a->t->next->v)
		a->t = stk_rot(a->t);
	else if (a->t->next->v > a->t->prev->v)
		a->t = stk_rrot(a->t);
}

void	stk_sort_new_block4(t_pile *a, t_pile *b)
{
	b->t = stk_push(b->t, stk_pop(&a->t));
	b->t = stk_push(b->t, stk_pop(&a->t));
	a->i = ilst_add(a->i, 2);
	a->i->next->v -= 4;
	b->i = ilst_add(b->i, 2);
	if (a->t->v > a->t->next->v)
		a->t = stk_swap(a->t);
	if (b->t->v < b->t->next->v)
		b->t = stk_swap(b->t);
}

void	stk_sort_new_block(t_pile *a, t_pile *b)
{
	if (a->i->v >= 4)
		return (stk_sort_new_block4(a, b));
	if (a->i->v == 3)
		stk_sort_triple(a);
	else if (a->i->v == 2 && a->t->v > a->t->next->v)
		a->t = stk_swap(a->t);
	a->i = ilst_add(a->i, a->i->v);
	a->i->next->v = 0;
}

int	stk_sort_rewind(t_pile *a, int btop, int s)
{
	int	ia;

	if (a->i->next == 0 || a->i->next->v == 0)
		return (0);
	ia = a->i->v;
	while (ia > 0 && s * a->t->v < s * btop)
	{
		a->t = stk_rot(a->t);
		--ia;
	}
	return (ia);
}

void	stk_sort_merge_to_from(t_pile *a, t_pile *b, int s)
{
	int	ia;
	int	ib;

	ia = stk_sort_rewind(a, b->t->v, s);
	ib = b->i->v;
	while (ia < a->i->v || ib > 0)
	{
		if (ib == 0)
			a->t = stk_rrot(a->t);
		else if (ia == a->i->v || s * a->t->prev->v < s * b->t->v)
		{
			a->t = stk_push(a->t, stk_pop(&b->t));
			--ib;
			--ia;
		}
		else
			a->t = stk_rrot(a->t);
		++ia;
	}
	a->i->v += b->i->v;
	b->i = ilst_pop(b->i);
}

void	stk_sort_merge(t_pile *a, t_pile *b)
{
	if (a->i->next == 0 || a->i->next->v == 0)
		stk_sort_merge_to_from(a, b, 1);
	else if (b->i->next == 0)
		stk_sort_merge_to_from(b, a, -1);
	else if (a->i->v + b->i->v >= b->i->next->v)
		stk_sort_merge_to_from(a, b, 1);
	else
		stk_sort_merge_to_from(b, a, -1);
}

t_stack	*stk_sort(t_stack *top, int n)
{
	t_pile	a;
	t_pile	b;

	a.t = top;
	b.t = 0;
	b.i = 0;
	a.i = ilst_add(0, n);
	while (a.i->next == 0 || a.i->v != n)
	{
		stk_print(a.t, "A: ");
		stk_print(b.t, "B: ");
		if (a.i->next == 0)
			stk_sort_new_block(&a, &b);
		else
			stk_sort_merge(&a, &b);
	}
	stk_print(a.t, "A: ");
	stk_print(b.t, "B: ");
	return (a.t);
}	

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*top;
	int		err;
	char	*np;

	i = 1;
	top = 0;
	err = 0;
	while (i < argc)
	{
		np = argv[i];
		top = stk_pushbck(top,
				stk_new(ft_strtonum(&np, INT_MIN, INT_MAX, &err)));
		if (err || *np != '\0')
			error_exit();
		++i;
	}
	top = stk_sort(top, argc - 1);
}
