TARGET := tictactoe

SRC_DIR := ./src

LIB_DIR := ./libs
LIB_DIRS := $(sort $(dir $(wildcard $(LIB_DIR)/*/*/)))
LIB_NAMES := $(patsubst $(LIB_DIR)/lib%/,%,$(LIB_DIRS))
LIB_FLAGS := $(patsubst %, -l%, $(LIB_NAMES))

TESTS_DIR := ./tests
TESTS_DIRS := $(sort $(dir $(wildcard $(TESTS_DIR)/testlibs/*/*/)))
TESTS_NAMES := $(patsubst $(TESTS_DIR)/testlibs/lib%/,%,$(TESTS_DIRS))
TESTS_FLAGS := $(patsubst %, -l%, $(TESTS_NAMES))

CC := clang++
AR := llvm-ar
CXXFLAGS := -std=c++11 -Wall

.PHONY: clean all $(LIB_DIRS) $(TESTS_DIRS)

all: clean $(LIB_DIRS) $(TESTS_DIRS) main.o $(TESTS_DIR)/main.o 
	$(CC) $(CXXFLAGS) \
-L$(LIB_DIR) -L$(TESTS_DIR)/testlibs/ \
$(LIB_FLAGS) $(TESTS_FLAGS) \
$(TESTS_DIR)/main.o -o $(TARGET)-test
	./$(TARGET)-test && $(CC) $(CXXFLAGS) -L$(LIB_DIR) $(LIB_FLAGS) main.o -o $(TARGET)

$(TESTS_DIRS):
	$(MAKE) -C $@

$(TESTS_DIR)/main.o: $(TESTS_DIR)/main.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

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