TARGET := tictactoe-test

SRC_DIR := ./src
L_FLAG  := -l
AR_EXT  := a

LIB_DIR := ../libs
LIB_DIRS  := $(sort $(dir $(wildcard $(LIB_DIR)/*/*/)))
LIB_NAMES := $(patsubst $(LIB_DIR)/lib%/,%,$(LIB_DIRS))
LIB_FLAGS := $(patsubst %,$(L_FLAG)%,$(LIB_NAMES))

TESTS_DIRS  := $(sort $(dir $(wildcard ./testlibs/*/*/)))
TESTS_NAMES := $(patsubst ./testlibs/lib%/,%,$(TESTS_DIRS))
TESTS_FLAGS := $(patsubst %,$(L_FLAG)%,$(TESTS_NAMES))

CC := clang++
AR := llvm-ar
CXXFLAGS := -std=c++11 -Wall

.PHONY: clean all $(TESTS_DIRS)

all: clean $(TESTS_DIRS) main.o
	$(CC) $(CXXFLAGS) main.o \
-L./testlibs $(TESTS_FLAGS) \
-L$(LIB_DIR) $(LIB_FLAGS) -o $(TARGET)$(EXE)

$(TESTS_DIRS):
	$(MAKE) -C $@ AR_EXT=$(AR_EXT) CC=$(CC) AR=$(AR) CXXFLAGS="$(CXXFLAGS)"

main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CXXFLAGS) -c $<

clean:
ifdef OS
	del /q /s *.o *.lib *.a
else
	$(foreach dir, $(TESTS_DIRS) $(TESTS_DIR),$(MAKE) -C $(dir) clean;)
	rm -f main.o
endif