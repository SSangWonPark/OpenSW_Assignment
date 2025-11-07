# ===== root makefile (week08_make_v2/makefile) =====
.PHONY: all libs basic_ops advanced_ops clean

# --- paths (루트 기준 고정 경로) ---
INC_DIR := $(CURDIR)/include
LIB_DIR := $(CURDIR)/lib
BIN_DIR := $(CURDIR)/bin
OBJ_DIR := $(CURDIR)/obj
SRC_DIR := $(CURDIR)/src

# --- tools/flags ---
CC      := gcc
CFLAGS  := -Wall -Wextra -O2 -I$(INC_DIR)
LDFLAGS := -L$(LIB_DIR)
LDLIBS  := -lmybasic -lmyadvanced

# --- app targets ---
APP_SRC := $(SRC_DIR)/myapp.c
APP_OBJ := $(OBJ_DIR)/myapp.o
APP_BIN := $(BIN_DIR)/myapp

# ================= top =================
# all 은 "파일 타깃"인 $(APP_BIN)을 직접 의존합니다.
all: $(APP_BIN)

# ===== libs (두 .a를 '파일' 타깃으로 보장) =====
libs: $(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a

$(LIB_DIR)/libmybasic.a:
	@$(MAKE) -C basic_ops INC_DIR=$(INC_DIR) LIB_DIR=$(LIB_DIR)

$(LIB_DIR)/libmyadvanced.a:
	@$(MAKE) -C advanced_ops INC_DIR=$(INC_DIR) LIB_DIR=$(LIB_DIR)

# ===== link app (부모 디렉토리 보장 + 라이브러리 의존) =====
$(APP_BIN): $(APP_OBJ) $(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a
	@mkdir -p $(dir $@)
	@echo "Linking $@"
	$(CC) $(APP_OBJ) $(LDFLAGS) $(LDLIBS) -o $@

# ===== compile app obj (부모 디렉토리 보장) =====
$(APP_OBJ): $(APP_SRC) $(INC_DIR)/basic_ops.h $(INC_DIR)/advanced_ops.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ===== clean =====
clean:
	@echo "Cleaning everything..."
	@rm -rf $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)
	-@$(MAKE) -C basic_ops clean
	-@$(MAKE) -C advanced_ops clean
