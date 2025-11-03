# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror=sign-compare -Werror=delete-non-virtual-dtor -Wextra -g -fprofile-arcs -ftest-coverage
LDFLAGS = -fprofile-arcs -ftest-coverage

# Try to detect SFML via pkg-config
SFML_CFLAGS := $(shell pkg-config --cflags sfml-all 2>/dev/null)
SFML_LIBS := $(shell pkg-config --libs sfml-all 2>/dev/null)

# Fallback if pkg-config fails
ifeq ($(SFML_LIBS),)
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
endif


# Directories
SRC_DIR = .
TEST_DIR = .
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Source files
COMMON_SRC = $(filter-out DemoMain.cpp UnitTest.cpp TestingMain.cpp, $(wildcard *.cpp))
DEMO_SRC = DemoMain.cpp $(COMMON_SRC)
TEST_SRC = UnitTest.cpp $(COMMON_SRC)
TEST_MAIN_SRC = TestingMain.cpp $(COMMON_SRC)

# Object files
DEMO_OBJECTS = $(DEMO_SRC:%.cpp=$(OBJ_DIR)/%.o)
DEMO_OBJ = $(DEMO_OBJECTS)
TEST_OBJECTS = $(TEST_SRC:%.cpp=$(OBJ_DIR)/%.o)
TEST_OBJ = $(TEST_OBJECTS)
TEST_MAIN_OBJECTS = $(TEST_MAIN_SRC:%.cpp=$(OBJ_DIR)/%.o)
TEST_MAIN_OBJ = $(TEST_MAIN_OBJECTS)

MAIN_SRC = $(COMMON_SRC)
MAIN_OBJECTS = $(MAIN_SRC:%.cpp=$(OBJ_DIR)/%.o)
MAIN_OBJ = $(MAIN_OBJECTS)
MAIN_TARGET = MainTest

# Compile and link main test
$(BUILD_DIR)/$(MAIN_TARGET): $(MAIN_OBJ) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SFML_CFLAGS) -o $@ $(MAIN_OBJ) $(LDFLAGS) $(SFML_LIBS)

run_main: $(BUILD_DIR)/$(MAIN_TARGET)
	./$(BUILD_DIR)/$(MAIN_TARGET)

gdb_main: $(BUILD_DIR)/$(MAIN_TARGET)
	gdb ./$(BUILD_DIR)/$(MAIN_TARGET)

valgrind_main: $(BUILD_DIR)/$(MAIN_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/$(MAIN_TARGET)

coverage_main: $(BUILD_DIR)/$(MAIN_TARGET)
	@echo "Running main test to generate coverage data..."
	./$(BUILD_DIR)/$(MAIN_TARGET)
	@echo "Generating coverage report..."
	gcov -o $(OBJ_DIR) *.cpp
	@echo "Coverage report generated (.gcov files)."

.PHONY: all run_demo run_test run_test_main run_main run_all \
        gdb_demo gdb_test gdb_test_main gdb_main \
        valgrind_demo valgrind_test valgrind_test_main valgrind_main \
        doxy clean \
        coverage_demo coverage_test coverage_test_main coverage_main coverage_all


# Output executables
DEMO_TARGET = DemoMain
TEST_TARGET = UnitTest
TEST_MAIN_TARGET = TestingMain

# Default target: compile all three
all: $(BUILD_DIR)/$(DEMO_TARGET) $(BUILD_DIR)/$(TEST_TARGET) $(BUILD_DIR)/$(TEST_MAIN_TARGET)

# Create build directories
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Compile and Linking demo
$(BUILD_DIR)/$(DEMO_TARGET): $(DEMO_OBJ) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SFML_CFLAGS) -o $@ $(DEMO_OBJ) $(LDFLAGS) $(SFML_LIBS)

# Compile and Linking unit test
$(BUILD_DIR)/$(TEST_TARGET): $(TEST_OBJ) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SFML_CFLAGS) -o $@ $(TEST_OBJ) $(LDFLAGS) $(SFML_LIBS)

