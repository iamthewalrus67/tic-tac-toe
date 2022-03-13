# Tic Tac Toe

#### Author: [Bohdan Ruban](https://github.com/iamthewalrus67)

Tic Tac Toe written in C++

## Prerequisites

- `CMake`
- `Make`
- `C++ Compiler`
- [`fmt`](https://github.com/fmtlib/fmt)

## Compilation

```shell
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Usage

After compilation there should be a binary file named `tic_tac_toe`.


Here is an example of running this game with two Minimax AIs against each other:
```shell
$ ./tic_tac_toe
h - human, cr - computer, using random, cm - computer, using minimax.
Choose player 1:
cm
h - human, cr - computer, using random, cm - computer, using minimax.
Choose player 2:
cm
|1|2|3|
|4|5|6|
|7|8|9|
Enter a number from 1 to 9 to choose a corresponding cell on the board.

First player's turn:
|X|_|_|
|_|_|_|
|_|_|_|

Second player's turn:
|X|_|_|
|_|O|_|
|_|_|_|

First player's turn:
|X|X|_|
|_|O|_|
|_|_|_|

Second player's turn:
|X|X|O|
|_|O|_|
|_|_|_|

First player's turn:
|X|X|O|
|_|O|_|
|X|_|_|

Second player's turn:
|X|X|O|
|O|O|_|
|X|_|_|

First player's turn:
|X|X|O|
|O|O|X|
|X|_|_|

Second player's turn:
|X|X|O|
|O|O|X|
|X|O|_|

First player's turn:
|X|X|O|
|O|O|X|
|X|O|X|

Tie!
```

## Results

A simple Tic Tac Toe game with an implemented Minimax algorithm and an ability to easily add new algorithms.