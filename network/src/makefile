SRC  := $(wildcard *.c)
OBJS := $(SRC:.c=.o)
INC  := -I${INCLUDE_DIR}

ALL: $(OBJS)
	mv *.o $(OBJ_DIR)

#%.o: %.c
#	$(CC) -c  $<  -o  $@ $(CCFLAGS) $(INC)
#
%: %.c
	$(CC) -c $< -o $@ $(CCFLAGS) $(INC)
