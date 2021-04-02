CC = g++
CFLAGS = -Wall
INCLUDES = -I$(LIB_DIR)

TARGET = time
MAIN = main
TEST = test
TEST_OUTPUT = test_output.txt
TEST_RUN = ./$(TEST) -nv=1 -fc=1 | tee "$(TEST_OUTPUT)"
DOC = doxygen Doxyfile

SOURCE_DIR = src
LIB_DIR = lib

SOURCE_FILES = $(wildcard $(SOURCE_DIR)/*.cpp $(LIB_DIR)/*.cpp)
OBJECT_FILES = $(SOURCE_FILES:%.cpp=%.o)
HEADER_FILES = $(wildcard $(SOURCE_DIR)/*.h $(LIB_DIR)/*.h)

TARGET_SOURCE_FILES = $(OBJECT_FILES) $(MAIN).o
TARGET_OBJECT_FILES = $(TARGET_SOURCE_FILES:%.cpp=%.o)

TEST_SOURCE_FILES = $(OBJECT_FILES) $(TEST).o
TEST_OBJECT_FILES = $(TEST_SOURCE_FILES:%.cpp=%.o)
TEST_HEADER_FILES = $(HEADER_FILES) doctest.h

all: $(TARGET)

$(TARGET): $(TARGET_OBJECT_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(MAIN).o: $(MAIN).cpp $(SOURCE_DIR)/time.h $(LIB_DIR)/locatedException.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.cpp $(SOURCE_DIR)/%.h $(LIB_DIR)/locatedException.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIB_DIR)/%.o: $(LIB_DIR)/%.cpp $(LIB_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@


build_test: $(TEST_OBJECT_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $(TEST)

$(TEST).o: $(TEST).cpp $(TEST_HEADER_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

run_test:
	$(TEST_RUN)

test: build_test run_test

doc:
	$(DOC)

deploy:
	git add .
	git commit
	git push

rebuild: clean all

clean:
	rm -f $(TARGET)
	rm -f $(OBJECT_FILES)
	rm -f $(MAIN).o
	rm -f $(TEST)
	rm -f $(TEST).o
	rm -f $(TEST_OUTPUT)

.PHONY: all clean rebuild build_test run_test test doc deploy
