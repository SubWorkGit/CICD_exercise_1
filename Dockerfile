# Use a base image with a build environment
FROM ubuntu:20.04

# Set environment variables to prevent interactive prompts during installation
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    curl \
    && apt-get clean

# Set up a working directory
WORKDIR /app

# Copy the entire project into the container
COPY . /app

RUN git --version
RUN ls /app

# Configure and build the project
RUN cmake -S . -B build && cmake --build build

# Run tests
CMD ["bash", "-c", "cd /app/build && ctest --verbose"]
