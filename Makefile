##
## EPITECH PROJECT, 2020
## MUL_my_rpg_2019
## File description:
## Makefile
##

CFLAGS 	=	-g -Iengine/include -Igame/include -Wall
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
			engine/scenes/scene_depth.c								\
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
			game/map_change.c										\
			game/inventory.c										\
			game/quests.c											\
			game/items/health_potion.c								\
			game/entities/splashscreen/sound.c						\
			game/entities/splashscreen/video.c						\
			game/entities/game/icon.c								\
			game/entities/game/background.c							\
			game/entities/game/camera.c								\
			game/entities/game/colliders.c							\
			game/entities/game/obstacle.c							\
			game/entities/game/player_movement.c					\
			game/entities/game/player.c								\
			game/entities/game/enemy.c								\
			game/entities/game/warp.c								\
			game/entities/game/rain.c								\
			game/entities/game/menu_shop.c							\
			game/entities/chara_design/chara_preview.c				\
			game/entities/game/menu.c								\
			game/entities/game/menu_update.c						\
			game/entities/game/menu_main.c							\
			game/entities/game/menu_inventory.c						\
			game/entities/game/menu_stats.c							\
			game/entities/game/menu_quests.c						\
			game/entities/game/menu_entries.c						\
			game/entities/game/menu_talk.c							\
			game/entities/game/menu_talk_init.c						\
			game/entities/game/talk.c								\
			game/entities/game/answer.c								\
			game/entities/game/menu_answer_update.c					\
			game/entities/game/answer_callbacks.c					\
			game/entities/menu/menu_background.c					\
			game/entities/game/menu_entries_answer.c				\
			game/entities/game/reset_view.c							\
			game/entities/game/get_current_slot.c					\
			game/entities/game/save.c								\
			game/entities/game/autosave.c							\
			game/entities/game/npc.c								\
			game/entities/game/barre_stat.c							\
			game/entities/game/enemy_stat.c							\
			game/entities/game/fight_info.c							\
			game/entities/game/fight_player.c						\
			game/entities/game/fight_enemy.c						\
			game/entities/game/fightbg.c							\
			game/entities/game/current_quest.c						\
			game/entities/game/init_coliders.c						\
			game/entities/game/init_colliders2.c					\
			game/entities/game/music.c								\
			game/scenes/splashscreen/splashscreen.c					\
			game/scenes/main_menu/main_menu.c						\
			game/scenes/main_menu/main_menu_callback.c				\
			game/scenes/option/option_callback.c					\
			game/scenes/option/option.c								\
			game/scenes/option/resolution/resolution.c				\
			game/scenes/option/resolution/resolution_callback.c		\
			game/scenes/option/volume/volume.c						\
			game/scenes/option/volume/volume_callback.c				\
			game/scenes/loadgame/loadgame.c							\
			game/scenes/loadgame/loadgame_callback.c				\
			game/scenes/spawn_map/spawn_map.c						\
			game/scenes/spawn_map/add_obstacles.c					\
			game/scenes/player_design/player_design.c				\
			game/scenes/player_design/player_design_callback.c		\
			game/scenes/fight/fight_map.c							\
			game/scenes/fight/fight_callback.c						\
			game/scenes/fight/create_labels.c						\
			game/scenes/fight/get_fight_info.c						\
			game/scenes/fight/update_labels.c						\
			game/scenes/fight/attack.c								\
			game/npc_talk/default_talk.c							\
			game/shop/buy.c

OBJ		=	$(SRC:.c=.o)

all:		$(EXEC)

$(EXEC):	$(OBJ)
	gcc -o $(EXEC) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(EXEC)
	rm -f vgcore*

re:			fclean all

cdb:
	compiledb make re
