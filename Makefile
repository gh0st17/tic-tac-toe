TARGET := tictactoe

SRC_DIR := ./src
L_FLAG  := -l

LIB_DIR   := ./libs
LIB_DIRS  := $(sort $(dir $(wildcard $(LIB_DIR)/*/*/)))
LIB_NAMES := $(patsubst $(LIB_DIR)/lib%/,%,$(LIB_DIRS))
LIB_FLAGS := $(patsubst %,$(L_FLAG)%,$(LIB_NAMES))

TESTS_DIR   := ./tests
TESTS_DIRS  := $(sort $(dir $(wildcard $(TESTS_DIR)/testlibs/*/*/)))
TESTS_NAMES := $(patsubst $(TESTS_DIR)/testlibs/lib%/,%,$(TESTS_DIRS))
TESTS_FLAGS := $(patsubst %,$(L_FLAG)%,$(TESTS_NAMES))

CC := clang++
CXXFLAGS := -std=c++11 -Wall

.PHONY: clean all $(LIB_DIRS) $(TESTS_DIRS)
all: $(ifneq )
all: clean $(LIB_DIRS) $(TESTS_DIRS) main.o $(TESTS_DIR)/main.o 
	$(CC) $(CXXFLAGS) $(TESTS_DIR)/main.o \
-L$(TESTS_DIR)/testlibs/ $(TESTS_FLAGS) \
-L$(LIB_DIR) $(LIB_FLAGS) \
-o $(TARGET)-test$(EXE)
ifdef OS
	.\$(TARGET)-test$(EXE) && $(CC) $(CXXFLAGS) main.o -L$(LIB_DIR) $(LIB_FLAGS) -o $(TARGET)$(EXE)
else
	./$(TARGET)-test$(EXE) && $(CC) $(CXXFLAGS) main.o -L$(LIB_DIR) $(LIB_FLAGS) -o $(TARGET)$(EXE)
endif

$(TESTS_DIRS):
ifdef OS
	$(MAKE) -C $@ AR_EXT=$(AR_EXT) CC=$(CC) AR=$(AR)
else
	$(MAKE) -C $@
endif

$(TESTS_DIR)/main.o: $(TESTS_DIR)/main.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(LIB_DIRS):
ifdef OS
	$(MAKE) -C $@ AR_EXT=$(AR_EXT) CC=$(CC) AR=$(AR)
else
	$(MAKE) -C $@
endif

main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CXXFLAGS) -c $<

clean:
ifdef OS
	del /q /s *.o *.lib *.a
else
	$(foreach dir, $(LIB_DIRS), $(MAKE) -C $(dir) clean;)
	$(foreach dir, $(TESTS_DIRS) $(TESTS_DIR), $(MAKE) -C $(dir) clean;)
	rm -f main.o
endif