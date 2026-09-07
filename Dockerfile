# Stage 1: Build stage
FROM ubuntu:latest 

# Install build-essential for compiling C++ code
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    gdb \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the source code into the container
COPY . .

# Compile the project using the Makefile
RUN make

# Run the compiled program when the container starts
CMD ["./taskforge"]