##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

LIB1	=	ncurses
LIB2	=	sfml
LIB3	=	sdl

all:
	-mkdir bin
	-mkdir assets
	$(MAKE) -C $(LIB1)
	$(MAKE) -C $(LIB2)
	$(MAKE) -C $(LIB3)
	-cp -r assets ..


clean:
	$(MAKE) clean -C $(LIB1)
	$(MAKE) clean -C $(LIB2)
	$(MAKE) clean -C $(LIB3)


fclean:		clean
	$(RM) -rf bin
	$(RM) -rf assets
	$(MAKE) fclean -C $(LIB1)
	$(MAKE) fclean -C $(LIB2)
	$(MAKE) fclean -C $(LIB3)


re:		fclean all

.PHONY:		re all fclean clean
