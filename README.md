# Darkfish Chess Engine

Darkfish is a chess engine implemented in C++ using the UCI (Universal Chess Interface) protocol. It features a basic chess AI that can play chess moves based on simple evaluation and search algorithms.

## Features

- Implements the UCI protocol for communication with chess GUIs.
- Supports parsing FEN (Forsyth–Edwards Notation) strings to set up the chess board.
- Provides a basic evaluation function to assess the value of the chess position.
- Implements a simple search algorithm to find the best move based on the current position.
- Supports legal move generation for a given chess position.
- Includes a command-line interface for testing and playing against the engine.

## Dependencies

- C++17 or later
- Qt (version 5 or 6) for the GUI interface (optional)

## Build Instructions

1. Clone the Darkfish repository: `git clone https://github.com/yourusername/darkfish.git`
2. Navigate to the project directory: `cd darkfish`
3. Create a build directory: `mkdir build && cd build`
4. Generate the build files with CMake: `cmake ..`
5. Build the project: `cmake --build .`

Note: If you are using Qt for the GUI interface, make sure to install the Qt development libraries and set up CMake to find the Qt package.

## Usage

1. Run the Darkfish executable: `./darkfish`
2. If using a GUI, select the Darkfish engine in the settings or connect to it using the UCI protocol.
3. If using the command-line interface, follow the prompts to set up the board, make moves, and play against the engine.

## Contributing

Contributions to Darkfish are welcome! If you find any bugs, issues, or have suggestions for improvements, please submit them via GitHub issues or consider creating a pull request.

## License

Darkfish is open-source software licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
