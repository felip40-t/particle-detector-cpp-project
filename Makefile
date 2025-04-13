# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -MMD -MP

# Sources and objects
SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
DEP := $(SRC:.cpp=.d)
EXEC := particle_detector

# Default target
all: $(EXEC)

# Linking
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation rule
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(DEP) $(EXEC)

# Include auto-generated dependency files
-include $(DEP)

.PHONY: all clean
