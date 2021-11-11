##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

NAME	=	lib_arcade_sfml.so

ROOT	=	.
SRCS_DIR	=	$(ROOT)/sources
SRCS	=	$(SRCS_DIR)/Main.cpp
OBJS	=	$(SRCS:.cpp=.o)

CPPFLAGS=	-fPIC -Iinclude -lsfml-graphics -lsfml-window -lsfml-system

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) -shared -o $@ $(OBJS) -lsfml-graphics -lsfml-window -lsfml-system
	-cp $(NAME) ../bin/
	-cp -r assets/* ../assets

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean
