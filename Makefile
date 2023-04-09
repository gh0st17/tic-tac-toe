TARGET := tictactoe

SRC_DIR := ./src

L_FLAG := -l

LIB_DIR := ./libs
LIB_DIRS := $(sort $(dir $(wildcard $(LIB_DIR)/*/*/)))
LIB_NAMES := $(patsubst $(LIB_DIR)/lib%/,%,$(LIB_DIRS))
LIB_FLAGS := $(patsubst %, $(L_FLAG)%, $(LIB_NAMES))

TESTS_DIR := ./tests
TESTS_DIRS := $(sort $(dir $(wildcard $(TESTS_DIR)/testlibs/*/*/)))
TESTS_NAMES := $(patsubst $(TESTS_DIR)/testlibs/lib%/,%,$(TESTS_DIRS))
TESTS_FLAGS := $(patsubst %, $(L_FLAG)%, $(TESTS_NAMES))

CC := clang++
CXXFLAGS := -std=c++11 -Wall

.PHONY: clean all $(LIB_DIRS) $(TESTS_DIRS)

all: $(LIB_DIRS) $(TESTS_DIRS) main.o $(TESTS_DIR)/main.o 
	$(CC) $(CXXFLAGS) \
-L$(LIB_DIR) -L$(TESTS_DIR)/testlibs/ \
$(LIB_FLAGS) $(TESTS_FLAGS) \
$(TESTS_DIR)/main.o -o $(TARGET)-test$(EXE)
	$(TARGET)-test$(EXE) && $(CC) $(CXXFLAGS) -L$(LIB_DIR) $(LIB_FLAGS) main.o -o $(TARGET)$(EXE)

$(TESTS_DIRS):
ifdef OS
	$(MAKE) -C $@ AR_EXT=lib
else
	$(MAKE) -C $@
endif

$(TESTS_DIR)/main.o: $(TESTS_DIR)/main.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(LIB_DIRS):
ifdef OS
	$(MAKE) -C $@ AR_EXT=lib
else
	$(MAKE) -C $@
endif

main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CXXFLAGS) -c $<

ifdef OS
clean: LIB_DIRS_2 := $(subst /,\,$(LIB_DIRS))
clean: LIB_DIRS_2 := $(patsubst %,$(MAKE) -C % clean SLASH=\ AR_EXT=lib RM="del /q";,$(LIB_DIRS_2))
clean: TESTS_DIRS_2 := $(subst /,\,$(TESTS_DIRS))
endif
clean:
ifdef OS
	@echo $(LIB_DIRS_2)
	$(LIB_DIRS_2)
	$(foreach dir, $(TESTS_DIRS), $(MAKE) -C $(dir) clean SLASH=\ AR_EXT=lib RM="del /q";)
	del /q main.o
else
	$(foreach dir, $(LIB_DIRS), $(MAKE) -C $(dir) clean;)
	$(foreach dir, $(TESTS_DIRS), $(MAKE) -C $(dir) clean;)
	rm -f main.o
endif