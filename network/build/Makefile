CC		:= gcc
CCFLAGS 	:= -Wall -pedantic -std=C99 -g

CUR_DIR 	:= $(PWD)
TOP_DIR     := $(shell dirname $(CUR_DIR))
OBJ_DIR 	:= $(TOP_DIR)/obj/
BIN_DIR 	:= $(TOP_DIR)/bin/
LIB_DIR     := $(TOP_DIR)/lib/
#LIB			:= -lmul -ldiv
BIN 		:= network

LD_FLAGS    := -L$(LIB_DIR)

SUB_DIR 	:= $(TOP_DIR)/src
#SUB_DIR		+= $(TOP_DIR)/src/multiplication
#SUB_DIR     += $(TOP_DIR)/src/division
#SUB_DIR		+= $(TOP_DIR)/main
SUB_DIR		+= $(TOP_DIR)/obj

INCLUDE_DIR	:= $(TOP_DIR)/include

#为让总控Makefile定义变量，在子makefile中能够访问，使用export命令将变量声明为全局可用
export OBJ_DIR BIN_DIR LIB_DIR LIB INCLUDE_DIR BIN CC CCFLAGS LD_FLAGS

#ALL伪指令是Makefile的入口处理指令，执行顺序根据ALL：后面指定的顺序执行。
#先执行BEGIN，再执行$(SUB_DIR)，最后执行END。
ALL: BEGIN $(SUB_DIR) END

BEGIN:
	@echo --- begin compile ---
	@echo $(TOP_DIR)

$(SUB_DIR): ECHO
#执行SUB_DIR下的makefile
	make -C $@

ECHO:
	@echo "Compiling : " $(SUB_DIR) "..."

END:
	@echo --- end compile ---
	@echo ---------------------------
	@echo   success: $(BIN_DIR)$(BIN)
	@echo ---------------------------

clean:
	rm -rf $(OBJ_DIR)*.o $(BIN_DIR)$(BIN) $(LIB_DIR)*

.PHONY = ALL ECHO BEGIN END
