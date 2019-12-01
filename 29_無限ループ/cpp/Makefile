#Makefile

# 変数定義
PROGRAM       := main
TEST          := unit_test

# release1.8.0
GTEST_DIR     := ~/github/googletest
GTEST_INCLUDE := $(GTEST_DIR)/googletest/include
GTEST_LIB_DIR := $(GTEST_DIR)/googletest/make

# 依存関係
$(PROGRAM): $(OBJS)
$(TEST)   : $(OBJS)

# ビルドオプション
CPPFLAGS := -Wall -Wextra -std=c++11
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
