

# Multi-Game Terminal Application

This project is a collection of terminal-based games written in **C**, where players can buy coins to unlock and play different games. The system is built with a simple user interface, designed for ease of use and enjoyment.

## Features
- Multiple games available to play after purchasing coins
- Simple and interactive terminal-based interface
- Modular structure for adding more games easily
- Built with C programming language for performance and portability

## Table of Contents
1. [Prerequisites](#prerequisites)
2. [Installation](#installation)
3. [How to Run](#how-to-run)
4. [Gameplay](#gameplay)
5. [Contributing](#contributing)
6. [License](#license)

## Prerequisites

Before running the game, ensure you have the following installed on your system:

- **GCC Compiler**: Used for compiling C code. You can install it via:
  - For **Ubuntu/Linux**: 
    ```bash
    sudo apt-get install build-essential
    ```
  - For **Windows**: You can use **MinGW**. Follow [this guide](https://www.mingw-w64.org/) to install.
  - For **macOS**: 
    ```bash
    xcode-select --install
    ```
- **Git**: To clone the repository.
  - For **Ubuntu/Linux**:
    ```bash
    sudo apt-get install git
    ```
  - For **Windows/macOS**: Download from [here](https://git-scm.com/).

## Installation

1. **Clone the Repository**

   Clone the project from GitHub using the following command:

   ```bash
   git clone https://github.com/maazrehman99/Super-Space-Game
   ```

2. **Navigate to the Project Directory**

   Once cloned, navigate into the directory:

   ```bash
   cd Super-Space-Game
   ```

3. **Compile the Code**

   Use the `gcc` compiler to compile the C source files into an executable. You can run the following command:

   ```bash
   gcc -o game superspace.c
   ```

   - Here, `superspace.c` is your entry point.


   This will generate an executable file named `game`.

## How to Run

After compiling the project, run the generated executable by entering the following command:

```bash
./game
```

The game will launch, and you'll be guided through the coin purchase and game selection process in the terminal.

## Gameplay

1. **Starting the Game**: Upon launching the game, you will be prompted to buy coins to unlock different games.
   
2. **Game Selection**: Once you have coins, you can choose from the available games by typing the number corresponding to the game you want to play.

3. **Coin Management**: Coins are deducted as you play. You can buy more coins if needed.

4. **Game Modes**: The project currently supports multiple games, which can be expanded easily.

### Example Games:
- **Game 1**: Casino
- **Game 2**: Hangman
- **Game 3**: Rock, Paper, Scissors

You can add more games by following the project's modular structure.

## Contributing

If you want to contribute to this project:

1. Fork the repository.
2. Create a new branch for your feature or bugfix (`git checkout -b feature-name`).
3. Commit your changes (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature-name`).
5. Create a new Pull Request.

## License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.

---

### Enjoy the Game! 🎮

Feel free to modify and extend the project with more games and features.

