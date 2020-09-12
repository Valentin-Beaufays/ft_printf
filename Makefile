CC =	gcc

NAME =	libftprintf.a

CFLAGS = -Werror -Wextra -Wall

LIB =	libft.a

FILES =	ft_printf.c\
		parser/parser.c\
		parser/parsing_utils.c\
		struct_utils.c\
		handler/handler.c\
		handler/handler_utils.c\
		handler/text_handler.c\
		handler/integer_handler.c\
		handler/unsigned_handler.c\
		writer/writer.c

OBJ =	$(FILES:.c=.o)

LIBFTPATH =	libft/

all: $(NAME)

$(NAME): $(OBJ) libft.a
	@cp $(LIBFTPATH)$(LIB) .
	@mv libft.a $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Done"

libft.a:
	@make -C $(LIBFTPATH) libft.a

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@make -C $(LIBFTPATH) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIBFTPATH) fclean
	@rm -f $(NAME)

re: fclean $(NAME)
