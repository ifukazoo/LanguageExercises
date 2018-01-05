#Makefile

# 変数定義
PROGRAM       := main
TEST          := unit_test
OBJS          := karvonen.o

GTEST_DIR     := ~/github/googletest      # release1.7.0
GTEST_INCLUDE := $(GTEST_DIR)/include
GTEST_LIB_DIR := $(GTEST_DIR)/make

# 依存関係
$(PROGRAM): $(OBJS)
$(TEST)   : $(OBJS)

# ビルドオプション
CPPFLAGS := -Wall -Wextra -std=c++11
$(PROGRAM): CPPFLAGS += -MMD -MP
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
