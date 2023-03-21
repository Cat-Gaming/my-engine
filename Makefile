CC=g++

OBJS = main/main.o display/x11/x11_displayserver.o
LIBS = -lX11

all: build link

build: $(OBJS)

link:
	$(CC) $(OBJS) -o bin/engine.x86_64 $(LIBS)