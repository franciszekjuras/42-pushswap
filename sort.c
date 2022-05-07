#include "ilist.h"
#include "stack.h"
#include "psops.h"
#include "sort.h"
#include "utils.h"

static char	*stk_sort_triple(t_pile *a, char *instr)
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

int stk_check_asort(t_pile *a)
{
	int		atop;
	int		abase;
	t_stack	*pos;

	pos = a->t;
	atop = 1;
	abase = a->i->v - 1;
	while(abase > 0 && pos->v <= pos->next->v)
	{
		pos = pos->next;
		++atop;
		--abase;
	}
	if (atop >= 4)
	{
		a->i->v = abase;
		a->i = ilst_add(a->i, atop);
		return (1);
	}
	return (0);
}

static char	*stk_sort_new_block4(t_pile *a, t_pile *b, char *instr)
{
	if (stk_check_asort(a))
		return (instr);
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

static char	*stk_sort_new_block(t_pile *a, t_pile *b, char *instr)
{
	if (a->i->v >= 4)
		return (stk_sort_new_block4(a, b, instr));
	else if (a->i->v == 3)
		instr = stk_sort_triple(a, instr);
	else if (a->i->v == 2 && a->t->v > a->t->next->v)
		instr = ps_swap(a, instr);
	a->i = ilst_add(a->i, a->i->v);
	a->i->next->v = 0;
	return (instr);
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
		if (a.i->next == 0)
			instr = stk_sort_new_block(&a, &b, instr);
		else
			instr = stk_sort_merge(&a, &b, instr);
	}
	*instr = 0;
	ilst_clear(a.i);
	ilst_clear(b.i);
	return (a.t);
}	
