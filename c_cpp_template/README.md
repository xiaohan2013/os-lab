# project scaoffold baesd on makefile for C/C++

#### Features


1. support nested structures
2. static linkage library
3. dynamic linkage library
4. generate executable file

#### Demo


#### Directory 

1. bin： executable scipts
2. build：building artifact
3. include：header files
4. lib：static or dynamic library
5. main：executable program entry
6. obj：compile artifact
7. src：source file

#### Makefile


```shell
CXX 		:= g++
CXXFLAGS 	:= -Wall -pedantic -std=c++11 -g

CUR_DIR 	:= $(PWD)
TOP_DIR     := $(shell dirname $(CUR_DIR))
OBJ_DIR 	:= $(TOP_DIR)/obj/
BIN_DIR 	:= $(TOP_DIR)/bin/
LIB_DIR     := $(TOP_DIR)/lib/
LIB			:= -lmul -ldiv
BIN 		:= test

LD_FLAGS    := -L$(LIB_DIR)

SUB_DIR 	:= $(TOP_DIR)/src
SUB_DIR		+= $(TOP_DIR)/src/multiplication
SUB_DIR     += $(TOP_DIR)/src/division
SUB_DIR		+= $(TOP_DIR)/main
SUB_DIR		+= $(TOP_DIR)/obj

INCLUDE_DIR	:= $(TOP_DIR)/include

export OBJ_DIR BIN_DIR LIB_DIR LIB INCLUDE_DIR BIN CXX CXXFLAGS LD_FLAGS

ALL: BEGIN $(SUB_DIR) END

BEGIN:
	@echo --- begin compile ---
	@echo $(TOP_DIR)

$(SUB_DIR): ECHO
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
```


#### makefile inside source


```shell
SRC  := $(wildcard *.cpp)
OBJS := $(SRC:.cpp=.o)
INC  := -I${INCLUDE_DIR}

ALL: $(OBJS)
	mv *.o $(OBJ_DIR)

%.o: %.cpp
	$(CXX) -c  $<  -o  $@ $(CXXFLAGS) $(INC)
```

#### src/division makefile


```shell
SRC  := $(wildcard *.cpp)
OBJS := $(SRC:.cpp=.o)
INC  := -I${INCLUDE_DIR}/division/

TARGET := libdiv.so

$(TARGET): $(OBJS)
	$(CXX) -shared $^ -o $@
	rm -rf *.o
	mv $@ $(LIB_DIR)

%.o: %.cpp
	$(CXX) -c  $<  -o  $@ $(CXXFLAGS) $(INC)
```

#### src/multiplication makefile



```shell
SRC  := $(wildcard *.cpp)
OBJS := $(SRC:.cpp=.o)
INC  := -I${INCLUDE_DIR}/multiplication/

TARGET := libmul.a
AR     := ar

$(TARGET): $(OBJS)
	$(AR) -r $@ $^
	rm -rf *.o
	mv $@ $(LIB_DIR)

%.o: %.cpp
	$(CXX) -c  $<  -o  $@ $(CXXFLAGS) $(INC)
```

#### src/obj makefile


```shell
OBJS     := $(shell find . -name '*.o' -type f;)

$(BIN): $(OBJS)
	echo $(OBJS)
	$(CXX) -o  $@  $(OBJS) $(LD_FLAGS) $(LIB)
	mv $(BIN) $(BIN_DIR)

clean:
	rm -rf *.o
```

#### main makefile


```shell
SRC  := $(wildcard *.cpp)
OBJS := $(SRC:.cpp=.o)
INC  := -I${INCLUDE_DIR}
INC  += -I${INCLUDE_DIR}/multiplication/
INC  += -I${INCLUDE_DIR}/division

ALL: $(OBJS)
	mv *.o $(OBJ_DIR)

%.o: %.cpp
	$(CXX) -c  $<  -o  $@ $(CXXFLAGS) $(INC)
```

#### lib目录


#### bin目录

```shell
export LD_LIBRARY_PATH=../lib:$LD_LIBRARY_PATH
./test
```

#### build


```shell

```


#### test.sh




