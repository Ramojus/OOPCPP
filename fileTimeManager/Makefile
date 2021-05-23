CC = g++
CFLAGS = -Wall
INCLUDES = -I$(LIB_DIR)

TARGET = fileTimeManager

SOURCE_DIR = src
LIB_DIR = lib

SOURCE_FILES = $(wildcard $(SOURCE_DIR)/*.cpp $(LIB_DIR)/*.cpp !(main.cpp))
OBJECT_FILES = $(SOURCE_FILES:%.cpp=%.o)
HEADER_FILES = $(wildcard $(SOURCE_DIR)/*.h $(LIB_DIR)/*.h)

all: $(TARGET)

$(TARGET): $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.cpp $(SOURCE_DIR)/%.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIB_DIR)/%.o: $(LIB_DIR)/%.cpp $(LIB_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

deploy:
	git add .
	git commit
	git push

rebuild: clean all

clean:
	rm -f $(TARGET)
	rm -f $(OBJECT_FILES)

.PHONY: all clean rebuild deploy
