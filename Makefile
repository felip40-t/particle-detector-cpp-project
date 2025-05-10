# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -MMD -MP -Iinclude

# Build directory
BUILD_DIR := build

# Source directories
SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.cpp) particle_detector.cpp

# Object and dependency files
OBJ := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(SRC)))
DEP := $(patsubst %.cpp, $(BUILD_DIR)/%.d, $(notdir $(SRC)))

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

# Compilation rules
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/particle_detector.o: particle_detector.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Include dependency files
-include $(DEP)

.PHONY: all clean
