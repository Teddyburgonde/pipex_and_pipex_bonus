NAME = pipex

SRCS = main_bonus.c heredoc_bonus.c parsing_bonus.c paths_bonus.c open_files_bonus.c process_bonus.c \
	get_next_line.c get_next_line_utils.c ft_memset.c \
	ft_calloc.c ft_split.c ft_strncmp.c ft_free_and_close.c ft_strlcpy.c ft_putstr_fd.c ft_array_len.c ft_strjoin.c ft_strdup.c

OBJS=$(SRCS:.c=.o)

RM=rm -f

CC= clang

CFLAGS= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation successful!\033[0m"; \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@$(RM) $(OBJS)
fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
