#include <stdlib.h>
#include <limits.h>
#include <libft/libft.h>
#include "utils.h"
#include "stack.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*top;
	t_stack	*n;
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
	top = stk_swap(top);
	n = top;
	while (1)
	{
		if (n->v == 4)
			free(stk_pop(&n));
		n = stk_rrot(n);
		if (n == top)
			break;
	}
	while (1)
	{
		ft_putnbr_fd(n->v, 1);
		ft_putendl_fd("", 1);
		n = stk_rrot(n);
		if (n == top)
			break;
	}
}
