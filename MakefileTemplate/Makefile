PROJECT_ROOT_PATH=$(shell pwd)
VERSION  = 1.0.0

MFLAGS = "CFLAGS=-w"
DFLAGS = "CFLAGS=-w -g -fPIC -DDEBUG -DREENTRANT"

    
#如果想编译静态库 指定TARGET_AR=1即可	
all :
	cd $(PROJECT_ROOT_PATH)/src/bar && $(MAKE) $(DFLAGS) TARGET_SO=1 && $(MAKE) install TARGET_SO=1		
	cd $(PROJECT_ROOT_PATH)/src/foo && $(MAKE) $(DFLAGS) TARGET_AR=1 && $(MAKE) install TARGET_AR=1
	cd $(PROJECT_ROOT_PATH)/src/test && $(MAKE) $(DFLAGS) && $(MAKE) install 

.PHONY: clean
clean :
	@echo "Remove linked and compiled files......"
	cd $(PROJECT_ROOT_PATH)/src/bar && $(MAKE) clean TARGET_SO=1
	cd $(PROJECT_ROOT_PATH)/src/foo && $(MAKE) clean TARGET_AR=1
	cd $(PROJECT_ROOT_PATH)/src/test && $(MAKE) clean
	-rm -rf $(CCOBJS)
	-rm -rf $(TARGET)
	-rm -rf $(PROJECT_ROOT_PATH)/lib/$(TARGET)

#export出来的变量将被子make进程继承。 如果在确定是需要这种方式去传输变量，那么可以在子Makefile中注释相关的变量。相当于export全局变量
export PROJECT_ROOT_PATH VERSION
