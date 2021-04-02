CC = g++
CFLAGS = -Wall
TARGET = time
SOURCE_FILES = $(wildcard ./*.cpp)
OBJECT_FILES = $(SOURCE_FILES:%.cpp=%.o)

$(TARGET): $(OBJECT_FILES)
	$(CC) $(CFLAGS) $^ -o $@

OBJECT_FILES: SOURCE_FILES myTime.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET)
	rm -f $(OBJECT_FILES)
