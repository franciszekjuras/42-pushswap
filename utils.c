#include <stdlib.h>
#include <limits.h>
#include <libft/libft.h>
#include "stack.h"
#include "psops.h"

void	error_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	ilog2(int n)
{
	int	r;

	r = 0;
	while (n > 1)
	{
		n = n >> 1;
		++r;
	}
	return (r);
}

t_stack	*stk_parse(char **argv, int n)
{
	int		i;
	t_stack	*top;
	int		err;
	char	*np;

	i = 0;
	top = 0;
	err = 0;
	while (i < n)
	{
		np = argv[i];
		top = stk_pushbck(top,
				stk_new(ft_strtonum(&np, INT_MIN, INT_MAX, &err)));
		if (err || *np != '\0')
			error_exit();
		++i;
	}
	return (top);
}

int	stk_check_rep_sorted(t_stack *top)
{
	t_stack	*n;

	if (top == 0)
		return (0);
	n = top;
	while (n->next != top)
	{
		if (n->v >= n->next->v)
			return (1);
		n = n->next;
	}
	return (0);
}

void	instr_print(char *instr)
{
	while (*(++instr) != '\0')
	{
		if (*instr == PA)
			ft_putendl_fd(PA_STR, 1);
		else if (*instr == PB)
			ft_putendl_fd(PB_STR, 1);
		else if (*instr == SA)
			ft_putendl_fd(SA_STR, 1);
		else if (*instr == SB)
			ft_putendl_fd(SB_STR, 1);
		else if (*instr == RA)
			ft_putendl_fd(RA_STR, 1);
		else if (*instr == RB)
			ft_putendl_fd(RB_STR, 1);
		else if (*instr == RRA)
			ft_putendl_fd(RRA_STR, 1);
		else if (*instr == RRB)
			ft_putendl_fd(RRB_STR, 1);
		else if (*instr == SS)
			ft_putendl_fd(SS_STR, 1);
		else if (*instr == RR)
			ft_putendl_fd(RR_STR, 1);
		else if (*instr == RRR)
			ft_putendl_fd(RRR_STR, 1);
	}
}
