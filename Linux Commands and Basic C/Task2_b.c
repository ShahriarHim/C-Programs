#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[] = "input.txt";
    char outputFileName[] = "output.txt";
    char c;
    int inSpace = 0;


    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }


    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    while ((c = fgetc(inputFile)) != EOF) {
        if (c == ' ') {
            if (!inSpace) {
                inSpace = 1;
                fputc(c, outputFile);
            }
        } else {
            inSpace = 0;
            fputc(c, outputFile);
        }
    }

 
    fclose(inputFile);
    fclose(outputFile);

    printf("Extra spaces removed. Check the %s file for the output.\n", outputFileName);

    return 0;
}
