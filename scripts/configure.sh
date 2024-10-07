#!/bin/bash

# Check if a build directory already exists, if so, remove it
if [ -d "build" ]; then
    echo "Removing existing build directory."
    rm -rf build
fi

# Create a new build directory
echo "Creating build directory."
mkdir build

# Move into the build directory
cd build

# Run cmake to configure the project
echo "Configuring the project with CMake..."
cmake ..
