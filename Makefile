# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -MMD -MP

# Build directory
BUILD_DIR := build

# Sources, objects, and dependency files
SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRC))
DEP := $(patsubst %.cpp, $(BUILD_DIR)/%.d, $(SRC))

# Executable
EXEC := $(BUILD_DIR)/particle_detector

# Default target
all: $(EXEC)

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Linking
$(EXEC): $(OBJ) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation rule
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Include dependency files
-include $(DEP)

.PHONY: all clean