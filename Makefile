##
## EPITECH PROJECT, 2025
## NanoTekSpice
## File description:
## Makefile
##

NAME = nanotekspice

CC = g++

CXXFLAGS += -g3 -Wall -Wextra -Werror -std=c++20 -Iinclude
LDFLAGS += -lsfml-graphics -lsfml-window -lsfml-system -lncurses -DNCURSES_STATIC

SRCS_PREFIX = ./src/

FILES = Nts.cpp \
        Shell.cpp \
		parser.cpp \
		circuit.cpp \
		ClockComponent.cpp \
		AComponent.cpp \
		Elementary_Components/TrueComponent.cpp \
		Elementary_Components/FalseComponent.cpp \
		Elementary_Components/AndComponent.cpp \
		Elementary_Components/XorComponent.cpp \
		Elementary_Components/NotComponent.cpp \
		Elementary_Components/OrComponent.cpp \
		Elementary_Components/NorComponent.cpp \
		Elementary_Components/NandComponent.cpp \
		Gates_Components/4071.cpp \
		Gates_Components/4081.cpp \
		Gates_Components/4030.cpp \
		Gates_Components/4069.cpp \
		Gates_Components/4001.cpp \
		Gates_Components/4011.cpp \
		Advanced_Components/4008.cpp \
		Advanced_Components/4013.cpp \
		Advanced_Components/4017.cpp \

SRCS = $(addprefix $(SRCS_PREFIX), $(FILES))
OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

.PHONY: fclean clean all re

.SILENT:

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.cpp
	@$(CC) -o $@ $(CXXFLAGS) -c $<

clean:
	@rm -rf $(OBJ)
	@rm -rf vgcore.*
	@rm -f gmon.out
	@rm -rf a.out
	@find . -name '*.gc*' -delete

fclean: clean
	@rm -rf $(NAME)

re: fclean all
