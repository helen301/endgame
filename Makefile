CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -lcurses

SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
# SRC_FILES_OB = $(notdir $(SRC_FILES))

INC_DIR = inc
# INC_FILES = $(wildcard $(INC_DIR)/*.h)
# INC_FILES_OB = $(notdir $(INC_FILES))

NAME = endgame
RM = rm -rf 


all: uninstall $(NAME) 


$(NAME) : $(SRC_FILES) $(INC_DIR) 
	@$(CC) $(CFLAGS) $(SRC_FILES) -I $(INC_DIR) -o $(NAME)

# install clean
# install: ENDGAME

# ENDGAME:  
# @cp $(SRC_FILES) .
# @cp $(INC_FILES) .
# @$(CC) $(CFLAGS) $(SRC_FILES_OB) -I$(INC_FILES_OB) -o $(NA

uninstall: 
	@$(RM) $(NAME)

clean:
	# @rm -f $(SRC_FILES_OB)
	@$(RM) *.o

reinstall: 
