# # Compiler
# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -Werror=sign-compare -Werror=delete-non-virtual-dtor -Wextra -g -fprofile-arcs -ftest-coverage
# LDFLAGS = -fprofile-arcs -ftest-coverage

# # Explicitly list source files needed for TestingMain based on included headers
# TEST_MAIN_COMMON_SRC = Plant.cpp Zone.cpp CareStaff.cpp LowCare.cpp MediumCare.cpp \
#                        HighCare.cpp WaterPlant.cpp FertilisePlant.cpp CareCommand.cpp \
#                        CareStrategy.cpp Inventory.cpp PlantIterator.cpp Seedling.cpp \
#                        Growing.cpp Mature.cpp Withered.cpp NurseryMediator.cpp \
#                        CustomerStaff.cpp BuildPlantDirector.cpp PotPlantBuilder.cpp \
#                        PottedPlant.cpp WrapPlantBuilder.cpp WrappedPlant.cpp \
#                        CustomisePlant.cpp DiscardPlant.cpp PlantPot.cpp PlantSoil.cpp \
#                        PlantWrap.cpp PlantDecorator.cpp Bow.cpp Ribbon.cpp BasePlant.cpp

# # Source files for other targets (using wildcard)
# COMMON_SRC = $(filter-out DemoMain.cpp UnitTesting.cpp TestingMain.cpp, $(wildcard *.cpp))
# DEMO_SRC = DemoMain.cpp $(COMMON_SRC)
# TEST_SRC = UnitTesting.cpp $(COMMON_SRC)
# TEST_MAIN_SRC = TestingMain.cpp $(TEST_MAIN_COMMON_SRC)

# # Object files
# DEMO_OBJ = $(DEMO_SRC:.cpp=.o)
# TEST_OBJ = $(TEST_SRC:.cpp=.o)
# TEST_MAIN_OBJ = $(TEST_MAIN_SRC:.cpp=.o)

# # Output executables
# DEMO_TARGET = DemoMain
# TEST_TARGET = UnitTesting
# TEST_MAIN_TARGET = TestingMain

# # Default target: compile only TestingMain
# all: $(TEST_MAIN_TARGET)

# # Build all three executables
# all_targets: $(DEMO_TARGET) $(TEST_TARGET) $(TEST_MAIN_TARGET)

# # Linking demo
# $(DEMO_TARGET): $(DEMO_OBJ)
# 	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) $(DEMO_OBJ) $(LDFLAGS)

# # Linking unit test
# $(TEST_TARGET): $(TEST_OBJ)
# 	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ) $(LDFLAGS)

# # Linking testing main
# $(TEST_MAIN_TARGET): $(TEST_MAIN_OBJ)
# 	$(CXX) $(CXXFLAGS) -o $(TEST_MAIN_TARGET) $(TEST_MAIN_OBJ) $(LDFLAGS)

# # Compiling rule
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Run programs
# run_demo: $(DEMO_TARGET)
# 	./$(DEMO_TARGET)

# run_test: $(TEST_TARGET)
# 	./$(TEST_TARGET)

# run_test_main: $(TEST_MAIN_TARGET)
# 	./$(TEST_MAIN_TARGET)

# # Run all executables
# run_all: run_demo run_test run_test_main

# # Run gdb
# gdb_demo: $(DEMO_TARGET)
# 	gdb ./$(DEMO_TARGET)

# gdb_test: $(TEST_TARGET)
# 	gdb ./$(TEST_TARGET)

# gdb_test_main: $(TEST_MAIN_TARGET)
# 	gdb ./$(TEST_MAIN_TARGET)

# # Run with Valgrind
# valgrind_demo: $(DEMO_TARGET)
# 	valgrind --leak-check=full --show-leak-kinds=all ./$(DEMO_TARGET)

# valgrind_test: $(TEST_TARGET)
# 	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_TARGET)

# valgrind_test_main: $(TEST_MAIN_TARGET)
# 	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_MAIN_TARGET)

# # Generate documentation with Doxygen
# doxy:
# 	doxygen Doxyfile

# # Clean build files
# clean:
# 	rm -f $(DEMO_OBJ) $(TEST_OBJ) $(TEST_MAIN_OBJ) $(DEMO_TARGET) $(TEST_TARGET) $(TEST_MAIN_TARGET) *.gcda *.gcno *.gcov

# # Clean only TestingMain build files
# clean_test_main:
# 	rm -f $(TEST_MAIN_OBJ) $(TEST_MAIN_TARGET)

# # Generate coverage reports
# coverage_demo: $(DEMO_TARGET)
# 	@echo "Running demo to generate coverage data..."
# 	./$(DEMO_TARGET)
# 	@echo "Generating coverage report..."
# 	gcov -o . *.cpp
# 	@echo "Coverage report generated (.gcov files)."

