TARGET := tictactoe

SRC_DIR := ./src

LIB_DIR := ./libs
LIB_DIRS := $(wildcard $(LIB_DIR)/*/)

TESTS_DIR := ./tests
TESTS_DIRS := $(wildcard $(TESTS_DIR)/testlibs/*/) $(TESTS_DIR)

CC := clang++
AR := llvm-ar
CXXFLAGS := -std=c++11 -Wall

.PHONY: clean libs all $(LIB_DIRS) $(TESTS_DIRS)

all: $(LIB_DIRS) $(TESTS_DIRS) main.o
	$(CC) $(CXXFLAGS) *.a $(TESTS_DIR)/*.a $(TESTS_DIR)/main.o -o $(TARGET)-test
	./$(TARGET)-test && $(CC) $(CXXFLAGS) *.a main.o -o $(TARGET)

$(TESTS_DIRS):
	$(info "$@")
	$(MAKE) -C $@

$(LIB_DIRS):
	$(MAKE) -C $@

main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CXXFLAGS) -c $<

clean:
	@for dir in $(LIB_DIRS); do \
			$(MAKE) -C $$dir clean; \
	done
	@for dir in $(TESTS_DIRS); do \
			$(MAKE) -C $$dir clean; \
	done
	rm -f main.o