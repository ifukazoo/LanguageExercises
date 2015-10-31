#Makefile

PRODUCTION := p

TEST_PROG := testp

GTEST_DIR := /opt/gtest/gtest-1.7.0
GTEST_INCLUDE := $(GTEST_DIR)/include
GTEST_LIB_DIR := $(GTEST_DIR)/make

CPPFLAGS := -I ../include -std=c++11 -Wall -Wextra -MMD -MP

all: $(PRODUCTION)
test: $(PRODUCTION) $(TEST_PROG)
	./$(TEST_PROG)

$(TEST_PROG): CPPFLAGS := -I $(GTEST_INCLUDE)
$(TEST_PROG): LDFLAGS  := -L $(GTEST_LIB_DIR)
$(TEST_PROG): LDLIBS := -l:gtest_main.a -lpthread

debug: CPPFLAGS += -g
debug: $(PRODUCTION)

-include *.d

.PHONY:clean test
clean:
	rm -rf $(PRODUCTION) $(TEST_PROG) *.d *.o core tags