# coverage_test: $(TEST_TARGET)
# 	@echo "Running unit tests to generate coverage data..."
# 	./$(TEST_TARGET)
# 	@echo "Generating coverage report..."
# 	gcov -o . *.cpp
# 	@echo "Coverage report generated (.gcov files)."

# coverage_test_main: $(TEST_MAIN_TARGET)
# 	@echo "Running testing main to generate coverage data..."
# 	./$(TEST_MAIN_TARGET)
# 	@echo "Generating coverage report..."
# 	gcov -o . $(TEST_MAIN_COMMON_SRC)
# 	@echo "Coverage report generated (.gcov files)."

# .PHONY: all all_targets run_demo run_test run_test_main run_all gdb_demo gdb_test gdb_test_main \
#         valgrind_demo valgrind_test valgrind_test_main doxy clean clean_test_main \
#         coverage_demo coverage_test coverage_test_main

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
LDFLAGS =

# Directories
SRC_DIR = .
TEST_DIR = .
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Test executable name
TEST_EXEC = UnitTest

# Source files (only the ones you actually have)
SOURCES = \
	BasePlant.cpp \
	BuildPlantDirector.cpp \
	Plant.cpp \
	PlantBuilder.cpp \
	PlantComponent.cpp \
	PotPlantBuilder.cpp \
	PottedPlant.cpp \
	WrappedPlant.cpp \
	WrapPlantBuilder.cpp

# Add these files only if they exist in your directory
# Uncomment the ones you have:
SOURCES += PlantPot.cpp
SOURCES += PlantSoil.cpp
SOURCES += PlantWrap.cpp
SOURCES += PlantDecorator.cpp
# SOURCES += Greenhouse.cpp
# SOURCES += PlantState.cpp
SOURCES += Growing.cpp
SOURCES += Seedling.cpp
SOURCES += Mature.cpp
SOURCES += Withered.cpp
SOURCES += Zone.cpp
SOURCES += CareStrategy.cpp
SOURCES += LowCare.cpp
SOURCES += MediumCare.cpp
SOURCES += HighCare.cpp
SOURCES += WaterPlant.cpp
SOURCES += FertilisePlant.cpp
SOURCES += CareStaff.cpp
SOURCES += Staff.cpp
SOURCES += Inventory.cpp
SOURCES += PlantIterator.cpp
SOURCES += Bow.cpp
SOURCES += Ribbon.cpp
SOURCES += String.cpp
SOURCES += CareStrategy.cpp
SOURCES += LowCare.cpp
SOURCES += MediumCare.cpp
SOURCES += HighCare.cpp
SOURCES += WaterPlant.cpp
SOURCES += FertilisePlant.cpp
SOURCES += CareStaff.cpp
SOURCES += Zone.cpp
SOURCES += PlantObserver.cpp
SOURCES += NurseryMediator.cpp
SOURCES += Greenhouse.cpp

# Test file
TEST_SOURCE = UnitTest.cpp

# Object files
OBJECTS = $(SOURCES:%.cpp=$(OBJ_DIR)/%.o)
TEST_OBJECT = $(OBJ_DIR)/UnitTest.o

# Default target
all: $(BUILD_DIR)/$(TEST_EXEC)

# Create build directories
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test file
$(TEST_OBJECT): $(TEST_DIR)/$(TEST_SOURCE) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link everything together
$(BUILD_DIR)/$(TEST_EXEC): $(OBJECTS) $(TEST_OBJECT)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Run tests
test: $(BUILD_DIR)/$(TEST_EXEC)
	@echo "Running tests..."
	@./$(BUILD_DIR)/$(TEST_EXEC)

# Run tests with verbose output
test-verbose: $(BUILD_DIR)/$(TEST_EXEC)
	@echo "Running tests (verbose)..."
	@./$(BUILD_DIR)/$(TEST_EXEC) -s

# Run specific test case
test-case: $(BUILD_DIR)/$(TEST_EXEC)
	@echo "Running specific test case..."
	@./$(BUILD_DIR)/$(TEST_EXEC) -tc="$(CASE)"

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Rebuild everything
rebuild: clean all

# Run with Valgrind
valgrind_unit: $(BUILD_DIR)/$(TEST_EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/$(TEST_EXEC)

# Run gdb (specify which target)
gdb_unit: $(BUILD_DIR)/$(TEST_EXEC)
	gdb ./$(BUILD_DIR)/$(TEST_EXEC)


# Show help
help:
	@echo "Available targets:"
	@echo "  all           - Build test executable (default)"
	@echo "  test          - Build and run tests"
	@echo "  test-verbose  - Build and run tests with verbose output"
	@echo "  test-case     - Run specific test case (usage: make test-case CASE='test name')"
	@echo "  clean         - Remove build artifacts"
	@echo "  rebuild       - Clean and rebuild"
	@echo "  help          - Show this help message"

.PHONY: all test test-verbose test-case clean rebuild help