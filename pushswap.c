#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <libft/libft.h>
#include "utils.h"
#include "stack.h"
#include "ilist.h"
#include "psops.h"

char	*stk_sort_triple(t_pile *a, char *instr)
{
	if (((a->t->v < a->t->next->v)
			+ (a->t->next->v < a->t->prev->v)
			+ (a->t->prev->v < a->t->v)) <= 1)
		instr = ps_swap(a, instr);
	if (a->t->v > a->t->next->v)
		instr = ps_rot(a, instr);
	else if (a->t->next->v > a->t->prev->v)
		instr = ps_rrot(a, instr);
	return (instr);
}

char	*stk_sort_new_block4(t_pile *a, t_pile *b, char *instr)
{
	instr = ps_push(b, a, instr);
	instr = ps_push(b, a, instr);
	a->i = ilst_add(a->i, 2);
	a->i->next->v -= 4;
	b->i = ilst_add(b->i, 2);
	if ((a->t->v > a->t->next->v) && (b->t->v < b->t->next->v))
		instr = ps_swap2(a, b, instr);
	if (a->t->v > a->t->next->v)
		instr = ps_swap(a, instr);
	if (b->t->v < b->t->next->v)		
		instr = ps_swap(b, instr);
	return (instr);
}

char	*stk_sort_new_block(t_pile *a, t_pile *b, char *instr)
{
	if (a->i->v >= 4)
		return (stk_sort_new_block4(a, b, instr));
	if (a->i->v == 3)
		instr = stk_sort_triple(a, instr);
	else if (a->i->v == 2 && a->t->v > a->t->next->v)
		instr = ps_swap(a, instr);
	a->i = ilst_add(a->i, a->i->v);
	a->i->next->v = 0;
	return (instr);
}

int	stk_sort_rewind(t_pile *a, int btop, int s, char **instr)
{
	int	ia;

	ia = a->i->v;
	if (a->i->next == 0 || a->i->next->v == 0)
	{
		fprintf(stderr, "%d # Elided rewind in stack %c\n", ia, 'A' + a->idx);
		return (0);
	}
	fprintf(stderr, "%d ! Rewinding in stack %c\n", ia, 'A' + a->idx);
	while (ia > 0 && s * a->t->v < s * btop)
	{
		*instr = ps_rot(a, *instr);
		--ia;
	}
	return (ia);
}

char	*stk_sort_merge_to_from(t_pile *a, t_pile *b, int s, char *instr)
{
	int	ia;
	int	ib;

	ia = stk_sort_rewind(a, b->t->v, s, &instr);
	ib = b->i->v;
	while (ia < a->i->v || ib > 0)
	{
		if (ib == 0)
			instr = ps_rrot(a, instr);
		else if (ia == a->i->v || s * a->t->prev->v < s * b->t->v)
		{
			instr = ps_push(a, b, instr);
			--ib;
			--ia;
		}
		else
			instr = ps_rrot(a, instr);
		++ia;
	}
	a->i->v += b->i->v;
	b->i = ilst_pop(b->i);
	return (instr);
}

char	*stk_sort_merge(t_pile *a, t_pile *b, char *instr)
{
	if (a->i->next == 0 || a->i->next->v == 0)
		return (stk_sort_merge_to_from(a, b, 1, instr));
	else if (b->i->next == 0)
		return (stk_sort_merge_to_from(b, a, -1, instr));
	else if (a->i->v + b->i->v >= b->i->next->v)
		return (stk_sort_merge_to_from(a, b, 1, instr));
	else
		return (stk_sort_merge_to_from(b, a, -1, instr));
}

t_stack	*stk_sort(t_stack *top, int n, char *instr)
{
	t_pile	a;
	t_pile	b;

	a.idx = 0;
	b.idx = 1;
	a.t = top;
	b.t = 0;
	b.i = 0;
	a.i = ilst_add(0, n);
	while (a.i->next == 0 || a.i->v != n)
	{
		// stk_print(a.t, "A: ");
		// stk_print(b.t, "B: ");
		if (a.i->next == 0)
			instr = stk_sort_new_block(&a, &b, instr);
		else
			instr = stk_sort_merge(&a, &b, instr);
	}
	stk_print(a.t, "A: ");
	stk_print(b.t, "B: ");
	*instr = 0;
	return (a.t);
}	

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*top;
	int		err;
	char	*np;
	char	*instr;
	int		clen;

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
	clen = 4 * argc * (ilog2(argc - 2) + 1);
	instr = malloc(clen);
	top = stk_sort(top, argc - 1, instr);
	printf("clen: %d\n", clen);
	printf("# instr: %ld\n", ft_strlen(instr));
	printf("instr:\n%s\n", instr);
}
