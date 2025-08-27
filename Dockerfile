# Debian 12 Base image 
FROM debian:12-slim

# Install build essentials
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    cmake \
    libfftw3-dev \
    libgtest-dev \
    git \
    && rm -rf /var/lib/apt/lists/*

# Build and install GoogleTest
RUN cd /usr/src/gtest && \
    cmake . && \
    make && \
    cp lib/*.a /usr/lib

# Set work directory
WORKDIR /app

# Copy project files into container
COPY . .

# Build target program
RUN make clean && make

# Run unit tests by default
CMD ["make", "test"]