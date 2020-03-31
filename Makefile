##
## EPITECH PROJECT, 2020
## MUL_my_rpg_2019
## File description:
## Makefile
##

CFLAGS 	=	-Iengine/include -Igame/include -Wall
LDFLAGS	+=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

EXEC 	=	my_rpg

SRC		=	engine/core/engine.c									\
			engine/core/event_management.c							\
			engine/core/pevent_keyboard.c							\
			engine/core/pevent_mouse.c								\
			engine/core/create_win.c								\
			engine/entities/entity.c								\
			engine/entities/entity_node.c							\
			engine/scenes/scene.c									\
			engine/scenes/scene_add_entity.c						\
			engine/scenes/scene_get_entity.c						\
			engine/scenes/scene_remove_entity.c						\
			engine/scenes/scene_manager.c							\
			engine/utils/delta_time.c								\
			engine/utils/output.c									\
			engine/utils/random.c									\
			engine/utils/string_convert.c							\
			engine/utils/string_utils.c								\
			engine/utils/string_utils2.c							\
			engine/utils/vector_helper.c							\
			engine/utils/rect_helper.c								\
			engine/ui/label.c										\
			engine/ui/label_helper.c								\
			engine/ui/panel.c										\
			engine/ui/button.c										\
			engine/ini/loader.c										\
			engine/ini/set.c										\
			engine/ini/free.c										\
			engine/ini/get.c										\
			engine/ini/save.c										\
			game/main.c												\
			game/entities/splashscreen/sound.c						\
			game/entities/splashscreen/video.c						\
			game/entities/game/icon.c								\
			game/scenes/splashscreen/splashscreen.c					\
			game/scenes/main_menu/main_menu.c						\
			game/scenes/main_menu/main_menu_callback.c				\
			game/scenes/option/option_callback.c					\
			game/scenes/option/option.c								\
			game/scenes/option/resolution/resolution.c				\
			game/scenes/option/resolution/resolution_callback.c		\
			game/scenes/option/volume/volume.c						\
			game/scenes/option/volume/volume_callback.c

OBJ		=	$(SRC:.c=.o)

all:		$(EXEC)

$(EXEC):	$(OBJ)
	gcc -o $(EXEC) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(EXEC)

re:			fclean all

cdb:
	compiledb make re
