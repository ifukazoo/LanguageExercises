#Makefile

PROGRAM      := p
TEST_PROGRAM := testp

all:   $(PROGRAM)
debug: $(PROGRAM)
test:  $(PROGRAM) $(TEST_PROGRAM)
	./$(TEST_PROGRAM)

GTEST_DIR     := /opt/gtest/gtest-1.7.0
GTEST_INCLUDE := $(GTEST_DIR)/include
GTEST_LIB_DIR := $(GTEST_DIR)/make

CPPFLAGS := -I ../include -std=c++11 -Wall -Wextra -MMD -MP
debug:           CPPFLAGS += -pg
$(TEST_PROGRAM): gtest_main.a -lpthread
$(TEST_PROGRAM): CPPFLAGS := -I $(GTEST_INCLUDE)
vpath %.a $(GTEST_LIB_DIR)

-include *.d

.PHONY:clean all debug test
clean:
	rm -rf $(PROGRAM) $(TEST_PROGRAM) *.d *.o core tags
