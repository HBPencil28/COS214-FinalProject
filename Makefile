# ====== Project Configuration ======
CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -pedantic -g
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

# ====== Directories ======
SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
TARGET := main

# ====== Default target ======
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# ====== Run the program ======
run: $(TARGET)
	./$(TARGET)

# ====== Valgrind memory check ======
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# ====== Clean build artifacts ======
clean:
	rm -f $(OBJ) $(TARGET) *.gcno *.gcda *.gcov coverage.info

# ====== Code coverage ======
coverage: clean
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -fprofile-arcs -ftest-coverage" LDFLAGS="$(LDFLAGS) -lgcov"
	./$(TARGET)
	gcov $(SRC)

# ====== Phony targets ======
.PHONY: all run valgrind clean coverage
