# Epidemic Simulation

## Description

This project simulates the spread of an epidemic within a population using a simple model where individuals can be in one of three states:
- **Healthy**
- **Infected**
- **Recovered**

The project uses the SDL library to graphically display the state of each individual in the population on a grid.

## Features

- **Real-time graphical display**: Shows the population with different states for each individual (healthy, infected, recovered).
- **Epidemic simulation**: Every day, a probability of infection and recovery is applied.
- **Contacts**: Infected individuals have a certain number of contacts with others, influencing the spread of the infection.

## Prerequisites

- **SDL2**: The project uses the SDL2 library for graphical rendering. Make sure you have SDL2 installed on your system before compiling the project.

### Installing SDL2

1. Download SDL2 from [the official SDL website](https://www.libsdl.org/download-2.0.php).
2. Follow the installation instructions for your operating system.

## Compilation and Execution

### 1. Clone the repository

```bash
git clone https://github.com/houdabelhad1/EpidemicSim.git
cd EpidemicSim
```bash
### 2. Compile the project

Make sure your development environment (e.g., Visual Studio) is set up to include the SDL2 library.
- Open the EpidemicSim.vcxproj file with Visual Studio and build the project.

### 3. Run the project
After building the project, you can run the generated executable. The program will launch the epidemic simulation and display the real-time graphical representation of the infection spread.

### 4. Simulation Parameters
The simulation's behavior can be adjusted via the config.ini configuration file:

```bash
[Settings]
initial_infected = 1      ; Initial number of infected individuals
infection_rate = 0.3      ; Probability of infection with each contact
recovery_rate = 0.1       ; Probability of recovery for an infected individual
```bash
### 5. Project Structure

- **main.c**: Contains the main program loop and initializes the graphical elements.
- **simulation.c**: Manages the simulation logic, including infection and recovery.
- **graphics.c**: Handles graphical display of individuals' states using SDL2.
- **config.ini**: Configuration file with simulation parameters.
- **simulation.h** and **graphics.h**: Declarations of functions used in the program.


