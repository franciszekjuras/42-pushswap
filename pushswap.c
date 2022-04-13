#include <limits.h>
#include <libft/libft.h>
#include "utils.h"

int	main(int argc, char **argv)
{
	int		i;
	int		*t;
	int		err;
	char	*np;

	i = 1;
	t = ft_calloc(argc - 1, sizeof(int));
	err = 0;
	while (i < argc)
	{
		np = argv[i];
		t[i - 1] = ft_strtonum(&np, INT_MIN, INT_MAX, &err);
		if (err || *np != '\0')
			error_exit();
		++i;
	}
	i = 0;
	while (i < argc - 1)
	{
		ft_putnbr_fd(t[i], 1);
		ft_putendl_fd("", 1);
		++i;
	}
}