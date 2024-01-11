SRC  := $(wildcard *.cpp)
OBJS := $(SRC:.cpp=.o)
INC  := -I${INCLUDE_DIR}
INC  += -I${INCLUDE_DIR}/multiplication/
INC  += -I${INCLUDE_DIR}/division

ALL: $(OBJS)
	mv *.o $(OBJ_DIR)

%.o: %.cpp
	$(CXX) -c  $<  -o  $@ $(CXXFLAGS) $(INC)