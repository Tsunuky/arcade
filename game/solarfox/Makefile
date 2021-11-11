##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

NAME	=	lib_arcade_solarfox.so

ROOT	=	.
SRCS_DIR	=	$(ROOT)/sources
SRCS	=	$(SRCS_DIR)/Main.cpp
OBJS	=	$(SRCS:.cpp=.o)

CPPFLAGS=	-fPIC -Iinclude

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) -shared -o $@ $(OBJS)
	-cp $(NAME) ../bin/

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean
