SOURCE = $(wildcard *.c)  
OBJS = $(patsubst %.c,%,$(SOURCE))  
      
#CROSS_COMPILE = arm-linux-  
CC = gcc  
  
#CFLAGS += -g -O2  -Wall -Werror -Wno-unused
CFLAGS += -g
#CLFAGS += -Wall   
LDFLAGS += -lm  
      
all:$(OBJS) 
#.PHONY: all

#.PHONY:clean 
clean:  
	rm -f $(OBJS)
  
#include $(SOURCE:.c=.d)   
      
%:%.c  
	$(CC) $(CFLAGS)  -o $@ $^
