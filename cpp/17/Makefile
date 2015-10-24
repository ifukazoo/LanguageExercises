#Makefile

PRODUCTION = \
	p\

TEST = \
	testp\

GTEST_DIR = /opt/gtest/gtest-1.7.0
GTEST_HEADER_DIR = $(GTEST_DIR)/include
GTEST_LIB_DIR = $(GTEST_DIR)/make
GTEST_LIB = gtest_main.a
GTEST_CFLAG = -I $(GTEST_HEADER_DIR) -L $(GTEST_LIB_DIR) -l:$(GTEST_LIB) -lpthread

LOCAL_INCLUDE_DIR = ../include
CC     =  g++
CFLAGS = -g -Wall -Wextra -MD

all: $(PRODUCTION)
test: $(PRODUCTION) $(TEST)
	./$(TEST)

ifeq ($(MAKECMDGOALS), test)
CFLAGS += $(GTEST_CFLAG)
endif

%:%.cc
	$(CC) $< $(CFLAGS) -I $(LOCAL_INCLUDE_DIR) -o $*

-include *.d

.PHONY:clean
clean:
	rm -rf $(PRODUCTION) $(TEST) *.d *.o core tags
