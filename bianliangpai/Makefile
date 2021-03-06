CC=g++

CXX_RELEASE_FLAGS=-O3 -fpermissive -fPIC -std=c++11
CXX_DEBUG_FLAGS=-g -O0 -fpermissive -fPIC -DDEBUG -std=c++11
CXX_TEST_FLAGS=$(CXX_DEBUG_FLAGS)
CXX_PROFILE_FLAGS=$(CXX_RELEASE_FLAGS) -pg

SRCS_DIR=src
SRCS=$(wildcard $(SRCS_DIR)/${ID}.cpp)
TEST_SRCS_DIR=test
TEST_SRCS=$(wildcard $(TEST_SRCS_DIR)/${ID}_test.cpp)

INC_DIR=-Iinc

LIBRARY_DIR=
TEST_LIBRARY_DIR=

LIBRARIES=
TEST_LIBRARIES=-lgtest -lpthread

TARGET_DIR=out

RELEASE_TARGET=release
DEBUG_TARGET=debug
TEST_TARGET=unittest
PROFILE_TARGET=profile

all: $(RELEASE_TARGET) $(DEBUG_TARGET) $(TEST_TARGET)

$(RELEASE_TARGET): $(SRCS)
	mkdir -p out
	$(CC) $(SRCS)      $(INC_DIR) $(CXX_RELEASE_FLAGS) $(LIBRARY_DIR)      $(LIBRARIES)      -o $(TARGET_DIR)/${ID}_$(RELEASE_TARGET)

$(DEBUG_TARGET): $(SRCS)
	mkdir -p out
	$(CC) $(SRCS)      $(INC_DIR) $(CXX_DEBUG_FLAGS)   $(LIBRARY_DIR)      $(LIBRARIES)      -o $(TARGET_DIR)/${ID}_$(DEBUG_TARGET)

$(TEST_TARGET): $(TEST_SRCS)
	mkdir -p out
	$(CC) $(TEST_SRCS) $(INC_DIR) $(CXX_TEST_FLAGS)    $(TEST_LIBRARY_DIR) $(TEST_LIBRARIES) -o $(TARGET_DIR)/${ID}_$(TEST_TARGET)

$(PROFILE_TARGET): $(SRCS)
	mkdir -p out
	$(CC) $(SRCS)      $(INC_DIR) $(CXX_PROFILE_FLAGS) $(LIBRARY_DIR)      $(LIBRARIES)      -o $(TARGET_DIR)/${ID}_$(PROFILE_TARGET)


clean:
	if [ -d "out" ]; then rm -r out; fi;