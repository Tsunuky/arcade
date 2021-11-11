##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

NAME		=	arcade

FINAL_GAME	=	$(ROOT)/games
FINAL_LIB	=	$(ROOT)/libs

ROOT		=	.
CORE_DIR	=	$(ROOT)/core
GRAPH_DIR	=	$(ROOT)/graphic
GAME_DIR	=	$(ROOT)/game

all:	core graphicals games

core:
	$(MAKE) -C $(CORE_DIR)
	-mkdir bin
	-cp $(CORE_DIR)/bin/$(NAME) .
	-cp $(CORE_DIR)/bin/$(NAME) bin/

graphicals:
	$(MAKE) -C $(GRAPH_DIR)
	-mkdir $(FINAL_LIB)
	-cp $(GRAPH_DIR)/bin/* $(FINAL_LIB)
	-cp -r $(GRAPH_DIR)/assets ..

games:
	$(MAKE) -C $(GAME_DIR)
	-mkdir	$(FINAL_GAME)
	-cp $(GAME_DIR)/bin/* $(FINAL_GAME)

clean:
	$(MAKE) clean -C $(CORE_DIR)
	$(MAKE) clean -C $(GRAPH_DIR)
	$(MAKE) clean -C $(GAME_DIR)

fclean:		clean
	$(MAKE) fclean -C $(CORE_DIR)
	$(MAKE) fclean -C $(GRAPH_DIR)
	$(MAKE) fclean -C $(GAME_DIR)
	$(RM) -rf assets
	$(RM) -rf $(FINAL_GAME)
	$(RM) -rf $(FINAL_LIB)
	$(RM) -rf assets
	$(RM) -rf bin
	$(RM) $(NAME)

re:		fclean
	$(MAKE) re -C $(CORE_DIR)
	$(MAKE) re -C $(GRAPH_DIR)
	$(MAKE) re -C $(GAME_DIR)
	$(MAKE) -C $(ROOT)

.PHONY:		all fclean clean re core games graphicals