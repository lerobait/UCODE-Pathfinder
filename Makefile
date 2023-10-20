NAME = libmx.a

SRC = src

OBJ = obj

INC = inc

FLAGS = -g -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
		@make -C ./libmx
		@clang-14 $(FLAGS) -I $(INC) $(SRC)/*.c -L ./libmx -lmx -o pathfinder

uninstall: clean
		@rm -rf $(NAME)
		@rm -rf $(OBJ)
		@rm -rf pathfinder
		@make uninstall -C ./libmx

clean:
		@rm -rf $(OBJ)

reinstall: all
