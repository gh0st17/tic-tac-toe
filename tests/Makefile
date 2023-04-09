TARGET := main.o

CC := clang++
AR := llvm-ar
RM = rm -f
AR_EXT := a
CXXFLAGS := -std=c++11 -Wall

.PHONY: clean

$(TARGET): main.cpp
	$(CC) $(CXXFLAGS) -c $< -o $(TARGET)

clean:
	$(RM) $(TARGET)