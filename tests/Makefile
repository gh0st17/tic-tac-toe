TARGET := main.o

CC := clang++
AR := llvm-ar
CXXFLAGS := -std=c++11 -Wall

.PHONY: clean

$(TARGET): main.cpp
	$(CC) $(CXXFLAGS) -c $< -o $(TARGET)

clean:
	rm -f $(TARGET)