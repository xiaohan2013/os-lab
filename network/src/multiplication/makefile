SRC  := $(wildcard *.cpp)
OBJS := $(SRC:.cpp=.o)
INC  := -I${INCLUDE_DIR}/multiplication/

#定义静态连接库的名字和生成静态连接库的命令
TARGET := libmul.a
AR     := ar

$(TARGET): $(OBJS)
#生成静态连接库
	$(AR) -r $@ $^
	rm -rf *.o
	mv $@ $(LIB_DIR)

%.o: %.cpp
#用cpp文件来生成object文件
	$(CXX) -c  $<  -o  $@ $(CXXFLAGS) $(INC)