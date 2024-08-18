#include "office_manager.h"

int main(int argc, char* argv[]) {
    char* inputFile = argv[1];
    char* outputFile = argv[2];
    
    int* inputData = getInput(inputFile);
    int floors = inputData[0];
    int minOffices = inputData[1];
    int maxOffices = inputData[2];
    int numDesks = inputData[3];

    // Validate input data
    if (validateInput(floors, minOffices, maxOffices, numDesks) == 0) {

        int* officeMatrix = generateMatrix(floors, minOffices, maxOffices);
        int** occupationTable = generateOccupation(officeMatrix, floors, numDesks, outputFile);

        freeMemory(occupationTable, officeMatrix, floors, numDesks, inputData);
    }

    return 0;
}
