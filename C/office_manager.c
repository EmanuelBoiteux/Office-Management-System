#include "office_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int* getInput(char* inputFile){
    FILE* input = fopen(inputFile, "r");
    int* data = malloc(sizeof(int) * 4);
    fscanf(input, "%d\n", &data[0]);
    fscanf(input, "%d %d\n", &data[1], &data[2]);
    fscanf(input, "%d\n", &data[3]);
    fclose(input);
    return data;
}


int validateInput(int floors, int minOffices, int maxOffices, int numDesks) {
    if (floors < 1 || floors > 3 || minOffices < 2 || maxOffices > 10 || numDesks < 1 || numDesks > 3) {
        printf("The input data exceeds the established limits\n");
        return 1;
    }
    return 0;
}


int* generateMatrix(int floors, int minOffices, int maxOffices) {
    int* matrix = malloc(sizeof(int) * floors);
    srand(time(NULL));

    for(int i = 0; i < floors; i++) {
        matrix[i] = (rand() % (maxOffices - minOffices + 1)) + minOffices;
    }
    
    return matrix;
}


int** generateOccupation(int* matrix, int floors, int numDesks, char* outputFile) {
    char outputPath[256];
    snprintf(outputPath, sizeof(outputPath), "../%s", outputFile);
    FILE* output = fopen(outputFile, "w");
    int totalOffices = 0;

    for (int i = 0; i < floors; i++) {
        totalOffices += matrix[i];
    }

    int totalDesks = totalOffices * numDesks;
    int** table = malloc(sizeof(int*) * totalDesks);

    for (int i = 0; i < totalDesks; i++) {
        table[i] = malloc(sizeof(int) * 4);
    }

    int person = 1;

    for (int i = 0; i < floors; i++) {
        int officesPerFloor = matrix[i];

        for (int j = 0; j < officesPerFloor; j++) {
            for (int k = 0; k < numDesks; k++) {
                table[i][0] = i;
                table[i][1] = j;

                int occupied = rand() % 2;
                if (occupied == 0) {
                    table[i][2] = 0;  // store the person as 0
                    table[i][3] = -1; // not applicable
                } else {
                    int priority = rand() % 2;
                    table[i][2] = person; // store the person
                    person++;
                    table[i][3] = priority; // store their priority
                }

                if (occupied != 0) {
                    fprintf(output, "%d %d person%d %d\n", table[i][0], table[i][1], table[i][2], table[i][3]);
                } else {
                    fprintf(output, "%d %d NOBODY %d\n", table[i][0], table[i][1], table[i][3]);
                }
            }
        }
    }

    fclose(output);
    return table;
}


void freeMemory(int** occupationTable, int* officeMatrix, int floors, int numDesks, int* inputData) {
    int totalOffices = 0;

    for (int i = 0; i < floors; i++) {
        totalOffices += officeMatrix[i];
    }

    int totalDesks = totalOffices * numDesks;
    for (int i = 0; i < totalDesks; i++) {
        free(occupationTable[i]);
    }

    free(occupationTable);
    free(officeMatrix);
    free(inputData);
}