############################## COMPILE VAR #####################################

CC			=	gcc
#CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	-g -Wall -Wextra -fsanitize=address,undefined
HDIR		=	includes
SRCDIR		=	src
HFLAGS		=	-I $(HDIR)
NAME		=	libft.a

############################## SOURCES #########################################

BINTDIR			=	bint
CHARDIR			=	char
FT_COLLECTORDIR	=	ft_collector
FT_GETOPTDIR	=	ft_getopt
FT_LSDIR		=	ft_ls
FT_PRINTFDIR	=	ft_printf
INTDIR			=	int
MEMORYDIR		=	memory
STRDIR			=	str
T_LSTDIR		=	t_lst
WTDIR			=	wt

SRCC			=	ft_swap_p.c\
					get_next_line.c\
					get_next_line_utils.c\

BINTC			=	bint_mathconsts.c\
					divide_bint.c\
					dragon4.c\
					log_and_ceil.c\
					multiply_bint.c\
					op_bint.c\
					pow_bint.c\
					shiftleft_bint.c\
					utility_bint.c\

CHARC			=	ft_isalnum.c\
					ft_isalpha.c\
					ft_isascii.c\
					ft_isdigit.c\
					ft_isprint.c\
					ft_putchar.c\
					ft_putchar_fd.c\
					ft_tolower.c\
					ft_toupper.c\

FT_COLLECTORC		=	ft_collector.c\
					ft_dir_collector.c\
					ft_exit.c\
					ft_heap_collector.c\
					ft_secmalloc.c\

FT_GETOPTC		=	ft_getopt.c\
					get_next_option_argument.c\
					get_short_option.c\
					getopt_errors.c\
					getopt_long_errors.c\
					init_getopt.c\
					permute_order.c\
					process_long_option.c\

FT_LSC			=	ft_ls_files.c\

FT_PRINTFC		=	basic_conversions.c\
					convert.c\
					convert_alloc.c\
					convert_pbuf.c\
					convert_str.c\
					efg_conversions.c\
					fetch.c\
					float_formats.c\
					format_data.c\
					format_data_utils.c\
					ft_asprintf.c\
					ft_bufprintf.c\
					ft_printf.c\
					ft_printf_utils.c\
					get_conv.c\
					get_flags.c\
					itoa.c\
					itoa_cast.c\
					itoa_signed.c\
					itoa_unsigned.c\
					parser.c\
					t_pbuf.c\
					t_pdata.c\
					t_pdata_stralloc.c\
					tab_conversion.c\
					uni_conversions.c\

INTC			=	ft_atoi.c\
					ft_atoi_forward.c\
					ft_intlen.c\
					ft_itoa.c\
					ft_putnbr.c\
					ft_putnbr_fd.c\
					ft_rand.c\

MEMORYC			=	ft_bzero.c\
					ft_memalloc.c\
					ft_memccpy.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_memcpy.c\
					ft_memdel.c\
					ft_memmove.c\
					ft_memset.c\

STRC			=	ft_putendl.c\
					ft_putendl_fd.c\
					ft_putstr.c\
					ft_putstr_fd.c\
					ft_stradd.c\
					ft_strcat.c\
					ft_strchr.c\
					ft_strclr.c\
					ft_strcmp.c\
					ft_strcpy.c\
					ft_strcut.c\
					ft_strdel.c\
					ft_strdup.c\
					ft_strequ.c\
					ft_striter.c\
					ft_striteri.c\
					ft_strjoin.c\
					ft_strlcat.c\
					ft_strlen.c\
					ft_strmap.c\
					ft_strmapi.c\
					ft_strncat.c\
					ft_strncmp.c\
					ft_strncpy.c\
					ft_strndup.c\
					ft_strnequ.c\
					ft_strnew.c\
					ft_strnstr.c\
					ft_strrchr.c\
					ft_strrm.c\
					ft_strsplit.c\
					ft_strstr.c\
					ft_strsub.c\
					ft_strtrim.c\

T_LSTC			=	ft_lst_at.c\
					ft_lst_discard.c\
					ft_lst_find.c\
					ft_lst_find_index.c\
					ft_lst_foreach.c\
					ft_lst_foreach_if.c\
					ft_lst_last.c\
					ft_lst_merge.c\
					ft_lst_move_back.c\
					ft_lst_move_front.c\
					ft_lst_move_to_back.c\
					ft_lst_move_to_front.c\
					ft_lst_pop.c\
					ft_lst_push_back.c\
					ft_lst_push_front.c\
					ft_lst_push_params.c\
					ft_lst_quicksort.c\
					ft_lst_remove_if.c\
					ft_lst_reverse.c\
					ft_lst_size.c\
					ft_lst_sort.c\
					ft_lst_sorted_insert.c\
					ft_lstadd.c\
					ft_lstdel.c\
					ft_lstdelone.c\
					ft_lstiter.c\
					ft_lstmap.c\
					ft_lstnew.c\

