#Makefile

# 変数定義
PROGRAM       := main
TEST          := unit_test
OBJS          := anagram.o
INCLUDE       := ../include
GTEST_DIR     := /opt/gtest/gtest-1.7.0
GTEST_INCLUDE := $(GTEST_DIR)/include
GTEST_LIB_DIR := $(GTEST_DIR)/make

# 依存関係
$(PROGRAM): $(OBJS)
$(TEST)   : $(OBJS)

# ビルドオプション
CPPFLAGS := -I $(INCLUDE) -std=c++11 -Wall -Wextra
$(PROGRAM): CPPFLAGS += -MMD -MP
$(OBJS)   : CPPFLAGS += -MMD -MP
$(TEST)   : CPPFLAGS += -I $(GTEST_INCLUDE)
$(TEST)   : LDFLAGS  := -L $(GTEST_LIB_DIR)
$(TEST)   : LDLIBS   := -l:gtest_main.a -lpthread
debug     : CPPFLAGS += -pg

-include *.d

# makeターゲット
all:   $(PROGRAM)
test:  $(TEST)
	./$(TEST)
debug: $(PROGRAM)
.PHONY:clean
clean:
	rm -rf $(PROGRAM) $(TEST) $(OBJS) *.d *.out core tags
