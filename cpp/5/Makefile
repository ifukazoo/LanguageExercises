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
$(TEST_PROGRAM): CPPFLAGS := -I $(GTEST_INCLUDE)

$(TEST_PROGRAM): LDFLAGS := -L $(GTEST_LIB_DIR)
$(TEST_PROGRAM): LDLIBS  := -l:gtest_main.a -lpthread

-include *.d

.PHONY:clean all debug test
clean:
	rm -rf $(PROGRAM) $(TEST_PROGRAM) *.d *.o core tags
