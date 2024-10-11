CMAKE_BUILD_DIR = build
TARGET = my_project

# Build the project using CMake
all: 
	@mkdir -p $(CMAKE_BUILD_DIR)
	cd $(CMAKE_BUILD_DIR) && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. && make

# Run the project
run: all
	@./$(CMAKE_BUILD_DIR)/$(TARGET)

# Clean build files
clean:
	rm -rf $(CMAKE_BUILD_DIR) $(TARGET) compile_commands.json

.PHONY: all run clean
