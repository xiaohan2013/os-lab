#查找当前目录下所有的object文件
OBJS     := $(shell find . -name '*.o' -type f;)

$(BIN): $(OBJS)
	echo $(OBJS)
#生成可执行程序
	$(CXX) -o  $@  $(OBJS) $(LD_FLAGS) $(LIB)
	mv $(BIN) $(BIN_DIR)

clean:
	rm -rf *.o