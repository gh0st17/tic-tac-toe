TARGET := tictactoe
DBG := -release

SRC_DIR := ./src
SRC_FILES := $(shell find $(SRC_DIR) -name "*.cpp") 
OBJ_FILES := $(patsubst %.cpp, %.o, $(notdir $(SRC_FILES)))

LIB_DIR := ./libs
LIB_FILES := $(shell find $(LIB_DIR) -name "*.cpp")
LIB_FILENAMES := $(patsubst %.cpp, lib%.a, $(notdir $(LIB_FILES)))
LIB_OBJ_FILES := $(patsubst %.cpp, %.o, $(notdir $(LIB_FILES)))

TESTS_DIR := ./tests
TESTS_FILES := $(shell find $(TESTS_DIR) -name "*.cpp")
TESTS_OBJ_FILES := $(patsubst %.cpp, %.o, $(notdir $(TESTS_FILES)))

CC := clang++
AR := llvm-ar
CXXFLAGS := -std=c++11 -Wall

.PHONY: clean clean_dSYM release debug tests done

release: CXXFLAGS += -Ofast -flto=full
release: $(TARGET) clean clean_dSYM done
debug: CXXFLAGS += -O0 -g -fsanitize=address
debug: DBG := -debug
debug: $(TARGET) clean_dSYM $(TARGET).dSYM clean done
test: CXXFLAGS += -flto=full
test: $(TARGET)-test

$(TARGET): $(LIB_FILENAMES) $(OBJ_FILES)
	@echo "\033[1;36m\nBuilding target \"$@$(DBG)\" \033[0m"
	$(CC) $(CXXFLAGS) -L$(LIB_DIR) $(patsubst lib%.a, -l%, $(LIB_FILENAMES)) -o $@ $(OBJ_FILES)

$(OBJ_FILES): $(SRC_FILES)
	@echo "\033[1;33m\nBuilding object files\033[0m"
	$(CC) $(CXXFLAGS) -c $^

$(LIB_OBJ_FILES): $(LIB_FILES)
	@echo "\033[1;33m\nBuilding libraries object files\033[0m"
	$(CC) $(CXXFLAGS) -c $^

$(LIB_FILENAMES): $(LIB_OBJ_FILES)
	@echo "\033[1;33m\nMaking static library $@\033[0m"
	$(AR) r $(LIB_DIR)/$@ $(patsubst lib%.a, %.o, $@)

$(TARGET)-test:
	@echo "\033[1;36m\nBuilding target \"$@\" \033[0m"
	$(CC) $(CXXFLAGS) $(LIB_FILES) $(TESTS_FILES) -o $@
	$(MAKE) done

$(TARGET).dSYM: $(TARGET)
	@echo "\033[1;33m\nGenerating new $(TARGET).dSYM\033[0m"
	dsymutil $<

clean:
	@echo "\033[1;31m\nCleaning up\033[0m"
	rm -f $(OBJ_FILES) $(LIB_OBJ_FILES) $(patsubst %, $(LIB_DIR)/%, $(LIB_FILENAMES))

clean_dSYM:
	@echo "\033[1;31m\nRemoving old $(TARGET).dSYM\033[0m"
	rm -rf $(TARGET).dSYM

done:
	@echo "\033[1;32m\nAll done! 🙂\033[0m"