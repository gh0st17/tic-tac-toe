TARGET := main.o

CC := clang++
AR := llvm-ar
CXXFLAGS := -Wall

.PHONY: clean

$(TARGET): main.cpp
	$(CC) $(CXXFLAGS) -c $< -o $(TARGET)

clean:
	rm -f $(TARGET)