# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cponce-q <cponce-q@student.42luxembou      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 15:05:20 by cponce-q          #+#    #+#              #
#    Updated: 2024/01/28 19:16:49 by cponce-q         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
# Name of the program
NAME = rush-02

SRC_DIR = srcs/

INCLUDES_DIR = includes/

HEAD =./includes/

# List the C to compile. \ to continue in the next line
# SOURCES = $(wildcard $(SRC_DIR)/*.c)
SOURCES = srcs/main.c srcs/print_value.c srcs/util_nums.c srcs/print_result.c \
			srcs/read_dict.c srcs/util_str.c srcs/start_values.c

# .o files: they contain compiled object code \
			Object files are processed by the linker to produce \
			the final executable
OBJECTS = $(SOURCES:.c=.o)

#INCLUDES = -Iincludes 		#-I is look into this folder

INCLUDES = -I/usr/local/include -I$(INCLUDES_DIR) -I$(HOME)/include

LIBINCLUDES = -L/usr/local/lib -Lbuild/lib  -L $(HOME)/lib

INC = $(INCLUDES) $(LIBINCLUDES)

CFLAGS += -Wall -Wextra -Werror

CUR_DIR = $(shell pwd)

# DEFAULT RULE MAKE executes (it is the first one it encounters)
all:	info1 $(NAME)

.c.o:
	cc $(CFLAGS) -c -I $(HEAD) $< -o $(<:.c=.o)

$(NAME): $(OBJECTS)
		cc -o $(NAME) $(CFLAGS) $(INCLUDES) $(OBJECTS) 

# Remove .o files, you have to add - to rm if to indicate to make that is okay to fai
clean:
		rm -f $(OBJECTS)

fclean:
		rm -f $(NAME)

re: fclean all

# Tell Make that all' is not a real target
.PHONY: all

info1: 
	$(info Compiling the files in 	$(CUR_DIR)/$(SRC_DIR))
	$(info "		  	$(CUR_DIR)/$(INCLUDES_DIR))

$(warning)

$(error) #IT STOPS THE COMPILATION