# Compile and Linking testing main
$(BUILD_DIR)/$(TEST_MAIN_TARGET): $(TEST_MAIN_OBJ) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SFML_CFLAGS) -o $@ $(TEST_MAIN_OBJ) $(LDFLAGS) $(SFML_LIBS)

# Compiling rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run programs
run_demo: $(BUILD_DIR)/$(DEMO_TARGET)
	./$(BUILD_DIR)/$(DEMO_TARGET)

run_test: $(BUILD_DIR)/$(TEST_TARGET)
	./$(BUILD_DIR)/$(TEST_TARGET)

run_test_main: $(BUILD_DIR)/$(TEST_MAIN_TARGET)
	./$(BUILD_DIR)/$(TEST_MAIN_TARGET)

# Run all executables
run_all: run_demo run_test run_test_main

# Run gdb (specify which target)
gdb_demo: $(BUILD_DIR)/$(DEMO_TARGET)
	gdb ./$(BUILD_DIR)/$(DEMO_TARGET)

gdb_test: $(BUILD_DIR)/$(TEST_TARGET)
	gdb ./$(BUILD_DIR)/$(TEST_TARGET)

gdb_test_main: $(BUILD_DIR)/$(TEST_MAIN_TARGET)
	gdb ./$(BUILD_DIR)/$(TEST_MAIN_TARGET)

# Run with Valgrind
valgrind_demo: $(BUILD_DIR)/$(DEMO_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/$(DEMO_TARGET)

valgrind_test: $(BUILD_DIR)/$(TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/$(TEST_TARGET)

valgrind_test_main: $(BUILD_DIR)/$(TEST_MAIN_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/$(TEST_MAIN_TARGET)

# Generate documentation with Doxygen
doxy:
	doxygen Doxyfile

# Clean build files
clean:
	rm -rf $(BUILD_DIR) *.gcda *.gcno *.gcov

# Generate coverage reports
coverage_demo: $(BUILD_DIR)/$(DEMO_TARGET)
	@echo "Running demo to generate coverage data..."
	./$(BUILD_DIR)/$(DEMO_TARGET)
	@echo "Generating coverage report..."
	gcov -o $(OBJ_DIR) *.cpp
	@echo "Coverage report generated (.gcov files)."

coverage_test: $(BUILD_DIR)/$(TEST_TARGET)
	@echo "Running unit tests to generate coverage data..."
	./$(BUILD_DIR)/$(TEST_TARGET)
	@echo "Generating coverage report..."
	gcov -o $(OBJ_DIR) *.cpp
	@echo "Coverage report generated (.gcov files)."

coverage_test_main: $(BUILD_DIR)/$(TEST_MAIN_TARGET)
	@echo "Running testing main to generate coverage data..."
	./$(BUILD_DIR)/$(TEST_MAIN_TARGET)
	@echo "Generating coverage report..."
	gcov -o $(OBJ_DIR) *.cpp
	@echo "Coverage report generated (.gcov files)."

# Generate combined coverage from all executables
coverage_all: $(BUILD_DIR)/$(DEMO_TARGET) $(BUILD_DIR)/$(TEST_TARGET) $(BUILD_DIR)/$(TEST_MAIN_TARGET)
	@echo "Running all executables to generate combined coverage data..."
	./$(BUILD_DIR)/$(DEMO_TARGET)
	./$(BUILD_DIR)/$(TEST_TARGET)
	./$(BUILD_DIR)/$(TEST_MAIN_TARGET)
	@echo "Generating coverage report..."
	gcov -o $(OBJ_DIR) *.cpp
	@echo "Combined coverage report generated (.gcov files)."

.PHONY: all run_demo run_test run_test_main run_all gdb_demo gdb_test gdb_test_main \
        valgrind_demo valgrind_test valgrind_test_main doxy clean \
        coverage_demo coverage_test coverage_test_main coverage_all