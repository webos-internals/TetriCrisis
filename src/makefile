TARGET	= tetricrisis

VERSION	= 5.9

DEL_FILE = rm -f

CC       = $(CXX)
CFLAGS   = -O2 -pipe -Wall -g

SDL_CFLAGS	= `sdl-config --cflags`
SDL_LIBS	= `sdl-config --libs`
SDL_MIXER_LIBS	= -lSDL_mixer
SDL_TTF_LIBS	= -lSDL_ttf
SDL_IMAGE_LIBS	= -lSDL_image \

OBJECTS = src/main.o \
	src/Audio.o \
	src/Buttons.o \
	src/Control.o \
	src/Game.o \
	src/Settings.o \
	src/Tetri.o \
	src/Visuals.o
SOURCES = src/main.cpp \
	src/Audio.cpp \
	src/Buttons.cpp \
	src/Control.cpp \
	src/Game.cpp \
	src/Settings.cpp \
	src/Tetri.cpp \
	src/Visuals.cpp
HEADERS = src/Audio.h \
	src/Buttons.h \
	src/Control.h \
	src/Game.h \
	src/Settings.h \
	src/Tetri.h \
	src/Visuals.h
	
.PHONY:	all clean

all: $(TARGET)

fresh: clean all

$(TARGET): $(OBJECTS)
	$(CC) $(SDL_LIBS) $(SDL_MIXER_LIBS) $(SDL_TTF_LIBS) $(SDL_IMAGE_LIBS)$(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(SDL_CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(TARGET)
