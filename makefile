# Variables
CFLAGS = -Wall
CC = gcc
CFILES = C/main.c C/office_manager.c
EXEC = C/a.out
PYTHON = python3
PY_SCRIPT = Python/main.py
INPUT = input.txt
OUTPUT = output.txt
OUTPUT_PY = python_output.txt

# Compilar el programa en C
$(EXEC): $(CFILES)
	$(CC) $(CFLAGS) -o $(EXEC) $(CFILES)

# Ejecutar el programa en C
run_c: $(EXEC)
	./$(EXEC) $(INPUT) $(OUTPUT)

# Ejecutar el programa en Python
run_py: $(OUTPUT)
	$(PYTHON) $(PY_SCRIPT) $(OUTPUT) $(OUTPUT_PY)

# Ejecutar todo: compilación de C, ejecución de C y Python
all: run_c run_py

# Limpiar los archivos generados
clean:
	rm -f $(EXEC) $(OUTPUT) $(OUTPUT_PY)

.PHONY: all clean run_c run_py
