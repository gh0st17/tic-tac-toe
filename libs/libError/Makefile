TARGET := libError

CC := clang++
AR := llvm-ar
SLASH = /
RM = rm -f
AR_EXT := a
CXXFLAGS := -std=c++11 -Wall

.PHONY: clean

../$(TARGET).$(AR_EXT): $(TARGET).o
	$(AR) crs $@ $<

$(TARGET).o: Error.cpp
	$(CC) $(CXXFLAGS) -c $< -o $(TARGET).o

clean:
	$(RM) $(TARGET).o ..$(SLASH)$(TARGET).$(AR_EXT)