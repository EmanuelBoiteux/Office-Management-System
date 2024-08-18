# Office Management System

## Overview

This project provides a comprehensive solution for managing office space allocation within a building. It consists of two main components:
- **C Program**: Generates an office occupation table based on provided parameters.
- **Python Script**: Processes the generated table to resolve allocation conflicts and produces a final output file.

### How It Works

1. **Input Data**: The project starts with an `input.txt` file that specifies the building's layout and the number of desks. The C program reads this file to generate a detailed occupation table, which includes information about each office's occupancy status and the priority of individuals.

2. **C Program Execution**: The C program creates an output file (`output.txt`) that describes the occupation of each office in terms of occupied or empty states, along with the priority of the individuals.

3. **Python Script Processing**: The Python script reads the output file generated by the C program, analyzes the data to identify and resolve any conflicts (e.g., multiple high-priority individuals in the same office), and then produces a final result in a separate output file (`python_output.txt`).


## Project Structure

### C Directory

- **main.c**: The main entry point of the C program.
- **office_manager.c**: Contains functions for managing office data and generating the occupation table.
- **office_manager.h**: Header file with function declarations.

### Python Directory

- **main.py**: The main entry point of the Python script.
- **file_functions.py**: Contains functions for creating the structure from the C output and generating the final output.
- **building_functions.py**: Contains functions for processing and resolving conflicts in office allocations.

## File Formats

### `input.txt`

The `input.txt` file should be formatted as follows:

`<number_of_floors>`
`<min_offices>` `<max_offices>`
`<number_of_desks>`

- **number_of_floors**: The number of floors in the building (1 to 3).
- **min_offices**: The minimum number of offices per floor (2 to 10).
- **max_offices**: The maximum number of offices per floor (2 to 10).
- **number_of_desks**: The number of desks per office (1 to 3).

### Output File

The C program generates an output file with the following format:

`<floor>` `<office>` `<person_or_NOBODY>` `<priority>`

Where:
- **floor**: The floor number.
- **office**: The office number on that floor.
- **person_or_NOBODY**: A person's identifier or "NOBODY" if the office is empty.
- **priority**: The priority of the person (0 or 1).

## Compilation and Execution

To compile and run the project, use the following command:

```sh
make all

```

This command will compile the C program, execute it, and then run the Python script with the generated output.