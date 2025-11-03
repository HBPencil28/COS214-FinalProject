# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror=sign-compare -Werror=delete-non-virtual-dtor -Wextra -g -fprofile-arcs -ftest-coverage
LDFLAGS = -fprofile-arcs -ftest-coverage

# Explicitly list source files needed for TestingMain based on included headers
TEST_MAIN_COMMON_SRC = Plant.cpp Zone.cpp CareStaff.cpp LowCare.cpp MediumCare.cpp \
                       HighCare.cpp WaterPlant.cpp FertilisePlant.cpp CareCommand.cpp \
                       CareStrategy.cpp Inventory.cpp PlantIterator.cpp Seedling.cpp \
                       Growing.cpp Mature.cpp Withered.cpp NurseryMediator.cpp \
                       CustomerStaff.cpp BuildPlantDirector.cpp PotPlantBuilder.cpp \
                       PottedPlant.cpp WrapPlantBuilder.cpp WrappedPlant.cpp \
                       CustomisePlant.cpp DiscardPlant.cpp PlantPot.cpp PlantSoil.cpp \
                       PlantWrap.cpp PlantDecorator.cpp Bow.cpp Ribbon.cpp BasePlant.cpp

# Source files for other targets (using wildcard)
COMMON_SRC = $(filter-out DemoMain.cpp UnitTest.cpp TestingMain.cpp, $(wildcard *.cpp))
DEMO_SRC = DemoMain.cpp $(COMMON_SRC)
TEST_SRC = UnitTest.cpp $(COMMON_SRC)
TEST_MAIN_SRC = TestingMain.cpp $(TEST_MAIN_COMMON_SRC)

# Object files
DEMO_OBJ = $(DEMO_SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_MAIN_OBJ = $(TEST_MAIN_SRC:.cpp=.o)

# Output executables
DEMO_TARGET = DemoMain
TEST_TARGET = UnitTest # to run valgrind, we will then use make valgrind_test 
# file UnitTest is under TESt_TARGET
TEST_MAIN_TARGET = TestingMain

# Default target: compile only TestingMain
all: $(TEST_MAIN_TARGET)

# Build all three executables
all_targets: $(DEMO_TARGET) $(TEST_TARGET) $(TEST_MAIN_TARGET)

# Linking demo
$(DEMO_TARGET): $(DEMO_OBJ)
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) $(DEMO_OBJ) $(LDFLAGS)

# Linking unit test
$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ) $(LDFLAGS)

# Linking testing main
$(TEST_MAIN_TARGET): $(TEST_MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_MAIN_TARGET) $(TEST_MAIN_OBJ) $(LDFLAGS)

# Compiling rule
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run programs
run_demo: $(DEMO_TARGET)
	./$(DEMO_TARGET)

run_test: $(TEST_TARGET)
	./$(TEST_TARGET)

run_test_main: $(TEST_MAIN_TARGET)
	./$(TEST_MAIN_TARGET)

# Run all executables
run_all: run_demo run_test run_test_main

# Run gdb
gdb_demo: $(DEMO_TARGET)
	gdb ./$(DEMO_TARGET)

gdb_test: $(TEST_TARGET)
	gdb ./$(TEST_TARGET)

gdb_test_main: $(TEST_MAIN_TARGET)
	gdb ./$(TEST_MAIN_TARGET)