WTC				=	ft_print_words_tables.c\
					ft_print_words_tables_fd.c\
					ft_split_whitespaces.c\
					ft_wtdup.c\
					ft_wtfree.c\
					ft_wtlen.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(BINTC))\
					$(patsubst %.c,%.o,$(CHARC))\
					$(patsubst %.c,%.o,$(FT_COLLECTORC))\
					$(patsubst %.c,%.o,$(FT_GETOPTC))\
					$(patsubst %.c,%.o,$(FT_LSC))\
					$(patsubst %.c,%.o,$(FT_PRINTFC))\
					$(patsubst %.c,%.o,$(INTC))\
					$(patsubst %.c,%.o,$(MEMORYC))\
					$(patsubst %.c,%.o,$(STRC))\
					$(patsubst %.c,%.o,$(T_LSTC))\
					$(patsubst %.c,%.o,$(WTC))\
					$(patsubst %.c,%.o,$(SRCC))\

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.c	$(SRCDIR)/$(BINTDIR)
vpath			%.c	$(SRCDIR)/$(CHARDIR)
vpath			%.c	$(SRCDIR)/$(FT_COLLECTORDIR)
vpath			%.c	$(SRCDIR)/$(FT_GETOPTDIR)
vpath			%.c	$(SRCDIR)/$(FT_LSDIR)
vpath			%.c	$(SRCDIR)/$(FT_PRINTFDIR)
vpath			%.c	$(SRCDIR)/$(INTDIR)
vpath			%.c	$(SRCDIR)/$(MEMORYDIR)
vpath			%.c	$(SRCDIR)/$(STRDIR)
vpath			%.c	$(SRCDIR)/$(T_LSTDIR)
vpath			%.c	$(SRCDIR)/$(WTDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): $(ODIR) $(OBJ)
	ar rc $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ))
	ranlib $@

divide_bint.o: bint.h
dragon4.o: dragon4.h bint.h log_and_ceil.h
log_and_ceil.o: bint_mathconsts.h
multiply_bint.o: bint.h
op_bint.o: bint.h
pow_bint.o: bint.h bint_mathconsts.h
shiftleft_bint.o: bint.h
utility_bint.o: bint.h
ft_isalnum.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_isalpha.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_isascii.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_isdigit.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_isprint.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_putchar.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_putchar_fd.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_tolower.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_toupper.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_collector.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_dir_collector.o: ft_collector.h
ft_exit.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_heap_collector.o: ft_collector.h
ft_secmalloc.o: ft_collector.h
ft_getopt.o: get_next_option_argument.h ft_getopt.h get_short_option.h
get_next_option_argument.o: permute_order.h ft_getopt.h process_long_option.h\
	libft.h ft_printf.h t_pbuf.h ft_collector.h
get_short_option.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h\
	getopt_errors.h
getopt_errors.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
getopt_long_errors.o: getopt_errors.h ft_getopt.h libft.h ft_printf.h t_pbuf.h\
	ft_collector.h
init_getopt.o: ft_getopt.h
permute_order.o: ft_getopt.h
process_long_option.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h\
	getopt_errors.h
ft_ls_files.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
basic_conversions.o: fetch.h t_farg.h libft.h ft_getopt.h ft_printf.h t_pbuf.h\
	ft_collector.h itoa_unsigned.h t_pdata.h t_params.h
convert.o: conversions.h t_farg.h t_pdata.h t_params.h format_data.h t_pbuf.h\
	libft.h ft_getopt.h ft_printf.h ft_collector.h
convert_alloc.o: conversions.h t_farg.h t_pdata.h t_params.h format_data.h\
	t_pbuf.h libft.h ft_getopt.h ft_printf.h ft_collector.h
convert_pbuf.o: conversions.h t_farg.h t_pdata.h t_params.h format_data.h\
	t_pbuf.h libft.h ft_getopt.h ft_printf.h ft_collector.h
convert_str.o: conversions.h t_farg.h t_pdata.h t_params.h format_data.h\
	t_pbuf.h libft.h ft_getopt.h ft_printf.h ft_collector.h
