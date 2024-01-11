SRC  := $(wildcard *.cpp)
OBJS := $(SRC:.cpp=.o)
INC  := -I${INCLUDE_DIR}

ALL: $(OBJS)
	mv *.o $(OBJ_DIR)

%.o: %.cpp
	$(CXX) -c  $<  -o  $@ $(CXXFLAGS) $(INC)