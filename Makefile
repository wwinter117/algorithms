# 定义编译器和编译选项
CC = gcc
CFLAGS = -Wall -Wextra

# 定义源文件和目标文件
SRCS = main.c \
       common/util.c \
       c1/insertsort.c \
       c1/mergesort.c

OBJS = $(SRCS:.c=.o)
DEPS = common/util.h \
       c1/algorithm_c1.h

# 目标文件
TARGET = algorithms

# 默认目标
all: $(TARGET)

# 链接目标文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 生成依赖文件
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

# 定义运行目标的模板
define RUN_TEMPLATE
$1: CFLAGS += -D$1 -DRUN_FUNC=\""$1"\"
$1: $(TARGET)
	./$(TARGET)
endef

# 使用模板定义运行目标
$(eval $(call RUN_TEMPLATE,C2_2_3_2))
$(eval $(call RUN_TEMPLATE,C2_2_3_4))

# 可以继续添加更多的运行目标
# $(eval $(call RUN_TEMPLATE,another_target))

# 清理
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
