# 定义包括目录，用于包含头文件
#common makefile header
DIR_INC = ./include
# 定义二进制文件输出目录
DIR_BIN = ./bin
# 定义库文件输出目录
DIR_LIB = ./libs

# 定义目标程序的名称
TARGET = main
# 定义二进制目标文件的名称
BIN_TARGET = $(TARGET)

# 定义交叉编译器的前缀，用于交叉编译
CROSS_COMPILE = arm-linux-
# 定义C编译器的标志，包括调试信息和头文件包含路径
CFLAGS = -g -Wall -I$(DIR_INC)
# 定义链接器的标志，包括库路径和链接的库
LDFLAGS := -L$(DIR_LIB)
LDFLAGS += -lmsc -lrt -ldl -lpthread -lasound -lstdc++

# 通过通配符自动定义所有的源文件
SRC_FILES := $(wildcard ./src/*.c)
# 通过模式替换定义所有的目标文件
OBJ_FILES := $(SRC_FILES:./src/%.c=%.o)

# 规则定义如何生成最终的二进制目标文件
$(BIN_TARGET): $(OBJ_FILES)
	# 使用交叉编译器和相关的标志，链接所有的目标文件生成二进制目标文件
	$(CROSS_COMPILE)gcc $(CFLAGS) $^ -o $@ $(LDFLAGS)

# 规则定义如何从源文件生成目标文件
%.o: ./src/%.c
	# 使用交叉编译器和编译标志，编译源文件生成目标文件
	$(CROSS_COMPILE)gcc -c $(CFLAGS) $< -o $@

# 定义一个清理目标，用于清除所有的编译产物
# 自动清理中间文件及指定目录
clean:
	# 清除所有的目标文件
	# 清除对象文件
	rm -f $(OBJ_FILES)
	# 清除最终的二进制目标文件
	# 清除二进制目标文件
	rm -f $(BIN_TARGET)
	# 清除所有的依赖文件
	# 清理可能存在的依赖文件
	find . -name "*.d" -exec rm -f {} +
	# 清空bin目录下的所有文件
	# 清空bin目录
	rm -rf $(DIR_BIN)/*
	# 注意：这里谨慎地清空libs目录，确保不会误删重要文件
	# rm -rf $(DIR_LIB)/*

# 定义一个伪目标，用于告诉make这是一个不生成实际文件的目标
.PHONY: clean