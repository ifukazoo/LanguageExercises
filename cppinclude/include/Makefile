#Makefile

TEST_PROGRAM := testp

all:   $(TEST_PROGRAM)
	./$(TEST_PROGRAM)

# release1.7.0
GTEST_DIR     := ~/github/googletest
GTEST_INCLUDE := $(GTEST_DIR)/include
GTEST_LIB_DIR := $(GTEST_DIR)/make

CPPFLAGS := -I ../../cppinclude/include -std=c++11 -Wall -Wextra -MMD -MP
$(TEST_PROGRAM): CPPFLAGS := -I $(GTEST_INCLUDE)

$(TEST_PROGRAM): LDFLAGS := -L $(GTEST_LIB_DIR)
$(TEST_PROGRAM): LDLIBS  := -l:gtest_main.a -lpthread

-include *.d

.PHONY:clean all
clean:
	rm -rf $(TEST_PROGRAM) *.d *.o core tags
