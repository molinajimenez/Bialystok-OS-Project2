
#include "builtinfuncs.h"

struct MatrixBase GenerateMatrices(char *argv[])
{
    struct MatrixBase matrix;

    matrix.row1 = atoi(argv[2]);
    matrix.col1 = atoi(argv[3]);
    matrix.row2 = atoi(argv[3]);
    matrix.col2 = atoi(argv[4]);
    matrix.min = atoi(argv[5]);
    matrix.max = atoi(argv[6]);

    matrix.matrix1 = malloc(matrix.row1 * sizeof(int *));
    for (int i = 0; i < matrix.row1; i++)
    {
        matrix.matrix1[i] = malloc(matrix.col1 * sizeof(int));
    }

    matrix.matrix2 = malloc(matrix.row2 * sizeof(int *));
    for (int i = 0; i < matrix.row2; i++)
    {
        matrix.matrix2[i] = malloc(matrix.col2 * sizeof(int));
    }

    return matrix;
}
int main(int argc, char *argv[])
{

    if (*argv[1] == 'm')
    {
        struct MatrixBase matrix = GenerateMatrices(argv);
        matrix = FillMatrices(matrix);
        MultiplyMatrices(matrix);
    }
}