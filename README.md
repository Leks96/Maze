# Maze

This project implements a simple raycasting engine using C and SDL2 for rendering. Raycasting is a technique used primarily for rendering 3D scenes in a 2D environment, commonly seen in early video games like Wolfenstein 3D.

## Features

- **Raycasting Rendering**: Simulates 3D walls using 2D graphics techniques.
- **Texture Mapping**: Implements basic texture mapping for walls.
- **Player Movement**: Allows the player to move within a predefined map.
- **Collision Detection**: Detects collisions with walls using ray intersections.
- **SDL2 Graphics**: Utilizes SDL2 library for graphics and input handling.

## Project Structure

The project is structured as follows:

- **`src/`**: Contains the source code files.
  - `main.c`: Entry point of the program.
  - `the_wall.c`: Implements raycasting and wall rendering logic.
  - `the_texture.c`: Handles texture loading and management.
  - Other files for utility functions and player mechanics.
- **`headers/`**: Includes necessary header files.
  - `header.h`: Declares constants, structs, and function prototypes.
- **`images/`**: Stores textures used for wall rendering.
- **`Makefile`**: Automation script for compiling the project.

## Dependencies

- **SDL2**: Simple DirectMedia Layer version 2.
- **libupng**: Lightweight Portable Network Graphics (PNG) library.

## How to Build and Run

1. **Install Dependencies**:
   - SDL2 development libraries (`libsdl2-dev` on Ubuntu).
   - libupng development libraries (`libupng-dev` on Ubuntu).

2. **Clone the Repository**:
   ```bash
   git clone https://github.com/Leks96/Maze.git
   cd Maze

3. **Build and Run The Project**:
   ```bash
   .Makefile

## Controls

    - Arrow Keys: Move the player forward, backward and rotate
    - W, S, D, and A: Move the player forward, backward and rotate
    - ESC Key: Exit the game

## ScreenShot
![The Maze Flow Chart](https://res.cloudinary.com/dglpy94yq/image/upload/v1719486880/Screenshot_91_srfbjk.png)

## Demo
[![The Maze Demo](https://res.cloudinary.com/dglpy94yq/image/upload/v1719486880/Screenshot_91_srfbjk.png)](https://res.cloudinary.com/dglpy94yq/video/upload/v1719487891/top-level_window_Ubuntu_2024-06-27_12-26-03_sanacf.mp4)