# Run with Valgrind
valgrind_demo: $(DEMO_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(DEMO_TARGET)

valgrind_test: $(TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_TARGET)

valgrind_test_main: $(TEST_MAIN_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_MAIN_TARGET)

# Generate documentation with Doxygen
doxy:
	doxygen Doxyfile

# Clean build files
clean:
	rm -f $(DEMO_OBJ) $(TEST_OBJ) $(TEST_MAIN_OBJ) $(DEMO_TARGET) $(TEST_TARGET) $(TEST_MAIN_TARGET) *.gcda *.gcno *.gcov

# Clean only TestingMain build files
clean_test_main:
	rm -f $(TEST_MAIN_OBJ) $(TEST_MAIN_TARGET)

# Generate coverage reports
coverage_demo: $(DEMO_TARGET)
	@echo "Running demo to generate coverage data..."
	./$(DEMO_TARGET)
	@echo "Generating coverage report..."
	gcov -o . *.cpp
	@echo "Coverage report generated (.gcov files)."

coverage_test: $(TEST_TARGET)
	@echo "Running unit tests to generate coverage data..."
	./$(TEST_TARGET)
	@echo "Generating coverage report..."
	gcov -o . *.cpp
	@echo "Coverage report generated (.gcov files)."

coverage_test_main: $(TEST_MAIN_TARGET)
	@echo "Running testing main to generate coverage data..."
	./$(TEST_MAIN_TARGET)
	@echo "Generating coverage report..."
	gcov -o . $(TEST_MAIN_COMMON_SRC)
	@echo "Coverage report generated (.gcov files)."

.PHONY: all all_targets run_demo run_test run_test_main run_all gdb_demo gdb_test gdb_test_main \
        valgrind_demo valgrind_test valgrind_test_main doxy clean clean_test_main \
        coverage_demo coverage_test coverage_test_main

# # Compiler
# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -Werror=sign-compare -Werror=delete-non-virtual-dtor -Wextra -g -fprofile-arcs -ftest-coverage
# LDFLAGS = -fprofile-arcs -ftest-coverage

# # Directories
# SRC_DIR = .
# TEST_DIR = .
# BUILD_DIR = build
# OBJ_DIR = $(BUILD_DIR)/obj

# # Source files
# COMMON_SRC = $(filter-out DemoMain.cpp UnitTest.cpp TestingMain.cpp, $(wildcard *.cpp))
# DEMO_SRC = DemoMain.cpp $(COMMON_SRC)
# TEST_SRC = UnitTest.cpp $(COMMON_SRC)
# TEST_MAIN_SRC = TestingMain.cpp $(COMMON_SRC)

# # Object files
# DEMO_OBJECTS = $(DEMO_SRC:%.cpp=$(OBJ_DIR)/%.o)
# DEMO_OBJ = $(DEMO_OBJECTS)
# TEST_OBJECTS = $(TEST_SRC:%.cpp=$(OBJ_DIR)/%.o)
# TEST_OBJ = $(TEST_OBJECTS)
# TEST_MAIN_OBJECTS = $(TEST_MAIN_SRC:%.cpp=$(OBJ_DIR)/%.o)
# TEST_MAIN_OBJ = $(TEST_MAIN_OBJECTS)

# # Output executables
# DEMO_TARGET = DemoMain
# TEST_TARGET = UnitTest
# TEST_MAIN_TARGET = TestingMain

# # Default target: compile all three
# all: $(BUILD_DIR)/$(DEMO_TARGET) $(BUILD_DIR)/$(TEST_TARGET) $(BUILD_DIR)/$(TEST_MAIN_TARGET)

# # Create build directories
# $(OBJ_DIR):
# 	@mkdir -p $(OBJ_DIR)

# $(BUILD_DIR):
# 	@mkdir -p $(BUILD_DIR)

# # Compile and Linking demo
# $(BUILD_DIR)/$(DEMO_TARGET): $(DEMO_OBJ) | $(BUILD_DIR)
# 	$(CXX) $(CXXFLAGS) -o $@ $(DEMO_OBJ) $(LDFLAGS)

# # Compile and Linking unit test
# $(BUILD_DIR)/$(TEST_TARGET): $(TEST_OBJ) | $(BUILD_DIR)
# 	$(CXX) $(CXXFLAGS) -o $@ $(TEST_OBJ) $(LDFLAGS)

# # Compile and Linking testing main
# $(BUILD_DIR)/$(TEST_MAIN_TARGET): $(TEST_MAIN_OBJ) | $(BUILD_DIR)
# 	$(CXX) $(CXXFLAGS) -o $@ $(TEST_MAIN_OBJ) $(LDFLAGS)

# # Compiling rule
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Run programs
# run_demo: $(BUILD_DIR)/$(DEMO_TARGET)
# 	./$(BUILD_DIR)/$(DEMO_TARGET)

# run_test: $(BUILD_DIR)/$(TEST_TARGET)
# 	./$(BUILD_DIR)/$(TEST_TARGET)

# run_test_main: $(BUILD_DIR)/$(TEST_MAIN_TARGET)
# 	./$(BUILD_DIR)/$(TEST_MAIN_TARGET)

# # Run all executables
# run_all: run_demo run_test run_test_main

# # Run gdb (specify which target)
# gdb_demo: $(BUILD_DIR)/$(DEMO_TARGET)
# 	gdb ./$(BUILD_DIR)/$(DEMO_TARGET)

# gdb_test: $(BUILD_DIR)/$(TEST_TARGET)
# 	gdb ./$(BUILD_DIR)/$(TEST_TARGET)

# gdb_test_main: $(BUILD_DIR)/$(TEST_MAIN_TARGET)
# 	gdb ./$(BUILD_DIR)/$(TEST_MAIN_TARGET)

# # Run with Valgrind
# valgrind_demo: $(BUILD_DIR)/$(DEMO_TARGET)
# 	valgrind --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/$(DEMO_TARGET)

# valgrind_test: $(BUILD_DIR)/$(TEST_TARGET)
# 	valgrind --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/$(TEST_TARGET)

# valgrind_test_main: $(BUILD_DIR)/$(TEST_MAIN_TARGET)
# 	valgrind --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/$(TEST_MAIN_TARGET)

# # Generate documentation with Doxygen
# doxy:
# 	doxygen Doxyfile

# # Clean build files
# clean:
# 	rm -rf $(BUILD_DIR) *.gcda *.gcno *.gcov

# # Generate coverage reports
# coverage_demo: $(BUILD_DIR)/$(DEMO_TARGET)
# 	@echo "Running demo to generate coverage data..."
# 	./$(BUILD_DIR)/$(DEMO_TARGET)
# 	@echo "Generating coverage report..."
# 	gcov -o $(OBJ_DIR) *.cpp
# 	@echo "Coverage report generated (.gcov files)."

# coverage_test: $(BUILD_DIR)/$(TEST_TARGET)
# 	@echo "Running unit tests to generate coverage data..."
# 	./$(BUILD_DIR)/$(TEST_TARGET)
# 	@echo "Generating coverage report..."
# 	gcov -o $(OBJ_DIR) *.cpp
# 	@echo "Coverage report generated (.gcov files)."

# coverage_test_main: $(BUILD_DIR)/$(TEST_MAIN_TARGET)
# 	@echo "Running testing main to generate coverage data..."
# 	./$(BUILD_DIR)/$(TEST_MAIN_TARGET)
# 	@echo "Generating coverage report..."
# 	gcov -o $(OBJ_DIR) *.cpp
# 	@echo "Coverage report generated (.gcov files)."

# # Generate combined coverage from all executables
# coverage_all: $(BUILD_DIR)/$(DEMO_TARGET) $(BUILD_DIR)/$(TEST_TARGET) $(BUILD_DIR)/$(TEST_MAIN_TARGET)
# 	@echo "Running all executables to generate combined coverage data..."
# 	./$(BUILD_DIR)/$(DEMO_TARGET)
# 	./$(BUILD_DIR)/$(TEST_TARGET)
# 	./$(BUILD_DIR)/$(TEST_MAIN_TARGET)
# 	@echo "Generating coverage report..."
# 	gcov -o $(OBJ_DIR) *.cpp
# 	@echo "Combined coverage report generated (.gcov files)."

# .PHONY: all run_demo run_test run_test_main run_all gdb_demo gdb_test gdb_test_main \
#         valgrind_demo valgrind_test valgrind_test_main doxy clean \
#         coverage_demo coverage_test coverage_test_main coverage_all