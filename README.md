# My C Project

This project is a simple C application that demonstrates the use of a development container for building and running C programs. 

## Project Structure

```
my-c-project
├── .devcontainer
│   ├── devcontainer.json
│   └── Dockerfile
├── src
│   ├── main.c
│   └── utils.c
├── include
│   └── utils.h
├── Makefile
└── README.md
```

## Getting Started

To get started with this project, follow the instructions below:

### Prerequisites

- Docker must be installed on your machine.
- Visual Studio Code with the Remote - Containers extension.

### Setting Up the Development Container

1. Clone the repository to your local machine:
   ```
   git clone <repository-url>
   cd my-c-project
   ```

2. Open the project in Visual Studio Code.

3. Reopen the folder in the container:
   - Press `F1` and select `Remote-Containers: Reopen in Container`.

### Building the Project

Once the container is up and running, you can build the project using the provided Makefile. Open a terminal in VS Code and run:

```
make
```

### Running the Application

After building the project, you can run the application with:

```
./my-c-project
```

### Contributing

Feel free to submit issues or pull requests if you would like to contribute to this project.

### License

This project is licensed under the MIT License. See the LICENSE file for more details.