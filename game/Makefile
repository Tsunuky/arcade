##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

GAME1	=	pacman
GAME2	=	nibbler
GAME3	=	centipede
GAME4	=	qix
GAME5	=	solarfox


all:
	-mkdir bin
	$(MAKE) -C $(GAME1)
	$(MAKE) -C $(GAME2)
	$(MAKE) -C $(GAME3)
	$(MAKE) -C $(GAME4)
	$(MAKE) -C $(GAME5)

clean:
	$(MAKE) clean -C $(GAME1)
	$(MAKE) clean -C $(GAME2)
	$(MAKE) clean -C $(GAME3)
	$(MAKE) clean -C $(GAME4)
	$(MAKE) clean -C $(GAME5)

fclean:		clean
	$(RM) -rf bin
	$(MAKE) fclean -C $(GAME1)
	$(MAKE) fclean -C $(GAME2)
	$(MAKE) fclean -C $(GAME3)
	$(MAKE) fclean -C $(GAME4)
	$(MAKE) fclean -C $(GAME5)

re:		fclean all

.PHONY:		re all fclean clean
