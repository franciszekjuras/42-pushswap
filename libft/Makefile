NAME = libft.a

FILES = \
	ft_alloc ft_mapi ft_math ft_membase ft_memcmp ft_memcpy ft_put \
	ft_strbase ft_strcase ft_strcmp ft_strcpy ft_strdup ft_stris \
	ft_stris2 ft_strmpl ft_putn ft_strtoll_e ft_strtoll_e_utils \
	ft_strtoull_e ft_strtonum ft_atoi ft_itoa ft_swap

OFILES = $(FILES:%=%.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $@ $?

$(OFILES): %.o: %.c
	gcc $(CFLAGS) $(OPTIM) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
