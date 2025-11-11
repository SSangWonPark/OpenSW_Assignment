PROJ_DIR = $(shell pwd)
SRC_DIR  = $(PROJ_DIR)/src
INC_DIR  = $(PROJ_DIR)/include
BIN_DIR  = $(PROJ_DIR)/bin
OBJ_DIR  = $(PROJ_DIR)/obj
LIB_DIR  = $(PROJ_DIR)/lib

CC      = gcc
CFLAGS  = -I$(INC_DIR)
PICFLAG = -fPIC

OPS_SRCS = src/myadd.c src/mysub.c src/mymul.c src/mydiv.c src/mypow.c src/mymod.c
OPS_OBJS = obj/myadd.o obj/mysub.o obj/mymul.o obj/mydiv.o obj/mypow.o obj/mymod.o


APP_SRC = $(SRC_DIR)/myapp.c
APP_OBJ = $(OBJ_DIR)/myapp.o
APP_BIN = $(BIN_DIR)/myapp

LIB_SO  = $(LIB_DIR)/libmyops.so.1.0

.PHONY: all clean run

all: $(APP_BIN)

$(APP_BIN): $(APP_OBJ) $(LIB_SO)
	$(CC) $(APP_OBJ) $(LIB_SO) -o $@

$(APP_OBJ): $(APP_SRC) $(INC_DIR)/myops.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/myops.h
	$(CC) $(CFLAGS) $(PICFLAG) -c $< -o $@

$(LIB_SO): $(OPS_OBJS)
	$(CC) -shared -o $@ $^

run: all
	./$(APP_BIN)

clean:
	@echo "Cleaning object files, libraries, and binaries..."
	rm -f $(OBJ_DIR)/*.o $(LIB_DIR)/* $(BIN_DIR)/*
