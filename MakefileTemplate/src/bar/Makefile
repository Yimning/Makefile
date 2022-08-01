LIB_NAME = libbar

PROJECT_ROOT_PATH = /home/yimning/MakefileTemplate
VERSION     = 1.0.0

CCSRCS	= $(wildcard *.c)
CCOBJS = $(patsubst %.c,%.o, $(CCSRCS))

CC = gcc
DEBUG   =-DUSE_DEBUG
CFLAGS  =-Wall
AR = ar
ARFLAGS = -rv
SOFLAGS = -fPIC -shared
INCPATH = -I$(PROJECT_ROOT_PATH)/include
LDFLAGS = -L.
LIB_NAMES =  

#links
ifdef TARGET_SO
	TARGET = $(LIB_NAME).$(VERSION).so
endif

ifdef TARGET_AR
	TARGET = $(LIB_NAME).$(VERSION).a
endif

ifdef TARGET_SO
$(TARGET): $(CCOBJS)
	$(CC) $(SOFLAGS) $^ -o $@ $(LDFLAGS) $(LIB_NAMES)
endif

ifdef TARGET_AR
$(TARGET):$(CCOBJS)
	$(AR) $(ARFLAGS) $@ $^
endif

#compile
$(CCOBJS): %.o: %.c
	$(CC) $(INCPATH) $(CFLAGS) -c $< -o $@
	
.PHONY: install
install:
	mkdir -p $(PROJECT_ROOT_PATH)/lib
	cp $(TARGET) $(PROJECT_ROOT_PATH)/lib
	
.PHONY: clean
clean:
	@echo "Remove linked and compiled files......"
	-rm -rf $(CCOBJS)
	-rm -rf $(TARGET)
	-rm -rf $(PROJECT_ROOT_PATH)/include/$(LIB_NAME)
	-rm -rf $(PROJECT_ROOT_PATH)/lib/$(TARGET)

