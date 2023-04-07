TARGET := libtestUI

CC := clang++
AR := llvm-ar
CXXFLAGS := -Wall

.PHONY: clean

../../$(TARGET).a: $(TARGET).o
	$(AR) crs $@ $<

$(TARGET).o: UI_test.cpp
	$(CC) $(CXXFLAGS) -c $< -o $(TARGET).o

clean:
	rm -f $(TARGET).o ../../$(TARGET).a