##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

NAME	=	lib_arcade_sdl.so

ROOT	=	.
SRCS_DIR	=	$(ROOT)/sources
SRCS	=	$(SRCS_DIR)/Main.cpp
OBJS	=	$(SRCS:.cpp=.o)

CPPFLAGS=	-fPIC -Iinclude -lSDL2 -lSDL_image -lSDL2_ttf -lSDL_ttf -lSDL

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) -shared -o $@ $(OBJS) -lSDL2 -lSDL2_ttf -lSDL_ttf -lSDL
	-cp $(NAME) ../bin/
	-cp -r assets/* ../assets

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean
