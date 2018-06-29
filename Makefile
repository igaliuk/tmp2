CC = clang++

NAME = ft_gkrellm

FLAGS = -Wall -Wextra -Werror

IDIR = ./inc

EXTENSIONS = $(addprefix $(IDIR)/,$(EXT))

EXT =

CFLAGS = -I$(IDIR) \
		-I./frameworks/SDL2.framework/Headers/ \
		-I./frameworks/SDL2_image.framework/Headers/ \
		-I./frameworks/SDL2_ttf.framework/Headers/ \

SDL2_F		= -framework SDL2 -framework SDL2_image -framework SDL2_ttf -F ./frameworks/

SDL2_P		= -rpath @loader_path/frameworks/

DIR_S = src

DIR_O = obj

HEADER = inc

_DEPS =

DEPS = $(patsubst %,$(HEADER)/%,$(_DEPS))

SOURCES =   main.cpp \
			Sdl.cpp \
			StandardMonitor.cpp \
			MainMonitor.cpp \
			CPUModule.cpp \
			MainModule.cpp \
			NetworkModule.cpp \
			RAMModule.cpp \
			DisksModule.cpp \
			ProcessesModule.cpp \
			LoadAverageModule.cpp \



SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.cpp=.o))

all: obj $(NAME)

$(NAME): $(OBJS) $(EXTENSIONS)
		$(CC) -o $(NAME) $(OBJS) $(FLAGS) $(CFLAGS) $(SDL2_P) $(SDL2_F)

obj:
	mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.cpp $(DEPS) $(EXTENSIONS)
		$(CC) -c -o $@ $< $(FLAGS) $(CFLAGS)


clean:
		rm -f $(OBJS)
		rm -rf $(DIR_O)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all, obj, clean, fclean, re
.NOTPARALLEL:  all, obj, clean, fclean, re
.SILENT:
