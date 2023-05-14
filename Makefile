TARGET := tictactoe

SRC_DIR := ./src
L_FLAG  := -l
AR_EXT  := a

LIB_DIR   := ./libs
LIB_DIRS  := $(sort $(dir $(wildcard $(LIB_DIR)/*/*/)))
LIB_NAMES := $(patsubst $(LIB_DIR)/lib%/,%,$(LIB_DIRS))
LIB_FLAGS := $(patsubst %,$(L_FLAG)%,$(LIB_NAMES))

CC := clang++
AR := llvm-ar
CXXFLAGS := -std=c++11 -Wall

.PHONY: clean all $(LIB_DIRS)

all: clean $(LIB_DIRS) main.o $(TESTS_DIR)/$(TARGET)-test
ifdef OS
	cd .\tests && .\$(TARGET)-test$(EXE) && cd .. && \
$(CC) $(CXXFLAGS) main.o -L$(LIB_DIR) $(LIB_FLAGS) -o $(TARGET)$(EXE)
else
	cd ./tests && ./$(TARGET)-test && cd .. && \
$(CC) $(CXXFLAGS) main.o -L$(LIB_DIR) $(LIB_FLAGS) -o $(TARGET)
endif

$(TESTS_DIR)/$(TARGET)-test:
ifdef OS
	$(MAKE) -C .\tests AR_EXT=$(AR_EXT) CC=$(CC) AR=$(AR) L_FLAG=$(L_FLAG)
else
	$(MAKE) -C ./tests AR_EXT=$(AR_EXT) CC=$(CC) AR=$(AR) L_FLAG=$(L_FLAG) CXXFLAGS="$(CXXFLAGS)"
endif

$(LIB_DIRS):
	$(MAKE) -C $@ AR_EXT=$(AR_EXT) CC=$(CC) AR=$(AR) CXXFLAGS="$(CXXFLAGS)"

main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CXXFLAGS) -c $<

clean:
ifdef OS
	del /q /s *.o *.lib *.a
else
	$(foreach dir, $(LIB_DIRS), $(MAKE) -C $(dir) clean;)
	rm -f main.o
endif
