TARGET := main.o

CC := clang++
RM = rm -f
CXXFLAGS := -std=c++11 -Wall

.PHONY: clean

$(TARGET): main.cpp
	$(CC) $(CXXFLAGS) -c $< -o $(TARGET)

clean:
	$(RM) $(TARGET)