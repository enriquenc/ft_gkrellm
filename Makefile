#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 13:04:14 by tmaslyan          #+#    #+#              #
#    Updated: 2018/10/14 19:23:46 by tkiselev         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_gkrellm

FLAGS = -Wall -Wextra -Werror

INCLUDES =	-I ./frameworks/SDL2.framework/Versions/A/Headers \
			-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-F./frameworks/
				
FRAMEWORKS =	-F ~/Library/Frameworks/ -framework SDL2 \
				-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer


SRC = src/main.cpp src/CPUModule.cpp src/DateModule.cpp \
	 src/DiskModule.cpp src/HostNameModule.cpp src/IMonitorModule.cpp \
	 src/NetworkModule.cpp src/OSInfoModule.cpp src/RAMModule.cpp src/TextMod.cpp  src/GraphicMod.cpp


OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(OBJ) -o $(NAME) $(FRAMEWORKS) -lncurses

%.o: %.cpp
	clang++ $(FLAGS) $(INCLUDES)  -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
