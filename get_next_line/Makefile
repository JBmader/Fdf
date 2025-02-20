# **************************************************************************** #
#                                VARIABLES                                    #
# **************************************************************************** #

NAME            = libgnl.a
CC              = cc
CFLAGS          = -Wall -Wextra -Werror -fPIC
AR              = ar rcs
RM              = rm -f
LDLIBS += -L$(LIBFT_DIR) -lft

SRCS            = get_next_line.c

BONUS_SRCS      = get_next_line_bonus.c \
                  get_next_line_utils_bonus.c

OBJS            = $(SRCS:.c=.o)
BONUS_OBJS      = $(BONUS_SRCS:.c=.o)

LIBFT_DIR       = ../libft
LIBFT_A         = $(LIBFT_DIR)/libft.a

# **************************************************************************** #
#                                RULES                                        #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(AR) $(NAME) $(OBJS)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

bonus: $(BONUS_OBJS) $(LIBFT_A)
	$(AR) $(NAME) $(BONUS_OBJS) $(LIBFT_A)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
