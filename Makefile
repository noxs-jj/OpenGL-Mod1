#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/20 10:27:01 by jmoiroux          #+#    #+#              #
#    Updated: 2015/01/20 10:27:02 by jmoiroux         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# /usr/bin/g++
# /usr/local/bin/g++

CXX = g++

NAME = mod1

PLATFORM := $(shell uname)

ifeq "$(PLATFORM)" "Darwin"	#Mac
	GL = -framework GLUT -framework OpenGL -framework Cocoa
endif
ifeq "$(PLATFORM)" "Linux"	#Linux
	GL = -lGL -lGLU -lglut
endif
ifeq "$(PLATFORM)" "Win32"	#Windows
	GL = -lopengl32 -lglu32 -lglut32
endif

CFLAGS = -Wall -Werror -Wextra -w -pedantic

HEAD = 	main.hpp \
		ft42.class.hpp \
		Parseur.class.hpp \
		Map.class.hpp \
		Event.class.hpp \
		Scenar1.class.hpp \
		Scenar3.class.hpp \
		Scenar4.class.hpp \
		Scenar7.class.hpp \
		Scenar8.class.hpp

SRC = 	main.cpp \
		fts.cpp \
		ft42.class.cpp \
		Display.cpp \
		Parseur.class.cpp \
		Map.class.cpp \
		Event.class.cpp \
		Scenar1.class.cpp \
		Scenar3.class.cpp \
		Scenar4.class.cpp \
		Scenar7.class.cpp \
		Scenar8.class.cpp

OBJ = $(SRC:.cpp=.cpp.o)

%.cpp.o: %.cpp $(HEAD)
	@$(CXX) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) $(OBJ) -o $(NAME) $(GL)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
