FROM gcc:latest

# Set the working directory
WORKDIR /workspace

# Copy the source files and header files into the container
COPY src/ ./src/
COPY include/ ./include/
COPY Makefile ./

# Install any necessary packages (if needed)
# RUN apt-get update && apt-get install -y <packages>

# Build the project
RUN make

# Command to run the application
CMD ["./your_executable_name"]  # Replace with the actual executable name after building