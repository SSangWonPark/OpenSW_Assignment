# ===== advanced_ops/Makefile =====
.PHONY: all clean prep

# 상위에서 넘겨받음: INC_DIR, LIB_DIR
CC      := gcc
AR      := ar
ARFLAGS := rcs
CFLAGS  := -Wall -Wextra -O2 -I$(INC_DIR)

SRC_DIR := src
OBJ_DIR := obj

SRCS := $(SRC_DIR)/mymod.c $(SRC_DIR)/mypow.c
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

TARGET := $(LIB_DIR)/libmyadvanced.a

all: prep $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/advanced_ops.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

prep: | $(OBJ_DIR) $(LIB_DIR)
$(OBJ_DIR) $(LIB_DIR):
	@mkdir -p $@

clean:
	@echo "[advanced_ops] clean"
	@rm -f $(OBJS) $(DEPS) $(TARGET)

-include $(DEPS)
