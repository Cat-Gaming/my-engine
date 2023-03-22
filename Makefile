ifeq ($(OS),Windows_NT)
	CC=g++
	LIBS= -lgdi32
	OBJS = main/main.o display/win32/win32_displayserver.o
	OUTPUT = bin/engine-x86_64
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
    	CC=g++
    	LIBS = -lX11
    	OBJS = main/main.o display/x11/x11_displayserver.o
    	OUTPUT = bin/engine.x86_64
    endif
endif

all: build link clean

build: $(OBJS)

link:
	$(CC) $(OBJS) $(LIBS) -o $(OUTPUT)

clean:
	rm $(OBJS)