efg_conversions.o: fetch.h t_farg.h t_params.h log_and_ceil.h float_formats.h\
	t_pdata.h dragon4.h
fetch.o: fetch.h t_farg.h t_params.h
float_formats.o: ft_printf_utils.h t_pdata.h dragon4.h t_params.h
format_data.o: format_data_utils.h t_pdata.h t_params.h format_data.h t_pbuf.h\
	libft.h ft_getopt.h ft_printf.h ft_collector.h
format_data_utils.o: format_data.h t_params.h t_pdata.h t_pbuf.h libft.h\
	ft_getopt.h ft_printf.h ft_collector.h
ft_asprintf.o: parser.h t_farg.h t_pbuf.h t_pdata.h t_params.h libft.h\
	ft_getopt.h ft_printf.h ft_collector.h
ft_bufprintf.o: t_pbuf.h parser.h t_farg.h t_pdata.h t_params.h libft.h\
	ft_getopt.h ft_printf.h ft_collector.h
ft_printf.o: parser.h t_farg.h t_pbuf.h t_pdata.h t_params.h libft.h\
	ft_getopt.h ft_printf.h ft_collector.h
get_conv.o: get_flags.h t_farg.h t_params.h libft.h ft_getopt.h ft_printf.h\
	t_pbuf.h ft_collector.h
get_flags.o: t_params.h fetch.h t_farg.h libft.h ft_getopt.h ft_printf.h\
	t_pbuf.h ft_collector.h
itoa.o: fetch.h t_farg.h itoa_signed.h t_pdata.h itoa_unsigned.h t_params.h
itoa_cast.o: itoa.h t_farg.h t_params.h t_pdata.h
itoa_signed.o: itoa_signed.h t_pdata.h
itoa_unsigned.o: itoa_unsigned.h t_pdata.h t_params.h
parser.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h get_conv.h\
	t_farg.h t_params.h convert.h t_pdata.h
t_pbuf.o: t_pbuf.h libft.h ft_getopt.h ft_printf.h ft_collector.h
t_pdata.o: t_pdata.h libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
t_pdata_stralloc.o: t_pdata.h libft.h ft_getopt.h ft_printf.h t_pbuf.h\
	ft_collector.h
tab_conversion.o: get_conv.h t_farg.h t_params.h parser.h t_pbuf.h t_pdata.h\
	fetch.h libft.h ft_getopt.h ft_printf.h ft_collector.h
uni_conversions.o: fetch.h t_farg.h t_pdata.h t_params.h
get_next_line.o: get_next_line.h libft.h ft_getopt.h ft_printf.h t_pbuf.h\
	ft_collector.h
get_next_line_utils.o: get_next_line.h libft.h ft_getopt.h ft_printf.h\
	t_pbuf.h ft_collector.h
ft_atoi.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_itoa.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_putnbr.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_putnbr_fd.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_bzero.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_memalloc.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_memccpy.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_memchr.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_memcmp.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_memcpy.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_memdel.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_memmove.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_memset.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_putendl.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_putendl_fd.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_putstr.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_putstr_fd.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_stradd.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strcat.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strchr.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strclr.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strcmp.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strcpy.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strcut.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strdel.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strdup.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strequ.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_striter.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_striteri.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strjoin.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strlcat.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strlen.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strmap.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strmapi.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strncat.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strncmp.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strncpy.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strndup.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strnequ.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strnew.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strnstr.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strrchr.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strrm.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strsplit.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strstr.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strsub.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_strtrim.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_at.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_discard.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_find.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_find_index.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_foreach.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_foreach_if.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_last.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_merge.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_move_back.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_move_front.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_move_to_back.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_move_to_front.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h\
	ft_collector.h
ft_lst_pop.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_push_back.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_push_front.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_push_params.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_quicksort.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_remove_if.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_reverse.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_size.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_sort.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lst_sorted_insert.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h\
	ft_collector.h
ft_lstadd.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lstdel.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lstdelone.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lstiter.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lstmap.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_lstnew.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_print_words_tables.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h\
	ft_collector.h
ft_print_words_tables_fd.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h\
	ft_collector.h
ft_split_whitespaces.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h\
	ft_collector.h
ft_wtdup.o: libft.h ft_getopt.h ft_printf.h t_pbuf.h ft_collector.h
ft_wtfree.o: ft_collector.h
%.o: %.c
	@mkdir -p $(ODIR)
	$(CC) -c $(CFLAGS) $< $(HFLAGS) -o $(ODIR)/$@

$(ODIR):
	mkdir -p $@

############################## CLEANUP #########################################

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
