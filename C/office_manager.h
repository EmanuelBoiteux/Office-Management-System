// Function declarations

/*
 * This function reads the file passed as an argument and returns an array of int
 * with the read information.
 */
int* getInput(char* inputFile);

/*
 * This function receives the number of floors, the maximum and minimum number of offices,
 *and the number of desks, and returns 0 if they are within the specified range or 1 if
 * any of the variables are out of range.
 */
int validateInput(int floors, int minOffices, int maxOffices, int numDesks);

/*
 * This function receives the number of floors in a building, a maximum and minimum number of offices,
 * and returns an array where each position of the array represents a floor and assigns it a random number
 * of offices within the limits passed as arguments.
 */
int* generateMatrix(int floors, int minOffices, int maxOffices);

/*
 * This function returns a 4-column integer matrix where the values of the third and fourth columns are generated
 * randomly. It creates an output file with the generated information.
 */
int** generateOccupation(int* matrix, int floors, int numDesks, char* outputFile);

/*
 * Frees the memory allocated for the occupation table and the office matrix.
 */
void freeMemory(int** occupationTable, int* officeMatrix, int floors, int numDesks, int* inputData);
