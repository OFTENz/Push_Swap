CC = cc  -Wall -Wextra -Werror 

H_SRC = Helpers/Enigma_Helper.c \
		Helpers/Free_Helpers.c \
		Helpers/OEnigma_Helper.c \
		Helpers/OOEnigmaHelper.c \
		Helpers/OOOHelpers.c \
		Helpers/SideKick.c \
		Helpers/Struct_Fixes.c \
		Helpers/array_Helpers.c \
		Helpers/method0.c \
		Helpers/split.c \
		Helpers/garbage_collector.c

C_SRC = Core.c \
		Enigma.c \
		Builders.c
		

HEADER = ./Helpers/pushswap.h


H_OBJ = $(H_SRC:.c=.o)

C_OBJ = $(C_SRC:.c=.o)

NAME = push_swap


all : $(NAME)

$(NAME) : $(H_OBJ) $(C_OBJ)

	$(CC) $(H_OBJ) $(C_OBJ) -o $(NAME)


%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean : cleanc
	rm -f $(H_OBJ) 

cleanc :
	rm -f $(C_OBJ)

re : fclean all 

fclean : clean

	rm -f $(NAME)
