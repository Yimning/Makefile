EXE_NAME = app

DEBUG = -D_MACRO #宏定义 

#PROJECT_ROOT_PATH = /home/yimning/MakefileTemplate
#VERSION     = 1.0.0

CC = gcc
DEBUG   =-DUSE_DEBUG
CFLAGS  =-Wall
CCSRCS	= $(wildcard *.c)			#获取所有的.c文件 
CCOBJS = $(patsubst %.c,%.o, $(CCSRCS))		#符合模式[%.c]的单词替换成[%.o] 即将.c文件转为.o文件 
INCPATH = -I../include -I$(PROJECT_ROOT_PATH)/include			#头文件路径 
LDFLAGS = -L$(PROJECT_ROOT_PATH)/lib			#库文件路径
LIB_NAMES = $(LIB_SO_OBJS)	$(LIBS_A_OBJS)		#链接库文件名字 

# 获取静态库名字
LIBS_A	= $(wildcard $(PROJECT_ROOT_PATH)/lib/*.a)   # 获取该目录下动态库(*.a)的路径名
LIBS_A_NOTDIR    = $(notdir $(LIBS_A))			# 去掉路路径，只留下文件名为libxxx.a
LIBS_A_NOTLIB    = $(subst lib,,$(LIBS_A_NOTDIR))	# 去掉文件名的lib,留下部分为xxx.a
LIBS_A_OBJS = $(patsubst %.a,-l%, $(LIBS_A_NOTLIB))		# 去掉文件名的后缀并在前面添加-l,留下部分为-lxxx


# 获取动态库名字
LIBS_SO	= $(wildcard $(PROJECT_ROOT_PATH)/lib/*.so)   # 获取该目录下动态库(*.so)的路径名
LIBS_SO_NOTDIR    = $(notdir $(LIBS_SO))			# 去掉路路径，只留下文件名为libxxx.so
LIBS_SO_NOTLIB    = $(subst lib,,$(LIBS_SO_NOTDIR))	# 去掉文件名的lib,留下部分为xxx.so
LIB_SO_OBJS = $(patsubst %.so,-l%, $(LIBS_SO_NOTLIB))		# 去掉文件名的后缀并在前面添加-l,留下部分为-lxxx


#links
$(EXE_NAME): $(CCOBJS)
	$(CC) $^ -o $@ $(LDFLAGS) $(LIB_NAMES)

#compile
$(CCOBJS): %.o: %.c
	$(CC) $(INCPATH) $(CFLAGS) -c $< -o $@
	
.PHONY: install
install:
	cp $(EXE_NAME) $(PROJECT_ROOT_PATH)
# 	make print						#调试打印变量

.PHONY: clean
clean:
	@echo "Remove linked and compiled files......"
	-rm -rf $(CCOBJS)
	-rm -rf $(EXE_NAME)
	-rm -rf $(PROJECT_ROOT_PATH)/$(EXE_NAME)

print:
	@echo $(LIBS_SO)
	@echo $(LIBS_SO_NOTDIR)
	@echo $(LIBS_SO_NOTLIB)
	@echo $(LIB_SO_OBJS)


