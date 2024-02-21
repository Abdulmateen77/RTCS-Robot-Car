# RTCS-Robot-Car

# Line Follower Robot Car


## Overview

This repository contains the code for a line follower robot car. The robot car is designed to autonomously follow a black line using infrared line sensors. The project provides a basic implementation of a line-following algorithm and includes options for optimization and further development.

## Contents

- **line_follower.c:** The main C program that implements the line-following logic.
- **initio.h:** Header file providing function prototypes for controlling the robot car.
- **Documentation:** Additional documentation, including a cheat sheet and explanatory notes.

## Getting Started

### Prerequisites

- The code is designed for the 4tronix initio robot car.
- Ensure you have the necessary development tools installed, including GCC, WiringPi, and Curses library.

### Compilation

Compile the code using the following command:

```bash
gcc -o line_follower -Wall -Werror -lcurses -lwiringPi -lpthread -linitio line_follower.c
```

### Running the Program

1. Connect to the robot car via SSH:

   ```bash
   ssh e300user@10.0.1.2
   ```

2. Navigate to the directory containing the compiled program.

3. Execute the program:

   ```bash
   ./line_follower
   ```

4. Observe the robot car's behavior in response to the line-following algorithm.


## Contributors

- Abdul Mateen

## License

This project is licensed under the [GNU Lesser General Public License (LGPL) Version 2.1](LICENSE).

Feel free to fork the repository, experiment with the code, and contribute to its development!
