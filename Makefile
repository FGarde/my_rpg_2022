##
## EPITECH PROJECT, 2022
## Makefile for every project
## File description:
## Makefile
##

override SRC_TMP	=	main.c 							\
						animations/character_anim.c		\
						audio/play_audio.c 				\
						audio/play_sound.c 				\
						window/window.c					\
						window/resolution.c    			\
						backgrounds/backgrounds.c 		\
						buttons/buttons.c				\
						buttons/buttons_list.c 			\
						errors/error.c 					\
						menu/main_menu.c				\
						menu/menu_htp.c 				\
						menu/menu_settings.c			\
						menu/menu_pause.c				\
						menu/menu_tools.c				\
						menu/selections/main_menu_select.c 	\
						menu/selections/menu_settings_select.c 	\
						menu/selections/menu_htp_select.c 		\
						menu/selections/menu_pause_select.c 	\
						destroys/destroy_game.c			\
						destroys/destroy_global.c		\
						game_loop.c						\
						view/edit_view.c				\
						inits/init_game.c				\
						inits/init_window.c				\
						inits/init_character.c			\
						inits/init_map.c				\
						inits/init_music.c 				\
						inits/init_sound.c 				\
						events/analyse_event.c			\
						events/keyboard_events.c		\
						particles/particles.c			\
						particles/rain_particles.c		\
						text/texts.c					\
						text/texts_list.c				\
						environment/rain.c				\
						enemy/enemy.c					\
						enemy/hero_attacks.c

override SRC		=	$(addprefix src/, $(SRC_TMP:.c=.c))

override CPPFLAGS	+=	-Iincludes

override CFLAGS		+=	-W -Wall -Wextra -lcsfml-graphics -lcsfml-system \
						-lcsfml-window -lcsfml-audio
#-Wextragood idea

override LDFLAGS	=	-Llib

override LDLIBS		=	-lmy

LIB_SRC_PATH		=	lib/my
LIB					=	lib/libmy.a

NAME				=	my_rpg

BUILDDIR			=	obj

override OBJ		=	$(SRC:%.c=$(BUILDDIR)/%.o)

CC					=	gcc

LD					=	$(CC)

all:				$(LIB) $(NAME)		## The "make" rule, compile the program
.PHONY:	all

$(LIB):
					make -C lib/my

$(NAME):			$(OBJ) $(LIB)
					$(LINK.o) $^ $(LDLIBS) $(OUTPUT_OPTION) $(CFLAGS)

.SECONDEXPANSION:
$(BUILDDIR)/%.o:	override CPPFLAGS += -MT $@ -MMD -MP -MF $(@:.o=.d)
$(BUILDDIR)/%.o:	%.c | $$(@D)/.
					$(COMPILE.c) $(OUTPUT_OPTION) $<

$(BUILDDIR)/.:
					mkdir $@

$(BUILDDIR)%/.:
					mkdir -p $@

.PRECIOUS:			$(BUILDDIR)/. $(BUILDDIR)%/.

vclean:						## Delete *~ & *#*#* & .#* & vgcore.* *.gcno *.gcda
					$(RM) *~ *#*#* .#* vgcore.* *.gcno *.gcda
.PHONY:	vclean

cleanlib:													## Delete the lib
					$(RM) -r $(LIB)
					make -C $(LIB_SRC_PATH) fclean
.PHONY:	cleanlib

clean:											        ## Delete the build dir
					$(RM) -r $(BUILDDIR)
.PHONY:	clean

fclean:				clean cleanlib		  ## Delete the binary and call "clean"
					$(RM) $(NAME)
.PHONY:	fclean

re:					fclean all
.PHONY:	re		 ## Delete everything from the previous compilation and compile

allclean:			cleanlib fclean vclean
.PHONY:	allclean 				   ## Call every function that delete something

-include make_tests.mk

help:										## Print every help in the terminal
		@printf "USAGE:\n\n"
		@grep -E "^[a-zA-Z\\_]+:.*## " Makefile | awk 'BEGIN {FS = ":.*## "}; \
		{printf "%-30s\033[36m%s\033[0m\n", $$1, $$2}'
.PHONY:	help

-include $(OBJ:.o=.d)
