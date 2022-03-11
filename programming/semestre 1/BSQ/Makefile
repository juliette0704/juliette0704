##                                                                                  
## EPITECH PROJECT, 2021                                                            
## Makefile                                                                        
## File description:                                                                
## task01                                                                          
##                                                                                  

CFLAGS  =       -I./include -lmy -L./lib

NAME    =       bsq

SRC     =       BSQ.c

OBJ     =       $(SRC:.c=o)

all:            $(SRC)
	make -C ./lib/my/

	gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my

re: fclean all
