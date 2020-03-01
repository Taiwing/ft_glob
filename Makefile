############################## COMPILE VAR #####################################

CC			=	gcc
#CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	-g -Wall -Wextra -Werror -fsanitize=address,undefined
HDIR		=	includes
SRCDIR		=	src
SUB1D		=	libft
HFLAGS		=	-I $(HDIR) -I $(SUB1D)/$(HDIR)
LIBS		=	$(SUB1D)/libft.a
NAME		=	fnmatchtest

############################## SOURCES #########################################

FT_FNMATCHDIR	=	ft_fnmatch

SRCC			=	test_fnmatch.c\
					main.c\

FT_FNMATCHC		=	ft_fnmatch.c\
					g_char_classes.c\
					match_brack.c\
					match.c\
					char_class_functions_2.c\
					char_class_functions_3.c\
					char_class_functions_1.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(FT_FNMATCHC))\
					$(patsubst %.c,%.o,$(SRCC))\

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.h	$(SUB1D)/$(HDIR)
vpath			%.c	$(SRCDIR)/$(FT_FNMATCHDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): $(SUB1D)/libft.a $(ODIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ)) $(LIBS)

$(SUB1D)/libft.a:
	make -C $(SUB1D)

ft_fnmatch.o: ft_fnmatch.h ft_fnmatch_internal.h
g_char_classes.o: libft.h g_char_classes.h
match_brack.o: libft.h g_char_classes.h ft_fnmatch_internal.h
match.o: libft.h ft_fnmatch.h ft_fnmatch_internal.h
test_fnmatch.o: c_colors.h ft_fnmatch.h
%.o: %.c
	@mkdir -p $(ODIR)
	$(CC) -c $(CFLAGS) $< $(HFLAGS) -o $(ODIR)/$@

$(ODIR):
	mkdir -p $@

############################## CLEANUP #########################################

clean:
	rm -rf $(ODIR)
	make -C $(SUB1D) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
