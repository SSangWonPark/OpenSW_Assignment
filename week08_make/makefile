.PHONY: all basic_ops advanced_ops clean prep

# ===== 경로 매크로 =====
PROJ    := $(PWD)
SRC_DIR := $(PROJ)/src
OBJ_DIR := $(PROJ)/obj
BIN_DIR := $(PROJ)/bin
INC_DIR := $(PROJ)/include
LIB_DIR := $(PROJ)/lib

# ===== 도구/옵션 =====
CC      := gcc
CFLAGS  := -Wall -Wextra -O2 -I$(INC_DIR)
LDFLAGS := -L$(LIB_DIR)
LDLIBS  := -lmybasic -lmyadvanced

APP_SRC := $(SRC_DIR)/myapp.c
APP_OBJ := $(OBJ_DIR)/myapp.o
APP_BIN := $(BIN_DIR)/myapp

# ----- 총괄 타깃 -----
all: prep basic_ops advanced_ops $(APP_BIN)

basic_ops:
	$(MAKE) -C basic_ops INC_DIR=$(INC_DIR) LIB_DIR=$(LIB_DIR)

advanced_ops:
	$(MAKE) -C advanced_ops INC_DIR=$(INC_DIR) LIB_DIR=$(LIB_DIR)

# myapp 링크
$(APP_BIN): $(APP_OBJ) $(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a | $(BIN_DIR)
	$(CC) $< $(LDFLAGS) $(LDLIBS) -o $@

# myapp 컴파일
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 디렉토리 준비
prep: | $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)

$(OBJ_DIR) $(BIN_DIR) $(LIB_DIR):
	@mkdir -p $@

# 정리
clean:
	@echo "Cleaning everything..."
	@rm -rf $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)
	@$(MAKE) -C basic_ops clean
	@$(MAKE) -C advanced_ops clean

-include $(APP_OBJ:.o=.d)
