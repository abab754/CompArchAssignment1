#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void mexp(FILE * file){
    int input;
    fscanf(file, "%d", &input);
    int **result = (int **)malloc(input*sizeof(int*));
    int **original = (int **)malloc(input*sizeof(int*));
    int **changing = (int **)malloc(input*sizeof(int*));

    for(int i =0; i < input; i++){
        original[i] = (int *)malloc(input*sizeof(int*));
        changing[i] = (int *)malloc(input*sizeof(int*));
        result[i] = (int *)malloc(input*sizeof(int*));

    }

    for(int i =0; i < input; i++){
        for(int j = 0; j<input; j++){
            fscanf(file, "%d", &original[i][j]);
            changing[i][j] = original[i][j];
        }
    }

    int exp;
    fscanf(file, "%d", &exp);
    for(int k = 0; k < exp-1; k++){
        for(int i = 0; i < input; i++){
            for(int j = 0; j < input; j++ ){
                result[i][j] = 0;
                for(int a =0; a< input; a++){
                    result[i][j] += (original[i][a] * changing[a][j]);
                }
            }
        }
        for(int i =0; i < input; i++){
            for(int j =0; j< input; j++){
                changing[i][j] = result[i][j];
            }
        }
    }

    for(int i = 0; i < input; i++){
        for(int j = 0; j< input; j++){
            if(j == input-1){
                printf("%d", result[i][j]);
            }
            else{
                printf("%d ", result[i][j]);
            }
        }
        printf("\n");
    }

    for(int i =0; i< input; i++){
        free(original[i]);
        free(changing[i]);
        free(result[i]);
    }

    free(original);
    free(changing);
    free(result);
}

int main(int argc, char *argv[]){
    FILE *file = fopen(argv[1], "r");
    if(file == NULL || argc != 2){
        return 0;
    }

    mexp(file);
    fclose(file);

    
    return EXIT_SUCCESS;
}