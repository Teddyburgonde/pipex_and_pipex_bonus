#=================== NAME ===================#
NAME = pipex


#================ COMPILATOR ================#
CC= clang


#=================== FLAGS ==================#
CFLAGS= -Wall -Wextra -Werror -I. -g


#============= MANDATORY SOUCES =============#
SRCS = 	mandatory/main.c \
		mandatory/free.c \
		mandatory/open.c \
		mandatory/path.c \
		mandatory/process.c \
		mandatory/verif_and_error.c


#=============== BONUS SOURCES ==============#
SRCS_BONUS = 	pipex_bonus/ft_array_len_bonus.c \
				pipex_bonus/ft_calloc_bonus.c \
				pipex_bonus/ft_free_and_close_bonus.c \
				pipex_bonus/ft_memset_bonus.c \
				pipex_bonus/ft_putstr_fd_bonus.c \
				pipex_bonus/ft_split_bonus.c \
				pipex_bonus/ft_strdup_bonus.c \
				pipex_bonus/ft_strjoin_bonus.c \
				pipex_bonus/ft_strlcpy_bonus.c \
				pipex_bonus/ft_strlen_bonus.c \
				pipex_bonus/ft_strncmp_bonus.c \
				pipex_bonus/get_next_line_bonus.c \
				pipex_bonus/get_next_line_utils_bonus.c \
				pipex_bonus/heredoc_bonus.c \
				pipex_bonus/main_bonus.c \
				pipex_bonus/open_files_bonus.c \
				pipex_bonus/parsing_bonus.c \
				pipex_bonus/paths_bonus.c \
				pipex_bonus/process_bonus.c

#============ TRANSFORM .c TO .o ============#
#============== MANDATORY PART ==============#
OBJS=$(SRCS:.c=.o)

#================ BONUS PART ================#
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

#=============== INCLUDES PART ==============#
INCLUDES = -I mandatory/ -I $(LIBFT_DIR)
INCLUDES_BONUS = -I pipex_bonus/ -I $(LIBFT_DIR)

#================ LIBFT PART ================#
LIBFT_DIR = mandatory/libft
LIBFT = $(LIBFT_DIR)/libft.a

#================ UTILS PART ================#
RM=rm -f


all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

bonus : $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) $(OBJS_BONUS) $(LIBFT) -o $(NAME)

clean: 
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus
