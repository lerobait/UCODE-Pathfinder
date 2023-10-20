NAME = libmx.a

SRC = src

OBJ = obj

INC = inc

FLAGS = -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
		@clang-14 $(FLAGS) -I $(INC) -c $(SRC)/*.c
		@mkdir -p $(OBJ)
		@cp *.o $(OBJ)
		@ar -rc $(NAME) $(OBJ)/*.o
		@ranlib $(NAME)
		@rm -rf *.o

uninstall: clean
		@rm -rf $(NAME)
		@rm -rf $(OBJ)
		@rm -rf *.a

clean:
		@rm -rf $(OBJ)

reinstall: alls
