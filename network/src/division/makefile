SRC  := $(wildcard *.cpp)
OBJS := $(SRC:.cpp=.o)
INC  := -I${INCLUDE_DIR}/division/

#定义动态连接库的名字
TARGET := libdiv.so

$(TARGET): $(OBJS)
#生成动态连接库
	$(CXX) -shared $^ -o $@
	rm -rf *.o
	mv $@ $(LIB_DIR)

%.o: %.cpp
#用cpp文件来生成object文件
	$(CXX) -c  $<  -o  $@ $(CXXFLAGS) $(INC)