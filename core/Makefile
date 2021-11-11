##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

NAME	=	arcade

ROOT	=	.
SRC_DIR	=	$(ROOT)/sources
SRCS	=	$(SRC_DIR)/Main.cpp\
			$(SRC_DIR)/Core.cpp
OBJS	=	$(SRCS:.cpp=.o)

CPPFLAGS=	-Iinclude

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CXX) -o $@ $(OBJS) -ldl
	-mkdir bin
	-cp $(NAME) bin/

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)
	$(RM) -rf bin

re:		fclean all

.PHONY:		re all fclean clean