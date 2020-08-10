##
## EPITECH PROJECT, 2019
## pushswap
## File description:
## Makefile
##

SRC	=	./src/Main/main.c\
		./src/Main/window.c\
		./src/Main/free_list_node0.c\
		./src/Main/free_list_node1.c\
		./src/Main/free_defender_data.c

SRC	+=	./src/Settings/Menu/menu.c\
		./src/Settings/Menu/menu_event.c\
		./src/Settings/Menu/setting_box.c\
		./src/Settings/Menu/update_menu_settings.c\
		./src/Settings/Menu/settings_box_events.c

SRC	+=	./src/Settings/Game/magazin_event.c\
		./src/Settings/Game/magazin.c\
		./src/Settings/Game/settings0.c\
		./src/Settings/Game/setting_box.c\
		./src/Settings/Game/setting_anim_events.c\

SRC	+=	./src/Game/Map/map.c\
		./src/Game/Map/mini_map.c\

SRC	+=	./src/Game/Plants/operate_plants/plants.c\
		./src/Game/Plants/operate_plants/anim_plants.c\
		./src/Game/Plants/operate_plants/plants_draw.c\
		./src/Game/Plants/operate_plants/creat_plants.c\

SRC	+=	./src/Game/Plants/pea/pea_skilles0.c\
		./src/Game/Plants/pea/pea_skilles1.c\

SRC	+=	./src/Game/Plants/beet/beet_skilles0.c\
		./src/Game/Plants/beet/beet_skilles1.c\

SRC	+=	./src/Game/Plants/flower/sun_skilles0.c\
		./src/Game/Plants/flower/sun_skilles1.c\

SRC += ./src/Game/Plants/walnut/walnut_skiles0.c\

SRC	+=	./src/Game/Zombies/creat_zombies.c\
		./src/Game/Zombies/zombies_skilles0.c\
		./src/Game/Zombies/zombies_skilles1.c\
		./src/Game/Zombies/set_zombies_round.c\
		./src/Game/Zombies/zombies_draw.c\

SRC += 	./src/Game/win_louse/win_lose0.c\
		./src/Game/win_louse/win_lose1.c\

SRC	+=	./src/Tools/csfml_tools0.c\
		./src/Tools/csfml_tools1.c\
		./src/Tools/csfml_tools2.c\
		./src/Tools/csfml_tools3.c\
		./src/Settings/Game/score.c

OBJ	= 	$(SRC:.c=.o)

LIB	=	-L./lib/ -l my_tools -l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system

CFLAGS	= 	-g -g3 -I./inc -I./inc/lib_inc

CC	=	gcc -o

NAME	=	my_defender

all: $(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/
	$(CC)	$(NAME)	$(OBJ)	$(LIB)	$(CFLAGS)

clean:
	make -C ./lib/ clean
	rm -rf	$(OBJ)
	rm -f	*~
	rm -f	*#
	rm -f	#*

fclean:	clean
	make -C ./lib/ fclean
	rm -rf  $(NAME)

re:	fclean all